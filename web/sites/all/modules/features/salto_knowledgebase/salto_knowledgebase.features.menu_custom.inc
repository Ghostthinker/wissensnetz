<?php

/**
 * @file
 * salto_knowledgebase.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function salto_knowledgebase_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-knowledgebase.
  $menus['menu-knowledgebase'] = array(
    'menu_name' => 'menu-knowledgebase',
    'title' => 'Knowledgebase',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Knowledgebase');

  return $menus;
}
