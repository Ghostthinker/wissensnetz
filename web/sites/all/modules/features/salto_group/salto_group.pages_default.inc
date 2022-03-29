<?php

/**
 * @file
 * salto_group.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function salto_group_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_7';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Group: intern',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'OG membership from a group node and user',
        'keyword' => 'og_membership',
        'name' => 'og_membership_from_group_and_user',
        'context' => array(
          0 => 'argument_entity_id:node_1',
        ),
        'id' => 1,
      ),
    ),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'group' => 'group',
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
      'middle' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '67c904f5-843f-4d39-9669-cadd4be7fc5d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fd0c9a41-ee83-4530-8724-12e632223d7e';
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
  $pane->uuid = 'fd0c9a41-ee83-4530-8724-12e632223d7e';
  $display->content['new-fd0c9a41-ee83-4530-8724-12e632223d7e'] = $pane;
  $display->panels['left'][0] = 'new-fd0c9a41-ee83-4530-8724-12e632223d7e';
  $pane = new stdClass();
  $pane->pid = 'new-2494de52-ecf1-475a-b861-79bca3bc47fd';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<h2>%node:title</h2>',
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
  $pane->uuid = '2494de52-ecf1-475a-b861-79bca3bc47fd';
  $display->content['new-2494de52-ecf1-475a-b861-79bca3bc47fd'] = $pane;
  $display->panels['middle'][0] = 'new-2494de52-ecf1-475a-b861-79bca3bc47fd';
  $pane = new stdClass();
  $pane->pid = 'new-8ddc9d7a-017f-4182-a7f1-fe3515d6b62c';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => TRUE,
      ),
      1 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'info area',
          'php' => 'if((arg(2) == "info")) {
  drupal_set_title("Gruppenbeschreibung");
  return true;
}

return false;',
        ),
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'entity_field_value:node:group:field_group_option_description',
        'settings' => array(
          'field_group_option_description' => array(
            'und' => array(
              0 => array(
                'value' => '1',
              ),
            ),
          ),
          'field_group_option_description_value' => array(
            0 => '1',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  );
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'card',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8ddc9d7a-017f-4182-a7f1-fe3515d6b62c';
  $display->content['new-8ddc9d7a-017f-4182-a7f1-fe3515d6b62c'] = $pane;
  $display->panels['middle'][1] = 'new-8ddc9d7a-017f-4182-a7f1-fe3515d6b62c';
  $pane = new stdClass();
  $pane->pid = 'new-68e84336-b5d9-46ac-8354-b59e544a52a2';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'organisation_invites-invite_by_og_and_uid';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-people pane-subpane',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '68e84336-b5d9-46ac-8354-b59e544a52a2';
  $display->content['new-68e84336-b5d9-46ac-8354-b59e544a52a2'] = $pane;
  $display->panels['middle'][2] = 'new-68e84336-b5d9-46ac-8354-b59e544a52a2';
  $pane = new stdClass();
  $pane->pid = 'new-daeb0e2d-541f-4a7a-b1ce-c2287fdb8a4c';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'groups_members-panel_og_pending_memberships';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_perm',
        'settings' => array(
          'perm' => 'approve and deny subscription',
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
    'arguments' => array(
      'gid' => '%node:nid',
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
  $pane->uuid = 'daeb0e2d-541f-4a7a-b1ce-c2287fdb8a4c';
  $display->content['new-daeb0e2d-541f-4a7a-b1ce-c2287fdb8a4c'] = $pane;
  $display->panels['middle'][3] = 'new-daeb0e2d-541f-4a7a-b1ce-c2287fdb8a4c';
  $pane = new stdClass();
  $pane->pid = 'new-90b22af9-72a3-4e60-bc18-be85cb0e90c8';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'group_content-base';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'info area',
          'php' => 'if((arg(2) == "info")) {
  //drupal_set_title("Gruppenbeschreibung");
  return true;
}

return false;',
        ),
        'not' => TRUE,
      ),
    ),
  );
  $pane->configuration = array(
    'arguments' => array(
      'field_og_group_target_id' => '%node:nid',
    ),
    'context' => array(
      0 => 'argument_entity_id:node_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-subpane',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '90b22af9-72a3-4e60-bc18-be85cb0e90c8';
  $display->content['new-90b22af9-72a3-4e60-bc18-be85cb0e90c8'] = $pane;
  $display->panels['middle'][4] = 'new-90b22af9-72a3-4e60-bc18-be85cb0e90c8';
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
      2 => 'empty',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'type' => 'groups',
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
  $pane->pid = 'new-83ee0771-9c3a-4266-96db-2d96e18b475f';
  $pane->panel = 'right';
  $pane->type = 'online_meetings_active';
  $pane->subtype = 'online_meetings_active';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Online Meeting enabled',
          'php' => 'return salto_online_meeting_enabled();',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '83ee0771-9c3a-4266-96db-2d96e18b475f';
  $display->content['new-83ee0771-9c3a-4266-96db-2d96e18b475f'] = $pane;
  $display->panels['right'][1] = 'new-83ee0771-9c3a-4266-96db-2d96e18b475f';
  $pane = new stdClass();
  $pane->pid = 'new-ff4e6542-f858-4f1a-84dd-1e369e0130e3';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'people-panel_people_online_in_og';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
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
    'arguments' => array(
      'gid' => '%node:nid',
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
  $pane->uuid = 'ff4e6542-f858-4f1a-84dd-1e369e0130e3';
  $display->content['new-ff4e6542-f858-4f1a-84dd-1e369e0130e3'] = $pane;
  $display->panels['right'][2] = 'new-ff4e6542-f858-4f1a-84dd-1e369e0130e3';
  $pane = new stdClass();
  $pane->pid = 'new-163a0874-66c4-490c-96d6-f0076a856c53';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'info Argument set',
          'php' => 'return (arg(2) != "info");',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'entity_field_value:node:group:field_group_option_description',
        'settings' => array(
          'field_group_option_description' => array(
            'und' => array(
              0 => array(
                'value' => '1',
              ),
            ),
          ),
          'field_group_option_description_value' => array(
            0 => '1',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => TRUE,
      ),
    ),
  );
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '',
    'format' => 'editor',
    'substitute' => TRUE,
    'name' => 'groups_group_description',
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
  $pane->uuid = '163a0874-66c4-490c-96d6-f0076a856c53';
  $display->content['new-163a0874-66c4-490c-96d6-f0076a856c53'] = $pane;
  $display->panels['right'][3] = 'new-163a0874-66c4-490c-96d6-f0076a856c53';
  $pane = new stdClass();
  $pane->pid = 'new-ddb165d2-aa51-4d7d-9fd5-42309c3a7450';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'people-panel_people_in_og';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
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
    'arguments' => array(
      'gid' => '%node:nid',
    ),
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
  $pane->uuid = 'ddb165d2-aa51-4d7d-9fd5-42309c3a7450';
  $display->content['new-ddb165d2-aa51-4d7d-9fd5-42309c3a7450'] = $pane;
  $display->panels['right'][4] = 'new-ddb165d2-aa51-4d7d-9fd5-42309c3a7450';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'a25c953e-51a3-4427-8b7a-3036fd84e178';
  $display->content['new-a25c953e-51a3-4427-8b7a-3036fd84e178'] = $pane;
  $display->panels['right'][6] = 'new-a25c953e-51a3-4427-8b7a-3036fd84e178';
  $pane = new stdClass();
  $pane->pid = 'new-7068df83-0b8e-4b2b-9412-d8efcf8585f2';
  $pane->panel = 'right';
  $pane->type = 'node_attachments';
  $pane->subtype = 'node_attachments';
  $pane->shown = TRUE;
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '7068df83-0b8e-4b2b-9412-d8efcf8585f2';
  $display->content['new-7068df83-0b8e-4b2b-9412-d8efcf8585f2'] = $pane;
  $display->panels['right'][7] = 'new-7068df83-0b8e-4b2b-9412-d8efcf8585f2';
  $pane = new stdClass();
  $pane->pid = 'new-9ac8ce54-b790-4735-b031-bb9b835b768f';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'tmp_files_by_node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
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
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '9ac8ce54-b790-4735-b031-bb9b835b768f';
  $display->content['new-9ac8ce54-b790-4735-b031-bb9b835b768f'] = $pane;
  $display->panels['right'][8] = 'new-9ac8ce54-b790-4735-b031-bb9b835b768f';
  $pane = new stdClass();
  $pane->pid = 'new-bf1830f9-5ac8-47ae-bc16-ea3a9926225e';
  $pane->panel = 'right';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:flag_notification_subscribe_node';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'og_member',
        'settings' => array(
          'state' => array(
            1 => '1',
          ),
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = 'bf1830f9-5ac8-47ae-bc16-ea3a9926225e';
  $display->content['new-bf1830f9-5ac8-47ae-bc16-ea3a9926225e'] = $pane;
  $display->panels['right'][9] = 'new-bf1830f9-5ac8-47ae-bc16-ea3a9926225e';
  $pane = new stdClass();
  $pane->pid = 'new-56bc0aaf-a0de-4852-bfd2-8ec0a1bb3d53';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Join links',
    'title' => '',
    'body' => '<div class="group-actions action-links">
<?php
print salto_group_render_join_action(%node:nid, FALSE);
?>
</div>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '56bc0aaf-a0de-4852-bfd2-8ec0a1bb3d53';
  $display->content['new-56bc0aaf-a0de-4852-bfd2-8ec0a1bb3d53'] = $pane;
  $display->panels['right'][10] = 'new-56bc0aaf-a0de-4852-bfd2-8ec0a1bb3d53';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_7'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_8';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'KB: in group',
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
              'shared_post' => 'shared_post',
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
        2 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if group is selected',
            'php' => '$node = $contexts[\'argument_entity_id:node_1\']->data;

if (isset($node ->field_og_group[LANGUAGE_NONE][0][\'target_id\'])) {
 return true ;
}
else{
return  false; 
}',
          ),
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
  $display->uuid = '67c904f5-843f-4d39-9669-cadd4be7fc5d';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_8';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-46c2064b-7228-4187-b953-fff1ed8a57aa';
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
  $pane->uuid = '46c2064b-7228-4187-b953-fff1ed8a57aa';
  $display->content['new-46c2064b-7228-4187-b953-fff1ed8a57aa'] = $pane;
  $display->panels['left'][0] = 'new-46c2064b-7228-4187-b953-fff1ed8a57aa';
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
  $pane->uuid = 'bed47fb4-4c54-45a9-b603-b5dbe1481a0f';
  $display->content['new-bed47fb4-4c54-45a9-b603-b5dbe1481a0f'] = $pane;
  $display->panels['middle'][0] = 'new-bed47fb4-4c54-45a9-b603-b5dbe1481a0f';
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
      2 => 'empty',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'type' => 'groups',
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
  $pane->shown = TRUE;
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
  $pane->pid = 'new-43805163-da76-474d-8e70-f02d2d363a11';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'tmp_files_by_node-panel_file_with_ref';
  $pane->shown = TRUE;
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
  $pane->uuid = '43805163-da76-474d-8e70-f02d2d363a11';
  $display->content['new-43805163-da76-474d-8e70-f02d2d363a11'] = $pane;
  $display->panels['right'][2] = 'new-43805163-da76-474d-8e70-f02d2d363a11';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '246cbee8-a5b6-43ef-b443-4295ff3cd324';
  $display->content['new-246cbee8-a5b6-43ef-b443-4295ff3cd324'] = $pane;
  $display->panels['right'][4] = 'new-246cbee8-a5b6-43ef-b443-4295ff3cd324';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'a25c953e-51a3-4427-8b7a-3036fd84e178';
  $display->content['new-a25c953e-51a3-4427-8b7a-3036fd84e178'] = $pane;
  $display->panels['right'][5] = 'new-a25c953e-51a3-4427-8b7a-3036fd84e178';
  $pane = new stdClass();
  $pane->pid = 'new-8dbbbc5f-6198-4bda-9c3d-b511fa4ad3c7';
  $pane->panel = 'right';
  $pane->type = 'entity_field_extra';
  $pane->subtype = 'node:flag_notification_subscribe_node';
  $pane->shown = TRUE;
  $pane->access = array();
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
  $pane->uuid = '8dbbbc5f-6198-4bda-9c3d-b511fa4ad3c7';
  $display->content['new-8dbbbc5f-6198-4bda-9c3d-b511fa4ad3c7'] = $pane;
  $display->panels['right'][6] = 'new-8dbbbc5f-6198-4bda-9c3d-b511fa4ad3c7';
  $pane = new stdClass();
  $pane->pid = 'new-a0044945-7c9b-426c-904a-b60392cd82c8';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array(
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
  );
  $pane->configuration = array(
    'admin_title' => 'salto_share_post_action',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<a href="/node/add/shared-post?field_sharedpost_reference=%node:nid" title="<?php print t("You can share this post to one of your groups"); ?>" class="share share-action salto_knowledgebase-processed share-processed" rel="nofollow"><?php print t("Share"); ?></a>',
    'format' => 'php_code',
    'substitute' => 1,
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'a0044945-7c9b-426c-904a-b60392cd82c8';
  $display->content['new-a0044945-7c9b-426c-904a-b60392cd82c8'] = $pane;
  $display->panels['right'][7] = 'new-a0044945-7c9b-426c-904a-b60392cd82c8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bed47fb4-4c54-45a9-b603-b5dbe1481a0f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_8'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function salto_group_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'groups';
  $page->task = 'page';
  $page->admin_title = 'Groups';
  $page->admin_description = 'The main menue region for people and organisations';
  $page->path = 'groups';
  $page->access = array(
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
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Groups',
    'name' => 'main-menu',
    'weight' => '48',
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
  $handler->name = 'page_groups_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'groups';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Benutzer',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
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
  $display->layout = 'salto_363';
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
  $display->uuid = '4088d96d-5bcd-4c33-b439-839a553bb49a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_groups_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3c872048-fcb8-443e-9531-6c7a878bd24e';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-e578939dcd9008b2e3608e2eb4467d96';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3c872048-fcb8-443e-9531-6c7a878bd24e';
  $display->content['new-3c872048-fcb8-443e-9531-6c7a878bd24e'] = $pane;
  $display->panels['left'][0] = 'new-3c872048-fcb8-443e-9531-6c7a878bd24e';
  $pane = new stdClass();
  $pane->pid = 'new-367a887b-dced-4029-84f5-0d51e4187bce';
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
  $pane->uuid = '367a887b-dced-4029-84f5-0d51e4187bce';
  $display->content['new-367a887b-dced-4029-84f5-0d51e4187bce'] = $pane;
  $display->panels['middle'][0] = 'new-367a887b-dced-4029-84f5-0d51e4187bce';
  $pane = new stdClass();
  $pane->pid = 'new-1956b2cf-fbfc-4380-a00e-3e86fdccf914';
  $pane->panel = 'middle';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
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
  $pane->uuid = '1956b2cf-fbfc-4380-a00e-3e86fdccf914';
  $display->content['new-1956b2cf-fbfc-4380-a00e-3e86fdccf914'] = $pane;
  $display->panels['middle'][1] = 'new-1956b2cf-fbfc-4380-a00e-3e86fdccf914';
  $pane = new stdClass();
  $pane->pid = 'new-8a007577-5d41-4ebb-83bc-f09fb1272b41';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'groups-panel_groups_directory';
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
  $pane->uuid = '8a007577-5d41-4ebb-83bc-f09fb1272b41';
  $display->content['new-8a007577-5d41-4ebb-83bc-f09fb1272b41'] = $pane;
  $display->panels['middle'][2] = 'new-8a007577-5d41-4ebb-83bc-f09fb1272b41';
  $pane = new stdClass();
  $pane->pid = 'new-4282dcc8-8d29-4d28-976a-4b1903f26727';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'groups',
    'context' => array(
      0 => 'empty',
      1 => 'empty',
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
  $pane->uuid = '4282dcc8-8d29-4d28-976a-4b1903f26727';
  $display->content['new-4282dcc8-8d29-4d28-976a-4b1903f26727'] = $pane;
  $display->panels['right'][0] = 'new-4282dcc8-8d29-4d28-976a-4b1903f26727';
  $pane = new stdClass();
  $pane->pid = 'new-e7f247ec-737b-43a2-96d7-22d2c6451427';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'groups_user_groups-panel_my_og_groups_by_type';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e7f247ec-737b-43a2-96d7-22d2c6451427';
  $display->content['new-e7f247ec-737b-43a2-96d7-22d2c6451427'] = $pane;
  $display->panels['right'][1] = 'new-e7f247ec-737b-43a2-96d7-22d2c6451427';
  $pane = new stdClass();
  $pane->pid = 'new-c8622cb7-bc50-4acc-87a7-bc16a59c2744';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'organisation_invites-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'context_user_1',
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
  $pane->uuid = 'c8622cb7-bc50-4acc-87a7-bc16a59c2744';
  $display->content['new-c8622cb7-bc50-4acc-87a7-bc16a59c2744'] = $pane;
  $display->panels['right'][2] = 'new-c8622cb7-bc50-4acc-87a7-bc16a59c2744';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'groups_files';
  $page->task = 'page';
  $page->admin_title = 'groups-files';
  $page->admin_description = 'Knowledgebase main area';
  $page->path = 'groups/%node/files/term/!term';
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
    'type' => 'none',
    'title' => 'Files',
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
    'term' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vocabularies' => array(),
        'breadcrumb' => 1,
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
  $handler->name = 'page_groups_files_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'groups_files';
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
  $display->title = 'Dateien';
  $display->uuid = 'e41a225e-1178-4815-b625-8c481227457c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_groups_files_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c0e404d1-83a7-472d-a8b1-92d70147a4f8';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-groups';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'menu-groups',
    'parent_mlid' => '0',
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
    'depth_relative' => 0,
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
  $pane->uuid = 'c0e404d1-83a7-472d-a8b1-92d70147a4f8';
  $display->content['new-c0e404d1-83a7-472d-a8b1-92d70147a4f8'] = $pane;
  $display->panels['left'][0] = 'new-c0e404d1-83a7-472d-a8b1-92d70147a4f8';
  $pane = new stdClass();
  $pane->pid = 'new-8f844485-01f8-4ff7-a9ea-61edfaa6dd9c';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'groups_files-files_directory';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'field_og_group_target_id' => '%node:nid',
    ),
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
  $pane->uuid = '8f844485-01f8-4ff7-a9ea-61edfaa6dd9c';
  $display->content['new-8f844485-01f8-4ff7-a9ea-61edfaa6dd9c'] = $pane;
  $display->panels['middle'][0] = 'new-8f844485-01f8-4ff7-a9ea-61edfaa6dd9c';
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
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_files'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'groups_people';
  $page->task = 'page';
  $page->admin_title = 'Groups People';
  $page->admin_description = '';
  $page->path = 'groups/%node/people';
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
  $handler->name = 'page_groups_people_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'groups_people';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Managers',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'OG membership from a group node and user',
        'keyword' => 'og_membership',
        'name' => 'og_membership_from_group_and_user',
        'context' => array(
          0 => 'argument_entity_id:node_1',
        ),
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'og_member',
          'settings' => array(
            'state' => array(
              1 => '1',
            ),
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'bypass node access',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
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
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Mitglieder';
  $display->uuid = 'fc3adb1a-2826-41ad-a3d2-09a39365724e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_groups_people_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-17b082cc-cdb0-4573-9710-fb935ce880eb';
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
  $pane->uuid = '17b082cc-cdb0-4573-9710-fb935ce880eb';
  $display->content['new-17b082cc-cdb0-4573-9710-fb935ce880eb'] = $pane;
  $display->panels['left'][0] = 'new-17b082cc-cdb0-4573-9710-fb935ce880eb';
  $pane = new stdClass();
  $pane->pid = 'new-c6e90c44-0691-4663-a5c2-e0c1c678fcb9';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-47c86d510d422969674e3320e0b62b58';
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
  $pane->uuid = 'c6e90c44-0691-4663-a5c2-e0c1c678fcb9';
  $display->content['new-c6e90c44-0691-4663-a5c2-e0c1c678fcb9'] = $pane;
  $display->panels['left'][1] = 'new-c6e90c44-0691-4663-a5c2-e0c1c678fcb9';
  $pane = new stdClass();
  $pane->pid = 'new-42a8fa9c-d4fa-4870-bf96-9266ed5e8fb4';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'groups_members-panel_og_members';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'arguments' => array(
      'gid' => '%node:nid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-people-directory',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '42a8fa9c-d4fa-4870-bf96-9266ed5e8fb4';
  $display->content['new-42a8fa9c-d4fa-4870-bf96-9266ed5e8fb4'] = $pane;
  $display->panels['middle'][0] = 'new-42a8fa9c-d4fa-4870-bf96-9266ed5e8fb4';
  $pane = new stdClass();
  $pane->pid = 'new-ba8e68f3-7cba-46e4-af7c-38c3bc76738e';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'organisation_invites-invite_by_og';
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
    'style' => 'default',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-people',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ba8e68f3-7cba-46e4-af7c-38c3bc76738e';
  $display->content['new-ba8e68f3-7cba-46e4-af7c-38c3bc76738e'] = $pane;
  $display->panels['middle'][1] = 'new-ba8e68f3-7cba-46e4-af7c-38c3bc76738e';
  $pane = new stdClass();
  $pane->pid = 'new-341ce5b8-80bb-4d5d-9a5d-4d94194774bd';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'organisation_invites-panel_pane_3';
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
    'style' => 'default',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-people',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '341ce5b8-80bb-4d5d-9a5d-4d94194774bd';
  $display->content['new-341ce5b8-80bb-4d5d-9a5d-4d94194774bd'] = $pane;
  $display->panels['middle'][2] = 'new-341ce5b8-80bb-4d5d-9a5d-4d94194774bd';
  $pane = new stdClass();
  $pane->pid = 'new-d6211788-d05c-42c9-bd3c-1a426b3ec9e6';
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
  $pane->uuid = 'd6211788-d05c-42c9-bd3c-1a426b3ec9e6';
  $display->content['new-d6211788-d05c-42c9-bd3c-1a426b3ec9e6'] = $pane;
  $display->panels['right'][0] = 'new-d6211788-d05c-42c9-bd3c-1a426b3ec9e6';
  $pane = new stdClass();
  $pane->pid = 'new-b43c29ff-4588-4289-9aeb-592b718cee25';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'people-panel_people_online_in_og';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'gid' => '%node:nid',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-people-online',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b43c29ff-4588-4289-9aeb-592b718cee25';
  $display->content['new-b43c29ff-4588-4289-9aeb-592b718cee25'] = $pane;
  $display->panels['right'][1] = 'new-b43c29ff-4588-4289-9aeb-592b718cee25';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-17b082cc-cdb0-4573-9710-fb935ce880eb';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_people'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'groups_posts';
  $page->task = 'page';
  $page->admin_title = 'groups-posts';
  $page->admin_description = 'Groups knowledgebase main area';
  $page->path = 'groups/%node/posts/%category';
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
    'category' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          2 => 0,
          10 => 0,
          1 => 0,
          15 => 0,
          18 => 0,
          19 => 0,
          20 => 0,
          21 => 0,
          6 => 0,
          8 => 0,
          4 => 0,
          3 => 0,
          5 => 0,
          11 => 0,
          7 => 0,
        ),
        'breadcrumb' => 1,
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
  $handler->name = 'page_groups_posts_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'groups_posts';
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
  $display->storage_id = 'page_groups_posts_panel_context';
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
  $pane->pid = 'new-983c27cc-f286-4313-9ce4-2519af3c2ad7';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'group_content-base';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:node_1',
      1 => 'argument_term_1',
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
  $pane->uuid = '983c27cc-f286-4313-9ce4-2519af3c2ad7';
  $display->content['new-983c27cc-f286-4313-9ce4-2519af3c2ad7'] = $pane;
  $display->panels['middle'][0] = 'new-983c27cc-f286-4313-9ce4-2519af3c2ad7';
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
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_posts'] = $page;

  return $pages;

}
