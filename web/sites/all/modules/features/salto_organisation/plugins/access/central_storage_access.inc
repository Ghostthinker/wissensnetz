<?php

/**
 * @file
 * Plugin to provide access control based on drupal_is_front_page.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = [
  'title' => t('Organisation: Central storage'),
  'description' => t('Central storage settings are made'),
  'callback' => 'salto_organisation_central_storage_access_ctools_access_check',
  'default' => ['negate' => 0],
  'summary' => 'salto_organisation_central_storage_access_ctools_access_summary',
  'required context' => [
    new ctools_context_required(t('User'), 'user'),
  ],
];

/**
 * Check for access.
 */
function salto_organisation_central_storage_access_ctools_access_check($conf, $context) {

  $account = isset($context[0]->data->uid) ? clone($context[0]->data) : NULL;

  if (empty($account->uid)) {
    return FALSE;
  }

  $group = salto_organisation_get_central_storage_first_unset_orgs_by_user($account->uid);

  if ($group) {
    $message = t('There are still organisations that have not decided wheter touse central storage or not. Please set it for !org_link.', ["!org_link" => l($group->title, 'node/' . $group->nid . '/edit', ['fragment' => 'field_organisation_obscure_anchor'])]);
    drupal_set_message($message, "warning");
    return FALSE;
  }


  return TRUE;

}

/**
 * Provide a summary description based upon the checked terms.
 */
function salto_organisation_central_storage_access_ctools_access_summary($conf, $context) {
  return t('User account legal has been accepted');
}
