<?php

/**
 * @file
 * salto_online_meeting.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function salto_online_meeting_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create online_meeting content'.
  $permissions['create online_meeting content'] = array(
    'name' => 'create online_meeting content',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
      'Online-Treffen-Manager:in' => 'Online-Treffen-Manager:in',
      'Support' => 'Support',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any online_meeting content'.
  $permissions['delete any online_meeting content'] = array(
    'name' => 'delete any online_meeting content',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
      'Online-Treffen-Manager:in' => 'Online-Treffen-Manager:in',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own online_meeting content'.
  $permissions['delete own online_meeting content'] = array(
    'name' => 'delete own online_meeting content',
    'roles' => array(
      'Online-Treffen-Manager:in' => 'Online-Treffen-Manager:in',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any online_meeting content'.
  $permissions['edit any online_meeting content'] = array(
    'name' => 'edit any online_meeting content',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
      'Online-Treffen-Manager:in' => 'Online-Treffen-Manager:in',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own online_meeting content'.
  $permissions['edit own online_meeting content'] = array(
    'name' => 'edit own online_meeting content',
    'roles' => array(
      'Online-Treffen-Manager:in' => 'Online-Treffen-Manager:in',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
