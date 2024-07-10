<?php
//@file access control pr bildungsnetz

use salto_core\service\SettingsService;

define('SALTO_KNOWLEDGEBASE_ACCESS_OPTION_PUBLIC', -1);
define('SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL', 1);
define('SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION', 2);
define('SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS', 4);


/**
 * Implements hook_field_schema().
 */
function salto_knowledgebase_field_schema($field) {
  $columns = [
    'read' => [
      'type' => 'int',
      'length' => 11,
      'not null' => FALSE,
    ],
    'edit' => [
      'type' => 'int',
      'length' => 11,
      'not null' => FALSE,
    ],
  ];
  return [
    'columns' => $columns,
    'indexes' => [
      '' => [],
    ],
  ];
}

/**
 * Implements hook_field_info().
 */
function salto_knowledgebase_field_info() {
  return [
    'salto_collaboration' => [
      'label' => t('Collaboration'),
      'description' => t('Set collaboration node access.'),
      // 'settings' => array('' => ),
      //  'instance_settings' => array('' => ),
      'default_widget' => 'salto_collaboration_select',
      'default_formatter' => 'salto_collaboration_default',
    ],
  ];
}

/**
 * Implements hook_field_widget_info().
 */
function salto_knowledgebase_field_widget_info() {
  return [
    'salto_collaboration_select' => [
      'label' => t('Collaboration'),
      'field types' => ['salto_collaboration'],
      'behaviors' => [
        'multiple values' => FIELD_BEHAVIOR_DEFAULT,
        'default value' => FIELD_BEHAVIOR_DEFAULT,
      ],
    ],
  ];
}

/**
 * Implements hook_field_is_empty().
 */
function salto_knowledgebase_field_is_empty($item, $field) {
  return FALSE;
}

/**
 * Implements hook_field_widget_form().
 */
function salto_knowledgebase_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {

  $read_value = isset($items[$delta]['read']) ? $items[$delta]['read'] : SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL;
  $edit_value = isset($items[$delta]['edit']) ? $items[$delta]['edit'] : SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS;


  $element['read'] = [
    '#type' => 'select',
    '#title' => t('Read access'),
    '#description' => t('Define who can read this post.'),
    '#default_value' => $read_value,
    '#options' => salto_knowledgebase_post_access_options('view'),
  ];

  $element['edit'] = [
    '#type' => 'select',
    '#title' => t('Edit access'),
    '#description' => t('Define who can edit this post.'),
    '#default_value' => $edit_value,
    '#options' => salto_knowledgebase_post_access_options('edit'),
  ];

  return $element;
}


/**
 * Implements hook_field_formatter_info().
 */
function salto_knowledgebase_field_formatter_info() {
  return [
    'salto_collaboration_default' => [
      'label' => t('Collaboration select box'),
      'field types' => ['salto_collaboration'],
    ],
    'salto_taxonomy_term_reference_link' => [
      'label' => t('Salto Taxonomy Link'),
      'field types' => ['taxonomy_term_reference'],
    ],
  ];
}

/**
 * Implements hook_field_formatter_view().
 */
function salto_knowledgebase_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = [];
  $settings = $display['settings'];


  switch ($display['type']) {
    case 'salto_collaboration_default':
      $options = salto_knowledgebase_post_access_options();
      foreach ($items as $delta => $item) {

        $view = !empty($options[$item['read']]) ? $options[$item['read']] : '??';
        $edit = !empty($options[$item['edit']]) ? $options[$item['edit']] : '??';
        $element[$delta] = [
          '#markup' => '<div class="collaboration_read"><div class="field-label">' . t('Read access') . '</div>' . $view . ' </div>' . '<div class="collaboration_edit"><div class="field-label">' . t('Edit access') . '</div>' . $edit . ' </div>',
        ];
      }
      break;
    case 'salto_taxonomy_term_reference_link':
      $options = [];
      $href = 'search/node';
      foreach ($items as $item) {
        $term = taxonomy_term_load($item['tid']);
        $options['query'] = [
          'f[0]' => $field['field_name'] . ':' . $term->tid,
        ];
        $element[] = [
          '#type' => 'link',
          '#title' => $term->name,
          '#href' => $href,
          '#options' => $options,
        ];
      }
      break;
  }

  return $element;
}

/**
 * Get all options for access selection
 *
 * @return [type] [description]
 */
function salto_knowledgebase_post_access_options($op = NULL) {
  $options = [];

  if ($op == 'view') {
    $options[SALTO_KNOWLEDGEBASE_ACCESS_OPTION_PUBLIC] = t('Public');
  }

  $options += [
    SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL => t('All site members'),
    SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION => t('Only organisations of authors'),
    SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS => t('Only authors'),
  ];

  drupal_alter('salto_post_access_options', $op, $options);

  return $options;
}


/**
 * Implements hook_node_access_records().
 */
