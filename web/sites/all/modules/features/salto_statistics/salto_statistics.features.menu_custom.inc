<?php
/**
 * @file
 * salto_statistics.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function salto_statistics_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'Das <em>Management-Menü</em> enthält Links für administrative Aufgaben.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-statistik.
  $menus['menu-statistik'] = array(
    'menu_name' => 'menu-statistik',
    'title' => 'Statistik',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Das <em>Management-Menü</em> enthält Links für administrative Aufgaben.');
  t('Management');
  t('Statistik');

  return $menus;
}
