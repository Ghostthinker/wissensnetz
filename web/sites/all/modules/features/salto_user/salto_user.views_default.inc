<?php
/**
 * @file
 * salto_user.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function salto_user_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'heartbeat_useractivity';
  $view->description = 'Show user\'s hearbeat activity';
  $view->tag = 'default';
  $view->base_table = 'heartbeat_activity';
  $view->human_name = 'Heartbeat - Useractivity';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Aktivitäten';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'heartbeat_activity';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 1;
  /* Field: Heartbeat activity: Activity message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = '';
  $handler->display->display_options['fields']['message']['element_label_colon'] = FALSE;
  /* Field: Heartbeat activity: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Beitrags-ID';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Heartbeat activity: User ID */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Benutzer-ID';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = '//+preview output
$vars = heartbeat_decode_message_variables($data->heartbeat_activity_variables);

return $vars[\'!node_preview\'] ? $vars[\'!node_preview\'] : \'\' ;';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php echo $value ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '//icons for useractivity stream

$vars = heartbeat_decode_message_variables($data->heartbeat_activity_variables);

if($data->heartbeat_activity_message_id  == \'heartbeat_add_node\' || $data->heartbeat_activity_message_id  == \'heartbeat_edit_node\' ) {
  return "-type-" . $vars[\'node_type\'];
}

if( $data->heartbeat_activity_message_id == \'heartbeat_add_comment\' ) {
  return "-comment";
}';
  $handler->display->display_options['fields']['php']['php_output'] = '<span class="heartbeat-activity<?php echo $value?>"></span>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Heartbeat activity: Buttons */
  $handler->display->display_options['fields']['buttons']['id'] = 'buttons';
  $handler->display->display_options['fields']['buttons']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['buttons']['field'] = 'buttons';
  $handler->display->display_options['fields']['buttons']['label'] = '';
  $handler->display->display_options['fields']['buttons']['element_label_colon'] = FALSE;
  /* Sort criterion: Heartbeat activity: Creation date */
  $handler->display->display_options['sorts']['created_at']['id'] = 'created_at';
  $handler->display->display_options['sorts']['created_at']['table'] = 'heartbeat_activity';
  $handler->display->display_options['sorts']['created_at']['field'] = 'created_at';
  $handler->display->display_options['sorts']['created_at']['order'] = 'DESC';
  /* Contextual filter: Heartbeat activity: User ID */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Heartbeat activity: Heartbeat template */
  $handler->display->display_options['filters']['message_id']['id'] = 'message_id';
  $handler->display->display_options['filters']['message_id']['table'] = 'heartbeat_activity';
  $handler->display->display_options['filters']['message_id']['field'] = 'message_id';
  $handler->display->display_options['filters']['message_id']['operator'] = 'not in';
  $handler->display->display_options['filters']['message_id']['value'] = array(
    'heartbeat_edit_account' => 'heartbeat_edit_account',
  );

  /* Display: Panel Inhalt */
  $handler = $view->new_display('panel_pane', 'Panel Inhalt', 'panel_heartbeat_useractivity');
  $handler->display->display_options['pane_category']['name'] = 'People';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'panel',
      'context' => 'entity:search_api_autocomplete_search.name',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Heartbeat activity: Benutzer-ID',
    ),
  );
  $translatables['heartbeat_useractivity'] = array(
    t('Master'),
    t('Aktivitäten'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Beitrags-ID'),
    t('.'),
    t(','),
    t('Benutzer-ID'),
    t('Alle'),
    t('Panel Inhalt'),
    t('People'),
  );
  $export['heartbeat_useractivity'] = $view;

  $view = new view();
  $view->name = 'invites_mine';
  $view->description = 'show all my invites with a link in user menu';
  $view->tag = 'default';
  $view->base_table = 'salto_invite';
  $view->human_name = 'Invites: mine';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Meine Einladungen';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
    6 => '6',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'salto_invite_id' => 'salto_invite_id',
    'field_profile_contact_email_1' => 'field_profile_contact_email_1',
    'field_profile_name_last_1' => 'field_profile_name_last_1',
    'field_profile_name_first_1' => 'field_profile_name_first_1',
    'field_salto_invite_organisations' => 'field_salto_invite_organisations',
    'created' => 'created',
    'used' => 'used',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'salto_invite_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_contact_email_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_name_last_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_name_first_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_salto_invite_organisations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'used' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sie haben noch keine Personen in eine Organisation eingeladen!';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Relationship: Salto Invite: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'salto_invite';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Field: Salto Invite: Salto invite ID */
  $handler->display->display_options['fields']['salto_invite_id']['id'] = 'salto_invite_id';
  $handler->display->display_options['fields']['salto_invite_id']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['salto_invite_id']['field'] = 'salto_invite_id';
  $handler->display->display_options['fields']['salto_invite_id']['exclude'] = TRUE;
  /* Field: Field: Email */
  $handler->display->display_options['fields']['field_profile_contact_email_1']['id'] = 'field_profile_contact_email_1';
  $handler->display->display_options['fields']['field_profile_contact_email_1']['table'] = 'field_data_field_profile_contact_email';
  $handler->display->display_options['fields']['field_profile_contact_email_1']['field'] = 'field_profile_contact_email';
  $handler->display->display_options['fields']['field_profile_contact_email_1']['label'] = 'E-Mail';
  /* Field: Field: Nachname */
  $handler->display->display_options['fields']['field_profile_name_last_1']['id'] = 'field_profile_name_last_1';
  $handler->display->display_options['fields']['field_profile_name_last_1']['table'] = 'field_data_field_profile_name_last';
  $handler->display->display_options['fields']['field_profile_name_last_1']['field'] = 'field_profile_name_last';
  /* Field: Field: Vorname */
  $handler->display->display_options['fields']['field_profile_name_first_1']['id'] = 'field_profile_name_first_1';
  $handler->display->display_options['fields']['field_profile_name_first_1']['table'] = 'field_data_field_profile_name_first';
  $handler->display->display_options['fields']['field_profile_name_first_1']['field'] = 'field_profile_name_first';
  /* Field: Salto Invite: Organisations */
  $handler->display->display_options['fields']['field_salto_invite_organisations']['id'] = 'field_salto_invite_organisations';
  $handler->display->display_options['fields']['field_salto_invite_organisations']['table'] = 'og_membership';
  $handler->display->display_options['fields']['field_salto_invite_organisations']['field'] = 'field_salto_invite_organisations';
  $handler->display->display_options['fields']['field_salto_invite_organisations']['label'] = 'Organisation';
  $handler->display->display_options['fields']['field_salto_invite_organisations']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_salto_invite_organisations']['delta_offset'] = '0';
  /* Field: Salto Invite: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Erstellt am';
  /* Field: Salto Invite: Used */
  $handler->display->display_options['fields']['used']['id'] = 'used';
  $handler->display->display_options['fields']['used']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['used']['field'] = 'used';
  $handler->display->display_options['fields']['used']['label'] = 'Verwendet';
  $handler->display->display_options['fields']['used']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['used']['not'] = 0;
  /* Field: Salto Invite: Resend invite Link */
  $handler->display->display_options['fields']['link_salto_resend_invite']['id'] = 'link_salto_resend_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['field'] = 'link_salto_resend_invite';
  $handler->display->display_options['fields']['link_salto_resend_invite']['label'] = 'Aktionen';
  $handler->display->display_options['fields']['link_salto_resend_invite']['text'] = 'Erneut versenden';
  $handler->display->display_options['fields']['link_salto_resend_invite']['css_primary_button'] = 1;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate']['fail'] = 'empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/invites';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Meine Einladungen';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $translatables['invites_mine'] = array(
    t('Master'),
    t('Meine Einladungen'),
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
    t('Sie haben noch keine Personen in eine Organisation eingeladen!'),
    t('User'),
    t('Salto invite ID'),
    t('.'),
    t(','),
    t('E-Mail'),
    t('Nachname'),
    t('Vorname'),
    t('Organisation'),
    t('Erstellt am'),
    t('Verwendet'),
    t('Aktionen'),
    t('Erneut versenden'),
    t('Alle'),
    t('Page'),
    t('more'),
  );
  $export['invites_mine'] = $view;

  $view = new view();
  $view->name = 'membership_requests';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Membership requests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Membership requests';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    8 => '8',
  );
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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Feld: Benutzer: Erstellungsdatum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Datum der Anfrage';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Feld: Benutzer: Daten */
  $handler->display->display_options['fields']['data_1']['id'] = 'data_1';
  $handler->display->display_options['fields']['data_1']['table'] = 'users';
  $handler->display->display_options['fields']['data_1']['field'] = 'data';
  $handler->display->display_options['fields']['data_1']['label'] = 'Organisation';
  $handler->display->display_options['fields']['data_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['data_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['data_1']['format'] = 'key';
  $handler->display->display_options['fields']['data_1']['key'] = 'organisation';
  /* Feld: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Organisation';
  $handler->display->display_options['fields']['php']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
echo salto_user_membership_request_get_og_title($row->data_1);

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Benutzer: Daten */
  $handler->display->display_options['fields']['data_2']['id'] = 'data_2';
  $handler->display->display_options['fields']['data_2']['table'] = 'users';
  $handler->display->display_options['fields']['data_2']['field'] = 'data';
  $handler->display->display_options['fields']['data_2']['label'] = 'Tätigkeit / Position';
  $handler->display->display_options['fields']['data_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['data_2']['format'] = 'key';
  $handler->display->display_options['fields']['data_2']['key'] = 'activity';
  /* Feld: Benutzer: Daten */
  $handler->display->display_options['fields']['data']['id'] = 'data';
  $handler->display->display_options['fields']['data']['table'] = 'users';
  $handler->display->display_options['fields']['data']['field'] = 'data';
  $handler->display->display_options['fields']['data']['label'] = 'Grund / Erklärung';
  $handler->display->display_options['fields']['data']['empty'] = 'Nicht angegeben';
  $handler->display->display_options['fields']['data']['format'] = 'key';
  $handler->display->display_options['fields']['data']['key'] = 'explanation';
  /* Feld: Benutzer: Membership request button */
  $handler->display->display_options['fields']['membership_request_button']['id'] = 'membership_request_button';
  $handler->display->display_options['fields']['membership_request_button']['table'] = 'users';
  $handler->display->display_options['fields']['membership_request_button']['field'] = 'membership_request_button';
  $handler->display->display_options['fields']['membership_request_button']['label'] = '';
  $handler->display->display_options['fields']['membership_request_button']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: Benutzer UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'users';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = '';
  $handler->display->display_options['fields']['uuid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uuid']['element_label_colon'] = FALSE;
  /* Filterkriterium: Benutzer: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Benutzer: Organisations (field_user_organisations) */
  $handler->display->display_options['filters']['field_user_organisations_target_id']['id'] = 'field_user_organisations_target_id';
  $handler->display->display_options['filters']['field_user_organisations_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['field_user_organisations_target_id']['field'] = 'field_user_organisations_target_id';
  $handler->display->display_options['filters']['field_user_organisations_target_id']['operator'] = 'empty';
  /* Filterkriterium: Benutzer: Rollen */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'empty';
  /* Filterkriterium: Benutzer: Benutzer-ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_membership_requests');
  $handler->display->display_options['path'] = 'user/membership-requests';
  $handler->display->display_options['menu']['title'] = 'Membership requests';
  $handler->display->display_options['menu']['weight'] = '-42';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['membership_requests'] = array(
    t('Master'),
    t('Membership requests'),
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
    t('Datum der Anfrage'),
    t('Organisation'),
    t('Tätigkeit / Position'),
    t('Grund / Erklärung'),
    t('Nicht angegeben'),
    t('Page'),
  );
  $export['membership_requests'] = $view;

  $view = new view();
  $view->name = 'people';
  $view->description = 'Default people view. Used on /people';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'people';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
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
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );

  /* Display: People Directory */
  $handler = $view->new_display('panel_pane', 'People Directory', 'directory');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'The people directory in the middle column of /people panel';
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
  $handler->display->display_options['empty']['area']['content'] = 'Die Suche im Personenverzeichnis lieferte leider keine Treffer.';
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
  /* Relationship: OG membership: OG Roles from membership */
  $handler->display->display_options['relationships']['og_users_roles']['id'] = 'og_users_roles';
  $handler->display->display_options['relationships']['og_users_roles']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_users_roles']['field'] = 'og_users_roles';
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['label'] = 'Group';
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
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul class="user_links"><!--<li><a class="action_user_chat" href="#">Chat</a></li>--><li><a class="action_user_message" href="/messages/new/[uid]">Nachricht</a></li></ul>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Profile: Arbeitsschwerpunkte */
  $handler->display->display_options['fields']['field_profile_competencies']['id'] = 'field_profile_competencies';
  $handler->display->display_options['fields']['field_profile_competencies']['table'] = 'field_data_field_profile_competencies';
  $handler->display->display_options['fields']['field_profile_competencies']['field'] = 'field_profile_competencies';
  $handler->display->display_options['fields']['field_profile_competencies']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_competencies']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_profile_competencies']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_profile_competencies']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_profile_competencies']['field_api_classes'] = TRUE;
  /* Field: Profile: Interessen */
  $handler->display->display_options['fields']['field_profile_interests']['id'] = 'field_profile_interests';
  $handler->display->display_options['fields']['field_profile_interests']['table'] = 'field_data_field_profile_interests';
  $handler->display->display_options['fields']['field_profile_interests']['field'] = 'field_profile_interests';
  $handler->display->display_options['fields']['field_profile_interests']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_interests']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_profile_interests']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_profile_interests']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_profile_interests']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_profile_interests']['field_api_classes'] = TRUE;
  /* Field: Profile: Sportarten */
  $handler->display->display_options['fields']['field_profile_sports']['id'] = 'field_profile_sports';
  $handler->display->display_options['fields']['field_profile_sports']['table'] = 'field_data_field_profile_sports';
  $handler->display->display_options['fields']['field_profile_sports']['field'] = 'field_profile_sports';
  $handler->display->display_options['fields']['field_profile_sports']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_profile_sports']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_profile_sports']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_profile_sports']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_profile_sports']['field_api_classes'] = TRUE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['exclude'] = TRUE;
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
  $handler->display->display_options['filters']['realname']['group'] = 1;
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
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_items'] = '0';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_field'] = 'realname';
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
  $handler->display->display_options['filters']['field_profile_sports_tid']['group'] = 1;
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
  $handler->display->display_options['filters']['field_profile_interests_tid']['group'] = 1;
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
  $handler->display->display_options['filters']['field_profile_competencies_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_profile_competencies_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_competencies_tid']['expose']['operator_id'] = 'field_profile_competencies_tid_op';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['expose']['label'] = 'Arbeitsschwerpunkte';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['expose']['description'] = 'Schränken sie die Personen mit kommagetrennten Stichwörtern für Sportarten, Interessen und Arbeitsschwerpunkten ein.';
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
    7 => 0,
  );
  $handler->display->display_options['filters']['field_profile_competencies_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_profile_competencies_tid']['vocabulary'] = 'profile_competencies';
  $handler->display->display_options['filters']['field_profile_competencies_tid']['error_message'] = FALSE;
  /* Filter criterion: User: Is online */
  $handler->display->display_options['filters']['is_online']['id'] = 'is_online';
  $handler->display->display_options['filters']['is_online']['table'] = 'users';
  $handler->display->display_options['filters']['is_online']['field'] = 'is_online';
  $handler->display->display_options['filters']['is_online']['value'] = 'All';
  $handler->display->display_options['filters']['is_online']['group'] = 1;
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
  $handler->display->display_options['filters']['uid']['group'] = 1;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  /* Filter criterion: User: Organisations (field_user_organisations) */
  $handler->display->display_options['filters']['field_user_organisations_target_id']['id'] = 'field_user_organisations_target_id';
  $handler->display->display_options['filters']['field_user_organisations_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['field_user_organisations_target_id']['field'] = 'field_user_organisations_target_id';
  $handler->display->display_options['filters']['field_user_organisations_target_id']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['field_user_organisations_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_user_organisations_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_organisations_target_id']['expose']['operator_id'] = 'field_user_organisations_target_id_op';
  $handler->display->display_options['filters']['field_user_organisations_target_id']['expose']['label'] = 'Organisationen';
  $handler->display->display_options['filters']['field_user_organisations_target_id']['expose']['operator'] = 'field_user_organisations_target_id_op';
  $handler->display->display_options['filters']['field_user_organisations_target_id']['expose']['identifier'] = 'field_user_organisations_target_id';
  $handler->display->display_options['filters']['field_user_organisations_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Profile: Salto - Dynamischer Themenfeld(er) Filter */
  $handler->display->display_options['filters']['field_profile_themenfelder_tid']['id'] = 'field_profile_themenfelder_tid';
  $handler->display->display_options['filters']['field_profile_themenfelder_tid']['table'] = 'field_data_field_profile_categories';
  $handler->display->display_options['filters']['field_profile_themenfelder_tid']['field'] = 'field_profile_themenfelder_tid';
  $handler->display->display_options['filters']['field_profile_themenfelder_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_profile_themenfelder_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_profile_themenfelder_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_profile_themenfelder_tid']['expose']['operator_id'] = 'field_profile_themenfelder_tid_op';
  $handler->display->display_options['filters']['field_profile_themenfelder_tid']['expose']['label'] = 'Themenfelder';
  $handler->display->display_options['filters']['field_profile_themenfelder_tid']['expose']['operator'] = 'field_profile_themenfelder_tid_op';
  $handler->display->display_options['filters']['field_profile_themenfelder_tid']['expose']['identifier'] = 'field_profile_themenfelder_tid';
  $handler->display->display_options['filters']['field_profile_themenfelder_tid']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Verbändegruppe (field_organisation_category) */
  $handler->display->display_options['filters']['field_organisation_category_value']['id'] = 'field_organisation_category_value';
  $handler->display->display_options['filters']['field_organisation_category_value']['table'] = 'field_data_field_organisation_category';
  $handler->display->display_options['filters']['field_organisation_category_value']['field'] = 'field_organisation_category_value';
  $handler->display->display_options['filters']['field_organisation_category_value']['relationship'] = 'og_membership_related_node_group';
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
  $handler->display->display_options['pane_title'] = 'Personenverzeichnis';
  $handler->display->display_options['pane_category']['name'] = 'Personen';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: People Online */
  $handler = $view->new_display('panel_pane', 'People Online', 'online');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Wer ist online?';
  $handler->display->display_options['display_description'] = 'Show Who\'s online on the people page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'picture' => 'picture',
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profilbild */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
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
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: User: Last access */
  $handler->display->display_options['sorts']['access']['id'] = 'access';
  $handler->display->display_options['sorts']['access']['table'] = 'users';
  $handler->display->display_options['sorts']['access']['field'] = 'access';
  $handler->display->display_options['sorts']['access']['order'] = 'DESC';
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: User: Is online */
  $handler->display->display_options['filters']['is_online']['id'] = 'is_online';
  $handler->display->display_options['filters']['is_online']['table'] = 'users';
  $handler->display->display_options['filters']['is_online']['field'] = 'is_online';
  $handler->display->display_options['filters']['is_online']['value'] = '1';
  $handler->display->display_options['pane_title'] = 'Personen online';
  $handler->display->display_options['pane_category']['name'] = 'Personen';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: People New */
  $handler = $view->new_display('panel_pane', 'People New', 'new');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Wer ist neu?';
  $handler->display->display_options['display_description'] = 'Show Who\'s new on the people page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'picture' => 'picture',
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profilbild */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
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
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['pane_title'] = 'Neue Personen';
  $handler->display->display_options['pane_category']['name'] = 'Personen';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: People Online in Og */
  $handler = $view->new_display('panel_pane', 'People Online in Og', 'panel_people_online_in_og');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Wer ist online?';
  $handler->display->display_options['display_description'] = 'Show Who\'s online in special og context';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'picture' => 'picture',
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no people online.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profilbild */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'user_30x30',
    'image_link' => 'content',
  );
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['filters']['access']['expose']['operator_id'] = 'access_op';
  $handler->display->display_options['filters']['access']['expose']['label'] = 'Letzter Zugriff';
  $handler->display->display_options['filters']['access']['expose']['operator'] = 'access_op';
  $handler->display->display_options['filters']['access']['expose']['identifier'] = 'access';
  $handler->display->display_options['filters']['access']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_title'] = 'People Online in Og';
  $handler->display->display_options['pane_category']['name'] = 'People, Groups';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'user',
      'context' => 'entity:clients_connection.configuration',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
  );

  /* Display: People in Og */
  $handler = $view->new_display('panel_pane', 'People in Og', 'panel_people_in_og');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mitglieder';
  $handler->display->display_options['display_description'] = 'Show who is member in special og context';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'picture' => 'picture',
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<?php

