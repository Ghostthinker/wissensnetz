<?php

/**
 * @file
 * Plugin to handle the 'profile2' content type which allows individual profiles
 * to be embedded into a panel.
 */


/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = [
  'single' => TRUE,
  'title' => t('Central Storage enabled is set?'),
  'description' => t('Has an organisation already set the central storage for its organisation'),
  'category' => t('Organisations'),
  'defaults' => ['type' => NULL],
];

/**
 * Render the user profile2 content type.
 */
function salto_organisation_central_storage_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;

  $group = salto_organisation_get_central_storage_first_unset_orgs_by_user($user->uid);

  drupal_set_message($group->title);

  $block = new stdClass();
  $block->title = t('Your Membership');

  $block->content = $out;

  return $block;
}

/**
 * Display the administrative title for a panel pane in the drag & drop UI.
 */
function salto_organisation_central_storage_content_type_admin_title($subtype, $conf, $context) {
  return t('Central Storage enabled is set?');
}
