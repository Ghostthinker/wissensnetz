<?php

/**
 * Menu callback: content administration.
 */
function salto_user_admin_form() {
  $form = array();

  $salto_admin_ips = implode("\r\n",variable_get('salto_admin_ip_allowed',''));

  $form['salto_admin_ip_allowed'] = array(
    '#type' => 'textarea',
    '#title' => t('Allowed ips'),
    '#description' => t('Enter admin ips here. Your current ip is <strong>!ip</strong>', ['!ip' => salto_get_client_IP()]),
    '#default_value' => $salto_admin_ips,
  );


  $form['salto_admin_ip_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Admin ip enabled'),
    '#description' => t('Enable admin ip. <b>Only enable this option if you saved your own ip.</b> If you set this up wrong, use <b>drush vset salto_admin_ip_enabled 0 </b>'),
    '#default_value' => variable_get('salto_admin_ip_enabled',FALSE)
  );


  $form['salto_admin_themenfelder_selection_all'] = [
    '#type' => 'checkbox',
    '#title' => t('Select all Themenfelder when inviting'),
    '#description' => t('Selects all Themenfelder for a user profile, when the user invite succeeded'),
    '#default_value' => variable_get('salto_admin_themenfelder_selection_all', FALSE),
  ];

  $form = system_settings_form($form);

  array_unshift($form['#submit'],'salto_admin_ip_page_submit');
  return $form;
}

function salto_admin_ip_page_submit($form, &$form_state) {

  $salto_admin_ips = explode("\r\n", $form_state['values']['salto_admin_ip_allowed']);
  $salto_admin_ips = array_map('trim', $salto_admin_ips);
  $form_state['values']['salto_admin_ip_allowed'] = $salto_admin_ips;
}
