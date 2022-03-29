<?php
namespace Helper;

// here you can define custom actions
// all public methods declared in helper class will be available in $I

class Api extends \Codeception\Module
{

  public function amAuthenticatedAs($account)
  {


    $REST = $this->getModule('REST');

  //  $REST->haveHttpHeader('Authorization', "APIKEY key=$YOUR_APIKEY, secret=$YOUR_SECRET");
    $REST->amHttpAuthenticated($account->name, $account->password_cleartext);

  }


  public function getResponseArray($format = "json") {
    $response = $this->getModule('REST')->response;

    print $response;

    if($format == "json") {
      return (array)json_decode($response, TRUE);
    }
    return $this->_xmlToArray($response);

  }

  private function _xmlToArray($xmlString) {
    $xml = simplexml_load_string($xmlString);
    $json = json_encode($xml);
    $data = json_decode($json, TRUE);
    return $data;
  }

}
