<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = [
  'title' => t('Three-Six-Three'),
  'category' => t('Salto-Bip'),
  'icon' => 'salto_363.png',
  'theme' => 'salto_363',
  'admin css' => '../salto-layout-admin.css',
  'regions' => [
    'left' => t('Left side'),
    'middle' => t('Middle column'),
    'right' => t('Right side'),
  ],
];
