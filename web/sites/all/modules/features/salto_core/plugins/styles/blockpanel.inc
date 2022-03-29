<?php

/**
 * @file
 * Definition of the 'naked' panel style.
 */

// Plugin definition
$plugin = [
  'title' => t('Bootstrap Panel'),
  'description' => t('Display the pane or region with no markup, not even a title.'),
  'render region' => 'salto_core_blockpanel_style_render_region',
  'render pane' => 'salto_core_blockpanel_style_render_pane',
  'weight' => -5,
  'hook theme' => [
    'panels_bootstrap_panel' => [
      'variables' => ['content' => NULL, 'title' => NULL, 'css_class' => NULL],
      'path' => drupal_get_path('module', 'salto_core') . '/plugins/styles',
      'template' => 'panels-bootstrap-panel',
    ],
  ],
];

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_salto_core_blockpanel_style_render_region($vars) {
  return implode($vars['panes']);
}

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_salto_core_blockpanel_style_render_pane($vars) {

  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];

  $title = !empty($vars['content']->title) ? $vars['content']->title : NULL;

  if (empty($content->content)) {
    return;
  }
  //unset the title for the normal panel style
  unset($content->title);

  $output = theme('panels_pane', [
    'content' => $content,
    'pane' => $pane,
    'display' => $display,
  ]);

  // Just stick a box around the standard theme_panels_pane.
  $output = theme('panels_bootstrap_panel', [
    'content' => $output,
    'title' => $title,
    'css_class' => $vars['content']->css_class,
  ]);

  return $output;
}

