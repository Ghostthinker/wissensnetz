<?php

/**
 * @file
 * salto_organisation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function salto_organisation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit any organisation_invite salto invite'.
  $permissions['edit any organisation_invite salto invite'] = array(
    'name' => 'edit any organisation_invite salto invite',
    'roles' => array(),
    'module' => 'salto_invite',
  );

  // Exported permission: 'edit organisation meta fields'.
  $permissions['edit organisation meta fields'] = array(
    'name' => 'edit organisation meta fields',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
    ),
    'module' => 'salto_organisation',
  );

  // Exported permission: 'manage people in any organisation'.
  $permissions['manage people in any organisation'] = array(
    'name' => 'manage people in any organisation',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
    ),
    'module' => 'salto_organisation',
  );

  // Exported permission: 'view any organisation_invite salto_invite'.
  $permissions['view any organisation_invite salto_invite'] = array(
    'name' => 'view any organisation_invite salto_invite',
    'roles' => array(),
    'module' => 'salto_invite',
  );

  return $permissions;
}
