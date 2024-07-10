<?php
/**
 * @file events and wrapperw for notifications
 *
 * To creat new events, see technical docs!
 */
define('MESSAGE_TYPE_NOTIFICATION_GROUP_INVITE_RECIEVED', 'notification_group_invite_recieved');
define('MESSAGE_TYPE_NOTIFICATION_GROUP_MEMBERSHIP_REQUEST', 'notification_group_membership_request');
define('MESSAGE_TYPE_NOTIFICATION_LICENSE_CORRECT_BY', 'notification_license_correct_by');
define('MESSAGE_TYPE_NOTIFICATION_LICENSE_MIGRATE', 'notification_license_migrate');
define('MESSAGE_TYPE_NOTIFICATION_LICENSES_MARKED_FOR_EXTENSION', 'notification_licenses_marked_for_extension');
define('MESSAGE_TYPE_NOTIFICATION_LICENSE_FORMS_WERE_REQUESTED', 'notification_license_forms_were_requested');
define('MESSAGE_TYPE_NOTIFICATION_PRIVATE_MESSAGE_RECEIVED', 'notification_private_message_received');
define('MESSAGE_TYPE_NOTIFICATION_GROUP_MEMBERSHIP_REMOVED', 'notification_group_membership_removed');
define('MESSAGE_TYPE_NOTIFICATION_REVISION_CREATED', 'notification_revision_created');
define('MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT_REPLY', 'notification_create_comment_reply');
define('MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT', 'notification_create_comment');
define('MESSAGE_TYPE_NOTIFICATION_USER_MENTIONED', 'notification_user_mentioned');
define('MESSAGE_TYPE_NOTIFICATION_POST_CREATED_GROUP', 'notification_group_post_created');
define('MESSAGE_TYPE_NOTIFICATION_POST_CREATED', 'notification_post_created');
define('MESSAGE_TYPE_NOTIFICATION_MATERIAL_UPDATED', 'notification_material_updated');
define('MESSAGE_TYPE_NOTIFICATION_MATERIAL_CREATED', 'notification_material_created');
define('MESSAGE_TYPE_NOTIFICATION_ONLINE_MEETING_SCHEDULED', 'notification_online_meeting_scheduled');


/**
 * Implements hook_comment_insert().
 *
 * @param $comment
 */
function onsite_notification_comment_insert($comment) {

  $data = [
    'comment' => $comment,
  ];

  $queue = CoreSystemQueue::create('onsite_notification_comment_insert');
  $queue->createItem($data);
}

/**
 * Implements hook_node_update().
 */
function onsite_notification_node_update($node) {
  //check autoflags -  auto subscribes authors

  if (!empty($node->salto_file)) {
    onsite_notification_autoflag('file', $node);
  }
  else {
    onsite_notification_autoflag('node', $node);
  }

}


/**
 * Implements hook_node_insert
 *
 * @return [type] [description]
 */
function onsite_notification_node_insert($node) {
  onsite_notification_autoflag('node', $node);
}

/**
 * Implements hook_salto_invite_created
 *
 * @param  [type] $invite [description]
 *
 * @return [type]         [description]
 */
function onsite_notification_salto_invite_created($invite) {

  if ($invite->type == 'accept_invite') {
    $wrapper = entity_metadata_wrapper('salto_invite', $invite);

    $inviter = user_load($invite->uid);
    $audience = [$wrapper->field_salto_invite_account->value()->uid => $wrapper->field_salto_invite_account->value()->uid];
    $og = $wrapper->field_salto_invite_og->value();
    $link = url('node/' . $og->nid);

    $context = [
      'node' => $og,
      'salto_invite' => $invite,
      'actor' => $inviter,
    ];

    onsite_notification_create(MESSAGE_TYPE_NOTIFICATION_GROUP_INVITE_RECIEVED, $audience, $link, $context);
  }
}

/**
 * Implements  hook_salto_group_membership_requested
 *
 * @param  [type] $group   [description]
 * @param  [type] $account [description]
 */
