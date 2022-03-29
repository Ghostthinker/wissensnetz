<?php

/**
 * @file
 * salto_core.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function salto_core_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'default_selection_wysiwyg';
  $ds_view_mode->label = 'Default Selection WYSIWYG';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['default_selection_wysiwyg'] = $ds_view_mode;

  return $export;
}
