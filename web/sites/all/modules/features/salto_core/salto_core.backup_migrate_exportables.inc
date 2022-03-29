<?php
/**
 * @file
 * salto_core.backup_migrate_exportables.inc
 */

/**
 * Implements hook_exportables_backup_migrate_destinations().
 */
function salto_core_exportables_backup_migrate_destinations() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'storage19_scheduled';
  $item->name = 'Storage19 - scheduled';
  $item->subtype = 'ftp';
  $item->location = 'ftp://u197194-sub4:pMNwk2hJpntLCMYw@u197194.your-storagebox.de:21/dosb/';
  $item->settings = array(
    'pasv' => TRUE,
  );
  $export['storage19_scheduled'] = $item;

  return $export;
}

/**
 * Implements hook_exportables_backup_migrate_profiles().
 */
function salto_core_exportables_backup_migrate_profiles() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->machine_name = 'db1b';
  $item->name = 'Standardeinstellungen - without accesslog, cache, browscap, lims_api_log, visitors';
  $item->filename = '[site:name]';
  $item->append_timestamp = TRUE;
  $item->timestamp_format = 'Y-m-d\\TH-i-s';
  $item->filters = array(
    'compression' => 'gzip',
    'utils_site_offline' => 0,
    'utils_site_offline_message' => 'Wir führen auf Bildungsnetz DOSB momentan Wartungsarbeiten durch und sollten bald wieder erreichbar sein. Vielen Dank für Ihre Geduld.',
    'utils_description' => '',
    'use_cli' => 0,
    'ignore_errors' => 0,
    'notify_success_enable' => 0,
    'notify_success_email' => 'info@bildungsnetz.dosb.de',
    'notify_failure_enable' => 0,
    'notify_failure_email' => 'info@bildungsnetz.dosb.de',
    'sources' => array(
      'db' => array(
        'exclude_tables' => array(),
        'nodata_tables' => array(
          'accesslog' => 'accesslog',
          'browscap' => 'browscap',
          'cache' => 'cache',
          'cache_admin_menu' => 'cache_admin_menu',
          'cache_block' => 'cache_block',
          'cache_bootstrap' => 'cache_bootstrap',
          'cache_browscap' => 'cache_browscap',
          'cache_clients' => 'cache_clients',
          'cache_entity_message' => 'cache_entity_message',
          'cache_entity_message_type' => 'cache_entity_message_type',
          'cache_entity_message_type_category' => 'cache_entity_message_type_category',
          'cache_entity_og_membership' => 'cache_entity_og_membership',
          'cache_entity_og_membership_type' => 'cache_entity_og_membership_type',
          'cache_features' => 'cache_features',
          'cache_feeds_http' => 'cache_feeds_http',
          'cache_field' => 'cache_field',
          'cache_filter' => 'cache_filter',
          'cache_form' => 'cache_form',
          'cache_image' => 'cache_image',
          'cache_l10n_update' => 'cache_l10n_update',
          'cache_libraries' => 'cache_libraries',
          'cache_menu' => 'cache_menu',
          'cache_page' => 'cache_page',
          'cache_panels' => 'cache_panels',
          'cache_path' => 'cache_path',
          'cache_path_breadcrumbs' => 'cache_path_breadcrumbs',
          'cache_rules' => 'cache_rules',
          'cache_search_api_solr' => 'cache_search_api_solr',
          'cache_token' => 'cache_token',
          'cache_update' => 'cache_update',
          'cache_variable' => 'cache_variable',
          'cache_views' => 'cache_views',
          'cache_views_data' => 'cache_views_data',
          'ctools_css_cache' => 'ctools_css_cache',
          'ctools_object_cache' => 'ctools_object_cache',
          'lims_api_log' => 'lims_api_log',
          'search_dataset' => 'search_dataset',
          'search_index' => 'search_index',
          'search_total' => 'search_total',
          'sessions' => 'sessions',
          'visitors' => 'visitors',
          'watchdog' => 'watchdog',
        ),
        'utils_lock_tables' => 0,
      ),
      'files' => array(
        'exclude_filepaths' => 'backup_migrate
styles
css
js
ctools
less',
      ),
      'archive' => array(
        'exclude_filepaths' => 'public://backup_migrate
public://styles
public://css
public://js
public://ctools
public://less
private://backup_migrate
sites/default/settings.php
/tmp',
      ),
    ),
  );
  $export['db1b'] = $item;

  return $export;
}
