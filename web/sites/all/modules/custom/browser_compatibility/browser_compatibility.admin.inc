<?php

/**
 * Form builder; Create and display the User Warn configuration
 * settings form.
 */
function browser_compatibility_form($form, &$form_state) {

  $form['browser_compatibility_whitelist'] = [
    '#type' => 'textarea',
    '#rows' => 10,
    '#columns' => 40,
    '#title' => t('Whitelist'),
    '#default_value' => variable_get('browser_compatibility_whitelist', ''),
    '#required' => FALSE,
    '#description' => t("The browsers which are supported. <em>One item per line. Examples: (Chrome|33+ to whitelist all Chrome versions > 33, Chrome|33 for a single version. Minor Versions e.g. 33.1 are also supported)"),
  ];

  $form['browser_compatibility_blacklist'] = [
    '#type' => 'textarea',
    '#rows' => 10,
    '#columns' => 40,
    '#title' => t('Blacklist'),
    '#default_value' => variable_get('browser_compatibility_blacklist', ''),
    '#required' => FALSE,
    '#description' => t("Browsers which are NOT supported. <em>One item per line. Examples: (Chrome|33+ to blacklist all Chrome versions > 33, Chrome|33 for a single version. Minor Versions e.g. 33.1 are also supported) </em>"),
  ];

  return system_settings_form($form);
}
