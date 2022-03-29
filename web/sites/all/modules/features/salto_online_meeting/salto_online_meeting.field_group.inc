<?php

/**
 * @file
 * salto_online_meeting.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function salto_online_meeting_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_online_meeting_timegroup|node|online_meeting|form';
  $field_group->group_name = 'group_online_meeting_timegroup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'online_meeting';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '3',
    'children' => array(
      0 => 'field_end_time',
      1 => 'field_online_meeting_date',
      2 => 'field_start_time',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-online-meeting-timegroup field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups[''] = $field_group;

  return $field_groups;
}
