<?php

include_once 'DialogGatewayAPI.inc';

class OnlineMeetingService {

  /**
   * @var \DialogGatewayAPI
   */
  private $gatewayAPI;


  /**
   * OnlineMeetingService constructor.
   */
  public function __construct($node) {

    $this->settings = salto_online_meeting_get_gateway_settings();
    $this->gatewayAPI = new DialogGatewayAPI($this->settings);
    $this->node = $node;
    $this->og_nid = $group_nid = salto_group_get_group_id_from_node($this->node);

  }


  public function renderJoinLink($bootstrap = FALSE) {

    //do not process actions in an ajax context
    if ($bootstrap) {
      $this->processJoinLinkActions();

      //auto check status
      $js_settings = [
        'online_meeting' => [
          'ajax_poll_interval' => variable_get('online_meeting_polling_interval', 10),
        ],
      ];


      drupal_add_js($js_settings, 'setting');
      drupal_add_js(drupal_get_path('module', 'salto_online_meeting') . '/js/dialog_gateway.js');


      $out = '<div class="alert alert-info">' . t("Loading online meeting information") . '</div>';
      return '<div id="dialog_status" data-nid="' . $this->node->nid . '">' . $out . '</div>';
    }


    $remoteInfo = $this->getRemoteInfo();
    $dialogStatus = $remoteInfo['body']['dialog_status'];

    switch ($dialogStatus) {
      case DialogGatewayAPI::DialogSessionStatusNotExists:
      case DialogGatewayAPI::DialogSessionStatusMeetingEnded:
      case DialogGatewayAPI::DialogSessionStatusAllocate:
      case DialogGatewayAPI::DialogSessionStatusStartDialogFailed:
      case DialogGatewayAPI::DialogSessionStatusStartWebinarFailed:
        try {
          $out = $this->renderStartLinkForDialogSessionNotActive($remoteInfo);
        } catch (\Exception $e) {
        }
        break;
      case DialogGatewayAPI::DialogSessionStatusMeetingInProgress:
        $out = $this->renderStartLinkForDialogSessionActive();
        break;
      case DialogGatewayAPI::DialogSessionStatusWaitingForHost:
        $out = $this->renderStartLinkForDialogSessionWaiting($remoteInfo);
    }


    return $out;
  }

  private function getDialogSessionID() {

    return 'dialog-' . $this->node->nid . "@" . $this->settings['online_meeting_instance_url'];
  }

  public function getRemoteInfo() {
    static $remoteInfo;

    if ($remoteInfo == NULL) {
      $remoteInfo = $this->gatewayAPI->getDialogSession($this->getDialogSessionID());
    }

    if (empty($remoteInfo['body']['dialog_status'])) {
      $remoteInfo['body']['dialog_status'] = DialogGatewayAPI::DialogSessionStatusNotExists;
    }

    return $remoteInfo;
  }

  public function checkAndUpdateLocalStatus() {
    try {
      $remoteInfo = $this->getRemoteInfo();
      $dialogStatus = $remoteInfo['body']['dialog_status'];

      switch ($dialogStatus) {
        case DialogGatewayAPI::DialogSessionStatusMeetingInProgress:
        case DialogGatewayAPI::DialogSessionStatusWaitingForHost:
        case DialogGatewayAPI::DialogSessionStatusAllocate:
          return;
      }
      $this->setStatus(ONLINE_MEETING_STATUS_INACTIVE);

    } catch (\Throwable $t) {
    }
  }

