<?php
/**
 * @file
 * salto_user.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function salto_user_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:organisation:add user'
  $permissions['node:organisation:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organisation:administer group'
  $permissions['node:organisation:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organisation:approve and deny subscription'
  $permissions['node:organisation:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organisation:manage members'
  $permissions['node:organisation:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organisation:manage permissions'
  $permissions['node:organisation:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organisation:manage roles'
  $permissions['node:organisation:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organisation:subscribe'
  $permissions['node:organisation:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:organisation:subscribe without approval'
  $permissions['node:organisation:subscribe without approval'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:organisation:unsubscribe'
  $permissions['node:organisation:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:organisation:update group'
  $permissions['node:organisation:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
