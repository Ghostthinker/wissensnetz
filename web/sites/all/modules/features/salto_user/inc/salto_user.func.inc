<?php

/**
 * @file functions and helper for salro_users
 */

/**
 * Get an array with organisation an responsibility of a user
 *
 * @param  [type] $uid [description]
 *
 * @return [type]      [description]
 */
function salto_user_get_organisations_by_user($uid, $limit_og = 1) {
  $account = user_load($uid);
  global $user;

  if (empty($account->field_user_organisations)) {
    return;
  }

  if (salto_user_is_in_fallback_organisation($account)) {
    return;
  }

  $memberships = [];
  $out = "";
  $c = 0;
  foreach ($account->field_user_organisations[LANGUAGE_NONE] as $org) {
    if ($c++ >= $limit_og) {
      break;
    }
    $gid = $org['target_id'];
    $membership = og_get_membership('node', $gid, 'user', $account->uid);
    $group = node_load($gid);

    $org = l($group->title, 'node/' . $group->nid);

    if (!empty($membership->field_organisation_position[LANGUAGE_NONE][0]['tid'])) {
      $term = taxonomy_term_load($membership->field_organisation_position[LANGUAGE_NONE][0]['tid']);

      $org_string = salto_core_strip_input($term->name) . ', ' . $org;
    }
    else {

      if ($user->uid == $account->uid) { //} || og_user_access('node', $gid, 'manage membership fields')) {
        $membership_link = salto_organisation_edit_membership_link($gid, $membership);
        $org_string = $org . " <small>(" . drupal_render($membership_link) . ")</small>";
      }
      else {
        $org_string = $org;
      }

    }
    $out .= '<div class="responsibility-organisation">' . $org_string . '</div>';
  }
  return $out;
}

/**
 * Context links used on the people overview
 *
 * @return [type] [description]
 */
function salto_user_profile_action_links() {

  $account = menu_get_object('user');
  $links = [];

  //devel switch
  if (user_access('switch users')) {
    $dest = drupal_get_destination();
    $path = 'devel/switch/' . $account->name;
    $link = [
      '#theme' => 'link',
      '#text' => t('Impersonate'),
      '#path' => $path,
      '#options' => [
        'query' => $dest + ['token' => drupal_get_token($path . '|' . $dest['destination'])],
        'attributes' => [
          'title' => t('This user can switch back.'),
          'class' => 'action_link switch_user',
        ],
        'html' => TRUE,
      ],
    ];
    $links["devel_switch"] = $link;
  }
  //edit profile && account
  if (user_edit_access($account)) {
    $dest = drupal_get_destination();
    $path = 'user/' . $account->uid . '/edit/main';
    $link = [
      '#theme' => 'link',
      '#text' => t('Edit Profile'),
      '#path' => $path,
      '#options' => [
        'query' => $dest,
        'attributes' => [
          'title' => t('Edit profile details.'),
          'class' => 'action_link edit_user edit_user_profile',
        ],
        'html' => TRUE,
      ],
    ];
    $links["edit_profile"] = $link;

    $dest = drupal_get_destination();
    $path = 'user/' . $account->uid . '/edit';
    $link = [
      '#theme' => 'link',
      '#text' => t('Edit Account'),
      '#path' => $path,
      '#options' => [
        'query' => $dest,
        'attributes' => [
          'title' => t('Edit profile details.'),
          'class' => 'action_link edit_user edit_user_account',
        ],
        'html' => TRUE,
      ],
    ];
    $links["edit_account"] = $link;
  }

  $menu_object = [
    'type' => 'list',
    'items' => $links,
  ];
  salto_core_context_links("knowledgebase", $menu_object);
}

/**
 * redirect user to its own profile link when uid is missing
 *
 * @param  [type] $type [description]
 *
 * @return [type]       [description]
 */
function salto_user_redirect_user_edit($type) {
  global $user;

  if ($type == "profile") {
    drupal_goto('user/' . $user->uid . '/edit/main');
  }

  if ($type == "account") {
    drupal_goto('user/' . $user->uid . '/edit');
  }
}

/**
 * Admin form callback for numeric count constraint.
 *
 * @param $password
 *
 * @return bool
 */
function _salto_user_digits_count_constraint($password) {
  $matches = [];
  $count = preg_match_all('/[[:digit:]]/', $password, $matches);

  return $count >= SALTO_USER_PASSWORD_MIN_DIGITS;
}

/**
 * Admin form callback for numeric count constraint.
 */
function _salto_user_characters_count_constraint($password) {
  return drupal_strlen($password) >= SALTO_USER_PASSWORD_MIN_LENGTH;
}

/**
 * Admin form callback for numeric count constraint.
 *
 * @param $password
 *
 * @return bool
 */
