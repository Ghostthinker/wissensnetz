<?php

namespace Wissensnetz\Video;

use Wissensnetz\Core\Node\DrupalNode;

class DrupalVideo {

  static function current() {
    $og = og_context();
    if(empty($og['gid'])){
      return NULL;
    }
    return self::make($og['gid']);
  }


  protected $file;

  /**
   * @return false|mixed|\stdClass
   */
  public function getFile() {
    return $this->file;
  }

  public function __construct($file_or_fid){
    if ($file_or_fid instanceof \stdClass){
      $this->file = $file_or_fid;
    }
    else{
      $this->file = file_load($file_or_fid);
    }
  }

  //make methode
  private static function make($file){
    return new DrupalVideo($file);
  }

  public function getGuid() {
    return $this->file->uuid;
  }

  public static function byUUID($uuid){

    $fids = entity_get_id_by_uuid('file', array($uuid), FALSE);
    if(empty($fids)) {
      throw new \Exception("file not available");
    }
    $fid = current($fids);
    return new DrupalVideo($fid);
  }

  public function getFileCommentNode() {
    if (!empty($this->file->field_file_comments[LANGUAGE_NONE][0]['target_id'])) {
      $nid = $this->file->field_file_comments[LANGUAGE_NONE][0]['target_id'];
      return DrupalNode::make($nid);
    }
    return NULL;
  }

  public function getFileId() {
    return $this->file->fid;
  }
}
