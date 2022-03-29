<?php

/**
 * Implements hook_preprocess_page().
 *
 */
function salto_core_preprocess_page() {

  //we want to set the active trail for posts here
  $path = current_path();

  $variants = path_breadcrumbs_load_variant($path);

  if (!empty($variants) && isset($variants->variant->paths_prepared)) {
    $paths_prepared = $variants->variant->paths_prepared;

    //special cases
    //breadcrumbs set programmatically
    if ($variants->variant->machine_name == 'category_assign') {
      //check type
      if (arg(2) == 'posts') {
        menu_set_active_item('posts');
      }
      elseif (arg(2) == 'materials') {
        menu_set_active_item('materials');
      }
    }

    if (!empty($paths_prepared[0])) {
      //set active trail
      if (strstr($paths_prepared[0], 'node')) {
        //set active item for
        //knowledge book
        menu_set_active_item('posts');
      }
      else {
        if (!in_array($paths_prepared[0], ['<none>', '<front>'])) {
          menu_set_active_item($paths_prepared[0]);
        }
      }
    }
  }
}

/**
 * set active trail for knowledgebase left menu
 *
 * @param type $tree
 * @param type $config
 */
function salto_core_menu_block_tree_alter(&$tree, &$config) {

  //handle knowledgebase left menu only
  if ($config['menu_name'] != 'menu-knowledgebase-left' && $config['menu_name'] != 'menu-groups') {
    return;
  }

  //node types handled for setting active trail
  $menu_items_titles = ['Beiträge'];

  //check path
  $node = menu_get_object();

  if (!empty($node->nid)) {
    foreach ($tree as &$ti) {
      if ($ti['link']['title'] == $menu_items_titles[0]) {
        $ti['link']['in_active_trail'] = TRUE;
      }
    }
  }
}
