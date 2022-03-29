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

  if (empty($group_node->nid)) {
    return;
  }


  $block = new stdClass();
  $block->title = '';

  //auto check status
  $js_settings = [
    'online_meeting' => [
      'ajax_poll_interval' => variable_get('online_meeting_polling_interval', 10),
    ],
  ];

  drupal_add_js($js_settings, 'setting');
  drupal_add_css(drupal_get_path('module', 'salto_online_meeting') . '/less/salto_online_meeting.less');
  drupal_add_js(drupal_get_path('module', 'salto_online_meeting') . '/js/dialog_gateway.js');

  $out = '<div id="salto-online-meeting-group-active" data-gid="' . $group_node->nid . '"></div>';

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
