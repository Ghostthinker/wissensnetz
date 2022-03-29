<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('Salto Files Listing'),
  'category' => t('Bildungsnetz'),
  'icon' => 'file_listing.png',
  'theme' => 'file_listing',
  'regions' => array(
    'left' => t('Left'),
    'right' => t('Right'),
    'license_left' => t('License Left'),
    'license_middle' => t('License Middle'),
    'license_right' => t('License Right'),
    'tags' => t(' Tags'),
    'meta_left' => t('Meta Left'),
    'meta_right' => t('Meta Right'),
  ),
);
