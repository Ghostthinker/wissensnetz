<?php
/**
 * @file
 * salto_statistics.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function salto_statistics_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'statistics';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Statistiken (Übersicht)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Statistik (Übersicht)';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Es wurde keine Tagesstatistik gefunden.';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Field: Beitrag: beiträge */
  $handler->display->display_options['fields']['field_beitraege']['id'] = 'field_beitraege';
  $handler->display->display_options['fields']['field_beitraege']['table'] = 'field_data_field_beitraege';
  $handler->display->display_options['fields']['field_beitraege']['field'] = 'field_beitraege';
  $handler->display->display_options['fields']['field_beitraege']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_beitraege']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: beitraege_br */
  $handler->display->display_options['fields']['field_beitraege_br']['id'] = 'field_beitraege_br';
  $handler->display->display_options['fields']['field_beitraege_br']['table'] = 'field_data_field_beitraege_br';
  $handler->display->display_options['fields']['field_beitraege_br']['field'] = 'field_beitraege_br';
  $handler->display->display_options['fields']['field_beitraege_br']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_beitraege_br']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: beitraege_pt */
  $handler->display->display_options['fields']['field_beitraege_pt']['id'] = 'field_beitraege_pt';
  $handler->display->display_options['fields']['field_beitraege_pt']['table'] = 'field_data_field_beitraege_pt';
  $handler->display->display_options['fields']['field_beitraege_pt']['field'] = 'field_beitraege_pt';
  $handler->display->display_options['fields']['field_beitraege_pt']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_beitraege_pt']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: besucher_br */
  $handler->display->display_options['fields']['field_besucher_br']['id'] = 'field_besucher_br';
  $handler->display->display_options['fields']['field_besucher_br']['table'] = 'field_data_field_besucher_br';
  $handler->display->display_options['fields']['field_besucher_br']['field'] = 'field_besucher_br';
  $handler->display->display_options['fields']['field_besucher_br']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_besucher_br']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: besucher_pt */
  $handler->display->display_options['fields']['field_besucher_pt']['id'] = 'field_besucher_pt';
  $handler->display->display_options['fields']['field_besucher_pt']['table'] = 'field_data_field_besucher_pt';
  $handler->display->display_options['fields']['field_besucher_pt']['field'] = 'field_besucher_pt';
  $handler->display->display_options['fields']['field_besucher_pt']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_besucher_pt']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: gruppen_br */
  $handler->display->display_options['fields']['field_gruppen_br']['id'] = 'field_gruppen_br';
  $handler->display->display_options['fields']['field_gruppen_br']['table'] = 'field_data_field_gruppen_br';
  $handler->display->display_options['fields']['field_gruppen_br']['field'] = 'field_gruppen_br';
  $handler->display->display_options['fields']['field_gruppen_br']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gruppen_br']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: gruppen_pt */
  $handler->display->display_options['fields']['field_gruppen_pt']['id'] = 'field_gruppen_pt';
  $handler->display->display_options['fields']['field_gruppen_pt']['table'] = 'field_data_field_gruppen_pt';
  $handler->display->display_options['fields']['field_gruppen_pt']['field'] = 'field_gruppen_pt';
  $handler->display->display_options['fields']['field_gruppen_pt']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gruppen_pt']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: kommentare_br */
  $handler->display->display_options['fields']['field_kommentare_br']['id'] = 'field_kommentare_br';
  $handler->display->display_options['fields']['field_kommentare_br']['table'] = 'field_data_field_kommentare_br';
  $handler->display->display_options['fields']['field_kommentare_br']['field'] = 'field_kommentare_br';
  $handler->display->display_options['fields']['field_kommentare_br']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kommentare_br']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: kommentare_pt */
  $handler->display->display_options['fields']['field_kommentare_pt']['id'] = 'field_kommentare_pt';
  $handler->display->display_options['fields']['field_kommentare_pt']['table'] = 'field_data_field_kommentare_pt';
  $handler->display->display_options['fields']['field_kommentare_pt']['field'] = 'field_kommentare_pt';
  $handler->display->display_options['fields']['field_kommentare_pt']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kommentare_pt']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: mitglieder pro gruppe_br */
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe_br']['id'] = 'field_mitglieder_pro_gruppe_br';
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe_br']['table'] = 'field_data_field_mitglieder_pro_gruppe_br';
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe_br']['field'] = 'field_mitglieder_pro_gruppe_br';
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe_br']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe_br']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: mitglieder pro gruppe_pt */
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe_pt']['id'] = 'field_mitglieder_pro_gruppe_pt';
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe_pt']['table'] = 'field_data_field_mitglieder_pro_gruppe_pt';
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe_pt']['field'] = 'field_mitglieder_pro_gruppe_pt';
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe_pt']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe_pt']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: registrated_users_br */
  $handler->display->display_options['fields']['field_registrated_users_br']['id'] = 'field_registrated_users_br';
  $handler->display->display_options['fields']['field_registrated_users_br']['table'] = 'field_data_field_registrated_users_br';
  $handler->display->display_options['fields']['field_registrated_users_br']['field'] = 'field_registrated_users_br';
  $handler->display->display_options['fields']['field_registrated_users_br']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_registrated_users_br']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: registrated_users_pt */
  $handler->display->display_options['fields']['field_registrated_users_pt']['id'] = 'field_registrated_users_pt';
  $handler->display->display_options['fields']['field_registrated_users_pt']['table'] = 'field_data_field_registrated_users_pt';
  $handler->display->display_options['fields']['field_registrated_users_pt']['field'] = 'field_registrated_users_pt';
  $handler->display->display_options['fields']['field_registrated_users_pt']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_registrated_users_pt']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: seitenaufrufe_br */
  $handler->display->display_options['fields']['field_seitenaufrufe_br']['id'] = 'field_seitenaufrufe_br';
  $handler->display->display_options['fields']['field_seitenaufrufe_br']['table'] = 'field_data_field_seitenaufrufe_br';
  $handler->display->display_options['fields']['field_seitenaufrufe_br']['field'] = 'field_seitenaufrufe_br';
  $handler->display->display_options['fields']['field_seitenaufrufe_br']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_seitenaufrufe_br']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: seitenaufrufe_pt */
  $handler->display->display_options['fields']['field_seitenaufrufe_pt']['id'] = 'field_seitenaufrufe_pt';
  $handler->display->display_options['fields']['field_seitenaufrufe_pt']['table'] = 'field_data_field_seitenaufrufe_pt';
  $handler->display->display_options['fields']['field_seitenaufrufe_pt']['field'] = 'field_seitenaufrufe_pt';
  $handler->display->display_options['fields']['field_seitenaufrufe_pt']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_seitenaufrufe_pt']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: besucher */
  $handler->display->display_options['fields']['field_besucher']['id'] = 'field_besucher';
  $handler->display->display_options['fields']['field_besucher']['table'] = 'field_data_field_besucher';
  $handler->display->display_options['fields']['field_besucher']['field'] = 'field_besucher';
  $handler->display->display_options['fields']['field_besucher']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_besucher']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: gruppen */
  $handler->display->display_options['fields']['field_gruppen']['id'] = 'field_gruppen';
  $handler->display->display_options['fields']['field_gruppen']['table'] = 'field_data_field_gruppen';
  $handler->display->display_options['fields']['field_gruppen']['field'] = 'field_gruppen';
  $handler->display->display_options['fields']['field_gruppen']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gruppen']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: kommentare */
  $handler->display->display_options['fields']['field_kommentare']['id'] = 'field_kommentare';
  $handler->display->display_options['fields']['field_kommentare']['table'] = 'field_data_field_kommentare';
  $handler->display->display_options['fields']['field_kommentare']['field'] = 'field_kommentare';
  $handler->display->display_options['fields']['field_kommentare']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kommentare']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: mitglieder pro gruppe */
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe']['id'] = 'field_mitglieder_pro_gruppe';
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe']['table'] = 'field_data_field_mitglieder_pro_gruppe';
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe']['field'] = 'field_mitglieder_pro_gruppe';
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mitglieder_pro_gruppe']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: registrated_users */
  $handler->display->display_options['fields']['field_registrated_users']['id'] = 'field_registrated_users';
  $handler->display->display_options['fields']['field_registrated_users']['table'] = 'field_data_field_registrated_users';
  $handler->display->display_options['fields']['field_registrated_users']['field'] = 'field_registrated_users';
  $handler->display->display_options['fields']['field_registrated_users']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_registrated_users']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Beitrag: seitenaufrufe */
  $handler->display->display_options['fields']['field_seitenaufrufe']['id'] = 'field_seitenaufrufe';
  $handler->display->display_options['fields']['field_seitenaufrufe']['table'] = 'field_data_field_seitenaufrufe';
  $handler->display->display_options['fields']['field_seitenaufrufe']['field'] = 'field_seitenaufrufe';
  $handler->display->display_options['fields']['field_seitenaufrufe']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_seitenaufrufe']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php

