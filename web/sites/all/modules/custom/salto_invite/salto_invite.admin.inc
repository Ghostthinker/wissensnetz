<?php

/**
 * @file
 * SaltoInvite editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring
 *   instead to use views. That offers more flexibility to change a UI that
 *   will, more often than not, be end-user facing.
 */

/**
 * UI controller.
 */
class SaltoInviteUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {

    $items = [];
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = [
      'title' => 'Salto Invite',
      'description' => 'Add edit and update salto_invite.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => ['access administration pages'],
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    ];

    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    $items[$this->path . '/add'] = [
      'title' => 'Add a salto invite',
      'description' => 'Add a new salto_invite',
      'page callback' => 'salto_invite_add_page',
      'access callback' => 'salto_invite_access',
      'access arguments' => ['edit'],
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'salto_invite.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),

    ];

    foreach (salto_invite_get_types() as $type) {
      $items[$this->path . '/add/' . $type->type] = [
        'title' => 'Add ' . $type->label,
        'page callback' => 'salto_invite_form_wrapper',
        'page arguments' => [salto_invite_create(['type' => $type->type])],
        'access callback' => 'salto_invite_access',
        'access arguments' => ['edit', 'edit ' . $type->type],
        'file' => 'salto_invite.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module']),
      ];
    }

    $items[$this->path . '/salto_invite/' . $wildcard] = [
      'page callback' => 'salto_invite_form_wrapper',
      'page arguments' => [$id_count + 1],
      'access callback' => 'salto_invite_access',
      'access arguments' => ['edit', $id_count + 1],
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'salto_invite.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    ];
    $items[$this->path . '/salto_invite/' . $wildcard . '/edit'] = [
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    ];

    $items[$this->path . '/salto_invite/' . $wildcard . '/delete'] = [
      'title' => 'Delete',
      'page callback' => 'salto_invite_delete_form_wrapper',
      'page arguments' => [$id_count + 1],
      'access callback' => 'salto_invite_access',
      'access arguments' => ['edit', $id_count + 1],
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'salto_invite.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module']),
    ];

    $items['salto_invite/' . $wildcard] = [
      //'title' => 'Title',
      'title callback' => 'salto_invite_page_title',
      'title arguments' => [1],
      'page callback' => 'salto_invite_page_view',
      'page arguments' => [1],
      'access callback' => 'salto_invite_access',
      'access arguments' => ['view', 1],
      'type' => MENU_CALLBACK,
    ];
    return $items;
  }

  /**
   * Create the markup for the add SaltoInvite Entities page within the class
   * so it can easily be extended/overriden.
   */
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }
    return theme('salto_invite_add_list', ['content' => $content]);
  }

}

/**
 * Form callback wrapper: create or edit a salto_invite.
 *
 * @param $salto_invite
 *   The salto_invite object being edited by this form.
 *
 * @see salto_invite_edit_form()
 */
function salto_invite_form_wrapper($salto_invite) {
  salto_invite_set_breadcrumb();
  return drupal_get_form('salto_invite_edit_form', $salto_invite);
}

/**
 * Form callback wrapper: delete a salto_invite.
 *
 * @param $salto_invite
 *   The salto_invite object being edited by this form.
 *
 * @see salto_invite_edit_form()
 */
function salto_invite_delete_form_wrapper($salto_invite) {
  return drupal_get_form('salto_invite_delete_form', $salto_invite);
}

/**
 * Form callback: create or edit a salto_invite.
 *
 * @param $salto_invite
 *   The salto_invite object to edit or for a create form an empty salto_invite
 *   object with only a salto_invite type defined.
 */
