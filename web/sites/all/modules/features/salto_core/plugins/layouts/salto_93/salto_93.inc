<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = [
  'title' => t('Nine-Three'),
  'category' => t('Salto-Bip'),
  'icon' => 'salto_93.png',
  'theme' => 'salto_93',
  'admin css' => '../salto-layout-admin.css',
  'regions' => [
    'left' => t('Left side'),
    'right' => t('Right side'),
  ],
];
