<?php

/**
 * @file
 * salto_core.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function salto_core_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Help',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'help' => 'help',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
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
  $display->title = '';
  $display->uuid = '9bc7d8bf-ec2f-4a82-b198-6dac106daeca';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1fd6e720-19c2-4a55-8e14-7b507a7171ea';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'help-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1fd6e720-19c2-4a55-8e14-7b507a7171ea';
  $display->content['new-1fd6e720-19c2-4a55-8e14-7b507a7171ea'] = $pane;
  $display->panels['left'][0] = 'new-1fd6e720-19c2-4a55-8e14-7b507a7171ea';
  $pane = new stdClass();
  $pane->pid = 'new-c63b44ac-f551-4760-bc5d-b1b3352d4427';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c63b44ac-f551-4760-bc5d-b1b3352d4427';
  $display->content['new-c63b44ac-f551-4760-bc5d-b1b3352d4427'] = $pane;
  $display->panels['middle'][0] = 'new-c63b44ac-f551-4760-bc5d-b1b3352d4427';
  $pane = new stdClass();
  $pane->pid = 'new-2dc8aa73-8c88-4cdc-99df-f2bc7d9682b1';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'help',
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
  $pane->uuid = '2dc8aa73-8c88-4cdc-99df-f2bc7d9682b1';
  $display->content['new-2dc8aa73-8c88-4cdc-99df-f2bc7d9682b1'] = $pane;
  $display->panels['right'][0] = 'new-2dc8aa73-8c88-4cdc-99df-f2bc7d9682b1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
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
  $display->layout = 'salto_372';
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
  $display->title = '';
  $display->uuid = 'a5ce3b39-cec1-4cf8-bdb2-d3519d6e3126';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-201a3273-ff84-4565-a0ed-f08e59720db6';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'term_content-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '201a3273-ff84-4565-a0ed-f08e59720db6';
  $display->content['new-201a3273-ff84-4565-a0ed-f08e59720db6'] = $pane;
  $display->panels['middle'][0] = 'new-201a3273-ff84-4565-a0ed-f08e59720db6';
  $pane = new stdClass();
  $pane->pid = 'new-ee8832b0-c5a4-4c2e-aced-dc0f70961400';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'term_files-panel_pane_1';
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
  $pane->uuid = 'ee8832b0-c5a4-4c2e-aced-dc0f70961400';
  $display->content['new-ee8832b0-c5a4-4c2e-aced-dc0f70961400'] = $pane;
  $display->panels['middle'][1] = 'new-ee8832b0-c5a4-4c2e-aced-dc0f70961400';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function salto_core_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'errors';
  $page->task = 'page';
  $page->admin_title = 'errors';
  $page->admin_description = '404 and 403';
  $page->path = 'error/%code';
  $page->access = array(
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'code' => array(
      'id' => 1,
      'identifier' => 'Zeichenkette',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
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
  $handler->name = 'page_errors_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'errors';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => '404',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => '404',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'salto_93';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '01a56a60-6a5e-4c6e-996a-a5179f1fe421';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_errors_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-81bcbe62-da9d-4dbe-92a4-31cf37247cbe';
  $pane->panel = 'left';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Leider ist der Inhalt nicht verfügbar',
    'body' => '<p>Es tut uns leid - der Inhalt den Sie versucht haben aufzurufen ist leider auf dem Bildungsnetz nicht verfügbar. Am besten Sie überprüfen noch einmal die Adresse oder folgen den direkten Links in der Umgebung. Falls das Problem weiterhin bestehen sollte, können Sie sich natürlich gerne direkt mit unserem Support Verbindung setzen.</p>',
    'format' => 'editor',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '81bcbe62-da9d-4dbe-92a4-31cf37247cbe';
  $display->content['new-81bcbe62-da9d-4dbe-92a4-31cf37247cbe'] = $pane;
  $display->panels['left'][0] = 'new-81bcbe62-da9d-4dbe-92a4-31cf37247cbe';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_errors_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'errors';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => '403',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => '403',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '01a56a60-6a5e-4c6e-996a-a5179f1fe421';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_errors_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-81bcbe62-da9d-4dbe-92a4-31cf37247cbe';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Bitte loggen Sie sich ein, um diesen Inhalt zu sehen',
    'body' => '<p>Es tut uns leid - Sie verfügen offensichtlich nicht über die Berechtigung, den von Ihnen aufgerufenen Inhalt einzusehen oder Ihre Anmeldung ist abgelaufen.</p><p>Aus Sicherheitsgründen ist eine gültige Anmeldung im Wissensnetz zeitlich begrenzt. Um den Inhalt einzusehen, müssen Sie sich im Wissensnetz erneut anmelden.</p>',
    'format' => 'editor',
    'substitute' => 1,
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '81bcbe62-da9d-4dbe-92a4-31cf37247cbe';
  $display->content['new-81bcbe62-da9d-4dbe-92a4-31cf37247cbe'] = $pane;
  $display->panels['middle'][0] = 'new-81bcbe62-da9d-4dbe-92a4-31cf37247cbe';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['errors'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'Home';
  $page->admin_description = 'The frontpage of the site. Both authenticated and anonymous users have variants';
  $page->path = 'home';
  $page->access = array(
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Home',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
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
    'access' => array(
      'logic' => 'and',
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
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:seven_five';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6da3ce99-dd9f-43d6-908b-486fd94160e0';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ca89e030-8457-44d5-b83d-d0c0780d53ba';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'home_tabs-panel_pane_1';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ca89e030-8457-44d5-b83d-d0c0780d53ba';
  $display->content['new-ca89e030-8457-44d5-b83d-d0c0780d53ba'] = $pane;
  $display->panels['center'][0] = 'new-ca89e030-8457-44d5-b83d-d0c0780d53ba';
  $pane = new stdClass();
  $pane->pid = 'new-af37a9e3-385d-4a62-a78f-70446fed3735';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'heartbeat-siteactivity';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'af37a9e3-385d-4a62-a78f-70446fed3735';
  $display->content['new-af37a9e3-385d-4a62-a78f-70446fed3735'] = $pane;
  $display->panels['center'][1] = 'new-af37a9e3-385d-4a62-a78f-70446fed3735';
  $pane = new stdClass();
  $pane->pid = 'new-c1ad42f4-6544-4283-bc3f-a43e9d3923c6';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Search',
    'title' => '',
    'body' => '<?php
  echo salto_search_render_search_form();
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c1ad42f4-6544-4283-bc3f-a43e9d3923c6';
  $display->content['new-c1ad42f4-6544-4283-bc3f-a43e9d3923c6'] = $pane;
  $display->panels['right'][0] = 'new-c1ad42f4-6544-4283-bc3f-a43e9d3923c6';
  $pane = new stdClass();
  $pane->pid = 'new-68c96aa1-5a02-456b-9b1e-8a9136ee137e';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Sidebar Actionlincs',
    'title' => '',
    'body' => '<?php
print salto_organisation_render_home_sidebar_action_links();
?>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'dynamic_actions',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '68c96aa1-5a02-456b-9b1e-8a9136ee137e';
  $display->content['new-68c96aa1-5a02-456b-9b1e-8a9136ee137e'] = $pane;
  $display->panels['right'][1] = 'new-68c96aa1-5a02-456b-9b1e-8a9136ee137e';
  $pane = new stdClass();
  $pane->pid = 'new-04e3a1b4-a9a6-4f38-81a4-bb316f1dca78';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'user check quick guide',
          'php' => 'return salto_help_show_quick_guide_panel();',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Module wn_blanko is disabled',
          'php' => 'if (!module_exists(\'wn_blanko\')) {
  return TRUE;
}

return FALSE;',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Quick in WN',
    'title' => 'Schnelleinstieg',
    'title_heading' => 'h2',
    'body' => '<div class="content">
<?php
print views_embed_view(\'quick_guide\', \'panel_pane_1\');
 drupal_add_js(drupal_get_path(\'module\', \'salto_help\') . "/js/salto_help.quick_guide.js");
?>
<div class="furthermore">
<a href="/context_help/nojs/screencast" title="Videos Schnelleinstieg" rel="home" class="quick-guide-panel">Alle weiteren Videos für Ihren Schnelleinstieg</a>
<div class="show-not-more">Nicht mehr anzeigen</div>
</div>
</div>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => 'quick-guide',
    'css_class' => 'quick-guide',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '04e3a1b4-a9a6-4f38-81a4-bb316f1dca78';
  $display->content['new-04e3a1b4-a9a6-4f38-81a4-bb316f1dca78'] = $pane;
  $display->panels['right'][2] = 'new-04e3a1b4-a9a6-4f38-81a4-bb316f1dca78';
  $pane = new stdClass();
  $pane->pid = 'new-4ba38fd9-0fd6-45e6-9fc0-20d9a370594a';
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
    'css_id' => 'tag_home',
    'css_class' => 'pane_w340',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '4ba38fd9-0fd6-45e6-9fc0-20d9a370594a';
  $display->content['new-4ba38fd9-0fd6-45e6-9fc0-20d9a370594a'] = $pane;
  $display->panels['right'][3] = 'new-4ba38fd9-0fd6-45e6-9fc0-20d9a370594a';
  $pane = new stdClass();
  $pane->pid = 'new-a98d7d19-bf7f-4662-8b33-30d83eaab9e7';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Module wn_blanko is disabled',
          'php' => 'if (!module_exists(\'wn_blanko\')) {
  return TRUE;
}

return FALSE;',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Neuestes Video',
    'body' => '<iframe  width="332" height="198" src="https://www.youtube.com/embed/wdafH9tX37M" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen wmode="Opaque"></iframe>',
    'format' => 'php_code',
    'substitute' => TRUE,
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'home_latest_video',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'a98d7d19-bf7f-4662-8b33-30d83eaab9e7';
  $display->content['new-a98d7d19-bf7f-4662-8b33-30d83eaab9e7'] = $pane;
  $display->panels['right'][4] = 'new-a98d7d19-bf7f-4662-8b33-30d83eaab9e7';
  $pane = new stdClass();
  $pane->pid = 'new-0d4251c2-e068-4208-b82b-8843160ec950';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Module wn_blanko is disabled',
          'php' => 'if (!module_exists(\'wn_blanko\')) {
  return TRUE;
}

return FALSE;',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Literaturdatenbank des IAT',
    'title' => 'Literaturdatenbank des IAT',
    'title_heading' => 'h2',
    'body' => '<a href="https://www.iat.uni-leipzig.de/datenbanken/iks/dosb-bn/" target="_blank"><img src="/sites/default/files/sponet_w340.jpg" style="margin-top: -14px; width: 340px;"></a>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'bip_side_box',
  );
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '0d4251c2-e068-4208-b82b-8843160ec950';
  $display->content['new-0d4251c2-e068-4208-b82b-8843160ec950'] = $pane;
  $display->panels['right'][5] = 'new-0d4251c2-e068-4208-b82b-8843160ec950';
  $pane = new stdClass();
  $pane->pid = 'new-a5c18cd4-4d44-40c6-b55e-943e91ffe975';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Module wn_blanko is disabled',
          'php' => 'if (!module_exists(\'wn_blanko\')) {
  return TRUE;
}

return FALSE;',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'PHP embed view',
    'title' => 'Aktuelles aus Trainer-im-Leistungssport.de',
    'title_heading' => 'h2',
    'body' => '<a href="/" title="Trainer-im-Leistungssport.de" rel="home" id="logo"><img class="tils" src="https://www.trainer-im-leistungssport.de/sites/all/themes/trainer_im_leistungssport/logo.png" alt="Trainer-im-Leistungssport.de"></a>
<?php
print views_embed_view(\'feed_items\', \'panel_pane_1\', 27269);
?>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => 'block-tils',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'a5c18cd4-4d44-40c6-b55e-943e91ffe975';
  $display->content['new-a5c18cd4-4d44-40c6-b55e-943e91ffe975'] = $pane;
  $display->panels['right'][6] = 'new-a5c18cd4-4d44-40c6-b55e-943e91ffe975';
  $pane = new stdClass();
  $pane->pid = 'new-11d21608-811f-4069-b898-f29d03b9a44b';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'latest_articles';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'home_latest_articles, bip_side_box',
  );
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '11d21608-811f-4069-b898-f29d03b9a44b';
  $display->content['new-11d21608-811f-4069-b898-f29d03b9a44b'] = $pane;
  $display->panels['right'][7] = 'new-11d21608-811f-4069-b898-f29d03b9a44b';
  $pane = new stdClass();
  $pane->pid = 'new-212762c9-e13b-4e7c-8d15-8805afcf24f3';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 4,
            2 => 6,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Wissensnetz-Team',
    'body' => '<p><a href="/statistics">Statistiken</a></p><p><a href="/newsletter/export">E-Mail-Verteiler</a></p>',
    'format' => 'editor',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'bip_side_box',
  );
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '212762c9-e13b-4e7c-8d15-8805afcf24f3';
  $display->content['new-212762c9-e13b-4e7c-8d15-8805afcf24f3'] = $pane;
  $display->panels['right'][8] = 'new-212762c9-e13b-4e7c-8d15-8805afcf24f3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_panel_context_4';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'guest',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible:seven_five';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd57bdabd-543c-4387-b600-c102556c1a83';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_home_panel_context_4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4925e332-87b7-4fc6-b7eb-4b9c2f35be4e';
  $pane->panel = 'center';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '<none>',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'mobile-login-form',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4925e332-87b7-4fc6-b7eb-4b9c2f35be4e';
  $display->content['new-4925e332-87b7-4fc6-b7eb-4b9c2f35be4e'] = $pane;
  $display->panels['center'][0] = 'new-4925e332-87b7-4fc6-b7eb-4b9c2f35be4e';
  $pane = new stdClass();
  $pane->pid = 'new-4d348e8c-5d90-41a6-94bd-28afffc6c3d2';
  $pane->panel = 'center';
  $pane->type = 'views_panes';
  $pane->subtype = 'home_tabs-panel_pane_1';
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
  $pane->uuid = '4d348e8c-5d90-41a6-94bd-28afffc6c3d2';
  $display->content['new-4d348e8c-5d90-41a6-94bd-28afffc6c3d2'] = $pane;
  $display->panels['center'][1] = 'new-4d348e8c-5d90-41a6-94bd-28afffc6c3d2';
  $pane = new stdClass();
  $pane->pid = 'new-7e125af9-7048-4037-b60b-2ffeb97d39e3';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Top Bild/Slider',
    'title' => '',
    'body' => '<img src="/sites/all/files/home_guest_image_140612-15-37_h236.jpg">',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '7e125af9-7048-4037-b60b-2ffeb97d39e3';
  $display->content['new-7e125af9-7048-4037-b60b-2ffeb97d39e3'] = $pane;
  $display->panels['center'][2] = 'new-7e125af9-7048-4037-b60b-2ffeb97d39e3';
  $pane = new stdClass();
  $pane->pid = 'new-2d9af1c4-0ebb-4e94-9cdd-66249b6a028b';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<table border="0" cellpadding="1" cellspacing="1"  width="100%"><tbody><tr><td style="padding-right: 25px;" width="50% vertical-align:top;"><h4>Was ist Bildungsnetz?</h4></td><td><h4>Wie erhalte ich ein Benutzerkonto</h4></td></tr><tr><td style="padding-right:25px;" width="50% vertical-align:top;""><p>&nbsp;</p><p><span style="font-size: 12px; line-height: 20.671998977661133px;">Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum&nbsp;</span></p></td><td><p>&nbsp;</p><p><span style="font-size: 12px; line-height: 20.671998977661133px;">nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum&nbsp;</span><span style="font-size: 12px; line-height: 20.671998977661133px;">nonumy eirmod tempor invidunt..</span></p></td></tr></tbody></table><p>&nbsp;</p>',
    'format' => 'editor',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '2d9af1c4-0ebb-4e94-9cdd-66249b6a028b';
  $display->content['new-2d9af1c4-0ebb-4e94-9cdd-66249b6a028b'] = $pane;
  $display->panels['center'][3] = 'new-2d9af1c4-0ebb-4e94-9cdd-66249b6a028b';
  $pane = new stdClass();
  $pane->pid = 'new-81be6c49-2854-405f-8a59-e0c320a79dec';
  $pane->panel = 'center';
  $pane->type = 'node';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'nid' => '1783',
    'links' => 0,
    'leave_node_title' => 0,
    'identifier' => '',
    'build_mode' => 'full',
    'link_node_title' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '81be6c49-2854-405f-8a59-e0c320a79dec';
  $display->content['new-81be6c49-2854-405f-8a59-e0c320a79dec'] = $pane;
  $display->panels['center'][4] = 'new-81be6c49-2854-405f-8a59-e0c320a79dec';
  $pane = new stdClass();
  $pane->pid = 'new-3d7b8c67-3090-4d4a-96b9-09306da7f3f0';
  $pane->panel = 'center';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Module wn_blanko is disabled',
          'php' => '
if (!module_exists(\'wn_blanko\')) {
  return TRUE;
}


return FALSE;',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Ihre direkte Ansprechpartnerin',
    'title' => '<none>',
    'title_heading' => 'h2',
    'body' => '<p>Ihre direkte Ansprechpartnerin:<br>Sabrina Hommel<br>Referentin Bildung<br><a href="mailto:hommel@dosb.de" target="_blank">hommel@dosb.de</a><br>+49 69 6700-279</p>',
    'format' => 'editor',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '3d7b8c67-3090-4d4a-96b9-09306da7f3f0';
  $display->content['new-3d7b8c67-3090-4d4a-96b9-09306da7f3f0'] = $pane;
  $display->panels['center'][5] = 'new-3d7b8c67-3090-4d4a-96b9-09306da7f3f0';
  $pane = new stdClass();
  $pane->pid = 'new-634af4e8-7635-4cfc-9547-ba89fdf4a923';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => 'desktop-login-form',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '634af4e8-7635-4cfc-9547-ba89fdf4a923';
  $display->content['new-634af4e8-7635-4cfc-9547-ba89fdf4a923'] = $pane;
  $display->panels['right'][0] = 'new-634af4e8-7635-4cfc-9547-ba89fdf4a923';
  $pane = new stdClass();
  $pane->pid = 'new-b795cc3f-c186-4b7a-be93-12ee94483e1b';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Module wn_blanko is disabled',
          'php' => 'if (!module_exists(\'wn_blanko\')) {
  return TRUE;
}


return FALSE;
',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => 'Neuestes Video',
    'title' => '',
    'body' => '<a href="/schnellstart-lims-anbindung">Anleitung zur Schnittstellenprogrammierung für das <br/>DOSB-Lizenzmanagementsystem<a><br/><br/>

<iframe  width="332" height="198" src="https://www.youtube.com/embed/wdafH9tX37M" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen wmode="Opaque"></iframe>',
    'format' => 'php_code',
    'substitute' => TRUE,
    'title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b795cc3f-c186-4b7a-be93-12ee94483e1b';
  $display->content['new-b795cc3f-c186-4b7a-be93-12ee94483e1b'] = $pane;
  $display->panels['right'][1] = 'new-b795cc3f-c186-4b7a-be93-12ee94483e1b';
  $pane = new stdClass();
  $pane->pid = 'new-30113965-038e-4359-8b52-f77bb78a68cc';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Neuestes Video',
    'title' => '',
    'body' => '<br><br><br><iframe style="z-index: 0" width="332" height="198" src="//www.youtube.com/embed/BQF-oShURxU?rel=0&wmode=transparent" frameborder="0" allowfullscreen wmode="Opaque"></iframe>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '30113965-038e-4359-8b52-f77bb78a68cc';
  $display->content['new-30113965-038e-4359-8b52-f77bb78a68cc'] = $pane;
  $display->panels['right'][2] = 'new-30113965-038e-4359-8b52-f77bb78a68cc';
  $pane = new stdClass();
  $pane->pid = 'new-8df5404b-1b5c-4760-a6ac-37b6632b2693';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'latest_articles';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '8df5404b-1b5c-4760-a6ac-37b6632b2693';
  $display->content['new-8df5404b-1b5c-4760-a6ac-37b6632b2693'] = $pane;
  $display->panels['right'][3] = 'new-8df5404b-1b5c-4760-a6ac-37b6632b2693';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
