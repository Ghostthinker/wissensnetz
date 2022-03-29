<?php

/**
 * @file
 * salto_group.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function salto_group_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Hauptmenü',
    'description' => 'Das <em>Hauptmenü</em> wird oft benutzt, um die Hauptbereiche der Website anzuzeigen, häufig in einer Top-Navigationsleiste.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-groups.
  $menus['menu-groups'] = array(
    'menu_name' => 'menu-groups',
    'title' => 'Groups',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Das <em>Hauptmenü</em> wird oft benutzt, um die Hauptbereiche der Website anzuzeigen, häufig in einer Top-Navigationsleiste.');
  t('Groups');
  t('Hauptmenü');

  return $menus;
}
