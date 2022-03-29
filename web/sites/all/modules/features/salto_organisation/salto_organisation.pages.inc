<?php

/**
 * Add Edit membership form.
 */
function salto_organisation_membership_form($form, &$form_state, $group_type, $gid, $og_membership) {
  salto_og_set_breadcrumb($gid);
  $group = entity_load_single($group_type, $gid);
  list(, , $bundle) = entity_extract_ids($group_type, $group);

  $form['group_type'] = ['#type' => 'value', '#value' => $group_type];
  $form['gid'] = ['#type' => 'value', '#value' => $gid];
  $form['id'] = ['#type' => 'value', '#value' => $og_membership->id];

  // Add group membership form. We still don't have the user or state.
  $form_state['og_membership'] = $og_membership;

  $form['membership_fields'] = [
    '#prefix' => '<div id="og-ui-field-name">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
    '#parents' => ['membership_fields'],
  ];
  field_attach_form('og_membership', $og_membership, $form['membership_fields'], $form_state);

  $form['actions'] = ['#type' => 'actions'];
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t('Update membership'),
  ];

  return $form;
}

/**
 * Validate handler; Edit membership in group.
 */
function salto_organisation_membership_form_validate($form, &$form_state) {
  $og_membership = $form_state['og_membership'];
  field_attach_form_validate('og_membership', $og_membership, $form['membership_fields'], $form_state);
}

/**
 * Submit handler; Edit membership in group.
 */
function salto_organisation_membership_form_submit($form, &$form_state) {

  $og_membership = $form_state['og_membership'];
  $og_membership->state = OG_STATE_ACTIVE;
  field_attach_submit('og_membership', $og_membership, $form['membership_fields'], $form_state);

  $og_membership->save();

  drupal_set_message(t('The membership has been updated.'));
}

/**
 * Form to create invites
 */
function salto_organisation_membership_add($form, &$form_state, $gid) {
  $group = entity_load_single('node', $gid);

  ctools_include('dependent');

  $form['#group'] = $group;

  $form['selector'] = [
    '#markup' => theme("og_invite_selector", ['group' => $group]),
  ];

  $form['accounts'] = [
    '#type' => 'hidden',
    '#title' => t('This should be the serialized string of all users to add'),
    '#default_value' => "[]",
  ];

  $form['invite'] = [
    '#type' => 'checkbox',
    '#title' => t('Custom invite message'),
    '#default_value' => FALSE,
    '#attributes' => ["id" => "edit-invite"],
  ];


  $form['invite_message'] = [
    '#type' => 'textarea',
    '#required' => FALSE,
    '#process' => ['ctools_dependent_process'],
    '#dependency' => ["edit-invite" => [1]],
    '#rows' => 20,
    '#description' => t('You can append a custom message to all invites. New users will additionally receive login informations.'),
  ];


  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Invite users'),
  ];
  return $form;
}

/**
 * Submit the user administration update form.
 */
function salto_organisation_membership_add_submit($form, &$form_state) {

  global $language;
  $message = !empty($form_state['values']['invite_message']) ? $form_state['values']['invite_message'] : " "; //set this so the token is replaced

  $accounts = json_decode($form_state['values']['accounts']);
  $group = $form['#group'];


  foreach ($accounts as $id => $data) {

    if (strpos($id, "new-") === 0) {
      //create new account

      $userdata = [];
      $userdata['firstname'] = check_plain($data->name_first);
      $userdata['lastname'] = check_plain($data->name_last);
      $userdata['mail'] = check_plain($data->email);
      $userdata['language'] = $language->language;

      salto_organisation_invite_user($userdata, $group, $message);

      drupal_set_message(t('%mail has been invited to the group %group-title.', [
        '%mail' => $userdata['mail'],
        '%group-title' => entity_label('node', $group),
      ]));
    }
    else {
      $uid = $data->id;

      if ($account = user_load($uid)) {
        //add users to group, create a normal membership
        $og_membership = og_membership_create('node', $group->nid, 'user', $uid, 'field_user_organisations', ['state' => 1]);
        $og_membership->save();

        drupal_set_message(t('%user has been added to the group %group-title.', [
          '%user' => format_username($account),
          '%group-title' => entity_label('node', $group),
        ]));
      }
    }
  }
}

/**
 * Ajax callback for adding and validating new and existing users
 *
 * @param  [type] $op [description]
 *
 * @return [type]     [description]
 */
function salto_organisation_membership_ajax_callback($op, $arg = NULL) {

  global $user;
  $data = [];
  $gid = arg(2);

  if (!is_numeric($gid)) {

  }

  //existing user
  if ($op == 'render') {
    if (!empty($_POST['uid'])) {
      $uid = check_plain($_POST['uid']);
      $data += salto_organistion_ajax_render_membership($gid, $uid);
    }
  }

  //validate new user
  if ($op == 'validate') {

    $userdata = $_POST['data'];
    $data += salto_organistion_ajax_validate_new_user($userdata, $gid);
  }

  if ($op == "search") {
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

    $data = salto_organistion_ajax_search($gid, $limit, $search, $exclude_search_uids);
  }

  return drupal_json_output($data);
}


/**
 * Redirect function for my organisations
 *
 * @return string
 */
function salto_organisation_redirect_my_organisations() {

  global $user;

  $organisations = salto_organisation_get_users_organisations($user);

  if (count($organisations) == 1) {

    drupal_goto('node/' . end($organisations)->nid);
  }
  else {
    drupal_goto('organisations/' . $user->uid);
  }
  return "";
}
