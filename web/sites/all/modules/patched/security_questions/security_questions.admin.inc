<?php
/**
 * @file
 * Administrative UI for the security questions module.
 */

/**
 * Questions list page with add form.
 */
function security_questions_list_form($form, &$form_state) {
  $form = array();

  // Add a new global question.
  $form['add'] = array('#type' => 'container');
  $form['add']['question'] = array(
    '#title' => t('Add a question'),
    '#type' => 'textfield',
    '#description' => t('Enter the question text.'),
  );
  $form['add']['actions'] = array('#type' => 'actions');
  $form['add']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add'),
  );

  // List global questions.
  $form['list'] = array('#type' => 'container');
  $form['list'][] = array(
    '#prefix' => '<h3>',
    '#markup' => t('Global questions'),
    '#suffix' => '</h3>',
  );
  $form['list'][] = array(
    '#prefix' => '<p>',
    '#markup' => t('The questions shown below are available for use by all users. Optionally, users may also be allowed to create their own questions.'),
    '#suffix' => '</p>',
  );

  $rows = array();
  $questions = security_questions_question_load_multiple(array('uid' => 0));
  foreach ($questions as $question) {
    $rows[] = array(check_plain($question->question), check_plain($question->machine_name), l(t('delete'), 'admin/config/people/security_questions/questions/delete/' . $question->sqid));
  }
  $table = array(
    'header' => array(t('Question'), t('Machine name'), t('Operations')),
    'rows' => $rows,
    'empty' => t('No global questions available. Use the form above to create one.'),
  );

  // See if any other modules want to add anything to the table.
  drupal_alter('security_questions_list', $table);
  $output = theme('table', $table);
  $form['list'][] = array('#markup' => $output);

  return $form;
}

/**
 * Questions add form validation handler.
 */
function security_questions_list_form_validate($form, &$form_state) {
  $question = trim($form_state['values']['question']);
  if (empty($question)) {
    form_set_error('question', t('The question text must not be blank.'));
  }
}

/**
 * Questions add form submit handler.
 */
function security_questions_list_form_submit($form, &$form_state) {
  security_questions_add_question($form_state['values']['question']);
}

/**
 * Question delete form.
 *
 * @param $question
 *   A question object.
 */
function security_questions_delete_question_form($form, &$form_state, $question) {
  $count = db_select('security_questions_answers', 'a')
    ->condition('sqid', $question->sqid)
    ->countQuery()
    ->execute()
    ->fetchField();
  $tokens = array('%question' => $question->question);

  $form['sqid'] = array('#type' => 'hidden', '#value' => $question->sqid);
  $form['question'] = array('#type' => 'value', '#value' => $question->question);
  $confirm = t('Are you sure you want to delete %question from the global security questions list?', $tokens);
  $path = 'admin/config/people/security_questions';
  $description = format_plural($count,
    '%question is currently being used by 1 user.',
    '%question is currently being used by @count users.',
    $tokens);

  return confirm_form($form, $confirm, $path, $description, t('Delete'));
}

/**
 * Question delete form submission handler.
 */
function security_questions_delete_question_form_submit($form, &$form_state) {
  security_questions_question_delete($form_state['values']['sqid']);

  $form_state['redirect'] = 'admin/config/people/security_questions';
  drupal_set_message(t('The security question %question has been deleted.', array('%question' => $form_state['values']['question'])));
}

/**
 * Security questions module settings form.
 */
function security_questions_settings_form($form, &$form_state) {
  // Configure the number and type of questions.
  $form['security_questions_number_required'] = array(
    '#title' => t('Required number of questions'),
    '#description' => t('The number of questions that users are required to have answered on their accounts.'),
    '#type' => 'select',
    '#default_value' => variable_get('security_questions_number_required', 3),
    '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)),
  );
  $form['security_questions_user_questions'] = array(
    '#title' => t('User-defined questions'),
    '#description' => t('Allow users to create their own questions to answer.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('security_questions_user_questions', FALSE),
  );

  // Configure question challenges.
  $form['challenges'] = array(
    '#title' => t('Protected forms'),
    '#description' => t('Users will be required to answer a security question when submitting one of the forms selected below.'),
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
  );
  $form['challenges']['security_questions_password_reset'] = array(
    '#title' => t('Password reset request'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('security_questions_password_reset', FALSE),
  );
  $form['challenges']['security_questions_user_login'] = array(
    '#title' => t('User login'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('security_questions_user_login', FALSE),
  );
  $form['challenges']['security_questions_protection_mode'] = array(
    '#title' => t('When should the question challenge occur during login?'),
    '#description' => t("Note that if the question is asked before the password, malicious people may be able to guess a user's answer through social engineering, just by knowing the user's username."),
    '#type' => 'radios',
    '#default_value' => variable_get('security_questions_protection_mode', 'after'),
    '#options' => array(
      'after' => t('After entering both the username and the password'),
      'before' => t('After entering the username, but before the password'),
    ),
    '#states' => array(
      'visible' => array(
        ':input[name="security_questions_user_login"]' => array('checked' => TRUE),
      ),
    ),
  );
  $form['challenges']['security_questions_cookie'] = array(
    '#title' => t('Show "remember this computer" option on protected forms'),
    '#description' => t('If enabled, users will have the option to disable future question challenges for actions performed from the same computer.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('security_questions_cookie', FALSE),
  );
  $form['challenges']['security_questions_cookie_expire'] = array(
    '#title' => t('Cookies expire after'),
    '#description' => t('Controls how long a user is allowed to bypass question challenges after selecting the "remember this computer" option.'),
    '#type' => 'select',
    '#default_value' => variable_get('security_questions_cookie_expire', 604800),
    '#options' => array(0 => t('Never')) + drupal_map_assoc(array(86400, 172800, 259200, 432000, 604800, 1209600, 2419200, 7776000), 'format_interval'),
    '#states' => array(
      'visible' => array(
        ':input[name="security_questions_cookie"]' => array('checked' => TRUE),
      ),
    ),
  );

  // Configure flood control.
  $form['flood'] = array(
    '#title' => t('Flood control'),
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
  );
  $form['flood']['security_questions_flood_expire'] = array(
    '#title' => t('After giving an incorrect answer, for how long should a visitor be blocked from attempting that same question again?'),
    '#description' => t("When a question is answered incorrectly, the visitor's IP address will be logged in the database, along with the question that was asked and the ID of the user account to which the visitor was trying to authenticate.  The logged question will not be shown again to that IP for that user account until either the timeout period set here expires or the visitor answers a question correctly for that user account.  If the visitor answers all of the user's questions incorrectly, access as that user will be denied to that IP for anything protected by security questions until the timeout expires for one or more questions."),
    '#type' => 'select',
    '#default_value' => variable_get('security_questions_flood_expire', 3600),
    '#options' => array(0 => t('No delay')) + drupal_map_assoc(array(60, 300, 900, 1800, 3600, 10800, 21600, 43200, 86400, 604800), 'format_interval'),
  );

  return system_settings_form($form);
}
