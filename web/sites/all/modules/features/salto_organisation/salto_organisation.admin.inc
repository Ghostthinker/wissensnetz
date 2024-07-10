<?php

function salto_organisation_admin_settings($form, &$form_state) {

  $form['organisation_custom_fields'] = [
    '#type' => 'fieldset',
    '#title' => 'Organisation',
    '#tree' => TRUE,
  ];

  $form['organisation_custom_fields']['field_organisation_sportkreis_options'] = [
    '#type' => 'textarea',
    '#title' => "Sportkreise",
    '#description' => "Sportkreise für diese Instanz in Komma getrennt",
    '#default_value' => !empty(salto_organisation_get_sportkreis_options()) ? salto_organisation_get_sportkreis_options() : '',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $custom_field_info = salto_organisation_custom_field_info();

  foreach($custom_field_info as $field_name => $info){
    $form['organisation_custom_fields'][$field_name] = [
      '#type' => 'fieldset',
      '#title' => "Organisation form $field_name and filter item",
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    ];

    $form['organisation_custom_fields'][$field_name]['form_field_enabled'] = [
      '#type' => 'checkbox',
      '#title' => "$field_name form field",
      '#default_value' => $info['form_field_enabled'],
      '#description' => t("Show and hide $field_name form fields"),
    ];

    $form['organisation_custom_fields'][$field_name]['filter_enabled'] = [
      '#type' => 'checkbox',
      '#title' => "$field_name filter item",
      '#default_value' => $info['filter_enabled'],
      '#description' => t("Show and hide $field_name filter item"),
    ];

  }

  return system_settings_form($form);

}