$role = _salto_statistics_node_get_view_role();
  if($role == SALTO_STATISTICS_ROLE_PROJEKTTEAM) {
    echo salto_statistics_global_render_field(\'Beiträge\', $data->field_field_beitraege_pt);
    echo salto_statistics_global_render_field(\'Besucher\', $data->field_field_besucher_pt);
    echo salto_statistics_global_render_field(\'Gruppen\', $data->field_field_gruppen_pt);
    echo salto_statistics_global_render_field(\'Kommentare\', $data->field_field_kommentare_pt);
    echo salto_statistics_global_render_field(\'Mitglieder pro Gruppe\', $data->field_field_mitglieder_pro_gruppe_pt);
    echo salto_statistics_global_render_field(\'Aktive Benutzerkonten\', $data->field_field_registrated_users_pt);
    echo salto_statistics_global_render_field(\'Seitenaufrufe\', $data->field_field_seitenaufrufe_pt);
  }else if($role == SALTO_STATISTICS_ROLE_BILDUNGSREFERENTEN) {
    echo salto_statistics_global_render_field(\'Beiträge\', $data->field_field_beitraege_br);
    echo salto_statistics_global_render_field(\'Besucher\', $data->field_field_besucher_br);
    echo salto_statistics_global_render_field(\'Gruppen\', $data->field_field_gruppen_br);
    echo salto_statistics_global_render_field(\'Kommentare\', $data->field_field_kommentare_br);
    echo salto_statistics_global_render_field(\'Mitglieder pro Gruppe\', $data->field_field_mitglieder_pro_gruppe_br);
    echo salto_statistics_global_render_field(\'Aktive Benutzerkonten\', $data->field_field_registrated_users_br);
    echo salto_statistics_global_render_field(\'Seitenaufrufe\', $data->field_field_seitenaufrufe_br);
  }else{
    echo salto_statistics_global_render_field(\'Beiträge\', $data->field_field_beitraege);
    echo salto_statistics_global_render_field(\'Besucher\', $data->field_field_besucher);
    echo salto_statistics_global_render_field(\'Gruppen\', $data->field_field_gruppen);
    echo salto_statistics_global_render_field(\'Kommentare\', $data->field_field_kommentare);
    echo salto_statistics_global_render_field(\'Mitglieder pro Gruppe\', $data->field_field_mitglieder_pro_gruppe);
    echo salto_statistics_global_render_field(\'Aktive Benutzerkonten\', $data->field_field_registrated_users);
    echo salto_statistics_global_render_field(\'Seitenaufrufe\', $data->field_field_seitenaufrufe);
  }
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'statistics_daily' => 'statistics_daily',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Typ';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Datum';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['default_date'] = '-1 day';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Rolle';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'user_role_soft_1';
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['type_1']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['type_1']['group_info']['label'] = 'Rolle';
  $handler->display->display_options['filters']['type_1']['group_info']['identifier'] = 'user_role_soft_1';
  $handler->display->display_options['filters']['type_1']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Projektteam',
      'operator' => 'in',
      'value' => array(
        'all' => 'all',
        'kb_article' => 0,
        'ausbildungskonzept' => 0,
        'book' => 0,
        'kb_report' => 0,
        'earemote' => 0,
        'article' => 0,
        'kb_question' => 0,
        'shared_post' => 0,
        'group' => 0,
        'help' => 0,
        'weiterbildungsmassnahme' => 0,
        'organisation' => 0,
        'page' => 0,
        'statistics_daily' => 0,
      ),
    ),
    2 => array(
      'title' => 'Bildunsverantwortliche',
      'operator' => 'in',
      'value' => array(
        'all' => 'all',
        'kb_article' => 0,
        'ausbildungskonzept' => 0,
        'book' => 0,
        'kb_report' => 0,
        'earemote' => 0,
        'article' => 0,
        'kb_question' => 0,
        'shared_post' => 0,
        'group' => 0,
        'help' => 0,
        'weiterbildungsmassnahme' => 0,
        'organisation' => 0,
        'page' => 0,
        'statistics_daily' => 0,
      ),
    ),
  );

  /* Display: Statistik (Übersicht) */
  $handler = $view->new_display('panel_pane', 'Statistik (Übersicht)', 'panel_statistics_overview');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'Statistik';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Statistik (Übersicht) Export */
  $handler = $view->new_display('views_data_export', 'Statistik (Übersicht) Export', 'data_export_statistics_overview');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Statistik (Übersicht) Export';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['attach_text'] = 'Statistik (Übersicht) - XLS';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-yyyy-%timestamp-mm-%timestamp-dd Statistik (Übersicht).xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'statistics/export/xls';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'panel_statistics_overview' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['statistics'] = array(
    t('Master'),
    t('Statistik (Übersicht)'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Es wurde keine Tagesstatistik gefunden.'),
    t('beiträge'),
    t('beitraege_br'),
    t('beitraege_pt'),
    t('besucher_br'),
    t('besucher_pt'),
    t('gruppen_br'),
    t('gruppen_pt'),
    t('kommentare_br'),
    t('kommentare_pt'),
    t('mitglieder pro gruppe_br'),
    t('mitglieder pro gruppe_pt'),
    t('registrated_users_br'),
    t('registrated_users_pt'),
    t('seitenaufrufe_br'),
    t('seitenaufrufe_pt'),
    t('besucher'),
    t('gruppen'),
    t('kommentare'),
    t('mitglieder pro gruppe'),
    t('registrated_users'),
    t('seitenaufrufe'),
    t('Typ'),
    t('Datum'),
    t('Rolle'),
    t('more'),
    t('Statistik'),
    t('Statistik (Übersicht) Export'),
  );
  $export['statistics'] = $view;

  $view = new view();
  $view->name = 'statistics_groups';
  $view->description = 'exposed filter overridden in salto_statistics_form_alter';
  $view->tag = 'salto, statistics';
  $view->base_table = 'node';
  $view->human_name = 'Statistics - Groups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Statistik (Gruppen)';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
  );
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'totalcount' => 'totalcount',
    'php_1' => 'php_1',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'totalcount' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'Keine Ergebnisse gefunden.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: OG membership: OG membership from Beitrag group */
  $handler->display->display_options['relationships']['og_membership_rel_group']['id'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel_group']['field'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Anzahl der Gruppenmitglieder';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return salto_statistics_count_group_members($row->nid);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?
 echo $value;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Anzahl der Gruppenbeiträge (Aktivitäten)';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return salto_statistics_count_group_nodes($row->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = ' <?php
print $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'group' => 'group',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: OG Mitgliedschaft: Entity_type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'og_membership';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['relationship'] = 'og_membership_rel_group';
  $handler->display->display_options['filters']['entity_type']['value'] = 'user';
  $handler->display->display_options['filters']['entity_type']['group'] = 1;
  $handler->display->display_options['filters']['entity_type']['expose']['operator_id'] = 'entity_type_op';
  $handler->display->display_options['filters']['entity_type']['expose']['label'] = 'Entity_type';
  $handler->display->display_options['filters']['entity_type']['expose']['operator'] = 'entity_type_op';
  $handler->display->display_options['filters']['entity_type']['expose']['identifier'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['entity_type']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['entity_type']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['entity_type']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['entity_type']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['entity_type']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Von';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter_soft_from_1';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Bis';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_soft_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: OG Mitgliedschaft: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel_group';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Typ';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['type_1']['group_info']['label'] = 'Rolle';
  $handler->display->display_options['filters']['type_1']['group_info']['identifier'] = 'user_role_soft_1';
  $handler->display->display_options['filters']['type_1']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Projektteam',
      'operator' => 'in',
      'value' => array(
        'all' => 'all',
        'kb_article' => 0,
        'ausbildungskonzept' => 0,
        'book' => 0,
        'kb_report' => 0,
        'earemote' => 0,
        'article' => 0,
        'kb_question' => 0,
        'shared_post' => 0,
        'group' => 0,
        'help' => 0,
        'weiterbildungsmassnahme' => 0,
        'organisation' => 0,
        'page' => 0,
        'statistics_daily' => 0,
      ),
    ),
    2 => array(
      'title' => 'Bildungsverantwortliche',
      'operator' => 'in',
      'value' => array(
        'all' => 'all',
        'kb_article' => 0,
        'ausbildungskonzept' => 0,
        'book' => 0,
        'kb_report' => 0,
        'earemote' => 0,
        'article' => 0,
        'kb_question' => 0,
        'shared_post' => 0,
        'group' => 0,
        'help' => 0,
        'weiterbildungsmassnahme' => 0,
        'organisation' => 0,
        'page' => 0,
        'statistics_daily' => 0,
      ),
    ),
  );

  /* Display: (!) Statistics - Groups */
  $handler = $view->new_display('panel_pane', '(!) Statistics - Groups', 'panel_statistics_groups');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'php_1' => 'php_1',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
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
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['pane_title'] = 'Statistics - Groups';
  $handler->display->display_options['pane_category']['name'] = 'Statistik';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Statistik (Groups) Export */
  $handler = $view->new_display('views_data_export', 'Statistik (Groups) Export', 'data_export_statistics_nodes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Statistik (Gruppen) Export';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['attach_text'] = 'Statistik (Gruppen) - XLS';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-yyyy-%timestamp-mm-%timestamp-dd Statistik (Gruppen).xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'statistics/groups/export/xls';
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['statistics_groups'] = array(
    t('Master'),
    t('Statistik (Gruppen)'),
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
    t('Keine Ergebnisse gefunden.'),
    t('OG membership from node group'),
    t('Anzahl der Gruppenmitglieder'),
    t('Anzahl der Gruppenbeiträge (Aktivitäten)'),
    t('Entity_type'),
    t('Von'),
    t('Bis'),
    t('Typ'),
    t('Rolle'),
    t('(!) Statistics - Groups'),
    t('more'),
    t('Statistics - Groups'),
    t('Statistik'),
    t('Statistik (Groups) Export'),
    t('Statistik (Gruppen) Export'),
  );
  $export['statistics_groups'] = $view;

  $view = new view();
  $view->name = 'statistics_nodes';
  $view->description = 'exposed filter overridden in salto_statistics_form_alter';
  $view->tag = 'salto, statistics';
  $view->base_table = 'node';
  $view->human_name = 'Statistics - Nodes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Statistik (Inhalte)';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
  );
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'php' => 'php',
    'php_1' => 'php_1',
    'php_2' => 'php_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'Keine Ergebnisse gefunden.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Seitenaufrufe Page Impressions';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return salto_statistics_node_count_visitors_hits($row->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
  echo $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Kommentierhäufigkeit';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return salto_statistics_node_count_comments($row->nid);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?
  echo $value;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Bearbeitungshäufigkeit';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = 'return salto_statistics_node_count_edits($row->nid);';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?
  echo $value;
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'help' => 'help',
    'page' => 'page',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Von';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter_soft_from_1';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Bis';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Typ';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['type_1']['group_info']['label'] = 'Rolle';
  $handler->display->display_options['filters']['type_1']['group_info']['identifier'] = 'user_role_soft_1';
  $handler->display->display_options['filters']['type_1']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Projektteam',
      'operator' => 'in',
      'value' => array(
        'all' => 'all',
        'kb_article' => 0,
        'ausbildungskonzept' => 0,
        'book' => 0,
        'kb_report' => 0,
        'earemote' => 0,
        'article' => 0,
        'kb_question' => 0,
        'shared_post' => 0,
        'group' => 0,
        'help' => 0,
        'weiterbildungsmassnahme' => 0,
        'organisation' => 0,
        'page' => 0,
        'statistics_daily' => 0,
      ),
    ),
    2 => array(
      'title' => 'Bildungsverantwortliche',
      'operator' => 'in',
      'value' => array(
        'all' => 'all',
        'kb_article' => 0,
        'ausbildungskonzept' => 0,
        'book' => 0,
        'kb_report' => 0,
        'earemote' => 0,
        'article' => 0,
        'kb_question' => 0,
        'shared_post' => 0,
        'group' => 0,
        'help' => 0,
        'weiterbildungsmassnahme' => 0,
        'organisation' => 0,
        'page' => 0,
        'statistics_daily' => 0,
      ),
    ),
  );

  /* Display: (!) Statistik (Inhalte) */
  $handler = $view->new_display('panel_pane', '(!) Statistik (Inhalte)', 'panel_statistics_nodes');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['pane_title'] = 'Statistik (Inhalte)';
  $handler->display->display_options['pane_category']['name'] = 'Statistik';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'data_export_statistics_nodes');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['attach_text'] = 'Statistik (Inhalte) - XLS';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-yyyy-%timestamp-mm-%timestamp-dd Statistik (Inhalte).xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'statistics/nodes/export/xls';
  $translatables['statistics_nodes'] = array(
    t('Master'),
    t('Statistik (Inhalte)'),
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
    t('Keine Ergebnisse gefunden.'),
    t('Seitenaufrufe Page Impressions'),
    t('Kommentierhäufigkeit'),
    t('Bearbeitungshäufigkeit'),
    t('Von'),
    t('Bis'),
    t('Typ'),
    t('Rolle'),
    t('(!) Statistik (Inhalte)'),
    t('more'),
    t('Statistik'),
    t('Data export'),
  );
  $export['statistics_nodes'] = $view;

  $view = new view();
  $view->name = 'statistics_people';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Statistics - People';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Statistik (Personen)';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
  );
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'name' => 'name',
    'php_5' => 'php_5',
    'php' => 'php',
    'php_1' => 'php_1',
    'php_2' => 'php_2',
    'php_3' => 'php_3',
    'php_4' => 'php_4',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_5' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_3' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_4' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'Keine Ergebnisse gefunden.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'Neue Beiträge';
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_value'] = 'return salto_statistics_people_count_nodes($row->uid);';
  $handler->display->display_options['fields']['php_5']['php_output'] = '<? echo $value; ?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Hochgeladene Dateien';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return salto_statistics_people_count_files($row->uid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Kommentare';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return  salto_statistics_people_count_comments($row->uid);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?
  echo $value;
?> ';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Bearbeitungshäufigkeit';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = 'return salto_statistics_people_count_edits($row->uid);';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<? echo $value; ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'Page Impressions';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_value'] = '  return salto_statistics_people_count_page_impressions($row->uid);
';
  $handler->display->display_options['fields']['php_3']['php_output'] = '<? echo $value; ?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '5';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'Besuche';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_value'] = 'return salto_statistics_people_count_visits($row->uid);
';
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?
  echo $value;
?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '4';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
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
  /* Filter criterion: Date: Date (users) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'users';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'Von';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_soft_from_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'users.created' => 'users.created',
  );
  /* Filter criterion: Date: Date (users) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'users';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Bis';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['year_range'] = '-3:+0';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'users.created' => 'users.created',
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Rollen';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['rid']['group_info']['label'] = 'Rolle';
  $handler->display->display_options['filters']['rid']['group_info']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Bildungsverantwortliche',
      'operator' => 'empty',
      'value' => array(
        'all' => 'all',
      ),
    ),
    2 => array(
      'title' => 'Projektteam',
      'operator' => 'or',
      'value' => array(
        6 => '6',
      ),
    ),
    3 => array(
      'title' => '',
      'operator' => 'or',
      'value' => array(),
    ),
  );

  /* Display: Statistics - People */
  $handler = $view->new_display('panel_pane', 'Statistics - People', 'panel_statistics_people');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'Statistik';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Statistik (Personen) Export */
  $handler = $view->new_display('views_data_export', 'Statistik (Personen) Export', 'data_export_statistics_people');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Statistik (Personen) Export';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['attach_text'] = 'Statistik (Übersicht) - XLS';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%timestamp-yyyy-%timestamp-mm-%timestamp-dd Statistik (Personen).xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'statistics/people/export/xls';
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['statistics_people'] = array(
    t('Master'),
    t('Statistik (Personen)'),
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
    t('Keine Ergebnisse gefunden.'),
    t('Uid'),
    t('Name'),
    t('Neue Beiträge'),
    t('Hochgeladene Dateien'),
    t('Kommentare'),
    t('Bearbeitungshäufigkeit'),
    t('Page Impressions'),
    t('Besuche'),
    t('Von'),
    t('Bis'),
    t('Rollen'),
    t('Rolle'),
    t('Statistics - People'),
    t('more'),
    t('Statistik'),
    t('Statistik (Personen) Export'),
  );
  $export['statistics_people'] = $view;

  return $export;
}
