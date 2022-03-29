<?php

function salto_core_admin_settings($form, &$form_state) {


  $form['general'] = [
    '#type' => 'fieldset',
    '#title' => 'General Settings',
    '#description' => t('General settings for salto-bip'),
  ];

  $form['general']['salto_protect_on_leave'] = [
    '#type' => 'checkbox',
    '#title' => 'Protect forms on leave',
    '#description' => t('Protect forms on leave'),
    '#default_value' => variable_get('salto_protect_on_leave', TRUE),
  ];

  $form['general']['salto_core_frontpage_slider_interval'] = [
    '#type' => 'textfield',
    '#title' => 'Frontpage slider interval',
    '#description' => t('Frontpage slider interval in milliseconds.'),
    '#default_value' => variable_get('salto_core_frontpage_slider_interval', 6000),
  ];

  $form['user'] = [
    '#type' => 'fieldset',
    '#title' => 'User Settings',
    '#description' => t('General settings for salto-bip'),
  ];

  $form['user']['salto_user_online_seconds'] = [
    '#type' => 'textfield',
    '#title' => 'Online time',
    '#description' => t('Seconds that must pass after the last action of a user to appear offline. IN SECONDS'),
    '#default_value' => variable_get('salto_user_online_seconds', 300),
  ];
  $form['user']['salto_user_direct_group_invite'] = [
    '#type' => 'checkbox',
    '#title' => 'Direct group invite',
    '#description' => t('When check, users that are invited via a group (not oragnisation) are directly added to the group. If not checked, invites are generated'),
    '#default_value' => variable_get('salto_user_direct_group_invite', FALSE),
  ];

  $form['user']['salto_user_keep_group'] = [
    '#type' => 'textfield',
    '#title' => 'Keep User Group',
    '#description' => t('The nid of the group where members are not deleted when replicating live.'),
    '#default_value' => variable_get('salto_user_keep_group', 2194),
  ];

  $form['organisation'] = [
    '#type' => 'fieldset',
    '#title' => 'Organisations Settings',
    '#description' => t('General settings for organisations'),
  ];
  $form['organisation']['salto_organisation_fallback_nid'] = [
    '#type' => 'textfield',
    '#title' => 'Organisation fallback nid',
    '#description' => t('Organisation nid used as fallback organisation for users which are removed from their last organisation'),
    '#default_value' => variable_get('salto_organisation_fallback_nid', 0),
  ];


  return system_settings_form($form);
}

/**
 * @param $form
 * @param $form_state
 */
function salto_core_admin_settings_validate($form, &$form_state) {
  $fallback_og = node_load($form_state['values']['salto_organisation_fallback_nid']);
  if (!$fallback_og || $fallback_og->type !== 'organisation') {
    form_set_error('salto_organisation_fallback_nid', t('Please enter a valid organisatio nid'));
  }
}
