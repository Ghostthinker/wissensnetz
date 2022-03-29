<?php

/**
 * @file
 * salto_group.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function salto_group_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:add user'
  $permissions['node:group:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:administer group'
  $permissions['node:group:administer group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:approve and deny subscription'
  $permissions['node:group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:cancel own membership'
  $permissions['node:group:cancel own membership'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:create ausbildungskonzept content'
  $permissions['node:group:create ausbildungskonzept content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:create file'
  $permissions['node:group:create file'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:create organisation content'
  $permissions['node:group:create organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:create post content'
  $permissions['node:group:create post content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:delete any ausbildungskonzept content'
  $permissions['node:group:delete any ausbildungskonzept content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any file'
  $permissions['node:group:delete any file'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:delete any organisation content'
  $permissions['node:group:delete any organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete any post content'
  $permissions['node:group:delete any post content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:delete group'
  $permissions['node:group:delete group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:delete own ausbildungskonzept content'
  $permissions['node:group:delete own ausbildungskonzept content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete own organisation content'
  $permissions['node:group:delete own organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:delete own post content'
  $permissions['node:group:delete own post content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:edit any file'
  $permissions['node:group:edit any file'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:edit any file category'
  $permissions['node:group:edit any file category'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:edit collaboration fields'
  $permissions['node:group:edit collaboration fields'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:invite existing users'
  $permissions['node:group:invite existing users'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:invite new users'
  $permissions['node:group:invite new users'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:manage all members'
  $permissions['node:group:manage all members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:manage group category'
  $permissions['node:group:manage group category'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:manage members'
  $permissions['node:group:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:manage membership fields'
  $permissions['node:group:manage membership fields'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:manage own membership'
  $permissions['node:group:manage own membership'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:manage permissions'
  $permissions['node:group:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:manage roles'
  $permissions['node:group:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:subscribe'
  $permissions['node:group:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:subscribe without approval'
  $permissions['node:group:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:unsubscribe'
  $permissions['node:group:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:update any ausbildungskonzept content'
  $permissions['node:group:update any ausbildungskonzept content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any organisation content'
  $permissions['node:group:update any organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update any post content'
  $permissions['node:group:update any post content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update group'
  $permissions['node:group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:group:update own ausbildungskonzept content'
  $permissions['node:group:update own ausbildungskonzept content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update own organisation content'
  $permissions['node:group:update own organisation content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:update own post content'
  $permissions['node:group:update own post content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:group:view any file'
  $permissions['node:group:view any file'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  return $permissions;
}
