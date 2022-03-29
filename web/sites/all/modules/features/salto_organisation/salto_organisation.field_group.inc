<?php

/**
 * @file
 * salto_organisation.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function salto_organisation_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_president_details|node|organisation|form';
  $field_group->group_name = 'group_president_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'organisation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Angaben zum/zur Unterschriftbevollmächtigten',
    'weight' => '7',
    'children' => array(
      0 => 'field_organisation_signature',
      1 => 'field_org_president_name',
      2 => 'field_org_position',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Angaben zum/zur Unterschriftbevollmächtigten',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'president_details',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Angaben zum/zur Unterschriftbevollmächtigten');

  return $field_groups;
}
