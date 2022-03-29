<?php
/**
 * @file
 * salto_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function salto_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'salto_search_comment';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_comments';
  $view->human_name = 'salto_search_comment';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 1;
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
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<strong>Ergebnisse für <span id="saltoSearchName">@name</span> @end von @total</strong>';
  /* Header: Search: Spellcheck */
  $handler->display->display_options['header']['search_api_spellcheck']['id'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['table'] = 'search_api_index_comments';
  $handler->display->display_options['header']['search_api_spellcheck']['field'] = 'search_api_spellcheck';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Leider gibt es auf Ihre Suche keine Ergebnis. Versuchen Sie doch noch einmal einen anderen Suchbegriff oder schauen Sie in einem anderen Bereich. Sicherlich kann Ihnen die Community weiterhelfen: Erstellen Sie doch einfach eine Frage zu Ihrer Suchanfrage.';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Relationship: Indexed Comment: Author */
  $handler->display->display_options['relationships']['author']['id'] = 'author';
  $handler->display->display_options['relationships']['author']['table'] = 'search_api_index_comments';
  $handler->display->display_options['relationships']['author']['field'] = 'author';
  /* Relationship: User: Profile profile */
  $handler->display->display_options['relationships']['profile_main']['id'] = 'profile_main';
  $handler->display->display_options['relationships']['profile_main']['table'] = 'entity_user';
  $handler->display->display_options['relationships']['profile_main']['field'] = 'profile_main';
  $handler->display->display_options['relationships']['profile_main']['relationship'] = 'author';
  /* Field: Global: Card Header */
  $handler->display->display_options['fields']['card_header']['id'] = 'card_header';
  $handler->display->display_options['fields']['card_header']['table'] = 'views';
  $handler->display->display_options['fields']['card_header']['field'] = 'nothing';
  $handler->display->display_options['fields']['card_header']['ui_name'] = 'Global: Card header';
  $handler->display->display_options['fields']['card_header']['label'] = '';
  $handler->display->display_options['fields']['card_header']['alter']['text'] = '<div class="header"></div>';
  $handler->display->display_options['fields']['card_header']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['card_header']['element_wrapper_class'] = 'header';
  /* Field: Profile: Profilbild */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'entity_profile2';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'profile_main';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'user_60x60',
    'image_link' => 'content',
  );
  /* Field: Indexed Comment: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'search_api_index_comments';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = '';
  $handler->display->display_options['fields']['subject']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['subject']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['subject']['link_to_entity'] = 1;
  /* Field: Search: Relevance */
  $handler->display->display_options['fields']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['table'] = 'search_api_index_comments';
  $handler->display->display_options['fields']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['fields']['search_api_relevance']['exclude'] = TRUE;
  $handler->display->display_options['fields']['search_api_relevance']['link_to_entity'] = 0;
  /* Field: Indexed Comment: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_comments';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Indexed Comment: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'search_api_index_comments';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 0;
  /* Field: Indexed Comment: Author */
  $handler->display->display_options['fields']['author']['id'] = 'author';
  $handler->display->display_options['fields']['author']['table'] = 'search_api_index_comments';
  $handler->display->display_options['fields']['author']['field'] = 'author';
  $handler->display->display_options['fields']['author']['exclude'] = TRUE;
  $handler->display->display_options['fields']['author']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['author']['view_mode'] = 'full';
  $handler->display->display_options['fields']['author']['bypass_access'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Gespeichert von [author] am [created] ([search_api_relevance])';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'submitted searchsub';
  /* Field: Indexed Comment: The main body text */
  $handler->display->display_options['fields']['comment_body']['id'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['table'] = 'search_api_index_comments';
  $handler->display->display_options['fields']['comment_body']['field'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['label'] = '';
  $handler->display->display_options['fields']['comment_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_body']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
  //dpm($data);
  //dpm($row);
  //dpm($data->_entity_properties [\'search_api_excerpt\']);
  //dpm(empty($data->_entity_properties [\'search_api_excerpt\']));
  //dpm($data->_entity_properties [\'body:value\']);
  //dpm($data);
  //dpm($data->_entity_properties[\'entity object\']->comment_body[LANGUAGE_NONE][0][\'value\']);
  if(empty($data->_entity_properties [\'search_api_excerpt\'])) {
    $tmp = $data->_entity_properties[\'entity object\']->comment_body[LANGUAGE_NONE][0][\'value\'];
    echo truncate_utf8(strip_tags($tmp), 600, TRUE, TRUE);
  }
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Search: Excerpt */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_comments';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  /* Field: Indexed Comment: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_comments';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = 'Weiterlesen';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['element_wrapper_class'] = 'node-readmore';
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_comments';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_comments';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Suche';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Panel Inhalt */
  $handler = $view->new_display('panel_pane', 'Panel Inhalt', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'Suche';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $translatables['salto_search_comment'] = array(
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
    t('<strong>Ergebnisse für <span id="saltoSearchName">@name</span> @end von @total</strong>'),
    t('Leider gibt es auf Ihre Suche keine Ergebnis. Versuchen Sie doch noch einmal einen anderen Suchbegriff oder schauen Sie in einem anderen Bereich. Sicherlich kann Ihnen die Community weiterhelfen: Erstellen Sie doch einfach eine Frage zu Ihrer Suchanfrage.'),
    t('Author'),
    t('Profile profile'),
    t('Relevance'),
    t('.'),
    t(','),
    t('Date created'),
    t('Gespeichert von [author] am [created] ([search_api_relevance])'),
    t('Weiterlesen'),
    t('Suche'),
    t('Panel Inhalt'),
    t('more'),
  );
  $export['salto_search_comment'] = $view;

  $view = new view();
  $view->name = 'salto_search_file';
  $view->description = '';
  $view->tag = 'salto, file';
  $view->base_table = 'search_api_index_default_file_index';
  $view->human_name = 'Salto Search File';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 1;
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
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<strong>Ergebnisse für <span id="saltoSearchName">@name</span> @end von @total</strong>';
  /* Header: Search: Spellcheck */
  $handler->display->display_options['header']['search_api_spellcheck']['id'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['table'] = 'search_api_index_default_file_index';
  $handler->display->display_options['header']['search_api_spellcheck']['field'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['label'] = 'Spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['empty'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Leider gibt es auf Ihre Suche keine Ergebnis. Versuchen Sie doch noch einmal einen anderen Suchbegriff oder schauen Sie in einem anderen Bereich. Sicherlich kann Ihnen die Community weiterhelfen: Erstellen Sie doch einfach eine Frage zu Ihrer Suchanfrage.';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Relationship: Indexed File: Owner */
  $handler->display->display_options['relationships']['owner']['id'] = 'owner';
  $handler->display->display_options['relationships']['owner']['table'] = 'search_api_index_default_file_index';
  $handler->display->display_options['relationships']['owner']['field'] = 'owner';
  /* Relationship: User: Profile profile */
  $handler->display->display_options['relationships']['profile_main']['id'] = 'profile_main';
  $handler->display->display_options['relationships']['profile_main']['table'] = 'entity_user';
  $handler->display->display_options['relationships']['profile_main']['field'] = 'profile_main';
  $handler->display->display_options['relationships']['profile_main']['relationship'] = 'owner';
  /* Field: Card header */
  $handler->display->display_options['fields']['card_header']['id'] = 'card_header';
  $handler->display->display_options['fields']['card_header']['table'] = 'views';
  $handler->display->display_options['fields']['card_header']['field'] = 'nothing';
  $handler->display->display_options['fields']['card_header']['ui_name'] = 'Card header';
  $handler->display->display_options['fields']['card_header']['label'] = '';
  $handler->display->display_options['fields']['card_header']['alter']['text'] = '<div class="header"></div>';
  $handler->display->display_options['fields']['card_header']['element_label_colon'] = FALSE;
  /* Field: Profile: Profilbild */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'entity_profile2';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'profile_main';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'user_60x60',
    'image_link' => 'content',
  );
  /* Field: Indexed File: File name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'search_api_index_default_file_index';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_type'] = 'h2';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 1;
  /* Field: Indexed File: File type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_default_file_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Indexed File: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'search_api_index_default_file_index';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'medium';
  $handler->display->display_options['fields']['timestamp']['link_to_entity'] = 0;
  /* Field: Indexed File: Owner */
  $handler->display->display_options['fields']['owner']['id'] = 'owner';
  $handler->display->display_options['fields']['owner']['table'] = 'search_api_index_default_file_index';
  $handler->display->display_options['fields']['owner']['field'] = 'owner';
  $handler->display->display_options['fields']['owner']['label'] = '';
  $handler->display->display_options['fields']['owner']['exclude'] = TRUE;
  $handler->display->display_options['fields']['owner']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['owner']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['owner']['view_mode'] = 'full';
  $handler->display->display_options['fields']['owner']['bypass_access'] = 0;
  /* Field: PHP: Feld File Title */
  $handler->display->display_options['fields']['php_title']['id'] = 'php_title';
  $handler->display->display_options['fields']['php_title']['table'] = 'views';
  $handler->display->display_options['fields']['php_title']['field'] = 'php';
  $handler->display->display_options['fields']['php_title']['ui_name'] = 'PHP: Feld File Title';
  $handler->display->display_options['fields']['php_title']['label'] = '';
  $handler->display->display_options['fields']['php_title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['php_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_title']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_title']['php_output'] = '<?php
//dpm($data);
print \'<a href=/file/\' . $data->entity . \'>\';
print $data->_entity_properties[\'entity object\']->field_file_title[LANGUAGE_NONE][0][\'value\'];
print \'</a>\';
?>';
  $handler->display->display_options['fields']['php_title']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_title']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[type] gespeichert von [owner] am [timestamp]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'submitted searchsub';
  /* Field: File: Rendered File */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_file';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'preview';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Search: Excerpt */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_default_file_index';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_file_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Suche';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Suche Files */
  $handler = $view->new_display('panel_pane', 'Suche Files', 'panel_salto_search_file');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'Suche';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $translatables['salto_search_file'] = array(
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
    t('<strong>Ergebnisse für <span id="saltoSearchName">@name</span> @end von @total</strong>'),
    t('Spellcheck'),
    t('Leider gibt es auf Ihre Suche keine Ergebnis. Versuchen Sie doch noch einmal einen anderen Suchbegriff oder schauen Sie in einem anderen Bereich. Sicherlich kann Ihnen die Community weiterhelfen: Erstellen Sie doch einfach eine Frage zu Ihrer Suchanfrage.'),
    t('Owner'),
    t('Profile profile'),
    t('Timestamp'),
    t('[type] gespeichert von [owner] am [timestamp]'),
    t('Suche'),
    t('Suche Files'),
    t('more'),
  );
  $export['salto_search_file'] = $view;

  $view = new view();
  $view->name = 'salto_search_node';
  $view->description = '';
  $view->tag = 'salto, search';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Salto Search Node';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 1;
  $handler->display->display_options['query']['options']['parse_mode'] = 'direct';
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
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<strong>Ergebnisse für <span id="saltoSearchName">@name</span> @end von @total</strong>';
  /* Header: Search: Spellcheck */
  $handler->display->display_options['header']['search_api_spellcheck']['id'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['header']['search_api_spellcheck']['field'] = 'search_api_spellcheck';
  $handler->display->display_options['header']['search_api_spellcheck']['label'] = 'Spellcheck';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Leider gibt es auf Ihre Suche keine Ergebnis. Versuchen Sie doch noch einmal einen anderen Suchbegriff oder schauen Sie in einem anderen Bereich. Sicherlich kann Ihnen die Community weiterhelfen: Erstellen Sie doch einfach eine Frage zu Ihrer Suchanfrage.';
  $handler->display->display_options['empty']['area']['format'] = 'editor';
  /* Relationship: Indexed Node: Author */
  $handler->display->display_options['relationships']['author']['id'] = 'author';
  $handler->display->display_options['relationships']['author']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['relationships']['author']['field'] = 'author';
  /* Relationship: User: Profile profile */
  $handler->display->display_options['relationships']['profile_main']['id'] = 'profile_main';
  $handler->display->display_options['relationships']['profile_main']['table'] = 'entity_user';
  $handler->display->display_options['relationships']['profile_main']['field'] = 'profile_main';
  $handler->display->display_options['relationships']['profile_main']['relationship'] = 'author';
  /* Field: Global: Card header */
  $handler->display->display_options['fields']['card_header']['id'] = 'card_header';
  $handler->display->display_options['fields']['card_header']['table'] = 'views';
  $handler->display->display_options['fields']['card_header']['field'] = 'nothing';
  $handler->display->display_options['fields']['card_header']['ui_name'] = 'Global: Card header';
  $handler->display->display_options['fields']['card_header']['label'] = '';
  $handler->display->display_options['fields']['card_header']['alter']['text'] = '<div class="header"></div>';
  $handler->display->display_options['fields']['card_header']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['card_header']['element_wrapper_class'] = 'header';
  /* Field: Profile: Profilbild */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'entity_profile2';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'profile_main';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'user_60x60',
    'image_link' => 'content',
  );
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Autoren */
  $handler->display->display_options['fields']['field_post_authors']['id'] = 'field_post_authors';
  $handler->display->display_options['fields']['field_post_authors']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_post_authors']['field'] = 'field_post_authors';
  $handler->display->display_options['fields']['field_post_authors']['label'] = '';
  $handler->display->display_options['fields']['field_post_authors']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_post_authors']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_post_authors']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_post_authors']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_post_authors']['bypass_access'] = 0;
  /* Field: Indexed Node: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Indexed Node: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 0;
  /* Field: Indexed Node: Author */
  $handler->display->display_options['fields']['author']['id'] = 'author';
  $handler->display->display_options['fields']['author']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['author']['field'] = 'author';
  $handler->display->display_options['fields']['author']['exclude'] = TRUE;
  $handler->display->display_options['fields']['author']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['author']['view_mode'] = 'full';
  $handler->display->display_options['fields']['author']['bypass_access'] = 0;
  /* Field: PHP: Original Title */
  $handler->display->display_options['fields']['php_title']['id'] = 'php_title';
  $handler->display->display_options['fields']['php_title']['table'] = 'views';
  $handler->display->display_options['fields']['php_title']['field'] = 'php';
  $handler->display->display_options['fields']['php_title']['ui_name'] = 'PHP: Original Title';
  $handler->display->display_options['fields']['php_title']['label'] = '';
  $handler->display->display_options['fields']['php_title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['php_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_title']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_title']['php_output'] = '<?php
//dpm($data);
print \'<a href=/node/\' . $data->entity . \'>\';
print $data->_entity_properties[\'entity object\']->title;
print \'</a>\';
?>';
  $handler->display->display_options['fields']['php_title']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_title']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<span class="[type]"/>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'kb-type';
  /* Field: The main body text: Text (indexed) */
  $handler->display->display_options['fields']['body_value']['id'] = 'body_value';
  $handler->display->display_options['fields']['body_value']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['body_value']['field'] = 'body_value';
  $handler->display->display_options['fields']['body_value']['label'] = '';
  $handler->display->display_options['fields']['body_value']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body_value']['alter']['max_length'] = '600';
  $handler->display->display_options['fields']['body_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body_value']['link_to_entity'] = 0;
  /* Field: Search: Excerpt */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
  //dpm($data);
  //dpm($row);
  //dpm($row->search_api_excerpt);
  //dpm(empty($data->_entity_properties [\'search_api_excerpt\']));
  //dpm($data->_entity_properties [\'body:value\']);
  if(empty($data->_entity_properties [\'search_api_excerpt\'])) {
    echo truncate_utf8(strip_tags($data->_entity_properties[\'body:value\']), 600, TRUE, TRUE);
  }
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'node-readmore';
  $handler->display->display_options['fields']['view_node']['text'] = 'Weiterlesen';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Beitrags-ID';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Suche';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'post' => 'post',
  );
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';

  /* Display: Suche */
  $handler = $view->new_display('panel_pane', 'Suche', 'panel_salto_search_node');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'Suche';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $translatables['salto_search_node'] = array(
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
    t('<strong>Ergebnisse für <span id="saltoSearchName">@name</span> @end von @total</strong>'),
    t('Spellcheck'),
    t('Leider gibt es auf Ihre Suche keine Ergebnis. Versuchen Sie doch noch einmal einen anderen Suchbegriff oder schauen Sie in einem anderen Bereich. Sicherlich kann Ihnen die Community weiterhelfen: Erstellen Sie doch einfach eine Frage zu Ihrer Suchanfrage.'),
    t('Author'),
    t('Profile profile'),
    t('Date created'),
    t('Content type'),
    t('<span class="[type]"/>'),
    t('Weiterlesen'),
    t('Beitrags-ID'),
    t('.'),
    t(','),
    t('Suche'),
    t('more'),
  );
  $export['salto_search_node'] = $view;

  return $export;
}
