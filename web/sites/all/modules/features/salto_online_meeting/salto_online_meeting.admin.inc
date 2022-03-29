<?php

function salto_online_meeting_admin_settings($form, &$form_state) {

  $form['dialog_gateway'] = [
    '#type' => 'fieldset',
    '#title' => 'Dialog Gateway',
    '#description' => t('General settings for the dialog gateway'),
  ];

  $form['dialog_gateway']['online_meeting_enabled'] = [
    '#type' => 'checkbox',
    '#title' => 'Online Meeting enabled',
    '#default_value' => salto_online_meeting_enabled(),
    '#description' => t('Enable Online Meetings on this domain'),
  ];

  $form['dialog_gateway']['online_meeting_url'] = [
    '#type' => 'textfield',
    '#title' => 'Url:',
    '#description' => 'Dialog gateway url',
    '#default_value' => variable_get('online_meeting_url', ''),
  ];

  $form['dialog_gateway']['online_meeting_access_token'] = [
    '#type' => 'textfield',
    '#title' => 'Access token:',
    '#description' => 'Auth token for the dialog gateway. This is also used as token for webhooks',
    '#default_value' => variable_get('online_meeting_access_token', ''),
  ];

  $form['dialog_gateway']['online_meeting_instance_url'] = [
    '#type' => 'textfield',
    '#title' => 'Instance URL:',
    '#description' => 'Edubreak instance url like "test.edubreak.de", "white.edubreak.de",... this MUST be set to each instance to receive webhooks from gateway',
    '#default_value' => variable_get('online_meeting_instance_url', ''),
  ];

  $form['dialog_gateway']['online_meeting_polling_interval'] = [
    '#type' => 'textfield',
    '#title' => 'Ajax Polling Interval',
    '#description' => 'Ajax polling intervall for reloading dialog page',
    '#default_value' => variable_get('online_meeting_polling_interval', 5),
  ];

  $form['dialog_gateway']['online_meeting_default_meeting_password'] = [
    '#type' => 'textfield',
    '#title' => 'Default meeting password',
    '#description' => 'Default meeting password',
    '#default_value' => variable_get('online_meeting_default_meeting_password', '1234'),
    '#maxlength' => 10,
  ];

  $form['dialog_gateway']['online_meeting_default_user_name'] = [
    '#type' => 'checkbox',
    '#title' => 'Shorten username',
    '#default_value' => FALSE,
    '#description' => t('Anonymize meeting member lastname, like Max M.'),
  ];

  return system_settings_form($form);

}
