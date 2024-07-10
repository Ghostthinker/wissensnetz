<?php

namespace Wissensnetz\Core\Node;

use Wissensnetz\Core\Node\Exception\DrupalNodeNotExistsException;
use Wissensnetz\Group\GroupDrupalNode;
use Wissensnetz\OnlineMeeting\OnlineMeetingDrupalNode;
use Wissensnetz\Organisation\OrganisationDrupalNode;
use Wissensnetz\Post\PostDrupalNode;
use Wissensnetz\User\DrupalUser;

class DrupalNode {
  /**
   * @var false|mixed|object|\stdClass
   */
  protected $node;

  /**
   * Node constructor.
   *
   * @throws \Wissensnetz\Core\Node\Exception\DrupalNodeNotExistsException
   */
  public function __construct($nid) {
    if ($nid instanceof \stdClass) {
      $this->node = $nid;
    }
    else {
      $this->node = node_load($nid);
      if (empty($this->node)) {
        throw new DrupalNodeNotExistsException();
      }
    }
  }

  public static function make($node_or_nid) {

    if (is_numeric($node_or_nid)) {
      $node = node_load($node_or_nid);
    }
    else {
      $node = $node_or_nid;
    }

    if (empty($node)) {
      throw new DrupalNodeNotExistsException();
    }

    switch ($node->type) {
      case 'post':
        return new PostDrupalNode($node);
      case 'group':
        return new GroupDrupalNode($node);
      case 'online_meeting':
        return new OnlineMeetingDrupalNode($node);
      case 'organisation':
        return new OrganisationDrupalNode($node);
      default:
        return new DrupalNode($node);
    }

  }

  /**
   * @return false|mixed|object|\stdClass
   */
  public function getNode() {
    return $this->node;
  }

  public function save() {
    node_save($this->node);
  }

  public function getNid() {
    return $this->node->nid;
  }
  public function getType() {
    return $this->node->type;
  }

  public function isType($type) {
    return $this->node->type == $type;
  }

  public function getTitle() {
    return $this->node->title;
  }

  public function getAuthor() {
    return new DrupalUser($this->node->field_post_authors[LANGUAGE_NONE][0]['target_id']);
  }

  public function getCreatedTimestamp() {
    return $this->node->created;
  }

  public function getUrlAbsolute() {
    return url('node/' . $this->getNid(), ['absolute' => TRUE,]);
  }

  public function getOgNid() {
    return $this->node->field_og_group[LANGUAGE_NONE][0]['target_id'];
  }

  public function getOgNode(): ?GroupDrupalNode{
    if ($og_nid = $this->getOgNid()) {
      return self::make($og_nid);
    }
    return NULL;
  }

  public function hasViewAccess(DrupalUser $drupalUser){
    return node_access('view', $this->getNode(), $drupalUser->getUser());
  }

  public function getCreatedDateISO() {
    return format_date($this->node->created, 'custom', 'Y-m-d H:i:s');
  }

  public function inOg(){
    return !empty($this->node->field_og_group);
  }

  public function setKbKategorie($category){
    $this->node->field_kb_content_category[LANGUAGE_NONE] = $category;
  }

  public function getBody(){
    return $this->node->body[LANGUAGE_NONE][0]['value'];
  }

  public function getNumViews(){
    $statistics = statistics_get($this->getNid());
    return $statistics['totalcount'];
  }

  public function getNumComments(){
    return $this->node->comment_count;
  }

}
