<?php

/**
 * @file
 * Plugin to handle the 'profile2' content type which allows individual profiles
 * to be embedded into a panel.
 */


/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = [
  'single' => TRUE,
  'title' => t('Membership summary'),
  'description' => t('Displays information about a users membership in the passed context'),
  'required context' => [
    new ctools_context_required(t('Og Node'), 'entity:node'),
    new ctools_context_optional(t('User'), 'entity:user'),
  ],
  'category' => t('Organisations'),
  'defaults' => ['type' => NULL],
];

/**
 * Render the user profile2 content type.
 */
function salto_organisation_membership_summary_content_type_render($subtype, $conf, $panel_args, $context) {

  global $user;

  //get context and load membership if exists
  $node = isset($context[0]->data->nid) ? clone($context[0]->data) : NULL;
  $account = isset($context[1]->data->uid) ? clone($context[1]->data) : clone($user);
  //get the membership
  $membership = og_get_membership('node', $node->nid, 'user', $account->uid);


  $block = new stdClass();
  $block->title = t('Your Membership');


  if (empty($membership)) {
    $out = t('You are not a member of this organisation.');
  }
  else {
    $membership_array = entity_view('og_membership', [$membership], 'membership_compact');

    $out = drupal_render($membership_array);

  }

  $block->content = $out;

  return $block;
}

/**
 * Display the administrative title for a panel pane in the drag & drop UI.
 */
function salto_organisation_membership_summary_content_type_admin_title($subtype, $conf, $context) {
  return t('Membership summary');
}

/**
 * TODO
 */
function salto_organisation_membership_summary_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->module = 'salto_organisation';
  // Title should display a profile type label.

  $block->title = t("Membership info");

  // Content dispays assigned build mode.
  $block->content = "tbi";
  return $block;
}

/**
 * The submit form stores the data in $conf.
 */
function salto_organisation_membership_summary_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}


/**
 * The form to add or edit a profile as content.
 */
function salto_organisation_membership_summary_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  // Select type of profile to display.
  $form['type'] = [
    '#type' => 'radios',
    '#title' => t('types'),
    '#options' => [],
    '#default_value' => $conf['type'],
  ];
  return $form;
}

