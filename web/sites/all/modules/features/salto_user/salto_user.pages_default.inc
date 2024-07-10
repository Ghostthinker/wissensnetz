<?php

/**
 * @file
 * salto_user.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function salto_user_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_edit_panel_context';
  $handler->task = 'user_edit';
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
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/*/edit/main',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
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
  $display->uuid = 'b6737587-c2a1-461e-ba9e-2e59caffae37';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'user_edit_panel_context';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_edit_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'default',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'user-profile',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Profile2 from user',
        'keyword' => 'profile2',
        'name' => 'profile2',
        'type' => 'main',
        'context' => 'argument_entity_id:user_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'legal_accepted',
          'settings' => NULL,
          'context' => array(
            0 => 'argument_entity_id:user_1',
          ),
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'salto_363';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-4',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'left',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-8',
      ),
    ),
  );
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
  $display->title = '%user:name';
  $display->uuid = '126f277d-a40a-4050-87d8-b82e55e4e836';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'user_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b4a592cc-c5c6-47e9-8248-86b55d25b269';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_user_picture';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'user_220x200',
      'image_link' => '',
    ),
    'context' => 'relationship_profile2_1',
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
  $pane->uuid = 'b4a592cc-c5c6-47e9-8248-86b55d25b269';
  $display->content['new-b4a592cc-c5c6-47e9-8248-86b55d25b269'] = $pane;
  $display->panels['left'][0] = 'new-b4a592cc-c5c6-47e9-8248-86b55d25b269';
  $pane = new stdClass();
  $pane->pid = 'new-a64fc1ed-906b-46c8-9f72-5f298dd3b767';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_contact_mobile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->uuid = 'a64fc1ed-906b-46c8-9f72-5f298dd3b767';
  $display->content['new-a64fc1ed-906b-46c8-9f72-5f298dd3b767'] = $pane;
  $display->panels['left'][1] = 'new-a64fc1ed-906b-46c8-9f72-5f298dd3b767';
  $pane = new stdClass();
  $pane->pid = 'new-c1b0a398-5d50-4fe1-9f37-87c33391bfc9';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_contact_phone';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'c1b0a398-5d50-4fe1-9f37-87c33391bfc9';
  $display->content['new-c1b0a398-5d50-4fe1-9f37-87c33391bfc9'] = $pane;
  $display->panels['left'][2] = 'new-c1b0a398-5d50-4fe1-9f37-87c33391bfc9';
  $pane = new stdClass();
  $pane->pid = 'new-d86f87e3-0f00-4e24-b9ac-e0c74c3dc93f';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_contact_email';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd86f87e3-0f00-4e24-b9ac-e0c74c3dc93f';
  $display->content['new-d86f87e3-0f00-4e24-b9ac-e0c74c3dc93f'] = $pane;
  $display->panels['left'][3] = 'new-d86f87e3-0f00-4e24-b9ac-e0c74c3dc93f';
  $pane = new stdClass();
  $pane->pid = 'new-5c02ddb1-9954-454a-88d7-4418734df6b4';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_postal_address';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'addressfield_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'use_widget_handlers' => 1,
      'format_handlers' => array(
        'address' => 'address',
      ),
    ),
    'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '5c02ddb1-9954-454a-88d7-4418734df6b4';
  $display->content['new-5c02ddb1-9954-454a-88d7-4418734df6b4'] = $pane;
  $display->panels['left'][4] = 'new-5c02ddb1-9954-454a-88d7-4418734df6b4';
  $pane = new stdClass();
  $pane->pid = 'new-b00586be-5597-4ad9-8083-4807e6eb18c7';
  $pane->panel = 'middle';
  $pane->type = 'token';
  $pane->subtype = 'user:name';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'sanitize' => 1,
    'context' => 'argument_entity_id:user_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'h2',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b00586be-5597-4ad9-8083-4807e6eb18c7';
  $display->content['new-b00586be-5597-4ad9-8083-4807e6eb18c7'] = $pane;
  $display->panels['middle'][0] = 'new-b00586be-5597-4ad9-8083-4807e6eb18c7';
  $pane = new stdClass();
  $pane->pid = 'new-e1c30634-906b-4963-a341-d18ce1815d75';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Responsibilities',
    'title' => '',
    'body' => '<?php
