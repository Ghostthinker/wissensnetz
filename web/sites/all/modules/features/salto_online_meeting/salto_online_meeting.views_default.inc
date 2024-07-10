<?php

/**
 * @file
 * salto_online_meeting.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function salto_online_meeting_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'group_online_meetings';
  $view->description = 'Base view to filter and show articles, questions and reports';
  $view->tag = 'groups';
  $view->base_table = 'node';
  $view->human_name = 'Group: online-meetings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Aktuellste Beiträge';
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
  $handler->display->display_options['row_plugin'] = 'node';
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php 
$post_id = arg(3);
if(is_numeric($post_id )) {
   $term = taxonomy_term_load($post_id );
  echo check_markup(render($term->description), \'editor\');

}

?>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'At the moment there is no content here, but that will surely change soon.';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Zeitpunkt -  start date (field_online_meeting_date) */
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['id'] = 'field_online_meeting_date_value';
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['table'] = 'field_data_field_online_meeting_date';
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['field'] = 'field_online_meeting_date_value';
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
    'post' => 'post',
  );

  /* Display: Content: Online Meetings */
  $handler = $view->new_display('panel_pane', 'Content: Online Meetings', 'base');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'online_meeting' => 'online_meeting',
  );
  $handler->display->display_options['pane_title'] = 'Group Online Meetings: base';
  $handler->display->display_options['pane_category']['name'] = 'Gruppen';
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
    'og_vocabulary_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Inhalt: OG vocabulary (og_vocabulary)',
    ),
  );

  /* Display: Online Meetings: Pending */
  $handler = $view->new_display('panel_pane', 'Online Meetings: Pending', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Pending';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'online_meeting' => 'online_meeting',
  );
  /* Filter criterion: Content: Wiederkehrende Meetings (field_recurring_meeting) */
  $handler->display->display_options['filters']['field_recurring_meeting_value']['id'] = 'field_recurring_meeting_value';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['table'] = 'field_data_field_recurring_meeting';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['field'] = 'field_recurring_meeting_value';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Content: Zeitpunkt - end date (field_online_meeting_date:value2) */
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['id'] = 'field_online_meeting_date_value2';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['table'] = 'field_data_field_online_meeting_date';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['field'] = 'field_online_meeting_date_value2';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['operator'] = '>';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['value']['min'] = '2021-07-02';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['default_date'] = 'now';
  $handler->display->display_options['pane_title'] = 'Group Online Meetings: pending';
  $handler->display->display_options['pane_category']['name'] = 'Gruppen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
    'og_vocabulary_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Inhalt: OG vocabulary (og_vocabulary)',
    ),
  );
  $handler->display->display_options['link_to_view'] = '1';

  /* Display: Online Meetings: Completed */
  $handler = $view->new_display('panel_pane', 'Online Meetings: Completed', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Completed';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Zeitpunkt -  start date (field_online_meeting_date) */
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['id'] = 'field_online_meeting_date_value';
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['table'] = 'field_data_field_online_meeting_date';
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['field'] = 'field_online_meeting_date_value';
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'online_meeting' => 'online_meeting',
  );
  /* Filter criterion: Content: Wiederkehrende Meetings (field_recurring_meeting) */
  $handler->display->display_options['filters']['field_recurring_meeting_value']['id'] = 'field_recurring_meeting_value';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['table'] = 'field_data_field_recurring_meeting';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['field'] = 'field_recurring_meeting_value';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Content: Zeitpunkt - end date (field_online_meeting_date:value2) */
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['id'] = 'field_online_meeting_date_value2';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['table'] = 'field_data_field_online_meeting_date';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['field'] = 'field_online_meeting_date_value2';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['operator'] = '<';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['value']['min'] = '2021-07-02';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['default_date'] = 'now';
  $handler->display->display_options['pane_title'] = 'Group Online Meetings: completed';
  $handler->display->display_options['pane_category']['name'] = 'Gruppen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
    'og_vocabulary_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Inhalt: OG vocabulary (og_vocabulary)',
    ),
  );

  /* Display: Online Meetings: Recurring */
  $handler = $view->new_display('panel_pane', 'Online Meetings: Recurring', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recurring';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'online_meeting' => 'online_meeting',
  );
  /* Filter criterion: Content: Wiederkehrende Meetings (field_recurring_meeting) */
  $handler->display->display_options['filters']['field_recurring_meeting_value']['id'] = 'field_recurring_meeting_value';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['table'] = 'field_data_field_recurring_meeting';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['field'] = 'field_recurring_meeting_value';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_title'] = 'Group Online Meetings: recurring';
  $handler->display->display_options['pane_category']['name'] = 'Gruppen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
    'og_vocabulary_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Inhalt: OG vocabulary (og_vocabulary)',
    ),
  );
  $translatables['group_online_meetings'] = array(
    t('Master'),
    t('Aktuellste Beiträge'),
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
    t('At the moment there is no content here, but that will surely change soon.'),
    t('OG membership from node'),
    t('Alle'),
    t('Content: Online Meetings'),
    t('more'),
    t('Titel'),
    t('Group Online Meetings: base'),
    t('Gruppen'),
    t('Online Meetings: Pending'),
    t('Pending'),
    t('Group Online Meetings: pending'),
    t('Online Meetings: Completed'),
    t('Completed'),
    t('Group Online Meetings: completed'),
    t('Online Meetings: Recurring'),
    t('Recurring'),
    t('Group Online Meetings: recurring'),
  );
  $export['group_online_meetings'] = $view;

  $view = new view();
  $view->name = 'online_meetings';
  $view->description = 'Base view to filter and show articles, questions and reports';
  $view->tag = 'groups';
  $view->base_table = 'node';
  $view->human_name = 'online-meetings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Aktuellste Beiträge';
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
  $handler->display->display_options['row_plugin'] = 'node';
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php 
$post_id = arg(3);
if(is_numeric($post_id )) {
   $term = taxonomy_term_load($post_id );
  echo check_markup(render($term->description), \'editor\');

}

?>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'At the moment there is no content here, but that will surely change soon.';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Relationship: OG membership: OG membership from Node */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['label'] = 'OG node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Zeitpunkt -  start date (field_online_meeting_date) */
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['id'] = 'field_online_meeting_date_value';
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['table'] = 'field_data_field_online_meeting_date';
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['field'] = 'field_online_meeting_date_value';
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
    'post' => 'post',
  );

  /* Display: Content: Online Meetings */
  $handler = $view->new_display('panel_pane', 'Content: Online Meetings', 'base');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'online_meeting' => 'online_meeting',
  );
  $handler->display->display_options['pane_title'] = 'Online Meetings: base';
  $handler->display->display_options['pane_category']['name'] = 'Online-Treffen';
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
    'og_vocabulary_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Inhalt: OG vocabulary (og_vocabulary)',
    ),
  );

  /* Display: Online Meetings: Pending */
  $handler = $view->new_display('panel_pane', 'Online Meetings: Pending', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Pending';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'online_meeting' => 'online_meeting',
  );
  /* Filter criterion: Content: Wiederkehrende Meetings (field_recurring_meeting) */
  $handler->display->display_options['filters']['field_recurring_meeting_value']['id'] = 'field_recurring_meeting_value';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['table'] = 'field_data_field_recurring_meeting';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['field'] = 'field_recurring_meeting_value';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Content: Zeitpunkt - end date (field_online_meeting_date:value2) */
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['id'] = 'field_online_meeting_date_value2';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['table'] = 'field_data_field_online_meeting_date';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['field'] = 'field_online_meeting_date_value2';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['operator'] = '>';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['value']['min'] = '2021-07-02';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['default_date'] = 'now';
  /* Filter criterion: OG membership: Entity id */
  $handler->display->display_options['filters']['etid']['id'] = 'etid';
  $handler->display->display_options['filters']['etid']['table'] = 'og_membership';
  $handler->display->display_options['filters']['etid']['field'] = 'etid';
  $handler->display->display_options['filters']['etid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['etid']['operator'] = 'empty';
  $handler->display->display_options['pane_title'] = 'Online Meetings: pending';
  $handler->display->display_options['pane_category']['name'] = 'Online-Treffen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
    'og_vocabulary_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Inhalt: OG vocabulary (og_vocabulary)',
    ),
  );
  $handler->display->display_options['link_to_view'] = '1';

  /* Display: Online Meetings: Completed */
  $handler = $view->new_display('panel_pane', 'Online Meetings: Completed', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Completed';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Zeitpunkt -  start date (field_online_meeting_date) */
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['id'] = 'field_online_meeting_date_value';
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['table'] = 'field_data_field_online_meeting_date';
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['field'] = 'field_online_meeting_date_value';
  $handler->display->display_options['sorts']['field_online_meeting_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'online_meeting' => 'online_meeting',
  );
  /* Filter criterion: Content: Wiederkehrende Meetings (field_recurring_meeting) */
  $handler->display->display_options['filters']['field_recurring_meeting_value']['id'] = 'field_recurring_meeting_value';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['table'] = 'field_data_field_recurring_meeting';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['field'] = 'field_recurring_meeting_value';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Content: Zeitpunkt - end date (field_online_meeting_date:value2) */
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['id'] = 'field_online_meeting_date_value2';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['table'] = 'field_data_field_online_meeting_date';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['field'] = 'field_online_meeting_date_value2';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['operator'] = '<';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['value']['min'] = '2021-07-02';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['granularity'] = 'minute';
  $handler->display->display_options['filters']['field_online_meeting_date_value2']['default_date'] = 'now';
  /* Filter criterion: OG membership: Entity id */
  $handler->display->display_options['filters']['etid']['id'] = 'etid';
  $handler->display->display_options['filters']['etid']['table'] = 'og_membership';
  $handler->display->display_options['filters']['etid']['field'] = 'etid';
  $handler->display->display_options['filters']['etid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['etid']['operator'] = 'empty';
  $handler->display->display_options['pane_title'] = 'Online Meetings: completed';
  $handler->display->display_options['pane_category']['name'] = 'Online-Treffen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
    'og_vocabulary_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Inhalt: OG vocabulary (og_vocabulary)',
    ),
  );

  /* Display: Online Meetings: Recurring */
  $handler = $view->new_display('panel_pane', 'Online Meetings: Recurring', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recurring';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'online_meeting' => 'online_meeting',
  );
  /* Filter criterion: Content: Wiederkehrende Meetings (field_recurring_meeting) */
  $handler->display->display_options['filters']['field_recurring_meeting_value']['id'] = 'field_recurring_meeting_value';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['table'] = 'field_data_field_recurring_meeting';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['field'] = 'field_recurring_meeting_value';
  $handler->display->display_options['filters']['field_recurring_meeting_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: OG membership: Entity id */
  $handler->display->display_options['filters']['etid']['id'] = 'etid';
  $handler->display->display_options['filters']['etid']['table'] = 'og_membership';
  $handler->display->display_options['filters']['etid']['field'] = 'etid';
  $handler->display->display_options['filters']['etid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['etid']['operator'] = 'empty';
  $handler->display->display_options['pane_title'] = 'Online Meetings: recurring';
  $handler->display->display_options['pane_category']['name'] = 'Online-Treffen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
    'og_vocabulary_target_id' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Inhalt: OG vocabulary (og_vocabulary)',
    ),
  );
  $translatables['online_meetings'] = array(
    t('Master'),
    t('Aktuellste Beiträge'),
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
    t('At the moment there is no content here, but that will surely change soon.'),
    t('OG node'),
    t('Content: Online Meetings'),
    t('more'),
    t('Titel'),
    t('Online Meetings: base'),
    t('Online-Treffen'),
    t('Online Meetings: Pending'),
    t('Pending'),
    t('Online Meetings: pending'),
    t('Online Meetings: Completed'),
    t('Completed'),
    t('Online Meetings: completed'),
    t('Online Meetings: Recurring'),
    t('Recurring'),
    t('Online Meetings: recurring'),
  );
  $export['online_meetings'] = $view;

  return $export;
}
