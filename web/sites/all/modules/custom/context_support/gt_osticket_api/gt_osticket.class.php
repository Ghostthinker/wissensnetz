<?php

/**
 * Class GTTicket
 * Creating new osTicket Tickets using osTicket API
 *
 * @author Sergej Naumenko
 * @version 1.0
 */

class gt_osTicket {

  private $config;

  public function __construct($_config) {
    $this->config = $_config;
  }

  public function send($data) {

    $config = $this->config;

    set_time_limit(30);

    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $config['url']);
    curl_setopt($ch, CURLOPT_POST, 1);
    curl_setopt($ch, CURLOPT_POSTFIELDS, json_encode($data));
    curl_setopt($ch, CURLOPT_USERAGENT, 'osTicket API Client v1.9');
    curl_setopt($ch, CURLOPT_HEADER, FALSE);
    curl_setopt($ch, CURLOPT_HTTPHEADER, [
      'Expect:',
      'X-API-Key: ' . $config['key'],
    ]);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, FALSE);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
    $result = curl_exec($ch);
    $code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
    curl_close($ch);

    if ($code != 201) {
      $error = 'Unable to create ticket: ' . $result;
      throw new Exception($error);
    }

    $ticket_id = (int) $result;

    return $ticket_id;
  }

}


?>
