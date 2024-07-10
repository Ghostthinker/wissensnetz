<?php


use GuzzleHttp\Client;

class DialogGatewayAPI {


  const DialogSessionTypeMeeting = 0;

  const DialogSessionTypeWebinar = 2;

  const DialogSessionStatusMeetingInProgress = 'meeting_in_progress';

  const DialogSessionStatusWaitingForHost = 'waiting_for_host';

  const DialogSessionStatusMeetingEnded = 'meeting_ended';

  const DialogSessionStatusNotExists = 'StatusDialogNotExists';

  const DialogSessionStatusAllocate = 'allocate';

  const DialogSessionStatusStartDialogFailed = 'start_dialog_failed';

  const DialogSessionStatusStartWebinarFailed = 'start_webinar_failed';

  public $settings;

  function __construct($settings) {
    $this->settings = $settings;
  }

  function validateSettings($settings = NULL) {

    if ($settings == NULL) {
      $settings = $this->settings;
    }

    if (empty($settings['online_meeting_url'])) {
      $errors[] = 'Gateway url not defined';
    }

    if (empty($settings['online_meeting_access_token'])) {
      $errors[] = 'Gateway access token not defined';
    }

    if (empty($settings['online_meeting_instance_url'])) {
      $errors[] = 'Instance URL to pass for webhook callbacks token not defined';
    }

    if ($errors) {
      throw new \Exception($errors);
    }
    return TRUE;
  }

  function getDialogSession($host_id) {

    $client = new Client(['base_uri' => $this->settings['online_meeting_url']]);

    try {
      $response = $client->request('GET', '/api/dialog',
        [
          'query' => ['host' => $host_id],
          'headers' => ['Authorization' => 'Bearer ' . $this->settings['online_meeting_access_token']],
        ]);
    } catch (\GuzzleHttp\Exception\GuzzleException $e) {
      switch ($e->getCode()) {
        case 404:
          return FALSE;
      }

    }

    try {
      $result = json_decode($response->getBody(), TRUE);

      if (json_last_error() !== JSON_ERROR_NONE) {
        return FALSE;
      }

      return $result;
    } catch (\Exception $e) {
      watchdog_exception('dialog_gateway', $e);
    }

  }

  function startDialogSession(array $options) {


    if (empty($options['host'])) {
      throw new \Exception("required host field");
    }

    $defaults = [
      'instance_id' => '',
      'instance_url' => $this->settings['online_meeting_instance_url'],
      'topic' => 'Dialog',
      'type' => self::DialogSessionTypeMeeting,
    ];
    $options = array_merge($defaults, $options);


    $client = new Client(['base_uri' => $this->settings['online_meeting_url']]);

    try {
      $response = $client->request('POST', '/api/dialog',
        [
          'form_params' => $options,
          'headers' => ['Authorization' => 'Bearer ' . $this->settings['online_meeting_access_token']],
          'debug' => FALSE,
        ]);
    } catch (\GuzzleHttp\Exception\GuzzleException $e) {
      watchdog_exception('dialog_gateway', $e);
      return FALSE;
    }

    try {
      $result = json_decode($response->getBody(), TRUE);
      if (json_last_error() !== JSON_ERROR_NONE) {
        return FALSE;
      }

      if (isset($result['body']['start_url'])) {
        return $result['body']['start_url'];
      }

      return $result['body']['join_url'];
    } catch (\Exception $e) {
      watchdog_exception('dialog_gateway', $e);
    }
  }

  public function joinDialogSession(array $options) {
    if (empty($options['host'])) {
      throw new \Exception("required host field");
    }

    $client = new Client(['base_uri' => $this->settings['online_meeting_url']]);

    try {
      $response = $client->request('POST', '/api/dialog/' . urlencode($options['host']) . '/join',
        [
          'headers' => ['Authorization' => 'Bearer ' . $this->settings['online_meeting_access_token']],
          'debug' => FALSE,
        ]);
    } catch (\GuzzleHttp\Exception\GuzzleException $e) {
      watchdog_exception('dialog_gateway', $e);
      return FALSE;
    }

    try {
      $result = json_decode($response->getBody(), TRUE);
      if (json_last_error() !== JSON_ERROR_NONE) {
        return FALSE;
      }

      if (empty($result['body']['join_url'])) {
        return FALSE;
      }

      return $result['body']['join_url'];
    } catch (\Exception $e) {
      watchdog_exception('dialog_gateway', $e);
      return FALSE;
    }
  }

  function getDialogRecordings($host_id) {
    $client = new \GuzzleHttp\Client(['base_uri' => $this->settings['online_meeting_url']]);

    try {
      $response = $client->request('GET', '/api/recordings',
        [
          'query' => ['host' => $host_id],
          'headers' => ['Authorization' => 'Bearer ' . $this->settings['online_meeting_access_token']],
          'debug' => FALSE
        ]);
    } catch (\GuzzleHttp\Exception\GuzzleException $e) {
      //TODO check the 404 which means no diag session  has been started yet
      return FALSE; //TODO better exception
    }

    try {
      $result = json_decode($response->getBody(), TRUE);
      if (json_last_error() !== JSON_ERROR_NONE) {
        //TODO better exception
        return FALSE;
      }

      return $result;
    } catch (\Exception $e) {
      watchdog_exception('dialog_gateway', $e);
    }

  }

  public function deleteDialogRecordings($recordingId, $host_id) {
    $client = new \GuzzleHttp\Client(['base_uri' => $this->settings['online_meeting_url']]);

    try {
      $response = $client->request('DELETE', '/api/recordings/' . $recordingId,
        [
          'query' => ['host' => $host_id],
          'headers' => ['Authorization' => 'Bearer ' . $this->settings['online_meeting_access_token']],
          'debug' => FALSE
        ]);
    } catch (\GuzzleHttp\Exception\GuzzleException $e) {
      //TODO check the 404 which means no diag session  has been started yet
      return FALSE; //TODO better exception
    }

    try {
      $result = json_decode($response->getBody(), TRUE);
      if (json_last_error() !== JSON_ERROR_NONE) {
        //TODO better exception
        return FALSE;
      }

      return $result;
    } catch (\Exception $e) {
      watchdog_exception('dialog_gateway', $e);
    }
  }

}
