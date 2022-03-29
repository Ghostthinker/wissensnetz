<?php
/**
 * @file
 * salto_statistics.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function salto_statistics_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'statistics';
  $page->task = 'page';
  $page->admin_title = 'Statistik - Nodes';
  $page->admin_description = '';
  $page->path = 'statistics/nodes';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 6,
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
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_statistics_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'statistics';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'salto_39';
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
  $display->title = 'Statistik (Inhalte)';
  $display->uuid = '89af0f7d-eb0d-4eaa-ae42-c6381909493c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_statistics_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-statistik';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-statistik',
    'parent_mlid' => 0,
    'title_link' => 0,
    'admin_title' => 'Statistik',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'parent' => 'menu-statistik:0',
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
  $pane->uuid = 'b68b6a00-2977-40af-a135-02a79af98e24';
  $display->content['new-b68b6a00-2977-40af-a135-02a79af98e24'] = $pane;
  $display->panels['left'][0] = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $pane = new stdClass();
  $pane->pid = 'new-b11229a3-7d26-49cd-8465-a32574cc846b';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-66829a8dfad3cc742386f6810093e125';
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
  $pane->uuid = 'b11229a3-7d26-49cd-8465-a32574cc846b';
  $display->content['new-b11229a3-7d26-49cd-8465-a32574cc846b'] = $pane;
  $display->panels['left'][1] = 'new-b11229a3-7d26-49cd-8465-a32574cc846b';
  $pane = new stdClass();
  $pane->pid = 'new-a5dac222-bd30-4ea8-a3ba-9c89a4a7dc21';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Export Button',
    'title' => '',
    'body' => '<?php 
$query = request_uri();
$query = substr($query, strpos($query, \'?\'));
?>
<a class="btn btn-primary action_link action_export" href="/statistics/nodes/export/xls<?=$query?>" style="float:right;">Statistik exportieren (XLS)</a>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a5dac222-bd30-4ea8-a3ba-9c89a4a7dc21';
  $display->content['new-a5dac222-bd30-4ea8-a3ba-9c89a4a7dc21'] = $pane;
  $display->panels['right'][0] = 'new-a5dac222-bd30-4ea8-a3ba-9c89a4a7dc21';
  $pane = new stdClass();
  $pane->pid = 'new-23e5c7eb-e29b-40d7-8bf8-9db70a0f89de';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'statistics_nodes-panel_statistics_nodes';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '23e5c7eb-e29b-40d7-8bf8-9db70a0f89de';
  $display->content['new-23e5c7eb-e29b-40d7-8bf8-9db70a0f89de'] = $pane;
  $display->panels['right'][1] = 'new-23e5c7eb-e29b-40d7-8bf8-9db70a0f89de';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['statistics'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'statistik';
  $page->task = 'page';
  $page->admin_title = 'Statistik';
  $page->admin_description = '';
  $page->path = 'statistics';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 6,
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
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_statistik_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'statistik';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'salto_39';
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
  $display->title = 'Statistik (Übersicht)';
  $display->uuid = '89af0f7d-eb0d-4eaa-ae42-c6381909493c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_statistik_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-statistik';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-statistik',
    'parent_mlid' => 0,
    'title_link' => 0,
    'admin_title' => 'Statistik',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'parent' => 'menu-statistik:0',
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
  $pane->uuid = 'b68b6a00-2977-40af-a135-02a79af98e24';
  $display->content['new-b68b6a00-2977-40af-a135-02a79af98e24'] = $pane;
  $display->panels['left'][0] = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $pane = new stdClass();
  $pane->pid = 'new-26123f32-6bd5-4892-af68-9eea9962dffe';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-a842239dfab63f9d68031e18a07f5abe';
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
  $pane->uuid = '26123f32-6bd5-4892-af68-9eea9962dffe';
  $display->content['new-26123f32-6bd5-4892-af68-9eea9962dffe'] = $pane;
  $display->panels['left'][1] = 'new-26123f32-6bd5-4892-af68-9eea9962dffe';
  $pane = new stdClass();
  $pane->pid = 'new-6b7785f0-86bc-4805-b279-397cb27a4050';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Export Button',
    'title' => '',
    'body' => '<?php 
$query = request_uri();
$query = substr($query, strpos($query, \'?\'));
?>
<a class="btn btn-primary action_link action_export" href="/statistics/export/xls<?=$query?>" style="float:right;">Statistik exportieren (XLS)</a>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6b7785f0-86bc-4805-b279-397cb27a4050';
  $display->content['new-6b7785f0-86bc-4805-b279-397cb27a4050'] = $pane;
  $display->panels['right'][0] = 'new-6b7785f0-86bc-4805-b279-397cb27a4050';
  $pane = new stdClass();
  $pane->pid = 'new-6d5f56b8-6c93-4430-9152-a800a0617baa';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'statistics-panel_statistics_overview';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6d5f56b8-6c93-4430-9152-a800a0617baa';
  $display->content['new-6d5f56b8-6c93-4430-9152-a800a0617baa'] = $pane;
  $display->panels['right'][1] = 'new-6d5f56b8-6c93-4430-9152-a800a0617baa';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['statistik'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'statistik_extended';
  $page->task = 'page';
  $page->admin_title = 'Statistik - Erweitert';
  $page->admin_description = '';
  $page->path = 'statistics/extended';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 6,
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
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_statistik_extended_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'statistik_extended';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'salto_39';
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
  $display->title = 'Erweiterte Statistik';
  $display->uuid = '89af0f7d-eb0d-4eaa-ae42-c6381909493c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_statistik_extended_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-statistik';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-statistik',
    'parent_mlid' => 0,
    'title_link' => 0,
    'admin_title' => 'Statistik',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'parent' => 'menu-statistik:0',
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
  $pane->uuid = 'b68b6a00-2977-40af-a135-02a79af98e24';
  $display->content['new-b68b6a00-2977-40af-a135-02a79af98e24'] = $pane;
  $display->panels['left'][0] = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $pane = new stdClass();
  $pane->pid = 'new-fcb9c6a4-b98c-4c75-a6d4-8752bd86e126';
  $pane->panel = 'left';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Filter',
    'title' => 'Filter',
    'body' => '<? 
$form = drupal_get_form(salto_statistics_extended_sites_dateselect_form);
echo drupal_render(($form ));

?>',
    'format' => 'php_code',
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
  $pane->uuid = 'fcb9c6a4-b98c-4c75-a6d4-8752bd86e126';
  $display->content['new-fcb9c6a4-b98c-4c75-a6d4-8752bd86e126'] = $pane;
  $display->panels['left'][1] = 'new-fcb9c6a4-b98c-4c75-a6d4-8752bd86e126';
  $pane = new stdClass();
  $pane->pid = 'new-2da9a3f7-0d36-4cb2-8e91-38aa7f8b8dbc';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Export Button',
    'title' => '',
    'body' => '<?php 
$query = request_uri();
$query = substr($query, strpos($query, \'?\'));
?>
<a class="btn btn-primary action_link action_export" href="/statistics/people/export/xls<?=$query?>" style="float:right;">Statistik exportieren (XLS)</a>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2da9a3f7-0d36-4cb2-8e91-38aa7f8b8dbc';
  $display->content['new-2da9a3f7-0d36-4cb2-8e91-38aa7f8b8dbc'] = $pane;
  $display->panels['right'][0] = 'new-2da9a3f7-0d36-4cb2-8e91-38aa7f8b8dbc';
  $pane = new stdClass();
  $pane->pid = 'new-a7a52338-7e21-4468-bc8c-074e68bca30f';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'extended render sites',
    'title' => '',
    'body' => '<? 
echo salto_statistics_extended_render();
?>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a7a52338-7e21-4468-bc8c-074e68bca30f';
  $display->content['new-a7a52338-7e21-4468-bc8c-074e68bca30f'] = $pane;
  $display->panels['right'][1] = 'new-a7a52338-7e21-4468-bc8c-074e68bca30f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['statistik_extended'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'statistik_groups';
  $page->task = 'page';
  $page->admin_title = 'Statistik - Groups';
  $page->admin_description = '';
  $page->path = 'statistics/groups';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 6,
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
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_statistik_groups_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'statistik_groups';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'salto_39';
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
  $display->title = 'Statistik (Gruppen)';
  $display->uuid = '89af0f7d-eb0d-4eaa-ae42-c6381909493c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_statistik_groups_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-statistik';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-statistik',
    'parent_mlid' => 0,
    'title_link' => 0,
    'admin_title' => 'Statistik',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'parent' => 'menu-statistik:0',
    'override_title_heading' => 'h2',
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
  $pane->uuid = 'b68b6a00-2977-40af-a135-02a79af98e24';
  $display->content['new-b68b6a00-2977-40af-a135-02a79af98e24'] = $pane;
  $display->panels['left'][0] = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $pane = new stdClass();
  $pane->pid = 'new-3d3628a3-1e0f-463a-a724-5290d347939f';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-e3b417153ded9590935fa924da4394d9';
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
  $pane->uuid = '3d3628a3-1e0f-463a-a724-5290d347939f';
  $display->content['new-3d3628a3-1e0f-463a-a724-5290d347939f'] = $pane;
  $display->panels['left'][1] = 'new-3d3628a3-1e0f-463a-a724-5290d347939f';
  $pane = new stdClass();
  $pane->pid = 'new-b6ebcf2c-ead4-4a82-be0f-08b995e43c79';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Export ',
    'title' => '',
    'body' => '<?php 
$query = request_uri();
$query = substr($query, strpos($query, \'?\'));
?>
<a class="btn btn-primary action_link action_export" href="/statistics/groups/export/xls<?=$query?>" style="float:right;">Statistik exportieren (XLS)</a>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b6ebcf2c-ead4-4a82-be0f-08b995e43c79';
  $display->content['new-b6ebcf2c-ead4-4a82-be0f-08b995e43c79'] = $pane;
  $display->panels['right'][0] = 'new-b6ebcf2c-ead4-4a82-be0f-08b995e43c79';
  $pane = new stdClass();
  $pane->pid = 'new-463c0af1-527e-40f1-a664-e20562b80a9c';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'statistics_groups-panel_statistics_groups';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '463c0af1-527e-40f1-a664-e20562b80a9c';
  $display->content['new-463c0af1-527e-40f1-a664-e20562b80a9c'] = $pane;
  $display->panels['right'][1] = 'new-463c0af1-527e-40f1-a664-e20562b80a9c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['statistik_groups'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'statistik_people';
  $page->task = 'page';
  $page->admin_title = 'Statistik - People';
  $page->admin_description = '';
  $page->path = 'statistics/people';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 6,
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
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_statistik_people_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'statistik_people';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'salto_39';
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
  $display->title = 'Statistik (Personen)';
  $display->uuid = '89af0f7d-eb0d-4eaa-ae42-c6381909493c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_statistik_people_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-statistik';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-statistik',
    'parent_mlid' => 0,
    'title_link' => 0,
    'admin_title' => 'Statistik',
    'level' => '1',
    'follow' => 0,
    'depth' => '1',
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'parent' => 'menu-statistik:0',
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
  $pane->uuid = 'b68b6a00-2977-40af-a135-02a79af98e24';
  $display->content['new-b68b6a00-2977-40af-a135-02a79af98e24'] = $pane;
  $display->panels['left'][0] = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $pane = new stdClass();
  $pane->pid = 'new-ee5446cc-f563-4b46-a6c0-147f836f0fbe';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-cbda92509542943fc87113c33fd96de6';
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
  $pane->uuid = 'ee5446cc-f563-4b46-a6c0-147f836f0fbe';
  $display->content['new-ee5446cc-f563-4b46-a6c0-147f836f0fbe'] = $pane;
  $display->panels['left'][1] = 'new-ee5446cc-f563-4b46-a6c0-147f836f0fbe';
  $pane = new stdClass();
  $pane->pid = 'new-2da9a3f7-0d36-4cb2-8e91-38aa7f8b8dbc';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Export Button',
    'title' => '',
    'body' => '<?php 
$query = request_uri();
$query = substr($query, strpos($query, \'?\'));
?>
<a class="btn btn-primary action_link action_export" href="/statistics/people/export/xls<?=$query?>" style="float:right;">Statistik exportieren (XLS)</a>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2da9a3f7-0d36-4cb2-8e91-38aa7f8b8dbc';
  $display->content['new-2da9a3f7-0d36-4cb2-8e91-38aa7f8b8dbc'] = $pane;
  $display->panels['right'][0] = 'new-2da9a3f7-0d36-4cb2-8e91-38aa7f8b8dbc';
  $pane = new stdClass();
  $pane->pid = 'new-777e112d-6366-47e3-bc3a-feae939c5486';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'statistics_people-panel_statistics_people';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '777e112d-6366-47e3-bc3a-feae939c5486';
  $display->content['new-777e112d-6366-47e3-bc3a-feae939c5486'] = $pane;
  $display->panels['right'][1] = 'new-777e112d-6366-47e3-bc3a-feae939c5486';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b68b6a00-2977-40af-a135-02a79af98e24';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['statistik_people'] = $page;

  return $pages;

}
