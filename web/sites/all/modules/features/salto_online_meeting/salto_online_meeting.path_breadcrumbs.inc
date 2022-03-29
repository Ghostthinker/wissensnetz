<?php

/**
 * @file
 * salto_online_meeting.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function salto_online_meeting_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_online_meeting_overview';
  $path_breadcrumb->name = 'Group Online Meetings';
  $path_breadcrumb->path = 'groups/%node/online-meetings/status';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
      2 => 'Online-Treffen',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
      2 => 'groups/%node:nid/online-meetings/status',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -80;
  $export['group_online_meeting_overview'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_online_meeting_status';
  $path_breadcrumb->name = 'Group Online Meetings';
  $path_breadcrumb->path = 'groups/%node/online-meetings/status/%state';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
      2 => 'Online-Treffen',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
      2 => 'groups/%node:nid/online-meetings/status',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
      'state' => array(
        'position' => 4,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -80;
  $export['group_online_meeting_status'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'online_meeting_node_view_in_group';
  $path_breadcrumb->name = 'Online-Meeting: Node View in Gruppe';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:field-og-group:title',
      2 => 'Online-Treffen',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:field-og-group:nid',
      2 => 'groups/%node:field-og-group:nid/online-meetings/status',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if node is OG Content',
            'php' => '$node = $contexts[\'node\']->data;
if (isset($node ->field_og_group[LANGUAGE_NONE][0][\'target_id\'])) {
 return true ;
}
return  false;
',
          ),
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'online_meeting' => 'online_meeting',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -34;
  $export['online_meeting_node_view_in_group'] = $path_breadcrumb;

  return $export;
}
