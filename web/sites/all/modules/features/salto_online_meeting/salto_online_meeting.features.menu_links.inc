<?php

/**
 * @file
 * salto_online_meeting.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function salto_online_meeting_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_online-meetings:online-meetings/status.
  $menu_links['main-menu_online-meetings:online-meetings/status'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'online-meetings/status',
    'router_path' => 'online-meetings/status',
    'link_title' => 'Online meetings',
    'options' => array(
      'identifier' => 'main-menu_online-meetings:online-meetings/status',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-groups_online-meetings:http://online-meetings.
  $menu_links['menu-groups_online-meetings:http://online-meetings'] = array(
    'menu_name' => 'menu-groups',
    'link_path' => 'http://online-meetings',
    'router_path' => '',
    'link_title' => 'Online meetings',
    'options' => array(
      'identifier' => 'menu-groups_online-meetings:http://online-meetings',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-online-meetings_online-meetings:http://online-meetings.
  $menu_links['menu-online-meetings_online-meetings:http://online-meetings'] = array(
    'menu_name' => 'menu-online-meetings',
    'link_path' => 'http://online-meetings',
    'router_path' => '',
    'link_title' => 'Online meetings',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-online-meetings_online-meetings:http://online-meetings',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: navigation_online-meeting:node/add/online-meeting.
  $menu_links['navigation_online-meeting:node/add/online-meeting'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/online-meeting',
    'router_path' => 'node/add/online-meeting',
    'link_title' => 'Online meeting',
    'options' => array(
      'identifier' => 'navigation_online-meeting:node/add/online-meeting',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Online meeting');
  t('Online meetings');

  return $menu_links;
}