if(is_numeric(arg(1))) {
  $uid = arg(1);
  print salto_user_get_organisations_by_user($uid,20);
}
?>',
    'format' => 'php_code',
    'substitute' => 0,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e1c30634-906b-4963-a341-d18ce1815d75';
  $display->content['new-e1c30634-906b-4963-a341-d18ce1815d75'] = $pane;
  $display->panels['middle'][1] = 'new-e1c30634-906b-4963-a341-d18ce1815d75';
  $pane = new stdClass();
  $pane->pid = 'new-26603ef4-4161-471f-984d-f278e155284d';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_about_me';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->uuid = '26603ef4-4161-471f-984d-f278e155284d';
  $display->content['new-26603ef4-4161-471f-984d-f278e155284d'] = $pane;
  $display->panels['middle'][2] = 'new-26603ef4-4161-471f-984d-f278e155284d';
  $pane = new stdClass();
  $pane->pid = 'new-42a1abc0-9579-4270-8383-79159031fd9b';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_categories';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->uuid = '42a1abc0-9579-4270-8383-79159031fd9b';
  $display->content['new-42a1abc0-9579-4270-8383-79159031fd9b'] = $pane;
  $display->panels['middle'][3] = 'new-42a1abc0-9579-4270-8383-79159031fd9b';
  $pane = new stdClass();
  $pane->pid = 'new-516af269-f174-452b-8063-27491769cb76';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_competencies';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '516af269-f174-452b-8063-27491769cb76';
  $display->content['new-516af269-f174-452b-8063-27491769cb76'] = $pane;
  $display->panels['middle'][4] = 'new-516af269-f174-452b-8063-27491769cb76';
  $pane = new stdClass();
  $pane->pid = 'new-49d12304-958c-415f-b20c-9083c5ed8260';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_interests';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '49d12304-958c-415f-b20c-9083c5ed8260';
  $display->content['new-49d12304-958c-415f-b20c-9083c5ed8260'] = $pane;
  $display->panels['middle'][5] = 'new-49d12304-958c-415f-b20c-9083c5ed8260';
  $pane = new stdClass();
  $pane->pid = 'new-5e5806fa-0b64-4568-9bc3-acf6351422de';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_sports';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '5e5806fa-0b64-4568-9bc3-acf6351422de';
  $display->content['new-5e5806fa-0b64-4568-9bc3-acf6351422de'] = $pane;
  $display->panels['middle'][6] = 'new-5e5806fa-0b64-4568-9bc3-acf6351422de';
  $pane = new stdClass();
  $pane->pid = 'new-d3345b17-b2a4-4109-9710-0eaeb9a80823';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'profile',
    'context' => array(
      0 => 'argument_entity_id:user_1',
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
  $pane->uuid = 'd3345b17-b2a4-4109-9710-0eaeb9a80823';
  $display->content['new-d3345b17-b2a4-4109-9710-0eaeb9a80823'] = $pane;
  $display->panels['right'][0] = 'new-d3345b17-b2a4-4109-9710-0eaeb9a80823';
  $pane = new stdClass();
  $pane->pid = 'new-769b744d-d3f3-4e61-9efb-4d7ddd53cafa';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'heartbeat-useractivity';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'bip_side_box',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '769b744d-d3f3-4e61-9efb-4d7ddd53cafa';
  $display->content['new-769b744d-d3f3-4e61-9efb-4d7ddd53cafa'] = $pane;
  $display->panels['right'][1] = 'new-769b744d-d3f3-4e61-9efb-4d7ddd53cafa';
  $pane = new stdClass();
  $pane->pid = 'new-6a6eda63-56ca-4d62-90ee-7b64a789ed16';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'activities';
  $pane->shown = FALSE;
  $pane->access = array(
    'logic' => 'and',
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => 'argument_entity_id:user_1.uid',
    ),
    'override_title' => 0,
    'override_title_text' => '',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6a6eda63-56ca-4d62-90ee-7b64a789ed16';
  $display->content['new-6a6eda63-56ca-4d62-90ee-7b64a789ed16'] = $pane;
  $display->panels['right'][2] = 'new-6a6eda63-56ca-4d62-90ee-7b64a789ed16';
  $pane = new stdClass();
  $pane->pid = 'new-1d5a1af5-250c-476e-909c-f40aafb712d1';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<a href="/user/%user:uid/activity">Zur vollen Ansicht</a>',
    'format' => 'php_code',
    'substitute' => 1,
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
  $pane->uuid = '1d5a1af5-250c-476e-909c-f40aafb712d1';
  $display->content['new-1d5a1af5-250c-476e-909c-f40aafb712d1'] = $pane;
  $display->panels['right'][3] = 'new-1d5a1af5-250c-476e-909c-f40aafb712d1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context_2';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'not accepted legal',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Profile2 from user',
        'keyword' => 'profile2',
        'name' => 'profile2',
        'type' => 'main',
        'context' => 'argument_entity_id:user_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(),
    ),
  );
  $display = new panels_display();
  $display->layout = 'salto_363';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-4',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'left',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-8',
      ),
    ),
  );
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
  $display->uuid = '126f277d-a40a-4050-87d8-b82e55e4e836';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'user_view_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b4a592cc-c5c6-47e9-8248-86b55d25b269';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_user_picture';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'medium',
      'image_link' => '',
    ),
    'context' => 'relationship_profile2_1',
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
  $pane->uuid = 'b4a592cc-c5c6-47e9-8248-86b55d25b269';
  $display->content['new-b4a592cc-c5c6-47e9-8248-86b55d25b269'] = $pane;
  $display->panels['left'][0] = 'new-b4a592cc-c5c6-47e9-8248-86b55d25b269';
  $pane = new stdClass();
  $pane->pid = 'new-c1b0a398-5d50-4fe1-9f37-87c33391bfc9';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_contact_phone';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->uuid = 'c1b0a398-5d50-4fe1-9f37-87c33391bfc9';
  $display->content['new-c1b0a398-5d50-4fe1-9f37-87c33391bfc9'] = $pane;
  $display->panels['left'][1] = 'new-c1b0a398-5d50-4fe1-9f37-87c33391bfc9';
  $pane = new stdClass();
  $pane->pid = 'new-d86f87e3-0f00-4e24-b9ac-e0c74c3dc93f';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_contact_email';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'd86f87e3-0f00-4e24-b9ac-e0c74c3dc93f';
  $display->content['new-d86f87e3-0f00-4e24-b9ac-e0c74c3dc93f'] = $pane;
  $display->panels['left'][2] = 'new-d86f87e3-0f00-4e24-b9ac-e0c74c3dc93f';
  $pane = new stdClass();
  $pane->pid = 'new-5c02ddb1-9954-454a-88d7-4418734df6b4';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_postal_address';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'addressfield_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'use_widget_handlers' => 1,
      'format_handlers' => array(
        'address' => 'address',
      ),
    ),
    'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '5c02ddb1-9954-454a-88d7-4418734df6b4';
  $display->content['new-5c02ddb1-9954-454a-88d7-4418734df6b4'] = $pane;
  $display->panels['left'][3] = 'new-5c02ddb1-9954-454a-88d7-4418734df6b4';
  $pane = new stdClass();
  $pane->pid = 'new-b00586be-5597-4ad9-8083-4807e6eb18c7';
  $pane->panel = 'middle';
  $pane->type = 'token';
  $pane->subtype = 'user:name';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'sanitize' => 1,
    'context' => 'argument_entity_id:user_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'h2',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b00586be-5597-4ad9-8083-4807e6eb18c7';
  $display->content['new-b00586be-5597-4ad9-8083-4807e6eb18c7'] = $pane;
  $display->panels['middle'][0] = 'new-b00586be-5597-4ad9-8083-4807e6eb18c7';
  $pane = new stdClass();
  $pane->pid = 'new-26603ef4-4161-471f-984d-f278e155284d';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_about_me';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->uuid = '26603ef4-4161-471f-984d-f278e155284d';
  $display->content['new-26603ef4-4161-471f-984d-f278e155284d'] = $pane;
  $display->panels['middle'][1] = 'new-26603ef4-4161-471f-984d-f278e155284d';
  $pane = new stdClass();
  $pane->pid = 'new-5e5806fa-0b64-4568-9bc3-acf6351422de';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_sports';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5e5806fa-0b64-4568-9bc3-acf6351422de';
  $display->content['new-5e5806fa-0b64-4568-9bc3-acf6351422de'] = $pane;
  $display->panels['middle'][2] = 'new-5e5806fa-0b64-4568-9bc3-acf6351422de';
  $pane = new stdClass();
  $pane->pid = 'new-49d12304-958c-415f-b20c-9083c5ed8260';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_interests';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '49d12304-958c-415f-b20c-9083c5ed8260';
  $display->content['new-49d12304-958c-415f-b20c-9083c5ed8260'] = $pane;
  $display->panels['middle'][3] = 'new-49d12304-958c-415f-b20c-9083c5ed8260';
  $pane = new stdClass();
  $pane->pid = 'new-516af269-f174-452b-8063-27491769cb76';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_competencies';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '516af269-f174-452b-8063-27491769cb76';
  $display->content['new-516af269-f174-452b-8063-27491769cb76'] = $pane;
  $display->panels['middle'][4] = 'new-516af269-f174-452b-8063-27491769cb76';
  $pane = new stdClass();
  $pane->pid = 'new-33137f8a-95d0-40aa-9934-db5791cd95ea';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Not Accepted legal',
    'title' => '',
    'body' => '<?php
