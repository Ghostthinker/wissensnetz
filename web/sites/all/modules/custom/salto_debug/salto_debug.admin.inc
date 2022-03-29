<?php

function salto_debug_admin_settings() {

  $form['general'] = [
    '#type' => 'fieldset',
    '#title' => 'General Settings',
    '#description' => t('General settings for salto-bip'),
  ];
  $form['general']['salto_is_development_system'] = [
    '#type' => 'checkbox',
    '#title' => t('Is this instance a develoment system?'),
    '#default_value' => variable_get('salto_is_development_system', FALSE),
    '#description' => t('Indicated that this system is a development system.'),
    '#disabled' => !extension_loaded('xhprof'),
  ];

  return system_settings_form($form);
}
