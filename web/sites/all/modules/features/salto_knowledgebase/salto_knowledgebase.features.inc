<?php

/**
 * @file
 * salto_knowledgebase.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function salto_knowledgebase_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
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
function salto_knowledgebase_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function salto_knowledgebase_image_default_styles() {
  $styles = array();

  // Exported image style: default_selection_wysiwyg.
  $styles['default_selection_wysiwyg'] = array(
    'label' => 'Default Selection WYSIWYG',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 458,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: term_cover.
  $styles['term_cover'] = array(
    'label' => 'Term Cover',
    'effects' => array(
      2 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 240,
          'strength' => 'low',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: term_cover_mail.
  $styles['term_cover_mail'] = array(
    'label' => 'Term Cover Mail',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 540,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 540,
          'height' => 135,
        ),
        'weight' => -9,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function salto_knowledgebase_node_info() {
  $items = array(
    'post' => array(
      'name' => t('Beitrag'),
      'base' => 'node_content',
      'description' => t('Main content type for the knowledgebase.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