  /**
   * Render the link for the user that is host
   *
   * @return string
   * @throws \Exception
   */
  function renderStartLinkForDialogSessionNotActive($remoteInfo) {

    $group_nid = salto_group_get_group_id_from_node($this->node);
    $has_start_dialog_permission = og_user_access('node', $group_nid, "create online_meeting content");

    $is_webinar = salto_online_meeting_is_webinar($this->node);

    //1) Check if access permissions are set
    if (!$has_start_dialog_permission) {
      return "<div class='alert alert-info'>" . t("Online Meeting has not started yet and will start automatically.") . "</div>";
    }

    //2) check if start timeframe for webinars is ok
    $timeAuthorization = $this->mayStartWebinarTimeAuthorization();
    if ($is_webinar && $timeAuthorization['allowed_to_start'] == FALSE) {
      return "<div class='alert alert-info'>" . $timeAuthorization['message'] . "</div>";

    }

    $dialogStatus = $remoteInfo['body']['dialog_status'];

    $mayStartMeeting = $remoteInfo['body']['capabilities']['start_meeting'];

    // Dialog is startung atm
    if ($dialogStatus == DialogGatewayAPI::DialogSessionStatusAllocate) {
      return "<div class='alert alert-info'>" . t("Meeting Start in progress, please wait") . "</div>";
    }

    //no free meeting slots
    if (!$mayStartMeeting) {
      return "<div class='alert info'>" . t("The meeting cannot be started at the moment.") . "</div>";
    }

    $label = !$is_webinar ?
      t('Start Meeting') :
      t("Start Webinar");


    $query = [
      'action' => 'start_meeting',
    ];

    $additional_info = '';

    //check webinar capabilities

    if ($is_webinar) {

      $mayStartWebinar = FALSE;
      $upgrade_capacity = FALSE;
      $downgrade_capacity = FALSE;

      $desired_capacity = !empty($this->node->field_webinar_size[LANGUAGE_NONE][0]['value']) ? $this->node->field_webinar_size[LANGUAGE_NONE][0]['value'] : 100;
      $webinar_capacities = $remoteInfo['body']['capabilities']['webinar_capacity'];
      if (!in_array($desired_capacity, $webinar_capacities)) {
        //try to find a bigger slot
        foreach ($webinar_capacities as $available_cap) {
          if ($available_cap >= $desired_capacity) {
            $upgrade_capacity = $available_cap;
            $mayStartWebinar = TRUE;
            break;
          }
        }

        //check downgrade capacity
        if (!$mayStartWebinar && count($webinar_capacities)) {
          $downgrade_capacity = end($webinar_capacities);
          $mayStartWebinar = TRUE;
        }

      }
      else {
        $mayStartWebinar = TRUE;
      }
    }

    if ($is_webinar) {

      if (($dialogStatus == DialogGatewayAPI::DialogSessionStatusStartWebinarFailed || $mayStartWebinar == FALSE) && $is_webinar) {

        $label = t('Start Meeting Dialog');
        $additional_info = "<div class='alert alert-error'>" . t('You cannot start a webinar at the moment, but you can start a Online-meeting instead.') . "</div>";
        $query['force_meeting'] = 1;
      }
      elseif ($upgrade_capacity && $mayStartWebinar) {
        $query['upgrade_webinar'] = $upgrade_capacity;
      }
      elseif (!$upgrade_capacity && $mayStartWebinar && $downgrade_capacity) {
        $additional_info = "<div class='alert alert-error'>" . t('You cannot start a webinar with up to %desired attendees but you could start a webinar with the up to %max attendees.', [
            '%max' => $downgrade_capacity,
            '%desired' => $desired_capacity,
          ]) . "</div>";
        $query['upgrade_webinar'] = $downgrade_capacity;
      }
      elseif (!$upgrade_capacity && $mayStartWebinar) {
        $additional_info = "<div class='alert alert-info'>" . t('The max number of attendees for this webinar is %max.', ['%max' => $desired_capacity]) . "</div>";

      }
      else {
        return "tbi downgrade webinar capacity";
      }
    }


    $url = url('node/' . $this->node->nid, [
      'query' => $query,
      'absolute' => TRUE,
    ]);

    $out = $this->renderActionLink($url, $label, ['action_start_meeting'], $additional_info);

    return $out;
  }

