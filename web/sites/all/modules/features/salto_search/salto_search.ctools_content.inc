<?php
/**
 * @file
 * salto_search.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function salto_search_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'search_pane_authors_and_editors';
  $content->admin_title = 'Authors and Editors';
  $content->admin_description = 'Pane on the righthand side used in combination with search views.';
  $content->category = 'Personen';
  $content->settings = array(
    'admin_title' => 'Authors and Editors',
    'title' => 'Personen',
    'body' => '<?php
return theme(\'salto_search_authors_and_editors_theme\');

?>',
    'format' => 'php_code',
    'substitute' => 0,
  );
  $export['search_pane_authors_and_editors'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'search_pane_organisations';
  $content->admin_title = 'Organisations';
  $content->admin_description = '';
  $content->category = 'Suche';
  $content->settings = array(
    'admin_title' => 'Organisations',
    'title' => 'Organisationen',
    'title_heading' => 'h2',
    'body' => '<?php
return theme(\'salto_search_organisations_theme\');

?>',
    'format' => 'php_code',
    'substitute' => 0,
  );
  $export['search_pane_organisations'] = $content;

  return $export;
}
