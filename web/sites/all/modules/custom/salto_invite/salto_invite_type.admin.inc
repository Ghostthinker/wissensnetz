<?php

/**
 * @file
 * Model type editing UI.
 */

/**
 * UI controller.
 */
class SaltoInviteTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage salto_invite entity types, including adding
		and removing fields and the display of fields.';
    return $items;
  }

}

/**
 * Generates the salto_invite type editing form.
 */
function salto_invite_type_form($form, &$form_state, $salto_invite_type, $op = 'edit') {

  if ($op == 'clone') {
    $salto_invite_type->label .= ' (cloned)';
    $salto_invite_type->type = '';
  }

  $form['label'] = [
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $salto_invite_type->label,
    '#description' => t('The human-readable name of this salto_invite type.'),
    '#required' => TRUE,
    '#size' => 30,
  ];
  // Machine-readable type name.
  $form['type'] = [
    '#type' => 'machine_name',
    '#default_value' => isset($salto_invite_type->type) ? $salto_invite_type->type : '',
    '#maxlength' => 32,
    '#machine_name' => [
      'exists' => 'salto_invite_get_types',
      'source' => ['label'],
    ],
    '#description' => t('A unique machine-readable name for this salto_invite type. It must only contain lowercase letters, numbers, and underscores.'),
  ];

  $form['data']['#tree'] = TRUE;
  $form['data']['sample_data'] = [
    '#type' => 'checkbox',
    '#title' => t('An interesting salto_invite switch'),
    '#default_value' => !empty($salto_invite_type->data['sample_data']),
  ];

  $form['actions'] = ['#type' => 'actions'];
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save salto_invite type'),
    '#weight' => 40,
  ];

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function salto_invite_type_form_submit(&$form, &$form_state) {
  $salto_invite_type = entity_ui_form_submit_build_entity($form, $form_state);
  $salto_invite_type->save();
  $form_state['redirect'] = 'admin/structure/salto_invite_types';
}

/**
 * Form API submit callback for the delete button.
 */
function salto_invite_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/salto_invite_types/manage/' . $form_state['salto_invite_type']->type . '/delete';
}
