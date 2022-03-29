<?php

/**
 * @file
 * Plugin to provide access control based on drupal_is_front_page.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = [
  'title' => t('Onsite Notification: Autosubscribe enabled'),
  'description' => t('Check if automatic or manual subscription is set for a user'),
  'callback' => 'onsite_notification_auto_subscribe_enabled_access_check',
  'default' => ['entity_type' => 'post', 'flag_type' => 'manual'],
  'summary' => 'onsite_notification_auto_subscribe_enabled_summary',
  'settings form' => 'onsite_notification_auto_subscribe_enabled_ctools_access_settings',
  'required context' => [
    new ctools_context_required(t('User'), 'user'),
    new ctools_context_optional(t('Node'), 'node'),
  ],
];

/**
 * Check for access.
 */
function onsite_notification_auto_subscribe_enabled_access_check($conf, $context) {

  $account = isset($context[0]->data->uid) ? clone($context[0]->data) : NULL;
  $node = isset($context[1]->data->nid) ? clone($context[1]->data) : NULL;

  if (empty($account->uid)) {
    return FALSE;
  }

  if (empty($node->nid)) {
    return onsite_notification_autosubscribe_enabled($account->uid, $conf['entity_type']);
  }

  if ($conf['flag_type'] == 'manual') {
    if (onsite_notification_autosubscribe_enabled($account->uid, $conf['entity_type'])) {
      if (salto_user_interested_in_entity($node, $account)) {
        return FALSE;
      }
    }
  }

  if ($conf['flag_type'] == 'auto') {
    if (!onsite_notification_autosubscribe_enabled($account->uid, $conf['entity_type'])) {
      return FALSE;
    }
    if (!salto_user_interested_in_entity($node, $account)) {
      return FALSE;
    }
  }
  return TRUE;
}

/**
 * Provide a summary description based upon the checked terms.
 */
function onsite_notification_auto_subscribe_enabled_summary($conf, $context) {

  return t('Grant access when entity is !entity_type and flag_type is !flag_type',
    [
      '!entity_type' => $conf['entity_type'],
      '!flag_type' => $conf['flag_type'],
    ]);
}


function onsite_notification_auto_subscribe_enabled_ctools_access_settings($form, &$form_state, $conf) {

  $form['settings']['entity_type'] = [
    '#type' => 'select',
    '#title' => 'Entitiy Type',
    '#options' => [
      'post' => 'post',
      'file' => 'file',
    ],
    '#default_value' => $conf['entity_type'],
  ];

  $form['settings']['flag_type'] = [
    '#type' => 'select',
    '#title' => 'Flag Type',
    '#options' => [
      'manual' => 'manual',
      'auto' => 'auto',
    ],
    '#default_value' => $conf['flag_type'],
  ];

  return $form;
}
