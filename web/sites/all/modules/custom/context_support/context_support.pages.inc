<?php

function context_help_page($js = FALSE) {

  $_SESSION['referer_for_support'] = $_SERVER['HTTP_REFERER'];
  if (!$js) {
    $form = drupal_get_form('context_support_contact_form');
    return $form;
  }

  $title = t("Help & Support");
  ctools_include('modal');
  ctools_include('ajax');
  $form_state = [
    'title' => $title,
    'ajax' => TRUE,
  ];

  $form_state += [
    'referer' => $_SERVER["HTTP_REFERER"],
  ];

  $output = ctools_modal_form_wrapper('context_support_contact_form', $form_state);
  if (!empty($form_state['ajax_commands'])) {
    $output = $form_state['ajax_commands'];
  }

  print ajax_render($output);
  drupal_exit();
}

/**
 * Form constructor for the site-wide contact form.
 *
 * @see contact_site_form_validate()
 * @see contact_site_form_submit()
 * @ingroup forms
 */
function context_support_contact_form($form, &$form_state) {
  global $user;

  $limit = variable_get('context_support_threshold_limit', 15);
  $window = variable_get('context_support_threshold_window', 3600);
  if (!flood_is_allowed('context_support', $limit, $window) && !user_access('administer site configuration')) {
    drupal_set_message(t("You cannot send more than %limit messages in @interval. Try again later.", [
      '%limit' => $limit,
      '@interval' => format_interval($window),
    ]), 'error');
    drupal_access_denied();
    drupal_exit();
  }

  $categories = context_support_get_categoriy_options();
  $default_category = reset($categories);


  if (!$user->uid) {
    $form['#attached']['library'][] = ['system', 'jquery.cookie'];
    $form['#attributes']['class'][] = 'user-info-from-cookie';
  }

  $form['#attributes']['class'][] = 'contact-form';

  $form['#prefix'] = '<div class="help_body form prefix">' . salto_help_tabs(TRUE, 'contact') . t('Via this form you can get in touch with the support team any time; Further information and faqs are also available in the help section. Please be sure to check the help before requesting the support.');

  $form['#suffix'] = '</div>';

  $form['name'] = [
    '#type' => 'textfield',
    '#title' => t('Your name'),
    '#maxlength' => 255,
    '#default_value' => $user->uid ? format_username($user) : '',
    '#required' => TRUE,
  ];

  if ($user->uid == 0) {
    $form['mail'] = [
      '#type' => 'textfield',
      '#title' => t('Your e-mail address'),
      '#maxlength' => 255,
      '#default_value' => '',
      '#required' => TRUE,
    ];
  }
  else {
    $form['mail'] = [
      '#type' => 'value',
      '#value' => $user->mail,
    ];
  }

  $form['subject'] = [
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#maxlength' => 255,
    '#required' => TRUE,
  ];
  $form['category'] = [
    '#type' => 'select',
    '#title' => t('Category'),
    '#default_value' => $default_category,
    '#options' => $categories,
    '#required' => TRUE,
    '#access' => count($categories) > 1,
  ];
  $form['message'] = [
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#required' => TRUE,
    '#resizable' => FALSE,
  ];

  $form['copy'] = [
    '#type' => 'checkbox',
    '#title' => t('Send me a copy.'),
    '#access' => $user->uid,
  ];
  $form['actions'] = ['#type' => 'actions'];
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t('Send message'),
  ];

  return $form;
}

/**
 * Form validation handler for contact_site_form().
 *
 * @see contact_site_form_submit()
 */
function context_support_contact_form_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['mail'])) {
    form_set_error('mail', t('You must enter a valid e-mail address.'));
  }
}

/**
 * Form submission handler for contact_site_form().
 *
 * @see contact_site_form_validate()
 */
