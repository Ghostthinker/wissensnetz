<?php
/**
 * @file
 * salto_user.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function salto_user_default_rules_configuration() {
  $items = array();
  $items['rules_profile_tweak_set_picture'] = entity_import('rules_config', '{ "rules_profile_tweak_set_picture" : {
      "LABEL" : "profile_tweak_set_picture",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "tweak" ],
      "REQUIRES" : [ "php", "rules" ],
      "ON" : { "user_update" : [] },
      "DO" : [ { "php_eval" : { "code" : "dpm($account);" } } ]
    }
  }');
  return $items;
}
