<?php

include_once DRUPAL_ROOT . '/sites/all/modules/features/salto_core/queue/CoreSystemQueue.php';

/**
 * Implements hook_cron_queue_info().
 */
function onsite_notification_cron_queue_info() {
  $queues = array();
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_POST_CREATED] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 240, //seconds to spend working on the queue
  );
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_POST_CREATED_GROUP] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 90, //seconds to spend working on the queue
  );
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 240, //seconds to spend working on the queue
  );
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT_REPLY] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 240, //seconds to spend working on the queue
  );
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_REVISION_CREATED] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 240, //seconds to spend working on the queue
  );
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_GROUP_INVITE_RECIEVED] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 30, //seconds to spend working on the queue
  );
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_GROUP_MEMBERSHIP_REQUEST] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 30, //seconds to spend working on the queue
  );
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_GROUP_MEMBERSHIP_REMOVED] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 20, //seconds to spend working on the queue
  );
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_LICENSE_CORRECT_BY] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 30, //seconds to spend working on the queue
  );
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_LICENSE_MIGRATE] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 30, //seconds to spend working on the queue
  );
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_LICENSES_MARKED_FOR_EXTENSION] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 30, //seconds to spend working on the queue
  );
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_LICENSE_FORMS_WERE_REQUESTED] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 30, //seconds to spend working on the queue
  );
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_PRIVATE_MESSAGE_RECEIVED] = array(
    'worker callback' => '_onsite_notification_queue_resolve_create', //function to call for each item
    'time' => 30, //seconds to spend working on the queue
  );
  $queues['onsite_notification_should_mail_immediately'] = [
    'worker callback' => '_onsite_notification_queue_resolve_should_mail_immediately',
    'time' => 360, //seconds to spend working on the queue
  ];
  $queues['onsite_notification_knowledgebase_post_submitted'] = [
    'worker callback' => '_onsite_notification_queue_resolve_knowledgebase_post_submitted',
    'time' => 30, //seconds to spend working on the queue
  ];
  $queues['onsite_notification_comment_insert'] = [
    'worker callback' => '_onsite_notification_queue_resolve_comment_insert',
    'time' => 30, //seconds to spend working on the queue
  ];
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_MATERIAL_UPDATED] = [
    'worker callback' => '_onsite_notification_queue_resolve_create',
    'time' => 30, //seconds to spend working on the queue
  ];
  $queues['onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_MATERIAL_CREATED] = [
    'worker callback' => '_onsite_notification_queue_resolve_create',
    'time' => 30, //seconds to spend working on the queue
  ];
  return $queues;
}

function _onsite_notification_queue_resolve_create($data) {
  $wd_type = 'onsite_notification_queue_resolve';
  watchdog($wd_type, 'Queue create for type %type', ['%type' => $data['type']], WATCHDOG_DEBUG);
  watchdog($wd_type, 'audience: %data', ['%data' => print_r($data['audience'], TRUE)], WATCHDOG_DEBUG);
  watchdog($wd_type, 'context: %data', ['%data' => print_r($data['context'], TRUE)], WATCHDOG_DEBUG);

  _onsite_notification_create($data['type'], $data['audience'], $data['link'], $data['context'], $data['filter']);
}

function _onsite_notification_queue_resolve_should_mail_immediately($data) {
  $item = (object) $data;
  $account = user_load($item->uid);
  $settings = onsite_nottification_settings_load($item->uid);

  $shouldMail = empty($settings['general']) === FALSE && $settings[$item->message_type]->data['mail'] == 1;
  $shouldMailImmediately = $shouldMail && $settings['general']->data['mail_frequency'] == NOTIFICATION_FREQUENCY_IMIDIATE;
  if ($shouldMailImmediately) {
    onsite_notification_send_mail_imidiate($account, $item->message);
  }
}

/**
 * after post update or create
 * step 1. add item (node) onsite_notification_knowledgebase_post_submitted
 * step 2. cron run queue resolver (_onsite_notification_queue_resolve_knowledgebase_post_submitted)
 * step 3. & 4. add audience onsite_notification_create and cron run resolver
 * step 5. & 6. equal and send mails immediately and cron run resolver
 *
 * @param $data
 */
function _onsite_notification_queue_resolve_knowledgebase_post_submitted($data) {
  $node = (object) $data['node'];
  $account = (object) $data['actor'];
  if ($data['is_new']) {
    onsite_notification_post_created($node, $account);
  } else {
    //existing posts got a new revision
    onsite_notification_revision_created($node, $account);
  }
}

/**
 * @param $data
 */
function _onsite_notification_queue_resolve_comment_insert($data) {
  $comment = (object) $data['comment'];
  onsite_notification_comment_created($comment);
}



