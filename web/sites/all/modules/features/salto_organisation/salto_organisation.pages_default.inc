<?php

/**
 * @file
 * salto_organisation.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function salto_organisation_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'Organisation',
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
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'organisation' => 'organisation',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
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
  $display->title = '%node:title';
  $display->uuid = '8ab5f3ea-371c-441f-a14f-6fe0ef7faac3';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4c6a1a03-1c99-4446-990a-44e5a30428de';
  $pane->panel = 'left';
  $pane->type = 'membership_summary';
  $pane->subtype = 'membership_summary';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => NULL,
    'context' => array(
      0 => 'argument_entity_id:node_1',
      1 => 'empty',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4c6a1a03-1c99-4446-990a-44e5a30428de';
  $display->content['new-4c6a1a03-1c99-4446-990a-44e5a30428de'] = $pane;
  $display->panels['left'][0] = 'new-4c6a1a03-1c99-4446-990a-44e5a30428de';
  $pane = new stdClass();
  $pane->pid = 'new-21419ebe-c9c3-4389-91c4-6b55cae28ece';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_organisation_parent';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'entityreference_label',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'link' => 1,
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '21419ebe-c9c3-4389-91c4-6b55cae28ece';
  $display->content['new-21419ebe-c9c3-4389-91c4-6b55cae28ece'] = $pane;
  $display->panels['left'][1] = 'new-21419ebe-c9c3-4389-91c4-6b55cae28ece';
  $pane = new stdClass();
  $pane->pid = 'new-0fb3f90e-a016-45cd-bdea-4f84c01c4e16';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'organisations-child_organisations';
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
  $pane->uuid = '0fb3f90e-a016-45cd-bdea-4f84c01c4e16';
  $display->content['new-0fb3f90e-a016-45cd-bdea-4f84c01c4e16'] = $pane;
  $display->panels['left'][2] = 'new-0fb3f90e-a016-45cd-bdea-4f84c01c4e16';
  $pane = new stdClass();
  $pane->pid = 'new-8528ee4a-fac7-4720-be18-ce102290c873';
  $pane->panel = 'middle';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 0,
    'markup' => 'h1',
    'id' => '',
    'class' => '',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '8528ee4a-fac7-4720-be18-ce102290c873';
  $display->content['new-8528ee4a-fac7-4720-be18-ce102290c873'] = $pane;
  $display->panels['middle'][0] = 'new-8528ee4a-fac7-4720-be18-ce102290c873';
  $pane = new stdClass();
  $pane->pid = 'new-f25a7ad1-ce43-49e0-b42d-0675050f0e03';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_organisation_logo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_rendered',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'teaser',
    ),
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = 'f25a7ad1-ce43-49e0-b42d-0675050f0e03';
  $display->content['new-f25a7ad1-ce43-49e0-b42d-0675050f0e03'] = $pane;
  $display->panels['middle'][1] = 'new-f25a7ad1-ce43-49e0-b42d-0675050f0e03';
  $pane = new stdClass();
  $pane->pid = 'new-bd2dad21-9487-4550-aa74-a63784cab329';
  $pane->panel = 'middle';
  $pane->type = 'node_body';
  $pane->subtype = 'node_body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
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
  $pane->uuid = 'bd2dad21-9487-4550-aa74-a63784cab329';
  $display->content['new-bd2dad21-9487-4550-aa74-a63784cab329'] = $pane;
  $display->panels['middle'][2] = 'new-bd2dad21-9487-4550-aa74-a63784cab329';
  $pane = new stdClass();
  $pane->pid = 'new-a130a397-1ba1-4ac7-9d01-b7497becf51a';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'licenses_educoncepts-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'arguments' => array(
      'field_educoncept_organisation_target_id' => '1120',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'a130a397-1ba1-4ac7-9d01-b7497becf51a';
  $display->content['new-a130a397-1ba1-4ac7-9d01-b7497becf51a'] = $pane;
  $display->panels['middle'][3] = 'new-a130a397-1ba1-4ac7-9d01-b7497becf51a';
  $pane = new stdClass();
  $pane->pid = 'new-9ba7c7d1-51ed-46a4-bd1b-1a17df766b7a';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'licenses_earemotes-panel_pane_2';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '9ba7c7d1-51ed-46a4-bd1b-1a17df766b7a';
  $display->content['new-9ba7c7d1-51ed-46a4-bd1b-1a17df766b7a'] = $pane;
  $display->panels['middle'][4] = 'new-9ba7c7d1-51ed-46a4-bd1b-1a17df766b7a';
  $pane = new stdClass();
  $pane->pid = 'new-a59fb72a-0edf-4310-91c6-fc1cf905ee5d';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'organisation',
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
  $pane->uuid = 'a59fb72a-0edf-4310-91c6-fc1cf905ee5d';
  $display->content['new-a59fb72a-0edf-4310-91c6-fc1cf905ee5d'] = $pane;
  $display->panels['right'][0] = 'new-a59fb72a-0edf-4310-91c6-fc1cf905ee5d';
  $pane = new stdClass();
  $pane->pid = 'new-acf8742b-db47-4936-8f6f-68a50bfe2375';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'og_membership:field_organisation_position';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'above',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'relationship_og_membership_from_group_and_user_1',
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
  $pane->uuid = 'acf8742b-db47-4936-8f6f-68a50bfe2375';
  $display->content['new-acf8742b-db47-4936-8f6f-68a50bfe2375'] = $pane;
  $display->panels['right'][1] = 'new-acf8742b-db47-4936-8f6f-68a50bfe2375';
  $pane = new stdClass();
  $pane->pid = 'new-fd6d910b-18b9-487b-bbbb-4278d10e0008';
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'fd6d910b-18b9-487b-bbbb-4278d10e0008';
  $display->content['new-fd6d910b-18b9-487b-bbbb-4278d10e0008'] = $pane;
  $display->panels['right'][2] = 'new-fd6d910b-18b9-487b-bbbb-4278d10e0008';
  $pane = new stdClass();
  $pane->pid = 'new-60ee0920-8653-4488-9877-b9d2f05f9d77';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'people-panel_people_in_og';
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '60ee0920-8653-4488-9877-b9d2f05f9d77';
  $display->content['new-60ee0920-8653-4488-9877-b9d2f05f9d77'] = $pane;
  $display->panels['right'][3] = 'new-60ee0920-8653-4488-9877-b9d2f05f9d77';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bd2dad21-9487-4550-aa74-a63784cab329';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function salto_organisation_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'organisations';
  $page->task = 'page';
  $page->admin_title = 'Organisations';
  $page->admin_description = 'A list of all organisations for dosb admins';
  $page->path = 'organisations';
  $page->access = array(
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
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
  $handler->name = 'page_organisations_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'organisations';
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
    'access' => array(
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
  $display->title = 'Organisationen';
  $display->uuid = 'c7f8186d-bbb7-4987-8750-0e9c3e521fc5';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_organisations_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2bf5c43b-6e94-4714-a64d-cfdae4ccd070';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-0471ca2c4d5ab1b8eca97ec9c4dff45b';
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
  $pane->uuid = '2bf5c43b-6e94-4714-a64d-cfdae4ccd070';
  $display->content['new-2bf5c43b-6e94-4714-a64d-cfdae4ccd070'] = $pane;
  $display->panels['left'][0] = 'new-2bf5c43b-6e94-4714-a64d-cfdae4ccd070';
  $pane = new stdClass();
  $pane->pid = 'new-d243b69b-e966-4cbb-b5b4-a363d8417181';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'salto_organisations_overview-panel_pane_2';
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
  $pane->uuid = 'd243b69b-e966-4cbb-b5b4-a363d8417181';
  $display->content['new-d243b69b-e966-4cbb-b5b4-a363d8417181'] = $pane;
  $display->panels['middle'][0] = 'new-d243b69b-e966-4cbb-b5b4-a363d8417181';
  $pane = new stdClass();
  $pane->pid = 'new-3ca0aa47-1407-465b-9922-5331f0a3340a';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'organisation',
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
  $pane->uuid = '3ca0aa47-1407-465b-9922-5331f0a3340a';
  $display->content['new-3ca0aa47-1407-465b-9922-5331f0a3340a'] = $pane;
  $display->panels['right'][0] = 'new-3ca0aa47-1407-465b-9922-5331f0a3340a';
  $pane = new stdClass();
  $pane->pid = 'new-d2ef1b4c-eb6f-4404-a504-77fc0eb1fe7c';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'my_organisations_people_pane';
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
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'people-org-pane',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd2ef1b4c-eb6f-4404-a504-77fc0eb1fe7c';
  $display->content['new-d2ef1b4c-eb6f-4404-a504-77fc0eb1fe7c'] = $pane;
  $display->panels['right'][1] = 'new-d2ef1b4c-eb6f-4404-a504-77fc0eb1fe7c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['organisations'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'organisations_by_user';
  $page->task = 'page';
  $page->admin_title = 'organisations_by_user';
  $page->admin_description = 'A listing of organisations by user';
  $page->path = 'organisations/%user';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'user_edit_access',
          'php' => 'if(!empty($contexts [\'argument_entity_id:user_1\']->data->uid)) {
  $account = user_load($contexts[\'argument_entity_id:user_1\']->data->uid);
  return user_edit_access($account);
}

return FALSE;',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'Benutzer: ID',
      'name' => 'entity_id:user',
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
  $handler->name = 'page_organisations_by_user__panel';
  $handler->task = 'page';
  $handler->subtask = 'organisations_by_user';
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
    'name' => 'panel',
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
  $display->title = 'Meine Organisationen';
  $display->uuid = '38e1dae0-c1d8-4b22-9eaf-bb003aa6656b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_organisations_by_user__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fdd0621f-0036-4285-bc6d-221f2d817b7c';
  $pane->panel = 'left';
  $pane->type = 'views_panes';
  $pane->subtype = 'my_organisations_people_pane-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:user_1',
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
  $pane->uuid = 'fdd0621f-0036-4285-bc6d-221f2d817b7c';
  $display->content['new-fdd0621f-0036-4285-bc6d-221f2d817b7c'] = $pane;
  $display->panels['left'][0] = 'new-fdd0621f-0036-4285-bc6d-221f2d817b7c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['organisations_by_user'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'organisations_people';
  $page->task = 'page';
  $page->admin_title = 'Organisations People';
  $page->admin_description = '';
  $page->path = 'organisations/%node/people';
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
  $handler->name = 'page_organisations_people_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'organisations_people';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'All',
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
      'plugins' => array(),
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
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Mitglieder';
  $display->uuid = 'fc3adb1a-2826-41ad-a3d2-09a39365724e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_organisations_people_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d285073e-3b96-4dc1-88da-ae0aed0d9bbf';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-6369a348b56401612633ec46d9c535dc';
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
  $pane->uuid = 'd285073e-3b96-4dc1-88da-ae0aed0d9bbf';
  $display->content['new-d285073e-3b96-4dc1-88da-ae0aed0d9bbf'] = $pane;
  $display->panels['left'][0] = 'new-d285073e-3b96-4dc1-88da-ae0aed0d9bbf';
  $pane = new stdClass();
  $pane->pid = 'new-1d975705-ec06-40e7-bf66-5c187d779bbe';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'organisations_people-member_list';
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
  $pane->uuid = '1d975705-ec06-40e7-bf66-5c187d779bbe';
  $display->content['new-1d975705-ec06-40e7-bf66-5c187d779bbe'] = $pane;
  $display->panels['middle'][0] = 'new-1d975705-ec06-40e7-bf66-5c187d779bbe';
  $pane = new stdClass();
  $pane->pid = 'new-58d3e791-08d9-408d-ab31-251d6a7cca0b';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'organisation_invites-panel_pane_1';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '58d3e791-08d9-408d-ab31-251d6a7cca0b';
  $display->content['new-58d3e791-08d9-408d-ab31-251d6a7cca0b'] = $pane;
  $display->panels['middle'][1] = 'new-58d3e791-08d9-408d-ab31-251d6a7cca0b';
  $pane = new stdClass();
  $pane->pid = 'new-d6211788-d05c-42c9-bd3c-1a426b3ec9e6';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'organisation',
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
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_organisations_people_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'organisations_people';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Unused',
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
  $display->storage_id = 'page_organisations_people_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-55582bee-dd01-481e-b342-3137220b5078';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-groups_people-directory';
  $pane->shown = TRUE;
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '55582bee-dd01-481e-b342-3137220b5078';
  $display->content['new-55582bee-dd01-481e-b342-3137220b5078'] = $pane;
  $display->panels['left'][0] = 'new-55582bee-dd01-481e-b342-3137220b5078';
  $pane = new stdClass();
  $pane->pid = 'new-947997de-c165-4e71-a8c0-bed63bb10baf';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'groups_people-directory';
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
    'style' => 'default',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '947997de-c165-4e71-a8c0-bed63bb10baf';
  $display->content['new-947997de-c165-4e71-a8c0-bed63bb10baf'] = $pane;
  $display->panels['middle'][0] = 'new-947997de-c165-4e71-a8c0-bed63bb10baf';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b43c29ff-4588-4289-9aeb-592b718cee25';
  $display->content['new-b43c29ff-4588-4289-9aeb-592b718cee25'] = $pane;
  $display->panels['right'][0] = 'new-b43c29ff-4588-4289-9aeb-592b718cee25';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['organisations_people'] = $page;

  return $pages;

}
