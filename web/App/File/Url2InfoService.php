<?php

namespace Wissensnetz\File;


use Firebase\JWT\JWT;

class Url2InfoService {


  /**
   * @var string
   */
  private $url2info_endpoint;

  /**
   * @var string[]
   */
  private $url2info_settings;

  public function __construct() {
    $this->url2info_settings = media_webresource_service_get_url2info_settings();
    $this->url2info_endpoint = $this->url2info_settings['url'];
  }

  public function healthCheckUrl2Info(){
    $url = $this->url2info_endpoint;
    // Create a Guzzle client with a 2-second timeout
    $client = new \GuzzleHttp\Client([
      'timeout' => 2, // Set timeout to 2 seconds
    ]);
    try {
      // Make a GET request to /ping
      $response = $client->request('GET', $url . '/status');

      // Check if the response is successful (status code 200)
      if (!$response->getStatusCode() === 200) {
        return FALSE;
      }
      $content = json_decode($response->getBody(), TRUE);

      if ($content['service'] === 'url2info' && $content['status'] === 'up'){
        return TRUE;
      }
      return FALSE;
    } catch (\Exception $e) {
      return false;
    }
  }
  public function healthCheckProxy(){

    $payload = [
      'op' => 'status',
    ];
    $token = JWT::encode($payload, $this->url2info_settings['proxy_secret'], 'HS256');
    $url = $this->url2info_settings['proxy_url'] . '?token=' . $token;
    $client = new \GuzzleHttp\Client([
      'timeout' => 2, // Set timeout to 2 seconds
    ]);
    try {
      // Make a GET request to /ping
      $response = $client->request('GET', $url);

      // Check if the response is successful (status code 200)
      if (!$response->getStatusCode() == 200) {
        return FALSE;
      }
      return TRUE;
    } catch (\Exception $e) {

      return false;
    }
  }

  public function getMetadataInfos($external_url){
    $service_endpoint = $this->url2info_endpoint . '/api/info';
    $url = $service_endpoint .  '?url=' . $external_url;
    $cid = 'metadatainfo:' . md5($external_url);
    $cache = cache_get($cid);
    if ($cache) {
      return $cache->data;
    }

    $client = new \GuzzleHttp\Client([
      'timeout' => 10, // Set timeout to 2 seconds
    ]);
    $data = [];
    try {
      $response = $client->request('GET', $url);
      if ($response->getStatusCode() === 200) {
        $data = json_decode($response->getBody(), TRUE);
      }
    } catch (\Exception $e) {
      //drupal_set_message('Error: ' . $e);
    }
    cache_set($cid, $data);
    return $data;
  }

  public function proxyImageUrl($url){
    $payload = [
      'op' => 'proxy',
      'url' => $url,
    ];
    $token = JWT::encode($payload, $this->url2info_settings['proxy_secret'], 'HS256');
    $proxy_url = $this->url2info_settings['proxy_url'] . '?token=' . $token;
    return $proxy_url;
  }
}
