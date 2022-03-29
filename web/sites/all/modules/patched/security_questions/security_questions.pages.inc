<?php
/**
 * @file
 * User page callbacks for the security questions module.
 */

/**
 * Helper function to generate a question selector and answer form element.
 *
 * @param $parent_name
 *   The name of the parent form element, used for the custom question field's
 *   '#states' property.
 * @param $account
 *   (optional) The user whose questions/answers are being chosen.
 * @param $answer
 *   (optional) An answer object to use as the default value.
 *
 * @return
 *   A form element array.
 */
function security_questions_selector_element($parent_name, $account = NULL, $answer = NULL) {
  $form['question'] = array(
    '#type' => 'select',
    '#title' => t('Security question'),
    '#required' => TRUE,
    '#options' => security_questions_get_question_list($account),
    '#default_value' => isset($answer) ? $answer->sqid : NULL,
  );
  if (variable_get('security_questions_user_questions', FALSE)) {
    $form['question']['#options']['other'] = t('- CUSTOM - Enter your own question');
    $form['custom_question'] = array(
      '#type' => 'textfield',
      '#title' => t('Custom question'),
      '#states' => array(
        'visible' => array(
          ':input[name="' . $parent_name . '[question]"]' => array('value' => 'other'),
        ),
      ),
    );
  }
  $form['answer'] = array(
    '#type' => 'textfield',
    '#title' => t('Answer'),
    '#required' => TRUE,
    '#default_value' => isset($answer) ? $answer->answer : '',
  );
  return $form;
}

/**
 * The user's security questions form.
 *
 * @param $account
 *   (optional) A user account object.
 */
function security_questions_user_form($form, &$form_state, $account = NULL) {
  $form['questions'] = array('#tree' => TRUE);
  $i = 0;

  if (isset($account)) {
    $form['account'] = array('#type' => 'value', '#value' => $account);
    // Fields for changing existing answers.
    $answers = security_questions_get_answer_list($account->uid);
    foreach ($answers as $answer) {
      $form['questions'][$i] = security_questions_selector_element('questions[' . $i . ']', $account, $answer);
      $i++;
    }
  }

  // Fields for selecting new answers.
  $required = variable_get('security_questions_number_required', 3);
  while ($i < $required) {
    $form['questions'][$i] = security_questions_selector_element('questions[' . $i . ']', $account);
    $i++;
  }

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Validation handler for the user's security questions form.
 */
function security_questions_user_form_validate($form, &$form_state) {
  $chosen = array();
  foreach ($form_state['values']['questions'] as $i => $question) {
    $chosen[$i] = $question['question'];

    // Make sure that custom questions are not blank.
    if ($question['question'] == 'other' && empty($question['custom_question'])) {
      form_set_error('questions][' . $i . '][custom_question', t('Please supply a custom question.'));
    }
  }

  // Disallow duplicate question selections.
  $duplicates = array_diff_key($chosen, array_unique($chosen));
  foreach ($duplicates as $duplicate => $sqid) {
    if ($sqid != 'other') {
      form_set_error('questions][' . $duplicate . '][question', t('Please select a question that you have not already chosen.'));
    }
  }
}

/**
 * Submission handler for the user's security questions form.
 */
function security_questions_user_form_submit($form, &$form_state) {
  // While security_questions_user_form() may be called with $account = NULL
  // during registration, that case uses hook_user_insert() to save the form.
  // Thus, it should be safe to assume that 'account' exists here.
  $account = $form_state['values']['account'];
  security_questions_user_answers_save($account, $form_state['values']['questions']);
}
