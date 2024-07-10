<?php

namespace Wissensnetz\Post;

use Wissensnetz\Core\File\DrupalFile;
use Wissensnetz\Core\Node\DrupalNode;

class PostDrupalNode extends DrupalNode{

  public function getPreviewImage(){
    try {
      return DrupalFile::make($this->node->field_teaser_image[LANGUAGE_NONE][0]['fid']);
    } catch (\Throwable $t) {
      return NULL;
    }
  }

  public function getPreviewImageUrl(){
    $preview = $this->getPreviewImage();
    if(empty($preview)){
      return NULL;
    }

    return $preview->getUrl();

  }

}
