<?php

/**
 * @file
 * onsite_notification.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function onsite_notification_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
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
function onsite_notification_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function onsite_notification_flag_default_flags() {
  $flags = array();
  // Exported flag: "Notification: Ignore material".
  $flags['notification_ignore_material'] = array(
    'entity_type' => 'file',
    'title' => 'Notification: Ignore material',
    'global' => 0,
    'types' => array(
      0 => 'image',
      1 => 'video',
      2 => 'audio',
      3 => 'document',
      4 => 'swf',
      5 => 'webresource',
    ),
    'flag_short' => 'Ignorieren',
    'flag_long' => 'Klicken Sie hier, um dieses Material zu ignorieren und somit keine Benachrichtigungen mehr zu erhalten.',
    'flag_message' => '',
    'unflag_short' => 'Wieder Benachrichtigen',
    'unflag_long' => 'Klicken Sie hier, um wieder  Nachrichten über dieses Material zu erhalten.',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'teaser' => 0,
      'full' => 0,
      'preview' => 0,
      'rss' => 0,
      'colorbox' => 0,
      'wysiwyg' => 0,
      'token' => 0,
      'default_selection_wysiwyg' => 0,
      'listing' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'onsite_notification',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Notification: Ignore post".
  $flags['notification_ignore_post'] = array(
    'entity_type' => 'node',
    'title' => 'Notification: Ignore post',
    'global' => 0,
    'types' => array(
      0 => 'post',
    ),
    'flag_short' => 'Ignorieren',
    'flag_long' => 'Klicken Sie hier, um diesen Beitrag zu ignorieren und somit keine Benachrichtigungen mehr zu erhalten.',
    'flag_message' => '',
    'unflag_short' => 'Wieder Benachrichtigen',
    'unflag_long' => 'Klicken Sie hier, um wieder  Nachrichten über diesen Beitrag zu erhalten.',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -6,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'print' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'membership_compact' => 0,
      'salto_diff' => 0,
      'shared_post' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'onsite_notification',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Notification: Mark as read".
  $flags['notification_mark_as_read'] = array(
    'entity_type' => 'message',
    'title' => 'Notification: Mark as read',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'mark as read',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Mark as unread',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -11,
    'show_in_links' => array(
      'full' => 'full',
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'onsite_notification',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Notification: Subscribe material".
  $flags['notification_subscribe_material'] = array(
    'entity_type' => 'file',
    'title' => 'Notification: Subscribe material',
    'global' => 0,
    'types' => array(
      0 => 'image',
      1 => 'video',
      2 => 'audio',
      3 => 'document',
      4 => 'swf',
      5 => 'webresource',
    ),
    'flag_short' => 'Abonnieren',
    'flag_long' => 'Klicken Sie auf "Abonnieren", um über diesen Beitrag auf dem Laufenden gehalten zu werden.',
    'flag_message' => '',
    'unflag_short' => 'Abonniert',
    'unflag_long' => 'Klicken Sie hier, um keine Benachrichtigungen mehr zu diesem Beitrag zu erhalten. Sie können ihn jederzeit wieder abonnieren.',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -9,
    'show_in_links' => array(
      'teaser' => 0,
      'full' => 0,
      'preview' => 0,
      'rss' => 0,
      'colorbox' => 0,
      'wysiwyg' => 0,
      'token' => 0,
      'default_selection_wysiwyg' => 0,
      'listing' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'onsite_notification',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Notification: Subscribe node".
  $flags['notification_subscribe_node'] = array(
    'entity_type' => 'node',
    'title' => 'Notification: Subscribe node',
    'global' => 0,
    'types' => array(
      0 => 'ausbildungskonzept',
      1 => 'post',
      2 => 'group',
      3 => 'weiterbildungsmassnahme',
    ),
    'flag_short' => 'Abonnieren',
    'flag_long' => 'Klicken Sie auf "Abonnieren", um über diesen Beitrag auf dem Laufenden gehalten zu werden.',
    'flag_message' => '',
    'unflag_short' => 'Abonniert',
    'unflag_long' => 'Klicken Sie hier, um keine Benachrichtigungen mehr zu diesem Beitrag zu erhalten. Sie können ihn jederzeit wieder abonnieren.',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => -10,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'print' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'membership_compact' => 0,
      'salto_diff' => 0,
      'shared_post' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'onsite_notification',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_default_message_type().
 */
