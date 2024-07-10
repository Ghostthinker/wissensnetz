<?php

/**
 * @file
 * salto_online_meeting.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function salto_online_meeting_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-online-meetings.
  $menus['menu-online-meetings'] = array(
    'menu_name' => 'menu-online-meetings',
    'title' => 'Online-meetings',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Online-meetings');

  return $menus;
}
