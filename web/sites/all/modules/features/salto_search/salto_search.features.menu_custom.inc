<?php
/**
 * @file
 * salto_search.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function salto_search_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-suche.
  $menus['menu-suche'] = array(
    'menu_name' => 'menu-suche',
    'title' => 'Suche',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Suche');

  return $menus;
}