function onsite_notification_salto_group_membership_requested($group, $account) {

  $rid = salto_og_get_admin_rid($group->nid);
  $audience = [];
  $group_admins = salto_og_get_users_by_roles($group->nid, [$rid]);

  foreach ($group_admins as $value) {
    $audience[$value->uid] = $value->uid;
  }

  $link = url('node/' . $group->nid . '/people');

  $context = [
    'node' => $group,
    'actor' => $account,
  ];

  onsite_notification_create(MESSAGE_TYPE_NOTIFICATION_GROUP_MEMBERSHIP_REQUEST, $audience, $link, $context);
}

/**
 * Wrapper for the notification_group_post_created event
 *
 * @param $node
 * @param $account
 */
function onsite_notification_post_created($node, $account) {

  //wrapping in url() function causes usr/bin prefix in tests
  $link = '/node/' . $node->nid;

  $audience = _onsite_notification_node_get_subscribers($node);

  $context = ['node' => $node, 'actor' => $account];

  $hasReadAccessAll = onsite_notification_entity_has_read_access_all($node);
  $isPostInGroup = onsite_notification_entity_has_group($node);
  if ($isPostInGroup) {

    $context['group'] = node_load($node->field_og_group[LANGUAGE_NONE][0]['target_id']);
    $group_members = salto_og_get_users_by_og($context['group']->nid);
    $audience += $group_members;
  }

  if ($isPostInGroup && !$hasReadAccessAll) {
    $message_type = MESSAGE_TYPE_NOTIFICATION_POST_CREATED_GROUP;
  }
  else {
    onsite_notification_add_audience_for_entity_create($audience, $node);
    $message_type = MESSAGE_TYPE_NOTIFICATION_POST_CREATED;
  }

  onsite_notification_create($message_type, $audience, $link, $context);
}

/**
 * Extend the audience for users that have
 * MESSAGE_TYPE_NOTIFICATION_POST_CREATED enabled and are interested in the
 * category of the entity
 *
 * @param $audience
 * @param $entity
 *
 * @return int[]
 */
function onsite_notification_add_audience_for_entity_create(&$audience, $entity, $message_type = MESSAGE_TYPE_NOTIFICATION_POST_CREATED): array {
  $tmpAudience = onsite_notification_get_users_that_have_enabled_message_type($message_type);
  $diff = array_diff_key($tmpAudience, $audience);
  $tmpAudience = user_load_multiple($diff);
  $isPostInGroup = onsite_notification_entity_has_group($entity);


    foreach ($tmpAudience as $user) {
      if (!$isPostInGroup){
        if (salto_user_interested_in_entity($entity, $user)) {
          $audience += [$user->uid => (int) $user->uid];
        }
      }else{
        $audience += [$user->uid => (int) $user->uid];
      }

    }
  return $audience;
}


/**
 * Wrapper for the notification_create_comment event and create parent comment
 * event
 *
 * @param  [type] $comment [description]
 *
 * @return [type]          [description]
 */
