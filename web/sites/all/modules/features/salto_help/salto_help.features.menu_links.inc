<?php
/**
 * @file
 * salto_help.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function salto_help_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_hilfe:context_support/nojs/contact/user_bar.
  $menu_links['user-menu_hilfe:context_support/nojs/contact/user_bar'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'context_support/nojs/contact/user_bar',
    'router_path' => 'context_support/%/contact',
    'link_title' => 'Hilfe',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'help-dropdown-link',
          1 => 'use-ajax',
          2 => 'ctools-use-modal',
        ),
      ),
      'identifier' => 'user-menu_hilfe:context_support/nojs/contact/user_bar',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Hilfe');

  return $menu_links;
}
