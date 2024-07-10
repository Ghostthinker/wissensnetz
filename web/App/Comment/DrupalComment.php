<?php

namespace Wissensnetz\Comment;

use Wissensnetz\Core\Node\DrupalNode;

class DrupalComment {

  protected $comment;

  public function __construct($comment){
    if ($comment instanceof \stdClass){
      $this->comment = $comment;
    }
    else{
      $this->comment = comment_load($comment, TRUE);
    }

  }

  public static function make($comment){
    return new DrupalComment($comment);
  }

  public function getCreatedDateISO() {
    return format_date($this->comment->created, 'custom', 'Y-m-d H:i:s');
  }

  public function getTitle() {
    $drupalNode = DrupalNode::make($this->getNid());
    return $drupalNode->getTitle();
  }

  public function getUrlAbsolute(){
    return url('node/' . $this->getNid() . '/#comment-' . $this->getCid(), ['absolute' => TRUE, ]);
  }

  public function getNid(){
    return $this->comment->nid;
  }

  public function getCid(){
    return $this->comment->cid;
  }

  public function inOg(){
    $drupalNode = DrupalNode::make($this->getNid());
    return $drupalNode->inOg();
  }

  public function getOgNid(){
    $drupalNode = DrupalNode::make($this->getNid());
    return $drupalNode->getOgNid();
  }

}
