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
  'title' => t('Notification settings'),
  'description' => t('Notification settings'),
  'required context' => [
    new ctools_context_optional(t('User'), 'entity:user'),
  ],
  'category' => t('Notifications'),
  'defaults' => ['type' => NULL],
];

/**
 * Render the user profile content type.
 */
function onsite_notification_notification_settings_content_type_render($subtype, $conf, $panel_args, $context) {
  if (!isset($conf['type'])) {
    return;
  }


  $account_context = isset($context[0]->data->uid) ? clone($context[0]->data) : NULL;

  if (empty($account_context)) {
    return;
  }

  $output = theme_onsite_notification_form_settings($account_context->uid);

  $block = new stdClass();
  $block->content = $output;

  return $block;
}

/**
 * Display the administrative title for a panel pane in the drag & drop UI.
 */
function onsite_notification_notification_settings_content_type_admin_title($subtype, $conf, $context) {
  return t('Notification settings');
}


function onsite_notification_notification_settings_content_type_admin_info($subtype, $conf) {
  $block = new stdClass();
  $block->module = 'onsite_notification';
  $block->title = t("Notification settings");
  $block->content = " ";
  return $block;
}

/**
 * The submit form stores the data in $conf.
 */
function onsite_notification_notification_settings_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * The form to add or edit a profile as content.
 */
function onsite_notification_notification_settings_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['type'] = [
    '#type' => 'checkbox',
    '#title' => t('Nothing special here'),
    '#default_value' => $conf['type'],
  ];
  return $form;
}