function salto_invite_edit_form($form, &$form_state, $salto_invite) {
  // Add the default field elements.
  $form['code'] = [
    '#type' => 'textfield',
    '#title' => t('Salto Invite Code'),
    '#default_value' => isset($salto_invite->code) ? $salto_invite->code : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  ];

  $form['data']['#tree'] = TRUE;
  $form['data']['sample_data'] = [
    '#type' => 'checkbox',
    '#title' => t('This is just a dummy'),
    '#default_value' => isset($salto_invite->data['sample_data']) ? $salto_invite->data['sample_data'] : 1,
  ];

  // Add the field related form elements.
  $form_state['salto_invite'] = $salto_invite;
  field_attach_form('salto_invite', $salto_invite, $form, $form_state);

  $form['actions'] = [
    '#type' => 'container',
    '#attributes' => ['class' => ['form-actions']],
    '#weight' => 400,
  ];

  $submit = [];

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t('Save salto_invite'),
    '#submit' => $submit + ['salto_invite_edit_form_submit'],
  ];

  if (!empty($salto_invite->code)) {
    $form['actions']['delete'] = [
      '#type' => 'submit',
      '#value' => t('Delete salto_invite'),
      '#suffix' => l(t('Cancel'), 'admin/content/salto_invites'),
      '#submit' => $submit + ['salto_invite_form_submit_delete'],
      '#weight' => 45,
    ];
  }

  $form['#validate'][] = 'salto_invite_edit_form_validate';
  return $form;
}

/**
 * Form API validate callback for the salto_invite form
 */
function salto_invite_edit_form_validate(&$form, &$form_state) {
  $salto_invite = $form_state['salto_invite'];

  field_attach_form_validate('salto_invite', $salto_invite, $form, $form_state);
}

/**
 * Form API submit callback for the salto_invite form.
 *
 */
function salto_invite_edit_form_submit(&$form, &$form_state) {

  $salto_invite = entity_ui_controller('salto_invite')->entityFormSubmitBuildEntity($form, $form_state);

  if ($salto_invite->is_new = isset($salto_invite->is_new) ? $salto_invite->is_new : 0) {
    $salto_invite->created = time();
  }

  $salto_invite->changed = time();

  $salto_invite->save();
  $form_state['redirect'] = 'admin/content/salto_invites';
}

/**
 * Form API submit callback for the delete button.
 *
 */
function salto_invite_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/salto_invites/salto_invite/' . $form_state['salto_invite']->salto_invite_id . '/delete';
}

/**
 * Form callback: confirmation form for deleting a salto_invite.
 *
 * @param $salto_invite
 *   The salto_invite to delete
 *
 * @see confirm_form()
 */
function salto_invite_delete_form($form, &$form_state, $salto_invite) {
  $form_state['salto_invite'] = $salto_invite;

  $form['#submit'][] = 'salto_invite_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete salto_invite %name?', ['%name' => $salto_invite->code]),
    'admin/content/salto_invites/salto_invite',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for salto_invite_delete_form
 */
function salto_invite_delete_form_submit($form, &$form_state) {
  $salto_invite = $form_state['salto_invite'];

  salto_invite_delete($salto_invite);

  drupal_set_message(t('The salto_invite %name has been deleted.', ['%name' => $salto_invite->code]));
  watchdog('salto_invite', 'Deleted salto_invite %name.', ['%name' => $salto_invite->code]);

  $form_state['redirect'] = 'admin/content/salto_invites';
}

/**
 * Page to add SaltoInvite Entities.
 *
 */
function salto_invite_add_page() {
  $controller = entity_ui_controller('salto_invite');
  return $controller->addPage();
}

/**
 * Displays the list of available salto_invite types for salto_invite creation.
 *
 * @ingroup themeable
 */
function theme_salto_invite_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="salto-invite-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer salto invite types')) {
      $output = '<p>' . t('Salto Invite Entities cannot be added because you have not created any salto_invite types yet. Go to the <a href="@create-salto_invite-type">salto_invite type creation page</a> to add a new salto_invite type.', ['@create-salto_invite-type' => url('admin/structure/salto_invite_types/add')]) . '</p>';
    }
    else {
      $output = '<p>' . t('No salto_invite types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Sets the breadcrumb for administrative salto_invite pages.
 */
function salto_invite_set_breadcrumb() {
  $breadcrumb = [
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Salto Invites'), 'admin/content/salto_invites'),
  ];
  drupal_set_breadcrumb($breadcrumb);
}



