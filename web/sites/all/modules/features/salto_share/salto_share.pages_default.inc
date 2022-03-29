<?php
/**
 * @file
 * salto_share.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function salto_share_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'groups_shared_posts';
  $page->task = 'page';
  $page->admin_title = 'groups-shared-posts';
  $page->admin_description = 'Knowledgebase main area';
  $page->path = 'groups/%node/shared';
  $page->access = array(
    'plugins' => array(),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Erfahrungsberichte',
    'name' => 'menu-knowledgebase-left',
    'weight' => '3',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_groups_shared_posts_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'groups_shared_posts';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Zielseite',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'salto_363';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
    ),
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Geteilte Beiträge';
  $display->uuid = 'e41a225e-1178-4815-b625-8c481227457c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_groups_shared_posts_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2df9b298-b148-4dbc-bb2d-8b9d5d30cf22';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-groups';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-groups',
    'parent_mlid' => 'menu-groups:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2df9b298-b148-4dbc-bb2d-8b9d5d30cf22';
  $display->content['new-2df9b298-b148-4dbc-bb2d-8b9d5d30cf22'] = $pane;
  $display->panels['left'][0] = 'new-2df9b298-b148-4dbc-bb2d-8b9d5d30cf22';
  $pane = new stdClass();
  $pane->pid = 'new-8ac96df8-be93-4892-84b6-928832c9d561';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'group_shared_posts-base';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8ac96df8-be93-4892-84b6-928832c9d561';
  $display->content['new-8ac96df8-be93-4892-84b6-928832c9d561'] = $pane;
  $display->panels['middle'][0] = 'new-8ac96df8-be93-4892-84b6-928832c9d561';
  $pane = new stdClass();
  $pane->pid = 'new-839eb5bf-bc87-427c-a4d5-973b0f80305d';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'groups',
    'context' => array(
      0 => 'empty',
      1 => 'argument_entity_id:node_1',
      2 => 'empty',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '839eb5bf-bc87-427c-a4d5-973b0f80305d';
  $display->content['new-839eb5bf-bc87-427c-a4d5-973b0f80305d'] = $pane;
  $display->panels['right'][0] = 'new-839eb5bf-bc87-427c-a4d5-973b0f80305d';
  $pane = new stdClass();
  $pane->pid = 'new-24efb7f5-aaf9-4343-97c8-2fa08449a5d5';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '24efb7f5-aaf9-4343-97c8-2fa08449a5d5';
  $display->content['new-24efb7f5-aaf9-4343-97c8-2fa08449a5d5'] = $pane;
  $display->panels['right'][1] = 'new-24efb7f5-aaf9-4343-97c8-2fa08449a5d5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_shared_posts'] = $page;

  return $pages;

}
