<?php
/**
 * Implements hook_field_formatter_info().
 */
function media_webresource_file_formatter_info() {

  $info['media_webresource_link'] = [
    'label' => t('Remote Web link'),
    'description' => t('Render an url to an external site.'),
    'file types' => ['webresource'],

    'default settings' => [
    ],
    'view callback' => 'media_webresource_file_formatter_link_view',
    'mime types' => ['webresource/*'],
  ];
  $info['media_webresource_youtube_player'] = [
    'label' => t('Youtube player'),
    'description' => t('Render the youtube player'),
    'file types' => ['webresource'],
    'default settings' => [
      'autoplay' => FALSE,
      'width' => 640,
      'height' => 390,
      'html5' => TRUE,
    ],
    'view callback' => 'media_webresource_file_formatter_youtube_player_view',
    'settings callback' => 'media_webresource_file_youtube_player_settings',
    'mime types' => ['webresource/youtube'],
  ];

  $info['media_webresource_youtube_thumbnail'] = [
    'label' => t('Youtube Thumbnail'),
    'description' => t('Render the youtube thumbnail'),
    'file types' => ['webresource'],
    'default settings' => [
      'preset' => 'thumbnail',
      'link' => TRUE,
    ],
    'view callback' => 'media_webresource_file_formatter_youtube_thumbnail_view',
    'settings callback' => 'media_webresource_file_youtube_thumbnail_settings',
    'mime types' => ['webresource/youtube'],
  ];
  return $info;
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
 */
function media_webresource_file_formatter_link_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);

  if ($scheme == 'webresource') {
    $info = MediaWebresourceStreamWrapper::getItemFromUri($file->uri);
    if (isset($info['item'])) {
      $url = urldecode($info['item']);
      $element = [
        '#type' => 'link',
        '#href' => urldecode($url),
        '#title' => urldecode($url),
        '#options' => [],
      ];
      return $element;
    }
  }
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
 */
function media_webresource_file_formatter_youtube_thumbnail_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);

  if ($scheme == 'webresource') {

    $info = MediaWebresourceStreamWrapper::getItemFromUri($file->uri);
    if (isset($info['item'])) {
      $id = $info['item'];
      $image_url = "https://img.youtube.com/vi/$id/1.jpg";

      $preset = isset($file->override['preset']) ? $file->override['preset'] : $display['settings']['preset'];

      $image = theme('imagecache_external', [
        'path' => $image_url,
        'style_name' => $preset,
        'alt' => 'youtube',
      ]);

      $element = [
        '#type' => 'link',
        '#title' => $image,
        '#href' => url('file/' . $file->fid),
        '#options' => ['html' => TRUE, 'title' => 'link1'],
        '#suffix' => '<br />',
      ];
      return $element;
    }
  }
}

/**
 * Implements hook_file_formatter_FORMATTER_settings().
 */
function media_webresource_file_youtube_thumbnail_settings($form, &$form_state, $settings) {
  $element = [];

  $element['preset'] = [
    '#title' => t('Image style'),
    '#type' => 'select',
    '#default_value' => $settings['preset'],
    '#options' => image_style_options(),
  ];
  return $element;
}

/**
 * Implements hook_file_formatter_FORMATTER_view().
 */
function media_webresource_file_formatter_youtube_player_view($file, $display, $langcode) {
  $scheme = file_uri_scheme($file->uri);

  if ($scheme == 'webresource') {
    $info = MediaWebresourceStreamWrapper::getItemFromUri($file->uri);
    if (isset($info['item'])) {
      $yotube_id = $info['item'];

      $element = [
        '#theme' => 'media_webresource_youtube_player',
        '#yotube_id' => $yotube_id,
        '#options' => [],
      ];

      // Fake a default for attributes so the ternary doesn't choke.
      $display['settings']['attributes'] = [];
      foreach ([
                 'width',
                 'height',
                 'attributes',
               ] as $setting) {
        $element['#options'][$setting] = isset($file->override[$setting]) ? $file->override[$setting] : $display['settings'][$setting];
      }
      return $element;
    }
  }
}

/**
 * Implements hook_file_formatter_FORMATTER_settings().
 */
function media_webresource_file_youtube_player_settings($form, &$form_state, $settings) {
  $element = [];

  $element['autoplay'] = [
    '#type' => 'checkbox',
    '#title' => t('Autoplay'),
    '#default_value' => $settings['autoplay'],
  ];

  $element['width'] = [
    '#type' => 'textfield',
    '#title' => t('Width'),
    '#default_value' => $settings['width'],
    '#size' => 5,
    '#maxlength' => 5,
    '#field_suffix' => t('pixels'),
  ];
  $element['height'] = [
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#default_value' => $settings['height'],
    '#size' => 5,
    '#maxlength' => 5,
    '#field_suffix' => t('pixels'),
  ];

  return $element;
}
