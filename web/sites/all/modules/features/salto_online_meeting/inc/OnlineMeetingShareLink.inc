<?php

class OnlineMeetingShareLink {


  public static function encode($node) {
    return url('online-meeting/attend/' . $node->uuid, array('absolute' => TRUE, 'language' => (object)array('language' => FALSE)));
  }

  public static function decode($url, $skip_access_check = TRUE) {

    $re = '/[a-fA-F0-9]{8}-[a-fA-F0-9]{4}-[a-fA-F0-9]{4}-[a-fA-F0-9]{4}-[a-fA-F0-9]{12}/m';

    preg_match_all($re, $url, $matches, PREG_SET_ORDER, 0);

    if(empty($matches[0][0])) {
      throw new Exception("uuid_not_found");
    }
    $uuid = $matches[0][0];
    $nid =  entity_get_id_by_uuid('node', [$uuid]);
    $node = node_load(reset($nid));
    if(empty($node)) {
      throw new Exception("node_not_found");
    }
    if(!$skip_access_check && !node_access('view', $node)) {
      throw new Exception("node_no_access");
    }

    return $node;

  }

  /**
   * encode $node
   * @param $uid
   * @param int $lifetime
   * @return string
   */
  private function encodeToken($node ) {


    $token_data = array(
      "iat"  => time(),
      # "exp" => time() + $node,
      "jti" => base64_encode(drupal_random_key(32)),
      "nid" => $node->nid

    );
    //   print_r($token_data);
    $token =  \Firebase\JWT\JWT::encode($token_data, variable_get("salto_online_meeting_app_token_secret", "youhouldhavereallysetanapptokensecret"), 'HS256');


    return $token;
  }

  /**
   * Decode $token and return $node
   * @param $token
   * @return mixed
   * @throws \Exception
   */
  private function decodeToken($token) {
    // TODO: Implement authWithToken() method.

    $secretKey = variable_get("salto_online_meeting_app_token_secret", "youhouldhavereallysetanapptokensecret");

    try {
      $data = \Firebase\JWT\JWT::decode($token, $secretKey, array('HS256'));
    } catch (Exception $e) {
      throw new \Exception("token_decode_error");
    }

    $nid = $data->nid;

    if(empty($nid)) {
      throw new \Exception("node_not_found");
    }

    $node = node_load($nid);

    if(empty($node)) {
      throw new \Exception("node_not_found");
    }

    return $node;
  }


}