function onsite_notification_default_message_type() {
  $items = array();
  $items['notification_base'] = entity_import('message_type', '{
    "name" : "notification_base",
    "description" : "Notification: base",
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
          "value" : "\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E  hat den Beitrag \\u003Ca href=\\u0022[message:field-notification-comment-ref:url]\\u0022\\u003E[message:field-notification-node-ref:title]\\u003C\\/a\\u003E kommentiert",
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
  $items['notification_create_comment'] = entity_import('message_type', '{
    "name" : "notification_create_comment",
    "description" : "Notification: Comment created on a subscribed content",
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
          "value" : "@{message:user:name}  hat den Inhalt [message:field-notification-node-ref:title] kommentiert.",
          "format" : "php_code"
        }
      ],
      "en" : [
        {
          "value" : "@{message:user:name}  hat den Inhalt [message:field-notification-node-ref:title] kommentiert.",
          "format" : "machine",
          "safe_value" : "@{message:user:name}  hat den Inhalt [message:field-notification-node-ref:title] kommentiert."
        }
      ]
    }
  }');
  $items['notification_create_comment_reply'] = entity_import('message_type', '{
    "name" : "notification_create_comment_reply",
    "description" : "Notification: A reply was made to one of my comments",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "de",
    "arguments" : null,
    "message_text" : {
      "de" : [
        {
          "value" : "[message:user:name] hat auf Ihren Kommentar [message:field-notification-comment-ref:parent:original] geantwortet. [message:field-notification-comment-ref:original:subject]\\r\\n\\r\\n[message:field_notification_comment_ref:original:subject]\\r\\n",
          "format" : "php_code"
        }
      ],
      "en" : [
        {
          "value" : "[message:user:name] hat den auf ihren Kommentar [message:field-notification-comment-ref:parent:original]  geantwortet.",
          "format" : "machine",
          "safe_value" : "[message:user:name] hat den auf ihren Kommentar [message:field-notification-comment-ref:parent:original]  geantwortet."
        }
      ]
    }
  }');
  $items['notification_group_invite_recieved'] = entity_import('message_type', '{
    "name" : "notification_group_invite_recieved",
    "description" : "Notification: Group Invite recieved",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "de",
    "arguments" : null,
    "message_text" : {
      "de" : [
        {
          "value" : "[message:user:name] hat Sie in die Gruppe  [message:field-notification-node-ref:title] eingeladen.",
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
  $items['notification_group_membership_request'] = entity_import('message_type', '{
    "name" : "notification_group_membership_request",
    "description" : "Notification: Membership was for my Groups was requested",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "de",
    "arguments" : null,
    "message_text" : {
      "de" : [
        {
          "value" : "@{message:user:name} hat eine Beitrittsanfrage f\\u00fcr die Gruppe [message:field-notification-node-ref:title] gestellt.",
          "format" : "php_code"
        }
      ],
      "en" : [
        {
          "value" : "@{message:user:name} hat den Beitrag [message:field-notification-node-ref:title] bearbeitet.",
          "format" : "machine",
          "safe_value" : "@{message:user:name} hat den Beitrag [message:field-notification-node-ref:title] bearbeitet."
        }
      ]
    }
  }');
  $items['notification_group_post_created'] = entity_import('message_type', '{
    "name" : "notification_group_post_created",
    "description" : "Notification: Group Post created",
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
          "value" : "@{message:user:name} hat einen neuen Beitrag [message:field-notification-node-ref:title] in der Gruppe [message:field-notification-group-ref:title] erstellt.",
          "format" : "machine",
          "safe_value" : "@{message:user:name} hat einen neuen Beitrag [message:field-notification-node-ref:title] in der Gruppe [message:field-notification-group-ref:title] erstellt."
        }
      ],
      "en" : [
        {
          "value" : "@{message:user:name} hat einen neuen Beitrag [message:field-notification-node-ref:title] in der Gruppe [message:field-notification-group-ref:title] erstellt.",
          "format" : "machine",
          "safe_value" : "@{message:user:name} hat einen neuen Beitrag [message:field-notification-node-ref:title] in der Gruppe [message:field-notification-group-ref:title] erstellt."
        }
      ]
    }
  }');
  $items['notification_license_correct_by'] = entity_import('message_type', '{
    "name" : "notification_license_correct_by",
    "description" : "Notification: License correct by",
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
        { "value" : "!{message:field_notification_note}", "format" : "php_code" }
      ],
      "en" : [
        { "value" : "!{message:field_notification_note}", "format" : "php_code" }
      ]
    }
  }');
  $items['notification_license_forms_were_requested'] = entity_import('message_type', '{
    "name" : "notification_license_forms_were_requested",
    "description" : "Notification: License-forms were requested",
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
          "value" : "@{message:user:name} !{message:field_notification_note}",
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
  $items['notification_license_migrate'] = entity_import('message_type', '{
    "name" : "notification_license_migrate",
    "description" : "Notification: License migration",
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
          "value" : "@{message:user:name} !{message:field_notification_note}",
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
  $items['notification_licenses_marked_for_extension'] = entity_import('message_type', '{
    "name" : "notification_licenses_marked_for_extension",
    "description" : "Notification: Licenses marked for extension",
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
          "value" : "Eine oder mehrere Lizenz(en) ([message:field-notification-node-ref:title]) k\\u00f6nnen nun verl\\u00e4ngert ausgegeben werden.",
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
  $items['notification_material_created'] = entity_import('message_type', '{
    "name" : "notification_material_created",
    "description" : "Notification: Material created",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "de",
    "arguments" : null,
    "message_text" : { "de" : [
        {
          "value" : "@{message:user:name} hat ein neues Material [message:field-notification-file-ref:name] im Gemeinschaftsbereich erstellt.",
          "format" : "machine",
          "safe_value" : "@{message:user:name} hat ein neues Material [message:field-notification-file-ref:name] im Gemeinschaftsbereich erstellt."
        }
      ]
    }
  }');
  $items['notification_material_updated'] = entity_import('message_type', '{
    "name" : "notification_material_updated",
    "description" : "Notification: Material updated",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 1 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "de",
    "arguments" : null,
    "message_text" : { "de" : [
        {
          "value" : "@{message:user:name} hat das Material [message:field-notification-file-ref:name] bearbeitet.",
          "format" : "machine",
          "safe_value" : "@{message:user:name} hat das Material [message:field-notification-file-ref:name] bearbeitet."
        }
      ]
    }
  }');
  $items['notification_online_meeting_scheduled'] = entity_import('message_type', '{
    "name" : "notification_online_meeting_scheduled",
    "description" : "Notification: Online Meeting scheduled",
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
          "value" : "@{message:user:name} hat eine Benachrichtigung zum Online-Treffen [message:field-notification-node-ref:title] in einer Ihrer Gruppe versandt.",
          "format" : "machine",
          "safe_value" : "@{message:user:name} hat eine Benachrichtigung zum Online-Treffen [message:field-notification-node-ref:title] in einer Ihrer Gruppe versandt."
        }
      ],
      "en" : [
        {
          "value" : "@{message:user:name} hat einen neuen Beitrag [message:field-notification-node-ref:title] im Gemeinschaftsbereich erstellt.",
          "format" : "machine",
          "safe_value" : "@{message:user:name} hat einen neuen Beitrag [message:field-notification-node-ref:title] im Gemeinschaftsbereich erstellt."
        }
      ]
    }
  }');
  $items['notification_post_created'] = entity_import('message_type', '{
    "name" : "notification_post_created",
    "description" : "Notification: Post created",
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
          "value" : "@{message:user:name} hat einen neuen Beitrag [message:field-notification-node-ref:title] im Gemeinschaftsbereich erstellt.",
          "format" : "machine",
          "safe_value" : "@{message:user:name} hat einen neuen Beitrag [message:field-notification-node-ref:title] im Gemeinschaftsbereich erstellt."
        }
      ],
      "en" : [
        {
          "value" : "@{message:user:name} hat einen neuen Beitrag [message:field-notification-node-ref:title] im Gemeinschaftsbereich erstellt.",
          "format" : "machine",
          "safe_value" : "@{message:user:name} hat einen neuen Beitrag [message:field-notification-node-ref:title] im Gemeinschaftsbereich erstellt."
        }
      ]
    }
  }');
  $items['notification_private_message_received'] = entity_import('message_type', '{
    "name" : "notification_private_message_received",
    "description" : "Private message received",
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
          "value" : "@{message:user:name}  hat Ihnen eine pers\\u00f6nliche Nachricht [message:field-notification-privatemsg:subject] gesendet.",
          "format" : "php_code"
        }
      ],
      "en" : [
        {
          "value" : "@{message:user:name}  hat den Beitrag [message:field-notification-node-ref:title] kommentiert.",
          "format" : "machine",
          "safe_value" : "@{message:user:name}  hat den Beitrag [message:field-notification-node-ref:title] kommentiert."
        }
      ]
    }
  }');
  $items['notification_revision_created'] = entity_import('message_type', '{
    "name" : "notification_revision_created",
    "description" : "Notification: Revision Created",
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
          "value" : "@{message:user:name} hat den Beitrag [message:field-notification-node-ref:title] bearbeitet.",
          "format" : "php_code"
        }
      ],
      "en" : [
        {
          "value" : "@{message:user:name} hat den Beitrag [message:field-notification-node-ref:title] bearbeitet.",
          "format" : "machine",
          "safe_value" : "@{message:user:name} hat den Beitrag [message:field-notification-node-ref:title] bearbeitet."
        }
      ]
    }
  }');
  $items['notification_user_mentioned'] = entity_import('message_type', '{
    "name" : "notification_user_mentioned",
    "description" : "Notification: User mentioned",
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
          "value" : "@{message:user:name} hat Sie [content-prefix] [message:field-notification-node-ref:title] erw\\u00e4hnt.",
          "format" : "php_code"
        }
      ],
      "en" : [
        {
          "value" : "@{message:user:name}  hat den Inhalt [message:field-notification-node-ref:title] kommentiert.",
          "format" : "machine",
          "safe_value" : "@{message:user:name}  hat den Inhalt [message:field-notification-node-ref:title] kommentiert."
        }
      ]
    }
  }');
  return $items;
}
