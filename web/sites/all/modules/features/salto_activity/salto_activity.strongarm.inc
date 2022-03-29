<?php
/**
 * @file
 * salto_activity.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function salto_activity_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'features_semaphore';
  $strongarm->value = array();
  $export['features_semaphore'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_heartbeat_activity__heartbeat_add_comment';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'membership_compact' => array(
        'custom_settings' => TRUE,
      ),
      'heartbeat_compact' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'avatar' => array(
          'default' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'membership_compact' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
        'username' => array(
          'default' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'membership_compact' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
        ),
        'message' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'time' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'buttons' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_heartbeat_activity__heartbeat_add_comment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_heartbeat_activity__heartbeat_add_node';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'membership_compact' => array(
        'custom_settings' => TRUE,
      ),
      'heartbeat_compact' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'avatar' => array(
          'default' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'token' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'membership_compact' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'heartbeat_compact' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
        'username' => array(
          'default' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'token' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'membership_compact' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'heartbeat_compact' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
        ),
        'message' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'token' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'heartbeat_compact' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'time' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'token' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'heartbeat_compact' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'buttons' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'token' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'membership_compact' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'heartbeat_compact' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_heartbeat_activity__heartbeat_add_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_heartbeat_activity__heartbeat_edit_account';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'membership_compact' => array(
        'custom_settings' => TRUE,
      ),
      'heartbeat_compact' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'avatar' => array(
          'default' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'membership_compact' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
        'username' => array(
          'default' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'membership_compact' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
        ),
        'message' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'time' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'buttons' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_heartbeat_activity__heartbeat_edit_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_heartbeat_activity__heartbeat_edit_node';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'membership_compact' => array(
        'custom_settings' => TRUE,
      ),
      'heartbeat_compact' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'avatar' => array(
          'default' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'membership_compact' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
        'username' => array(
          'default' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'membership_compact' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
        ),
        'message' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'time' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'buttons' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_heartbeat_activity__heartbeat_edit_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_heartbeat_activity__heartbeat_tweet';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'membership_compact' => array(
        'custom_settings' => TRUE,
      ),
      'heartbeat_compact' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'avatar' => array(
          'default' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'membership_compact' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'username' => array(
          'default' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'membership_compact' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
        'message' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'time' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'buttons' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'membership_compact' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_heartbeat_activity__heartbeat_tweet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_activity_grouping_how_many';
  $strongarm->value = '5';
  $export['heartbeat_activity_grouping_how_many'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_activity_grouping_seconds';
  $strongarm->value = '7200';
  $export['heartbeat_activity_grouping_seconds'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_activity_log_cron_delete';
  $strongarm->value = '0';
  $export['heartbeat_activity_log_cron_delete'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_activity_records_per_user';
  $strongarm->value = '1000';
  $export['heartbeat_activity_records_per_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_allowed_html_tags';
  $strongarm->value = 'a em strong blockquote ul ol li p div';
  $export['heartbeat_allowed_html_tags'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_debug';
  $strongarm->value = 0;
  $export['heartbeat_debug'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_enabled';
  $strongarm->value = 1;
  $export['heartbeat_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_include_default_style';
  $strongarm->value = 1;
  $export['heartbeat_include_default_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_profile_message_templates';
  $strongarm->value = array();
  $export['heartbeat_profile_message_templates'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_show_message_times';
  $strongarm->value = 1;
  $export['heartbeat_show_message_times'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_show_time_grouped_items';
  $strongarm->value = 1;
  $export['heartbeat_show_time_grouped_items'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_show_user_profile_messages_kbactivity';
  $strongarm->value = 0;
  $export['heartbeat_show_user_profile_messages_kbactivity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'heartbeat_show_user_profile_messages_useractivity';
  $strongarm->value = 1;
  $export['heartbeat_show_user_profile_messages_useractivity'] = $strongarm;

  return $export;
}
