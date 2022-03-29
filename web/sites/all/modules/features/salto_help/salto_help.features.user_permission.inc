<?php
/**
 * @file
 * salto_help.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function salto_help_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag help_entry_useful_no'.
  $permissions['flag help_entry_useful_no'] = array(
    'name' => 'flag help_entry_useful_no',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag help_entry_useful_yes'.
  $permissions['flag help_entry_useful_yes'] = array(
    'name' => 'flag help_entry_useful_yes',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag help_entry_useful_no'.
  $permissions['unflag help_entry_useful_no'] = array(
    'name' => 'unflag help_entry_useful_no',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag help_entry_useful_yes'.
  $permissions['unflag help_entry_useful_yes'] = array(
    'name' => 'unflag help_entry_useful_yes',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
