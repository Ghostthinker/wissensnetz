<?php

/**
 * @file
 * salto_knowledgebase.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function salto_knowledgebase_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'leistungssport';
  $feeds_importer->config = array(
    'name' => 'Leistungssport',
    'description' => 'Trainer-Leistungssport.de',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 1,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => 'https://www.trainer-im-leistungssport.de/aktuelles/alle/feed?token=Nn5HCFm5MWZDamrqmk',
        'accept_invalid_cert' => 0,
        'cache_http_result' => 1,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '6952',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'parent:taxonomy:tags',
            'target' => 'field_taxonomy_post_tags',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'tags',
            'target' => 'field_post_tags',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          3 => array(
            'source' => 'description',
            'target' => 'body',
            'format' => 'editor',
            'language' => 'und',
          ),
          4 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 1,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'editor',
        'skip_hash_check' => 0,
        'bundle' => 'post',
        'language' => 'und',
      ),
    ),
    'content_type' => 'feed',
    'update' => 0,
    'import_period' => '86400',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['leistungssport'] = $feeds_importer;

  return $export;
}
