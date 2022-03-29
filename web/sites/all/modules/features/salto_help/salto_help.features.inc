<?php
/**
 * @file
 * salto_help.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function salto_help_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ctools_custom_content" && $api == "ctools_content") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function salto_help_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function salto_help_flag_default_flags() {
  $flags = array();
  // Exported flag: "Help - Eintrag - hilfreich - Nein".
  $flags['help_entry_useful_no'] = array(
    'entity_type' => 'node',
    'title' => 'Help - Eintrag - hilfreich - Nein',
    'global' => 0,
    'types' => array(
      0 => 'help',
    ),
    'flag_short' => 'Nein',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => '"Nein" zurücksetzen',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'flagged',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'print' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'membership_compact' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'salto_help',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Help - Eintrag - hilfreich - Ja".
  $flags['help_entry_useful_yes'] = array(
    'entity_type' => 'node',
    'title' => 'Help - Eintrag - hilfreich - Ja',
    'global' => 0,
    'types' => array(
      0 => 'help',
    ),
    'flag_short' => 'Ja',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => '"Ja" zurücksetzen',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'flagged',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'print' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'membership_compact' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'salto_help',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function salto_help_node_info() {
  $items = array(
    'help' => array(
      'name' => t('Hilfeeintrag'),
      'base' => 'node_content',
      'description' => t('A help page'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
