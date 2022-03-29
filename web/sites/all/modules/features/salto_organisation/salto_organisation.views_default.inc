<?php

/**
 * @file
 * salto_organisation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function salto_organisation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_organisations';
  $view->description = 'Show groups of a user.';
  $view->tag = 'og';
  $view->base_table = 'og_membership';
  $view->human_name = 'My Organisations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Meine Organisationen';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'state' => 'state',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Gehört noch keiner Organisation an.';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Field: OG membership: Rendered OG membership */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_og_membership';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'membership_compact';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: OG membership: Funktion */
  $handler->display->display_options['fields']['field_organisation_position']['id'] = 'field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['table'] = 'field_data_field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['field'] = 'field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['delta_offset'] = '0';
  /* Contextual filter: We pass the user ID as the Entity ID. */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['ui_name'] = 'We pass the user ID as the Entity ID.';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['etid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['etid']['validate']['type'] = 'user';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'Panel-Ansichten';
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'We pass to the &quot;Entity ID&quot; the User ID.',
    ),
  );

  /* Display: Meine Organisatinen (Übersicht) */
  $handler = $view->new_display('panel_pane', 'Meine Organisatinen (Übersicht)', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: OG membership: Rendered OG membership */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_og_membership';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'membership_compact';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: OG membership: Funktion */
  $handler->display->display_options['fields']['field_organisation_position']['id'] = 'field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['table'] = 'field_data_field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['field'] = 'field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_organisation_position']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['pane_title'] = 'my organisations overview';
  $handler->display->display_options['pane_description'] = 'People, Groups';
  $handler->display->display_options['pane_category']['name'] = '1';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'We pass to the &quot;Entity ID&quot; the User ID.',
    ),
  );
  $translatables['my_organisations'] = array(
    t('Master'),
    t('Meine Organisationen'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Gehört noch keiner Organisation an.'),
    t('Rendered OG membership'),
    t('Funktion'),
    t('Alle'),
    t('Content pane'),
    t('more'),
    t('Panel-Ansichten'),
    t('Meine Organisatinen (Übersicht)'),
    t('Group node from OG membership'),
    t('my organisations overview'),
    t('People, Groups'),
    t('1'),
  );
  $export['my_organisations'] = $view;

  $view = new view();
  $view->name = 'my_organisations_people_pane';
  $view->description = 'Show groups of a user.';
  $view->tag = 'og';
  $view->base_table = 'og_membership';
  $view->human_name = 'my_organisations_people_pane';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Meine Organisationen';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Gehört noch keiner Organisation an.';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Contextual filter: We pass the user ID as the Entity ID. */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['ui_name'] = 'We pass the user ID as the Entity ID.';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['etid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['etid']['validate']['type'] = 'user';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );
  /* Filter criterion: OG membership: Entity_type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'user';

  /* Display: Sidebar */
  $handler = $view->new_display('panel_pane', 'Sidebar', 'panel_pane_2');
  $handler->display->display_options['pane_title'] = 'my organisations sidebar';
  $handler->display->display_options['pane_description'] = 'Sidebar on "people"';
  $handler->display->display_options['pane_category']['name'] = 'Organisationen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'We pass to the &quot;Entity ID&quot; the User ID.',
    ),
  );

  /* Display: Volle Anzeige auf Panel */
  $handler = $view->new_display('panel_pane', 'Volle Anzeige auf Panel', 'panel_pane_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['pane_title'] = 'my organisations overview';
  $handler->display->display_options['pane_description'] = 'Full listing on organisations/!uid';
  $handler->display->display_options['pane_category']['name'] = 'Organisationen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'We pass to the &quot;Entity ID&quot; the User ID.',
    ),
  );
  $translatables['my_organisations_people_pane'] = array(
    t('Master'),
    t('Meine Organisationen'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Gehört noch keiner Organisation an.'),
    t('Group node from OG membership'),
    t('Alle'),
    t('Sidebar'),
    t('more'),
    t('my organisations sidebar'),
    t('Sidebar on "people"'),
    t('Organisationen'),
    t('Volle Anzeige auf Panel'),
    t('my organisations overview'),
    t('Full listing on organisations/!uid'),
  );
  $export['my_organisations_people_pane'] = $view;

  $view = new view();
  $view->name = 'organisation_invites';
  $view->description = 'A list of all salto_invites';
  $view->tag = 'salto_invites';
  $view->base_table = 'salto_invite';
  $view->human_name = 'Invites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Einladungen (Neue Personen)';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'og_context';
  $handler->display->display_options['access']['perm'] = 'invite existing users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '4';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['content'] = 'Es gibt im Moment keine Einladungen.';
  /* Field: Salto Invite: Salto invite ID */
  $handler->display->display_options['fields']['salto_invite_id']['id'] = 'salto_invite_id';
  $handler->display->display_options['fields']['salto_invite_id']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['salto_invite_id']['field'] = 'salto_invite_id';
  /* Field: Field: Nachname */
  $handler->display->display_options['fields']['field_profile_name_last']['id'] = 'field_profile_name_last';
  $handler->display->display_options['fields']['field_profile_name_last']['table'] = 'field_data_field_profile_name_last';
  $handler->display->display_options['fields']['field_profile_name_last']['field'] = 'field_profile_name_last';
  /* Field: Field: Vorname */
  $handler->display->display_options['fields']['field_profile_name_first']['id'] = 'field_profile_name_first';
  $handler->display->display_options['fields']['field_profile_name_first']['table'] = 'field_data_field_profile_name_first';
  $handler->display->display_options['fields']['field_profile_name_first']['field'] = 'field_profile_name_first';
  /* Field: Field: E-mail */
  $handler->display->display_options['fields']['field_profile_contact_email']['id'] = 'field_profile_contact_email';
  $handler->display->display_options['fields']['field_profile_contact_email']['table'] = 'field_data_field_profile_contact_email';
  $handler->display->display_options['fields']['field_profile_contact_email']['field'] = 'field_profile_contact_email';
  $handler->display->display_options['fields']['field_profile_contact_email']['label'] = 'E-Mail';
  /* Field: Salto Invite: Code */
  $handler->display->display_options['fields']['code']['id'] = 'code';
  $handler->display->display_options['fields']['code']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['code']['field'] = 'code';
  /* Field: Salto Invite: Link */
  $handler->display->display_options['fields']['link_salto_invite']['id'] = 'link_salto_invite';
  $handler->display->display_options['fields']['link_salto_invite']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['link_salto_invite']['field'] = 'link_salto_invite';
  $handler->display->display_options['fields']['link_salto_invite']['label'] = 'Ansicht';
  /* Field: Salto Invite: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  /* Contextual filter: Salto Invite: OG (field_salto_invite_og) */
  $handler->display->display_options['arguments']['field_salto_invite_og_target_id']['id'] = 'field_salto_invite_og_target_id';
  $handler->display->display_options['arguments']['field_salto_invite_og_target_id']['table'] = 'field_data_field_salto_invite_og';
  $handler->display->display_options['arguments']['field_salto_invite_og_target_id']['field'] = 'field_salto_invite_og_target_id';
  $handler->display->display_options['arguments']['field_salto_invite_og_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_salto_invite_og_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_salto_invite_og_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_salto_invite_og_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_salto_invite_og_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_salto_invite_og_target_id']['summary_options']['items_per_page'] = '25';

  /* Display: Invite by og */
  $handler = $view->new_display('panel_pane', 'Invite by og', 'panel_pane_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: OG membership: Group Salto Invite from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_salto_invite_group']['id'] = 'og_membership_related_salto_invite_group';
  $handler->display->display_options['relationships']['og_membership_related_salto_invite_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_salto_invite_group']['field'] = 'og_membership_related_salto_invite_group';
  /* Relationship: OG membership: Salto Invite from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_salto_invite']['id'] = 'og_membership_related_salto_invite';
  $handler->display->display_options['relationships']['og_membership_related_salto_invite']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_salto_invite']['field'] = 'og_membership_related_salto_invite';
  $handler->display->display_options['relationships']['og_membership_related_salto_invite']['relationship'] = 'og_membership_related_salto_invite_group';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Salto Invite: Salto invite ID */
  $handler->display->display_options['fields']['salto_invite_id']['id'] = 'salto_invite_id';
  $handler->display->display_options['fields']['salto_invite_id']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['salto_invite_id']['field'] = 'salto_invite_id';
  $handler->display->display_options['fields']['salto_invite_id']['label'] = 'Salto einladung ID';
  $handler->display->display_options['fields']['salto_invite_id']['exclude'] = TRUE;
  /* Field: Field: Nachname */
  $handler->display->display_options['fields']['field_profile_name_last']['id'] = 'field_profile_name_last';
  $handler->display->display_options['fields']['field_profile_name_last']['table'] = 'field_data_field_profile_name_last';
  $handler->display->display_options['fields']['field_profile_name_last']['field'] = 'field_profile_name_last';
  $handler->display->display_options['fields']['field_profile_name_last']['exclude'] = TRUE;
  /* Field: Field: Vorname */
  $handler->display->display_options['fields']['field_profile_name_first']['id'] = 'field_profile_name_first';
  $handler->display->display_options['fields']['field_profile_name_first']['table'] = 'field_data_field_profile_name_first';
  $handler->display->display_options['fields']['field_profile_name_first']['field'] = 'field_profile_name_first';
  $handler->display->display_options['fields']['field_profile_name_first']['exclude'] = TRUE;
  /* Field: Field: E-mail */
  $handler->display->display_options['fields']['field_profile_contact_email']['id'] = 'field_profile_contact_email';
  $handler->display->display_options['fields']['field_profile_contact_email']['table'] = 'field_data_field_profile_contact_email';
  $handler->display->display_options['fields']['field_profile_contact_email']['field'] = 'field_profile_contact_email';
  $handler->display->display_options['fields']['field_profile_contact_email']['label'] = 'E-Mail';
  $handler->display->display_options['fields']['field_profile_contact_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_contact_email']['alter']['text'] = '<span title="[field_profile_contact_email-value] ">[field_profile_contact_email-format]</span>';
  $handler->display->display_options['fields']['field_profile_contact_email']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['field_profile_contact_email']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_profile_contact_email']['alter']['html'] = TRUE;
  /* Field: Salto Invite: Code */
  $handler->display->display_options['fields']['code']['id'] = 'code';
  $handler->display->display_options['fields']['code']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['code']['field'] = 'code';
  $handler->display->display_options['fields']['code']['exclude'] = TRUE;
  /* Field: Salto Invite: Used */
  $handler->display->display_options['fields']['used']['id'] = 'used';
  $handler->display->display_options['fields']['used']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['used']['field'] = 'used';
  $handler->display->display_options['fields']['used']['label'] = '';
  $handler->display->display_options['fields']['used']['exclude'] = TRUE;
  $handler->display->display_options['fields']['used']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['used']['not'] = 0;
  /* Field: Salto Invite: Resend invite Link */
  $handler->display->display_options['fields']['link_salto_resend_invite']['id'] = 'link_salto_resend_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['field'] = 'link_salto_resend_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['relationship'] = 'og_membership_related_salto_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['link_salto_resend_invite']['exclude'] = TRUE;
  $handler->display->display_options['fields']['link_salto_resend_invite']['text'] = 'Erneut versenden';
  $handler->display->display_options['fields']['link_salto_resend_invite']['css_primary_button'] = 1;
  /* Field: Salto Invite: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-12">
<div class="row">
<div class="col-md-7">
  <div class="groups-members-name"><b>[field_profile_name_first] [field_profile_name_last]</b></div>
 <div class="groups-members-name">[field_profile_contact_email]</div>
 <div class="groups-members-name">[created]</div>
</div>
<div class="col-md-5">[link_salto_resend_invite] </div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Salto Invite: Used */
  $handler->display->display_options['filters']['used']['id'] = 'used';
  $handler->display->display_options['filters']['used']['table'] = 'salto_invite';
  $handler->display->display_options['filters']['used']['field'] = 'used';
  $handler->display->display_options['filters']['used']['value'] = '0';
  $handler->display->display_options['pane_title'] = 'Organisationen: Einladungen';
  $handler->display->display_options['pane_category']['name'] = 'Organisationen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG Mitgliedschaft: Gruppen-ID',
    ),
  );

  /* Display: Accept invites by og */
  $handler = $view->new_display('panel_pane', 'Accept invites by og', 'invite_by_og');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Einladungen (Bestehende Personen)';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_salto_invite_account_target_id']['id'] = 'field_salto_invite_account_target_id';
  $handler->display->display_options['relationships']['field_salto_invite_account_target_id']['table'] = 'field_data_field_salto_invite_account';
  $handler->display->display_options['relationships']['field_salto_invite_account_target_id']['field'] = 'field_salto_invite_account_target_id';
  $handler->display->display_options['relationships']['field_salto_invite_account_target_id']['required'] = TRUE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'field_salto_invite_account_target_id';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profilbild */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'user_30x30',
    'image_link' => 'content',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_salto_invite_account_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Salto Invite: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '<em>Eingeladen am [created]</em> ';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Salto Invite: Resend invite Link */
  $handler->display->display_options['fields']['link_salto_resend_invite']['id'] = 'link_salto_resend_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['field'] = 'link_salto_resend_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['label'] = '';
  $handler->display->display_options['fields']['link_salto_resend_invite']['exclude'] = TRUE;
  $handler->display->display_options['fields']['link_salto_resend_invite']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['link_salto_resend_invite']['text'] = 'Erneut versenden';
  $handler->display->display_options['fields']['link_salto_resend_invite']['css_primary_button'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-12">
<div class="row">
<div class="col-md-2">[field_user_picture] </div>
<div class="col-md-6">
  <div class="groups-members-name">[name]</div>
</div>
<div class="col-md-4">[link_salto_resend_invite] </div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['pane_title'] = 'Invites: Accept Invites by og';
  $handler->display->display_options['pane_category']['name'] = 'OG People';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_salto_invite_og_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Salto Einladung: OG (field_salto_invite_og)',
    ),
  );

  /* Display: Accept invites by og and uid */
  $handler = $view->new_display('panel_pane', 'Accept invites by og and uid', 'invite_by_og_and_uid');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Salto Invite: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'salto_invite';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['label'] = 'Inviter';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'user';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_salto_invite_account_target_id']['id'] = 'field_salto_invite_account_target_id';
  $handler->display->display_options['relationships']['field_salto_invite_account_target_id']['table'] = 'field_data_field_salto_invite_account';
  $handler->display->display_options['relationships']['field_salto_invite_account_target_id']['field'] = 'field_salto_invite_account_target_id';
  $handler->display->display_options['relationships']['field_salto_invite_account_target_id']['label'] = 'Invited User';
  $handler->display->display_options['relationships']['field_salto_invite_account_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profilbild */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'user_30x30',
    'image_link' => 'content',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Salto Invite: Invite message */
  $handler->display->display_options['fields']['salto_invite_message']['id'] = 'salto_invite_message';
  $handler->display->display_options['fields']['salto_invite_message']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['salto_invite_message']['field'] = 'salto_invite_message';
  $handler->display->display_options['fields']['salto_invite_message']['label'] = '';
  $handler->display->display_options['fields']['salto_invite_message']['element_label_colon'] = FALSE;
  /* Field: Salto Invite: Accept/Decline invite links */
  $handler->display->display_options['fields']['acccept_salto_invite']['id'] = 'acccept_salto_invite';
  $handler->display->display_options['fields']['acccept_salto_invite']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['acccept_salto_invite']['field'] = 'acccept_salto_invite';
  $handler->display->display_options['fields']['acccept_salto_invite']['label'] = '';
  $handler->display->display_options['fields']['acccept_salto_invite']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'field_salto_invite_account_target_id';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['pane_title'] = 'Invites: My Accept Invites by og';
  $handler->display->display_options['pane_category']['name'] = 'OG People';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_salto_invite_og_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Salto Einladung: OG (field_salto_invite_og)',
    ),
  );

  /* Display: Accept invites by uid */
  $handler = $view->new_display('panel_pane', 'Accept invites by uid', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Meine Einladungen';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Salto Invite: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'salto_invite';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['label'] = 'Inviter';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'user';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_salto_invite_og_target_id']['id'] = 'field_salto_invite_og_target_id';
  $handler->display->display_options['relationships']['field_salto_invite_og_target_id']['table'] = 'field_data_field_salto_invite_og';
  $handler->display->display_options['relationships']['field_salto_invite_og_target_id']['field'] = 'field_salto_invite_og_target_id';
  $handler->display->display_options['relationships']['field_salto_invite_og_target_id']['label'] = 'OG';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_salto_invite_og_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Salto Invite: Accept/Decline invite links */
  $handler->display->display_options['fields']['acccept_salto_invite']['id'] = 'acccept_salto_invite';
  $handler->display->display_options['fields']['acccept_salto_invite']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['acccept_salto_invite']['field'] = 'acccept_salto_invite';
  $handler->display->display_options['fields']['acccept_salto_invite']['label'] = '';
  $handler->display->display_options['fields']['acccept_salto_invite']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Salto Invite: Account (field_salto_invite_account) */
  $handler->display->display_options['arguments']['field_salto_invite_account_target_id']['id'] = 'field_salto_invite_account_target_id';
  $handler->display->display_options['arguments']['field_salto_invite_account_target_id']['table'] = 'field_data_field_salto_invite_account';
  $handler->display->display_options['arguments']['field_salto_invite_account_target_id']['field'] = 'field_salto_invite_account_target_id';
  $handler->display->display_options['arguments']['field_salto_invite_account_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_salto_invite_account_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_salto_invite_account_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_salto_invite_account_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_salto_invite_account_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_salto_invite_account_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Salto Invite: Used */
  $handler->display->display_options['filters']['used']['id'] = 'used';
  $handler->display->display_options['filters']['used']['table'] = 'salto_invite';
  $handler->display->display_options['filters']['used']['field'] = 'used';
  $handler->display->display_options['filters']['used']['value'] = '0';
  $handler->display->display_options['pane_title'] = 'Invites: My Accept Invites (all and unsed)';
  $handler->display->display_options['pane_category']['name'] = 'OG People';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_salto_invite_account_target_id' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Salto Einladung: Account (field_salto_invite_account)',
    ),
  );

  /* Display: Organisation invites by group */
  $handler = $view->new_display('panel_pane', 'Organisation invites by group', 'panel_pane_3');
  $handler->display->display_options['display_description'] = 'New user invite blocks that where invited via group';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Salto Invite: Organisations */
  $handler->display->display_options['fields']['field_salto_invite_organisations']['id'] = 'field_salto_invite_organisations';
  $handler->display->display_options['fields']['field_salto_invite_organisations']['table'] = 'og_membership';
  $handler->display->display_options['fields']['field_salto_invite_organisations']['field'] = 'field_salto_invite_organisations';
  $handler->display->display_options['fields']['field_salto_invite_organisations']['label'] = '';
  $handler->display->display_options['fields']['field_salto_invite_organisations']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_salto_invite_organisations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_salto_invite_organisations']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_salto_invite_organisations']['delta_offset'] = '0';
  /* Field: Field: Nachname */
  $handler->display->display_options['fields']['field_profile_name_last']['id'] = 'field_profile_name_last';
  $handler->display->display_options['fields']['field_profile_name_last']['table'] = 'field_data_field_profile_name_last';
  $handler->display->display_options['fields']['field_profile_name_last']['field'] = 'field_profile_name_last';
  $handler->display->display_options['fields']['field_profile_name_last']['label'] = '';
  $handler->display->display_options['fields']['field_profile_name_last']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_name_last']['element_label_colon'] = FALSE;
  /* Field: Field: Vorname */
  $handler->display->display_options['fields']['field_profile_name_first']['id'] = 'field_profile_name_first';
  $handler->display->display_options['fields']['field_profile_name_first']['table'] = 'field_data_field_profile_name_first';
  $handler->display->display_options['fields']['field_profile_name_first']['field'] = 'field_profile_name_first';
  $handler->display->display_options['fields']['field_profile_name_first']['label'] = '';
  $handler->display->display_options['fields']['field_profile_name_first']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_name_first']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_name_first']['alter']['text'] = '[field_profile_name_first] [field_profile_name_last] ([field_salto_invite_organisations] )';
  $handler->display->display_options['fields']['field_profile_name_first']['element_label_colon'] = FALSE;
  /* Field: Salto Invite: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '<em>Eingeladen am [created]</em> ';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Field: E-mail */
  $handler->display->display_options['fields']['field_profile_contact_email']['id'] = 'field_profile_contact_email';
  $handler->display->display_options['fields']['field_profile_contact_email']['table'] = 'field_data_field_profile_contact_email';
  $handler->display->display_options['fields']['field_profile_contact_email']['field'] = 'field_profile_contact_email';
  $handler->display->display_options['fields']['field_profile_contact_email']['label'] = '';
  $handler->display->display_options['fields']['field_profile_contact_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_contact_email']['element_label_colon'] = FALSE;
  /* Field: Salto Invite: Edit Link */
  $handler->display->display_options['fields']['edit_salto_invite']['id'] = 'edit_salto_invite';
  $handler->display->display_options['fields']['edit_salto_invite']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['edit_salto_invite']['field'] = 'edit_salto_invite';
  $handler->display->display_options['fields']['edit_salto_invite']['label'] = '';
  $handler->display->display_options['fields']['edit_salto_invite']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_salto_invite']['element_label_colon'] = FALSE;
  /* Field: Salto Invite: Resend invite Link */
  $handler->display->display_options['fields']['link_salto_resend_invite']['id'] = 'link_salto_resend_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['field'] = 'link_salto_resend_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['label'] = '';
  $handler->display->display_options['fields']['link_salto_resend_invite']['exclude'] = TRUE;
  $handler->display->display_options['fields']['link_salto_resend_invite']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['link_salto_resend_invite']['text'] = 'Erneut versenden';
  $handler->display->display_options['fields']['link_salto_resend_invite']['css_primary_button'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="col-md-12">
<div class="row">
<div class="col-md-2">-</div>
<div class="col-md-6">
  <div class="groups-members-name"><b>[field_profile_name_first]</b></div>
 <div class="groups-members-name">[field_profile_contact_email]</div>
 <div class="groups-members-name">[created]</div>
</div>
<div class="col-md-4">[link_salto_resend_invite] </div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Salto Invite: Groups (field_salto_invite_groups) */
  $handler->display->display_options['arguments']['field_salto_invite_groups_target_id']['id'] = 'field_salto_invite_groups_target_id';
  $handler->display->display_options['arguments']['field_salto_invite_groups_target_id']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['field_salto_invite_groups_target_id']['field'] = 'field_salto_invite_groups_target_id';
  $handler->display->display_options['arguments']['field_salto_invite_groups_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_salto_invite_groups_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_salto_invite_groups_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_salto_invite_groups_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_salto_invite_groups_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_salto_invite_groups_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Salto Invite: Used */
  $handler->display->display_options['filters']['used']['id'] = 'used';
  $handler->display->display_options['filters']['used']['table'] = 'salto_invite';
  $handler->display->display_options['filters']['used']['field'] = 'used';
  $handler->display->display_options['filters']['used']['value'] = '0';
  $handler->display->display_options['pane_title'] = 'Invites: Organisation Invites by group';
  $handler->display->display_options['pane_category']['name'] = 'OG People';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_salto_invite_groups_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Salto Einladung: Groups (field_salto_invite_groups)',
    ),
  );
  $translatables['organisation_invites'] = array(
    t('Master'),
    t('Einladungen (Neue Personen)'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Empty '),
    t('Es gibt im Moment keine Einladungen.'),
    t('Salto invite ID'),
    t('.'),
    t(','),
    t('Nachname'),
    t('Vorname'),
    t('E-Mail'),
    t('Code'),
    t('Ansicht'),
    t('Operations links'),
    t('Alle'),
    t('Invite by og'),
    t('more'),
    t('Group salto_invite from OG membership'),
    t('salto_invite from OG membership'),
    t('Salto einladung ID'),
    t('<span title="[field_profile_contact_email-value] ">[field_profile_contact_email-format]</span>'),
    t('Aktionen'),
    t('Erneut versenden'),
    t('<div class="col-md-12">
<div class="row">
<div class="col-md-7">
  <div class="groups-members-name"><b>[field_profile_name_first] [field_profile_name_last]</b></div>
 <div class="groups-members-name">[field_profile_contact_email]</div>
 <div class="groups-members-name">[created]</div>
</div>
<div class="col-md-5">[link_salto_resend_invite] </div>
</div>
</div>'),
    t('Organisationen: Einladungen'),
    t('Organisationen'),
    t('Accept invites by og'),
    t('Einladungen (Bestehende Personen)'),
    t('User entity referenced from field_salto_invite_account'),
    t('Profile'),
    t('<em>Eingeladen am [created]</em> '),
    t('<div class="col-md-12">
<div class="row">
<div class="col-md-2">[field_user_picture] </div>
<div class="col-md-6">
  <div class="groups-members-name">[name]</div>
</div>
<div class="col-md-4">[link_salto_resend_invite] </div>
</div>
</div>'),
    t('Invites: Accept Invites by og'),
    t('OG People'),
    t('Accept invites by og and uid'),
    t('Inviter'),
    t('Invited User'),
    t('Invites: My Accept Invites by og'),
    t('Accept invites by uid'),
    t('Meine Einladungen'),
    t('OG'),
    t('Invites: My Accept Invites (all and unsed)'),
    t('Organisation invites by group'),
    t('New user invite blocks that where invited via group'),
    t('[field_profile_name_first] [field_profile_name_last] ([field_salto_invite_organisations] )'),
    t('<div class="col-md-12">
<div class="row">
<div class="col-md-2">-</div>
<div class="col-md-6">
  <div class="groups-members-name"><b>[field_profile_name_first]</b></div>
 <div class="groups-members-name">[field_profile_contact_email]</div>
 <div class="groups-members-name">[created]</div>
</div>
<div class="col-md-4">[link_salto_resend_invite] </div>
</div>
</div>'),
    t('Invites: Organisation Invites by group'),
  );
  $export['organisation_invites'] = $view;

  $view = new view();
  $view->name = 'organisation_members';
  $view->description = 'Memberships of an organisation';
  $view->tag = 'salto,organisations';
  $view->base_table = 'og_membership';
  $view->human_name = 'Organisation: Memberships';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_organisation_position' => 'field_organisation_position',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organisation_position' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: OG membership: User from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_user']['id'] = 'og_membership_related_user';
  $handler->display->display_options['relationships']['og_membership_related_user']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_user']['field'] = 'og_membership_related_user';
  $handler->display->display_options['relationships']['og_membership_related_user']['label'] = 'Benutzer';
  $handler->display->display_options['relationships']['og_membership_related_user']['required'] = TRUE;
  /* Relationship: OG membership: Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node']['id'] = 'og_membership_related_node';
  $handler->display->display_options['relationships']['og_membership_related_node']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node']['field'] = 'og_membership_related_node';
  $handler->display->display_options['relationships']['og_membership_related_node']['label'] = 'Organisation Node';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'user_small';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'og_membership_related_user';
  /* Field: OG membership: Funktion */
  $handler->display->display_options['fields']['field_organisation_position']['id'] = 'field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['table'] = 'field_data_field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['field'] = 'field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['delta_offset'] = '0';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';

  /* Display: Overview */
  $handler = $view->new_display('panel_pane', 'Overview', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'can be accessed by all users';
  $handler->display->display_options['pane_title'] = 'Membership list ';
  $handler->display->display_options['pane_category']['name'] = 'Organisationen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
  );

  /* Display: Admin */
  $handler = $view->new_display('panel_pane', 'Admin', 'panel_pane_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: OG membership */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_og_membership';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::og_set_state_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::og_user_roles_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::og_membership_delete_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: OG membership: Group ID */
  $handler->display->display_options['fields']['gid']['id'] = 'gid';
  $handler->display->display_options['fields']['gid']['table'] = 'og_membership';
  $handler->display->display_options['fields']['gid']['field'] = 'gid';
  $handler->display->display_options['fields']['gid']['label'] = '';
  $handler->display->display_options['fields']['gid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['gid']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'user_30x30';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'og_membership_related_user';
  /* Field: OG membership: Funktion */
  $handler->display->display_options['fields']['field_organisation_position']['id'] = 'field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['table'] = 'field_data_field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['field'] = 'field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['delta_offset'] = '0';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$membership = entity_load_single(\'og_membership\', $data->id);
print drupal_render(salto_organisation_edit_membership_link($data->og_membership_gid, $membership));?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['pane_title'] = 'Membership admin';
  $handler->display->display_options['pane_category']['name'] = 'Organisationen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'user',
      'context' => 'entity:search_api_autocomplete_search.name',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG Mitgliedschaft: Gruppen-ID',
    ),
  );
  $translatables['organisation_members'] = array(
    t('Master'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Benutzer'),
    t('Organisation Node'),
    t('Name'),
    t('Funktion'),
    t('Alle'),
    t('Overview'),
    t('can be accessed by all users'),
    t('more'),
    t('Membership list '),
    t('Organisationen'),
    t('Admin'),
    t('- Choose an operation -'),
    t('.'),
    t(','),
    t('Membership admin'),
  );
  $export['organisation_members'] = $view;

  $view = new view();
  $view->name = 'organisations';
  $view->description = 'Views for organisation listing';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'organisations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );

  /* Display: Random organisations */
  $handler = $view->new_display('panel_pane', 'Random organisations', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Weitere Organisationen';
  $handler->display->display_options['display_description'] = 'new organisations block on people';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/organisations">Alle Organisationen</a>';
  $handler->display->display_options['footer']['area']['format'] = 'editor';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['pane_title'] = 'Random organisations';
  $handler->display->display_options['pane_category']['name'] = 'Organisationen';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: DOSB Overview */
  $handler = $view->new_display('panel_pane', 'DOSB Overview', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );
  /* Filter criterion: Content: Dachorganisation (field_organisation_parent) */
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['id'] = 'field_organisation_parent_target_id';
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['field'] = 'field_organisation_parent_target_id';
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['operator'] = 'empty';
  $handler->display->display_options['pane_title'] = 'DOSB Overview';
  $handler->display->display_options['pane_category']['name'] = 'Organisationen';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Child organisations */
  $handler = $view->new_display('panel_pane', 'Child organisations', 'child_organisations');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Untergliederungen';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ ';
  $handler->display->display_options['pager']['options']['tags']['next'] = ' ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Diese Organisation hat keine Untergliederung.';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Child organisations';
  $handler->display->display_options['pane_category']['name'] = 'Organisationen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG Mitgliedschaft: Gruppen-ID',
    ),
  );

  /* Display: Organisations by EA */
  $handler = $view->new_display('panel_pane', 'Organisations by EA', 'pane_organisations_by_ea');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'php' => 'php',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Verbände nutzen diesen Ausbildungsgang';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_organisation_earemotes_target_id']['id'] = 'field_organisation_earemotes_target_id';
  $handler->display->display_options['relationships']['field_organisation_earemotes_target_id']['table'] = 'field_data_field_organisation_earemotes';
  $handler->display->display_options['relationships']['field_organisation_earemotes_target_id']['field'] = 'field_organisation_earemotes_target_id';
  $handler->display->display_options['relationships']['field_organisation_earemotes_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$organisation = node_load($row->nid);
$eas = _knowledgebase_get_educoncepts_by_organisation($organisation );
echo _knowledgebase_render_earemotes_organisations($eas);

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="/node/[nid]" title="[title]">[title]</a> [php]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Ausbildungsgänge (field_organisation_earemotes) */
  $handler->display->display_options['arguments']['field_organisation_earemotes_target_id']['id'] = 'field_organisation_earemotes_target_id';
  $handler->display->display_options['arguments']['field_organisation_earemotes_target_id']['table'] = 'field_data_field_organisation_earemotes';
  $handler->display->display_options['arguments']['field_organisation_earemotes_target_id']['field'] = 'field_organisation_earemotes_target_id';
  $handler->display->display_options['arguments']['field_organisation_earemotes_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_organisation_earemotes_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_organisation_earemotes_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_organisation_earemotes_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_organisation_earemotes_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_organisation_earemotes_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Organisations by EA';
  $handler->display->display_options['pane_category']['name'] = 'Organisationen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'field_organisation_earemotes_target_id' => array(
      'type' => 'user',
      'context' => 'entity:clients_connection.configuration',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Ausbildungsgänge (field_organisation_earemotes)',
    ),
  );

  /* Display: Child organisations commalist */
  $handler = $view->new_display('panel_pane', 'Child organisations commalist', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Untergliederungen';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Child organisations';
  $handler->display->display_options['pane_category']['name'] = 'Organisationen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG Mitgliedschaft: Gruppen-ID',
    ),
  );
  $translatables['organisations'] = array(
    t('Master'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Name'),
    t('Random organisations'),
    t('Weitere Organisationen'),
    t('new organisations block on people'),
    t('more'),
    t('<a href="/organisations">Alle Organisationen</a>'),
    t('Organisationen'),
    t('DOSB Overview'),
    t('Child organisations'),
    t('Untergliederungen'),
    t('‹ '),
    t(' ›'),
    t('Diese Organisation hat keine Untergliederung.'),
    t('OG membership from node'),
    t('Alle'),
    t('Organisations by EA'),
    t('Keine Verbände nutzen diesen Ausbildungsgang'),
    t('Content entity referenced from field_organisation_earemotes'),
    t('<a href="/node/[nid]" title="[title]">[title]</a> [php]'),
    t('Child organisations commalist'),
  );
  $export['organisations'] = $view;

  $view = new view();
  $view->name = 'organisations_license_overview_by_user';
  $view->description = 'Show a license summary on the license front page';
  $view->tag = 'og';
  $view->base_table = 'og_membership';
  $view->human_name = 'Organisations: License Overview by user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Relationship: OG membership: OG Roles from membership */
  $handler->display->display_options['relationships']['og_users_roles']['id'] = 'og_users_roles';
  $handler->display->display_options['relationships']['og_users_roles']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_users_roles']['field'] = 'og_users_roles';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2>[title]</h2>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print dosb_license_validity_history_view_output($data->node_og_membership_nid);
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$gid = $data->node_og_membership_nid ;

$node = node_load($gid);

 $delta = \'organisations_ea_overview\';
  $panel_mini = panels_mini_load($delta);
  ctools_include(\'context\');
  $context = ctools_context_create(\'entity:node\', $node);
  $contexts = ctools_context_match_required_contexts($panel_mini->requiredcontexts, array($context));
  $panel_mini->context = $panel_mini->display->context =  ctools_context_load_contexts($panel_mini, FALSE, $contexts);
  $panel_mini->display->css_id = panels_mini_get_id($panel_mini->name);
  // Here is the markup, to with with whatever you wish.
  $markup = panels_render_display($panel_mini->display);
return $markup;



$name = \'licenses_educoncepts\';
$display_id = \'panel_pane_3\';
$view = views_get_view($name);
if (!$view || !$view->access($display_id)) {
  return;
}
return views_embed_view($name, $display_id, $gid);
$view->set_arguments(array($gid));
$view->set_display($display_id);
$view->pre_execute();
$view->execute();
$view_content = $view->render(); //$view->preview($display_id);
return $view->preview($display_id);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Content: Verbändegruppe (field_organisation_category) */
  $handler->display->display_options['sorts']['field_organisation_category_value']['id'] = 'field_organisation_category_value';
  $handler->display->display_options['sorts']['field_organisation_category_value']['table'] = 'field_data_field_organisation_category';
  $handler->display->display_options['sorts']['field_organisation_category_value']['field'] = 'field_organisation_category_value';
  $handler->display->display_options['sorts']['field_organisation_category_value']['relationship'] = 'og_membership_related_node_group';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'og_membership_related_node_group';
  /* Contextual filter: We pass the user ID as the Entity ID. */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['ui_name'] = 'We pass the user ID as the Entity ID.';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['etid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['etid']['validate']['type'] = 'user';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: Entity_type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['value'] = 'user';
  /* Filter criterion: OG user roles: Role Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'og_role';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'og_users_roles';
  $handler->display->display_options['filters']['name']['value'] = array(
    'license manager' => 'license manager',
  );

  /* Display: Licenses Overview by user orgs */
  $handler = $view->new_display('panel_pane', 'Licenses Overview by user orgs', 'panel_pane_1');
  $handler->display->display_options['pane_title'] = 'License Overview: By my organisations';
  $handler->display->display_options['pane_category']['name'] = 'Lizenzen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'We pass to the &quot;Entity ID&quot; the User ID.',
    ),
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Inhalt: Beitrags-ID',
    ),
  );

  /* Display: Licenses Overview by user orgs */
  $handler = $view->new_display('panel_pane', 'Licenses Overview by user orgs', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jump_menu';
  $handler->display->display_options['style_options']['hide'] = TRUE;
  $handler->display->display_options['style_options']['path'] = 'php';
  $handler->display->display_options['style_options']['text'] = '';
  $handler->display->display_options['style_options']['choose'] = 'Weiteren Verband auswählen';
  $handler->display->display_options['style_options']['default_value'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2>[title]</h2>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$gid = $data->node_og_membership_nid ;

return "licenses/".$gid;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: We pass the user ID as the Entity ID. */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['ui_name'] = 'We pass the user ID as the Entity ID.';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['etid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['etid']['validate']['type'] = 'user';
  $handler->display->display_options['pane_title'] = 'License Overview: Jump Menu';
  $handler->display->display_options['pane_category']['name'] = 'Lizenzen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'We pass to the &quot;Entity ID&quot; the User ID.',
    ),
  );

  /* Display: Licenses Overview by user orgs */
  $handler = $view->new_display('panel_pane', 'Licenses Overview by user orgs', 'panel_main_organisation');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<div class="col-md-offset-9">
<?php
if(user_access(\'view any dosb_license\')) {
  print l(t("Overview DOSB-Licenses"), \'licenses/all\');
}
?>

<?php
if(user_access(\'view any dosb_license\')) {
  $options = array();
  $options[\'attributes\'] = array();
  $options[\'attributes\'][\'class\'][] = \'float-right\';
  print l(t("Overall stats DOSB-Licenses"), \'licenses/all/statistics\', $options);
  $options[\'attributes\'][\'class\'][] = \'margin-bottom-1\';
  print l(t("Federal state stats DOSB-Licenses"), \'licenses/all/statistics/federal-states\', $options);
}
?>

<?php
if(user_access(\'edit any earemote content\')) {
   print l(t("Overview EA"), \'licenses/ea\');
}

?>

</div>

<?php
print theme("license_statistics_showcase") ; 

?>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['php_output'] = '<div class="col-md-3 help">
<?php
if(user_access(\'view any dosb_license\')) {
print \'<div class="panel panel-default bip_side_box ">
  <div class="panel-heading">
    <h3 class="panel-title">Hilfe</h3>
  </div>
  <div class="panel-body">
    <div class="panel-pane pane-custom">
  <div class="pane-content">
    <div class="views-row"><a href="https://wissensnetz.dosb.de/lims-start" class="salto_core-processed">LiMS-Start</a></div>
    <div class="views-row"><a href="https://wissensnetz.dosb.de/schnellstart-lims-anbindung" class="salto_core-processed">LiMS-API</a></div>
  </div>
  </div>
  </div>
</div>\';
}
?>
</div>';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sie sind kein Mitglied in einem ausbildenden Verband.';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: We pass the user ID as the Entity ID. */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['ui_name'] = 'We pass the user ID as the Entity ID.';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['etid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['etid']['validate']['type'] = 'user';
  $handler->display->display_options['pane_title'] = 'License Overview: Main Organisation';
  $handler->display->display_options['pane_category']['name'] = 'Lizenzen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'We pass to the &quot;Entity ID&quot; the User ID.',
    ),
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Inhalt: Beitrags-ID',
    ),
  );
  $translatables['organisations_license_overview_by_user'] = array(
    t('Master'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Group node from OG membership'),
    t('OG Roles from OG membership'),
    t('<h2>[title]</h2>'),
    t('Alle'),
    t('Licenses Overview by user orgs'),
    t('more'),
    t('License Overview: By my organisations'),
    t('Lizenzen'),
    t('License Overview: Jump Menu'),
    t('Sie sind kein Mitglied in einem ausbildenden Verband.'),
    t('License Overview: Main Organisation'),
  );
  $export['organisations_license_overview_by_user'] = $view;

  $view = new view();
  $view->name = 'organisations_people';
  $view->description = '';
  $view->tag = 'organisations';
  $view->base_table = 'users';
  $view->human_name = 'organisations_people';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '4';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'is_online' => 'is_online',
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Leider ist im Moment keine andere Person im Bildungsnetz unterwegs.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'user_30x30';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print salto_user_get_organisations_by_user($data->uid); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul class="user_links"><li><a class="action_user_chat" href="#">Chat</a></li><li><a class="action_user_message" href="#">Nachricht</a></li></ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Field: Nachname (field_profile_name_last) */
  $handler->display->display_options['sorts']['field_profile_name_last_value']['id'] = 'field_profile_name_last_value';
  $handler->display->display_options['sorts']['field_profile_name_last_value']['table'] = 'field_data_field_profile_name_last';
  $handler->display->display_options['sorts']['field_profile_name_last_value']['field'] = 'field_profile_name_last_value';
  $handler->display->display_options['sorts']['field_profile_name_last_value']['relationship'] = 'profile';
  $handler->display->display_options['sorts']['field_profile_name_last_value']['expose']['label'] = 'Nachname';
  /* Sort criterion: Profile: Adresse - First name */
  $handler->display->display_options['sorts']['field_profile_postal_address_first_name']['id'] = 'field_profile_postal_address_first_name';
  $handler->display->display_options['sorts']['field_profile_postal_address_first_name']['table'] = 'field_data_field_profile_postal_address';
  $handler->display->display_options['sorts']['field_profile_postal_address_first_name']['field'] = 'field_profile_postal_address_first_name';
  $handler->display->display_options['sorts']['field_profile_postal_address_first_name']['relationship'] = 'profile';
  /* Sort criterion: Realname: Real name */
  $handler->display->display_options['sorts']['realname']['id'] = 'realname';
  $handler->display->display_options['sorts']['realname']['table'] = 'realname';
  $handler->display->display_options['sorts']['realname']['field'] = 'realname';
  $handler->display->display_options['sorts']['realname']['expose']['label'] = 'Echter Name';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  /* Filter criterion: User: Last access */
  $handler->display->display_options['filters']['access']['id'] = 'access';
  $handler->display->display_options['filters']['access']['table'] = 'users';
  $handler->display->display_options['filters']['access']['field'] = 'access';
  $handler->display->display_options['filters']['access']['operator'] = '>=';
  $handler->display->display_options['filters']['access']['value']['value'] = '-5 minutes';
  $handler->display->display_options['filters']['access']['value']['type'] = 'offset';

  /* Display: Organisation members */
  $handler = $view->new_display('panel_pane', 'Organisation members', 'member_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mitglieder';
  $handler->display->display_options['display_description'] = 'The managment view for listing peoples in organisations';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeige Ergebnisse @start bis @end von insgesamt @total';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There\'s no result for your search terms in the person directory.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['label'] = 'Hauptprofil';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Profile: Profilbild */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'user_60x60',
    'image_link' => 'content',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print salto_organisation_user_duties_render($view->args[0], $data->uid); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
echo salto_organisation_render_og_manager_member_action($view->args[0], $row->uid);
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="row member-item">
<div class="col-md-2">[field_user_picture]</div>
<div class="col-md-6">
  <div class="groups-members-name">[name]</div>
  <div class="groups-members-state">[php]</div>
</div>
<div class="col-md-4 member-actions">[php_1] </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Nachname (field_profile_name_last) */
  $handler->display->display_options['sorts']['field_profile_name_last_value']['id'] = 'field_profile_name_last_value';
  $handler->display->display_options['sorts']['field_profile_name_last_value']['table'] = 'field_data_field_profile_name_last';
  $handler->display->display_options['sorts']['field_profile_name_last_value']['field'] = 'field_profile_name_last_value';
  $handler->display->display_options['sorts']['field_profile_name_last_value']['relationship'] = 'profile';
  $handler->display->display_options['sorts']['field_profile_name_last_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_profile_name_last_value']['expose']['label'] = 'Nachname';
  /* Sort criterion: Field: Vorname (field_profile_name_first) */
  $handler->display->display_options['sorts']['field_profile_name_first_value']['id'] = 'field_profile_name_first_value';
  $handler->display->display_options['sorts']['field_profile_name_first_value']['table'] = 'field_data_field_profile_name_first';
  $handler->display->display_options['sorts']['field_profile_name_first_value']['field'] = 'field_profile_name_first_value';
  $handler->display->display_options['sorts']['field_profile_name_first_value']['relationship'] = 'profile';
  $handler->display->display_options['sorts']['field_profile_name_first_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_profile_name_first_value']['expose']['label'] = 'Vorname';
  /* Sort criterion: Realname: Real name */
  $handler->display->display_options['sorts']['realname']['id'] = 'realname';
  $handler->display->display_options['sorts']['realname']['table'] = 'realname';
  $handler->display->display_options['sorts']['realname']['field'] = 'realname';
  $handler->display->display_options['sorts']['realname']['expose']['label'] = 'Echter Name';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Realname: Name */
  $handler->display->display_options['filters']['realname']['id'] = 'realname';
  $handler->display->display_options['filters']['realname']['table'] = 'realname';
  $handler->display->display_options['filters']['realname']['field'] = 'realname';
  $handler->display->display_options['filters']['realname']['operator'] = 'contains';
  $handler->display->display_options['filters']['realname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['realname']['expose']['operator_id'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['realname']['expose']['operator'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['identifier'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Profile: Sportarten (field_profile_sports) */
  $handler->display->display_options['filters']['field_profile_sports_tid']['id'] = 'field_profile_sports_tid';
  $handler->display->display_options['filters']['field_profile_sports_tid']['table'] = 'field_data_field_profile_sports';
  $handler->display->display_options['filters']['field_profile_sports_tid']['field'] = 'field_profile_sports_tid';
  $handler->display->display_options['filters']['field_profile_sports_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_profile_sports_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_profile_sports_tid']['value'] = '';
  $handler->display->display_options['filters']['field_profile_sports_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_sports_tid']['expose']['operator_id'] = 'field_profile_sports_tid_op';
  $handler->display->display_options['filters']['field_profile_sports_tid']['expose']['label'] = 'Sportarten';
  $handler->display->display_options['filters']['field_profile_sports_tid']['expose']['operator'] = 'field_profile_sports_tid_op';
  $handler->display->display_options['filters']['field_profile_sports_tid']['expose']['identifier'] = 'profile_sports';
  $handler->display->display_options['filters']['field_profile_sports_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_profile_sports_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_profile_sports_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_profile_sports_tid']['vocabulary'] = 'profile_sports';
  $handler->display->display_options['filters']['field_profile_sports_tid']['error_message'] = FALSE;
  /* Filter criterion: Profile: Interessen (field_profile_interests) */
  $handler->display->display_options['filters']['field_profile_interests_tid']['id'] = 'field_profile_interests_tid';
  $handler->display->display_options['filters']['field_profile_interests_tid']['table'] = 'field_data_field_profile_interests';
  $handler->display->display_options['filters']['field_profile_interests_tid']['field'] = 'field_profile_interests_tid';
  $handler->display->display_options['filters']['field_profile_interests_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_profile_interests_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_profile_interests_tid']['value'] = '';
  $handler->display->display_options['filters']['field_profile_interests_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_interests_tid']['expose']['operator_id'] = 'field_profile_interests_tid_op';
  $handler->display->display_options['filters']['field_profile_interests_tid']['expose']['label'] = 'Interessen';
  $handler->display->display_options['filters']['field_profile_interests_tid']['expose']['operator'] = 'field_profile_interests_tid_op';
  $handler->display->display_options['filters']['field_profile_interests_tid']['expose']['identifier'] = 'profile_interests';
  $handler->display->display_options['filters']['field_profile_interests_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_profile_interests_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_profile_interests_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_profile_interests_tid']['vocabulary'] = 'profile_interests';
  /* Filter criterion: Profile: Arbeitsschwerpunkte (field_profile_competencies) */
  $handler->display->display_options['filters']['field_profile_competencies_tid']['id'] = 'field_profile_competencies_tid';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['table'] = 'field_data_field_profile_competencies';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['field'] = 'field_profile_competencies_tid';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['value'] = '';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_competencies_tid']['expose']['operator_id'] = 'field_profile_competencies_tid_op';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['expose']['label'] = 'Kompetenzen';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['expose']['description'] = 'Schränken sie die Personen mit kommagetrennten Stichwörtern für Sportarten, Interessen und Kompetenzen ein.';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['expose']['operator'] = 'field_profile_competencies_tid_op';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['expose']['identifier'] = 'profile_competencies';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_profile_competencies_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_profile_competencies_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_profile_competencies_tid']['vocabulary'] = 'profile_competencies';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['error_message'] = FALSE;
  /* Filter criterion: User: Is online */
  $handler->display->display_options['filters']['is_online']['id'] = 'is_online';
  $handler->display->display_options['filters']['is_online']['table'] = 'users';
  $handler->display->display_options['filters']['is_online']['field'] = 'is_online';
  $handler->display->display_options['filters']['is_online']['value'] = 'All';
  $handler->display->display_options['filters']['is_online']['exposed'] = TRUE;
  $handler->display->display_options['filters']['is_online']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['is_online']['expose']['label'] = 'Online Status';
  $handler->display->display_options['filters']['is_online']['expose']['operator'] = 'is_online_op';
  $handler->display->display_options['filters']['is_online']['expose']['identifier'] = 'is_online';
  $handler->display->display_options['filters']['is_online']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid']['value'] = array(
    0 => '1',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['pane_title'] = 'Organisation members';
  $handler->display->display_options['pane_category']['name'] = 'Organisations';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
  );
  $translatables['organisations_people'] = array(
    t('Master'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Leider ist im Moment keine andere Person im Bildungsnetz unterwegs.'),
    t('Profile'),
    t('<ul class="user_links"><li><a class="action_user_chat" href="#">Chat</a></li><li><a class="action_user_message" href="#">Nachricht</a></li></ul>'),
    t('Nachname'),
    t('Echter Name'),
    t('Alle'),
    t('Organisation members'),
    t('Mitglieder'),
    t('The managment view for listing peoples in organisations'),
    t('more'),
    t('Zeige Ergebnisse @start bis @end von insgesamt @total'),
    t('There\'s no result for your search terms in the person directory.'),
    t('Hauptprofil'),
    t('OG membership from user'),
    t('<div class="row member-item">
<div class="col-md-2">[field_user_picture]</div>
<div class="col-md-6">
  <div class="groups-members-name">[name]</div>
  <div class="groups-members-state">[php]</div>
</div>
<div class="col-md-4 member-actions">[php_1] </div>
</div>'),
    t('Vorname'),
    t('Name'),
    t('Sportarten'),
    t('Interessen'),
    t('Kompetenzen'),
    t('Schränken sie die Personen mit kommagetrennten Stichwörtern für Sportarten, Interessen und Kompetenzen ein.'),
    t('Online Status'),
    t('Organisations'),
  );
  $export['organisations_people'] = $view;

  $view = new view();
  $view->name = 'salto_organisations_overview';
  $view->description = 'Views for organisation listing';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'salto_organisations_overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Organisationsverzeichnis';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '4';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Zeige Ergebnisse @start bis @end von insgesamt @total
<br><br>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'org-directory-title';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<a href="/personen?field_user_organisations_target_id=<?php print  $data->nid; ?>">(
<?php
  //more efficient way
  $query = new EntityFieldQuery();
  $query->entityCondition(\'entity_type\', \'og_membership\');
  $query->entityCondition(\'bundle\', \'organisation_membership\');
  $query->propertyCondition("gid", $data->nid, "=");
  $query->propertyCondition(\'entity_type\', \'user\');
  $query->propertyCondition(\'state\', OG_STATE_ACTIVE);
  $sum_members = $query->count()->execute();
 // $sum_members = $query->execute();
print  $sum_members;

 ?> )</a>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: Dachorganisation */
  $handler->display->display_options['fields']['field_organisation_parent']['id'] = 'field_organisation_parent';
  $handler->display->display_options['fields']['field_organisation_parent']['table'] = 'og_membership';
  $handler->display->display_options['fields']['field_organisation_parent']['field'] = 'field_organisation_parent';
  $handler->display->display_options['fields']['field_organisation_parent']['label'] = 'Zugehörig zu';
  $handler->display->display_options['fields']['field_organisation_parent']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_organisation_parent']['settings'] = array(
    'link' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Untergliederungen';
  $handler->display->display_options['fields']['php']['element_class'] = 'suborganisations-directory';
  $handler->display->display_options['fields']['php']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = ' $children = views_embed_view(\'organisations\',\'panel_pane_3\', $data->nid);
// dpm(  $children );
// check if the view is empty
if( strpos( $children , \'class="field-content"\') === false){
return 0;
}
else{
 return $children ;
}
';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Organisationsname';
  /* Sort criterion: Content: Dachorganisation (field_organisation_parent) */
  $handler->display->display_options['sorts']['field_organisation_parent_target_id']['id'] = 'field_organisation_parent_target_id';
  $handler->display->display_options['sorts']['field_organisation_parent_target_id']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['field_organisation_parent_target_id']['field'] = 'field_organisation_parent_target_id';
  $handler->display->display_options['sorts']['field_organisation_parent_target_id']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_organisation_parent_target_id']['expose']['label'] = 'Dachorganisation';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );

  /* Display: salto_organisations_overview  */
  $handler = $view->new_display('panel_pane', 'salto_organisations_overview ', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'card';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'php_1' => 'php_1',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Organisationsname';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Dachorganisation (field_organisation_parent) */
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['id'] = 'field_organisation_parent_target_id';
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['field'] = 'field_organisation_parent_target_id';
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['expose']['operator_id'] = 'field_organisation_parent_target_id_op';
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['expose']['label'] = 'Dachorganisation';
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['expose']['operator'] = 'field_organisation_parent_target_id_op';
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['expose']['identifier'] = 'field_organisation_parent_target_id';
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['group_info']['label'] = 'Dachorganisation';
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['group_info']['identifier'] = 'field_organisation_parent_target_id';
  $handler->display->display_options['filters']['field_organisation_parent_target_id']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Allgemeiner Deutscher Hochschulsportverband',
      'operator' => '=',
      'value' => array(
        'value' => '1195',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'American Football Verband Deutschland',
      'operator' => '=',
      'value' => array(
        'value' => '1120',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => 'Bayerischer Landes-Sportverband',
      'operator' => '=',
      'value' => array(
        'value' => '1061',
        'min' => '',
        'max' => '',
      ),
    ),
    4 => array(
      'title' => 'Bob- und Schlittenverband für Deutschland',
      'operator' => '=',
      'value' => array(
        'value' => '1077',
        'min' => '',
        'max' => '',
      ),
    ),
    5 => array(
      'title' => 'Bund Deutscher Radfahrer',
      'operator' => '=',
      'value' => array(
        'value' => '1088',
        'min' => '',
        'max' => '',
      ),
    ),
    6 => array(
      'title' => 'Bundesverband Deutscher Gewichtheber',
      'operator' => '=',
      'value' => array(
        'value' => '1073',
        'min' => '',
        'max' => '',
      ),
    ),
    7 => array(
      'title' => 'Bundesverband Deutscher Kraftdreikämpfer',
      'operator' => '=',
      'value' => array(
        'value' => '1143',
        'min' => '',
        'max' => '',
      ),
    ),
    8 => array(
      'title' => 'CVJM-Sport',
      'operator' => '=',
      'value' => array(
        'value' => '1136',
        'min' => '',
        'max' => '',
      ),
    ),
    9 => array(
      'title' => 'Deutsche Billard-Union',
      'operator' => '=',
      'value' => array(
        'value' => '1076',
        'min' => '',
        'max' => '',
      ),
    ),
    10 => array(
      'title' => 'Deutsche Eislauf-Union',
      'operator' => '=',
      'value' => array(
        'value' => '1140',
        'min' => '',
        'max' => '',
      ),
    ),
    11 => array(
      'title' => 'Deutsche Eisschnelllauf-Gemeinschaft',
      'operator' => '=',
      'value' => array(
        'value' => '1139',
        'min' => '',
        'max' => '',
      ),
    ),
    12 => array(
      'title' => 'Deutsche Lebens-Rettungs-Gesellschaft',
      'operator' => '=',
      'value' => array(
        'value' => '1132',
        'min' => '',
        'max' => '',
      ),
    ),
    13 => array(
      'title' => 'Deutsche Olympische Gesellschaft',
      'operator' => '=',
      'value' => array(
        'value' => '1137',
        'min' => '',
        'max' => '',
      ),
    ),
    14 => array(
      'title' => 'Deutsche Reiterliche Vereinigung',
      'operator' => '=',
      'value' => array(
        'value' => '1089',
        'min' => '',
        'max' => '',
      ),
    ),
    15 => array(
      'title' => 'Deutsche Taekwondo Union',
      'operator' => '=',
      'value' => array(
        'value' => '1116',
        'min' => '',
        'max' => '',
      ),
    ),
    16 => array(
      'title' => 'Deutsche Triathlon-Union',
      'operator' => '=',
      'value' => array(
        'value' => '1117',
        'min' => '',
        'max' => '',
      ),
    ),
    17 => array(
      'title' => 'Deutscher Aero Club',
      'operator' => '=',
      'value' => array(
        'value' => '1071',
        'min' => '',
        'max' => '',
      ),
    ),
    18 => array(
      'title' => 'Deutscher Aikido Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1128',
        'min' => '',
        'max' => '',
      ),
    ),
    19 => array(
      'title' => 'Deutscher Alpenverein',
      'operator' => '=',
      'value' => array(
        'value' => '1121',
        'min' => '',
        'max' => '',
      ),
    ),
    20 => array(
      'title' => 'Deutscher Angelfischerverband',
      'operator' => '=',
      'value' => array(
        'value' => '1099',
        'min' => '',
        'max' => '',
      ),
    ),
    21 => array(
      'title' => 'Deutscher Badminton-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1074',
        'min' => '',
        'max' => '',
      ),
    ),
    22 => array(
      'title' => 'Deutscher Baseball und Softball Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1118',
        'min' => '',
        'max' => '',
      ),
    ),
    23 => array(
      'title' => 'Deutscher Basketball Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1075',
        'min' => '',
        'max' => '',
      ),
    ),
    24 => array(
      'title' => 'Deutscher Behindertensportverband',
      'operator' => '=',
      'value' => array(
        'value' => '1112',
        'min' => '',
        'max' => '',
      ),
    ),
    25 => array(
      'title' => 'Deutscher Betriebssportverband',
      'operator' => '=',
      'value' => array(
        'value' => '1129',
        'min' => '',
        'max' => '',
      ),
    ),
    26 => array(
      'title' => 'Deutscher Boccia-Boule-und Pétanque-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1113',
        'min' => '',
        'max' => '',
      ),
    ),
    27 => array(
      'title' => 'Deutscher Boxsport-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1072',
        'min' => '',
        'max' => '',
      ),
    ),
    28 => array(
      'title' => 'Deutscher Curling-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1142',
        'min' => '',
        'max' => '',
      ),
    ),
    29 => array(
      'title' => 'Deutscher Dart-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1147',
        'min' => '',
        'max' => '',
      ),
    ),
    30 => array(
      'title' => 'Deutscher Eishockey-Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1141',
        'min' => '',
        'max' => '',
      ),
    ),
    31 => array(
      'title' => 'Deutscher Eisstock-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1144',
        'min' => '',
        'max' => '',
      ),
    ),
    32 => array(
      'title' => 'Deutscher Fechter-Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1078',
        'min' => '',
        'max' => '',
      ),
    ),
    33 => array(
      'title' => 'Deutscher Fußball-Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1079',
        'min' => '',
        'max' => '',
      ),
    ),
    34 => array(
      'title' => 'Deutscher Gehörlosen-Sportverband',
      'operator' => '=',
      'value' => array(
        'value' => '1111',
        'min' => '',
        'max' => '',
      ),
    ),
    35 => array(
      'title' => 'Deutscher Golf Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1080',
        'min' => '',
        'max' => '',
      ),
    ),
    36 => array(
      'title' => 'Deutscher Handballbund',
      'operator' => '=',
      'value' => array(
        'value' => '1081',
        'min' => '',
        'max' => '',
      ),
    ),
    37 => array(
      'title' => 'Deutscher Hockey-Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1082',
        'min' => '',
        'max' => '',
      ),
    ),
    38 => array(
      'title' => 'Deutscher Judo-Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1083',
        'min' => '',
        'max' => '',
      ),
    ),
    39 => array(
      'title' => 'Deutscher Ju-Jutsu-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1119',
        'min' => '',
        'max' => '',
      ),
    ),
    40 => array(
      'title' => 'Deutscher Kanu-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1084',
        'min' => '',
        'max' => '',
      ),
    ),
    41 => array(
      'title' => 'Deutscher Karate Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1114',
        'min' => '',
        'max' => '',
      ),
    ),
    42 => array(
      'title' => 'Deutscher Kegler- und Bowlingbund',
      'operator' => '=',
      'value' => array(
        'value' => '1085',
        'min' => '',
        'max' => '',
      ),
    ),
    43 => array(
      'title' => 'Deutscher Leichtathletik-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1086',
        'min' => '',
        'max' => '',
      ),
    ),
    44 => array(
      'title' => 'Deutscher Minigolfsport Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1127',
        'min' => '',
        'max' => '',
      ),
    ),
    45 => array(
      'title' => 'Deutscher Motor Sport Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1145',
        'min' => '',
        'max' => '',
      ),
    ),
    46 => array(
      'title' => 'Deutscher Motoryachtverband',
      'operator' => '=',
      'value' => array(
        'value' => '1087',
        'min' => '',
        'max' => '',
      ),
    ),
    47 => array(
      'title' => 'Deutscher Rasenkraftsport- und Tauzieh-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1109',
        'min' => '',
        'max' => '',
      ),
    ),
    48 => array(
      'title' => 'Deutscher Ringer-Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1110',
        'min' => '',
        'max' => '',
      ),
    ),
    49 => array(
      'title' => 'Deutscher Rollsport- und Inline-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1090',
        'min' => '',
        'max' => '',
      ),
    ),
    50 => array(
      'title' => 'Deutscher Ruderverband',
      'operator' => '=',
      'value' => array(
        'value' => '1091',
        'min' => '',
        'max' => '',
      ),
    ),
    51 => array(
      'title' => 'Deutscher Rugby-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1092',
        'min' => '',
        'max' => '',
      ),
    ),
    52 => array(
      'title' => 'Deutscher Schachbund',
      'operator' => '=',
      'value' => array(
        'value' => '1093',
        'min' => '',
        'max' => '',
      ),
    ),
    53 => array(
      'title' => 'Deutscher Schützenbund',
      'operator' => '=',
      'value' => array(
        'value' => '1094',
        'min' => '',
        'max' => '',
      ),
    ),
    54 => array(
      'title' => 'Deutscher Schwimm-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1095',
        'min' => '',
        'max' => '',
      ),
    ),
    55 => array(
      'title' => 'Deutscher Segler-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1096',
        'min' => '',
        'max' => '',
      ),
    ),
    56 => array(
      'title' => 'Deutscher Skibob-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1097',
        'min' => '',
        'max' => '',
      ),
    ),
    57 => array(
      'title' => 'Deutscher Skiverband',
      'operator' => '=',
      'value' => array(
        'value' => '1098',
        'min' => '',
        'max' => '',
      ),
    ),
    58 => array(
      'title' => 'Deutscher Sportakrobatik-Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1108',
        'min' => '',
        'max' => '',
      ),
    ),
    59 => array(
      'title' => 'Deutscher Squash Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1115',
        'min' => '',
        'max' => '',
      ),
    ),
    60 => array(
      'title' => 'Deutscher Tanzsportverband',
      'operator' => '=',
      'value' => array(
        'value' => '1101',
        'min' => '',
        'max' => '',
      ),
    ),
    61 => array(
      'title' => 'Deutscher Tennis Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1102',
        'min' => '',
        'max' => '',
      ),
    ),
    62 => array(
      'title' => 'Deutscher Tischtennis-Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1103',
        'min' => '',
        'max' => '',
      ),
    ),
    63 => array(
      'title' => 'Deutscher Turner-Bund',
      'operator' => '=',
      'value' => array(
        'value' => '1104',
        'min' => '',
        'max' => '',
      ),
    ),
    64 => array(
      'title' => 'Deutscher Verband für Freikörperkultur',
      'operator' => '=',
      'value' => array(
        'value' => '1134',
        'min' => '',
        'max' => '',
      ),
    ),
    65 => array(
      'title' => 'Deutscher Verband für Modernen Fünfkampf',
      'operator' => '=',
      'value' => array(
        'value' => '1105',
        'min' => '',
        'max' => '',
      ),
    ),
    66 => array(
      'title' => 'Deutscher Volleyball-Verband',
      'operator' => '=',
      'value' => array(
        'value' => '1106',
        'min' => '',
        'max' => '',
      ),
    ),
    67 => array(
      'title' => 'Deutscher Wasserski- und Wakeboardverband',
      'operator' => '=',
      'value' => array(
        'value' => '1107',
        'min' => '',
        'max' => '',
      ),
    ),
    68 => array(
      'title' => 'Deutsches Polizeisportkuratorium',
      'operator' => '=',
      'value' => array(
        'value' => '1133',
        'min' => '',
        'max' => '',
      ),
    ),
    69 => array(
      'title' => 'DJK-Sportverband',
      'operator' => '=',
      'value' => array(
        'value' => '1135',
        'min' => '',
        'max' => '',
      ),
    ),
    70 => array(
      'title' => 'DOSB',
      'operator' => '=',
      'value' => array(
        'value' => '1755',
        'min' => '',
        'max' => '',
      ),
    ),
    71 => array(
      'title' => 'Ghostthinker',
      'operator' => '=',
      'value' => array(
        'value' => '104',
        'min' => '',
        'max' => '',
      ),
    ),
    72 => array(
      'title' => 'Hamburger Barfußtänzer',
      'operator' => '=',
      'value' => array(
        'value' => '1214',
        'min' => '',
        'max' => '',
      ),
    ),
    73 => array(
      'title' => 'Hamburger Sportbund',
      'operator' => '=',
      'value' => array(
        'value' => '1064',
        'min' => '',
        'max' => '',
      ),
    ),
    74 => array(
      'title' => 'Kneipp-Bund - Bundesverband für Gesundheitsförderung',
      'operator' => '=',
      'value' => array(
        'value' => '1131',
        'min' => '',
        'max' => '',
      ),
    ),
    75 => array(
      'title' => 'Landessportbund Berlin',
      'operator' => '=',
      'value' => array(
        'value' => '1062',
        'min' => '',
        'max' => '',
      ),
    ),
    76 => array(
      'title' => 'Landessportbund Brandenburg',
      'operator' => '=',
      'value' => array(
        'value' => '1123',
        'min' => '',
        'max' => '',
      ),
    ),
    77 => array(
      'title' => 'Landessportbund Bremen',
      'operator' => '=',
      'value' => array(
        'value' => '1063',
        'min' => '',
        'max' => '',
      ),
    ),
    78 => array(
      'title' => 'Landessportbund Hessen',
      'operator' => '=',
      'value' => array(
        'value' => '1065',
        'min' => '',
        'max' => '',
      ),
    ),
    79 => array(
      'title' => 'Landessportbund Mecklenburg-Vorpommern',
      'operator' => '=',
      'value' => array(
        'value' => '1122',
        'min' => '',
        'max' => '',
      ),
    ),
    80 => array(
      'title' => 'LandesSportBund Niedersachsen',
      'operator' => '=',
      'value' => array(
        'value' => '1066',
        'min' => '',
        'max' => '',
      ),
    ),
    81 => array(
      'title' => 'Landessportbund Nordrhein-Westfalen',
      'operator' => '=',
      'value' => array(
        'value' => '1067',
        'min' => '',
        'max' => '',
      ),
    ),
    82 => array(
      'title' => 'Landessportbund Rheinland-Pfalz',
      'operator' => '=',
      'value' => array(
        'value' => '1068',
        'min' => '',
        'max' => '',
      ),
    ),
    83 => array(
      'title' => 'Landessportbund Sachsen',
      'operator' => '=',
      'value' => array(
        'value' => '1125',
        'min' => '',
        'max' => '',
      ),
    ),
    84 => array(
      'title' => 'Landessportbund Sachsen-Anhalt',
      'operator' => '=',
      'value' => array(
        'value' => '1124',
        'min' => '',
        'max' => '',
      ),
    ),
    85 => array(
      'title' => 'Landessportbund Thüringen',
      'operator' => '=',
      'value' => array(
        'value' => '1126',
        'min' => '',
        'max' => '',
      ),
    ),
    86 => array(
      'title' => 'Landessportverband Baden-Württemberg',
      'operator' => '=',
      'value' => array(
        'value' => '1138',
        'min' => '',
        'max' => '',
      ),
    ),
    87 => array(
      'title' => 'Landessportverband für das Saarland',
      'operator' => '=',
      'value' => array(
        'value' => '1069',
        'min' => '',
        'max' => '',
      ),
    ),
    88 => array(
      'title' => 'Landessportverband Schleswig-Holstein',
      'operator' => '=',
      'value' => array(
        'value' => '1070',
        'min' => '',
        'max' => '',
      ),
    ),
    89 => array(
      'title' => 'Makkabi',
      'operator' => '=',
      'value' => array(
        'value' => '1149',
        'min' => '',
        'max' => '',
      ),
    ),
    90 => array(
      'title' => 'Rad- und Kraftfahrerbund „Solidarität“ Deutschland 1896',
      'operator' => '=',
      'value' => array(
        'value' => '1148',
        'min' => '',
        'max' => '',
      ),
    ),
    91 => array(
      'title' => 'Snowboard Verband Deutschland',
      'operator' => '=',
      'value' => array(
        'value' => '1146',
        'min' => '',
        'max' => '',
      ),
    ),
    92 => array(
      'title' => 'Special Olympics Deutschland',
      'operator' => '=',
      'value' => array(
        'value' => '1686',
        'min' => '',
        'max' => '',
      ),
    ),
    93 => array(
      'title' => 'Verband Deutscher Eisenbahner-Sportvereine',
      'operator' => '=',
      'value' => array(
        'value' => '1130',
        'min' => '',
        'max' => '',
      ),
    ),
    94 => array(
      'title' => 'Verband Deutscher Sporttaucher',
      'operator' => '=',
      'value' => array(
        'value' => '1100',
        'min' => '',
        'max' => '',
      ),
    ),
    95 => array(
      'title' => 'Cheerleading und Cheerdance Verband Deutschland',
      'operator' => '=',
      'value' => array(
        'value' => '11660',
        'min' => '',
        'max' => '',
      ),
    ),
    96 => array(
      'title' => 'Bundesfachverband für Kickboxen (WAKO Deutschland)',
      'operator' => '=',
      'value' => array(
        'value' => '11661',
        'min' => '',
        'max' => '',
      ),
    ),
    97 => array(
      'title' => 'Floorball-Verband Deutschland',
      'operator' => '=',
      'value' => array(
        'value' => '7704',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  /* Filter criterion: Content: Verbändegruppe (field_organisation_category) */
  $handler->display->display_options['filters']['field_organisation_category_value']['id'] = 'field_organisation_category_value';
  $handler->display->display_options['filters']['field_organisation_category_value']['table'] = 'field_data_field_organisation_category';
  $handler->display->display_options['filters']['field_organisation_category_value']['field'] = 'field_organisation_category_value';
  $handler->display->display_options['filters']['field_organisation_category_value']['group'] = 1;
  $handler->display->display_options['filters']['field_organisation_category_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organisation_category_value']['expose']['operator_id'] = 'field_organisation_category_value_op';
  $handler->display->display_options['filters']['field_organisation_category_value']['expose']['label'] = 'Verbändegruppe';
  $handler->display->display_options['filters']['field_organisation_category_value']['expose']['operator'] = 'field_organisation_category_value_op';
  $handler->display->display_options['filters']['field_organisation_category_value']['expose']['identifier'] = 'field_organisation_category_value';
  $handler->display->display_options['filters']['field_organisation_category_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Bundesland (field_organisation_bundesland) */
  $handler->display->display_options['filters']['field_organisation_bundesland_value']['id'] = 'field_organisation_bundesland_value';
  $handler->display->display_options['filters']['field_organisation_bundesland_value']['table'] = 'field_data_field_organisation_bundesland';
  $handler->display->display_options['filters']['field_organisation_bundesland_value']['field'] = 'field_organisation_bundesland_value';
  $handler->display->display_options['filters']['field_organisation_bundesland_value']['group'] = 1;
  $handler->display->display_options['filters']['field_organisation_bundesland_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organisation_bundesland_value']['expose']['operator_id'] = 'field_organisation_bundesland_value_op';
  $handler->display->display_options['filters']['field_organisation_bundesland_value']['expose']['label'] = 'Bundesland';
  $handler->display->display_options['filters']['field_organisation_bundesland_value']['expose']['operator'] = 'field_organisation_bundesland_value_op';
  $handler->display->display_options['filters']['field_organisation_bundesland_value']['expose']['identifier'] = 'field_organisation_bundesland_value';
  $handler->display->display_options['filters']['field_organisation_bundesland_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['pane_title'] = 'salto_organisations_overview';
  $handler->display->display_options['pane_category']['name'] = 'Organisationen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $translatables['salto_organisations_overview'] = array(
    t('Master'),
    t('Organisationsverzeichnis'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Zeige Ergebnisse @start bis @end von insgesamt @total
<br><br>'),
    t('Zugehörig zu'),
    t('Untergliederungen'),
    t('Organisationsname'),
    t('Dachorganisation'),
    t('salto_organisations_overview '),
    t('more'),
    t('Verbändegruppe'),
    t('Bundesland'),
    t('salto_organisations_overview'),
    t('Organisationen'),
  );
  $export['salto_organisations_overview'] = $view;

  $view = new view();
  $view->name = 'user_organisations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'User Organisations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Gehört noch keiner Organisation an.';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Relationship: OG membership: OG membership from Node group */
  $handler->display->display_options['relationships']['og_membership_rel_group']['id'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel_group']['field'] = 'og_membership_rel_group';
  /* Relationship: OG membership: User from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_user']['id'] = 'og_membership_related_user';
  $handler->display->display_options['relationships']['og_membership_related_user']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_user']['field'] = 'og_membership_related_user';
  $handler->display->display_options['relationships']['og_membership_related_user']['relationship'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_related_user']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: OG membership: Funktion */
  $handler->display->display_options['fields']['field_organisation_position']['id'] = 'field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['table'] = 'field_data_field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['field'] = 'field_organisation_position';
  $handler->display->display_options['fields']['field_organisation_position']['relationship'] = 'og_membership_rel_group';
  $handler->display->display_options['fields']['field_organisation_position']['alter']['text'] = '[field_organisation_position]';
  $handler->display->display_options['fields']['field_organisation_position']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_organisation_position']['delta_offset'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'access denied';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );
  $translatables['user_organisations'] = array(
    t('Master'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Gehört noch keiner Organisation an.'),
    t('OG membership from node group'),
    t('user from OG membership'),
    t('Funktion'),
    t('[field_organisation_position]'),
    t('Alle'),
  );
  $export['user_organisations'] = $view;

  return $export;
}
