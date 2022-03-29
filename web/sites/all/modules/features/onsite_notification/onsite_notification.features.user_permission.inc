<?php

/**
 * @file
 * onsite_notification.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function onsite_notification_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit any accept_invite salto invite'.
  $permissions['edit any accept_invite salto invite'] = array(
    'name' => 'edit any accept_invite salto invite',
    'roles' => array(),
    'module' => 'salto_invite',
  );

  // Exported permission: 'flag notification_ignore_material'.
  $permissions['flag notification_ignore_material'] = array(
    'name' => 'flag notification_ignore_material',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag notification_ignore_post'.
  $permissions['flag notification_ignore_post'] = array(
    'name' => 'flag notification_ignore_post',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag notification_mark_as_read'.
  $permissions['flag notification_mark_as_read'] = array(
    'name' => 'flag notification_mark_as_read',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag notification_subscribe_material'.
  $permissions['flag notification_subscribe_material'] = array(
    'name' => 'flag notification_subscribe_material',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag notification_subscribe_node'.
  $permissions['flag notification_subscribe_node'] = array(
    'name' => 'flag notification_subscribe_node',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag notification_ignore_material'.
  $permissions['unflag notification_ignore_material'] = array(
    'name' => 'unflag notification_ignore_material',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag notification_ignore_post'.
  $permissions['unflag notification_ignore_post'] = array(
    'name' => 'unflag notification_ignore_post',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag notification_mark_as_read'.
  $permissions['unflag notification_mark_as_read'] = array(
    'name' => 'unflag notification_mark_as_read',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag notification_subscribe_material'.
  $permissions['unflag notification_subscribe_material'] = array(
    'name' => 'unflag notification_subscribe_material',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag notification_subscribe_node'.
  $permissions['unflag notification_subscribe_node'] = array(
    'name' => 'unflag notification_subscribe_node',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'view any accept_invite salto_invite'.
  $permissions['view any accept_invite salto_invite'] = array(
    'name' => 'view any accept_invite salto_invite',
    'roles' => array(),
    'module' => 'salto_invite',
  );

  // Exported permission: 'view any notifications'.
  $permissions['view any notifications'] = array(
    'name' => 'view any notifications',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'onsite_notification',
  );

  // Exported permission: 'view own notifications'.
  $permissions['view own notifications'] = array(
    'name' => 'view own notifications',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'onsite_notification',
  );

  return $permissions;
}
