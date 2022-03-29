<?php

/**
 * @file
 * salto_files.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function salto_files_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_type") {
    return array("version" => "1");
  }
  if ($module == "media_derivatives" && $api == "media_derivatives_presets") {
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
function salto_files_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function salto_files_image_default_styles() {
  $styles = array();

  // Exported image style: document_thumb_squared.
  $styles['document_thumb_squared'] = array(
    'label' => 'Document Thumb Squared (100x100)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => -10,
      ),
      4 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 100,
            'height' => 100,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => -8,
      ),
      5 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'anchor' => 'left-top',
        ),
        'weight' => -9,
      ),
    ),
  );

  // Exported image style: file_140x140.
  $styles['file_140x140'] = array(
    'label' => 'File: preview (140x140)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 140,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 140,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      3 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '#ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 140,
            'height' => 140,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: media_140x140.
  $styles['media_140x140'] = array(
    'label' => 'Media: preview (140x140)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 140,
          'height' => 140,
        ),
        'weight' => 2,
      ),
      4 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 'center',
          'alpha' => 80,
          'path' => 'sites/all/files/play.png',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: videdeoplayer_708x398.
  $styles['videdeoplayer_708x398'] = array(
    'label' => 'Videdeoplayer_708x398',
    'effects' => array(
      11 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 398,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      12 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 708,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: video_medium.
  $styles['video_medium'] = array(
    'label' => 'Video Medium (220x220)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 220,
          'height' => 220,
          'upscale' => 1,
        ),
        'weight' => 0,
      ),
      2 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 'center',
          'alpha' => 80,
          'path' => 'sites/all/files/play.png',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: video_thumb_squared.
  $styles['video_thumb_squared'] = array(
    'label' => 'Video Thumb Squared (100x100)',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 100,
          'height' => 100,
        ),
        'weight' => -10,
      ),
      2 => array(
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'center',
          'ypos' => 'center',
          'alpha' => 80,
          'path' => 'sites/all/files/play.png',
        ),
        'weight' => -8,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function salto_files_node_info() {
  $items = array(
    'file_comments' => array(
      'name' => t('Datei Kommentare'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
