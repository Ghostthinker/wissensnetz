<?php
/**
 * @file
 * User page callbacks for the security questions module.
 */

function security_questions_rules_event_info() {
  $events = array();

  $events['security_questions_incorrect_answer'] = array(
    'label' => t('A security question was answered incorrectly'),
    'group' => t('Security Questions'),
    'variables' => array(
      'user' => array(
        'type' => 'user',
        'label' => t('The user who answered the question incorrectly'),
      ),
    ),
    'access callback' => 'security_questions_rules_access',
  );

  $events['security_questions_updated_answers'] = array(
    'label' => t('A updated their security question answers'),
    'group' => t('Security Questions'),
    'variables' => array(
      'user' => array(
        'type' => 'user',
        'label' => t('The user who updated the security question'),
      ),
    ),
    'access callback' => 'security_questions_rules_access',
  );

  $events['security_questions_all_incorrect_answers'] = array(
    'label' => t('All security questions for a user answered incorrectly'),
    'group' => t('Security Questions'),
    'variables' => array(
      'user' => array(
        'type' => 'user',
        'label' => t('The user who answered the questions incorrectly'),
      ),
    ),
    'access callback' => 'security_questions_rules_access',
  );

  return $events;
}

/**
 * Rules access callback.
 */
function security_questions_rules_access() {
  return user_access('administer security questions');
}
