<?php

/**
 * @file
 * salto_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function salto_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'salto cancel own account'.
  $permissions['salto cancel own account'] = array(
    'name' => 'salto cancel own account',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user_delete',
  );

  return $permissions;
}