function onsite_notification_comment_created($comment) {

  $account = user_load($comment->uid);
  $node = node_load($comment->nid);

  if (!empty($comment->parent_comment)){
    $drupalUser = \Wissensnetz\User\DrupalUser::byGuid($comment->parent_comment['user_id']);
    $parent_comment = new stdClass();
    $parent_comment->uid = $drupalUser->getUid();
  }else if (!empty($comment->pid)) {
    $parent_comment = comment_load($comment->pid);
  }
  $published = $node->status && $comment->status;
  if (!$published) {
    return;
  }


  if ($node->type === SALTO_FILE_COMMENT_NODE_TYPE) {
    $file = salto_files_comment_node_get_file($node);
    $audience = _onsite_notification_material_get_subscribers($file);
  }
  else {
    $audience = _onsite_notification_node_get_subscribers($node);
  }

  if (!empty($audience[$comment->uid])) {
    unset($audience[$comment->uid]);
  }


  if($comment->metadata['svs_comment']){
    $queryParameters = $comment->metadata['link_parameter'];
    $link = url('node/' . $node->nid, ['query' => $queryParameters]);
  }else{
    $link = url('node/' . $node->nid, ['fragment' => 'comment-' . $comment->cid]);
  }



  $context = [
    'node' => $node,
    'comment' => $comment,
    'actor' => $account,
    'metadata' => json_encode($comment->metadata) ?? NULL
  ];

  $socialVideoService = new \SocialVideoService\SocialVideoService();

  //send the mentioned users own notification
  if(!empty($comment->mentionedIds)){

    $mentioned_audience = $socialVideoService->getMentionedUserIds($comment->mentionedIds);
    foreach($mentioned_audience as $key => $uid){
      unset($audience[$uid]);
    }

    $message_type = MESSAGE_TYPE_NOTIFICATION_USER_MENTIONED;
    onsite_notification_create($message_type, $mentioned_audience, $link, $context);

  }

  $message_type = MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT;
  onsite_notification_create($message_type, $audience, $link, $context);

  //send the parent comment author own notification
  if (!empty($parent_comment)) {

    if (!empty($audience[$parent_comment->uid])) {
      unset($audience[$parent_comment->uid]);
    }
    $parent_audience = [];
    $parent_audience[$parent_comment->uid] = $parent_comment->uid;

    if(!empty($comment->mentionedIds)){
      $mentioned_audience = $socialVideoService->getMentionedUserIds($comment->mentionedIds);
      foreach($mentioned_audience as $key => $uid){
        unset($parent_audience[$uid]);
      }
    }

    $message_type = MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT_REPLY;
    onsite_notification_create($message_type, $parent_audience, $link, $context);
  }


}


/**
 * Wrapper for the notification_revision_created event
 *
 * @param $node
 * @param $account
 *
 * @return void [type]       [description]
 */
function onsite_notification_revision_created($node, $account) {

  if (!empty($node->salto_ignore_notification) && $node->salto_ignore_notification == TRUE) {
    return;
  }

  //message link
  $link = url('node/' . $node->nid);
  $audience = _onsite_notification_node_get_subscribers($node);

  $context = [
    'node' => $node,
    'actor' => $account,
  ];

  onsite_notification_create(MESSAGE_TYPE_NOTIFICATION_REVISION_CREATED, $audience, $link, $context);
}

/**
 * Implements hook_salto_share_with_people
 *
 * @return void [type] [description]
 */
function onsite_notification_salto_share_with_people($message_type, $audience, $link, $context = []) {
  $context['actor'] = salto_user_get_current();
  onsite_notification_create($message_type, $audience, $link, $context);
}


/**
 * Implements  hook_salto_group_membership_removed
 *
 * @param  [type] $group   [description]
 * @param  [type] $account [description]
 *
 * @return void [type]          [description]
 */
function onsite_notification_salto_group_membership_removed($group, $account) {

  global $user;
  if ($user->uid == $account->uid) {
    return;
  }

  //message link
  $link = url('node/' . $group->nid);//. '/revisions/'.$node->vid . '/view');
  $audience = [$account->uid => $account->uid];

  $context = [
    'node' => $group,
    'actor' => $user,
  ];

  onsite_notification_create(MESSAGE_TYPE_NOTIFICATION_GROUP_MEMBERSHIP_REMOVED, $audience, $link, $context);
}


/**
 * Implements hook_privatemsg_message_insert().
 *
 * @param $message
 */
function onsite_notification_privatemsg_message_insert($message) {

  $audience = [];
  foreach ($message->recipients as $recipient) {
    $audience[$recipient->uid] = $recipient->uid;
  }

  $uri = entity_uri('privatemsg_message', $message);
  $link = url($uri['path']);

  $context = [
    'privatemsg' => $message,
    'actor' => salto_user_get_current(),
  ];

  onsite_notification_create(MESSAGE_TYPE_NOTIFICATION_PRIVATE_MESSAGE_RECEIVED, $audience, $link, $context);

}

/**
 * Implements dosb_license_initially_requested
 *
 * @param $node
 * @param $init_licenses
 * @param $account
 */
