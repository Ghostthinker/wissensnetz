<?php
/**
 * @file
 * salto_statistics.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function salto_statistics_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-statistik_erweiterte-statistik:statistics/extended.
  $menu_links['menu-statistik_erweiterte-statistik:statistics/extended'] = array(
    'menu_name' => 'menu-statistik',
    'link_path' => 'statistics/extended',
    'router_path' => 'statistics',
    'link_title' => 'Erweiterte Statistik',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-statistik_erweiterte-statistik:statistics/extended',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-statistik_gruppen:statistics/groups.
  $menu_links['menu-statistik_gruppen:statistics/groups'] = array(
    'menu_name' => 'menu-statistik',
    'link_path' => 'statistics/groups',
    'router_path' => 'statistics/groups',
    'link_title' => 'Gruppen',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-statistik_gruppen:statistics/groups',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-statistik_inhalt:statistics/nodes.
  $menu_links['menu-statistik_inhalt:statistics/nodes'] = array(
    'menu_name' => 'menu-statistik',
    'link_path' => 'statistics/nodes',
    'router_path' => 'statistics/nodes',
    'link_title' => 'Inhalt',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-statistik_inhalt:statistics/nodes',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-statistik_personen:statistics/people.
  $menu_links['menu-statistik_personen:statistics/people'] = array(
    'menu_name' => 'menu-statistik',
    'link_path' => 'statistics/people',
    'router_path' => 'statistics/people',
    'link_title' => 'Personen',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-statistik_personen:statistics/people',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Erweiterte Statistik');
  t('Gruppen');
  t('Inhalt');
  t('Personen');

  return $menu_links;
}