function context_support_contact_form_submit($form, &$form_state) {
  global $user, $language;

  $categories = context_support_get_categories();
  $values = $form_state['values'];
  $catkey = $values['category'];
  $category = isset($categories[$catkey]) ? $categories[$catkey] : end($categories);


  $values['sender'] = $user;
  $values['sender']->name = $values['name'];
  $values['sender']->mail = $values['mail'];
  $values['category'] = $category['label'];

  $values['browserinfo'] = $catkey == "a" ? FALSE : TRUE;

  if (!$user->uid) {
    user_cookie_save(array_intersect_key($values, array_flip([
      'name',
      'mail',
    ])));
  }

  $to = $category['mail'];
  $from = $values['sender']->mail;

  if ($to != context_support_get_support_mail()) {
    drupal_mail('context_support', 'support_mail', $to, language_default(), $values, $from);
  }
  else {
    try {
      $data = [];
      $data['subject'] = context_support_render_ticket_subject($values, $language);
      $data['message'] = 'data:text/html;charset=utf-8,' . context_support_render_ticket_message($values, $language);
      $data['name'] = format_username($values['sender']);
      $data['email'] = $values['sender']->mail;
      $data['topicId'] = 1;
      $data['deptId'] = CONTEXT_SUPPORT_API_DEPT_ID;
      $data['gt_field_project'] = 'Bildungsnetz';
      $data['gt_field_uid'] = $values['sender']->uid;
      $data['gt_field_user_role'] = implode($user->roles, ', ');
      $data['gt_field_referer_link'] = $_SESSION['referer_for_support'];
      $data['gt_field_category_user'] = $category['label'];
      $data['gt_field_ip'] = $_SERVER['REMOTE_ADDR'];

      //Browserdata
      if (module_exists('browscap')) {
        $browser_info = browscap_get_browser();
        $data['gt_field_client_browser'] = $browser_info['browser'];
        $data['gt_field_client_browser_version'] = $browser_info['version'];
        $data['gt_field_client_os'] = $browser_info['platform'];
        $data['gt_field_client_user_agent'] = $browser_info['useragent'];
      }
      context_support_create_new_ticket($data);
    } catch (Exception $e) {
      drupal_mail('context_support', 'support_mail', $to, language_default(), $values, $from);
      watchdog('context_support', '!user tried to submit a support request: <pre>!data</pre>', [
        '!user' => $data['name'],
        '!data' => print_r($data, TRUE),
      ], WATCHDOG_ERROR);
      watchdog('context_support', '!lk+jm exeception support api: <pre>!data</pre>', [
        '!user' => $data['name'],
        '!data' => print_r($e->getMessage(), TRUE),
      ], WATCHDOG_ERROR);
    }
  }

  watchdog('context_support', '!user submitted a support request: <pre>!data</pre>', [
    '!user' => $data['name'],
    '!data' => print_r($data, TRUE),
  ], WATCHDOG_NOTICE);

  if ($values['copy']) {
    drupal_mail('context_support', 'support_mail_copy', $from, $language, $values, $to);
  }

  $send_mail_copy_string = variable_get('context_support_mail_copy', '');
  if (!empty($send_mail_copy_string)) {
    $copy_mails = explode(',', $send_mail_copy_string);
    foreach ($copy_mails as $mail_item) {
      drupal_mail('context_support', 'support_mail', $mail_item, language_default(), $values, $from);
    }
  }

  flood_register_event('context_support', variable_get('context_support_threshold_window', 3600));
  watchdog('mail', '%sender-name (@sender-from) sent an support e-mail with following  %category.', [
    '%sender-name' => $values['name'],
    '@sender-from' => $from,
    '%category' => $values['category'],
  ]);

  $message = '<div class="alert alert-success">' . t('Your request has been sent!') . '</div>';
  $form_state['ajax_commands'][] = ajax_command_replace('#modal-content', $message);
}

/**
 * @param $data
 *
 * @throws \Exception
 */
function context_support_create_new_ticket($data) {
  module_load_include('class.php', 'context_support', 'gt_osticket_api/gt_osticket');

  $config = [
    'url' => CONTEXT_SUPPORT_API_URL,
    'key' => CONTEXT_SUPPORT_API_KEY,
  ];

  $gtticket = new gt_osTicket($config);
  $gtticket->send($data);
}
