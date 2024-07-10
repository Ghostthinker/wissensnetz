<?php

/**
 * @file
 * salto_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function salto_user_user_default_roles() {
  $roles = array();

  // Exported role: Ghost.
  $roles['Ghost'] = array(
    'name' => 'Ghost',
    'weight' => 4,
  );

  return $roles;
}
