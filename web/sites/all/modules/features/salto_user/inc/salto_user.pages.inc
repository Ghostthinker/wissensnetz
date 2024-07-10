<?php


function salto_user_ajax_authorpane_callback($account) {


  $out['content'] = theme('user_picture', [
    "account" => $account,
    'preset' => 'thumbnail',
  ]);
  $out['title'] = format_username($account);

  return $out;
}

/**
 * @return bool
 */
function salto_user_membership_request_ajax_access() {
  $user = salto_user_get_current();

  if (user_has_role(ROLE_GLOBAL_ADMIN_RID, $user)) {
    return TRUE;
  }

  return user_has_role(ROLE_GLOBAL_GARDENER_RID, $user);
}

/**
 * ajax callback for membership requests (accept)
 *
 * @param $uuid
 *
 * @return int
 * @throws OgException
 */
function salto_user_membership_request_ajax_accept($uuid) {
  if (!salto_user_membership_request_ajax_access()) {
    drupal_json_output(['status' => 401, 'error' => t('Access denied')]);
    return 1;
  }
  $uid = check_plain(urldecode($_POST['uid']));
  if ($uid === NULL) {
    drupal_json_output(['status' => 404, 'error' => t('Missing user id!')]);
    return 1;
  }
  $account = user_load($uid);
  if ($account->uuid !== $uuid) {
    drupal_json_output(['status' => 409, 'error' => t('Conflict for user!')]);
    return 1;
  }
  $account->status = 1;
  $nid = $account->data['organisation'];

  $og_membership = og_membership_create('node', $nid, 'user', $uid, 'field_user_organisations', ['state' => 1]);
  $og_membership->save();

  $account = user_save($account);

  $message = check_plain(urldecode($_POST['message']));
  $isSend = salto_user_membership_request_send_mail($account, TRUE, $message);

  if (!$isSend) {
    drupal_json_output([
      'status' => 417,
      'error' => t('Account was accepted, but mail could not send'),
    ]);
  }
  drupal_json_output(['status' => 200, 'message' => 'Ok']);
}

/**
 * ajax callback for membership requests (decline)
 *
 * @param $uuid
 *
 * @return int
 */
function salto_user_membership_request_ajax_decline($uuid) {
  if (!salto_user_membership_request_ajax_access()) {
    drupal_json_output(['status' => 401, 'error' => t('Access denied!')]);
    return 1;
  }
  $uid = check_plain(urldecode($_POST['uid']));
  if ($uid === NULL) {
    drupal_json_output(['status' => 404, 'error' => t('Missing user id!')]);
    return 1;
  }
  $account = user_load($uid);
  if ($account->uuid !== $uuid) {
    drupal_json_output(['status' => 409, 'error' => t('Conflict for user!')]);
    return 1;
  }

  $message = check_plain(urldecode($_POST['message']));
  $isSend = salto_user_membership_request_send_mail($account, FALSE, $message);

  user_delete($account->uid);

  if (!$isSend) {
    drupal_json_output([
      'status' => 417,
      'error' => t('Account was deleted, but mail could not send'),
    ]);
    return 0;
  }
  drupal_json_output(['status' => 200, 'message' => 'Ok']);
}

function salto_user_process_user_status_action_callback($uid, $op){

  $drupalUser = \Wissensnetz\User\DrupalUser::make($uid);

  switch ($op){
    case 'activate':
      salto_user_activate_action($drupalUser->getUser());
      break;
    case 'deactivate':
      salto_user_deactivate_action($drupalUser->getUser());
      break;
  }

  drupal_goto('community-manager/people');
}

function salto_user_process_user_status_action_access(){
  if (!user_access("change user status")){
    return FALSE;
  }
  return TRUE;
}
