<?php

/**
 * @file
 * salto_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function salto_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'suche';
  $page->task = 'page';
  $page->admin_title = 'Suche';
  $page->admin_description = '';
  $page->path = 'search/%entity_type';
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
  $page->menu = array();
  $page->arguments = array(
    'entity_type' => array(
      'id' => 1,
      'identifier' => 'Zeichenkette',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
      'keyword' => 'entity_type',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_suche_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'suche';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Suche Node',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'salto-facet-search-container',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'node',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'salto_363';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'default' => NULL,
    ),
    'style' => 'default',
  );
  $display->cache = array();
  $display->title = 'Beiträge';
  $display->uuid = '558240b6-a8ae-4107-aea4-bf1e89fd7345';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_suche_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-24b228e3-6f7d-4f0b-9bde-cc486ab80bc6';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-suche';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-suche',
    'parent_mlid' => 'menu-suche:0',
    'title_link' => 0,
    'admin_title' => 'Suche',
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
    'style' => 'default',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '24b228e3-6f7d-4f0b-9bde-cc486ab80bc6';
  $display->content['new-24b228e3-6f7d-4f0b-9bde-cc486ab80bc6'] = $pane;
  $display->panels['left'][0] = 'new-24b228e3-6f7d-4f0b-9bde-cc486ab80bc6';
  $pane = new stdClass();
  $pane->pid = 'new-e547bb62-a25c-45e7-9d20-b90a5bf771f9';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-5808fa01cd5eb6d38d296251f1939506';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'exposed-filter-node-search',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e547bb62-a25c-45e7-9d20-b90a5bf771f9';
  $display->content['new-e547bb62-a25c-45e7-9d20-b90a5bf771f9'] = $pane;
  $display->panels['left'][1] = 'new-e547bb62-a25c-45e7-9d20-b90a5bf771f9';
  $pane = new stdClass();
  $pane->pid = 'new-b1740222-bcb1-41b4-8a55-9e01fd0c9c66';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-nX7OckzG8ZuopQWtdC7zOIap6bK7v15R';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Autor',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'salto-facet-search',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b1740222-bcb1-41b4-8a55-9e01fd0c9c66';
  $display->content['new-b1740222-bcb1-41b4-8a55-9e01fd0c9c66'] = $pane;
  $display->panels['left'][2] = 'new-b1740222-bcb1-41b4-8a55-9e01fd0c9c66';
  $pane = new stdClass();
  $pane->pid = 'new-7c6a3528-3b6a-41ac-b735-8608acbb41f1';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-hO4YDdyAY14EW0Apfl1dz0rhB4086LJy';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Autor(en)',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'salto-facet-search',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '7c6a3528-3b6a-41ac-b735-8608acbb41f1';
  $display->content['new-7c6a3528-3b6a-41ac-b735-8608acbb41f1'] = $pane;
  $display->panels['left'][3] = 'new-7c6a3528-3b6a-41ac-b735-8608acbb41f1';
  $pane = new stdClass();
  $pane->pid = 'new-2d72b45c-31ef-4f73-b22d-36b1f799f2d6';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-vQSQijtfof0pYJS2UueuRyioHW1CB7gK';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Schlagworte',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'salto-facet-search',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '2d72b45c-31ef-4f73-b22d-36b1f799f2d6';
  $display->content['new-2d72b45c-31ef-4f73-b22d-36b1f799f2d6'] = $pane;
  $display->panels['left'][4] = 'new-2d72b45c-31ef-4f73-b22d-36b1f799f2d6';
  $pane = new stdClass();
  $pane->pid = 'new-b9c8c1c4-ac3a-4089-bc59-c817473f4a05';
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
  $pane->uuid = 'b9c8c1c4-ac3a-4089-bc59-c817473f4a05';
  $display->content['new-b9c8c1c4-ac3a-4089-bc59-c817473f4a05'] = $pane;
  $display->panels['middle'][0] = 'new-b9c8c1c4-ac3a-4089-bc59-c817473f4a05';
  $pane = new stdClass();
  $pane->pid = 'new-20d4d6ec-cf7f-4e0a-afb5-b4f918082043';
  $pane->panel = 'middle';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-suche';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-suche:0',
    'title_link' => 0,
    'admin_title' => 'Suche',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-suche',
    'parent_mlid' => '0',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'mobile responsive',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '20d4d6ec-cf7f-4e0a-afb5-b4f918082043';
  $display->content['new-20d4d6ec-cf7f-4e0a-afb5-b4f918082043'] = $pane;
  $display->panels['middle'][1] = 'new-20d4d6ec-cf7f-4e0a-afb5-b4f918082043';
  $pane = new stdClass();
  $pane->pid = 'new-7e54dc4e-d7f2-487b-adf7-9ee208c9d766';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'salto_search_node-panel_salto_search_node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'default',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '7e54dc4e-d7f2-487b-adf7-9ee208c9d766';
  $display->content['new-7e54dc4e-d7f2-487b-adf7-9ee208c9d766'] = $pane;
  $display->panels['middle'][2] = 'new-7e54dc4e-d7f2-487b-adf7-9ee208c9d766';
  $pane = new stdClass();
  $pane->pid = 'new-5fdbbef5-14ba-42e7-a201-f886836c68ec';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Authors and Editors',
    'title' => 'Personen',
    'body' => '<?php
return theme(\'salto_search_authors_and_editors_theme\');

?>',
    'format' => 'php_code',
    'substitute' => 0,
    'name' => 'search_pane_authors_and_editors',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'bip_side_box pane-people',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5fdbbef5-14ba-42e7-a201-f886836c68ec';
  $display->content['new-5fdbbef5-14ba-42e7-a201-f886836c68ec'] = $pane;
  $display->panels['right'][0] = 'new-5fdbbef5-14ba-42e7-a201-f886836c68ec';
  $pane = new stdClass();
  $pane->pid = 'new-4dc000fd-11e7-47d5-afe9-f1404144b421';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '',
    'format' => 'editor',
    'substitute' => TRUE,
    'name' => 'search_pane_organisations',
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
  $pane->uuid = '4dc000fd-11e7-47d5-afe9-f1404144b421';
  $display->content['new-4dc000fd-11e7-47d5-afe9-f1404144b421'] = $pane;
  $display->panels['right'][1] = 'new-4dc000fd-11e7-47d5-afe9-f1404144b421';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_suche_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'suche';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Suche File',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'salto-facet-search-container',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'file',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  );
  $display->cache = array();
  $display->title = 'Dateien';
  $display->uuid = '558240b6-a8ae-4107-aea4-bf1e89fd7345';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_suche_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ee95424c-7ca2-41fe-bac5-29be5387ae63';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-suche';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-suche',
    'parent_mlid' => 'menu-suche:0',
    'title_link' => 0,
    'admin_title' => 'Suche',
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
  $pane->uuid = 'ee95424c-7ca2-41fe-bac5-29be5387ae63';
  $display->content['new-ee95424c-7ca2-41fe-bac5-29be5387ae63'] = $pane;
  $display->panels['left'][0] = 'new-ee95424c-7ca2-41fe-bac5-29be5387ae63';
  $pane = new stdClass();
  $pane->pid = 'new-342ca8e5-02c3-486b-af0f-0c5faf0ae18b';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-1527fffde03eb7b80006d58a9d38841c';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 1,
    'override_title_text' => '',
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
  $pane->uuid = '342ca8e5-02c3-486b-af0f-0c5faf0ae18b';
  $display->content['new-342ca8e5-02c3-486b-af0f-0c5faf0ae18b'] = $pane;
  $display->panels['left'][1] = 'new-342ca8e5-02c3-486b-af0f-0c5faf0ae18b';
  $pane = new stdClass();
  $pane->pid = 'new-eabb724c-8752-4238-b27c-d2e281539b9e';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-yAg5iE1C4s56RJk0rfqQEdGamYENnSDs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Autor',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'salto-facet-search',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'eabb724c-8752-4238-b27c-d2e281539b9e';
  $display->content['new-eabb724c-8752-4238-b27c-d2e281539b9e'] = $pane;
  $display->panels['left'][2] = 'new-eabb724c-8752-4238-b27c-d2e281539b9e';
  $pane = new stdClass();
  $pane->pid = 'new-1d3fea06-d2d7-4a60-a4a4-ae37e2388689';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-8b6sAFXHV5RwuiPfu8oJna1HHjgUJO6O';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Kategorie',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'salto-facet-search',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '1d3fea06-d2d7-4a60-a4a4-ae37e2388689';
  $display->content['new-1d3fea06-d2d7-4a60-a4a4-ae37e2388689'] = $pane;
  $display->panels['left'][3] = 'new-1d3fea06-d2d7-4a60-a4a4-ae37e2388689';
  $pane = new stdClass();
  $pane->pid = 'new-2e417219-1dd5-4977-a376-056a8f32bbec';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-qEhBkNszo0Jmu7U2yI0QEjpAC4uHS019';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Schlagworte',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'salto-facet-search',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '2e417219-1dd5-4977-a376-056a8f32bbec';
  $display->content['new-2e417219-1dd5-4977-a376-056a8f32bbec'] = $pane;
  $display->panels['left'][4] = 'new-2e417219-1dd5-4977-a376-056a8f32bbec';
  $pane = new stdClass();
  $pane->pid = 'new-057deb86-c201-45d1-82e9-cbf504f0f024';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-kO97d1g4XzIXtLK8N7PxGiY9HEK72Z2u';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Organisationen',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'salto-facet-search',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '057deb86-c201-45d1-82e9-cbf504f0f024';
  $display->content['new-057deb86-c201-45d1-82e9-cbf504f0f024'] = $pane;
  $display->panels['left'][5] = 'new-057deb86-c201-45d1-82e9-cbf504f0f024';
  $pane = new stdClass();
  $pane->pid = 'new-c7cf06d6-2ff7-42f2-8d98-cd10dcb92b29';
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
  $pane->uuid = 'c7cf06d6-2ff7-42f2-8d98-cd10dcb92b29';
  $display->content['new-c7cf06d6-2ff7-42f2-8d98-cd10dcb92b29'] = $pane;
  $display->panels['middle'][0] = 'new-c7cf06d6-2ff7-42f2-8d98-cd10dcb92b29';
  $pane = new stdClass();
  $pane->pid = 'new-f90e3ab8-849a-4b14-a390-3b229f5b4990';
  $pane->panel = 'middle';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-suche';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-suche:0',
    'title_link' => 0,
    'admin_title' => 'Suche',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-suche',
    'parent_mlid' => '0',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'mobile responsive',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f90e3ab8-849a-4b14-a390-3b229f5b4990';
  $display->content['new-f90e3ab8-849a-4b14-a390-3b229f5b4990'] = $pane;
  $display->panels['middle'][1] = 'new-f90e3ab8-849a-4b14-a390-3b229f5b4990';
  $pane = new stdClass();
  $pane->pid = 'new-4c56bb5f-2e66-4d9e-9cb6-614f0f3a9595';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'salto_search_file-panel_salto_search_file';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4c56bb5f-2e66-4d9e-9cb6-614f0f3a9595';
  $display->content['new-4c56bb5f-2e66-4d9e-9cb6-614f0f3a9595'] = $pane;
  $display->panels['middle'][2] = 'new-4c56bb5f-2e66-4d9e-9cb6-614f0f3a9595';
  $pane = new stdClass();
  $pane->pid = 'new-173ef334-df2f-402e-b914-00913310feb3';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'search_pane_authors_and_editors';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'editor',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'bip_side_box pane-people',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '173ef334-df2f-402e-b914-00913310feb3';
  $display->content['new-173ef334-df2f-402e-b914-00913310feb3'] = $pane;
  $display->panels['right'][0] = 'new-173ef334-df2f-402e-b914-00913310feb3';
  $pane = new stdClass();
  $pane->pid = 'new-a6122802-2df4-4954-b9fe-678e09ca69a1';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'search_pane_organisations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '',
    'format' => 'editor',
    'substitute' => TRUE,
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
  $pane->uuid = 'a6122802-2df4-4954-b9fe-678e09ca69a1';
  $display->content['new-a6122802-2df4-4954-b9fe-678e09ca69a1'] = $pane;
  $display->panels['right'][1] = 'new-a6122802-2df4-4954-b9fe-678e09ca69a1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_suche_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'suche';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Search Comment',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'salto-facet-search-container',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'comment',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  );
  $display->cache = array();
  $display->title = 'Kommentare';
  $display->uuid = '558240b6-a8ae-4107-aea4-bf1e89fd7345';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_suche_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-24b228e3-6f7d-4f0b-9bde-cc486ab80bc6';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-suche';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-suche',
    'parent_mlid' => 'menu-suche:0',
    'title_link' => 0,
    'admin_title' => 'Suche',
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
  $pane->uuid = '24b228e3-6f7d-4f0b-9bde-cc486ab80bc6';
  $display->content['new-24b228e3-6f7d-4f0b-9bde-cc486ab80bc6'] = $pane;
  $display->panels['left'][0] = 'new-24b228e3-6f7d-4f0b-9bde-cc486ab80bc6';
  $pane = new stdClass();
  $pane->pid = 'new-a360032a-b2ff-4f33-aa77-4b012efe28b2';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-efd9c32e08b634cf01292558a86ce037';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 0,
    'override_title_text' => '',
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
  $pane->uuid = 'a360032a-b2ff-4f33-aa77-4b012efe28b2';
  $display->content['new-a360032a-b2ff-4f33-aa77-4b012efe28b2'] = $pane;
  $display->panels['left'][1] = 'new-a360032a-b2ff-4f33-aa77-4b012efe28b2';
  $pane = new stdClass();
  $pane->pid = 'new-8748cb62-d642-409a-8696-0529abe42f52';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-G8g18p6Mz7pOEXbg1Aeuw4SM6nv1wplC';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Autor',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'salto-facet-search',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '8748cb62-d642-409a-8696-0529abe42f52';
  $display->content['new-8748cb62-d642-409a-8696-0529abe42f52'] = $pane;
  $display->panels['left'][2] = 'new-8748cb62-d642-409a-8696-0529abe42f52';
  $pane = new stdClass();
  $pane->pid = 'new-58570799-0f6c-4668-a29d-f2397bd158a3';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'facetapi-62LS1jFBXAhxNQAar18Ee25Kz4acsBAx';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Organisation',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'salto-facet-search',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '58570799-0f6c-4668-a29d-f2397bd158a3';
  $display->content['new-58570799-0f6c-4668-a29d-f2397bd158a3'] = $pane;
  $display->panels['left'][3] = 'new-58570799-0f6c-4668-a29d-f2397bd158a3';
  $pane = new stdClass();
  $pane->pid = 'new-7534467a-f833-4d5f-9c24-b705ef557802';
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
  $pane->uuid = '7534467a-f833-4d5f-9c24-b705ef557802';
  $display->content['new-7534467a-f833-4d5f-9c24-b705ef557802'] = $pane;
  $display->panels['middle'][0] = 'new-7534467a-f833-4d5f-9c24-b705ef557802';
  $pane = new stdClass();
  $pane->pid = 'new-417a1d28-0fd8-461c-96cc-c36495de3b7d';
  $pane->panel = 'middle';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-suche';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-suche:0',
    'title_link' => 0,
    'admin_title' => 'Suche',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-suche',
    'parent_mlid' => '0',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'mobile responsive',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '417a1d28-0fd8-461c-96cc-c36495de3b7d';
  $display->content['new-417a1d28-0fd8-461c-96cc-c36495de3b7d'] = $pane;
  $display->panels['middle'][1] = 'new-417a1d28-0fd8-461c-96cc-c36495de3b7d';
  $pane = new stdClass();
  $pane->pid = 'new-905f08ab-a439-48c6-b814-21ee981407b7';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'salto_search_comment-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '905f08ab-a439-48c6-b814-21ee981407b7';
  $display->content['new-905f08ab-a439-48c6-b814-21ee981407b7'] = $pane;
  $display->panels['middle'][2] = 'new-905f08ab-a439-48c6-b814-21ee981407b7';
  $pane = new stdClass();
  $pane->pid = 'new-8c96e99a-001a-4443-9609-01ab07380b66';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'search_pane_authors_and_editors';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'editor',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'bip_side_box pane-people',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8c96e99a-001a-4443-9609-01ab07380b66';
  $display->content['new-8c96e99a-001a-4443-9609-01ab07380b66'] = $pane;
  $display->panels['right'][0] = 'new-8c96e99a-001a-4443-9609-01ab07380b66';
  $pane = new stdClass();
  $pane->pid = 'new-187fea31-6ae8-4f8b-a18c-33d9c82a8dbe';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'search_pane_organisations';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '',
    'format' => 'editor',
    'substitute' => TRUE,
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
  $pane->uuid = '187fea31-6ae8-4f8b-a18c-33d9c82a8dbe';
  $display->content['new-187fea31-6ae8-4f8b-a18c-33d9c82a8dbe'] = $pane;
  $display->panels['right'][1] = 'new-187fea31-6ae8-4f8b-a18c-33d9c82a8dbe';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['suche'] = $page;

  return $pages;

}
