<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = [
  'title' => t('Three-Nine'),
  'category' => t('Salto-Bip'),
  'icon' => 'salto_39.png',
  'theme' => 'salto_39',
  'admin css' => '../salto-layout-admin.css',
  'regions' => [
    'left' => t('Left side'),
    'right' => t('Right side'),
  ],
];
