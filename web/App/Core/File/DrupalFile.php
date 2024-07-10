<?php

namespace Wissensnetz\Core\File;

use MediaWebresourceStreamWrapper;
use Exception;
use Wissensnetz\Core\Node\DrupalNode;
use Wissensnetz\Core\Node\Exception\DrupalNodeNotExistsException;
use Wissensnetz\File\Url2InfoService;
use Wissensnetz\Group\GroupDrupalNode;
use Wissensnetz\OnlineMeeting\OnlineMeetingDrupalNode;
use Wissensnetz\User\DrupalUser;

class DrupalFile {
  /**
   * @var false|mixed|object|\stdClass
   */
  protected $file;

  /**
   * Node constructor.
   *
   * @throws \Wissensnetz\Core\Node\Exception\DrupalNodeNotExistsException
   */
  public function __construct($fid) {
    if ($fid instanceof \stdClass) {
      $this->file = $fid;
    }
    else {
      $this->file = file_load($fid);
      if (empty($this->file)) {
        throw new \Exception("file not found");
      }
    }
  }

  public static function make($file_or_fid) {

    if (is_numeric($file_or_fid)) {
      $file = file_load($file_or_fid);
    }
    else {
      $file = $file_or_fid;
    }

    if (empty($file)) {
      throw new \Exception();
    }
    switch ($file->type) {
      case 'video':
        return new VideoDrupalFile($file);
      default:
        return new DrupalFile($file);
    }

  }

  public static function byUuid($uuid){
    $query = db_select('file_managed', 'fm');
    $query->fields('fm', array('fid'));
    $query->condition('uuid', $uuid);
    $fid = $query->execute()->fetchField();

    if ($fid) {
      return DrupalFile::make($fid);
    }

    return FALSE;
  }

  public static function getFileFromCommentNode(DrupalNode $drupalNode){
    $file = salto_files_comment_node_get_file($drupalNode->getNode());
    if(empty($file)){
      return NULL;
    }

    return DrupalFile::make($file);
  }

  public function save() {
    file_save($this->file);
  }

  public function getTitle() {
    return $this->file->field_file_title[LANGUAGE_NONE][0]["value"] ?? $this->file->title;
  }

  public function getFileUrl(){
    return url('file/' . $this->getFid(), ['absolute' => TRUE]);
  }

  public function getDescription(){
    return $this->file->field_file_description[LANGUAGE_NONE][0]['value'];
  }

  public function getCommentNodeNid(){

    return $this->file->field_file_comments[LANGUAGE_NONE][0]['target_id'] ?? NULL;
  }


  public function getCommentNode() {
    try {
      return DrupalNode::make($this->getCommentNodeNid());
    } catch (DrupalNodeNotExistsException $e) {
      return NULL;
    }
  }

  /**
   * @return false|mixed|object|\stdClass
   */
  public function getFile() {
    return $this->file;
  }

  public function getTitleLink() {
    return l($this->getTitle(), 'node/' . $this->getCommentNodeNid(), ['absolute' => TRUE,]);
  }

  public function getUrl(){
    return file_create_url($this->file->uri);
  }

  public function getStyleUrl($style){

    return image_style_url($style, $this->file->uri);
  }

  public function getFid() {
    return $this->file->fid;
  }

  public function getUid() {
    return $this->file->uid;
  }

  public function getKbKategorie(){
    return $this->file->field_kb_kategorie[LANGUAGE_NONE];
  }

  public function getTimestamp(){
    return $this->file->timestamp;
  }

  public function getRealPath() {
    return drupal_realpath($this->file->uri);
  }

  public function getUuid(){
    return $this->file->uuid;
  }

  public function getFileAttachmentNodeReferences() {
    $usage = file_usage_list($this->file);
    $nodes = [];

    if (!empty($usage)) {
      $nids = array_keys($usage['file']['node']);
      foreach($nids as $nid){
        $nodes[] = node_load($nid);
      }
    }
    return $nodes;
  }

  public function hasPublishedNodeReferences() {
    $node_references = $this->getFileAttachmentNodeReferences();
    if (empty($node_references)){
      return TRUE;
    }
    //Check if every node is unbublished
    foreach($node_references as $node_reference){
      if ($node_reference->field_publishing_options[LANGUAGE_NONE][0]['value'] !== POST_PUBLISH_IMMEDIATE){
        return FALSE;
      }
    }
    return TRUE;
  }

