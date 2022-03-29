<?php
/**
 * @file
 * salto_share.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function salto_share_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ctools_custom_content" && $api == "ctools_content") {
    return array("version" => "1");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function salto_share_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function salto_share_default_message_type() {
  $items = array();
  $items['notification_shared_post'] = entity_import('message_type', '{
    "name" : "notification_shared_post",
    "description" : "Notification: Shared Post",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "message_text" : {
      "de" : [
        {
          "value" : "\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E  hat den Beitrag \\u003Ca href=\\u0022[message:field-notification-node-ref:url]\\u0022\\u003E[message:field-notification-node-ref:title]\\u003C\\/a\\u003E empfohlen.",
          "format" : "php_code"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E  hat den Beitrag \\u003Ca href=\\u0022[message:field-notification-node-ref:url]\\u0022\\u003E[message:field-notification-node-ref:title]\\u003C\\/a\\u003E empfohlen.",
          "format" : "machine",
          "safe_value" : "\\u003Ca href=\\u0022url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E  hat den Beitrag \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-notification-node-ref:title]\\u003C\\/a\\u003E empfohlen."
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function salto_share_node_info() {
  $items = array(
    'shared_post' => array(
      'name' => t('Geteilter Beitrag'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
