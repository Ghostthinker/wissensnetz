<?php
/**
 * @file
 * salto_user.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function salto_user_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_contact|profile2|main|form';
  $field_group->group_name = 'group_profile_contact';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '8',
    'children' => array(
      0 => 'field_profile_contact_mobile',
      1 => 'field_profile_contact_phone',
      2 => 'field_profile_contact_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-profile-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_profile_contact|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_security|user|user|form';
  $field_group->group_name = 'group_user_security';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sicherheit',
    'weight' => '9',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_security|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_settings|user|user|form';
  $field_group->group_name = 'group_user_settings';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Einstellungen',
    'weight' => '1',
    'children' => array(
      0 => 'l10nclient',
      1 => 'privatemsg',
      2 => 'timezone',
      3 => 'contact',
      4 => 'locale',
      5 => 'wysiwyg',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-user-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_user_settings|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Einstellungen');
  t('Sicherheit');

  return $field_groups;
}