  public function getDownloadUrl(){
    $fileEntity = file_entity_download_uri($this->file);
    return url('/' . $fileEntity['path'], ['absolute' => TRUE, 'query' => ['token' => $fileEntity['options']['query']['token'] ]]);
  }

  public function getNumViews(){
    $statistics = salto_files_get_views_count($this->getFid());
    return $statistics['totalcount'];
  }

  public function getMediaDerivativePreset(){
    if(!$this->file->media_derivatives['has_derivatives']){
      return FALSE;
    }

    return current($this->file->media_derivatives['derivatives_list']);

  }

  public function getMediaDerivativeImage(){

    if ($this->isWebresource()){
      $info = MediaWebresourceStreamWrapper::getItemFromUri($this->file->uri);
      $url2InfoService = new Url2InfoService();
      $external_url = urldecode($info['url']);
      $urlInfos = $url2InfoService->getMetadataInfos($external_url);
      if ($urlInfos['image_url']){
        return $url2InfoService->proxyImageUrl($urlInfos['image_url']);
      }
    }

    $mimetype = $this->file->filemime;

    if(strpos($mimetype, 'image') === 0){
      return file_create_url($this->file->uri);
    }

    $mediaDerivatives = $this->getMediaDerivativePreset();

    if(!$mediaDerivatives->unmanaged_uri){
      return FALSE;
    }
    return file_create_url($mediaDerivatives->unmanaged_uri);
  }

  /**
   * @param $url
   * @param $image_style
   *
   * @return false|\stdClass
   * @throws \Exception
   */
  public function getImageStyle($image_style)  {

    $url = $this->getMediaDerivativeImage();

    $parsed_url = parse_url($url);
    $parsed_url_blank = str_replace('/system/files/', '', $parsed_url['path']);

    $file_path = file_build_uri($parsed_url_blank);

    $style = image_style_load($image_style);

    $args = func_get_args();
    array_shift($args);
    array_shift($args);
    $image_uri = $file_path;
    $image_uri = file_uri_normalize_dot_segments($image_uri);
    $derivative_uri = image_style_path($style['name'], $image_uri);

    // Don't start generating the image if the derivative already exists or if
    // generation is in progress in another thread.
    $lock_name = 'image_style_deliver:' . $style['name'] . ':' . drupal_hash_base64($image_uri);

    if (!file_exists($derivative_uri)) {
      $lock_acquired = lock_acquire($lock_name);
      if (!$lock_acquired) {
        throw new Exception('Service Unavailable', 503);

      }
    }

    // Try to generate the image, unless another thread just did it while we were
    // acquiring the lock.
    $success = file_exists($derivative_uri) || image_style_create_derivative($style, $image_uri, $derivative_uri);

    if (!empty($lock_acquired)) {
      lock_release($lock_name);
    }

    if ($success) {
      $image = image_load($derivative_uri);
      return $image;
    }
    else {
      watchdog('image', 'Unable to generate the derived image located at %path.', ['%path' => $derivative_uri]);
      //drupal_add_http_header('Status', '500 Internal Server Error');
      //drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');
      //print t('Error generating image.');
      throw new Exception('Unable to generate the derived image located at ' . $derivative_uri, 503);
    }
  }

  /**
   * @return string
   */
  public function getFileIcon(){

    if ($this->isWebresource()){
      return;
    }
    $mimetype = $this->file->filemime;

    if(strpos($mimetype, 'image') === 0){
      return url('/sites/all/static_files/image.svg', ['absolute' => TRUE]);
    }

    if(strpos($mimetype, 'pdf')){
      return url('/sites/all/static_files/pdf.svg', ['absolute' => TRUE]);
    }

    return url('/sites/all/static_files/default_material_card_icon.svg', ['absolute' => TRUE]);
  }

  public function isWebresource(){
    return $this->file->type === 'webresource';
  }

  public function getExternalWebresourceUrl(){
    $info = MediaWebresourceStreamWrapper::getItemFromUri($this->file->uri);
    return urldecode($info['item']);
  }


  public function hasEditAccess(DrupalUser $drupalUser) {
    return file_entity_access('update', $this->file, $drupalUser->getUser());
  }

  public function hasViewAccess(DrupalUser $drupalUser) {
    return file_entity_access('view', $this->file, $drupalUser->getUser());
  }

  public function hasDeleteAccess(DrupalUser $drupalUser) {
    return file_entity_access('delete', $this->file, $drupalUser->getUser());
  }

  public function hasDownloadAccess(DrupalUser $drupalUser) {
    return file_entity_access('download', $this->file, $drupalUser->getUser());
  }

}
