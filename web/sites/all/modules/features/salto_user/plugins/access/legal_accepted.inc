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
  'title' => t('Salto user: legal Accepted'),
  'description' => t('User has accepted terms & conditions'),
  'callback' => 'salto_user_legal_accepted_ctools_access_check',
  'default' => ['negate' => 0],
  'settings form' => 'salto_user_legal_accepted_ctools_access_settings',
  'summary' => 'salto_user_legal_accepted_ctools_access_summary',
  'required context' => [
    new ctools_context_required(t('User'), 'user'),
  ],
];

/**
 * Settings form for the 'by parent term' access plugin
 */
function salto_user_legal_accepted_ctools_access_settings($form, &$form_state, $conf) {
  // No additional configuration necessary.
  return $form;
}

/**
 * Check for access.
 */
function salto_user_legal_accepted_ctools_access_check($conf, $context) {

  $account = isset($context[0]->data->uid) ? clone($context[0]->data) : NULL;

  if (empty($account->uid)) {
    return FALSE;
  }

  $accepted = FALSE;

  // Get last accepted version for this account
  $legal_account = legal_get_accept($account->uid);

  // If no version has been accepted yet, get version with current language revision.

  if (!empty($legal_account['version'])) {
    $conditions = legal_get_conditions($legal_account['language']);
    // No conditions set yet.
    if (empty($conditions['conditions'])) {

      return $accepted;
    }
    // Check latest version of T&C has been accepted.
    $accepted = legal_version_check($account->uid, $conditions['version'], $conditions['revision'], $legal_account);
  }
  return $accepted;

}

/**
 * Provide a summary description based upon the checked terms.
 */
function salto_user_legal_accepted_ctools_access_summary($conf, $context) {
  return t('User account legal has been accepted');
}
