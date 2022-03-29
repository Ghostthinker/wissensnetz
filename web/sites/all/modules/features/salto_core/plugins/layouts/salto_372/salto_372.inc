<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('Three-Seven-Two'),
  'category' => t('Salto-Bip'),
  'icon' => 'salto_372.png',
  'theme' => 'salto_372',
  'admin css' => '../salto-layout-admin.css',
  'regions' => array(
    'left' => t('Left side'),
    'middle' => t('Middle column'),
    'right' => t('Right side'),
  ),
);
