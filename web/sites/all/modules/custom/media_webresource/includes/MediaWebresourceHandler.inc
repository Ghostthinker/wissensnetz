<?php

/**
 * @file
 * Extends the MediaInternetBaseHandler class to handle web links
 */

/**
 * Implementation of MediaInternetBaseHandler.
 *
 * @see hook_media_internet_providers().
 */
class MediaWebresourceHandler extends MediaInternetBaseHandler {

  protected $yotube_id = NULL;

  /**
   * Parse $embed_code to get uri.
   *
   * @param string $embed_code
   *   The emded code.
   *
   * @return string
   *   The normalized URI.
   */
  public function parse($embed_code) {
    $guid = time();

    if ($youtube_id = MediaWebresourceHandler::check_youtube_id($embed_code)) {
      $this->yotube_id = $youtube_id;

      return file_stream_wrapper_uri_normalize('webresource://youtube/' . $guid . '/' . $this->yotube_id);
    }
    return file_stream_wrapper_uri_normalize('webresource://link/' . $guid . '/' . urlencode($embed_code));
  }

  /**
   * Determines if this handler should claim the item.
   *
   * @param string $embed_code
   *   A string of user-submitted embed code.
   *
   * @return bool
   *   Pass TRUE to claim the item.
   */
  public function claim($embed_code) {
    if (valid_url($embed_code, TRUE)) {
      return TRUE;
    }
  }

  /**
   * File object from the url
   *
   * @return mixed
   *   A file.
   */
  public function getFileObject() {
    $uri = $this->parse($this->embedCode);
    $external_url = file_create_url($uri);

    $file = file_uri_to_object($uri, TRUE);

    return $file;
  }

  /**
   * get YouTube video ID from URL
   *
   * @thanks to http://stackoverflow.com/questions/9594943
   *
   * @param string $url
   *
   * @return string YouTube video id or FALSE if none found.
   */
  static function check_youtube_id($url) {
    $values = NULL;
    if (preg_match('/youtube\.com\/watch\?v=([^\&\?\/]+)/', $url, $id)) {
      $values = $id[1];
    }
    else {
      if (preg_match('/youtube\.com\/embed\/([^\&\?\/]+)/', $url, $id)) {
        $values = $id[1];
      }
      else {
        if (preg_match('/youtube\.com\/v\/([^\&\?\/]+)/', $url, $id)) {
          $values = $id[1];
        }
        else {
          if (preg_match('/youtu\.be\/([^\&\?\/]+)/', $url, $id)) {
            $values = $id[1];
          }
          else {
            if (preg_match('/youtube\.com\/verify_age\?next_url=\/watch%3Fv%3D([^\&\?\/]+)/', $url, $id)) {
              $values = $id[1];
            }
          }
        }
      }
    }
    return $values;
  }

  /**
   * Returns information about the media.
   *
   * See http://www.oembed.com.
   *
   * @return
   *   If oEmbed information is available, an array containing 'title', 'type',
   *   'url', and other information as specified by the oEmbed standard.
   *   Otherwise, NULL.
   */
  public function getOEmbed() {
    $uri = $this->parse($this->embedCode);
    $external_url = file_create_url($uri);
    $oembed_url = url('http://www.youtube.com/oembed', [
      'query' => [
        'url' => $external_url,
        'format' => 'json',
      ],
    ]);
    $response = drupal_http_request($oembed_url);

    if (!isset($response->error)) {
      return drupal_json_decode($response->data);
    }
    else {
      throw new Exception("Error Processing Request. (Error: {$response->code}, {$response->error})");
      return;
    }
  }

  /**
   * Parse a remote url for title.
   *
   * @param string $url
   *
   * @return mixed
   */
  static function get_title_from_remote_page($url) {
    static $titles;
    if (empty($titles[$url])) {
      $ch = curl_init();
      curl_setopt($ch, CURLOPT_URL, $url);
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
      curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, 5);
      curl_setopt($ch, CURLOPT_TIMEOUT, 10);
      $userAgent = 'Mozilla/5.0 (Windows NT 5.1; rv:31.0) Gecko/20100101 Firefox/31.0';
      curl_setopt($ch, CURLOPT_USERAGENT, $userAgent);
      $str = curl_exec($ch);
      curl_close($ch);

      if (strlen($str) > 0) {
        preg_match("/\<title\>(.*)\<\/title\>/", $str, $title);
        $titles[$url] = $title[1];
      }
    }
    return !empty($titles[$url]) ? $titles[$url] : NULL;
  }

}
