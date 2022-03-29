<?php

/**
 * @file
 * salto_files.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function salto_files_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'kb_files';
  $view->description = 'Default files view. Used on /knowledge/files';
  $view->tag = 'media, default';
  $view->base_table = 'file_managed';
  $view->human_name = 'kb_files';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Materialien';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'media_browser',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '18';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '6';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'listing';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Materialien verfügbar.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: File: User who uploaded */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['exclude'] = TRUE;
  /* Field: File: Rendered */
  $handler->display->display_options['fields']['rendered']['id'] = 'rendered';
  $handler->display->display_options['fields']['rendered']['table'] = 'file_managed';
  $handler->display->display_options['fields']['rendered']['field'] = 'rendered';
  $handler->display->display_options['fields']['rendered']['label'] = '';
  $handler->display->display_options['fields']['rendered']['alter']['path'] = 'file/[fid]';
  $handler->display->display_options['fields']['rendered']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['rendered']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered']['file_view_mode'] = 'colorbox';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_wrapper_class'] = 'statistics_counter';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '//return salto_files_render_views_count($row->fid);

$views = salto_files_get_views_count($row->fid);
$count = $views[\'totalcount\'] ? $views[\'totalcount\'] : 0;
return $count ;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: File: Download link */
  $handler->display->display_options['fields']['download']['id'] = 'download';
  $handler->display->display_options['fields']['download']['table'] = 'file_managed';
  $handler->display->display_options['fields']['download']['field'] = 'download';
  $handler->display->display_options['fields']['download']['label'] = '';
  $handler->display->display_options['fields']['download']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['download']['alter']['text'] = ' ';
  $handler->display->display_options['fields']['download']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['download']['alter']['link_class'] = 'icon-download';
  $handler->display->display_options['fields']['download']['element_label_colon'] = FALSE;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['filename']['alter']['path'] = 'file/[fid]';
  $handler->display->display_options['fields']['filename']['alter']['alt'] = '[filename]';
  $handler->display->display_options['fields']['filename']['alter']['max_length'] = '10';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['filename']['link_to_file'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['exclude'] = TRUE;
  /* Sort criterion: File: Upload date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Sort criterion: File: Name */
  $handler->display->display_options['sorts']['filename']['id'] = 'filename';
  $handler->display->display_options['sorts']['filename']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['filename']['field'] = 'filename';
  /* Filter criterion: File: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'file_managed';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: File: Path */
  $handler->display->display_options['filters']['uri']['id'] = 'uri';
  $handler->display->display_options['filters']['uri']['table'] = 'file_managed';
  $handler->display->display_options['filters']['uri']['field'] = 'uri';
  $handler->display->display_options['filters']['uri']['operator'] = 'not';
  $handler->display->display_options['filters']['uri']['value'] = '/user_pictures/';
  $handler->display->display_options['filters']['uri']['group'] = 1;
  /* Filter criterion: File: Name */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['group'] = 1;
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  $handler->display->display_options['filters']['filename']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['filename']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['filename']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['filename']['expose']['autocomplete_field'] = 'filename';
  $handler->display->display_options['filters']['filename']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['filename']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['filename']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Field: Schlagworte (field_post_tags) */
  $handler->display->display_options['filters']['field_post_tags_tid']['id'] = 'field_post_tags_tid';
  $handler->display->display_options['filters']['field_post_tags_tid']['table'] = 'field_data_field_post_tags';
  $handler->display->display_options['filters']['field_post_tags_tid']['field'] = 'field_post_tags_tid';
  $handler->display->display_options['filters']['field_post_tags_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_post_tags_tid']['value'] = '';
  $handler->display->display_options['filters']['field_post_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_post_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['operator_id'] = 'field_post_tags_tid_op';
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['label'] = 'Schlagworte';
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['operator'] = 'field_post_tags_tid_op';
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['identifier'] = 'field_post_tags_tid';
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_post_tags_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_post_tags_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['field_post_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Typ';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Realname: Name */
  $handler->display->display_options['filters']['realname']['id'] = 'realname';
  $handler->display->display_options['filters']['realname']['table'] = 'realname';
  $handler->display->display_options['filters']['realname']['field'] = 'realname';
  $handler->display->display_options['filters']['realname']['relationship'] = 'uid';
  $handler->display->display_options['filters']['realname']['operator'] = 'contains';
  $handler->display->display_options['filters']['realname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['realname']['expose']['operator_id'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['label'] = 'Eigentümer';
  $handler->display->display_options['filters']['realname']['expose']['operator'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['identifier'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_field'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Field: Gruppe (field_og_group) */
  $handler->display->display_options['filters']['field_og_group_target_id']['id'] = 'field_og_group_target_id';
  $handler->display->display_options['filters']['field_og_group_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['field_og_group_target_id']['field'] = 'field_og_group_target_id';
  $handler->display->display_options['filters']['field_og_group_target_id']['operator'] = 'empty';

  /* Display: Files Directory */
  $handler = $view->new_display('panel_pane', 'Files Directory', 'files_directory');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File: User who uploaded */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: OG membership: OG membership from File */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: File: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'percent',
    'tag' => '',
    'function' => 'average',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy Entity Index: Has taxonomy term ID on File (with depth and indexed in taxonomy_entity_index) */
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['id'] = 'taxonomy_entity_index_tid_depth';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['table'] = 'file_managed';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['field'] = 'taxonomy_entity_index_tid_depth';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['exception']['title'] = 'Materialien';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['default_argument_options']['code'] = '$u_tf  = salto_user_get_themenfelder();
$tids = array();
foreach($u_tf  as $term) {
 $tids[] = $term->tid;
}
return  implode("+", $tids);';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['depth'] = '4';
  $handler->display->display_options['arguments']['taxonomy_entity_index_tid_depth']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: File: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'file_managed';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: File: Name */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['group'] = 1;
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  $handler->display->display_options['filters']['filename']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['filename']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['filename']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['filename']['expose']['autocomplete_field'] = 'filename';
  $handler->display->display_options['filters']['filename']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['filename']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['filename']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Field: Schlagworte (field_post_tags) */
  $handler->display->display_options['filters']['field_post_tags_tid']['id'] = 'field_post_tags_tid';
  $handler->display->display_options['filters']['field_post_tags_tid']['table'] = 'field_data_field_post_tags';
  $handler->display->display_options['filters']['field_post_tags_tid']['field'] = 'field_post_tags_tid';
  $handler->display->display_options['filters']['field_post_tags_tid']['operator'] = 'and';
  $handler->display->display_options['filters']['field_post_tags_tid']['value'] = '';
  $handler->display->display_options['filters']['field_post_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_post_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['operator_id'] = 'field_post_tags_tid_op';
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['label'] = 'Schlagworte';
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['operator'] = 'field_post_tags_tid_op';
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['identifier'] = 'field_post_tags_tid';
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_post_tags_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_post_tags_tid']['vocabulary'] = 'tags';
  $handler->display->display_options['filters']['field_post_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Typ';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Realname: Name */
  $handler->display->display_options['filters']['realname']['id'] = 'realname';
  $handler->display->display_options['filters']['realname']['table'] = 'realname';
  $handler->display->display_options['filters']['realname']['field'] = 'realname';
  $handler->display->display_options['filters']['realname']['relationship'] = 'uid';
  $handler->display->display_options['filters']['realname']['operator'] = 'contains';
  $handler->display->display_options['filters']['realname']['group'] = 1;
  $handler->display->display_options['filters']['realname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['realname']['expose']['operator_id'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['label'] = 'Eigentümer';
  $handler->display->display_options['filters']['realname']['expose']['operator'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['identifier'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_field'] = 'realname';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: File: Path */
  $handler->display->display_options['filters']['uri']['id'] = 'uri';
  $handler->display->display_options['filters']['uri']['table'] = 'file_managed';
  $handler->display->display_options['filters']['uri']['field'] = 'uri';
  $handler->display->display_options['filters']['uri']['operator'] = 'not';
  $handler->display->display_options['filters']['uri']['value'] = '/user_pictures/';
  $handler->display->display_options['filters']['uri']['group'] = 1;
  /* Filter criterion: File Usage: Entity type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'file_usage';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['operator'] = '!=';
  $handler->display->display_options['filters']['type_1']['value'] = 'profile2';
  $handler->display->display_options['filters']['type_1']['group'] = 2;
  /* Filter criterion: File Usage: Entity type */
  $handler->display->display_options['filters']['type_2']['id'] = 'type_2';
  $handler->display->display_options['filters']['type_2']['table'] = 'file_usage';
  $handler->display->display_options['filters']['type_2']['field'] = 'type';
  $handler->display->display_options['filters']['type_2']['operator'] = 'empty';
  $handler->display->display_options['filters']['type_2']['group'] = 2;
  /* Filter criterion: File: Themenfeld(er) (field_kb_kategorie) */
  $handler->display->display_options['filters']['field_kb_kategorie_tid_1']['id'] = 'field_kb_kategorie_tid_1';
  $handler->display->display_options['filters']['field_kb_kategorie_tid_1']['table'] = 'field_data_field_kb_kategorie';
  $handler->display->display_options['filters']['field_kb_kategorie_tid_1']['field'] = 'field_kb_kategorie_tid';
  $handler->display->display_options['filters']['field_kb_kategorie_tid_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_kb_kategorie_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_kb_kategorie_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_kb_kategorie_tid_1']['vocabulary'] = 'lehr_lern_material_kategorien';
  /* Filter criterion: File: Themenfeld(er) (field_kb_kategorie) */
  $handler->display->display_options['filters']['field_kb_kategorie_tid']['id'] = 'field_kb_kategorie_tid';
  $handler->display->display_options['filters']['field_kb_kategorie_tid']['table'] = 'field_data_field_kb_kategorie';
  $handler->display->display_options['filters']['field_kb_kategorie_tid']['field'] = 'field_kb_kategorie_tid';
  $handler->display->display_options['filters']['field_kb_kategorie_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_kb_kategorie_tid']['value'] = '';
  $handler->display->display_options['filters']['field_kb_kategorie_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_kb_kategorie_tid']['vocabulary'] = 'lehr_lern_material_kategorien';
  /* Filter criterion: Vote results: Value */
  $handler->display->display_options['filters']['value']['id'] = 'value';
  $handler->display->display_options['filters']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['filters']['value']['field'] = 'value';
  $handler->display->display_options['filters']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['filters']['value']['group'] = 1;
  $handler->display->display_options['filters']['value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['value']['expose']['operator_id'] = 'value_op';
  $handler->display->display_options['filters']['value']['expose']['label'] = 'Wert';
  $handler->display->display_options['filters']['value']['expose']['operator'] = 'value_op';
  $handler->display->display_options['filters']['value']['expose']['identifier'] = 'value';
  $handler->display->display_options['filters']['value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['value']['group_info']['label'] = 'Bewertung';
  $handler->display->display_options['filters']['value']['group_info']['identifier'] = 'rating';
  $handler->display->display_options['filters']['value']['group_info']['group_items'] = array(
    1 => array(
      'title' => '1 Stern',
      'operator' => '=',
      'value' => array(
        'value' => '20',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => '2 Sterne',
      'operator' => '=',
      'value' => array(
        'value' => '40',
        'min' => '',
        'max' => '',
      ),
    ),
    3 => array(
      'title' => 'Mind. 2 Sterne',
      'operator' => '>=',
      'value' => array(
        'value' => '40',
        'min' => '',
        'max' => '',
      ),
    ),
    4 => array(
      'title' => '3 Sterne',
      'operator' => '=',
      'value' => array(
        'value' => '60',
        'min' => '',
        'max' => '',
      ),
    ),
    5 => array(
      'title' => 'Mind. 3 Sterne',
      'operator' => '>=',
      'value' => array(
        'value' => '60',
        'min' => '',
        'max' => '',
      ),
    ),
    6 => array(
      'title' => '4 Sterne',
      'operator' => '=',
      'value' => array(
        'value' => '80',
        'min' => '',
        'max' => '',
      ),
    ),
    7 => array(
      'title' => 'Mind. 4 Sterne',
      'operator' => '>=',
      'value' => array(
        'value' => '80',
        'min' => '',
        'max' => '',
      ),
    ),
    8 => array(
      'title' => '5 Sterne',
      'operator' => '=',
      'value' => array(
        'value' => '100',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  $handler->display->display_options['pane_category']['name'] = 'Panel-Ansichten';
  $handler->display->display_options['argument_input'] = array(
    'taxonomy_entity_index_tid_depth' => array(
      'type' => 'panel',
      'context' => 'entity:search_api_autocomplete_search.name',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy Entity Index: Has taxonomy term ID on Datei (with depth and indexed in taxonomy_entity_index)',
    ),
  );
  $translatables['kb_files'] = array(
    t('Master'),
    t('Materialien'),
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
    t('Keine Materialien verfügbar.'),
    t('User who uploaded'),
    t('File ID'),
    t(' '),
    t('[filename]'),
    t('Real name'),
    t('Name'),
    t('Schlagworte'),
    t('Typ'),
    t('Eigentümer'),
    t('Files Directory'),
    t('more'),
    t('OG membership from file'),
    t('Vote results'),
    t('%1'),
    t('Wert'),
    t('Bewertung'),
    t('Panel-Ansichten'),
  );
  $export['kb_files'] = $view;

  $view = new view();
  $view->name = 'salto_media_browser';
  $view->description = 'Default view for the media browser library tab.';
  $view->tag = 'media, default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Salto Media browser';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Materialien';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view files';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'media_browser',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'media_browser';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No files available.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: File: Upload date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['sorts']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['timestamp']['expose']['label'] = 'Upload Datum';
  /* Sort criterion: SUM(File Usage: Use count) */
  $handler->display->display_options['sorts']['count']['id'] = 'count';
  $handler->display->display_options['sorts']['count']['table'] = 'file_usage';
  $handler->display->display_options['sorts']['count']['field'] = 'count';
  $handler->display->display_options['sorts']['count']['group_type'] = 'sum';
  $handler->display->display_options['sorts']['count']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['count']['expose']['label'] = 'Anzahl der Verwendung';
  /* Filter criterion: File: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'file_managed';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: File: Name */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'Dateiname';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Typ';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';

  /* Display: Salto Media browser */
  $handler = $view->new_display('media_browser', 'Salto Media browser', 'media_browser_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Materialien und weitere Dateien';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Salto My files */
  $handler = $view->new_display('media_browser', 'Salto My files', 'media_browser_my_files');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Meine Dateien';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own files';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File: User who uploaded */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: File: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'file_managed';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: File: Name */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'Dateiname';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Typ';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  /* Filter criterion: File: Salto Datei Typ (field_salto_file_type) */
  $handler->display->display_options['filters']['field_salto_file_type_value']['id'] = 'field_salto_file_type_value';
  $handler->display->display_options['filters']['field_salto_file_type_value']['table'] = 'field_data_field_salto_file_type';
  $handler->display->display_options['filters']['field_salto_file_type_value']['field'] = 'field_salto_file_type_value';
  $handler->display->display_options['filters']['field_salto_file_type_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_salto_file_type_value']['value'] = array(
    1 => '1',
  );
  $translatables['salto_media_browser'] = array(
    t('Master'),
    t('Materialien'),
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
    t('No files available.'),
    t('Upload Datum'),
    t('Anzahl der Verwendung'),
    t('Dateiname'),
    t('Typ'),
    t('Salto Media browser'),
    t('Materialien und weitere Dateien'),
    t('more'),
    t('Salto My files'),
    t('Meine Dateien'),
    t('User who uploaded'),
  );
  $export['salto_media_browser'] = $view;

  $view = new view();
  $view->name = 'term_files';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'term_files';
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
  $handler->display->display_options['row_plugin'] = 'file';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['row_options']['links'] = 1;
  /* Relationship: Field: Schlagworte (field_post_tags) */
  $handler->display->display_options['relationships']['field_post_tags_tid']['id'] = 'field_post_tags_tid';
  $handler->display->display_options['relationships']['field_post_tags_tid']['table'] = 'field_data_field_post_tags';
  $handler->display->display_options['relationships']['field_post_tags_tid']['field'] = 'field_post_tags_tid';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_post_tags_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['pane_category']['name'] = 'Panel-Ansichten';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'panel',
      'context' => 'entity:clients_connection.configuration',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy term: Term ID',
    ),
  );
  $translatables['term_files'] = array(
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
    t('term from field_post_tags'),
    t('Alle'),
    t('Content pane'),
    t('more'),
    t('Panel-Ansichten'),
  );
  $export['term_files'] = $view;

  $view = new view();
  $view->name = 'tmp_files_by_node';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'tmp_files_by_node';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Anhänge';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ zurück';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weitere ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'filemime' => 'filemime',
    'id' => 'id',
    'fid' => 'fid',
    'field_file_title' => 'field_file_title',
    'field_file_image_title_text' => 'field_file_image_title_text',
  );
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="#attachments">Übersicht Anhänge</a>';
  $handler->display->display_options['footer']['area']['format'] = 'editor';
  /* Relationship: File: Content using Anhang */
  $handler->display->display_options['relationships']['reverse_field_post_attachment_node']['id'] = 'reverse_field_post_attachment_node';
  $handler->display->display_options['relationships']['reverse_field_post_attachment_node']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['reverse_field_post_attachment_node']['field'] = 'reverse_field_post_attachment_node';
  $handler->display->display_options['relationships']['reverse_field_post_attachment_node']['required'] = TRUE;
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['relationship'] = 'reverse_field_post_attachment_node';
  $handler->display->display_options['relationships']['nid']['label'] = 'Den aktuellen Inhalt einer Version laden.';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: File: Mime type */
  $handler->display->display_options['fields']['filemime']['id'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filemime']['field'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['label'] = '';
  $handler->display->display_options['fields']['filemime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['filemime']['filemime_image'] = TRUE;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['max_length'] = '25';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  /* Sort criterion: Global: PHP */
  $handler->display->display_options['sorts']['php']['id'] = 'php';
  $handler->display->display_options['sorts']['php']['table'] = 'views';
  $handler->display->display_options['sorts']['php']['field'] = 'php';
  $handler->display->display_options['sorts']['php']['use_php_setup'] = 0;
  $handler->display->display_options['sorts']['php']['php_sort'] = 'return $row1->php >= $row2->php;';
  /* Contextual filter: File Usage: Entity ID */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'file_usage';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: File Usage: Entity type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_usage';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = 'node';
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = '//only display attachments of current revision vid
$node = node_load($row->id);
$current_vid = $node->vid;
return $current_vid  != $row->vid;';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: File with reference */
  $handler = $view->new_display('panel_pane', 'File with reference', 'panel_file_with_ref');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: File: Mime type */
  $handler->display->display_options['fields']['filemime']['id'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filemime']['field'] = 'filemime';
  $handler->display->display_options['fields']['filemime']['label'] = '';
  $handler->display->display_options['fields']['filemime']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['filemime']['filemime_image'] = TRUE;
  /* Field: File Usage: Entity ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'file_usage';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['label'] = '';
  $handler->display->display_options['fields']['fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fid']['element_label_colon'] = FALSE;
  /* Field: File: Titel */
  $handler->display->display_options['fields']['field_file_title']['id'] = 'field_file_title';
  $handler->display->display_options['fields']['field_file_title']['table'] = 'field_data_field_file_title';
  $handler->display->display_options['fields']['field_file_title']['field'] = 'field_file_title';
  $handler->display->display_options['fields']['field_file_title']['label'] = '';
  $handler->display->display_options['fields']['field_file_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_file_title']['alter']['path'] = 'file/[fid]/[id]';
  $handler->display->display_options['fields']['field_file_title']['element_label_colon'] = FALSE;
  /* Field: File: Bildtitel */
  $handler->display->display_options['fields']['field_file_image_title_text']['id'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['table'] = 'field_data_field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['field'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['label'] = '';
  $handler->display->display_options['fields']['field_file_image_title_text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_file_image_title_text']['alter']['path'] = 'file/[fid]/[id]';
  $handler->display->display_options['fields']['field_file_image_title_text']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Delta';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '//load context filter value => post nid
$arg0 = $view->args[0];
if(!is_numeric($arg0)) {
 return 0;
}

$node = node_load($arg0);
$attachments = $node->field_post_attachment[LANGUAGE_NONE];

foreach($attachments as $key => $attachment) {
   //27.11.2017 - 12:21 - SN
   //key = delta
   if($row->fid == $attachment["fid"]) {
     return $key;
   }
}

return 0;
';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_post_attachment_node';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['relationship'] = 'reverse_field_post_attachment_node';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'Panel-Ansichten';
  $handler->display->display_options['argument_input'] = array(
    'id' => array(
      'type' => 'user',
      'context' => 'entity:clients_connection.configuration',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'File Usage: Entity ID',
    ),
  );
  $translatables['tmp_files_by_node'] = array(
    t('Master'),
    t('Anhänge'),
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
    t('‹ zurück'),
    t('weitere ›'),
    t('letzte Seite »'),
    t('<a href="#attachments">Übersicht Anhänge</a>'),
    t('field_post_attachment'),
    t('Den aktuellen Inhalt einer Version laden.'),
    t('Alle'),
    t('Block'),
    t('more'),
    t('File with reference'),
    t('.'),
    t('Delta'),
    t('Vid'),
    t('Panel-Ansichten'),
  );
  $export['tmp_files_by_node'] = $view;

  return $export;
}
