<?php

/**
 * @file
 *   Implements export UI plugin for Derivatives API.
 */


/**
 * Define this Export UI plugin.
 */
$plugin = array(
  'schema' => 'media_derivatives_presets',
  'access' => 'administer media_derivatives presets',
  'menu' => array(
    'menu prefix' => 'admin/config/media',
    'menu item' => 'media-derivatives',
    'menu title' => 'Media derivatives',
    'menu description' => 'Media derivatives configuration presets management.',
  ),

  'title singular' => t('preset'),
  'title plural' => t('presets'),
  'title singular proper' => t('Media derivatives preset'),
  'title plural proper' => t('Media derivatives presets'),

  'use wizard' => TRUE,
  'form info' => array(
    'add order' => array(
      'basic' => t('Basic preset settings'),
      'events' => t('Events settings'),
      'scheduler' => t('Scheduler settings'),
      'conditions' => t('Conditions settings'),
      'engine' => t('Engine settings'),
    ),
    'edit order' => array(
      'basic' => t('Basic preset settings'),
      'events' => t('Events settings'),
      'scheduler' => t('Scheduler settings'),
      'conditions' => t('Conditions settings'),
      'engine' => t('Engine settings'),
    ),
    'clone order' => array(
      'basic' => t('Basic preset settings'),
      'events' => t('Events settings'),
      'scheduler' => t('Scheduler settings'),
      'conditions' => t('Conditions settings'),
      'engine' => t('Engine settings'),
    ),
    'forms' => array(
      'basic' => array(
        'form id' => 'media_derivatives_ui_form_basic',
      ),
      'events' => array(
        'form id' => 'media_derivatives_ui_form_others',
      ),
      'scheduler' => array(
        'form id' => 'media_derivatives_ui_form_others',
      ),
      'conditions' => array(
        'form id' => 'media_derivatives_ui_form_others',
      ),
      'engine' => array(
        'form id' => 'media_derivatives_ui_form_others',
      ),
      'edit' => array(
        'form id' => 'media_derivatives_ui_form_edit',
      ),
    ),
  ),
);


/**
 * Define the preset add/edit form. This is basic preset information
 * form callback. It configures machine name, engine, ...
 */
function media_derivatives_ui_form_basic($form, &$form_state) {
  $new = _media_derivatives_ui_global_form_settings($form, $form_state);

  $form['wrapper']['machine_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine name'),
    '#required' => TRUE,
    '#description' => t("Enter preset's machine name."),
    '#machine_name' => array(
      'exists' => '_media_derivatives_ui_machine_name_check',
    ),
    '#default_value' => isset($form_state['item']->machine_name) ? $form_state['item']->machine_name : '',
    '#disabled' => !$new && $new = $form_state['form type'] != 'clone',
  );

  $form['wrapper']['basic'] = array(
    '#type' => 'fieldset',
    '#title' => t('Basic options'),
    '#collapsible' => TRUE,
  );

  $form['wrapper']['basic']['type'] = array(
    '#type' => 'radios',
    '#title' => t('File type'),
    '#description' => t('Which type created file should be.'),
    '#default_value' => isset($form_state['item']->settings['type']) ? $form_state['item']->settings['type'] : MEDIA_DERIVATIVE_FILE_TYPE_UNMANAGED,
    '#options' => array(
      MEDIA_DERIVATIVE_FILE_TYPE_UNMANAGED => t('Unmanaged'),
      MEDIA_DERIVATIVE_FILE_TYPE_MANAGED => t('Managed'),
    ),
  );

  $form['wrapper']['basic']['recursive_delete'] = array(
    '#type' => 'checkbox',
    '#title' => t('Recursive delete'),
    '#description' => t('Remove all derivatives when removing source file.'),
    '#default_value' => isset($form_state['item']->settings['recursive_delete']) ? $form_state['item']->settings['recursive_delete'] : FALSE,
  );

  $form['wrapper']['basic']['delete_source'] = array(
    '#type' => 'checkbox',
    '#title' => t('Delete source'),
    '#description' => t('Delete source when derivative was successfully created.'),
    '#default_value' => isset($form_state['item']->settings['delete_source']) ? $form_state['item']->settings['delete_source'] : FALSE,
  );

  $form['wrapper']['basic']['user'] = array(
    '#type' => 'select',
    '#title' => t('Derivative owner'),
    '#description' => t('Derivative owner policy.'),
    '#options' => array(
      MEDIA_DERIVATIVE_OWNER_FILE => t('Source file owner'),
      MEDIA_DERIVATIVE_OWNER_DERIVATIVE => t('Derivative creator'),
      MEDIA_DERIVATIVE_OWNER_STATIC => t('Fixed user'),
    ),
    '#default_value' => isset($form_state['item']->settings['user']) ? $form_state['item']->settings['user'] : MEDIA_DERIVATIVE_OWNER_FILE,
  );

  $form['wrapper']['basic']['user_uid'] = array(
    '#type' => 'select',
    '#title' => t('Username'),
    '#options' => _media_derivatives_ui_get_usernames(),
    '#states' => array(
      'visible' => array(
        'select[name="user"]' => array('value' => '2'),
      ),
    ),
    '#default_value' => isset($form_state['item']->settings['user_uid']) ? $form_state['item']->settings['user_uid'] : 1,
  );

  $form['wrapper']['engine'] = array(
    '#type' => 'select',
    '#title' => t('Engine'),
    '#description' => t('Select engine that should be used in this preset.'),
    '#options' => _media_derivatives_ui_get_options('engines', 'name'),
    '#default_value' => isset($form_state['item']->engine) ? $form_state['item']->engine : 0,
  );

  $form['wrapper']['events'] = array(
    '#type' => 'checkboxes',
    '#required' => TRUE,
    '#title' => t('Events'),
    '#description' => t('Select events that this preset should react upon.'),
    '#options' => _media_derivatives_ui_get_options('events', 'name'),
    '#default_value' => isset($form_state['item']->events) ? $form_state['item']->events : array(),
  );

  $form['wrapper']['scheduler'] = array(
    '#type' => 'select',
    '#title' => t('Scheduler'),
    '#description' => t('Select scheduler that should be used for this preset.'),
    '#options' => _media_derivatives_ui_get_options('schedulers', 'name'),
    '#default_value' => isset($form_state['item']->scheduler) ? $form_state['item']->scheduler : array(),
  );

  $form['wrapper']['conditions'] = array(
    '#type' => 'checkboxes',
    '#required' => TRUE,
    '#title' => t('Conditions'),
    '#description' => t('Select conditions that should be checked once this preset was triggered.'),
    '#options' => _media_derivatives_ui_get_options('conditions', 'name'),
    '#default_value' => isset($form_state['item']->conditions) ? $form_state['item']->conditions : array(),
  );

  return $form;
}

