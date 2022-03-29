<?php

/**
 * @file
 * salto_online_meeting.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function salto_online_meeting_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:create online_meeting content'
  $permissions['node:group:create online_meeting content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete any online_meeting content'
  $permissions['node:group:delete any online_meeting content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:delete own online_meeting content'
  $permissions['node:group:delete own online_meeting content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update any online_meeting content'
  $permissions['node:group:update any online_meeting content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update own online_meeting content'
  $permissions['node:group:update own online_meeting content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:organisation:create online_meeting content'
  $permissions['node:organisation:create online_meeting content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:delete any online_meeting content'
  $permissions['node:organisation:delete any online_meeting content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:delete own online_meeting content'
  $permissions['node:organisation:delete own online_meeting content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:update any online_meeting content'
  $permissions['node:organisation:update any online_meeting content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:update own online_meeting content'
  $permissions['node:organisation:update own online_meeting content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
