<?php

/**
 * Default files (default://) stream wrapper class.
 */
class SaltoStreamWrapper extends DrupalPublicStreamWrapper {

  public function getDirectoryPath() {
    return 'sites/all/files';
  }

}