/**
 * Queue wrapper for onsite_notification_create
 * Create new queue items, split audiences in chunks (for next run)
 * This is called by all notification event wrapper functions
 *
 * @param string $message_type
 *         the machine name of the message_type
 * @param array  $audience
 *         an uid key array with uids of the potential target audience. this
 *         will get filtered according to settings in this function.
 * @param string $link
 *         the link of the mesage - each message has one, needs one
 * @param array  $context
 *         an array with entit context to pass (atm node, comment) keyed by entity
 *         type
 * @param bool   $filter_audience
 */
function onsite_notification_create($message_type, $audience, $link, $context = array(), $filter_audience = TRUE){
  watchdog('onsite_notification_queue', 'Queue create for type %type', ['%type' => $message_type], WATCHDOG_INFO);

  $queue = CoreSystemQueue::create('onsite_notification_create_' . $message_type);

  $chunks = array_chunk($audience, variable_get('notification_queue_create_audience_chunk', 800), true);
  foreach ($chunks as $chunk) {
    $data = [
      'type' => $message_type,
      'audience' => $chunk,
      'link' => $link,
      'context' => $context,
      'filter' => $filter_audience
    ];
    $queue->createItem($data);
  }
}

/**
 * Create a new notification. This is called by all notification event wrapper
 * functions
 *
 * @param string $message_type
 *         the machine name of the message_type
 * @param array  $audience
 *         an uid key array with uids of the potential target audience. this
 *         will get filtered according to settings in this function.
 * @param string $link
 *         the link of the mesage - each message has one, needs one
 * @param array  $context
 *         an array with entit context to pass (atm node, comment) keyed by entity
 *         type
 * @param bool   $filter_audience
 *
 * @return null
 * @throws EntityMetadataWrapperException
 */
function _onsite_notification_create($message_type, $audience, $link, $context = array(), $filter_audience = TRUE) {

  $account = $context['actor'];
  // remove audience for actor => no notify
  unset($audience[$account->uid]);
  //create the message entity stub
  $message = message_create($message_type, [], $account);

  watchdog('onsite-notification', 'Audience count unfiltered %count', ['%count' => count($audience)], WATCHDOG_INFO);
  //filter the audience by notification settings; EVIL has big audience and now filter out (better like filter in)
  onsite_notification_filter_audience($audience, $message_type);
  watchdog('onsite-notification', 'Notification create after filtered, type %type', ['%type' => $message_type],
    WATCHDOG_INFO);


  //Create entity wrapper
  $wrapper = entity_metadata_wrapper('message', $message);


  //set systemuser
  if ($message_type == "notification_licenses_marked_for_extension") {
    $wrapper->user->set(0);
  }

  //set link
  $wrapper->field_notification_link->set($link);

  //set the matching context
  if (!empty($context['node'])) {
    $wrapper->field_notification_node_ref->set($context['node']);
  }

  //set the matching context
  if (!empty($context['group'])) {
    $wrapper->field_notification_group_ref->set($context['group']);
  }

  if (!empty($context['note'])) {
    /*$note = array(
      'value' => $context['note'],
      'format' => 'editor',
    );*/
    $wrapper->field_notification_note->set($context['note']);
  }

  if (!empty($context['metadata'])) {
    $wrapper->field_notification_metadata->set($context['metadata']);
  }

  if (!empty($context['tooltip'])) {
    $wrapper->field_notification_tooltip->set($context['tooltip']);
  }

  if (!empty($context['comment'])) {
    $wrapper->field_notification_comment_ref->set($context['comment']);
  }

  if (!empty($context['salto_invite'])) {
    $wrapper->field_notification_invite_ref->set($context['salto_invite']);
  }

  if (!empty($context['privatemsg'])) {
    $wrapper->field_notification_privatemsg->set($context['privatemsg']);
  }

  if (!empty($context['file'])) {
    $wrapper->field_notification_file_ref->set($context['file']);
  }

  if (!empty($context['a_new_fancy_context'])) {
    //....
  }

  //check if audience has view access for the referenced entity
  //check for nodes and node access
  if (!empty($context['node']) || !empty($context['comment'])) {
    watchdog('onsite-notification', 'Node or comment is not empty', [], WATCHDOG_INFO);

    foreach ($audience as $au_uid_key => $au_uid_val) {

      $account = user_load($au_uid_key);
      if (!onsite_notification_message_access('view', $message, $account)) {
        unset($audience[$au_uid_key]);
      }
    }
  }

  //set audience
  $wrapper->field_notification_audience->set(array_keys($audience));

  //create the message
  $wrapper->save();

  watchdog('onsite-notification', 'After module invoke', [], WATCHDOG_INFO);
  watchdog('onsite-notification', 'Audience count %count', ['%count' => count($audience)], WATCHDOG_INFO);

  foreach ($audience as $uid => $value) {
    $data = [
      'uid' => $uid,
      'message_type' => $message_type,
      'message' => $message
    ];
    $queue = CoreSystemQueue::create('onsite_notification_should_mail_immediately');
    $queue->createItem($data);
  }
  watchdog('onsite-notification', 'Create notification function end', [], WATCHDOG_INFO);
  return null;
}
