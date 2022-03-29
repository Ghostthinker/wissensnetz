<?php

/**
 * @file
 * Plugin to provide access control based upon role membership.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Salto OG: Has og accept invite"),
  'description' => t('Control access if a user has an invite.'),
  'callback' => 'salto_og_has_invite_ctools_access_check',
  'default' => array('rids' => array()),
  'settings form' => 'salto_og_has_invite_ctools_access_settings',
  'settings form submit' => 'salto_og_has_invite_ctools_access_settings_submit',
  'summary' => 'salto_og_has_invite_ctools_access_summary',
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
    new ctools_context_required(t('User'), 'entity:user'),
  )
);

/**
 * Settings form for the 'by role' access plugin
 */
function salto_og_has_invite_ctools_access_settings($form, &$form_state, $conf) {
  $form['settings']['salto_invite_type'] = array(
    '#type' => 'select',
    '#title' => t('Salto Invete Type'),
    '#default_value' => $conf['salto_invite_type'],
    '#options' => salto_invite_types_get_options(),
  );
  return $form;
}

/**
 * Compress the roles allowed to the minimum.
 */
function salto_og_has_invite_ctools_access_settings_submit($form, &$form_state) {
  //$form_state['values']['settings']['salto_invite_type'] = array_keys(array_filter($form_state['values']['settings']['salto_invite_type']);
}

/**
 * Check for access.
 */
function salto_og_has_invite_ctools_access_check($conf, $context) {
  // As far as I know there should always be a context at this point, but this
  // is safe.
  if (empty($context) || empty($context[0]->data) || !isset($context[0]->data->nid)) {
    return FALSE;
  }

  $node = $context[0]->data;
  $account = $context[1]->data;

  return salto_og_has_invite($node->nid, $account->gid);
}

/**
 * Provide a summary description based upon the checked roles.
 */
function salto_og_has_invite_ctools_access_summary($conf, $context) {
  if (!isset($conf['salto_invite_type'])) {
    return "??";
  }

  $types = salto_invite_types_get_options();

  return t("has an !type salto invite type", array('!type' => $types[$conf['salto_invite_type']]));

}
