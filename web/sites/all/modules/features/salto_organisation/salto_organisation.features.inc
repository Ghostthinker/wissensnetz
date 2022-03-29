<?php

/**
 * @file
 * salto_organisation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function salto_organisation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function salto_organisation_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function salto_organisation_node_info() {
  $items = array(
    'organisation' => array(
      'name' => t('Organisation'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_og_membership_type().
 */
function salto_organisation_default_og_membership_type() {
  $items = array();
  $items['organisation_membership'] = entity_import('og_membership_type', '{
    "name" : "organisation_membership",
    "description" : "Organisation membership",
    "language" : ""
  }');
  return $items;
}

/**
 * Implements hook_default_salto_invite_type().
 */
function salto_organisation_default_salto_invite_type() {
  $items = array();
  $items['organisation_invite'] = entity_import('salto_invite_type', '{
    "type" : "organisation_invite",
    "label" : "Organisation Invite",
    "weight" : "0",
    "data" : { "sample_data" : 0 }
  }');
  return $items;
}
