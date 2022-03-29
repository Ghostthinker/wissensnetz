<?php

/**
 * @file
 * salto_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function salto_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function salto_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function salto_core_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Seite'),
      'base' => 'node_content',
      'description' => t('A Basic page'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
