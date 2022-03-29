<?php

/**
 * @file
 * salto_organisation.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function salto_organisation_og_features_default_permissions() {
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

  // Exported og permission: 'node:organisation:cancel own membership'
  $permissions['node:organisation:cancel own membership'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:create ausbildungskonzept content'
  $permissions['node:organisation:create ausbildungskonzept content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'license manager' => 'license manager',
      'og role trainer' => 'og role trainer',
    ),
  );

  // Exported og permission: 'node:organisation:create file'
  $permissions['node:organisation:create file'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:create organisation content'
  $permissions['node:organisation:create organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:create post content'
  $permissions['node:organisation:create post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:create suborganisation'
  $permissions['node:organisation:create suborganisation'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'license manager' => 'license manager',
      'og role trainer' => 'og role trainer',
    ),
  );

  // Exported og permission: 'node:organisation:delete any ausbildungskonzept content'
  $permissions['node:organisation:delete any ausbildungskonzept content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:delete any file'
  $permissions['node:organisation:delete any file'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:delete any organisation content'
  $permissions['node:organisation:delete any organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:delete any post content'
  $permissions['node:organisation:delete any post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:delete own ausbildungskonzept content'
  $permissions['node:organisation:delete own ausbildungskonzept content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'license manager' => 'license manager',
      'og role trainer' => 'og role trainer',
    ),
  );

  // Exported og permission: 'node:organisation:delete own organisation content'
  $permissions['node:organisation:delete own organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:delete own post content'
  $permissions['node:organisation:delete own post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:delete suborganisation'
  $permissions['node:organisation:delete suborganisation'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:edit any file'
  $permissions['node:organisation:edit any file'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:edit collaboration fields'
  $permissions['node:organisation:edit collaboration fields'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:edit organisation license fields'
  $permissions['node:organisation:edit organisation license fields'] = array(
    'roles' => array(
      'license manager' => 'license manager',
    ),
  );

  // Exported og permission: 'node:organisation:invite existing users'
  $permissions['node:organisation:invite existing users'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'license manager' => 'license manager',
      'og role trainer' => 'og role trainer',
    ),
  );

  // Exported og permission: 'node:organisation:invite new users'
  $permissions['node:organisation:invite new users'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'license manager' => 'license manager',
      'og role trainer' => 'og role trainer',
    ),
  );

  // Exported og permission: 'node:organisation:manage all members'
  $permissions['node:organisation:manage all members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'license manager' => 'license manager',
      'og role trainer' => 'og role trainer',
    ),
  );

  // Exported og permission: 'node:organisation:manage members'
  $permissions['node:organisation:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organisation:manage membership fields'
  $permissions['node:organisation:manage membership fields'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:organisation:manage own membership'
  $permissions['node:organisation:manage own membership'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
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
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:subscribe without approval'
  $permissions['node:organisation:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:unsubscribe'
  $permissions['node:organisation:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:organisation:update any ausbildungskonzept content'
  $permissions['node:organisation:update any ausbildungskonzept content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'license manager' => 'license manager',
      'og role trainer' => 'og role trainer',
    ),
  );

  // Exported og permission: 'node:organisation:update any organisation content'
  $permissions['node:organisation:update any organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:update any post content'
  $permissions['node:organisation:update any post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:update group'
  $permissions['node:organisation:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'license manager' => 'license manager',
      'og role trainer' => 'og role trainer',
    ),
  );

  // Exported og permission: 'node:organisation:update own ausbildungskonzept content'
  $permissions['node:organisation:update own ausbildungskonzept content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'license manager' => 'license manager',
      'og role trainer' => 'og role trainer',
    ),
  );

  // Exported og permission: 'node:organisation:update own organisation content'
  $permissions['node:organisation:update own organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:update own post content'
  $permissions['node:organisation:update own post content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:organisation:view any file'
  $permissions['node:organisation:view any file'] = array(
    'roles' => array(),
  );

  return $permissions;
}
