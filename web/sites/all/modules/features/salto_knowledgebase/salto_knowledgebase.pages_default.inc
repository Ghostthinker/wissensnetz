<?php

/**
 * @file
 * salto_knowledgebase.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function salto_knowledgebase_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'KB: intern',
    'no_blocks' => 1,
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
              'post' => 'post',
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
  $display->uuid = '67c904f5-843f-4d39-9669-cadd4be7fc5d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d264bbef-d300-4568-b51f-b78d9ff0dcf4';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-knowledgebase';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-knowledgebase',
    'parent_mlid' => 0,
    'parent' => 'menu-knowledgebase:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
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
  $pane->uuid = 'd264bbef-d300-4568-b51f-b78d9ff0dcf4';
  $display->content['new-d264bbef-d300-4568-b51f-b78d9ff0dcf4'] = $pane;
  $display->panels['left'][0] = 'new-d264bbef-d300-4568-b51f-b78d9ff0dcf4';
  $pane = new stdClass();
  $pane->pid = 'new-bed47fb4-4c54-45a9-b603-b5dbe1481a0f';
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
  $pane->uuid = 'bed47fb4-4c54-45a9-b603-b5dbe1481a0f';
  $display->content['new-bed47fb4-4c54-45a9-b603-b5dbe1481a0f'] = $pane;
  $display->panels['middle'][0] = 'new-bed47fb4-4c54-45a9-b603-b5dbe1481a0f';
  $pane = new stdClass();
  $pane->pid = 'new-be2b8b31-aac8-420a-bac3-a66e127660a4';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Attachments',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
$node = node_load(%node:nid);
return salto_knowledgebase_render_salto_363_panel_attachment($node);

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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'be2b8b31-aac8-420a-bac3-a66e127660a4';
  $display->content['new-be2b8b31-aac8-420a-bac3-a66e127660a4'] = $pane;
  $display->panels['middle'][1] = 'new-be2b8b31-aac8-420a-bac3-a66e127660a4';
  $pane = new stdClass();
  $pane->pid = 'new-34002b6a-fef6-473a-a6cc-266597f08f86';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'empty',
      1 => 'argument_entity_id:node_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'type' => 'posts',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '34002b6a-fef6-473a-a6cc-266597f08f86';
  $display->content['new-34002b6a-fef6-473a-a6cc-266597f08f86'] = $pane;
  $display->panels['right'][0] = 'new-34002b6a-fef6-473a-a6cc-266597f08f86';
  $pane = new stdClass();
  $pane->pid = 'new-7068df83-0b8e-4b2b-9412-d8efcf8585f2';
  $pane->panel = 'right';
  $pane->type = 'node_attachments';
  $pane->subtype = 'node_attachments';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Anhänge',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '7068df83-0b8e-4b2b-9412-d8efcf8585f2';
  $display->content['new-7068df83-0b8e-4b2b-9412-d8efcf8585f2'] = $pane;
  $display->panels['right'][1] = 'new-7068df83-0b8e-4b2b-9412-d8efcf8585f2';
  $pane = new stdClass();
  $pane->pid = 'new-e7ffffc2-637e-4a28-afbc-5fce29465423';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'tmp_files_by_node-panel_file_with_ref';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'id' => '%node:nid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e7ffffc2-637e-4a28-afbc-5fce29465423';
  $display->content['new-e7ffffc2-637e-4a28-afbc-5fce29465423'] = $pane;
  $display->panels['right'][2] = 'new-e7ffffc2-637e-4a28-afbc-5fce29465423';
  $pane = new stdClass();
  $pane->pid = 'new-cc0c1841-a328-4986-8716-89de5d997988';
  $pane->panel = 'right';
  $pane->type = 'node_authors';
  $pane->subtype = 'node_authors';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'image_style' => 'user_30x30',
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'limit' => '5',
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
  $pane->uuid = 'cc0c1841-a328-4986-8716-89de5d997988';
  $display->content['new-cc0c1841-a328-4986-8716-89de5d997988'] = $pane;
  $display->panels['right'][3] = 'new-cc0c1841-a328-4986-8716-89de5d997988';
  $pane = new stdClass();
  $pane->pid = 'new-a25c953e-51a3-4427-8b7a-3036fd84e178';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_references';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Verweise',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'a25c953e-51a3-4427-8b7a-3036fd84e178';
  $display->content['new-a25c953e-51a3-4427-8b7a-3036fd84e178'] = $pane;
  $display->panels['right'][4] = 'new-a25c953e-51a3-4427-8b7a-3036fd84e178';
  $pane = new stdClass();
  $pane->pid = 'new-246cbee8-a5b6-43ef-b443-4295ff3cd324';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'knowledgebase_references-compact';
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
    'style' => 'blockpanel',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '246cbee8-a5b6-43ef-b443-4295ff3cd324';
  $display->content['new-246cbee8-a5b6-43ef-b443-4295ff3cd324'] = $pane;
  $display->panels['right'][5] = 'new-246cbee8-a5b6-43ef-b443-4295ff3cd324';
  $pane = new stdClass();
  $pane->pid = 'new-f171af61-1b91-41ed-a669-9636219b5014';
  $pane->panel = 'right';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:flag_notification_subscribe_node';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'auto_subscribe_enabled',
        'settings' => array(
          'entity_type' => 'post',
          'flag_type' => 'manual',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'subscriptions_view',
  );
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'f171af61-1b91-41ed-a669-9636219b5014';
  $display->content['new-f171af61-1b91-41ed-a669-9636219b5014'] = $pane;
  $display->panels['right'][6] = 'new-f171af61-1b91-41ed-a669-9636219b5014';
  $pane = new stdClass();
  $pane->pid = 'new-fe5acf03-876d-4ddb-94e6-d4e04871caa1';
  $pane->panel = 'right';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:flag_notification_ignore_post';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'auto_subscribe_enabled',
        'settings' => array(
          'entity_type' => 'post',
          'flag_type' => 'auto',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
    'css_class' => 'subscriptions_view',
  );
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'fe5acf03-876d-4ddb-94e6-d4e04871caa1';
  $display->content['new-fe5acf03-876d-4ddb-94e6-d4e04871caa1'] = $pane;
  $display->panels['right'][7] = 'new-fe5acf03-876d-4ddb-94e6-d4e04871caa1';
  $pane = new stdClass();
  $pane->pid = 'new-8f8fe7fa-337c-43a7-8f44-5878bdaa450e';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'salto_share_post_action',
    'title' => '',
    'body' => '<a href="/node/add/shared-post?field_sharedpost_reference=%node:nid" title="<?php print t("You can share this post to one of your groups"); ?>" class="share share-action salto_knowledgebase-processed share-processed" rel="nofollow"><?php print t("Share"); ?></a>',
    'format' => 'php_code',
    'substitute' => 1,
    'name' => 'salto_share_post_action',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-node-share-post',
  );
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '8f8fe7fa-337c-43a7-8f44-5878bdaa450e';
  $display->content['new-8f8fe7fa-337c-43a7-8f44-5878bdaa450e'] = $pane;
  $display->panels['right'][8] = 'new-8f8fe7fa-337c-43a7-8f44-5878bdaa450e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bed47fb4-4c54-45a9-b603-b5dbe1481a0f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'KB: public',
    'no_blocks' => 1,
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
              'post' => 'post',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
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
  $display->uuid = '67c904f5-843f-4d39-9669-cadd4be7fc5d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e655444e-9fdc-42f4-b932-9f249172535a';
  $pane->panel = 'left';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'salto_knowledgebase_book_menus_render',
    'title' => '',
    'body' => '',
    'format' => 'php_code',
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
  $pane->uuid = 'e655444e-9fdc-42f4-b932-9f249172535a';
  $display->content['new-e655444e-9fdc-42f4-b932-9f249172535a'] = $pane;
  $display->panels['left'][0] = 'new-e655444e-9fdc-42f4-b932-9f249172535a';
  $pane = new stdClass();
  $pane->pid = 'new-d72f7510-9aad-4fe5-8024-2fa9096c8bb6';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-knowledgebase';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-knowledgebase',
    'parent_mlid' => 0,
    'parent' => 'menu-knowledgebase:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd72f7510-9aad-4fe5-8024-2fa9096c8bb6';
  $display->content['new-d72f7510-9aad-4fe5-8024-2fa9096c8bb6'] = $pane;
  $display->panels['left'][1] = 'new-d72f7510-9aad-4fe5-8024-2fa9096c8bb6';
  $pane = new stdClass();
  $pane->pid = 'new-bed47fb4-4c54-45a9-b603-b5dbe1481a0f';
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
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'bed47fb4-4c54-45a9-b603-b5dbe1481a0f';
  $display->content['new-bed47fb4-4c54-45a9-b603-b5dbe1481a0f'] = $pane;
  $display->panels['middle'][0] = 'new-bed47fb4-4c54-45a9-b603-b5dbe1481a0f';
  $pane = new stdClass();
  $pane->pid = 'new-205a426c-99a1-45a5-a349-7bac97a0e0e2';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Attachments',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<?php
$node = node_load(%node:nid);
return salto_knowledgebase_render_salto_363_panel_attachment($node);

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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '205a426c-99a1-45a5-a349-7bac97a0e0e2';
  $display->content['new-205a426c-99a1-45a5-a349-7bac97a0e0e2'] = $pane;
  $display->panels['middle'][1] = 'new-205a426c-99a1-45a5-a349-7bac97a0e0e2';
  $pane = new stdClass();
  $pane->pid = 'new-34002b6a-fef6-473a-a6cc-266597f08f86';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'empty',
      1 => 'argument_entity_id:node_1',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'type' => 'posts',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '34002b6a-fef6-473a-a6cc-266597f08f86';
  $display->content['new-34002b6a-fef6-473a-a6cc-266597f08f86'] = $pane;
  $display->panels['right'][0] = 'new-34002b6a-fef6-473a-a6cc-266597f08f86';
  $pane = new stdClass();
  $pane->pid = 'new-60f13281-dc89-49dd-bd60-489982ef3f2c';
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
  $pane->uuid = '60f13281-dc89-49dd-bd60-489982ef3f2c';
  $display->content['new-60f13281-dc89-49dd-bd60-489982ef3f2c'] = $pane;
  $display->panels['right'][1] = 'new-60f13281-dc89-49dd-bd60-489982ef3f2c';
  $pane = new stdClass();
  $pane->pid = 'new-246cbee8-a5b6-43ef-b443-4295ff3cd324';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'knowledgebase_references-compact';
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
    'style' => 'blockpanel',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '246cbee8-a5b6-43ef-b443-4295ff3cd324';
  $display->content['new-246cbee8-a5b6-43ef-b443-4295ff3cd324'] = $pane;
  $display->panels['right'][2] = 'new-246cbee8-a5b6-43ef-b443-4295ff3cd324';
  $pane = new stdClass();
  $pane->pid = 'new-a25c953e-51a3-4427-8b7a-3036fd84e178';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_references';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Verweise',
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
  $pane->uuid = 'a25c953e-51a3-4427-8b7a-3036fd84e178';
  $display->content['new-a25c953e-51a3-4427-8b7a-3036fd84e178'] = $pane;
  $display->panels['right'][3] = 'new-a25c953e-51a3-4427-8b7a-3036fd84e178';
  $pane = new stdClass();
  $pane->pid = 'new-7068df83-0b8e-4b2b-9412-d8efcf8585f2';
  $pane->panel = 'right';
  $pane->type = 'node_attachments';
  $pane->subtype = 'node_attachments';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => 'Anhänge',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '7068df83-0b8e-4b2b-9412-d8efcf8585f2';
  $display->content['new-7068df83-0b8e-4b2b-9412-d8efcf8585f2'] = $pane;
  $display->panels['right'][4] = 'new-7068df83-0b8e-4b2b-9412-d8efcf8585f2';
  $pane = new stdClass();
  $pane->pid = 'new-b7639369-2f94-42a3-84ed-2af62879c141';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'tmp_files_by_node-panel_file_with_ref';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'id' => '%node:nid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'b7639369-2f94-42a3-84ed-2af62879c141';
  $display->content['new-b7639369-2f94-42a3-84ed-2af62879c141'] = $pane;
  $display->panels['right'][5] = 'new-b7639369-2f94-42a3-84ed-2af62879c141';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bed47fb4-4c54-45a9-b603-b5dbe1481a0f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function salto_knowledgebase_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'knowledgebase_all_content';
  $page->task = 'page';
  $page->admin_title = 'knowledgebase-all-content';
  $page->admin_description = 'Knowledgebase main area';
  $page->path = 'posts';
  $page->access = array(
    'plugins' => array(),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Beiträge',
    'name' => 'main-menu',
    'weight' => '-49',
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
  $handler->name = 'page_knowledgebase_all_content_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'knowledgebase_all_content';
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
  $display->title = 'Beiträge';
  $display->uuid = 'e41a225e-1178-4815-b625-8c481227457c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_knowledgebase_all_content_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6e998d1e-5a13-4636-8033-6774450aebed';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-knowledgebase';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-knowledgebase',
    'parent_mlid' => 0,
    'parent' => 'menu-knowledgebase:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
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
  $pane->uuid = '6e998d1e-5a13-4636-8033-6774450aebed';
  $display->content['new-6e998d1e-5a13-4636-8033-6774450aebed'] = $pane;
  $display->panels['left'][0] = 'new-6e998d1e-5a13-4636-8033-6774450aebed';
  $pane = new stdClass();
  $pane->pid = 'new-5de0a99f-79a0-4882-b9a4-ef2eb3546bec';
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
  $pane->uuid = '5de0a99f-79a0-4882-b9a4-ef2eb3546bec';
  $display->content['new-5de0a99f-79a0-4882-b9a4-ef2eb3546bec'] = $pane;
  $display->panels['middle'][0] = 'new-5de0a99f-79a0-4882-b9a4-ef2eb3546bec';
  $pane = new stdClass();
  $pane->pid = 'new-be9b4f2c-3182-44bb-ae79-c897c0f8272b';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'knowledgebase_content_by_category-panel_all';
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
  $pane->uuid = 'be9b4f2c-3182-44bb-ae79-c897c0f8272b';
  $display->content['new-be9b4f2c-3182-44bb-ae79-c897c0f8272b'] = $pane;
  $display->panels['middle'][1] = 'new-be9b4f2c-3182-44bb-ae79-c897c0f8272b';
  $pane = new stdClass();
  $pane->pid = 'new-4e3ee2be-98cc-43be-93f2-3845fbefa3b6';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'posts',
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
  $pane->pid = 'new-ca5c5fad-af47-4164-b88a-efb047d66cdf';
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
  $pane->uuid = 'ca5c5fad-af47-4164-b88a-efb047d66cdf';
  $display->content['new-ca5c5fad-af47-4164-b88a-efb047d66cdf'] = $pane;
  $display->panels['right'][1] = 'new-ca5c5fad-af47-4164-b88a-efb047d66cdf';
  $pane = new stdClass();
  $pane->pid = 'new-24efb7f5-aaf9-4343-97c8-2fa08449a5d5';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = FALSE;
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
  $pane = new stdClass();
  $pane->pid = 'new-fe1d51c5-d6f2-4aa1-b8c0-3b64cb875a79';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'heartbeat-kbactivity';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Aktivität',
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
  $pane->uuid = 'fe1d51c5-d6f2-4aa1-b8c0-3b64cb875a79';
  $display->content['new-fe1d51c5-d6f2-4aa1-b8c0-3b64cb875a79'] = $pane;
  $display->panels['right'][3] = 'new-fe1d51c5-d6f2-4aa1-b8c0-3b64cb875a79';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['knowledgebase_all_content'] = $page;

  return $pages;

}