print t("This user hasn\'t accepted the latest T&C yet. The profile details aren\'t available");
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '33137f8a-95d0-40aa-9934-db5791cd95ea';
  $display->content['new-33137f8a-95d0-40aa-9934-db5791cd95ea'] = $pane;
  $display->panels['middle'][5] = 'new-33137f8a-95d0-40aa-9934-db5791cd95ea';
  $pane = new stdClass();
  $pane->pid = 'new-d3345b17-b2a4-4109-9710-0eaeb9a80823';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'profile',
    'context' => array(
      0 => 'argument_entity_id:user_1',
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
  $pane->uuid = 'd3345b17-b2a4-4109-9710-0eaeb9a80823';
  $display->content['new-d3345b17-b2a4-4109-9710-0eaeb9a80823'] = $pane;
  $display->panels['right'][0] = 'new-d3345b17-b2a4-4109-9710-0eaeb9a80823';
  $pane = new stdClass();
  $pane->pid = 'new-6a6eda63-56ca-4d62-90ee-7b64a789ed16';
  $pane->panel = 'right';
  $pane->type = 'views';
  $pane->subtype = 'activities';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => 'argument_entity_id:user_1.uid',
    ),
    'override_title' => 0,
    'override_title_text' => '',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6a6eda63-56ca-4d62-90ee-7b64a789ed16';
  $display->content['new-6a6eda63-56ca-4d62-90ee-7b64a789ed16'] = $pane;
  $display->panels['right'][1] = 'new-6a6eda63-56ca-4d62-90ee-7b64a789ed16';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context_2'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function salto_user_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'people';
  $page->task = 'page';
  $page->admin_title = 'People';
  $page->admin_description = 'The main menue region for people and organisations';
  $page->path = 'people';
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
    'title' => 'People',
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
  $handler->name = 'page_people_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'people';
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
  $display->storage_id = 'page_people_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ad34dd5d-96b9-4c04-8bd0-05324c16a0be';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-people-directory';
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
  $pane->uuid = 'ad34dd5d-96b9-4c04-8bd0-05324c16a0be';
  $display->content['new-ad34dd5d-96b9-4c04-8bd0-05324c16a0be'] = $pane;
  $display->panels['left'][0] = 'new-ad34dd5d-96b9-4c04-8bd0-05324c16a0be';
  $pane = new stdClass();
  $pane->pid = 'new-f9d49fed-0ea7-4605-bc25-932aeb852b66';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f9d49fed-0ea7-4605-bc25-932aeb852b66';
  $display->content['new-f9d49fed-0ea7-4605-bc25-932aeb852b66'] = $pane;
  $display->panels['middle'][0] = 'new-f9d49fed-0ea7-4605-bc25-932aeb852b66';
  $pane = new stdClass();
  $pane->pid = 'new-c9586096-3697-4e6f-8170-6cfc11b172d0';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'people-directory';
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
  $pane->uuid = 'c9586096-3697-4e6f-8170-6cfc11b172d0';
  $display->content['new-c9586096-3697-4e6f-8170-6cfc11b172d0'] = $pane;
  $display->panels['middle'][1] = 'new-c9586096-3697-4e6f-8170-6cfc11b172d0';
  $pane = new stdClass();
  $pane->pid = 'new-4282dcc8-8d29-4d28-976a-4b1903f26727';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'people',
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
  $pane->uuid = '4282dcc8-8d29-4d28-976a-4b1903f26727';
  $display->content['new-4282dcc8-8d29-4d28-976a-4b1903f26727'] = $pane;
  $display->panels['right'][0] = 'new-4282dcc8-8d29-4d28-976a-4b1903f26727';
  $pane = new stdClass();
  $pane->pid = 'new-731ef170-2912-41eb-b05d-75c7521adb64';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'organisations-panel_pane_1';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'default',
  );
  $pane->css = array(
    'css_id' => 'people-org-pane-id',
    'css_class' => 'people-org-pane',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '731ef170-2912-41eb-b05d-75c7521adb64';
  $display->content['new-731ef170-2912-41eb-b05d-75c7521adb64'] = $pane;
  $display->panels['right'][1] = 'new-731ef170-2912-41eb-b05d-75c7521adb64';
  $pane = new stdClass();
  $pane->pid = 'new-1988d549-dfc7-48c1-9082-980eb73df2d6';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'people-online';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1988d549-dfc7-48c1-9082-980eb73df2d6';
  $display->content['new-1988d549-dfc7-48c1-9082-980eb73df2d6'] = $pane;
  $display->panels['right'][2] = 'new-1988d549-dfc7-48c1-9082-980eb73df2d6';
  $pane = new stdClass();
  $pane->pid = 'new-24d815fb-9c2c-436e-930a-a8c456f75e03';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'people-new';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '24d815fb-9c2c-436e-930a-a8c456f75e03';
  $display->content['new-24d815fb-9c2c-436e-930a-a8c456f75e03'] = $pane;
  $display->panels['right'][3] = 'new-24d815fb-9c2c-436e-930a-a8c456f75e03';
  $pane = new stdClass();
  $pane->pid = 'new-d7470369-0a8f-40ff-a4f8-5104a2036c52';
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
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'people-org-pane',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'd7470369-0a8f-40ff-a4f8-5104a2036c52';
  $display->content['new-d7470369-0a8f-40ff-a4f8-5104a2036c52'] = $pane;
  $display->panels['right'][4] = 'new-d7470369-0a8f-40ff-a4f8-5104a2036c52';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['people'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_activity';
  $page->task = 'page';
  $page->admin_title = 'User Activity';
  $page->admin_description = '';
  $page->path = 'user/%user/activity';
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
  $handler->name = 'page_user_activity_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'user_activity';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'default',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'user-profile',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Profile2 from user',
        'keyword' => 'profile2',
        'name' => 'profile2',
        'type' => 'main',
        'context' => 'argument_entity_id:user_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(),
    ),
  );
  $display = new panels_display();
  $display->layout = 'salto_363';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-4',
      ),
      'left' => array(
        'type' => 'region',
        'title' => 'left',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'col-md-8',
      ),
    ),
  );
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
  $display->title = 'Aktivitäten';
  $display->uuid = '126f277d-a40a-4050-87d8-b82e55e4e836';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_user_activity_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b4a592cc-c5c6-47e9-8248-86b55d25b269';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_user_picture';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'user_220x200',
      'image_link' => '',
    ),
    'context' => 'relationship_profile2_1',
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
  $pane->uuid = 'b4a592cc-c5c6-47e9-8248-86b55d25b269';
  $display->content['new-b4a592cc-c5c6-47e9-8248-86b55d25b269'] = $pane;
  $display->panels['left'][0] = 'new-b4a592cc-c5c6-47e9-8248-86b55d25b269';
  $pane = new stdClass();
  $pane->pid = 'new-a64fc1ed-906b-46c8-9f72-5f298dd3b767';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_contact_mobile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->uuid = 'a64fc1ed-906b-46c8-9f72-5f298dd3b767';
  $display->content['new-a64fc1ed-906b-46c8-9f72-5f298dd3b767'] = $pane;
  $display->panels['left'][1] = 'new-a64fc1ed-906b-46c8-9f72-5f298dd3b767';
  $pane = new stdClass();
  $pane->pid = 'new-c1b0a398-5d50-4fe1-9f37-87c33391bfc9';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_contact_phone';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'c1b0a398-5d50-4fe1-9f37-87c33391bfc9';
  $display->content['new-c1b0a398-5d50-4fe1-9f37-87c33391bfc9'] = $pane;
  $display->panels['left'][2] = 'new-c1b0a398-5d50-4fe1-9f37-87c33391bfc9';
  $pane = new stdClass();
  $pane->pid = 'new-d86f87e3-0f00-4e24-b9ac-e0c74c3dc93f';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_contact_email';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'relationship_profile2_1',
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'd86f87e3-0f00-4e24-b9ac-e0c74c3dc93f';
  $display->content['new-d86f87e3-0f00-4e24-b9ac-e0c74c3dc93f'] = $pane;
  $display->panels['left'][3] = 'new-d86f87e3-0f00-4e24-b9ac-e0c74c3dc93f';
  $pane = new stdClass();
  $pane->pid = 'new-5c02ddb1-9954-454a-88d7-4418734df6b4';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'profile2:field_profile_postal_address';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'addressfield_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'use_widget_handlers' => 1,
      'format_handlers' => array(
        'address' => 'address',
      ),
    ),
    'context' => 'relationship_entity_from_schema:uid-user-profile2_1',
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '5c02ddb1-9954-454a-88d7-4418734df6b4';
  $display->content['new-5c02ddb1-9954-454a-88d7-4418734df6b4'] = $pane;
  $display->panels['left'][4] = 'new-5c02ddb1-9954-454a-88d7-4418734df6b4';
  $pane = new stdClass();
  $pane->pid = 'new-b00586be-5597-4ad9-8083-4807e6eb18c7';
  $pane->panel = 'middle';
  $pane->type = 'token';
  $pane->subtype = 'user:name';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'sanitize' => 1,
    'context' => 'argument_entity_id:user_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'h2',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b00586be-5597-4ad9-8083-4807e6eb18c7';
  $display->content['new-b00586be-5597-4ad9-8083-4807e6eb18c7'] = $pane;
  $display->panels['middle'][0] = 'new-b00586be-5597-4ad9-8083-4807e6eb18c7';
  $pane = new stdClass();
  $pane->pid = 'new-93edc6af-e902-474f-a78a-bdd7f6b64328';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'heartbeat_useractivity-panel_heartbeat_useractivity';
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
  $pane->uuid = '93edc6af-e902-474f-a78a-bdd7f6b64328';
  $display->content['new-93edc6af-e902-474f-a78a-bdd7f6b64328'] = $pane;
  $display->panels['middle'][1] = 'new-93edc6af-e902-474f-a78a-bdd7f6b64328';
  $pane = new stdClass();
  $pane->pid = 'new-6a6eda63-56ca-4d62-90ee-7b64a789ed16';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'activities';
  $pane->shown = FALSE;
  $pane->access = array(
    'logic' => 'and',
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block_1',
    'context' => array(
      0 => 'argument_entity_id:user_1.uid',
    ),
    'override_title' => 0,
    'override_title_text' => '',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6a6eda63-56ca-4d62-90ee-7b64a789ed16';
  $display->content['new-6a6eda63-56ca-4d62-90ee-7b64a789ed16'] = $pane;
  $display->panels['middle'][2] = 'new-6a6eda63-56ca-4d62-90ee-7b64a789ed16';
  $pane = new stdClass();
  $pane->pid = 'new-d3345b17-b2a4-4109-9710-0eaeb9a80823';
  $pane->panel = 'right';
  $pane->type = 'action_links';
  $pane->subtype = 'action_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'profile',
    'context' => array(
      0 => 'argument_entity_id:user_1',
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
  $pane->uuid = 'd3345b17-b2a4-4109-9710-0eaeb9a80823';
  $display->content['new-d3345b17-b2a4-4109-9710-0eaeb9a80823'] = $pane;
  $display->panels['right'][0] = 'new-d3345b17-b2a4-4109-9710-0eaeb9a80823';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_activity'] = $page;

  return $pages;

}
