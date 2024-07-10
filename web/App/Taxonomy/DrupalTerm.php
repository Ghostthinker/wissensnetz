<?php

namespace Wissensnetz\Taxonomy;

use Wissensnetz\Core\File\DrupalFile;

class DrupalTerm {


  protected $term;

  public function __construct($tid) {
    if ($tid instanceof \stdClass) {
      $this->term = $tid;
    }
    else {
      $this->term = taxonomy_term_load($tid);
    }
  }


  public static function make($term_or_id) {
    return new DrupalTerm($term_or_id);
  }

  public function getImage() {
    try {
      return DrupalFile::make($this->term->field_term_image[LANGUAGE_NONE][0]['fid']);
    } catch (\Throwable $t) {
      return NULL;
    }
  }

  public function getName() {
    return $this->term->name;
  }

  public function getTid() {
    return $this->term->tid;
  }

  public function getImageUrl($scaled = true) {
    $preview = $this->getImage();
    if (empty($preview)) {
      return NULL;
    }

    if($scaled) {
      return $preview->getStyleUrl('term_cover');
    }
    return $preview->getUrl();

  }

  public function getIcon() {
    try {
      return DrupalFile::make($this->term->field_term_icon[LANGUAGE_NONE][0]['fid']);
    } catch (\Throwable $t) {
      return NULL;
    }
  }

  public function getIconUrl() {
    $preview = $this->getIcon();
    if (empty($preview)) {
      return NULL;
    }

    return $preview->getUrl();

  }

}
