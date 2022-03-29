<?php

/**
 * @file
 * salto_files.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function salto_files_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer background process'.
  $permissions['administer background process'] = array(
    'name' => 'administer background process',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'background_process',
  );

  // Exported permission: 'administer media_derivatives'.
  $permissions['administer media_derivatives'] = array(
    'name' => 'administer media_derivatives',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'media_derivatives',
  );

  // Exported permission: 'administer media_derivatives presets'.
  $permissions['administer media_derivatives presets'] = array(
    'name' => 'administer media_derivatives presets',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'media_derivatives_ui',
  );

  // Exported permission: 'administer media_derivatives_ffmpeg'.
  $permissions['administer media_derivatives_ffmpeg'] = array(
    'name' => 'administer media_derivatives_ffmpeg',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'media_derivatives_ffmpeg',
  );

  // Exported permission: 'create swf files'.
  $permissions['create swf files'] = array(
    'name' => 'create swf files',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
    ),
    'module' => 'salto_files',
  );

  // Exported permission: 'delete any swf files'.
  $permissions['delete any swf files'] = array(
    'name' => 'delete any swf files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any webresource files'.
  $permissions['delete any webresource files'] = array(
    'name' => 'delete any webresource files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own swf files'.
  $permissions['delete own swf files'] = array(
    'name' => 'delete own swf files',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own webresource files'.
  $permissions['delete own webresource files'] = array(
    'name' => 'delete own webresource files',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any swf files'.
  $permissions['download any swf files'] = array(
    'name' => 'download any swf files',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any webresource files'.
  $permissions['download any webresource files'] = array(
    'name' => 'download any webresource files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own swf files'.
  $permissions['download own swf files'] = array(
    'name' => 'download own swf files',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own webresource files'.
  $permissions['download own webresource files'] = array(
    'name' => 'download own webresource files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any swf files'.
  $permissions['edit any swf files'] = array(
    'name' => 'edit any swf files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any webresource files'.
  $permissions['edit any webresource files'] = array(
    'name' => 'edit any webresource files',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own swf files'.
  $permissions['edit own swf files'] = array(
    'name' => 'edit own swf files',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own webresource files'.
  $permissions['edit own webresource files'] = array(
    'name' => 'edit own webresource files',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  return $permissions;
}
