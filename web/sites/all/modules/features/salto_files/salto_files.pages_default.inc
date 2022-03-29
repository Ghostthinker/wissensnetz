<?php

/**
 * @file
 * salto_files.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function salto_files_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'knowledgebase_files';
  $page->task = 'page';
  $page->admin_title = 'knowledgebase-files';
  $page->admin_description = 'Knowledgebase main area';
  $page->path = 'materials/!category';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Materialien',
    'name' => 'main-menu',
    'weight' => '-49',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'category' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          6 => '6',
          2 => 0,
          1 => 0,
          8 => 0,
          4 => 0,
          3 => 0,
          5 => 0,
          7 => 0,
        ),
        'breadcrumb' => 0,
        'transform' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_knowledgebase_files_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'knowledgebase_files';
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
  $display->title = '';
  $display->uuid = 'e41a225e-1178-4815-b625-8c481227457c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_knowledgebase_files_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-01a91af4-b80f-453c-b98f-2da66faa79a0';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-knowledgebase-files-cats';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-knowledgebase-files-cats',
    'parent_mlid' => 'menu-knowledgebase-files-cats:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => 0,
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
  $pane->uuid = '01a91af4-b80f-453c-b98f-2da66faa79a0';
  $display->content['new-01a91af4-b80f-453c-b98f-2da66faa79a0'] = $pane;
  $display->panels['left'][0] = 'new-01a91af4-b80f-453c-b98f-2da66faa79a0';
  $pane = new stdClass();
  $pane->pid = 'new-2f74ebc3-4cdd-45d8-a79f-dc3228579869';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-kb_files-files_directory';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 1,
    'override_title_text' => 'Filter',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2f74ebc3-4cdd-45d8-a79f-dc3228579869';
  $display->content['new-2f74ebc3-4cdd-45d8-a79f-dc3228579869'] = $pane;
  $display->panels['left'][1] = 'new-2f74ebc3-4cdd-45d8-a79f-dc3228579869';
  $pane = new stdClass();
  $pane->pid = 'new-77ddeec4-def0-45ad-bdd6-05f44261f012';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'salto_search-salto_block_search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '77ddeec4-def0-45ad-bdd6-05f44261f012';
  $display->content['new-77ddeec4-def0-45ad-bdd6-05f44261f012'] = $pane;
  $display->panels['middle'][0] = 'new-77ddeec4-def0-45ad-bdd6-05f44261f012';
  $pane = new stdClass();
  $pane->pid = 'new-b1d6ba2e-a802-43df-a928-63343743af0f';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'kb_files-files_directory';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_term_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b1d6ba2e-a802-43df-a928-63343743af0f';
  $display->content['new-b1d6ba2e-a802-43df-a928-63343743af0f'] = $pane;
  $display->panels['middle'][1] = 'new-b1d6ba2e-a802-43df-a928-63343743af0f';
  $pane = new stdClass();
  $pane->pid = 'new-010ee379-a790-4d12-8dc9-6f930be59ec0';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Set title',
    'title' => '',
    'body' => '<?php

if(is_numeric(%category:tid)){
drupal_set_title("%category:name"); 
}
else{
drupal_set_title("Materialien");
}
?>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '010ee379-a790-4d12-8dc9-6f930be59ec0';
  $display->content['new-010ee379-a790-4d12-8dc9-6f930be59ec0'] = $pane;
  $display->panels['middle'][2] = 'new-010ee379-a790-4d12-8dc9-6f930be59ec0';
  $pane = new stdClass();
  $pane->pid = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'materials',
    'context' => array(
      0 => 'empty',
      1 => 'empty',
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
  $pane->uuid = '4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $display->content['new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6'] = $pane;
  $display->panels['right'][0] = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $pane = new stdClass();
  $pane->pid = 'new-bb215474-80a0-46b2-a990-a2b7fe9209f2';
  $pane->panel = 'right';
  $pane->type = 'salto_tagcloud';
  $pane->subtype = 'salto_tagcloud';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'max_age' => '180',
    'max_tags' => '30',
    'vids' => '5',
    'override_title' => 1,
    'override_title_text' => 'Schlagwortwolke',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane_w196',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'bb215474-80a0-46b2-a990-a2b7fe9209f2';
  $display->content['new-bb215474-80a0-46b2-a990-a2b7fe9209f2'] = $pane;
  $display->panels['right'][1] = 'new-bb215474-80a0-46b2-a990-a2b7fe9209f2';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '24efb7f5-aaf9-4343-97c8-2fa08449a5d5';
  $display->content['new-24efb7f5-aaf9-4343-97c8-2fa08449a5d5'] = $pane;
  $display->panels['right'][2] = 'new-24efb7f5-aaf9-4343-97c8-2fa08449a5d5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['knowledgebase_files'] = $page;

  return $pages;

}
