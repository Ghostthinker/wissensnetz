<?php

define('SALTO_GROUP_JOIN_OPEN', -1);
define('SALTO_GROUP_JOIN_SELECTED_ORGANISATIONS', 1);
define('SALTO_GROUP_JOIN_REQUIRE_APPROVAL', 2);
define('SALTO_GROUP_JOIN_ON_INVITATION', 4);
define('SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP', 3);


/**
 * Implements hook_salto_post_access_options_alter
 *
 * @param  [type] $op      [description]
 * @param  [type] $options [description]
 *
 * @return [type]          [description]
 */
function salto_group_salto_post_access_options_alter($op, &$options) {

  $context = og_context();

  //media post attachment ajax field
  if (arg(0) == 'media' && arg(1) == 'ajax') {
    $referer_url = parse_url($_SERVER['HTTP_REFERER']);
    $node_path = substr($referer_url['path'], 1);

    //add new post
    if ($referer_url['path'] == '/node/add/post') {
      parse_str($referer_url['query'], $query_params);
      if (!empty($query_params['field_og_group']) && is_numeric($query_params['field_og_group'])) {
        $context = ['gid' => $query_params['field_og_group']];
      }
    }
    else {
      if (arg(0, $node_path) == 'node' && is_numeric(arg(1, $node_path))) {
        $node = node_load(arg(1, $node_path));

        if (!empty($node->field_og_group)) {
          $context = ['gid' => $node->field_og_group[LANGUAGE_NONE][0]['target_id']];
        }

      }
    }
  }

  $is_on_group_add_page = (arg(0) == 'node' && arg(1) == 'add' && arg(2) == 'group');
  $is_on_group_content_admin_page = (arg(0) == 'admin' && arg(1) == 'structure' && arg(2) == 'types' && arg(3) == 'manage' && arg(4) == 'group');


  if (!empty($context['gid']) || $is_on_group_add_page || $is_on_group_content_admin_page) {
    if (!empty($options[SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS])) {
      $options[SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS] = t('Only authors and group managers');
    }

    //add the only group option
    if ($node = node_load($context['gid'])) {
      //existing
      $options[SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP] = t('Only Group "!group"', ['!group' => $node->title]);
    }
    elseif ($is_on_group_content_admin_page) {
      $options[SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP] = t('Only Group (from context)');
    }
    else {
      $options[SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP] = t('Only this Group');
    }
  }
}


/**
 * Implements hook_node_access_records().
 */
function salto_group_node_access_records($node) {

  $grants = [];

  if (!empty($node->field_post_collaboration[LANGUAGE_NONE][0]) && !empty($node->field_og_group[LANGUAGE_NONE][0]['target_id'])) {
    $access_option = $node->field_post_collaboration[LANGUAGE_NONE][0];
    $gid = $node->field_og_group[LANGUAGE_NONE][0]['target_id'];

    //set the access for all salto_members
    $canRead = $access_option['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP;
    $canEdit = $access_option['edit'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP;
    if ($canRead || $canEdit) {
      $grants[] = [
        'realm' => 'og_access:node',
        'gid' => $gid,
        'grant_view' => $canRead || $canEdit ? 1 : 0,
        'grant_update' => $canEdit ? 1 : 0,
        'grant_delete' => 0,
        'priority' => 0,
      ];
    }

    // access for group managers
    $canRead = $access_option['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS;
    $canEdit = $access_option['edit'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS;
    if ($canRead || $canEdit) {
      $grants[] = [
        'realm' => 'salto_manager',
        'gid' => $gid,
        'grant_view' => $canRead || $canEdit ? 1 : 0,
        'grant_update' => $canEdit ? 1 : 0,
        'grant_delete' => 0,
        'priority' => 0,
      ];
    }

  }

  return $grants;
}


/**
 * Implements hook_file_access_records().
 */
function salto_group_file_access_records($file) {

  $grants = [];

  if (!empty($file->field_post_collaboration[LANGUAGE_NONE][0]) && !empty($file->field_og_group[LANGUAGE_NONE][0]['target_id'])) {
    $access_option = $file->field_post_collaboration[LANGUAGE_NONE][0];
    $gid = $file->field_og_group[LANGUAGE_NONE][0]['target_id'];

    //set the access for all salto_members
    if ($access_option['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP || $access_option['edit'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP) {
      $grants[$gid] = [
        'realm' => 'og_access:node',
        'gid' => $gid,
        'grant_view' => $access_option['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP ? 1 : 0,
        'grant_download' => $access_option['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP ? 1 : 0,
        'grant_update' => $access_option['edit'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_GROUP ? 1 : 0,
        'grant_delete' => 0,
        'priority' => 0,
      ];
    }
  }

  //check the rid we got from override check. They can differ  - a fiel can have read access from node/group x and write access from node/group y

  $collaboration_access = salto_files_check_collaboration_override($file);

  if (!empty($collaboration_access['og_extra_access'])) {

    foreach ($collaboration_access['og_extra_access'] as $gid) {

      //may check if there is already a grant
      if (empty($grants[$gid])) {
        $grants[] = [
          'realm' => 'og_access:node',
          'gid' => $gid,
          'grant_view' => 1,
          'grant_download' => 1,
          'grant_update' => 0,
          'grant_delete' => 0,
          'priority' => 0,
        ];
      }
      else {
        $grants[$gid]['grant_view'] = 1;
        $grants[$gid]['grant_download'] = 1;
      }
    }

  }

  return $grants;
}

/**
 * Implements hook_node_access().
 */
function salto_group_node_access($node, $op, $account) {
  $type = is_string($node) ? $node : (is_array($node) ? $node['type'] : $node->type);

  if ($type == 'group' && $op == "delete") {
    $access = og_user_access_entity('delete group', 'node', $node, $account);

    if ($access) {
      return NODE_ACCESS_ALLOW;
    }
  }
  return NODE_ACCESS_IGNORE;
}