function media_derivatives_ui_form_basic_submit($form, &$form_state) {
  $form_state['item']->machine_name = $form_state['values']['machine_name'];
  $form_state['item']->engine = $form_state['values']['engine'];
  if (empty($form_state['item']->engine_settings)) {
    $form_state['item']->engine_settings = array();
  }
  $form_state['item']->settings['type'] = $form_state['values']['type'];
  $form_state['item']->settings['recursive_delete'] = $form_state['values']['recursive_delete'];
  $form_state['item']->settings['delete_source'] = $form_state['values']['delete_source'];
  $form_state['item']->settings['user'] = $form_state['values']['user'];
  if ($form_state['item']->settings['user'] == MEDIA_DERIVATIVE_OWNER_STATIC) {
    $form_state['item']->settings['user_uid'] = $form_state['values']['user_uid'];
  }
  $form_state['item']->events = array_values(array_filter($form_state['values']['events']));
  if (empty($form_state['item']->events_settings)) {
    $form_state['item']->events_settings = array();
  }
  $form_state['item']->conditions = array_values(array_filter($form_state['values']['conditions']));
  if (empty($form_state['item']->conditions_settings)) {
    $form_state['item']->conditions_settings = array();
  }
  $form_state['item']->scheduler = $form_state['values']['scheduler'];
  if (empty($form_state['item']->scheduler_settings)) {
    $form_state['item']->scheduler_settings = array();
  }

  // Clear cached presets.
  cache_clear_all('media_derivatives_presets', 'cache');
}

/**
 * Define the preset add/edit form. This is form callback for all non-basic configurations.
 * It is responsible for specific configurations for each type of plugins (conditions, events, engines
 * and schedulers).
 */
function media_derivatives_ui_form_others($form, &$form_state) {
  _media_derivatives_ui_global_form_settings($form, $form_state);

  // Get registry of a given plugin type. Plugin type is recognized from
  // the name of the current wizard step.
  $type = in_array($form_state['step'], array('engine', 'scheduler')) ? $form_state['step'] . 's' : $form_state['step'];
  $function = 'media_derivatives_get_' . $type;
  $registry = $function();

  // Get selected items that were selected on a basic configuration form
  // for a given plugin type. Engine and scheduler are saved as single values
  // and must be save differently.
  $items = array();
  if (!in_array($form_state['step'], array('engine', 'scheduler'))) {
    $items = $form_state['item']->{$form_state['step']};
  }
  else {
    $items[] = $form_state['item']->{$form_state['step']};
  }

  // Help message on the top of wizard step.
  $form['wrapper']['message'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
  );
  $form['wrapper']['message']['message_content'] = array(
    '#markup' => _media_derivatives_ui_wizard_message($form_state['step']),
  );

  // Load form for each item from it's module.
  foreach ($items as $item) {
    if (isset($registry[$item]['ui_callback'])) {
      $subform = $registry[$item]['ui_callback']();
      $form['wrapper'][$item] = array(
        '#type' => 'fieldset',
        '#title' => $registry[$item]['name'],
        '#collapsible' => TRUE,
      );

      foreach ($subform as $key => $element) {
        $form['wrapper'][$item][$key] = $element;
        if (isset($form_state['item']->{$form_state['step'] . '_settings'}[$key])) {
          $form['wrapper'][$item][$key]['#default_value'] = $form_state['item']->{$form_state['step'] . '_settings'}[$key];
        }
      }

      if ($type == 'conditions' && !empty($registry[$item]['negatable'])) {
        $form['wrapper'][$item][$item . '_negate'] = array(
          '#type' => 'checkbox',
          '#title' => t('Negate'),
          '#default_value' => !empty($form_state['item']->conditions_settings[$item . '_negate']),
          '#description' => t('If checked, the file will be processed if this condition is NOT true.'),
        );
      }
    }
  }

  return $form;
}

