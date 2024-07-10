<?php

/**
 * @file
 * salto_help.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function salto_help_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_help_category'.
  $field_bases['field_help_category'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_help_category',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'General' => 'Übersicht',
        'FAQ' => 'FAQ',
        'Screencast' => 'Screencast',
        'Scenario' => 'Nutzungsbeispiele',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_help_context_url'.
  $field_bases['field_help_context_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_help_context_url',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