function onsite_notification_dosb_license_initially_requested($node, $init_licenses, $account) {

  $audience = [];

  if ($node == NULL) {

    $license = $init_licenses;
    $organisation_nid = $init_licenses->og_nid;
    $organisation = node_load($organisation_nid);

    if (!empty($license->wbm_nid)) {
      $lehrgang = node_load($license->wbm_nid);
      $ausbildung = node_load($license->ea_nid);
      $message = "(" . $organisation->title . ") hat im Rahmen des Lehrgangs " . $lehrgang->title . " eine Lizenz für " . $ausbildung->title . " angefordert.";
    }
    else {
      $message = "(" . $organisation->title . ") hat eine Lizenz angefordert";
    }
  }

  switch ($node->type) {
    case 'weiterbildungsmassnahme':
      $lehrgang_wrapper = entity_metadata_wrapper('node', $node);
      $organisation = $lehrgang_wrapper->field_wbm_organisation->value();
      $organisation_nid = $organisation->nid;
      $ea = $lehrgang_wrapper->field_wbm_ea_ref->value();
      $message = "(" . $organisation->title . ") hat im Rahmen des Lehrgangs " . $node->title . " " . format_plural(count($init_licenses), "eine Lizenz", " @count Lizenzen") . " für " . $ea->title . " angefordert.";
      break;
    case 'organisation':
      $organisation_nid = $node->nid;
      $organisation = node_load($organisation_nid);
      $message = "(" . $organisation->title . ") hat " . format_plural(count($init_licenses), "eine Lizenz", " @count Lizenzen") . " angefordert.";
      break;
  }

  $dachorganisation = salto_organisation_get_dachorganisation($organisation);
  $dv_members = salto_og_get_users_by_roles($dachorganisation->nid, [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);
  $org_members = [];
  if ($dachorganisation->nid != $dachorganisation->nid) {
    $org_members = salto_og_get_users_by_roles($organisation->nid, [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);
  }

  $members = array_merge($dv_members, $org_members);

  foreach ($members as $member) {
    $audience[$member->uid] = $member->uid;
  }

  $link = url('organisations/' . $organisation_nid . '/licenses');

  $context = [
    'note' => $message,
    'actor' => $account,
  ];

  onsite_notification_create(MESSAGE_TYPE_NOTIFICATION_LICENSE_FORMS_WERE_REQUESTED, $audience, $link, $context);
}

/**
 * @param $organisation
 * @param $identifier
 */
function onsite_notification_licenses_marked_for_extension($organisation, $identifier) {

  $audience = [];
  $lm_members = salto_og_get_users_by_roles($organisation->nid, [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);

  foreach ($lm_members as $member) {
    $audience[$member->uid] = $member->uid;
  }

  $link = url('organisation/' . $organisation->nid . '/licenses/extendmarkedlicenses/' . $identifier);
  $message_type = MESSAGE_TYPE_NOTIFICATION_LICENSES_MARKED_FOR_EXTENSION;

  $metadata = ["week" => $identifier];

  $context = [
    'metadata' => serialize($metadata),
    'tooltip' => t('Notification: License ready for extensions tooltip'),
    'node' => $organisation,
  ];

  onsite_notification_create($message_type, $audience, $link, $context);

}

/**
 * Implements hook_og_membership_insert().
 */
function onsite_notification_og_membership_insert($og_membership) {
  onsite_notification_autoflag_on_membership_activation($og_membership);
}

/**
 * Implements hook_og_membership_insert().
 *
 */
function onsite_notification_og_membership_update($og_membership) {
  if ($og_membership->state == OG_STATE_ACTIVE) {
    onsite_notification_autoflag_on_membership_activation($og_membership);
  }
  else {
    onsite_notification_unflag_on_membership_deactivation($og_membership);
  }
}

/**
 * Wrapper for autoflagging groups when people join as ACTIVE members
 *
 * @param $og_membership
 */
function onsite_notification_autoflag_on_membership_activation($og_membership) {
  if ($og_membership->entity_type == 'user' && $og_membership->type == 'group_membership' && $og_membership->state == OG_STATE_ACTIVE) {
    $gid = $og_membership->gid;
    $account = user_load($og_membership->etid);
    flag('flag', 'notification_subscribe_node', $gid, $account);
  }
}

/**
 * Wrapper for unflagging a group when a member leaves a group or the status
 * becomes NOT ACIVE (pending, blocked)
 *
 * @param $og_membership
 */
function onsite_notification_unflag_on_membership_deactivation($og_membership) {
  if ($og_membership->entity_type == 'user' && $og_membership->type == 'group_membership' && $og_membership->state != OG_STATE_ACTIVE) {
    $gid = $og_membership->gid;
    $account = user_load($og_membership->etid);
    flag('unflag', 'notification_subscribe_node', $gid, $account);
  }
}

/**
 * Implements hook_og_membership_delete().
 *
 * user leaving Group
 */
function onsite_notification_og_membership_delete($og_membership) {
  onsite_notification_unflag_on_membership_deactivation($og_membership);
}

/**
 * subscribing to group - flag all content
 *
 * Implements hook_flag_flag().
 */
function onsite_notification_flag_flag($flag, $entity_id, $account, $flagging) {
  if ($flag->name == 'notification_subscribe_node') {
    $node = node_load($entity_id);
    if ($node->type == 'group') {
      onsite_notification_flag_group_content($node, $account);
    }
  }
}

/**
 * unsubscribing from group - flag all content
 *
 * Implements hook_flag_unflag().
 */
function onsite_notification_flag_unflag($flag, $entity_id, $account, $flagging) {
  if ($flag->name == 'notification_subscribe_node') {
    $node = node_load($entity_id);
    if ($node->type == 'group') {
      onsite_notification_unflag_group_content($node, $account);
    }
  }
}


/**
 * Implements hook_privatemsg_message_insert().
 *
 * @param $migration_request
 * @param $requester
 */
function onsite_notification_license_migration_requested($migration_request, $requester) {

  $audience = [];
  $dosb_license = dosb_license_load($migration_request['lid']);

  $target_verband = node_load($migration_request['target_og_nid']);

  $members = salto_og_get_users_by_roles($migration_request['source_og_nid'], [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);
  foreach ($members as $member) {
    $audience[$member->uid] = $member->uid;
  }

  $uri = entity_uri('dosb_license', $dosb_license);
  $link = url($uri['path']);

  $message = "(" . $target_verband->title . ") " . t("has requested a migration for the license: !license_number", ["!license_number" => $dosb_license->license_number_dosb]);

  $context = [
    'note' => $message,
    'dosb_license' => $dosb_license,
    'actor' => $requester,
  ];

  onsite_notification_create(MESSAGE_TYPE_NOTIFICATION_LICENSE_MIGRATE, $audience, $link, $context);

}

/**
 * Implements hook_license_migration_processed().
 */
function onsite_notification_license_migration_processed($op, $dosb_license) {

  $migration_request = dosb_license_migration_entry_get($dosb_license->lid);

  if (empty($migration_request)) {
    return;
  }

  $source_verband = node_load($migration_request['source_og_nid']);


  $audience[$migration_request['uid']] = $migration_request['uid'];

  $uri = entity_uri('dosb_license', $dosb_license);
  $link = url($uri['path']);

  if ($op == "accept") {
    $message = "(" . $source_verband->title . ") " . t("hat Ihrer Umzugsanfrage für die Lizenz !license_number zugestimmt", ["!license_number" => $dosb_license->license_number_dosb]);
  }
  else {
    $message = "(" . $source_verband->title . ") " . t("hat Ihre Umzugsanfrage für die Lizenz !license_number abgelehnt", ["!license_number" => $dosb_license->license_number_dosb]);
  }

  $context = [
    'note' => $message,
    'dosb_license' => $dosb_license,
    'actor' => salto_user_get_current(),
  ];
  onsite_notification_create(MESSAGE_TYPE_NOTIFICATION_LICENSE_MIGRATE, $audience, $link, $context);
}

/**
 *  Implements hook_license_migration_direct_migrate().
 *
 * @param DOSBLicense $dosb_license
 * @param $source_og_nid
 * @param $target_og_nid
 */
function onsite_notification_license_migration_direct_migrate($dosb_license, $source_og_nid, $target_og_nid) {

  $uri = entity_uri('dosb_license', $dosb_license);
  $link = url($uri['path']);
  $source_og = node_load($source_og_nid);
  $target_og = node_load($target_og_nid);
  $audience = [];

  $members_source = salto_og_get_users_by_roles($source_og_nid, [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);
  foreach ($members_source as $member) {
    $audience[$member->uid] = $member->uid;
  }
  $members_target = salto_og_get_users_by_roles($target_og_nid, [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);
  foreach ($members_target as $member) {
    $audience[$member->uid] = $member->uid;
  }

  $message = " (" . $source_og->title . ") " . t("hat die Lizenz !license_number nach !zielverband umgezogen", [
      "!license_number" => $dosb_license->license_number_dosb,
      "!zielverband" => $target_og->title,
    ]);

  $context = [
    'note' => $message,
    'dosb_license' => $dosb_license,
    'actor' => salto_user_get_current(),
  ];
  onsite_notification_create(MESSAGE_TYPE_NOTIFICATION_LICENSE_MIGRATE, $audience, $link, $context);
}

/*
 * a notification if prequalifications was correct by (linked) license
 *
 * param $dosb_license  the license was correct by user
 * param $pre_license   the prequalification was correct by $dosb_license
 */
function onsite_notification_license_correct_by($dosb_license, $pre_license) {
  $account = salto_user_get_current();

  $uri = entity_uri('dosb_license', $pre_license);
  $link = url($uri['path']);
  $message_type = MESSAGE_TYPE_NOTIFICATION_LICENSE_CORRECT_BY;

  $audience = [];

  $og = $pre_license->getOrganisation();
  $isObscure = $og->field_organisation_obscure[LANGUAGE_NONE][0]['value'] == '1';
  $isDVNone = $og->field_org_dv_license_settings[LANGUAGE_NONE][0]['value'] === 'none';

  $accessOthers = !$isObscure && !$isDVNone;
  if ($accessOthers) {

    $dv = $pre_license->getDachorganisation();
    $members_source = salto_og_get_users_by_roles($dv->nid, [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);
    foreach ($members_source as $member) {
      $audience[$member->uid] = $member->uid;
    }
  }

  if (count($og->field_org_lsb_inspection) > 0) {
    foreach ($og->field_org_lsb_inspection[LANGUAGE_NONE] as $idx => $arrTargetId) {
      $members_source = salto_og_get_users_by_roles($arrTargetId['target_id'], [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);
      foreach ($members_source as $member) {
        $audience[$member->uid] = $member->uid;
      }
    }
  }

  $members_target = salto_og_get_users_by_roles($pre_license->og_nid, [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);
  foreach ($members_target as $member) {
    $audience[$member->uid] = $member->uid;
  }
  unset($audience[$account->uid]);

  $message = t("Die Lizenzhalterdaten von !pre_number wurden durch die Verknüpfung !license_number übernommen.", [
    "!pre_number" => $pre_license->license_number_dosb,
    "!license_number" => $dosb_license->license_number_dosb,
  ]);

  $context = [
    'note' => $message,
    'dosb_license' => $pre_license,
    'actor' => $account,
  ];

  onsite_notification_create($message_type, $audience, $link, $context);
}


function onsite_notification_material_changed($file) {

  $account = salto_user_get_current();

  //message link
  $link = url('file/' . $file->fid);
  $audience = _onsite_notification_material_get_subscribers($file);

  if (empty($audience)) {
    return;
  }

  $context = [
    'file' => $file,
    'actor' => $account,
  ];

  onsite_notification_create(MESSAGE_TYPE_NOTIFICATION_MATERIAL_UPDATED, $audience, $link, $context);
}


/**
 * Create an onsite notification for all users interested in the node
 *
 * @param $file
 */
function onsite_notification_material_created($file) {

  $drupalFile = \Wissensnetz\Core\File\DrupalFile::make($file->fid);
  if (count($drupalFile->getFileAttachmentNodeReferences()) > 0){
    return;
  }

  $account = salto_user_get_current();

  //message link
  $link = url('file/' . $file->fid);
  $audience = _onsite_notification_material_get_subscribers($file);

  if (empty($audience)) {
    return;
  }

  $context = [
    'file' => $file,
    'actor' => $account,
  ];

  $hasReadAccessAll = onsite_notification_entity_has_read_access_all($file);
  $isPostInGroup = onsite_notification_entity_has_group($file);

  if (!$isPostInGroup && $hasReadAccessAll) {
    onsite_notification_add_audience_for_entity_create($audience, $file);
  }

  onsite_notification_create(MESSAGE_TYPE_NOTIFICATION_MATERIAL_CREATED, $audience, $link, $context);
}



/**
 * Wrapper for the notification_user_mentioned event
 *
 * @param $node
 * @param $account
 *
 * @return void [type]       [description]
 */
function onsite_notification_user_mentioned_comment($mention) {

  $comment = comment_load($mention['entity_id']);
  // $account_mentioned = user_load($mention['uid']);
  $account_author = user_load($mention['auid']);
  $node = node_load($comment->nid);

  $published = $node->status && $comment->status;

  if (!$published) {
    return;
  }

  //get audience for mentioned users
  $audience = [];
  $audience[$mention['uid']] = $mention['uid'];

  // do not notify if user mentions him/herself
  if (!empty($audience[$comment->uid])) {
    unset($audience[$comment->uid]);
  }

  $link = url('node/' . $node->nid, ['fragment' => 'comment-' . $comment->cid]);

  $context = [
    'node' => $node,
    'comment' => $comment,
    'actor' => $account_author,
  ];

  // todo handle via core queue?
  $message_type = MESSAGE_TYPE_NOTIFICATION_USER_MENTIONED;
  onsite_notification_create($message_type, $audience, $link, $context);
}


/**
 * Wrapper for the notification_user_mentioned event
 *
 * @param $node
 * @param $account
 *
 * @return void [type]       [description]
 */
function onsite_notification_user_mentioned_node($mention) {

  $node = node_load($mention['entity_id']);
  // $account_mentioned = user_load($mention['uid']);
  $account_author = user_load($mention['auid']);

  $published = $node->status;

  if (!$published) {
    return;
  }

  //get audience for mentioned users
  $audience = [];
  $audience[$mention['uid']] = $mention['uid'];

  // do not notify if user mentions him/herself
  if (!empty($audience[$node->uid])) {
    unset($audience[$node->uid]);
  }

  $link = url('node/' . $node->nid);

  $context = [
    'node' => $node,
    'actor' => $account_author,
  ];

  // todo handle via core queue?
  $message_type = MESSAGE_TYPE_NOTIFICATION_USER_MENTIONED;
  onsite_notification_create($message_type, $audience, $link, $context);
}

/**
 *
 * @param $node_ot
 */
function onsite_notification_online_meeting_scheduled($node_ot) {

  global $user;
  $account = clone $user;

  $published = $node_ot->status;

  if (!$published) {
    return;
  }

  $context = [
    'node' => $node_ot,
    'actor' => $account,
  ];

  //get audience for all group members except author
  $audience = [];

  $context['group'] = node_load($node_ot->field_og_group[LANGUAGE_NONE][0]['target_id']);
  $group_members = salto_og_get_users_by_og($context['group']->nid);
  $audience += $group_members;

  // do not notify if user mentions him/herself
  if (!empty($audience[$account->uid])) {
    unset($audience[$account->uid]);
  }

  $link = url('node/' . $node_ot->nid);

  $message_type = MESSAGE_TYPE_NOTIFICATION_ONLINE_MEETING_SCHEDULED;
  onsite_notification_create($message_type, $audience, $link, $context);

}
