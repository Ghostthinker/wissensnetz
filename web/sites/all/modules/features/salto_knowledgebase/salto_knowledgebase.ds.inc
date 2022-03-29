<?php

/**
 * @file
 * salto_knowledgebase.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function salto_knowledgebase_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'action_links';
  $ds_field->label = 'action_links';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
    'profile2' => 'profile2',
    'file' => 'file',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['action_links'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function salto_knowledgebase_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|post|salto_diff';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'post';
  $ds_layout->view_mode = 'salto_diff';
  $ds_layout->layout = 'panels-salto_363';
  $ds_layout->settings = array(
    'regions' => array(
      'middle' => array(
        0 => 'body',
        1 => 'field_taxonomy_post_tags',
        2 => 'field_post_tags',
      ),
    ),
    'fields' => array(
      'body' => 'middle',
      'field_taxonomy_post_tags' => 'middle',
      'field_post_tags' => 'middle',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'middle' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|post|salto_diff'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function salto_knowledgebase_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'salto_diff';
  $ds_view_mode->label = 'Salto Diff';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['salto_diff'] = $ds_view_mode;

  return $export;
}
