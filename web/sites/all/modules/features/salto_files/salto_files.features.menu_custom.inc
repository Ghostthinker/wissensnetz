<?php

/**
 * @file
 * salto_files.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function salto_files_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-knowledgebase-files-cats.
  $menus['menu-knowledgebase-files-cats'] = array(
    'menu_name' => 'menu-knowledgebase-files-cats',
    'title' => 'Lehr-Lern-Materialien Kategorien',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Lehr-Lern-Materialien Kategorien');

  return $menus;
}
