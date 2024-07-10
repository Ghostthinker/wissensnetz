<?php

/**
 * @file
 * salto_knowledgebase.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function salto_knowledgebase_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publishing|node|post|form';
  $field_group->group_name = 'group_publishing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'post';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Veröffentlichung planen',
    'weight' => '3',
    'children' => array(
      0 => 'field_publishing_options',
      1 => 'field_publishing_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Veröffentlichung planen',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => 'group-publishing field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Veröffentlichung planen');

  return $field_groups;
}
