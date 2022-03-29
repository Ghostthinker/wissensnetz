<?php
/**
 * @file
 * salto_user.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function salto_user_ctools_plugin_api($module = NULL, $api = NULL) {
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
function salto_user_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function salto_user_image_default_styles() {
  $styles = array();

  // Exported image style: user_100x100.
  $styles['user_100x100'] = array(
    'label' => 'User: Medium (100x100)',
    'effects' => array(
      9 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'strength' => 'high',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: user_220x200.
  $styles['user_220x200'] = array(
    'label' => 'User: Large (220x200)',
    'effects' => array(
      8 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 220,
          'strength' => 'high',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: user_30x30.
  $styles['user_30x30'] = array(
    'label' => 'User: Tiny (30x30)',
    'effects' => array(
      12 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 30,
          'height' => 30,
          'strength' => 'high',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: user_60x60.
  $styles['user_60x60'] = array(
    'label' => 'User: Small (60x60)',
    'effects' => array(
      13 => array(
        'name' => 'imagefield_focus_scale_and_crop',
        'data' => array(
          'width' => 60,
          'height' => 60,
          'strength' => 'high',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: user_small.
  $styles['user_small'] = array(
    'label' => 'User Small',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_default_profile2_type().
 */
function salto_user_default_profile2_type() {
  $items = array();
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "main",
    "label" : "Profile",
    "weight" : "0",
    "data" : { "registration" : 0 }
  }');
  return $items;
}