  public function mayStartWebinarTimeAuthorization() {

    $date_end = (new DateTime($this->node->field_online_meeting_date[LANGUAGE_NONE][0]['value2']))->getTimestamp() + variable_get('date_default_timezone', 0);
    $now_time = (strtotime('NOW') + variable_get('date_default_timezone', 0));
    $diff_time = ($now_time - $date_end) / 60;

    if ($diff_time >= 0) {
      return ['allowed_to_start' => TRUE];
    }
    $date_start = (new DateTime($this->node->field_online_meeting_date[LANGUAGE_NONE][0]['value']))->getTimestamp() + variable_get('date_default_timezone', 0);
    $diff_time = ($date_start - $now_time) / 60;

    if ($diff_time < 15 && $now_time < $date_end) {
      return ['allowed_to_start' => TRUE];
    }
    return [
      'allowed_to_start' => FALSE,
      'message' => t("This webinar cannot be started before !time", ['!time' => format_date($date_start - 900, 'custom', "d.m.Y H:i", 0)]),
    ];
  }

  function renderStartLinkForDialogSessionActive() {

    $url = url('node/' . $this->node->nid, [
      'query' => ['action' => 'join_meeting'],
      'absolute' => TRUE,
    ]);

    return $this->renderActionLink($url, t("Join Meeting"), ['action_join_meeting']);
  }

  private function renderStartLinkForDialogSessionWaiting($remoteInfo) {
    $out = '';

    $group_nid = salto_group_get_group_id_from_node($this->node);

    $has_start_dialog_permission = og_user_access('node', $group_nid, "create online_meeting content");


    if ($has_start_dialog_permission) {
      $out .= "<div class='alert alert-info'>" . t("Waiting for host to start") . "</div>";

      if (!empty($remoteInfo['body']['force_start_url'])) {
        $out = "<div class='alert alert-info'>" . t("The Meeting has been started but there is no host attending. Click !here to take over as host or wait a few more moments.", ['!here' => l(t('here'), $remoteInfo['body']['force_start_url'])]) . "</div>";
      }

    }
    else {
      return $this->renderStartLinkForDialogSessionNotActive($remoteInfo);
    }

    return $out;
  }

  /**
   * Process all url statuses
   *
   * @throws \Exception
   */
  private function processJoinLinkActions() {

    $action = check_plain($_GET['action']);

    //start meeting or webinar
    if ($action == 'start_meeting') {

      if (!$this->checkAccess('start')) {
        drupal_access_denied();
        exit();
      }

      $force_meeting = check_plain($_GET['force_meeting']);
      $force_capacity = isset($_GET['upgrade_webinar']) ? check_plain($_GET['upgrade_webinar']) : NULL;

      return $this->processActionStart($force_meeting, $force_capacity);

    }
    elseif ($action == 'join_meeting') {
      if (!$this->checkAccess('join')) {
        drupal_access_denied();
        exit();
      }
      return $this->processActionJoin();
    }
  }

  /**
   * Check if a user may create, start or join a meeting in context
   *
   * @param $op
   * @param null $account
   *
   * @return bool|mixed|null
   */
  public function checkAccess($op, $account = NULL) {
    switch ($op) {
      case 'create':
        return og_user_access('node', $this->og_nid, "create online_meeting content", $account);
      case 'start':
        return node_access('update', $this->node, $account);
      case 'join':
        return node_access('view', $this->node, $account);
    }
    return FALSE;
  }


