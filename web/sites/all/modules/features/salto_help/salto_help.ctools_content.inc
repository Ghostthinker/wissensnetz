<?php

/**
 * @file
 * salto_help.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function salto_help_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'support_add_help_link';
  $content->admin_title = 'support_add_help_link';
  $content->admin_description = '';
  $content->category = 'Help';
  $content->settings = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<div class="add-help">
<?php
$attributes = array(\'attributes\' => array(\'class\' => array(\'add-help-link\')),array(\'target\'=>\'_blank\'));
$attributes [\'attributes\'][\'target\'] = \'_blank\';
  print l(t(\'Add help enty\'), \'node/add/help\', $attributes);
//dpm( $attributes);
?></div>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $export['support_add_help_link'] = $content;

  return $export;
}
