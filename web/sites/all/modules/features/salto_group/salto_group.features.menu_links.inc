<?php

/**
 * @file
 * salto_group.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function salto_group_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_groups:groups.
  $menu_links['main-menu_groups:groups'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'groups',
    'router_path' => 'groups',
    'link_title' => 'Groups',
    'options' => array(
      'identifier' => 'main-menu_groups:groups',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-groups_beitrge:posts.
  $menu_links['menu-groups_beitrge:posts'] = array(
    'menu_name' => 'menu-groups',
    'link_path' => 'posts',
    'router_path' => 'posts',
    'link_title' => 'Beiträge',
    'options' => array(
      'identifier' => 'menu-groups_beitrge:posts',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-groups_dateien:posts.
  $menu_links['menu-groups_dateien:posts'] = array(
    'menu_name' => 'menu-groups',
    'link_path' => 'posts',
    'router_path' => 'posts',
    'link_title' => 'Dateien',
    'options' => array(
      'identifier' => 'menu-groups_dateien:posts',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Beiträge');
  t('Dateien');
  t('Groups');

  return $menu_links;
}
