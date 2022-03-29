<?php
/**
 * @file
 * salto_share.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function salto_share_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:create shared_post content'
  $permissions['node:group:create shared_post content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete any shared_post content'
  $permissions['node:group:delete any shared_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete own shared_post content'
  $permissions['node:group:delete own shared_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any shared_post content'
  $permissions['node:group:update any shared_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update own shared_post content'
  $permissions['node:group:update own shared_post content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:organisation:create shared_post content'
  $permissions['node:organisation:create shared_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:delete any shared_post content'
  $permissions['node:organisation:delete any shared_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:delete own shared_post content'
  $permissions['node:organisation:delete own shared_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:update any shared_post content'
  $permissions['node:organisation:update any shared_post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:update own shared_post content'
  $permissions['node:organisation:update own shared_post content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
