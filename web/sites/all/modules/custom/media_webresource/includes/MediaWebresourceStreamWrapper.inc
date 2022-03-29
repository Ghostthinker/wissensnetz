<?php

/**
 * @file
 * Extends the MediaProviderGenericStreamWrapper class to handle Generic web
 *   resources.
 */

/**
 * Create an instance.
 */
class MediaWebresourceStreamWrapper extends MediaReadOnlyStreamWrapper {

  /**
   * Modify the url with parameters.
   *
   * @return string
   *   Url with parameters.
   */
  public function interpolateUrl() {
    return $this->external_url;
  }

  /**
   * Get mime type.
   */
  public static function getMimeType($uri, $mapping = NULL) {
    $info = MediaWebresourceStreamWrapper::getItemFromUri($uri);

    if (!empty($info['type']) && $info['type'] == 'youtube') {
      return 'webresource/youtube';
    }
    return 'webresource/generic';
  }

  /**
   * Base implementation of setUri().
   */
  public function setUri($uri) {
    $this->uri = $uri;
    $path = explode('://', $uri);
    $this->external_url = urldecode($path[1]);
  }

  /**
   * Get infos from the uri
   *
   * @param $uri
   *
   * @return array
   */
  static function getItemFromUri($uri) {
    $parts = explode("://", $uri);
    if ($parts[0] != 'webresource') {
      return;
    }

    if (count($parts) > 1) {
      $parts2 = explode("/", $parts[1]);
      if (count($parts2) > 2) {
        $info = [];
        $info['type'] = $parts2[0];
        $info['timestamp'] = $parts2[1];
        $info['item'] = $parts2[2];
        return $info;
      }
    }
  }
}
