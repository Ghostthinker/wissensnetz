<?php

/**
 * @file
 * salto_organisation.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function salto_organisation_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'og_membership|organisation_membership|default';
  $ds_layout->entity_type = 'og_membership';
  $ds_layout->bundle = 'organisation_membership';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_organisation_position',
      ),
    ),
    'fields' => array(
      'field_organisation_position' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['og_membership|organisation_membership|default'] = $ds_layout;

  return $export;
}
