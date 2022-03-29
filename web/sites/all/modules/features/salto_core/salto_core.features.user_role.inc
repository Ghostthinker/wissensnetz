<?php

/**
 * @file
 * salto_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function salto_core_user_default_roles() {
  $roles = array();

  // Exported role: Admin.
  $roles['Admin'] = array(
    'name' => 'Admin',
    'weight' => 2,
  );

  // Exported role: DOSB.
  $roles['DOSB'] = array(
    'name' => 'DOSB',
    'weight' => 5,
  );

  // Exported role: Gärtner.
  $roles['Gärtner'] = array(
    'name' => 'Gärtner',
    'weight' => 7,
  );

  // Exported role: Support.
  $roles['Support'] = array(
    'name' => 'Support',
    'weight' => 3,
  );

  return $roles;
}
