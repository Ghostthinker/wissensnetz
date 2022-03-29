<?php
/**
 * @file
 * salto_breadcrumbs.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function salto_breadcrumbs_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_path_breadcrumbs';
  $strongarm->value = array(
    'node_ausbildungskonzept' => TRUE,
    'license_ausbildungskonzept_attachment' => TRUE,
    'license_ausbildungsgang_edit' => TRUE,
    'knowledge' => TRUE,
    'groups_overview' => TRUE,
    'statistics_overview' => TRUE,
    'knowledgebase_book' => TRUE,
    'knowledgebase_upload_file' => TRUE,
    'groups_experience' => TRUE,
  );
  $export['default_path_breadcrumbs'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'path_breadcrumbs_home_link_title';
  $strongarm->value = 'Startseite';
  $export['path_breadcrumbs_home_link_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'path_breadcrumbs_internal_render';
  $strongarm->value = '0';
  $export['path_breadcrumbs_internal_render'] = $strongarm;

  return $export;
}
