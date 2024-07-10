<?php

/**
 * @file
 * Plugin to handle the 'profile2' content type which allows individual profiles
 * to be embedded into a panel.
 */
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = [
  'single' => TRUE,
  'title' => t('Fast navigation'),
  'description' => t('Fast navigation'),
  'category' => t('Fast navigation'),
  'defaults' => ['type' => NULL],
];

/**
 * Render the user profile content type.
 */
function salto_core_fast_navigation_content_type_render($subtype, $conf, $panel_args, $context) {
  $settings = variable_get('customization_settings', []);

  if (empty($settings['fast_navigation'])) {
    return;
  }


  $block = new stdClass();
  $block->title = t('Fast navigation');
  $block->content = $settings['fast_navigation'];
  return $block;
}

/**
 * Display the administrative title for a panel pane in the drag & drop UI.
 */
function salto_core_fast_navigation_content_type_admin_title($subtype, $conf, $context) {
  return t('Fast navigation');
}
