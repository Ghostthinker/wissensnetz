<?php

/**
 * @file
 * salto_group.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function salto_group_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_default_access_options|node|group|form';
  $field_group->group_name = 'group_default_access_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Standardzugriff für Beiträge',
    'weight' => '7',
    'children' => array(
      0 => 'field_default_access_post',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Standardzugriff für Beiträge',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-default-access-options field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|node|group|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Info',
    'weight' => '5',
    'children' => array(
      0 => 'field_group_option_description',
      1 => 'field_group_posts_only',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_join_mode|node|group|form';
  $field_group->group_name = 'group_join_mode';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Beitrittsmodus',
    'weight' => '6',
    'children' => array(
      0 => 'field_group_join_mode',
      1 => 'field_group_join_org_refs',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-join-mode field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Beitrittsmodus');
  t('Info');
  t('Standardzugriff für Beiträge');

  return $field_groups;
}
