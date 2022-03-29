<?php
/**
 * @file
 * salto_search.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function salto_search_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-suche_beitrge:search/node.
  $menu_links['menu-suche_beitrge:search/node'] = array(
    'menu_name' => 'menu-suche',
    'link_path' => 'search/node',
    'router_path' => 'search/%',
    'link_title' => 'Beiträge',
    'options' => array(
      'identifier' => 'menu-suche_beitrge:search/node',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-suche_dateien:search/file.
  $menu_links['menu-suche_dateien:search/file'] = array(
    'menu_name' => 'menu-suche',
    'link_path' => 'search/file',
    'router_path' => 'search/%',
    'link_title' => 'Dateien',
    'options' => array(
      'identifier' => 'menu-suche_dateien:search/file',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-suche_kommentare:search/comment.
  $menu_links['menu-suche_kommentare:search/comment'] = array(
    'menu_name' => 'menu-suche',
    'link_path' => 'search/comment',
    'router_path' => 'search/%',
    'link_title' => 'Kommentare',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-suche_kommentare:search/comment',
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
  t('Beiträge');
  t('Dateien');
  t('Kommentare');

  return $menu_links;
}
