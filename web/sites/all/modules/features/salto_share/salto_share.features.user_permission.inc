<?php
/**
 * @file
 * salto_share.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function salto_share_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create shared_post content'.
  $permissions['create shared_post content'] = array(
    'name' => 'create shared_post content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any shared_post content'.
  $permissions['delete any shared_post content'] = array(
    'name' => 'delete any shared_post content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own shared_post content'.
  $permissions['delete own shared_post content'] = array(
    'name' => 'delete own shared_post content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any shared_post content'.
  $permissions['edit any shared_post content'] = array(
    'name' => 'edit any shared_post content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own shared_post content'.
  $permissions['edit own shared_post content'] = array(
    'name' => 'edit own shared_post content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
