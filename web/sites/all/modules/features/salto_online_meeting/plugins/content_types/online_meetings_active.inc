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
  'title' => t('Active online meetings'),
  'description' => t('Show all active online meetings with join link'),
  'required context' => [
    new ctools_context_required(t('Node'), 'entity:node'),
  ],
  'category' => t('Online meeting'),
  'defaults' => [],
];

/**
 * Render the authors of a node
 */
function salto_online_meeting_online_meetings_active_content_type_render($subtype, $conf, $panel_args, $context) {

  $group_node = isset($context[0]->data->nid) ? clone($context[0]->data) : NULL;

  $block = new stdClass();
  $block->title = '';

  //auto check status
  $js_settings = [
    'online_meeting' => [
      'ajax_poll_interval' => variable_get('online_meeting_polling_interval', 10),
    ],
  ];

  $nid = $group_node->nid ?? NULL;

  drupal_add_js($js_settings, 'setting');
  drupal_add_css(drupal_get_path('module', 'salto_online_meeting') . '/less/salto_online_meeting.less');
  drupal_add_js(drupal_get_path('module', 'salto_online_meeting') . '/js/dialog_gateway.js');

  $out = '<div id="salto-online-meeting-group-active" data-gid="' . $nid . '"></div>';

  $block->content = $out;
  return $block;
}

/**
 * Display the administrative title for a panel pane in the drag & drop UI.
 */
function salto_online_meeting_online_meetings_active_content_type_admin_title($subtype, $conf, $context) {
  return t('Active meetings in group');
}

function salto_online_meeting_online_meetings_active_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->module = 'salto_online_meeting';
  // Title should display a profile type label.

  $block->title = t("Authors of the node");

  // Content dispays assigned build mode.
  $block->content = " ";
  return $block;
}


/**
 * The submit form stores the data in $conf.
 */
function salto_online_meeting_online_meetings_active_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * The form to add or edit a profile as content.
 */
function salto_online_meeting_online_meetings_active_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  // Select type of profile to display.
  $form['type'] = [
    '#type' => 'select',
    '#title' => t('Image preset'),
    '#options' => [
      'all' => t("All (groups and no groups)"),
      'group none' => t("Only meetings without groups"),
      'group specific' => t("Only meetings in the context group"),
      'group all' => t("Only meetings in any group of the user"),
    ],
    '#default_value' => $conf['image_style'],
  ];
  return $form;
}