function _salto_user_punctuation_count_constraint($password) {
  $matches = [];
  $count = preg_match_all('/[[:punct:]]/', $password, $matches);
  return $count >= SALTO_USER_PASSWORD_MIN_PUNCTUATION;
}

/**
 * Admin form callback for numeric count constraint.
 *
 * @param $password
 *
 * @return bool
 */
function _salto_user_lowercase_count_constraint($password) {
  $matches = [];
  $count = preg_match_all('/[[:lower:]]/', $password, $matches);
  return $count >= SALTO_USER_PASSWORD_MIN_LOWERCASE;
}

/**
 * Admin form callback for numeric count constraint.
 *
 * @param $password
 *
 * @return bool
 */
function _salto_user_uppercase_count_constraint($password) {
  $matches = [];
  $count = preg_match_all('/[[:upper:]]/', $password, $matches);
  return $count >= SALTO_USER_PASSWORD_MIN_UPPERCASE;
}

/**
 * AJAX callback to check password against applicable policies.
 */
function salto_user_password_ajax_check() {
  // Sanitize password input.
  $password = check_plain(urldecode($_POST['password']));

  $total = 0;
  $errors = [];


  $constraints = salto_user_password_constraints_info();

  // Exit prematurely if no policies are usable.
  if (count($constraints) == 0) {
    return;
  }

  $total = 0;
  $errors = [];
  foreach ($constraints as $constraint) {
    $total++;
    if (function_exists($constraint['constraint_callback']) && !call_user_func($constraint['constraint_callback'], $password)) {
      $errors[] = $constraint['error'];
    }
  }

  $sus_count = $total - count($errors);

  $score = ($sus_count / $total) * 100;
  $msg = '';

  if (!empty($errors)) {
    $msg .= t('Password does not match the following requirements:');
    $msg .= theme('item_list', ['items' => $errors]);
  }

  $return = [
    'message' => $msg,
    'strength' => $score,
    'indicatorText' => "$sus_count of $total",
  ];

  drupal_json_output($return);
}

/**
 * Make the "My Account" dynamic to the users realname
 *
 * @param  [type] $account [description]
 *
 * @return [type]          [description]
 */
function _salto_user_menu_title($account = NULL) {
  global $user;

  if (!empty($user)) {
    return format_username($user);
  }
  return user_menu_title();
}

function _salto_user_password_constraint_validate($password) {

  $errors = [];

  $constraints = salto_user_password_constraints_info();

  // Exit prematurely if no policies are usable.
  if (count($constraints) == 0) {
    return;
  }

  foreach ($constraints as $constraint) {
    if (function_exists($constraint['constraint_callback']) && !call_user_func($constraint['constraint_callback'], $password)) {
      $errors[] = $constraint['error'];
    }
  }

  if (!empty($errors)) {
    form_set_error('pass', theme('item_list', ['items' => $errors]));
  }
}

/**
 * Validate wrapper for security questions
 *
 * @param  [type] $form       [description]
 * @param  [type] $form_state [description]
 *
 * @return [type]             [description]
 */
function salto_user_edit_account_security_validate($form, &$form_state) {
  module_load_include('inc', 'security_questions', 'security_questions.pages');
  security_questions_user_form_validate($form, $form_state);
}

/**
 * submit wrapper for security questions
 *
 * @param  [type] $form       [description]
 * @param  [type] $form_state [description]
 *
 * @return [type]             [description]
 */
function salto_user_edit_account_security_submit($form, &$form_state) {
  $account = $form['#user'];

  if (!empty($form_state['values']['questions'][0]['answer']) && !empty($account)) {
    module_load_include('inc', 'security_questions', 'security_questions.pages');
    security_questions_user_answers_save($account, $form_state['values']['questions']);
  }
  elseif (!empty($account)) {

    salto_user_security_questions_answer_delete($account->uid);
  }
}

/**
 * Validate a mail address
 *
 * @param string $mail The mail to validate
 *
 * @return array        empty array or an an array with errors
 */
function salto_user_validate_mail($mail) {

  $errors = [];
  if (!valid_email_address($mail) && strlen($data['mail']) == 0) {
    $errors['mail_valid'] = t('E-mail addresses is invalid!');
  }

  if (valid_email_address($mail) && $account = user_load_by_mail($mail)) {
    $errors['mail_unique'] = t('The addresse  %mail is already used.', ['%mail' => $mail]);
  }
  return $errors;
}

/**
 * @param $json
 *
 * @return mixed
 */
function salto_user_membership_request_get_og_title($json) {
  $data = unserialize($json);
  $og = node_load($data['organisation']);
  return $og->title;
}