  /**
   * Try to start a meeting via gateway call and redirect to external redirect
   * url
   *
   * @param $force_meeting
   *
   * @throws \Exception
   */
  private function processActionStart($force_meeting, $force_capacity = NULL) {

    if (salto_online_meeting_is_webinar($this->node) && !$force_meeting) {
      $meetingType = DialogGatewayAPI::DialogSessionTypeWebinar;
    }
    else {
      $meetingType = DialogGatewayAPI::DialogSessionTypeMeeting;
    }

    if ($force_capacity) {
      //normalize capacity
      if (!is_numeric($force_capacity)) {
        $force_capacity = NULL;
      }
    }

    $dialog_settings = $this->getDialogSessionParameters();

    if ($dialog_settings['large_meeting_1000_enabled']) {
      $force_capacity = 1000;
    }

    $url = $this->gatewayAPI->startDialogSession([
      'host' => $this->getDialogSessionID(),
      'instance_id' => $this->getInstanceId(),
      'topic' => $this->node->title,
      'settings' => $dialog_settings,
      'type' => $meetingType,
      'capacity' => $force_capacity ? $force_capacity : $this->getCapacity(),
    ]);

    if (empty($url)) {
      dpm("DEBUG: Konnte meeting nicht starten!");
      return;
    }
    drupal_goto($url, ['external' => TRUE]);

  }


  /**
   * Get all settings we pass to the  dialog
   *
   * @return array|bool
   */
  private function getDialogSessionParameters() {

    $dialog_settings['password'] = $this->settings['online_meeting_default_meeting_password'] ?? 'wissensnet';
    $dialog_settings['waiting_room'] = 1;
    $dialog_settings['cloud_recording_enabled'] = FALSE;
    $dialog_settings['auto_record'] = FALSE;

    //check large meeting 1000 exceptions
    $dialog_settings['large_meeting_1000_enabled'] = FALSE;

    return $dialog_settings;
  }

  public function getInstanceId() {
    return $this->og_nid;
  }

  private function getCapacity() {

    switch ($this->node->field_webinar_size[LANGUAGE_NONE][0]['value']) {
      case 500:
        return $this->node->field_webinar_size[LANGUAGE_NONE][0]['value'];
      case 1000:
        return $this->node->field_webinar_size[LANGUAGE_NONE][0]['value'];
      default:
        return 100;
    }
  }

  private function processActionJoin() {
    global $user;

    $shorten_username_enabled = variable_get('online_meeting_default_user_name', FALSE);

    if ($shorten_username_enabled) {
      $displayedName = $this->shorten_username($user);
    }
    else {
      $displayedName = format_username($user);
    }


    $url = $this->gatewayAPI->joinDialogSession([
      'host' => $this->getDialogSessionID(),
    ]);

    if (empty($url)) {
      drupal_set_message(t("An error occured, could not join dialog"), 'error');
      return;
    }

    if (!empty($user->uid)) {
      $url .= "&uname=" . urlencode($displayedName);
    }

    drupal_goto($url, ['external' => TRUE]);

  }


  private function renderActionLink($path, $title, $classes = [], $additional_info = '') {

    $classes = array_merge($classes, ['btn', 'btn-warning action_link']);

    $link = [
      '#theme' => 'link',
      '#text' => $title,
      '#path' => $path,
      '#options' => [
        #'query' => array('token' => $crsf_token) + drupal_get_destination(),
        'attributes' => [
          'title' => $title,
          'class' => $classes,
          'target' => '_blank',
        ],
        'html' => TRUE,
      ],
    ];
    $rendered_link = render($link);


    $out = '<div class="pane-action-links">';
    $out .= '<div class="pane-content">' . $rendered_link . '</div>' . $additional_info;
    $out .= '</div>';

    return $out;

  }

  public function setStatus($status) {
    $this->node->field_online_meeting_status[LANGUAGE_NONE][0]['value'] = $status;
    node_save($this->node);
  }


  function shorten_username($user) {
    $account = user_load($user->uid);
    $names = explode(' ', $account->realname);

    $profile_name_last = $names[0];
    $profile_name_first = $names[1];

    if (!$profile_name_first && !$profile_name_last) {
      $shortenedUsername = "";
    }
    else {
      if ($profile_name_first && $profile_name_last) {
        $shortenedUsername = $profile_name_first . ' ' . mb_substr($profile_name_last, 0, 1, "UTF-8") . '.';
      }
      else {
        if ($profile_name_first) {
          $shortenedUsername = $profile_name_first;
        }
        else {
          $shortenedUsername = "";
        }
      }
    }

    return $shortenedUsername;
  }

}