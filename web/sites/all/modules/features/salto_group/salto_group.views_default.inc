<?php

/**
 * @file
 * salto_group.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function salto_group_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'group_content';
  $view->description = 'Base view to filter and show articles, questions and reports';
  $view->tag = 'groups';
  $view->base_table = 'node';
  $view->human_name = 'Group: content';
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
  $handler->display->display_options['empty']['area']['content'] = 'Im Moment gibt es hier noch keine Inhalte, aber das wird sich sicherlich bald ändern.';
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
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
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
  /* Contextual filter: Field: OG vocabulary (og_vocabulary) */
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['id'] = 'og_vocabulary_target_id';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['table'] = 'field_data_og_vocabulary';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['field'] = 'og_vocabulary_target_id';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['exception']['title'] = 'Aktuellste Beiträge';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['title'] = '%2';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['breadcrumb'] = '%2';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['validate_options']['transform'] = TRUE;
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

  /* Display: Content: Base */
  $handler = $view->new_display('panel_pane', 'Content: Base', 'base');
  $handler->display->display_options['display_description'] = 'Default view on knowledgebase';
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
    'post' => 'post',
    'shared_post' => 'shared_post',
  );
  $handler->display->display_options['pane_title'] = 'Group Content: base';
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

  /* Display: Public posts */
  $handler = $view->new_display('panel_pane', 'Public posts', 'articles');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Beiträge';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['pane_title'] = 'Group: Public Articles';
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
  );
  $translatables['group_content'] = array(
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
    t('Im Moment gibt es hier noch keine Inhalte, aber das wird sich sicherlich bald ändern.'),
    t('OG membership from node'),
    t('Alle'),
    t('%2'),
    t('Content: Base'),
    t('Default view on knowledgebase'),
    t('more'),
    t('Titel'),
    t('Group Content: base'),
    t('Gruppen'),
    t('Public posts'),
    t('Beiträge'),
    t('Group: Public Articles'),
  );
  $export['group_content'] = $view;

  $view = new view();
  $view->name = 'groups';
  $view->description = 'used in groups overview, siehe salto_group_views_query_alter';
  $view->tag = 'groups, query override';
  $view->base_table = 'node';
  $view->human_name = 'Groups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Gruppen';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
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
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: OG membership: OG membership from Node group */
  $handler->display->display_options['relationships']['og_membership_rel_group']['id'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel_group']['field'] = 'og_membership_rel_group';
  /* Field: Content: Beitrittsmodus */
  $handler->display->display_options['fields']['field_group_join_mode']['id'] = 'field_group_join_mode';
  $handler->display->display_options['fields']['field_group_join_mode']['table'] = 'field_data_field_group_join_mode';
  $handler->display->display_options['fields']['field_group_join_mode']['field'] = 'field_group_join_mode';
  $handler->display->display_options['fields']['field_group_join_mode']['label'] = '';
  $handler->display->display_options['fields']['field_group_join_mode']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_group_join_mode']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'smart_trim_format';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_link' => '0',
    'trim_length' => '270',
    'trim_type' => 'chars',
    'trim_suffix' => '...',
    'more_link' => '0',
    'more_text' => 'Read more',
    'summary_handler' => 'full',
    'trim_options' => array(
      'text' => 'text',
    ),
    'trim_preserve_tags' => '',
  );
  $handler->display->display_options['fields']['body']['group_column'] = 'entity_id';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['exclude'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Gruppen-Manager';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Mitglieder';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
 $members = og_membership_load_multiple(FALSE, array(\'gid\' => $row->nid, \'entity_type\' => \'user\', \'state\' => OG_STATE_ACTIVE));
 if(count($members )> SALTO_GROUP_MAX_USER_PICS){
    $diff = count($members)-SALTO_GROUP_MAX_USER_PICS;
    if(!empty($diff)){
     print \'<div class="members more"> + \' .  $diff . \'</div>\';
  }
 }

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Beiträge';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
  $posts = og_membership_load_multiple(FALSE, array(\'gid\' => $row->nid, \'entity_type\' => \'node\', \'state\' => OG_STATE_ACTIVE)); 
if(!empty($posts)){
 print \'<div class="icon-article col-md-12 group-num-nodes">\' . count($posts) . \' \' . format_plural(count($posts),\'Beitrag\', \'Beiträge\') . \'</div>\';
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'Dateien';
  $handler->display->display_options['fields']['php_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_4']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
  $files = og_membership_load_multiple(FALSE, array(\'gid\' => $row->nid, \'entity_type\' => \'file\', \'state\' => OG_STATE_ACTIVE)); 
if(!empty($files)){
  print \'<div class="icon-attach col-md-12 group-num-files">\' . count($files) . \' \' . format_plural(count($files),\'Datei\', \'Dateien\') . \'</div>\';
}

?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_5']['id'] = 'php_5';
  $handler->display->display_options['fields']['php_5']['table'] = 'views';
  $handler->display->display_options['fields']['php_5']['field'] = 'php';
  $handler->display->display_options['fields']['php_5']['label'] = 'Mitglieder';
  $handler->display->display_options['fields']['php_5']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_5']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_5']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_5']['php_output'] = '<?php
  $members = og_membership_load_multiple(FALSE, array(\'gid\' => $row->nid, \'entity_type\' => \'user\', \'state\' => OG_STATE_ACTIVE)); 
if(!empty($members)){
   print \'<div class="icon-user col-md-12 group-num-members">\' . count($members) . \' \' . format_plural(count($members),\'Mitglied\', \'Mitglieder\') . \'</div>\';
}
?>';
  $handler->display->display_options['fields']['php_5']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_5']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'Mitglieder Bilder';
  $handler->display->display_options['fields']['php_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
  print salto_group_render_group_members_user_pictures($row->nid)
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Beitreten';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
 print salto_group_render_join_action($row->nid);
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Content: Beitrittsmodus */
  $handler->display->display_options['fields']['field_group_join_mode_1']['id'] = 'field_group_join_mode_1';
  $handler->display->display_options['fields']['field_group_join_mode_1']['table'] = 'field_data_field_group_join_mode';
  $handler->display->display_options['fields']['field_group_join_mode_1']['field'] = 'field_group_join_mode';
  $handler->display->display_options['fields']['field_group_join_mode_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_group_join_mode_1']['type'] = 'list_key';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="group-view-row row card">
<div class="col-md-12">
  <div class="row">
    <div class="col-md-12">
      <div class="group-title join_mode-[field_group_join_mode_1]">[title]</div>
      <div class="group-body">[body] </div>
    </div>
  </div>
  <div class="row group-view-item-footer">
   [php_1]
   [php_4]
   [php_5]
  </div>
</div>
<div class="col-md-12 group-footer">
   <div class="flex">
     <div class="members">[php_3]</div>
     [php]
   </div>
   <div class="group-actions action-links left">[php_2]</div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
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
    6 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Realname: Name */
  $handler->display->display_options['filters']['realname']['id'] = 'realname';
  $handler->display->display_options['filters']['realname']['table'] = 'realname';
  $handler->display->display_options['filters']['realname']['field'] = 'realname';
  $handler->display->display_options['filters']['realname']['relationship'] = 'uid';
  $handler->display->display_options['filters']['realname']['operator'] = 'contains';
  $handler->display->display_options['filters']['realname']['group'] = 1;
  $handler->display->display_options['filters']['realname']['exposed'] = TRUE;
  $handler->display->display_options['filters']['realname']['expose']['operator_id'] = 'realname_op';
  $handler->display->display_options['filters']['realname']['expose']['label'] = 'Gründer/Manager';
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
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: Content: Beitrittsmodus (field_group_join_mode) */
  $handler->display->display_options['filters']['field_group_join_mode_value']['id'] = 'field_group_join_mode_value';
  $handler->display->display_options['filters']['field_group_join_mode_value']['table'] = 'field_data_field_group_join_mode';
  $handler->display->display_options['filters']['field_group_join_mode_value']['field'] = 'field_group_join_mode_value';
  $handler->display->display_options['filters']['field_group_join_mode_value']['group'] = 1;
  $handler->display->display_options['filters']['field_group_join_mode_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_group_join_mode_value']['expose']['operator_id'] = 'field_group_join_mode_value_op';
  $handler->display->display_options['filters']['field_group_join_mode_value']['expose']['label'] = 'Beitrittsmodus';
  $handler->display->display_options['filters']['field_group_join_mode_value']['expose']['operator'] = 'field_group_join_mode_value_op';
  $handler->display->display_options['filters']['field_group_join_mode_value']['expose']['identifier'] = 'field_group_join_mode_value';
  $handler->display->display_options['filters']['field_group_join_mode_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Salto - Dynamischer Themenfeld(er) Filter */
  $handler->display->display_options['filters']['field_group_themenfelder_tid']['id'] = 'field_group_themenfelder_tid';
  $handler->display->display_options['filters']['field_group_themenfelder_tid']['table'] = 'field_data_field_group_categories';
  $handler->display->display_options['filters']['field_group_themenfelder_tid']['field'] = 'field_group_themenfelder_tid';
  $handler->display->display_options['filters']['field_group_themenfelder_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_group_themenfelder_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_group_themenfelder_tid']['expose']['operator_id'] = 'field_group_themenfelder_tid_op';
  $handler->display->display_options['filters']['field_group_themenfelder_tid']['expose']['label'] = 'Themenfelder';
  $handler->display->display_options['filters']['field_group_themenfelder_tid']['expose']['operator'] = 'field_group_themenfelder_tid_op';
  $handler->display->display_options['filters']['field_group_themenfelder_tid']['expose']['identifier'] = 'field_group_themenfelder_tid';
  $handler->display->display_options['filters']['field_group_themenfelder_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_post_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_post_tags_tid']['vocabulary'] = 'tags';
  /* Filter criterion: User: Group size */
  $handler->display->display_options['filters']['group_member_count']['id'] = 'group_member_count';
  $handler->display->display_options['filters']['group_member_count']['table'] = 'users';
  $handler->display->display_options['filters']['group_member_count']['field'] = 'group_member_count';
  $handler->display->display_options['filters']['group_member_count']['relationship'] = 'uid';
  $handler->display->display_options['filters']['group_member_count']['group'] = 1;
  $handler->display->display_options['filters']['group_member_count']['exposed'] = TRUE;
  $handler->display->display_options['filters']['group_member_count']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['group_member_count']['expose']['label'] = 'Group size';
  $handler->display->display_options['filters']['group_member_count']['expose']['operator'] = 'group_member_count_op';
  $handler->display->display_options['filters']['group_member_count']['expose']['identifier'] = 'group_member_count';
  $handler->display->display_options['filters']['group_member_count']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['group_member_count']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['group_member_count']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['group_member_count']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['group_member_count']['group_info']['label'] = 'Group size';
  $handler->display->display_options['filters']['group_member_count']['group_info']['identifier'] = 'group_member_count';
  $handler->display->display_options['filters']['group_member_count']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['group_member_count']['group_info']['group_items'] = array(
    1 => array(
      'title' => '-Alle-',
      'operator' => '=',
      'value' => array(
        'value' => '1',
        'min' => '3',
        'max' => '3',
      ),
    ),
    2 => array(
      'title' => '< 5',
      'operator' => '<',
      'value' => array(
        'value' => '5',
        'min' => '3',
        'max' => '3',
      ),
    ),
    3 => array(
      'title' => '5 - 25',
      'operator' => 'between',
      'value' => array(
        'value' => '3',
        'min' => '5',
        'max' => '25',
      ),
    ),
    4 => array(
      'title' => '25 - 50',
      'operator' => 'between',
      'value' => array(
        'value' => '3',
        'min' => '25',
        'max' => '50',
      ),
    ),
    5 => array(
      'title' => '> 50',
      'operator' => '>',
      'value' => array(
        'value' => '50',
        'min' => '3',
        'max' => '3',
      ),
    ),
  );
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel_group';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Mein Mitgliedsstatus';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'return salto_group_filter_relevant_group($data->nid);';

  /* Display: Groups Directory (!) */
  $handler = $view->new_display('panel_pane', 'Groups Directory (!)', 'panel_groups_directory');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'List of groups';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'Gruppen';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: My Groups */
  $handler = $view->new_display('panel_pane', 'My Groups', 'panel_groups_my_groups');
  $handler->display->display_options['display_description'] = 'List of my groups';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: OG membership: OG membership from Node group */
  $handler->display->display_options['relationships']['og_membership_rel_group']['id'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel_group']['field'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: OG membership: Entity id */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['relationship'] = 'og_membership_rel_group';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['etid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'my groups with action links';
  $handler->display->display_options['pane_category']['name'] = 'Groups. People';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $translatables['groups'] = array(
    t('Master'),
    t('Gruppen'),
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
    t('author'),
    t('OG membership from node group'),
    t('Real name'),
    t('Gruppen-Manager'),
    t('Mitglieder'),
    t('Beiträge'),
    t('Dateien'),
    t('Mitglieder Bilder'),
    t('Beitreten'),
    t('Beitrittsmodus'),
    t('<div class="group-view-row row card">
<div class="col-md-12">
  <div class="row">
    <div class="col-md-12">
      <div class="group-title join_mode-[field_group_join_mode_1]">[title]</div>
      <div class="group-body">[body] </div>
    </div>
  </div>
  <div class="row group-view-item-footer">
   [php_1]
   [php_4]
   [php_5]
  </div>
</div>
<div class="col-md-12 group-footer">
   <div class="flex">
     <div class="members">[php_3]</div>
     [php]
   </div>
   <div class="group-actions action-links left">[php_2]</div>
</div>
</div>'),
    t('Titel'),
    t('Gründer/Manager'),
    t('Themenfelder'),
    t('Schlagworte'),
    t('Group size'),
    t('Mein Mitgliedsstatus'),
    t('Groups Directory (!)'),
    t('List of groups'),
    t('more'),
    t('My Groups'),
    t('List of my groups'),
    t('Alle'),
    t('my groups with action links'),
    t('Groups. People'),
  );
  $export['groups'] = $view;

  $view = new view();
  $view->name = 'groups_files';
  $view->description = 'File view used in groups';
  $view->tag = 'media, default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Groups: files';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Dateien';
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
  $handler->display->display_options['pager']['options']['quantity'] = '4';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Keine Dateien verfügbar.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: File: User who uploaded */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: OG membership: OG membership from File */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['required'] = TRUE;
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
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['filename']['alter']['path'] = 'file/[fid]';
  $handler->display->display_options['fields']['filename']['alter']['max_length'] = '16';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['filename']['link_to_file'] = FALSE;
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
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['exclude'] = TRUE;
  /* Field: Bulk operations: File */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_file';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  /* Sort criterion: File: Upload date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Sort criterion: File: Name */
  $handler->display->display_options['sorts']['filename']['id'] = 'filename';
  $handler->display->display_options['sorts']['filename']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['filename']['field'] = 'filename';
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
  /* Contextual filter: Field: OG vocabulary (og_vocabulary) */
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['id'] = 'og_vocabulary_target_id';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['table'] = 'field_data_og_vocabulary';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['field'] = 'og_vocabulary_target_id';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['title'] = '%2';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['breadcrumb'] = '%2';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['og_vocabulary_target_id']['validate']['type'] = 'taxonomy_term';
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

  /* Display: Media browser */
  $handler = $view->new_display('media_browser', 'Media browser', 'media_browser_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Bibliothek';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['rendered']['file_view_mode'] = 'preview';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['max_length'] = '18';
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

  /* Display: Files Directory */
  $handler = $view->new_display('panel_pane', 'Files Directory', 'files_directory');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'listing';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
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
  $handler->display->display_options['pane_category']['name'] = 'Gruppen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'panel',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG Mitgliedschaft: Gruppen-ID',
    ),
    'og_vocabulary_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:search_api_autocomplete_search.name',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Feld: OG vocabulary (og_vocabulary)',
    ),
  );

  /* Display: Files Directory Download */
  $handler = $view->new_display('panel_pane', 'Files Directory Download', 'panel_pane_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'fid' => 'fid',
    'rendered' => 'rendered',
    'filename' => 'filename',
    'download' => 'download',
    'realname' => 'realname',
    'timestamp' => 'timestamp',
    'field_post_tags' => 'field_post_tags',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rendered' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'filename' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'download' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'realname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_post_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: File */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_file';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_archive_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'skip_permission_check' => 0,
      'override_label' => 1,
      'label' => 'Download selected files',
      'settings' => array(
        'scheme' => 'private',
        'temporary' => 1,
      ),
    ),
  );
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
  $handler->display->display_options['fields']['rendered']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rendered']['alter']['path'] = 'file/[fid]';
  $handler->display->display_options['fields']['rendered']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['rendered']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered']['file_view_mode'] = 'colorbox';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['exclude'] = TRUE;
  $handler->display->display_options['fields']['filename']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['filename']['alter']['path'] = 'file/[fid]';
  $handler->display->display_options['fields']['filename']['alter']['max_length'] = '16';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['filename']['link_to_file'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Dateititel';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php

echo salto_files_view_multiple_files_set_titel($row->fid);

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'Autor:in';
  /* Field: File: Upload date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Uploaddate';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'd.m.Y';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Field: Schlagworte */
  $handler->display->display_options['fields']['field_post_tags']['id'] = 'field_post_tags';
  $handler->display->display_options['fields']['field_post_tags']['table'] = 'field_data_field_post_tags';
  $handler->display->display_options['fields']['field_post_tags']['field'] = 'field_post_tags';
  $handler->display->display_options['fields']['field_post_tags']['empty'] = '-';
  $handler->display->display_options['fields']['field_post_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_post_tags']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_post_tags']['delta_offset'] = '0';
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
  $handler->display->display_options['pane_category']['name'] = 'Gruppen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'panel',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG Mitgliedschaft: Gruppen-ID',
    ),
    'og_vocabulary_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:search_api_autocomplete_search.name',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Feld: OG vocabulary (og_vocabulary)',
    ),
  );

  /* Display: Files Directory Edit */
  $handler = $view->new_display('panel_pane', 'Files Directory Edit', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'fid' => 'fid',
    'rendered' => 'rendered',
    'filename' => 'filename',
    'download' => 'download',
    'realname' => 'realname',
    'timestamp' => 'timestamp',
    'field_post_tags' => 'field_post_tags',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rendered' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'filename' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'download' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'realname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_post_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: File */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_file';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::salto_files_edit_multiple_files' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'skip_permission_check' => 1,
      'override_label' => 1,
      'label' => 'Edit selected files',
    ),
  );
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
  $handler->display->display_options['fields']['rendered']['exclude'] = TRUE;
  $handler->display->display_options['fields']['rendered']['alter']['path'] = 'file/[fid]';
  $handler->display->display_options['fields']['rendered']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['rendered']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered']['file_view_mode'] = 'colorbox';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['exclude'] = TRUE;
  $handler->display->display_options['fields']['filename']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['filename']['alter']['path'] = 'file/[fid]';
  $handler->display->display_options['fields']['filename']['alter']['max_length'] = '16';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['filename']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['filename']['link_to_file'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Dateititel';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php

echo salto_files_view_multiple_files_set_titel($row->fid);

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'Autor:in';
  /* Field: File: Upload date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Uploaddate';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'd.m.Y';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Field: Schlagworte */
  $handler->display->display_options['fields']['field_post_tags']['id'] = 'field_post_tags';
  $handler->display->display_options['fields']['field_post_tags']['table'] = 'field_data_field_post_tags';
  $handler->display->display_options['fields']['field_post_tags']['field'] = 'field_post_tags';
  $handler->display->display_options['fields']['field_post_tags']['empty'] = '-';
  $handler->display->display_options['fields']['field_post_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_post_tags']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_post_tags']['delta_offset'] = '0';
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
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'return !salto_files_view_user_has_file_edit_access($row->fid);';
  $handler->display->display_options['pane_category']['name'] = 'Gruppen';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'gid' => array(
      'type' => 'panel',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'OG Mitgliedschaft: Gruppen-ID',
    ),
    'og_vocabulary_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:search_api_autocomplete_search.name',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Feld: OG vocabulary (og_vocabulary)',
    ),
  );
  $translatables['groups_files'] = array(
    t('Master'),
    t('Dateien'),
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
    t('Keine Dateien verfügbar.'),
    t('User who uploaded'),
    t('OG membership from file'),
    t('File ID'),
    t(' '),
    t('Real name'),
    t('File'),
    t('- Choose an operation -'),
    t('Alle'),
    t('%2'),
    t('Name'),
    t('Schlagworte'),
    t('Typ'),
    t('Eigentümer'),
    t('Media browser'),
    t('Bibliothek'),
    t('more'),
    t('Files Directory'),
    t('Gruppen'),
    t('Files Directory Download'),
    t('Download selected files'),
    t('Dateititel'),
    t('Autor:in'),
    t('Uploaddate'),
    t('-'),
    t('Files Directory Edit'),
    t('Edit selected files'),
  );
  $export['groups_files'] = $view;

  $view = new view();
  $view->name = 'groups_members';
  $view->description = 'Newest group members.';
  $view->tag = 'groups';
  $view->base_table = 'users';
  $view->human_name = 'Groups: members';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Group Members';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'group_members',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'state',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Es wurden keine Mitglieder gefunden.


';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  /* Sort criterion: Field: Vorname (field_profile_name_first) */
  $handler->display->display_options['sorts']['field_profile_name_first_value']['id'] = 'field_profile_name_first_value';
  $handler->display->display_options['sorts']['field_profile_name_first_value']['table'] = 'field_data_field_profile_name_first';
  $handler->display->display_options['sorts']['field_profile_name_first_value']['field'] = 'field_profile_name_first_value';
  $handler->display->display_options['sorts']['field_profile_name_first_value']['relationship'] = 'profile';
  $handler->display->display_options['sorts']['field_profile_name_first_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_profile_name_first_value']['expose']['label'] = 'Vorname';
  /* Sort criterion: Field: Nachname (field_profile_name_last) */
  $handler->display->display_options['sorts']['field_profile_name_last_value']['id'] = 'field_profile_name_last_value';
  $handler->display->display_options['sorts']['field_profile_name_last_value']['table'] = 'field_data_field_profile_name_last';
  $handler->display->display_options['sorts']['field_profile_name_last_value']['field'] = 'field_profile_name_last_value';
  $handler->display->display_options['sorts']['field_profile_name_last_value']['relationship'] = 'profile';
  $handler->display->display_options['sorts']['field_profile_name_last_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_profile_name_last_value']['expose']['label'] = 'Nachname';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Mitgliedsorganisation';
  /* Sort criterion: OG membership: State */
  $handler->display->display_options['sorts']['state']['id'] = 'state';
  $handler->display->display_options['sorts']['state']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['state']['field'] = 'state';
  /* Sort criterion: Realname: Real name */
  $handler->display->display_options['sorts']['realname']['id'] = 'realname';
  $handler->display->display_options['sorts']['realname']['table'] = 'realname';
  $handler->display->display_options['sorts']['realname']['field'] = 'realname';
  /* Sort criterion: OG membership: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['gid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['gid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['gid']['title'] = '%1 members';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['state']['value'] = array(
    1 => '1',
  );

  /* Display: Pending Members */
  $handler = $view->new_display('panel_pane', 'Pending Members', 'panel_og_pending_memberships');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Beitrittsanfragen';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: OG membership: Group ID */
  $handler->display->display_options['fields']['gid']['id'] = 'gid';
  $handler->display->display_options['fields']['gid']['table'] = 'og_membership';
  $handler->display->display_options['fields']['gid']['field'] = 'gid';
  $handler->display->display_options['fields']['gid']['label'] = '';
  $handler->display->display_options['fields']['gid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['gid']['element_label_colon'] = FALSE;
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
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_user_picture']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_user_picture']['field_api_classes'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo salto_group_render_og_manager_member_action($row->gid, $row->uid);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="row">
<div class="col-md-2">[field_user_picture]</div>
<div class="col-md-7">
  <div class="groups-members-name">[name]</div>
  <div class="groups-members-state"></div>
</div>
<div class="col-md-3">[php] </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['filters']['state']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['pane_category']['name'] = 'Groups, People';
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

  /* Display: Group Members */
  $handler = $view->new_display('panel_pane', 'Group Members', 'panel_og_members');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mitglieder';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  /* Relationship: OG membership: OG membership from User */
  $handler->display->display_options['relationships']['og_membership_rel']['id'] = 'og_membership_rel';
  $handler->display->display_options['relationships']['og_membership_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['og_membership_rel']['field'] = 'og_membership_rel';
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['relationship'] = 'og_membership_rel';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: OG membership: Group ID */
  $handler->display->display_options['fields']['gid']['id'] = 'gid';
  $handler->display->display_options['fields']['gid']['table'] = 'og_membership';
  $handler->display->display_options['fields']['gid']['field'] = 'gid';
  $handler->display->display_options['fields']['gid']['label'] = '';
  $handler->display->display_options['fields']['gid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['gid']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['field_user_picture']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_user_picture']['field_api_classes'] = TRUE;
  /* Field: OG membership: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'og_membership';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = '';
  $handler->display->display_options['fields']['state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo salto_group_render_og_manager_member_action($row->gid, $row->uid);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'OG Roles';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
  echo salto_user_get_organisations_by_user($row->uid);
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Manager Star';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
  echo salto_group_user_manager_render($row->uid, $row->gid);
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="row member-item">
<div class="col-md-2">[field_user_picture]</div>
<div class="col-md-6">
  <div class="groups-members-name">[name][php_2]</div>
  <div class="groups-members-state">[php_1]</div>
</div>
<div class="col-md-4 member-actions">[php]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: COUNT(Content: Title) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['group_type'] = 'count';
  $handler->display->display_options['fields']['title']['label'] = 'Titel';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  /* Field: User: Organisations */
  $handler->display->display_options['fields']['field_user_organisations']['id'] = 'field_user_organisations';
  $handler->display->display_options['fields']['field_user_organisations']['table'] = 'og_membership';
  $handler->display->display_options['fields']['field_user_organisations']['field'] = 'field_user_organisations';
  $handler->display->display_options['fields']['field_user_organisations']['label'] = 'Organisationen';
  $handler->display->display_options['fields']['field_user_organisations']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_organisations']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_user_organisations']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_user_organisations']['delta_offset'] = '0';
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
  $handler->display->display_options['arguments']['gid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['gid']['validate']['type'] = 'og';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
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
  );
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['realname']['expose']['autocomplete_dependent'] = 0;
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = 'global $group_members_uids;

if (empty($group_members_uids[$row->uid])) {
  $group_members_uids[$row->uid] = $row->uid;
  return FALSE;
}


return TRUE;
';
  $handler->display->display_options['pane_category']['name'] = 'Groups, People';
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
  $translatables['groups_members'] = array(
    t('Defaults'),
    t('Group Members'),
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
    t('Es wurden keine Mitglieder gefunden.


'),
    t('OG membership from user'),
    t('Vorname'),
    t('Nachname'),
    t('Mitgliedsorganisation'),
    t('Alle'),
    t('%1 members'),
    t('Pending Members'),
    t('Beitrittsanfragen'),
    t('more'),
    t('Profile'),
    t('.'),
    t(','),
    t('PHP'),
    t('<div class="row">
<div class="col-md-2">[field_user_picture]</div>
<div class="col-md-7">
  <div class="groups-members-name">[name]</div>
  <div class="groups-members-state"></div>
</div>
<div class="col-md-3">[php] </div>
</div>'),
    t('Groups, People'),
    t('Mitglieder'),
    t('Group node from OG membership'),
    t('Name'),
    t('OG Roles'),
    t('Manager Star'),
    t('<div class="row member-item">
<div class="col-md-2">[field_user_picture]</div>
<div class="col-md-6">
  <div class="groups-members-name">[name][php_2]</div>
  <div class="groups-members-state">[php_1]</div>
</div>
<div class="col-md-4 member-actions">[php]</div>
</div>'),
    t('Titel'),
    t('Organisationen'),
    t('Status'),
  );
  $export['groups_members'] = $view;

  $view = new view();
  $view->name = 'groups_user_groups';
  $view->description = 'Show groups of a user.';
  $view->tag = 'og';
  $view->base_table = 'og_membership';
  $view->human_name = 'Groups: User groups';
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
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
  $handler->display->display_options['empty']['area']['content'] = 'Der Benutzer gehört keiner Gruppe an.';
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = 'Gruppe';
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: OG membership: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'og_membership';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Member since';
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
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
  $handler->display->display_options['arguments']['etid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['etid']['title'] = '%1\'s groups';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['etid']['validate']['type'] = 'user';
  /* Filter criterion: OG membership: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'og_membership';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'og_membership';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['filters']['type']['value'] = array(
    'group' => 'group',
  );

  /* Display: My Groups */
  $handler = $view->new_display('panel_pane', 'My Groups', 'panel_my_og_groups_by_type');
  $handler->display->display_options['display_description'] = 'used on group overview';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: We pass the user ID as the Entity ID. */
  $handler->display->display_options['arguments']['etid']['id'] = 'etid';
  $handler->display->display_options['arguments']['etid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['etid']['field'] = 'etid';
  $handler->display->display_options['arguments']['etid']['ui_name'] = 'We pass the user ID as the Entity ID.';
  $handler->display->display_options['arguments']['etid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['etid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['etid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['etid']['title'] = 'Meine Gruppen';
  $handler->display->display_options['arguments']['etid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['etid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['etid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['etid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['etid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['etid']['validate']['type'] = 'user';
  $handler->display->display_options['pane_category']['name'] = 'Groups, People';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'etid' => array(
      'type' => 'none',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'We pass the user ID as the Entity ID.',
    ),
  );
  $translatables['groups_user_groups'] = array(
    t('Master'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Der Benutzer gehört keiner Gruppe an.'),
    t('Group node from OG membership'),
    t('Gruppe'),
    t('Member since'),
    t('Alle'),
    t('%1\'s groups'),
    t('My Groups'),
    t('used on group overview'),
    t('more'),
    t('Meine Gruppen'),
    t('Groups, People'),
  );
  $export['groups_user_groups'] = $view;

  return $export;
}
