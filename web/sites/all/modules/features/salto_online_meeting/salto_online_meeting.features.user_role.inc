<?php

/**
 * @file
 * salto_online_meeting.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function salto_online_meeting_user_default_roles() {
  $roles = array();

  // Exported role: Online-Treffen-Manager:in.
  $roles['Online-Treffen-Manager:in'] = array(
    'name' => 'Online-Treffen-Manager:in',
    'weight' => 9,
  );

  return $roles;
}