function media_derivatives_ui_form_others_submit($form, $form_state) {
  // Get selected items (events, conditions, scheduler, ...)
  $items = array();
  if (!in_array($form_state['step'], array('engine', 'scheduler'))) {
    $items = $form_state['item']->{$form_state['step']};
  }
  else {
    $items[] = $form_state['item']->{$form_state['step']};
  }

  // Save configuration for each hook.
  $items_wrapper = $form['wrapper'];
  foreach ($items as $item) {
    if (isset($form['wrapper'][$item])) {
      foreach ($form['wrapper'][$item] as $key => $item) {
        if (isset($form_state['values'][$key])) {
          $form_state['item']->{$form_state['step'] . '_settings'}[$key] = $form_state['values'][$key];
        }
      }
    }
  }

  // Clear cached presets.
  cache_clear_all('media_derivatives_presets', 'cache');
}

/**
 * Load all non-blocked usernames and return them as an options array for
 * select form item.
 */
function _media_derivatives_ui_get_usernames() {
  $uids = db_select('users', 'u')
    ->fields('u', array('uid', 'name'))
    ->condition('u.status', 1)
    ->execute()
    ->fetchAllAssoc('uid', PDO::FETCH_ASSOC);

  foreach ($uids as $uid => $user) {
    $uids[$uid] = $user['name'];
  }

  return $uids;
}

/**
 * Load all options for a given plugin type and return them as an options array
 * for select form item.
 */
function _media_derivatives_ui_get_options($type, $value) {
  $function = 'media_derivatives_get_' . $type;
  $registry = $function();

  foreach ($registry as $key => $item) {
    $registry[$key] = $item[$value];
  }
  return $registry;
}

/**
 * Checks if preset's machine name already used.
 */
function _media_derivatives_ui_machine_name_check($name) {
  $presets = media_derivatives_get_presets();
  return isset($presets[$name]);
}

/**
 * Returns help messages for each plugin type. These help messages are displayed
 * on top of the plugin type configuration form in the configuration wizard.
 */
function _media_derivatives_ui_wizard_message($type) {
  switch ($type) {
    case 'events':
      return t("Events trigger a derivative creation. Each preset can react to more than one event." .
               "Each event can implement a set of configuration settings that define its behaviour." .
               "This page could be empty, if the events that you selected for this preset do not need any configuration.");
    case 'scheduler':
      return t("Scheduler decides when a derivative should be processed. This decision will be time-based most of the time, but" .
               "this is not the only option. Each preset can use only one scheduler. Each scheduler can implement a set of" .
               "configuration settings that define its behaviour. This page could be empty, if the scheduler that you selected" .
               "for this preset does not need any configuration.");
    case 'engine':
      return t("Engine processes source file and creates derivative file. Each preset can use only one engine. Each engine can implement a set of" .
               "configuration settings that define its behaviour. This page could be empty, if the engine that you selected" .
               "for this preset does not need any configuration.");
    case 'conditions':
      return t("Conditions are checks that are executed at the derivate creation. Each condition must be TRUE if a derivative should be created." .
               "Each preset can test more than one condition." .
               "Each condition can implement a set of configuration settings that define its behaviour." .
               "This page could be empty, if the conditions that you selected for this preset do not need any configuration.");
  }
}

/**
 * Executes actions that need to be done for every form in our wizard
 * (adds CSS, checks if new, moves submit buttons inside wrapper, ...).
 *
 * @return TRUE if this is an add wizard and false if edit.
 */
function _media_derivatives_ui_global_form_settings(&$form, &$form_state) {
  $new = $form_state['form type'] == 'add';
  $form['#attached']['css'][] = drupal_get_path('module', 'media_derivatives_ui') . '/css/media_derivatives_ui.css';
  $form['#attributes']['class'][] = $new ? 'add-preset' : 'edit-preset';

  if (!$new) {
    $form['ctools_trail']['#markup'] = str_replace('»', '', $form['ctools_trail']['#markup']);
    $form['wrapper']['#type'] = 'fieldset';
  }

  $form['wrapper']['buttons'] = $form['buttons'];
  unset($form['buttons']);

  return $new;
}
