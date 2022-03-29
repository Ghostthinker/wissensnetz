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
  'title' => t('Action links'),
  'description' => t('Action links'),
  'required context' => [
    new ctools_context_optional(t('User'), 'entity:user'),
    new ctools_context_optional(t('Node'), 'entity:node'),
    new ctools_context_optional(t('File'), 'entity:file'),
  ],
  'category' => t('Action Links'),
  'defaults' => ['type' => NULL],
];

/**
 * Render the user profile content type.
 */
function salto_core_action_links_content_type_render($subtype, $conf, $panel_args, $context) {
  if (!isset($conf['type'])) {
    return;
  }
  $type = $conf['type'];

  $account_context = isset($context[0]->data->uid) ? clone($context[0]->data) : NULL;
  $node_context = isset($context[1]->data->nid) ? clone($context[1]->data) : NULL;
  $file_context = isset($context[2]->data->fid) ? clone($context[2]->data) : NULL;
  $license_context = isset($context[3]->data->lid) ? clone($context[3]->data) : NULL;

  $content_context = [
    'account_context' => $account_context,
    'node_context' => $node_context,
    'file_context' => $file_context,
    'license_context' => $license_context,
  ];

  $block = new stdClass();
  $block->content = salto_core_render_action_links($type, $content_context);;
  return $block;
}

/**
 * Display the administrative title for a panel pane in the drag & drop UI.
 */
function salto_core_action_links_content_type_admin_title($subtype, $conf, $context) {
  return t('Action links');
}

/**
 * TODO
 */
function salto_core_action_links_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->module = 'salto_core';
  // Title should display a profile type label.

  $block->title = t("Action links for...");

  // Content dispays assigned build mode.
  $block->content = "";
  return $block;
}

/**
 * The submit form stores the data in $conf.
 */
function salto_core_action_links_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * The form to add or edit a profile as content.
 */
function salto_core_action_links_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  // Select type of profile to display.
  $form['type'] = [
    '#type' => 'radios',
    '#title' => t('Action links types'),
    '#options' => _action_links_options(),
    '#default_value' => $conf['type'],
  ];
  return $form;
}

/**
 * Get all action links categories
 *
 * @return [type] [description]
 */
function _action_links_options() {
  $links = [];
  $links += module_invoke_all('action_links_info');
  return $links;
}
