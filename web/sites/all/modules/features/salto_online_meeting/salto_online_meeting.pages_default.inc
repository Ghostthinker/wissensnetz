<?php

/**
 * @file
 * salto_online_meeting.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function salto_online_meeting_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__online_meeting-public';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -19;
  $handler->conf = array(
    'title' => 'online_meeting: public',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'online_meeting-public',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'online_meeting' => 'online_meeting',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
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
      'license_left' => NULL,
      'license_middle' => NULL,
      'license_right' => NULL,
      'tags' => NULL,
      'meta_left' => NULL,
      'meta_right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cad882a0-4098-409b-a119-3c5c7edbaad1';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__online_meeting-public';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7a00c6c3-8af3-4e2a-8bdb-e9aa056dab1a';
  $pane->panel = 'left';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 1,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '7a00c6c3-8af3-4e2a-8bdb-e9aa056dab1a';
  $display->content['new-7a00c6c3-8af3-4e2a-8bdb-e9aa056dab1a'] = $pane;
  $display->panels['left'][0] = 'new-7a00c6c3-8af3-4e2a-8bdb-e9aa056dab1a';
  $pane = new stdClass();
  $pane->pid = 'new-4067f43c-66e0-4f7f-9c41-71ca564b165e';
  $pane->panel = 'left';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'online meeting actions',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
$node = node_load(%node:nid);
$dialogServiceController = new OnlineMeetingService($node);
print $dialogServiceController->render();
?>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'salto-online-meeting-recordings-actions',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4067f43c-66e0-4f7f-9c41-71ca564b165e';
  $display->content['new-4067f43c-66e0-4f7f-9c41-71ca564b165e'] = $pane;
  $display->panels['left'][1] = 'new-4067f43c-66e0-4f7f-9c41-71ca564b165e';
  $pane = new stdClass();
  $pane->pid = 'new-8a52fc2a-418a-4291-b60c-bb644a6c0e8f';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'online_meeting',
    'context' => array(
      0 => 'empty',
      1 => 'argument_entity_id:node_1',
      2 => 'empty',
    ),
    'override_title' => 0,
    'override_title_text' => '',
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
  $pane->uuid = '8a52fc2a-418a-4291-b60c-bb644a6c0e8f';
  $display->content['new-8a52fc2a-418a-4291-b60c-bb644a6c0e8f'] = $pane;
  $display->panels['right'][0] = 'new-8a52fc2a-418a-4291-b60c-bb644a6c0e8f';
  $pane = new stdClass();
  $pane->pid = 'new-a7855c6d-71df-4823-8527-bbb41b111447';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Meeting starten/beitreten',
    'title_heading' => 'h2',
    'body' => '<?php
$node = node_load(%node:nid);

$online_meeting = salto_online_meeting_get_wrapper($node);
print $online_meeting->renderJoinLink(TRUE);',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'dialog-status-pane',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a7855c6d-71df-4823-8527-bbb41b111447';
  $display->content['new-a7855c6d-71df-4823-8527-bbb41b111447'] = $pane;
  $display->panels['right'][1] = 'new-a7855c6d-71df-4823-8527-bbb41b111447';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-7a00c6c3-8af3-4e2a-8bdb-e9aa056dab1a';
  $handler->conf['display'] = $display;
  $export['node_view__online_meeting-public'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_caa264d7-ba02-42fa-9e42-e44cc80f4a14';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -20;
  $handler->conf = array(
    'title' => 'online_meeting',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'online_meeting' => 'online_meeting',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
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
  $display->layout = 'salto_363';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'license_left' => NULL,
      'license_middle' => NULL,
      'license_right' => NULL,
      'tags' => NULL,
      'meta_left' => NULL,
      'meta_right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cad882a0-4098-409b-a119-3c5c7edbaad1';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_caa264d7-ba02-42fa-9e42-e44cc80f4a14';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-81108691-ccf6-40c3-bb1c-fd70c2431e17';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-groups';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-groups:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-groups',
    'parent_mlid' => '0',
    'override_title' => 1,
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
  $pane->uuid = '81108691-ccf6-40c3-bb1c-fd70c2431e17';
  $display->content['new-81108691-ccf6-40c3-bb1c-fd70c2431e17'] = $pane;
  $display->panels['left'][0] = 'new-81108691-ccf6-40c3-bb1c-fd70c2431e17';
  $pane = new stdClass();
  $pane->pid = 'new-7a00c6c3-8af3-4e2a-8bdb-e9aa056dab1a';
  $pane->panel = 'middle';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 0,
    'override_title' => 0,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 1,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '7a00c6c3-8af3-4e2a-8bdb-e9aa056dab1a';
  $display->content['new-7a00c6c3-8af3-4e2a-8bdb-e9aa056dab1a'] = $pane;
  $display->panels['middle'][0] = 'new-7a00c6c3-8af3-4e2a-8bdb-e9aa056dab1a';
  $pane = new stdClass();
  $pane->pid = 'new-4067f43c-66e0-4f7f-9c41-71ca564b165e';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'online meeting actions',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
$node = node_load(%node:nid);
$dialogServiceController = new OnlineMeetingService($node);
print $dialogServiceController->render();
?>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'salto-online-meeting-recordings-actions',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4067f43c-66e0-4f7f-9c41-71ca564b165e';
  $display->content['new-4067f43c-66e0-4f7f-9c41-71ca564b165e'] = $pane;
  $display->panels['middle'][1] = 'new-4067f43c-66e0-4f7f-9c41-71ca564b165e';
  $pane = new stdClass();
  $pane->pid = 'new-19e309d4-95b2-4f95-9a93-6e1d8291e688';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_online_meeting_recordings';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'listing',
      'links' => 1,
      'use_content_language' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '19e309d4-95b2-4f95-9a93-6e1d8291e688';
  $display->content['new-19e309d4-95b2-4f95-9a93-6e1d8291e688'] = $pane;
  $display->panels['middle'][2] = 'new-19e309d4-95b2-4f95-9a93-6e1d8291e688';
  $pane = new stdClass();
  $pane->pid = 'new-8a52fc2a-418a-4291-b60c-bb644a6c0e8f';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'online_meeting',
    'context' => array(
      0 => 'empty',
      1 => 'argument_entity_id:node_1',
      2 => 'empty',
    ),
    'override_title' => 0,
    'override_title_text' => '',
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
  $pane->uuid = '8a52fc2a-418a-4291-b60c-bb644a6c0e8f';
  $display->content['new-8a52fc2a-418a-4291-b60c-bb644a6c0e8f'] = $pane;
  $display->panels['right'][0] = 'new-8a52fc2a-418a-4291-b60c-bb644a6c0e8f';
  $pane = new stdClass();
  $pane->pid = 'new-a7855c6d-71df-4823-8527-bbb41b111447';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Meeting starten/beitreten',
    'title_heading' => 'h2',
    'body' => '<?php
$node = node_load(%node:nid);

$online_meeting = salto_online_meeting_get_wrapper($node);
print $online_meeting->renderJoinLink(TRUE);
',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'dialog-status-pane',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a7855c6d-71df-4823-8527-bbb41b111447';
  $display->content['new-a7855c6d-71df-4823-8527-bbb41b111447'] = $pane;
  $display->panels['right'][1] = 'new-a7855c6d-71df-4823-8527-bbb41b111447';
  $pane = new stdClass();
  $pane->pid = 'new-b7864eb1-aebc-4edc-a545-fba1df159310';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Share Link',
    'title_heading' => 'h2',
    'body' => '<?php
$node = node_load(%node:nid);

print theme("salto_online_meeting_share_button", [ \'node\' => $node]); ',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'dialog-share-pane',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b7864eb1-aebc-4edc-a545-fba1df159310';
  $display->content['new-b7864eb1-aebc-4edc-a545-fba1df159310'] = $pane;
  $display->panels['right'][2] = 'new-b7864eb1-aebc-4edc-a545-fba1df159310';
  $pane = new stdClass();
  $pane->pid = 'new-157f97a0-4402-4698-871b-021e81a43277';
  $pane->panel = 'right';
  $pane->type = 'node_authors';
  $pane->subtype = 'node_authors';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'image_style' => 'user_30x30',
    'limit' => '5',
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '157f97a0-4402-4698-871b-021e81a43277';
  $display->content['new-157f97a0-4402-4698-871b-021e81a43277'] = $pane;
  $display->panels['right'][3] = 'new-157f97a0-4402-4698-871b-021e81a43277';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_caa264d7-ba02-42fa-9e42-e44cc80f4a14'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function salto_online_meeting_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'groups_online_meetings';
  $page->task = 'page';
  $page->admin_title = 'groups-online-meetings';
  $page->admin_description = 'Groups knowledgebase main area';
  $page->path = 'groups/%node/online-meetings/status/!state';
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
      1 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Online Meeting enabled',
          'php' => 'return salto_online_meeting_enabled();',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Knowledgebase',
    'name' => 'main-menu',
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
    'state' => array(
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
  $handler->name = 'page_groups_online_meetings__online-meeting-overview';
  $handler->task = 'page';
  $handler->subtask = 'groups_online_meetings';
  $handler->handler = 'panel_context';
  $handler->weight = -3;
  $handler->conf = array(
    'title' => 'Online Meeting Overview',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'online-meeting-overview',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => '',
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
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Übersicht';
  $display->uuid = 'e41a225e-1178-4815-b625-8c481227457c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_groups_online_meetings__online-meeting-overview';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-77cc2df4-7a91-438b-8c5c-cf9f21cc63bb';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-groups';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-groups',
    'parent_mlid' => 0,
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'parent' => 'menu-groups:0',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '77cc2df4-7a91-438b-8c5c-cf9f21cc63bb';
  $display->content['new-77cc2df4-7a91-438b-8c5c-cf9f21cc63bb'] = $pane;
  $display->panels['left'][0] = 'new-77cc2df4-7a91-438b-8c5c-cf9f21cc63bb';
  $pane = new stdClass();
  $pane->pid = 'new-3d157f64-2b21-4184-9734-324583cdc46b';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Titel',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h1>Online-Treffen</h1>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'panel-pane pane-custom pane-1 title-explicit',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3d157f64-2b21-4184-9734-324583cdc46b';
  $display->content['new-3d157f64-2b21-4184-9734-324583cdc46b'] = $pane;
  $display->panels['middle'][0] = 'new-3d157f64-2b21-4184-9734-324583cdc46b';
  $pane = new stdClass();
  $pane->pid = 'new-099b1823-c3db-438f-a7cd-a493f7b5171b';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'group_online_meetings-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'string_equal',
        'settings' => array(
          'operator' => '=',
          'value' => '',
          'case' => 0,
        ),
        'context' => 'argument_string_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'use_pager' => 0,
    'pager_id' => '0',
    'items_per_page' => '3',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '099b1823-c3db-438f-a7cd-a493f7b5171b';
  $display->content['new-099b1823-c3db-438f-a7cd-a493f7b5171b'] = $pane;
  $display->panels['middle'][1] = 'new-099b1823-c3db-438f-a7cd-a493f7b5171b';
  $pane = new stdClass();
  $pane->pid = 'new-9430afbb-15c4-4a66-b661-031f574d8010';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'group_online_meetings-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 0,
    'pager_id' => '0',
    'items_per_page' => '3',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '9430afbb-15c4-4a66-b661-031f574d8010';
  $display->content['new-9430afbb-15c4-4a66-b661-031f574d8010'] = $pane;
  $display->panels['middle'][2] = 'new-9430afbb-15c4-4a66-b661-031f574d8010';
  $pane = new stdClass();
  $pane->pid = 'new-14b3d664-3659-411a-a474-458fcb0f6e48';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'group_online_meetings-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 0,
    'pager_id' => '0',
    'items_per_page' => '3',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '14b3d664-3659-411a-a474-458fcb0f6e48';
  $display->content['new-14b3d664-3659-411a-a474-458fcb0f6e48'] = $pane;
  $display->panels['middle'][3] = 'new-14b3d664-3659-411a-a474-458fcb0f6e48';
  $pane = new stdClass();
  $pane->pid = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane->uuid = '4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $display->content['new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6'] = $pane;
  $display->panels['right'][0] = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $pane = new stdClass();
  $pane->pid = 'new-ac457ea7-a98d-4144-8d84-86d041a64dde';
  $pane->panel = 'right';
  $pane->type = 'online_meetings_active';
  $pane->subtype = 'online_meetings_active';
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
  $pane->uuid = 'ac457ea7-a98d-4144-8d84-86d041a64dde';
  $display->content['new-ac457ea7-a98d-4144-8d84-86d041a64dde'] = $pane;
  $display->panels['right'][1] = 'new-ac457ea7-a98d-4144-8d84-86d041a64dde';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-099b1823-c3db-438f-a7cd-a493f7b5171b';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_groups_online_meetings__panel_context_8a8c051c-4c86-484a-8494-62217ad3f90b';
  $handler->task = 'page';
  $handler->subtask = 'groups_online_meetings';
  $handler->handler = 'panel_context';
  $handler->weight = -2;
  $handler->conf = array(
    'title' => 'Online Meeting pending',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'pending',
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
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Anstehende';
  $display->uuid = 'e41a225e-1178-4815-b625-8c481227457c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_groups_online_meetings__panel_context_8a8c051c-4c86-484a-8494-62217ad3f90b';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-77cc2df4-7a91-438b-8c5c-cf9f21cc63bb';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-groups';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-groups',
    'parent_mlid' => 0,
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'parent' => 'menu-groups:0',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '77cc2df4-7a91-438b-8c5c-cf9f21cc63bb';
  $display->content['new-77cc2df4-7a91-438b-8c5c-cf9f21cc63bb'] = $pane;
  $display->panels['left'][0] = 'new-77cc2df4-7a91-438b-8c5c-cf9f21cc63bb';
  $pane = new stdClass();
  $pane->pid = 'new-e09975bf-f811-4db2-ae70-cade5f8473b9';
  $pane->panel = 'left';
  $pane->type = 'online_meetings_active';
  $pane->subtype = 'online_meetings_active';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e09975bf-f811-4db2-ae70-cade5f8473b9';
  $display->content['new-e09975bf-f811-4db2-ae70-cade5f8473b9'] = $pane;
  $display->panels['left'][1] = 'new-e09975bf-f811-4db2-ae70-cade5f8473b9';
  $pane = new stdClass();
  $pane->pid = 'new-5157d838-6979-4425-83be-914939510c36';
  $pane->panel = 'left';
  $pane->type = 'online_meetings_active';
  $pane->subtype = 'online_meetings_active';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5157d838-6979-4425-83be-914939510c36';
  $display->content['new-5157d838-6979-4425-83be-914939510c36'] = $pane;
  $display->panels['left'][2] = 'new-5157d838-6979-4425-83be-914939510c36';
  $pane = new stdClass();
  $pane->pid = 'new-4c8b14c4-bc36-48a7-b2b7-2f5ea89139c1';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Titel',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h1>Online-Treffen</h1>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'panel-pane pane-custom pane-1 title-explicit',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4c8b14c4-bc36-48a7-b2b7-2f5ea89139c1';
  $display->content['new-4c8b14c4-bc36-48a7-b2b7-2f5ea89139c1'] = $pane;
  $display->panels['middle'][0] = 'new-4c8b14c4-bc36-48a7-b2b7-2f5ea89139c1';
  $pane = new stdClass();
  $pane->pid = 'new-b4735e6f-e0b1-447e-9e30-8eede46c0f68';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'group_online_meetings-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '10',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b4735e6f-e0b1-447e-9e30-8eede46c0f68';
  $display->content['new-b4735e6f-e0b1-447e-9e30-8eede46c0f68'] = $pane;
  $display->panels['middle'][1] = 'new-b4735e6f-e0b1-447e-9e30-8eede46c0f68';
  $pane = new stdClass();
  $pane->pid = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane->uuid = '4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $display->content['new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6'] = $pane;
  $display->panels['right'][0] = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane = new stdClass();
  $pane->pid = 'new-bad50905-3f98-42e7-aee6-b28416081508';
  $pane->panel = 'right';
  $pane->type = 'online_meetings_active';
  $pane->subtype = 'online_meetings_active';
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
  $pane->uuid = 'bad50905-3f98-42e7-aee6-b28416081508';
  $display->content['new-bad50905-3f98-42e7-aee6-b28416081508'] = $pane;
  $display->panels['right'][2] = 'new-bad50905-3f98-42e7-aee6-b28416081508';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_groups_online_meetings__online-meeting-recurring';
  $handler->task = 'page';
  $handler->subtask = 'groups_online_meetings';
  $handler->handler = 'panel_context';
  $handler->weight = -1;
  $handler->conf = array(
    'title' => 'Online Meeting recurring',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'online-meeting-recurring',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'recurring',
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
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Wiederkehrend';
  $display->uuid = 'e41a225e-1178-4815-b625-8c481227457c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_groups_online_meetings__online-meeting-recurring';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-77cc2df4-7a91-438b-8c5c-cf9f21cc63bb';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-groups';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-groups',
    'parent_mlid' => 0,
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'parent' => 'menu-groups:0',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '77cc2df4-7a91-438b-8c5c-cf9f21cc63bb';
  $display->content['new-77cc2df4-7a91-438b-8c5c-cf9f21cc63bb'] = $pane;
  $display->panels['left'][0] = 'new-77cc2df4-7a91-438b-8c5c-cf9f21cc63bb';
  $pane = new stdClass();
  $pane->pid = 'new-621e16a1-7a88-4913-9c71-e66948b1d231';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Titel',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h1>Online-Treffen</h1>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'panel-pane pane-custom pane-1 title-explicit',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '621e16a1-7a88-4913-9c71-e66948b1d231';
  $display->content['new-621e16a1-7a88-4913-9c71-e66948b1d231'] = $pane;
  $display->panels['middle'][0] = 'new-621e16a1-7a88-4913-9c71-e66948b1d231';
  $pane = new stdClass();
  $pane->pid = 'new-7a584654-2e86-4e20-9a69-722318f6773c';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'group_online_meetings-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '10',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7a584654-2e86-4e20-9a69-722318f6773c';
  $display->content['new-7a584654-2e86-4e20-9a69-722318f6773c'] = $pane;
  $display->panels['middle'][1] = 'new-7a584654-2e86-4e20-9a69-722318f6773c';
  $pane = new stdClass();
  $pane->pid = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane->uuid = '4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $display->content['new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6'] = $pane;
  $display->panels['right'][0] = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane = new stdClass();
  $pane->pid = 'new-fd87a240-2917-40e1-afb3-e20aaa51fd08';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Active meetings',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
  drupal_add_css(drupal_get_path(\'module\', \'salto_online_meeting\') . \'/less/salto_online_meeting.less\');
  print theme(\'active_dialogs_form_theme\');
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
  $pane->uuid = 'fd87a240-2917-40e1-afb3-e20aaa51fd08';
  $display->content['new-fd87a240-2917-40e1-afb3-e20aaa51fd08'] = $pane;
  $display->panels['right'][2] = 'new-fd87a240-2917-40e1-afb3-e20aaa51fd08';
  $pane = new stdClass();
  $pane->pid = 'new-c43c41fb-bf34-4aa7-aab9-1cc9f4a8a3a0';
  $pane->panel = 'right';
  $pane->type = 'online_meetings_active';
  $pane->subtype = 'online_meetings_active';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array();
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'c43c41fb-bf34-4aa7-aab9-1cc9f4a8a3a0';
  $display->content['new-c43c41fb-bf34-4aa7-aab9-1cc9f4a8a3a0'] = $pane;
  $display->panels['right'][3] = 'new-c43c41fb-bf34-4aa7-aab9-1cc9f4a8a3a0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_groups_online_meetings__online-meeting-completed';
  $handler->task = 'page';
  $handler->subtask = 'groups_online_meetings';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Online Meeting completed',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'online-meeting-completed',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'completed',
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
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Abgeschlossen';
  $display->uuid = 'e41a225e-1178-4815-b625-8c481227457c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_groups_online_meetings__online-meeting-completed';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-77cc2df4-7a91-438b-8c5c-cf9f21cc63bb';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-groups';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-groups',
    'parent_mlid' => 0,
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
    'parent' => 'menu-groups:0',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '77cc2df4-7a91-438b-8c5c-cf9f21cc63bb';
  $display->content['new-77cc2df4-7a91-438b-8c5c-cf9f21cc63bb'] = $pane;
  $display->panels['left'][0] = 'new-77cc2df4-7a91-438b-8c5c-cf9f21cc63bb';
  $pane = new stdClass();
  $pane->pid = 'new-9797ba36-44e8-4853-a297-b8a6f3f60210';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Titel',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h1>Online-Treffen</h1>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'panel-pane pane-custom pane-1 title-explicit',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9797ba36-44e8-4853-a297-b8a6f3f60210';
  $display->content['new-9797ba36-44e8-4853-a297-b8a6f3f60210'] = $pane;
  $display->panels['middle'][0] = 'new-9797ba36-44e8-4853-a297-b8a6f3f60210';
  $pane = new stdClass();
  $pane->pid = 'new-0fcc9fb8-db37-4069-a78b-71c342cff35e';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'group_online_meetings-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '10',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0fcc9fb8-db37-4069-a78b-71c342cff35e';
  $display->content['new-0fcc9fb8-db37-4069-a78b-71c342cff35e'] = $pane;
  $display->panels['middle'][1] = 'new-0fcc9fb8-db37-4069-a78b-71c342cff35e';
  $pane = new stdClass();
  $pane->pid = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane->uuid = '4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $display->content['new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6'] = $pane;
  $display->panels['right'][0] = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane = new stdClass();
  $pane->pid = 'new-c998fc7c-73d0-4772-a01b-cca747518eac';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Active meetings',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
  drupal_add_css(drupal_get_path(\'module\', \'salto_online_meeting\') . \'/less/salto_online_meeting.less\');
  print theme(\'active_dialogs_form_theme\');
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
  $pane->uuid = 'c998fc7c-73d0-4772-a01b-cca747518eac';
  $display->content['new-c998fc7c-73d0-4772-a01b-cca747518eac'] = $pane;
  $display->panels['right'][2] = 'new-c998fc7c-73d0-4772-a01b-cca747518eac';
  $pane = new stdClass();
  $pane->pid = 'new-b9aec0db-8e82-4ea0-867f-8725f1c27765';
  $pane->panel = 'right';
  $pane->type = 'online_meetings_active';
  $pane->subtype = 'online_meetings_active';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'b9aec0db-8e82-4ea0-867f-8725f1c27765';
  $display->content['new-b9aec0db-8e82-4ea0-867f-8725f1c27765'] = $pane;
  $display->panels['right'][3] = 'new-b9aec0db-8e82-4ea0-867f-8725f1c27765';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_online_meetings'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'online_meetings';
  $page->task = 'page';
  $page->admin_title = 'online-meetings';
  $page->admin_description = 'Groups knowledgebase main area';
  $page->path = 'online-meetings/status/!state';
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
      1 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Online Meeting enabled',
          'php' => 'return salto_online_meeting_enabled() && salto_online_meeting_community_area_enabled();',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Online meetings',
    'name' => 'main-menu',
    'weight' => '-48',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'state' => array(
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
  $handler->name = 'page_online_meetings__panel_context_20e7a55a-4c2b-45d6-920c-3ab373dc748b';
  $handler->task = 'page';
  $handler->subtask = 'online_meetings';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Online Meeting Overview',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => '',
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
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Übersicht';
  $display->uuid = 'e41a225e-1178-4815-b625-8c481227457c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_online_meetings__panel_context_20e7a55a-4c2b-45d6-920c-3ab373dc748b';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e4a1db2e-eefa-4770-a13c-6234c14dc878';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-online-meetings';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-online-meetings:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-online-meetings',
    'parent_mlid' => '0',
    'override_title' => 1,
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
  $pane->uuid = 'e4a1db2e-eefa-4770-a13c-6234c14dc878';
  $display->content['new-e4a1db2e-eefa-4770-a13c-6234c14dc878'] = $pane;
  $display->panels['left'][0] = 'new-e4a1db2e-eefa-4770-a13c-6234c14dc878';
  $pane = new stdClass();
  $pane->pid = 'new-3d157f64-2b21-4184-9734-324583cdc46b';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Titel',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h1>Online-Treffen</h1>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'panel-pane pane-custom pane-1 title-explicit',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3d157f64-2b21-4184-9734-324583cdc46b';
  $display->content['new-3d157f64-2b21-4184-9734-324583cdc46b'] = $pane;
  $display->panels['middle'][0] = 'new-3d157f64-2b21-4184-9734-324583cdc46b';
  $pane = new stdClass();
  $pane->pid = 'new-533974f0-a5af-4b77-9d97-cedb95527c6d';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'online_meetings-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 0,
    'pager_id' => '0',
    'items_per_page' => '3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '533974f0-a5af-4b77-9d97-cedb95527c6d';
  $display->content['new-533974f0-a5af-4b77-9d97-cedb95527c6d'] = $pane;
  $display->panels['middle'][1] = 'new-533974f0-a5af-4b77-9d97-cedb95527c6d';
  $pane = new stdClass();
  $pane->pid = 'new-ca0a6497-fdbb-4895-9f9a-147443ef500c';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'online_meetings-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 0,
    'pager_id' => '0',
    'items_per_page' => '3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'ca0a6497-fdbb-4895-9f9a-147443ef500c';
  $display->content['new-ca0a6497-fdbb-4895-9f9a-147443ef500c'] = $pane;
  $display->panels['middle'][2] = 'new-ca0a6497-fdbb-4895-9f9a-147443ef500c';
  $pane = new stdClass();
  $pane->pid = 'new-1056429f-de26-48a8-9e21-1540f1044f6c';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'online_meetings-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 0,
    'pager_id' => '0',
    'items_per_page' => '3',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '1056429f-de26-48a8-9e21-1540f1044f6c';
  $display->content['new-1056429f-de26-48a8-9e21-1540f1044f6c'] = $pane;
  $display->panels['middle'][3] = 'new-1056429f-de26-48a8-9e21-1540f1044f6c';
  $pane = new stdClass();
  $pane->pid = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'online_meeting',
    'context' => array(
      0 => 'empty',
      1 => 'empty',
      2 => 'empty',
    ),
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
  $pane->uuid = '4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $display->content['new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6'] = $pane;
  $display->panels['right'][0] = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $pane = new stdClass();
  $pane->pid = 'new-ac457ea7-a98d-4144-8d84-86d041a64dde';
  $pane->panel = 'right';
  $pane->type = 'online_meetings_active';
  $pane->subtype = 'online_meetings_active';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ac457ea7-a98d-4144-8d84-86d041a64dde';
  $display->content['new-ac457ea7-a98d-4144-8d84-86d041a64dde'] = $pane;
  $display->panels['right'][1] = 'new-ac457ea7-a98d-4144-8d84-86d041a64dde';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_online_meetings__panel_context_a263abe5-ae9a-42a5-9bf7-2bd7de74c890';
  $handler->task = 'page';
  $handler->subtask = 'online_meetings';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Online Meeting pending',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'pending',
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
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Anstehende';
  $display->uuid = 'e41a225e-1178-4815-b625-8c481227457c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_online_meetings__panel_context_a263abe5-ae9a-42a5-9bf7-2bd7de74c890';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b5497b78-6da7-4b8a-a1d8-59e501f1c297';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-online-meetings';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-online-meetings:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-online-meetings',
    'parent_mlid' => '0',
    'override_title' => 1,
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
  $pane->uuid = 'b5497b78-6da7-4b8a-a1d8-59e501f1c297';
  $display->content['new-b5497b78-6da7-4b8a-a1d8-59e501f1c297'] = $pane;
  $display->panels['left'][0] = 'new-b5497b78-6da7-4b8a-a1d8-59e501f1c297';
  $pane = new stdClass();
  $pane->pid = 'new-4c8b14c4-bc36-48a7-b2b7-2f5ea89139c1';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Titel',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h1>Online-Treffen</h1>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'panel-pane pane-custom pane-1 title-explicit',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4c8b14c4-bc36-48a7-b2b7-2f5ea89139c1';
  $display->content['new-4c8b14c4-bc36-48a7-b2b7-2f5ea89139c1'] = $pane;
  $display->panels['middle'][0] = 'new-4c8b14c4-bc36-48a7-b2b7-2f5ea89139c1';
  $pane = new stdClass();
  $pane->pid = 'new-59c19fe3-4ded-4005-978c-cce4f722a0c4';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'online_meetings-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 0,
    'pager_id' => '0',
    'items_per_page' => '10',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '59c19fe3-4ded-4005-978c-cce4f722a0c4';
  $display->content['new-59c19fe3-4ded-4005-978c-cce4f722a0c4'] = $pane;
  $display->panels['middle'][1] = 'new-59c19fe3-4ded-4005-978c-cce4f722a0c4';
  $pane = new stdClass();
  $pane->pid = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane->uuid = '4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $display->content['new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6'] = $pane;
  $display->panels['right'][0] = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane = new stdClass();
  $pane->pid = 'new-bad50905-3f98-42e7-aee6-b28416081508';
  $pane->panel = 'right';
  $pane->type = 'online_meetings_active';
  $pane->subtype = 'online_meetings_active';
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
  $pane->uuid = 'bad50905-3f98-42e7-aee6-b28416081508';
  $display->content['new-bad50905-3f98-42e7-aee6-b28416081508'] = $pane;
  $display->panels['right'][2] = 'new-bad50905-3f98-42e7-aee6-b28416081508';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_online_meetings__panel_context_af43a2ef-192e-4e58-8d6c-4ce438f974fd';
  $handler->task = 'page';
  $handler->subtask = 'online_meetings';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Online Meeting recurring',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'recurring',
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
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Wiederkehrend';
  $display->uuid = 'e41a225e-1178-4815-b625-8c481227457c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_online_meetings__panel_context_af43a2ef-192e-4e58-8d6c-4ce438f974fd';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-64eb453d-81f0-4993-b4ff-139db50e68c6';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-online-meetings';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-online-meetings:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-online-meetings',
    'parent_mlid' => '0',
    'override_title' => 1,
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
  $pane->uuid = '64eb453d-81f0-4993-b4ff-139db50e68c6';
  $display->content['new-64eb453d-81f0-4993-b4ff-139db50e68c6'] = $pane;
  $display->panels['left'][0] = 'new-64eb453d-81f0-4993-b4ff-139db50e68c6';
  $pane = new stdClass();
  $pane->pid = 'new-621e16a1-7a88-4913-9c71-e66948b1d231';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Titel',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h1>Online-Treffen</h1>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'panel-pane pane-custom pane-1 title-explicit',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '621e16a1-7a88-4913-9c71-e66948b1d231';
  $display->content['new-621e16a1-7a88-4913-9c71-e66948b1d231'] = $pane;
  $display->panels['middle'][0] = 'new-621e16a1-7a88-4913-9c71-e66948b1d231';
  $pane = new stdClass();
  $pane->pid = 'new-09a55179-a997-415e-ac7e-5cb9da8344ad';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'online_meetings-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '10',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '09a55179-a997-415e-ac7e-5cb9da8344ad';
  $display->content['new-09a55179-a997-415e-ac7e-5cb9da8344ad'] = $pane;
  $display->panels['middle'][1] = 'new-09a55179-a997-415e-ac7e-5cb9da8344ad';
  $pane = new stdClass();
  $pane->pid = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane->uuid = '4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $display->content['new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6'] = $pane;
  $display->panels['right'][0] = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane = new stdClass();
  $pane->pid = 'new-fd87a240-2917-40e1-afb3-e20aaa51fd08';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Active meetings',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
  drupal_add_css(drupal_get_path(\'module\', \'salto_online_meeting\') . \'/less/salto_online_meeting.less\');
  print theme(\'active_dialogs_form_theme\');
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
  $pane->uuid = 'fd87a240-2917-40e1-afb3-e20aaa51fd08';
  $display->content['new-fd87a240-2917-40e1-afb3-e20aaa51fd08'] = $pane;
  $display->panels['right'][2] = 'new-fd87a240-2917-40e1-afb3-e20aaa51fd08';
  $pane = new stdClass();
  $pane->pid = 'new-c43c41fb-bf34-4aa7-aab9-1cc9f4a8a3a0';
  $pane->panel = 'right';
  $pane->type = 'online_meetings_active';
  $pane->subtype = 'online_meetings_active';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'c43c41fb-bf34-4aa7-aab9-1cc9f4a8a3a0';
  $display->content['new-c43c41fb-bf34-4aa7-aab9-1cc9f4a8a3a0'] = $pane;
  $display->panels['right'][3] = 'new-c43c41fb-bf34-4aa7-aab9-1cc9f4a8a3a0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_online_meetings__panel_context_9466745f-f48d-4db5-9fd5-92b5a863346e';
  $handler->task = 'page';
  $handler->subtask = 'online_meetings';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Online Meeting completed',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'completed',
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
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Abgeschlossen';
  $display->uuid = 'e41a225e-1178-4815-b625-8c481227457c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_online_meetings__panel_context_9466745f-f48d-4db5-9fd5-92b5a863346e';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-479cb128-27de-47f5-96e0-db13310ed14c';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-online-meetings';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-online-meetings:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-online-meetings',
    'parent_mlid' => '0',
    'override_title' => 1,
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
  $pane->uuid = '479cb128-27de-47f5-96e0-db13310ed14c';
  $display->content['new-479cb128-27de-47f5-96e0-db13310ed14c'] = $pane;
  $display->panels['left'][0] = 'new-479cb128-27de-47f5-96e0-db13310ed14c';
  $pane = new stdClass();
  $pane->pid = 'new-9797ba36-44e8-4853-a297-b8a6f3f60210';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Titel',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h1>Online-Treffen</h1>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'panel-pane pane-custom pane-1 title-explicit',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9797ba36-44e8-4853-a297-b8a6f3f60210';
  $display->content['new-9797ba36-44e8-4853-a297-b8a6f3f60210'] = $pane;
  $display->panels['middle'][0] = 'new-9797ba36-44e8-4853-a297-b8a6f3f60210';
  $pane = new stdClass();
  $pane->pid = 'new-36fb84ee-a813-4eb0-8038-abf54352f7e3';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'online_meetings-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_pager' => 1,
    'pager_id' => '0',
    'items_per_page' => '10',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '36fb84ee-a813-4eb0-8038-abf54352f7e3';
  $display->content['new-36fb84ee-a813-4eb0-8038-abf54352f7e3'] = $pane;
  $display->panels['middle'][1] = 'new-36fb84ee-a813-4eb0-8038-abf54352f7e3';
  $pane = new stdClass();
  $pane->pid = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane->uuid = '4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $display->content['new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6'] = $pane;
  $display->panels['right'][0] = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
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
  $pane = new stdClass();
  $pane->pid = 'new-c998fc7c-73d0-4772-a01b-cca747518eac';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Active meetings',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
  drupal_add_css(drupal_get_path(\'module\', \'salto_online_meeting\') . \'/less/salto_online_meeting.less\');
  print theme(\'active_dialogs_form_theme\');
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
  $pane->uuid = 'c998fc7c-73d0-4772-a01b-cca747518eac';
  $display->content['new-c998fc7c-73d0-4772-a01b-cca747518eac'] = $pane;
  $display->panels['right'][2] = 'new-c998fc7c-73d0-4772-a01b-cca747518eac';
  $pane = new stdClass();
  $pane->pid = 'new-b9aec0db-8e82-4ea0-867f-8725f1c27765';
  $pane->panel = 'right';
  $pane->type = 'online_meetings_active';
  $pane->subtype = 'online_meetings_active';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'b9aec0db-8e82-4ea0-867f-8725f1c27765';
  $display->content['new-b9aec0db-8e82-4ea0-867f-8725f1c27765'] = $pane;
  $display->panels['right'][3] = 'new-b9aec0db-8e82-4ea0-867f-8725f1c27765';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['online_meetings'] = $page;

  return $pages;

}
