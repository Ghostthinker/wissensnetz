<?php
/**
 * @file
 * salto_statistics.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function salto_statistics_ctools_plugin_api($module = NULL, $api = NULL) {
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
function salto_statistics_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function salto_statistics_node_info() {
  $items = array(
    'statistics_daily' => array(
      'name' => t('Statistics daily'),
      'base' => 'node_content',
      'description' => t('Daily statistics report'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