$nid = arg(1);
if(is_numeric($nid)) {
  $node = node_load($nid);
  if($node->type=="group") {
    echo \'<a href="/groups/!1/people">alle Mitglieder</a>\';
  }else if($node->type=="organisation") {
   echo \'<a href="/organisations/!1/people">alle Mitglieder</a>\';
  }
}

?>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<?php echo t(\'There are no members.\'); ?>

<br /><br /><br />

<div class="view-footer view-salto-empty-text">  
<?php
$nid = arg(1);
if(is_numeric($nid)) {
  $node = node_load($nid);
  if($node->type=="group") {
    echo \'<a href="/groups/\'.$nid.\'/people">alle Mitglieder</a>\';
  }else if($node->type=="organisation") {
   echo \'<a href="/organisations/\'.$nid.\'/people">alle Mitglieder</a>\';
  }
}
?>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'php_code';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profilbild */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'user_30x30',
    'image_link' => 'content',
  );
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'People in Og';
  $handler->display->display_options['pane_category']['name'] = 'People, Groups';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'user',
      'context' => 'entity:clients_connection.configuration',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG membership: Group ID',
    ),
  );
  $translatables['people'] = array(
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
    t('People Directory'),
    t('The people directory in the middle column of /people panel'),
    t('more'),
    t('Zeige Ergebnisse @start bis @end von insgesamt @total'),
    t('Die Suche im Personenverzeichnis lieferte leider keine Treffer.'),
    t('Hauptprofil'),
    t('OG membership from user'),
    t('OG Roles from OG membership'),
    t('Group'),
    t('<ul class="user_links"><!--<li><a class="action_user_chat" href="#">Chat</a></li>--><li><a class="action_user_message" href="/messages/new/[uid]">Nachricht</a></li></ul>'),
    t('Arbeitsschwerpunkte'),
    t('Interessen'),
    t('Sportarten'),
    t('Real name'),
    t('Vorname'),
    t('Name'),
    t('Schränken sie die Personen mit kommagetrennten Stichwörtern für Sportarten, Interessen und Arbeitsschwerpunkten ein.'),
    t('Online Status'),
    t('Organisationen'),
    t('Themenfelder'),
    t('Verbändegruppe'),
    t('Personenverzeichnis'),
    t('Personen'),
    t('People Online'),
    t('Wer ist online?'),
    t('Show Who\'s online on the people page'),
    t('Personen online'),
    t('People New'),
    t('Wer ist neu?'),
    t('Show Who\'s new on the people page'),
    t('Neue Personen'),
    t('People Online in Og'),
    t('Show Who\'s online in special og context'),
    t('There are no people online.'),
    t('Alle'),
    t('Letzter Zugriff'),
    t('People, Groups'),
    t('People in Og'),
    t('Mitglieder'),
    t('Show who is member in special og context'),
    t('<?php

$nid = arg(1);
if(is_numeric($nid)) {
  $node = node_load($nid);
  if($node->type=="group") {
    echo \'<a href="/groups/!1/people">alle Mitglieder</a>\';
  }else if($node->type=="organisation") {
   echo \'<a href="/organisations/!1/people">alle Mitglieder</a>\';
  }
}

?>'),
    t('<?php echo t(\'There are no members.\'); ?>

<br /><br /><br />

<div class="view-footer view-salto-empty-text">  
<?php
$nid = arg(1);
if(is_numeric($nid)) {
  $node = node_load($nid);
  if($node->type=="group") {
    echo \'<a href="/groups/\'.$nid.\'/people">alle Mitglieder</a>\';
  }else if($node->type=="organisation") {
   echo \'<a href="/organisations/\'.$nid.\'/people">alle Mitglieder</a>\';
  }
}
?>
</div>'),
  );
  $export['people'] = $view;

  return $export;
}
