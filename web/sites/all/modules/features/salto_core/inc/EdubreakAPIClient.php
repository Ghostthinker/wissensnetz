<?php

namespace salto_core;
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

  private function sendGET($route, $options = []) {
    return $this->_call('GET', $route, $options);
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
#      print_r($this->client);
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
    print_r($response);
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
