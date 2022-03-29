<?php

/**
 * Form to create invites
 */
function salto_group_membership_add_form($form, &$form_state, $gid) {
  $group = entity_load_single('node', $gid);

  ctools_include('dependent');

  $form['#group'] = $group;

  $form['selector'] = [
    '#markup' => theme("og_invite_selector", ['group' => $group]),
  ];

  $form['accounts'] = [
    '#type' => 'hidden',
    '#title' => t('This should be the serialized string of all users to add'),
    '#default_value' => "[]",
  ];

  $form['invite'] = [
    '#type' => 'checkbox',
    '#title' => t('Custom invite message'),
    '#default_value' => FALSE,
    '#attributes' => ["id" => "edit-invite"],
  ];


  $form['invite_message'] = [
    '#type' => 'textarea',
    '#required' => FALSE,
    '#process' => ['ctools_dependent_process'],
    '#dependency' => ["edit-invite" => [1]],
    '#rows' => 20,
    '#description' => t('You can append a custom message to all invites. New users will additionally receive login informations.'),
  ];


  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Invite users'),
  ];
  return $form;
}
