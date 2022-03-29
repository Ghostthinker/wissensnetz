<?php

/**
 *Implements hook_privatemsg_view_alter
 */
function salto_core_privatemsg_view_alter(&$content) {

  $content['reply']['#attributes']['class'][] = "col-md-10 col-md-offset-2";
}

/**
 * Define the message column.
 *
 * @see theme_privatemsg_list_header()
 */
function salto2014_privatemsg_list_header__participants() {
  return [
    'data' => t('Participants'),
    'class' => ['privatemsg-header-participants'],
    '#weight' => -60,
  ];
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 * @param $form_state
 */
function salto_core_form_privatemsg_admin_settings_alter(&$form, $form_state) {
  $form['privatemsg_listing']['privatemsg_display_fields']['#options']['message'] = t('Message');
}

/**
 * Implements hook_query_privatemsg_list_alter().
 *
 * @param QueryAlterableInterface $query
 */
function salto_core_query_privatemsg_list_alter(QueryAlterableInterface $query) {
  $fields = array_filter(variable_get('privatemsg_display_fields', ['participants']));
  if (in_array('message', $fields)) {
    global $user;
    $query->addExpression("(SELECT pm.body
                      FROM {pm_message} pm
                      INNER JOIN {pm_index} pmx on pm.mid=pmx.mid
                      WHERE
                        pmx.thread_id = pmi.thread_id
                        AND pmx.mid > pmi.thread_id
                        AND pmx.recipient = :uid
                      ORDER BY pmx.mid DESC LIMIT 0, 1)", 'message', [':uid' => $user->uid]);
    $query->orderByHeader(_privatemsg_list_headers(array_merge([
      'subject',
      'message',
      'last_updated',
    ], $fields)));
  }
}

/**
 * Define the message column.
 *
 * @see theme_privatemsg_list_header()
 */
function salto2014_privatemsg_list_header__message() {
  return [
    'data' => t('Message'),
    'field' => 'message',
    'class' => ['privatemsg-header-message'],
    '#weight' => -35,
  ];
}

/**
 * Theme the message field.
 *
 * @param $variables
 *
 * @return array
 * @see theme_privatemsg_list_field()
 */
function salto2014_privatemsg_list_field__message($variables) {
  $thread = $variables['thread'];
  // Getting the latest message for the current user.
  $result = $thread['message'];
  $field = [];
  $field['data'] = empty($result) ? '' : substr($result, 0, 100) . '...';
  $field['class'][] = 'privatemsg-list-message';
  return $field;
}

/**
 * Theme the last updated column.
 *
 * @param $variables
 *
 * @return mixed
 * @see theme_privatemsg_list_field()
 */
function salto2014_privatemsg_list_field__last_updated($variables) {
  $thread = $variables['thread'];
  $field['data'] = format_date($thread['last_updated']);
  $field['class'][] = 'privatemsg-list-date';
  return $field;
}

function salto_core_preprocess_page_toolbar_alter(&$variables) {
  if (stripos(current_path(), 'messages') === FALSE) {
    return;
  }
  if (stripos(current_path(), 'view') !== FALSE) {
    return;
  }

  $variables['toolbar']['title'] = drupal_get_title();
  if (stripos(current_path(), 'new') !== FALSE) {
    $variables['toolbar']['back'] = '/messages';
  }
}

function salto_core_preprocess_page_floating_button_alter(&$variables) {
  if (current_path() !== 'messages') {
    return;
  }

  $variables['floating_button']['links'][] = [
    'icon' => 'envelope',
    'target' => '/messages/new?al',
    'title' => t('New message'),
  ];
}
