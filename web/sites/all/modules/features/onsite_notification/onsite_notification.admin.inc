<?php

function onsite_notification_admin_settings($form, &$form_state) {

  $form['mail'] = [
    '#type' => 'fieldset',
    '#title' => 'Mail Settings',
  ];

  $form['mail']['infos'] = [
    '#markup' => onsite_notification_admin_summary(),
    '#title' => t('Infos'),
  ];
  $form['mail']['reset_last_sent'] = [
    '#type' => 'submit',
    '#value' => t('Reset last mail sent times'),
    #'#weight' => 19,
  ];

  $form['mail']['salto_notification_mail_frequency'] = [
    '#title' => t('Mail frequency'),
    '#type' => 'radios',
    '#description' => t('The default setting for email frequency'),
    '#default_value' => variable_get('salto_notification_mail_frequency', NOTIFICATION_FREQUENCY_DAILY),
    '#options' => onsite_notification_get_mail_frequency_options(),
  ];

  $form['mail']['salto_notification_mail_time'] = [
    '#title' => t('Daily Mail Hour'),
    '#type' => 'textfield',
    '#description' => t('Hour to send mail notifications when setting is per day or per week.'),
    '#default_value' => variable_get('salto_notification_mail_time', 6),
  ];

  $form['mail']['salto_notification_mail_weekday'] = [
    '#title' => t('Weekly Mail Day'),
    '#type' => 'select',
    '#options' => onsite_notification_admin_weekday_options(),
    '#description' => t('day in the week when to send the weekly notifications'),
    '#default_value' => variable_get('salto_notification_mail_weekday', 1),
  ];

  $form = system_settings_form($form);
  $form['#submit'][] = 'onsite_notification_admin_settings_submit';

  return $form;
}


/**
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function onsite_notification_maintenance_message($form, &$form_state) {

  drupal_set_message(t("It is important that your form is displayed within SALTO-Template. Otherwise your Email template will be broken."), "warning", FALSE);


  $api_users = salto_license_get_api_users();
  $api_mails = array_map(function ($e) {
    return $e->mail;
  }, $api_users);

  $api_mails_string = implode(", ", $api_mails);

  $form['infos'] = [
    '#markup' => t("This maintenance message will be sent to %num_api_users API Users", ["%num_api_users" => count($api_users)]),
    '#title' => t('Infos'),
  ];

  $form['infos_mails'] = [
    "#type" => "fieldset",
    "#title" => t("Emails list"),
    "#collapsible" => TRUE,
    "#collapsed" => TRUE,
  ];

  $form["infos_mails"]['text'] = [
    '#markup' => $api_mails_string,
  ];

  $form['emails'] = [
    '#type' => 'hidden',
    '#value' => $api_mails,
  ];

  $form['dosb_license_maintenance_message_mail_body'] = [
    '#title' => t('Email attachment body'),
    '#type' => 'textarea',
    '#rows' => 10,
    '#default_value' => variable_get('dosb_license_maintenance_message_mail_body', ""),
  ];

  $form['salto_maintenance_test_mail'] = [
    '#type' => 'textfield',
    '#title' => 'Test email address',
    '#default_value' => variable_get('salto_maintenance_test_mail', ""),
  ];

  $form['send_test'] = [
    '#type' => 'checkbox',
    '#title' => "Send Email to Test email address only",
    '#default_value' => TRUE,
  ];


  $form = system_settings_form($form);
  $form['actions']['submit']['#value'] = ('Send and save configuration');
  $form['#submit'][] = 'onsite_notification_maintenance_message_submit';

  return $form;
}

function onsite_notification_maintenance_message_submit($form, &$form_state) {
  global $user;

  $params = [
    'key' => 'regcode_invite',
    'to' => "",
    'from' => variable_get('site_mail', ''),
    'subject' => "[Wartungsarbeiten] - Wissensnetz",
    'body' => nl2br($form_state['values']['dosb_license_maintenance_message_mail_body']),
  ];

  if ($form_state['values']['send_test']) {
    $params['to'] = $form_state['values']['salto_maintenance_test_mail'];
    //send testmail only
    drupal_mail('salto_core', $params['key'], $params['to'], user_preferred_language($user), $params);

    drupal_set_message(t('Maintenance message has been sent to: %emails', ['%emails' => $params['to']]), 'status', FALSE);
  }
  else {

    $recepients = $form_state['values']['emails'];
    $recepients[] = $form_state['values']['salto_maintenance_test_mail'];
    $recepients_string = implode(", ", $recepients);

    foreach ($recepients as $r_item) {
      $params['to'] = $form_state['values']['salto_maintenance_test_mail'] = $r_item;

      drupal_mail('salto_core', $params['key'], $params['to'], user_preferred_language($user), $params);
    }

    drupal_set_message(t('Maintenance message has been sent to: %emails', ['%emails' => $recepients_string]), 'status', FALSE);
  }

}


function onsite_notification_admin_settings_submit($form, &$form_state) {

  if ($form_state['clicked_button']['#id'] == 'edit-reset-last-sent') {
    variable_set('onsite_notification_mail_last_execution_daily', 0);
    variable_set('onsite_notification_mail_last_execution_weekly', 0);
    drupal_set_message(t('The last sent times have been reset.'), 'status', FALSE);
  }
}

/**
 * A short summary when the last events occured
 *
 * @return [type] [description]
 */
function onsite_notification_admin_summary() {

  $time_daily = variable_get('onsite_notification_mail_last_execution_daily', 0);
  $out[] = t("Last daily mail sent: !daily", ['!daily' => $time_daily > 0 ? format_date($time_daily) : t('never')]);

  $time_weekly = variable_get('onsite_notification_mail_last_execution_weekly', 0);
  $out[] = t("Last weekly mail sent: !weekly", ['!weekly' => $time_weekly > 0 ? format_date($time_weekly) : t('never')]);

  return implode("<br>", $out) . "<br>";
}

/**
 * Weekday options
 *
 * @return [type] [description]
 */
function onsite_notification_admin_weekday_options() {
  $timestamp = strtotime('next Sunday');
  $days = [];
  for ($i = 0; $i < 7; $i++) {
    $days[$i] = strftime('%A', $timestamp);
    $timestamp = strtotime('+1 day', $timestamp);
  }
  return $days;
}
