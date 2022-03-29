<?php

/**
 * @file
 * salto_organisation.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function salto_organisation_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:organisation:license manager'.
  $roles['node:organisation:license manager'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'organisation',
    'name' => 'license manager',
  );

  // Exported OG Role: 'node:organisation:og role extern trainer'.
  $roles['node:organisation:og role extern trainer'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'organisation',
    'name' => 'og role extern trainer',
  );

  // Exported OG Role: 'node:organisation:og role further member'.
  $roles['node:organisation:og role further member'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'organisation',
    'name' => 'og role further member',
  );

  // Exported OG Role: 'node:organisation:og role license owner'.
  $roles['node:organisation:og role license owner'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'organisation',
    'name' => 'og role license owner',
  );

  // Exported OG Role: 'node:organisation:og role trainer'.
  $roles['node:organisation:og role trainer'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'organisation',
    'name' => 'og role trainer',
  );

  return $roles;
}
