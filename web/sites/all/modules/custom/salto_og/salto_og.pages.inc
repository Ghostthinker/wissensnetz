<?php

/**
 * Ajax callback for adding and validating new and existing users
 *
 * @param  [type] $op [description]
 *
 * @return [type]     [description]
 */
function salto_og_invite_ajax_callback($gid, $op, $arg = NULL) {
  $data = [];
  $gid = arg(2);

  if (!is_numeric($gid)) {

  }

  if ($op == 'render') {
    if (!empty($_POST['uid'])) {
      $uid = check_plain($_POST['uid']);
      $data += salto_og_ajax_render_membership($gid, $uid);
    }
  }

  if ($op == 'validate') {

    $userdata = $_POST['data'];
    $data += salto_og_ajax_validate_new_user($userdata, $gid);
  }

  if ($op == "search" || $op == "search_api") {
    if (isset($_REQUEST['search'])) {
      $search = check_plain($_REQUEST['search']);
    }

    if (isset($_REQUEST['exclude'])) {

      $exclude_search_uids = $_REQUEST['exclude'];

      foreach ($exclude_search_uids as $uid) {
        if (!is_numeric($uid)) {
          $exclude_search_uids = NULL;
          break;
        }
      }
    }

    $l = check_plain($arg);
    $limit = is_numeric($l) && $l > 0 ? $l : 10;

    if ($op == "search") {
      $data = salto_og_ajax_search($gid, $limit, $search, $exclude_search_uids, FALSE);
    }
    else {
      if ($op == "search_api") {
        $data = salto_og_ajax_search($gid, $limit, $search, $exclude_search_uids, TRUE);
      }
    }

  }
  return drupal_json_output($data);
}

/**
 * Json callback for og member managing. Access is also handle here, so be
 * careful. Errors should be return with drupal_json_output_error("message");
 *
 * @param $gid
 * @param $op
 * @param $uid
 */
function salto_og_manage_ajax_callback($gid, $op, $uid) {

  if (!drupal_valid_token($_GET['token'], 'salto_og_manage')) {
    drupal_json_output_error(t("Wrong csrf token"));
    return;
  }

  $og = node_load($gid);
  $account = user_load($uid);

  switch ($op) {
    case SALTO_ORGANISATION_ACTION_GRANT_LICENSE_MANAGER:

      if (!salto_organisation_membership_action_access(SALTO_ORGANISATION_ACTION_GRANT_LICENSE_MANAGER, $og, $account)) {
        drupal_json_output_error(t("Access denied"));
        return;
      }

      og_role_grant('node', $gid, $uid, SALTO_OG_ROLE_LICENSE_MANAGER_RID);
      og_invalidate_cache($gid);
      break;
    case SALTO_ORGANISATION_ACTION_REVOKE_LICENSE_MANAGER:

      if (!salto_organisation_membership_action_access(SALTO_ORGANISATION_ACTION_REVOKE_LICENSE_MANAGER, $og, $account)) {
        drupal_json_output_error(t("Access denied"));
        return;
      }

      og_role_revoke('node', $gid, $uid, SALTO_OG_ROLE_LICENSE_MANAGER_RID);
      og_invalidate_cache($gid);
      break;

    case SALTO_ORGANISATION_ACTION_GRANT_TRAINER:
    case SALTO_ORGANISATION_ACTION_REVOKE_TRAINER:
    case SALTO_ORGANISATION_ACTION_GRANT_EXTERN_TRAINER:
    case SALTO_ORGANISATION_ACTION_REVOKE_EXTERN_TRAINER:
    case SALTO_ORGANISATION_ACTION_GRANT_LICENSE_OWNER:
    case SALTO_ORGANISATION_ACTION_REVOKE_LICENSE_OWNER:
    case SALTO_ORGANISATION_ACTION_GRANT_FURTHER_MEMBER:
    case SALTO_ORGANISATION_ACTION_REVOKE_FURTHER_MEMBER:
    case SALTO_ORGANISATION_ACTION_REMOVE_FROM_ORGANISATION:

      if (!og_user_access('node', $gid, 'manage all members')) {
        drupal_json_output_error(t("Access denied"));
        return;
      }

      switch ($op) {
        case SALTO_ORGANISATION_ACTION_GRANT_TRAINER:
          og_role_grant('node', $gid, $uid, SALTO_OG_ROLE_TRAINER_RID);
          break;
        case SALTO_ORGANISATION_ACTION_REVOKE_TRAINER:
          og_role_revoke('node', $gid, $uid, SALTO_OG_ROLE_TRAINER_RID);
          break;
        case SALTO_ORGANISATION_ACTION_GRANT_EXTERN_TRAINER:
          og_role_grant('node', $gid, $uid, SALTO_OG_ROLE_EXTERN_TRAINER_RID);
          break;
        case SALTO_ORGANISATION_ACTION_REVOKE_EXTERN_TRAINER:
          og_role_revoke('node', $gid, $uid, SALTO_OG_ROLE_EXTERN_TRAINER_RID);
          break;
        case SALTO_ORGANISATION_ACTION_GRANT_LICENSE_OWNER:
          og_role_grant('node', $gid, $uid, SALTO_OG_ROLE_LICENSE_OWNER_RID);
          break;
        case SALTO_ORGANISATION_ACTION_REVOKE_LICENSE_OWNER:
          og_role_revoke('node', $gid, $uid, SALTO_OG_ROLE_LICENSE_OWNER_RID);
          break;
        case SALTO_ORGANISATION_ACTION_GRANT_FURTHER_MEMBER:
          og_role_grant('node', $gid, $uid, SALTO_OG_ROLE_FURTHER_MEMBER_RID);
          break;
        case SALTO_ORGANISATION_ACTION_REVOKE_FURTHER_MEMBER:
          og_role_revoke('node', $gid, $uid, SALTO_OG_ROLE_FURTHER_MEMBER_RID);
          break;
        case SALTO_ORGANISATION_ACTION_REMOVE_FROM_ORGANISATION:
          $account = user_load($uid);

          //remove from organisation first
          og_ungroup('node', $gid, 'user', $uid);
          break;
      }
      og_invalidate_cache($gid);
  }

  $result['actions'] = theme('og_manage_action_links', [
    'og' => $og,
    'account' => $account,
  ]);

  $result['details'] = salto_organisation_user_duties_render($gid, $uid);

  return drupal_json_output($result);
}



