<?php
/**
 * @file
 * salto_statistics.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function salto_statistics_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer piwik'.
  $permissions['administer piwik'] = array(
    'name' => 'administer piwik',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'create statistics_daily content'.
  $permissions['create statistics_daily content'] = array(
    'name' => 'create statistics_daily content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any statistics_daily content'.
  $permissions['delete any statistics_daily content'] = array(
    'name' => 'delete any statistics_daily content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own statistics_daily content'.
  $permissions['delete own statistics_daily content'] = array(
    'name' => 'delete own statistics_daily content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any statistics_daily content'.
  $permissions['edit any statistics_daily content'] = array(
    'name' => 'edit any statistics_daily content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own statistics_daily content'.
  $permissions['edit own statistics_daily content'] = array(
    'name' => 'edit own statistics_daily content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'piwik',
  );

  return $permissions;
}
