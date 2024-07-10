<?php

/**
 * @file
 * salto_activity.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function salto_activity_default_rules_configuration() {
  $items = array();
  $items['heartbeat_rules_hearbeat_node_update'] = entity_import('rules_config', '{ "heartbeat_rules_hearbeat_node_update" : {
      "LABEL" : "Hearbeat: Node update",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "salto_activity" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "node_is_published" : { "node" : [ "node" ] } },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "post" : "post",
                "group" : "group",
                "weiterbildungsmassnahme" : "weiterbildungsmassnahme"
              }
            }
          }
        },
        { "php_eval" : { "code" : "global $user;\\r\\n\\/\\/http:\\/\\/support.ghostthinker.de\\/scp\\/tickets.php?id=8051\\r\\n\\/\\/temporarily deactivating for 1798\\r\\nif ($node-\\u003Esalto_ignore_notification) {\\r\\n  return FALSE;\\r\\n} else {\\r\\n  return ((($node-\\u003Ecreated \\u003C= strtotime(\\u0022-4 hours\\u0022)) \\u0026\\u0026 $node-\\u003Euid == $user-\\u003Euid) || $node-\\u003Euid != $user-\\u003Euid) \\u0026\\u0026 $user-\\u003Euid != 1798;\\r\\n}\\r\\n\\r\\n\\r\\n" } },
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "2" : "2" } }
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_heartbeat_edit_node" : {
            "nid" : "[node:nid]",
            "uid" : "[site:current-user:uid]",
            "nid_target" : "0",
            "uid_target" : "0",
            "message_id" : { "value" : { "heartbeat_edit_node" : "heartbeat_edit_node" } },
            "!username" : "[site:current-user:link]",
            "!node_type" : "\\u003C?php \\r\\n   print t(\\u0022the \\u0022.node_type_get_name( $node));\\r\\n ?\\u003E ",
            "!node_title" : "[node:link]",
            "!node_reference" : "\\u003C?php\\r\\n\\/\\/dpm($node);\\r\\nif( $node-\\u003Efield_references[\\u0027und\\u0027][0][\\u0027target_id\\u0027] )\\r\\n{\\r\\n  $referenced_node = node_load( $node-\\u003Efield_references[\\u0027und\\u0027][0][\\u0027target_id\\u0027] );\\r\\n  $node_type_human = node_type_get_name( $referenced_node);\\r\\n  $node_link = l($referenced_node-\\u003Etitle, \\u0022node\\/$referenced_node-\\u003Enid\\u0022);\\r\\n  print \\u0022 \\u0022.t(\\u0027 to the \\u0027 . $node_type_human . \\u0027 !nodelink\\u0027, array(\\u0027@nodetype\\u0027 =\\u003E $node_type_human, \\u0027!nodelink\\u0027 =\\u003E $node_link ));\\r\\n}\\r\\n?\\u003E ",
            "!node_preview" : "\\u003C?php\\r\\n$value =  $node-\\u003Ebody[\\u0027und\\u0027][0][\\u0027value\\u0027];\\r\\n$value = check_markup($value, \\u0027editor\\u0027);\\r\\n$value =  strip_tags( $value );\\r\\n\\r\\n$alter[\\u0027max_length\\u0027] = 200;\\r\\n$alter[\\u0027word_boundary\\u0027] = TRUE;\\r\\n$alter[\\u0027ellipsis\\u0027] = TRUE;\\r\\n$alter[\\u0027html\\u0027] = TRUE;\\r\\n\\r\\nprint views_trim_text($alter, $value);\\r\\nprint  \\u0022 \\u0022.l(t(\\u0027Read more\\u0027), \\u0022node\\/$node-\\u003Enid\\u0022);\\r\\n?\\u003E",
            "!types" : "\\u003C?php\\r\\n\\/\\/dpm($node);\\r\\n  $node_type_human = node_type_get_name( $node);\\r\\nprint t($node_type_human.\\u0022s\\u0022);\\r\\n?\\u003E "
          }
        }
      ]
    }
  }');
  $items['heartbeat_rules_heartbeat_comemnt_created'] = entity_import('rules_config', '{ "heartbeat_rules_heartbeat_comemnt_created" : {
      "LABEL" : "Heartbeat: comemnt created",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "salto_activity" ],
      "REQUIRES" : [ "rules", "heartbeat_rules", "comment" ],
      "ON" : { "comment_update" : [], "comment_insert" : [] },
      "IF" : [
        { "NOT entity_is_of_bundle" : {
            "entity" : [ "comment:node" ],
            "type" : "node",
            "bundle" : { "value" : { "file_comments" : "file_comments" } }
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_heartbeat_add_comment" : {
            "nid" : "[comment:node:nid]",
            "uid" : "[comment:author:uid]",
            "nid_target" : "0",
            "uid_target" : "0",
            "cid" : "[comment:cid]",
            "message_id" : { "value" : { "heartbeat_add_comment" : "heartbeat_add_comment" } },
            "!username" : "[comment:author:link]",
            "!title" : "[comment:node:link]",
            "!comment" : "[comment:body]"
          }
        }
      ]
    }
  }');
  $items['heartbeat_rules_heartbeat_node_create'] = entity_import('rules_config', '{ "heartbeat_rules_heartbeat_node_create" : {
      "LABEL" : "Heartbeat: Node create",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "salto_activity" ],
      "REQUIRES" : [ "rules", "php", "heartbeat_rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_published" : { "node" : [ "node" ] } },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "post" : "post",
                "group" : "group",
                "weiterbildungsmassnahme" : "weiterbildungsmassnahme"
              }
            }
          }
        },
        { "NOT user_has_role" : {
            "account" : [ "node:author" ],
            "roles" : { "value" : { "1" : "1", "5" : "5" } }
          }
        }
      ],
      "DO" : [
        { "heartbeat_activity_heartbeat_add_node" : {
            "nid" : "[node:nid]",
            "uid" : "[node:author:uid]",
            "nid_target" : "0",
            "uid_target" : "0",
            "message_id" : { "value" : { "heartbeat_add_node" : "heartbeat_add_node" } },
            "!username" : "[node:author:link]",
            "!node_type" : "\\u003C?php \\r\\n   print t(\\u0022the \\u0022.node_type_get_name( $node));\\r\\n ?\\u003E ",
            "!node_title" : "[node:link]",
            "!node_reference" : "\\u003C?php\\r\\n\\/\\/dpm($node);\\r\\nif(!empty( $node-\\u003Efield_references[\\u0027und\\u0027][0][\\u0027target_id\\u0027] ))\\r\\n{\\r\\n  $referenced_node = node_load( $node-\\u003Efield_references[\\u0027und\\u0027][0][\\u0027target_id\\u0027] );\\r\\n  $node_type_human = node_type_get_name( $referenced_node);\\r\\n  $node_link = l($referenced_node-\\u003Etitle, \\u0022node\\/$referenced_node-\\u003Enid\\u0022);\\r\\n  print \\u0022 \\u0022.t(\\u0027 to the \\u0027 . $node_type_human . \\u0027 !nodelink\\u0027, array(\\u0027@nodetype\\u0027 =\\u003E $node_type_human, \\u0027!nodelink\\u0027 =\\u003E $node_link ));\\r\\n}\\r\\n?\\u003E ",
            "!node_preview" : "\\u003C?php\\r\\nif(!empty($node-\\u003Ebody[\\u0027und\\u0027][0][\\u0027value\\u0027])){\\r\\n$value =  $node-\\u003Ebody[\\u0027und\\u0027][0][\\u0027value\\u0027];\\r\\n$value = check_markup($value, \\u0027editor\\u0027);\\r\\n$value =  strip_tags( $value );\\r\\n\\r\\n$alter[\\u0027max_length\\u0027] = 200;\\r\\n$alter[\\u0027word_boundary\\u0027] = TRUE;\\r\\n$alter[\\u0027ellipsis\\u0027] = TRUE;\\r\\n$alter[\\u0027html\\u0027] = TRUE;\\r\\n\\r\\nprint views_trim_text($alter, $value);\\r\\nprint  \\u0022 \\u0022.l(t(\\u0027Read more\\u0027), \\u0022node\\/$node-\\u003Enid\\u0022);\\r\\n}\\r\\n?\\u003E",
            "!types" : "\\u003C?php\\r\\n\\/\\/dpm($node);\\r\\n  $node_type_human = node_type_get_name( $node);\\r\\nprint t($node_type_human.\\u0022s\\u0022);\\r\\n?\\u003E "
          }
        }
      ]
    }
  }');
  $items['heartbeat_rules_heartbeat_user_updated'] = entity_import('rules_config', '{ "heartbeat_rules_heartbeat_user_updated" : {
      "LABEL" : "Heartbeat: User updated",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "salto_activity" ],
      "REQUIRES" : [ "rules", "heartbeat_rules" ],
      "ON" : { "user_update" : [] },
      "DO" : [
        { "heartbeat_activity_heartbeat_edit_account" : {
            "nid" : "0",
            "uid" : "[account:uid]",
            "nid_target" : "0",
            "uid_target" : "0",
            "message_id" : { "value" : { "heartbeat_edit_account" : "heartbeat_edit_account" } },
            "!username" : "[account:link]"
          }
        }
      ]
    }
  }');
  $items['salto_activity_heartbeat_node_update_creator'] = entity_import('rules_config', '{ "salto_activity_heartbeat_node_update_creator" : {
      "LABEL" : "Heartbeat: Node update creator",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "salto_activity" ],
      "REQUIRES" : [ "rules", "php" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "node_is_published" : { "node" : [ "node" ] } },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "post" : "post",
                "group" : "group",
                "weiterbildungsmassnahme" : "weiterbildungsmassnahme"
              }
            }
          }
        },
        { "NOT php_eval" : { "code" : "global $user;\\r\\nreturn (($node-\\u003Ecreated \\u003C= strtotime(\\u0022-4 hours\\u0022)) \\u0026\\u0026 $node-\\u003Euid == $user-\\u003Euid);" } },
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "2" : "2" } }
          }
        }
      ],
      "DO" : [
        { "php_eval" : { "code" : "salto_knowledgebase_update_heartbeat_activity_node($node, \\u0027heartbeat_add_node\\u0027);\\r\\nsalto_knowledgebase_update_heartbeat_activity_node($node, \\u0027heartbeat_edit_node\\u0027);" } }
      ]
    }
  }');
  return $items;
}