function salto_knowledgebase_node_access_records($node) {
  $grants = [];
  // We only care about the node if it has been marked private. If not, it is
  // treated just like any other node and we completely ignore it.

  if (!empty($node->field_post_collaboration[LANGUAGE_NONE][0])) {
    $access_option = $node->field_post_collaboration[LANGUAGE_NONE][0];

    //set the access for authors. Authors may always delete, edit and view
    $authors = salto_knowledgebase_post_get_authors($node);
    if (count($authors) > 0) {

      foreach ($authors as $uid) {
        if ($uid != 0) {
          $grants[] = [
            'realm' => 'salto_author',
            'gid' => $uid,
            'grant_view' => 1,
            'grant_update' => 1,
            'grant_delete' => 1,
            'priority' => 0,
          ];
        }
      }
    }


    //set the access for all salto_members
    if ($access_option['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL || $access_option['edit'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL) {
      $grants[] = [
        'realm' => 'salto_member',
        'gid' => 1,
        'grant_view' => $access_option['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL ? 1 : 0,
        'grant_update' => $access_option['edit'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL ? 1 : 0,
        'grant_delete' => 0,
        'priority' => 0,
      ];
    }

    //set access to authors organisations
    if ($access_option['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION || $access_option['edit'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION) {
      //get all groups of the authors
      $authors_orgs = salto_knowledgebase_get_author_organisations($authors);


      foreach ($authors_orgs as $gid) {
        $grants[] = [
          'realm' => 'og_access:node',
          'gid' => $gid,
          'grant_view' => $access_option['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION ? 1 : 0,
          'grant_update' => $access_option['edit'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION ? 1 : 0,
          'grant_delete' => 0,
          'priority' => 0,
        ];
      }
    }

    //public access
    if ($access_option['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_PUBLIC) {
      $grants[] = [
        'realm' => 'salto_public',
        'gid' => 1,
        'grant_view' => 1,
        'grant_update' => 0,
        'grant_delete' => 0,
        'priority' => 0,
      ];
    }

    //post publish access
    if ($node->type === 'post' && $node->field_publishing_options[LANGUAGE_NONE][0]['value'] != POST_PUBLISH_IMMEDIATE){
      foreach($grants as &$grant){
        if ($grant['grant_update'] != 1){
          $grant['grant_view'] = 0;
        }
      }
    }
  }

  return $grants;
}

/**
 * Implements hook_file_access_records().
 */
function salto_knowledgebase_file_access_records($file) {

  $grants = [];
  $authors = [$file->uid => $file->uid];

  $usage = file_usage_list($file);
  foreach ($usage as $type => $data) {
    if (!empty($data['node'])) {
      foreach ($data['node'] as $nid => $active) {
        $node = $data['node'];
        $node = !empty($file->temp_node) && $file->temp_node->nid == $nid ? $file->temp_node : $data['node'];
        if ($node->field_post_collaboration[LANGUAGE_NONE][0]['read'] == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS) {
          $node_authors = salto_knowledgebase_post_get_authors($node);
          $authors += $node_authors;
        }
      }
    }
  }

  if (!empty($file->field_salto_file_type[LANGUAGE_NONE]) && $file->field_salto_file_type[LANGUAGE_NONE][0]['value'] > 0) {
    $authors_orgs = salto_knowledgebase_get_author_organisations($authors);
    foreach ($authors_orgs as $gid) {
      $grants[] = [
        'realm' => 'salto_file:signature:' . SALTO_FILE_TYPE_ORGANISATION_SIGNATURE,
        'gid' => $gid,
        'grant_view' => 1,
        'grant_download' => 1,
        'grant_update' => 1,
        'grant_delete' => 1,
        'priority' => 0,
      ];
    }

  }
  else {
    if (!empty($file->field_post_collaboration[LANGUAGE_NONE][0])) {

      //set the access for authors. Authors may always delete, edit and view
      $access_option = $file->field_post_collaboration[LANGUAGE_NONE][0];

      foreach ($authors as $uid) {
        if ($uid != 0) {
          $grants[] = [
            'realm' => 'salto_author',
            'gid' => $uid,
            'grant_view' => 1,
            'grant_download' => 1,
            'grant_update' => 1,
            'grant_delete' => 1,
            'priority' => 0,
          ];
        }
      }

      $read = $access_option['read'];
      $edit = $access_option['edit'];

      //could be necessary to override settings by node usage
      if ($read_edit = salto_files_check_collaboration_override($file)) {
        $read = $read_edit['read'];
        if ($read_edit['edit'] !== NULL) {
          $edit = $read_edit['edit'];
        }
      }

      //set the access for all salto_members
      if ($read == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL || $edit == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL) {
        $grants[] = [
          'realm' => 'salto_member',
          'gid' => 1,
          'grant_view' => $read == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL ? 1 : 0,
          'grant_download' => $read == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL ? 1 : 0,
          'grant_update' => $edit == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL ? 1 : 0,
          'grant_delete' => 0,
          'priority' => 0,
        ];
      }

      //set access to authors organisations
      if ($read == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION || $edit == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION) {
        //get all groups of the authors
        $authors_orgs = salto_knowledgebase_get_author_organisations($authors);

        foreach ($authors_orgs as $gid) {

          $grants[] = [
            'realm' => 'og_access:node',
            'gid' => $gid,
            'grant_view' => $read == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION ? 1 : 0,
            'grant_download' => $read == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION ? 1 : 0,
            'grant_update' => $edit == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ORGANISATION ? 1 : 0,
            'grant_delete' => 0,
            'priority' => 0,
          ];
        }
      }

      //public access
      if ($read == SALTO_KNOWLEDGEBASE_ACCESS_OPTION_PUBLIC) {
        $grants[] = [
          'realm' => 'salto_public',
          'gid' => 1,
          'grant_view' => 1,
          'grant_download' => 1,
          'grant_update' => 0,
          'grant_delete' => 0,
          'priority' => 0,
        ];
      }
    }


  }

  return $grants;
}


function salto_knowledgebase_file_access_records_alter(&$grants, $file) {

  //publish access
  $drupalFile = \Wissensnetz\Core\File\DrupalFile::make($file->fid);
  if (!$drupalFile->hasPublishedNodeReferences()) {
    foreach ($grants as &$grant) {
      if ($grant['grant_update'] != 1) {
        $grant['grant_view'] = 0;
      }
    }
  }

  return $grants;
}

/**
 * Implements hook_node_grants().
 */
function salto_knowledgebase_node_grants($account, $op) {

  //set the member realm to all users accept anonym and blocked
  if (!empty($account->uid)) {
    $grants['salto_member'] = [1];
  }

  //public access, everbody can see it
  $grants['salto_public'] = [1];

  //set the author realm
  if ($account->uid != 0) {
    $grants['salto_author'] = [$account->uid];
  }

  //this is what og access does... but we do not use og access
  if ($groups = og_get_entity_groups('user', $account)) {
    foreach ($groups as $group_type => $gids) {
      foreach ($gids as $gid) {
        if (salto_group_user_is_manager($account->uid, $gid)) {
          $grants['salto_manager'][] = $gid;
        }
        if ($account->uid != 0) {
          $realm = 'og_access:' . $group_type;
          $grants[$realm][] = $gid;
          $realm = 'salto_file:signature:' . SALTO_FILE_TYPE_ORGANISATION_SIGNATURE;
          $grants[$realm][] = $gid;
        }
      }
    }
  }

  return $grants;
}

/**
 * Implements hook_file_grants().
 */
function salto_knowledgebase_file_grants($account, $op) {

  //same as node grants
  $grants = salto_knowledgebase_node_grants($account, $op);
  return $grants;
}


/**
 * Implements hook_field_attach_form().
 */
function salto_knowledgebase_field_attach_form($entity_type, $entity, &$form, &$form_state, $langcode) {

  $drupalUser = \Wissensnetz\User\DrupalUser::current();

  //hide the collaboration and author field
  if ($entity_type == 'node' && !empty($entity->field_post_collaboration)) {
    //only authors and admins can edit all permissions
    $access = FALSE;
    if (user_access('edit any collaboration access')) {
      $access = TRUE;
    }
    global $user;
    $authors = salto_knowledgebase_post_get_authors($entity);

    if (!empty($authors[$user->uid])) {
      $access = TRUE;
    }

    drupal_alter('field_post_collaboration_access', $access, $entity);
    if(SettingsService::assignGroupsRetrospectivelyEnabled() && $drupalUser->isCommunityManager()){
      $access = TRUE;
    }

    $form['field_post_collaboration']['#access'] = $access;

    //hide the collaboration and author field
    if (!empty($form['field_post_authors'])) {
      $form['field_post_authors']['#access'] = $access;
    }
  }

  if ($entity_type == 'file' && !empty($entity->field_post_collaboration)) {
    $access = FALSE;


    $access_details = salto_files_check_collaboration_override($entity);
    //dpm(salto_files_check_collaboration_override($entity));
    if (isset($access_details['read']) && $access_details['read'] != $access_details['read_original']) {
      $form['field_post_collaboration'][LANGUAGE_NONE][0]['read']['#default_value'] = $access_details['read'];
      $form['field_post_collaboration'][LANGUAGE_NONE][0]['read']['#disabled'] = TRUE;
      if ($access_details['read_reason']) {
        $form['field_post_collaboration'][LANGUAGE_NONE][0]['read']['#description'] = $access_details['read_reason'];
      }
      else {
        $form['field_post_collaboration'][LANGUAGE_NONE][0]['read']['#description'] = t('Access cannot be set because this file is in use');
      }
    }
    foreach ($access_details['og_extra_access'] as $gid) {
      $node = node_load($gid);
      $form['field_post_collaboration'][LANGUAGE_NONE][0]['read']['#description'] .= "<p>" . t('This post is visible for users og group %group', ['%group' => $node->title]) . '</p>';
    }


  }

}

/**
 * Implements salto_knowledgebase_field_post_collaboration_access_alter
 *
 * @param  [type] $access [description]
 * @param  [type] $node   [description]
 *
 * @return [type]         [description]
 */
function salto_knowledgebase_field_post_collaboration_access_alter(&$access, $node) {

  if (!empty($node->field_og_group[LANGUAGE_NONE][0])) {
    if (!$access) {
      $access = og_user_access('node', $node->field_og_group[LANGUAGE_NONE][0]['target_id'], 'edit collaboration fields');
    }
  }
}
