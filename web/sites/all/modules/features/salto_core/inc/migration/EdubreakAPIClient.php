<?php

namespace salto_core\migration;
use GuzzleHttp\Client;



class EdubreakAPIClient {

  private $credentials;

  private $client = '';

  public function __construct($options) {
    $this->client = new Client(['base_uri' => $options['url']]);
    $this->credentials['mail'] = $options['credentials']['mail'];
    $this->credentials['password'] = $options['credentials']['password'];
  }

  public function ogList(){
    return $this->sendGET('og');
  }

  public function ogMembership($gid) {
    $result = $this->sendGET('members', ['query' => ['og' => $gid]]);
    return $result['items'];
  }

  private function sendGET($route, $options = []) {
    return $this->_call('GET', $route, $options);
  }

  public function getOg($gid) {
    return $this->sendGET('og/' . $gid);
  }

  public function getNews($gid) {
    return $this->sendGET('news', ['query' => ['og' => $gid, 'limit' => 1000]]);
  }

  public function getNewsComments($nid) {
    return $this->sendGET('news/' . $nid . '/comment');
  }

  public function getBlog($gid) {
    return $this->sendGET('content', ['query' => ['og' => $gid, 'type[]' => 'blog']]);
  }

  public function getContentComments($nid) {
    return $this->sendGET('content/' . $nid . '/comment');
  }

  public function getVideo($gid) {
    return $this->sendGET('videos', ['query' => ['og' => $gid]]);
  }

  public function getVideoComments($videoId) {
    return $this->sendGET('svp/videos/' . $videoId . '/comments');
  }

  public function getCmap($gid) {
    return $this->sendGET('content', ['query' => ['og' => $gid, 'type[]' => 'cmap']]);
  }

  public function getFileTree($gid) {
    return $this->sendGET('files', ['query' => ['og' => $gid]]);
  }


  private function sendPOST($route, $params, $options = []) {
    $options['form_params'] = $params;
    return $this->_call('POST', $route, $options);
  }

  private function _call($method, $route, $options = []) {

    $default = [
      'query' => [],
      'headers' => [],
      'form_params' => [],
    ];

    $options = array_merge_recursive($default, $options);
    $options['headers']['Authorization'] = 'Basic '.base64_encode($this->credentials['mail'] . ':' . $this->credentials['password']);

    try {
      $response = $this->client->request($method, $route,
        [
          'query' => $options['query'],
          'headers' => $options['headers'],
          'form_params' => $options['form_params'],
        ]);
    } catch (\GuzzleHttp\Exception\GuzzleException $e) {
      //TODO check the 404 which means no dialog session has been started yet

      switch ($e->getCode()) {
        case 404:
          return FALSE;
      }

    }

    try {
      $result = json_decode($response->getBody(), TRUE);
      if (json_last_error() !== JSON_ERROR_NONE) {
        //TODO better exception
        return FALSE;
      }

      return $result;
    } catch (\Exception $e) {
      watchdog_exception('Guzzle exepction', $e);
    }
  }

}
