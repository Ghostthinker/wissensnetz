<?php

/**
 * @file
 * salto_group.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function salto_group_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ctools_custom_content" && $api == "ctools_content") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
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
function salto_group_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function salto_group_default_message_type() {
  $items = array();
  $items['notification_group_membership_removed'] = entity_import('message_type', '{
    "name" : "notification_group_membership_removed",
    "description" : "Notification: Group membership remove",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "de",
    "arguments" : null,
    "message_text" : {
      "de" : [
        {
          "value" : "[message:user:name] hat Ihre Gruppenmitgliedschaft in [message:field-notification-node-ref:title] beendet.\\r\\n",
          "format" : "php_code"
        }
      ],
      "en" : [
        {
          "value" : "\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E  hat den Beitrag \\u003Ca href=\\u0022[message:field-notification-comment-ref:url]\\u0022\\u003E[message:field-notification-node-ref:title]\\u003C\\/a\\u003E kommentiert",
          "format" : "machine",
          "safe_value" : "\\u003Ca href=\\u0022url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E  hat den Beitrag \\u003Ca href=\\u0022url]\\u0022\\u003E[message:field-notification-node-ref:title]\\u003C\\/a\\u003E kommentiert"
        }
      ]
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function salto_group_node_info() {
  $items = array(
    'group' => array(
      'name' => t('Gruppe'),
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

/**
 * Implements hook_default_og_membership_type().
 */
function salto_group_default_og_membership_type() {
  $items = array();
  $items['group_membership'] = entity_import('og_membership_type', '{
    "name" : "group_membership",
    "description" : "Group membership",
    "language" : ""
  }');
  return $items;
}

/**
 * Implements hook_default_salto_invite_type().
 */
function salto_group_default_salto_invite_type() {
  $items = array();
  $items['accept_invite'] = entity_import('salto_invite_type', '{
    "type" : "accept_invite",
    "label" : "Accept Invite",
    "weight" : "0",
    "data" : { "sample_data" : 0 }
  }');
  return $items;
}
