<?php
/**
 * @file
 * Admin ui for the File Entity Paths module.
 */

/**
 * Form builder for default configuration admin form.
 *
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function fe_paths_admin_form($form, &$form_state) {
  $allowed = fe_paths_get_allowed_schemes();
  $settings = fe_paths_get_settings();
  $entity_info = entity_get_info('file');
  foreach ($entity_info['bundles'] as $file_type => $bundle_info) {
    $form["fep_$file_type"] = array(
      '#type' => 'fieldset',
      '#title' => check_plain(t("Global settings for $file_type")),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,
    );
    foreach (file_get_stream_wrappers() as $scheme => $wrapper) {
      if (in_array($scheme, $allowed)) {
        $form["fep_$file_type"][$scheme] = array(
          '#type' => 'fieldset',
          '#title' => t("@scheme files", array('@scheme' => $scheme)),
          '#description' => t('Default settings for @scheme files.', array('@scheme' => $scheme)),
          '#tree' => TRUE,
          'path' => array(
            '#type' => 'textfield',
            '#title' => t("Path"),
            '#element_validate' => array('token_element_validate'),
            '#token_types' => array('file', 'file'),
            // Tmp disable until figure out, how to get the proper directory.
            //'#field_prefix' => variable_get('file_public_path', conf_path() . '/files') . '/',
            '#field_prefix' => "$scheme://",
            '#default_value' => $settings[$file_type][$scheme]['path'],
          ),
          'filename' => array(
            '#type' => 'textfield',
            '#title' => t("Filename"),
            '#element_validate' => array('token_element_validate'),
            '#token_types' => array('file', 'file'),
            '#default_value' => $settings[$file_type][$scheme]['filename'],
          )
        );
      }
    }
    $form["fep_$file_type"]['tokens'] = array(
      '#type' => 'fieldset',
      '#title' => t('Replacement patterns'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#description' => theme('token_tree', array(
        'token_types' => array(
          'file',
          'file'
        )
      )),
      '#weight' => 1000,
    );
  }

  return system_settings_form($form);
}

/**
 * Form builder for File Entity Paths configuration add/edit form.
 *
 * @param $form
 * @param $form_state
 * @param null $config
 *
 * @return mixed
 */
function fe_paths_entity_edit_form($form, &$form_state, $config = NULL) {
  $file_entity_info = entity_get_info('file');
  $entities = fe_paths_get_fieldable_entities();
  $file_types = array();
  $file_types_defaults = isset($config->data['file_entity']) ? $config->data['file_entity'] : array();
  // The name of the entity, which is connected to this config. Can be changed by $form_state.
  $entity_name = isset($config->data['entity']) ? $config->data['entity'] : NULL;
  // Set $entity_name value own $form_state value, if exists. It means, the form
  // is changed during ajax process.
  $entity_name = isset($form_state['values']['data']['entity']) ? $form_state['values']['data']['entity'] : $entity_name;

  foreach ($file_entity_info['bundles'] as $name => $bundle) {
    $file_types[$name] = $bundle['label'];
  }

  // Add id to form when editing existing config.
  if (!is_null($config)) {
    $form['id'] = array(
      '#type' => 'value',
      '#value' => $config->id,
    );
  }

  $form['label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#default_value' => isset($config->label) ? $config->label : '',
    '#required' => TRUE,
  );
  $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine name'),
    '#default_value' => isset($config->machine_name) ? $config->machine_name : '',
    '#machine_name' => array(
      'exists' => 'fe_paths_check_machine_name',
    ),
  );

  $form['path_name'] = array(
    '#type' => 'fieldset',
    '#title' => t('Path and filename settings'),
    'path' => array(
      '#type' => 'textfield',
      '#title' => t("Path"),
      '#description' => t('The path applied after the scheme://. It means, if the file has scheme "public", and this field is set as "foo", the file will be moved to the public://foo path. <strong>Do not use trailing slash at the end!</strong>'),
      //'#element_validate' => array('token_element_validate'),
      //'#token_types' => array('file', 'file'),
      // Tmp disable until figure out, how to get the proper directory.
      //'#field_prefix' => variable_get('file_public_path', conf_path() . '/files') . '/',
      '#field_prefix' => "scheme://",
      '#default_value' => isset($config->path) ? $config->path : '',
    ),
    'filename' => array(
      '#type' => 'textfield',
      '#title' => t("Filename"),
      '#description' => t('Set the filename pattern. This pattern will be validated based on parent entity settings. If settings is "global", all types of tokens are enabled. File tokens is always accepted. <strong>Do not use trailing slash in this field!</strong>'),
      //'#element_validate' => array('token_element_validate'),
      //'#token_types' => array('file', 'file'),
      '#default_value' => isset($config->filename) ? $config->filename : '[file:name-only-original].[file:extension-original]',
    ),
    'tokens' => array(
      '#type' => 'fieldset',
      '#title' => t('Replacement patterns'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      'help' => array(
        '#theme' => 'token_tree',
        '#token_types' => array_keys($entities),
      ),
      '#prefix' => '<div id="fe-paths-tokens">',
      '#suffix' => '</div>',
    ),
  );


  $form['path_name']['transliteration'] = array(
    '#type' => 'checkbox',
    '#title' => t('Transliterate'),
    '#default_value' => isset($config->data['transliteration']) ? $config->data['transliteration'] : FALSE,
    '#description' => t('Use module !link to cleanup path and filename.', array('!link' => l(t('Transliteration'), 'http://drupal.org/project/transliteration', array('external' => TRUE)))),
    '#parents' => array('data', 'transliteration'),
  );
  if (!module_exists('transliteration')) {
    $form['path_name']['transliteration']['#disabled'] = TRUE;
    $form['path_name']['transliteration']['#default_value'] = 0;
  }

  $form['path_name']['pathauto'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pathauto'),
    '#default_value' => isset($config->data['pathauto']) ? $config->data['pathauto'] : FALSE,
    '#description' => t('Use module !link to cleanup path and filename.', array('!link' => l(t('Pathauto'), 'http://drupal.org/project/pathauto', array('external' => TRUE)))),
    '#parents' => array('data', 'pathauto'),
  );
  if (!module_exists('pathauto')) {
    $form['path_name']['pathauto']['#disabled'] = TRUE;
    $form['path_name']['pathauto']['#default_value'] = 0;
  }

  $form['file_entity'] = array(
    '#type' => 'fieldset',
    '#title' => t('File types'),
    'file_bundle' => array(
      '#type' => 'checkboxes',
      '#options' => $file_types,
      '#description' => t('Choose, in which file types should this configuration be activated.'),
      '#parents' => array('data', 'file_entity'),
      '#default_value' => $file_types_defaults,
    ),
  );

  $form['parent_entity'] = array(
    '#type' => 'fieldset',
    '#title' => t('Parent entity settings'),
    '#tree' => TRUE,
    'entity' => array(
      '#type' => 'select',
      '#title' => t('Choose entity'),
      '#description' => t('Choose the parent entity. The parent entity determine, which type of tokens will be used in this config.'),
      '#options' => array('global' => t('Global')) + $entities,
      '#ajax' => array(
        'callback' => 'fe_paths_add_bundle_settings',
        'wrapper' => 'bundle-target',
        //'method' => 'html',
      ),
      '#parents' => array('data', 'entity'),
      '#default_value' => isset($config->data['entity']) ? $config->data['entity'] : 'global',
    ),
    'bundle' => array(
      '#tree' => TRUE,
      '#type' => 'container',
      '#attributes' => array(
        'id' => 'bundle-target',
      ),
      '#parents' => array('data', 'bundle'),
    )
  );

  if (!is_null($entity_name) && $entity_name != 'global') {
    $bundles = fe_paths_get_bundle_names($entity_name);

    // Only listed the bundles, in which proper field exists.
    foreach ($bundles as $key => $bundle) {
      $fields = fe_paths_get_available_fields($entity_name, $key);
      if (empty($fields)) {
        unset($bundles[$key]);
      }
    }

    foreach ($bundles as $key => $bundle) {
      $fields = fe_paths_get_available_fields($entity_name, $key);

      $form['parent_entity']['bundle'][$key] = array(
        '#type' => 'fieldset',
        '#title' => check_plain($bundles[$key]),
      );

      foreach ($fields as $field_name => $field) {
        $form['parent_entity']['bundle'][$key][$field_name] = array(
          '#type' => 'checkbox',
          '#title' => check_plain($field),
          '#default_value' => isset($config->data['bundle'][$key][$field_name]) ? $config->data['bundle'][$key][$field_name] : FALSE,
        );
      }
    }
  }

  $form['overrides'] = array(
    '#type' => 'fieldset',
    '#title' => t('Overrides'),
    'other_config' => array(
      '#type' => 'checkbox',
      '#title' => t('Override by other configuration.'),
      '#description' => t('Let other lower weight configuration to modify path provided by this configuration. This is independent of the <em>Override options</em> below. If this is checked, the lower weighted configuration will be always applied!'),
      '#default_value' => isset($config->data['other_config']) ? $config->data['other_config'] : FALSE,
      '#parents' => array('data', 'other_config'),
    ),
    'override_options' => array(
      '#type' => 'radios',
      '#title' => t('Override options'),
      '#description' => t('This override setting define the behaviour of files, which are used more than one entities in the same time.
        Set this to <em>Never</em> means, the path of the file will never be regenerated.
        <em>Within the same entity type</em> means, if a file was uploaded to a user entity, and is used again in a node, the file path will not be overridden.
        But if you upload the file to a node, and you use it again in other node, the new node tokens (if set) will be saved.
        If settings <em>Within the same entity</em> is choosen, the file used in two different node will be not updated,
        but if you set to change filename to node title, and the title is changed in the node, in which the file was originally uploaded,
        the path will be changed to the new node title.'),
      '#options' => fe_paths_get_override_options(),
      '#default_value' => isset($config->data['override_options']) ? $config->data['override_options'] : FE_PATHS_OVERRIDE_NEVER,
      '#parents' => array('data', 'override_options'),
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Ajax callback for fe_paths_entity_edit_form().
 *
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function fe_paths_add_bundle_settings($form, &$form_state) {
  return $form['parent_entity']['bundle'];
}

/**
 * Form validation of File Entity Paths configuration add/edit form.
 *
 * @param $form
 * @param $form_state
 */
function fe_paths_entity_edit_form_validate($form, &$form_state) {
  $form_state['redirect'] = 'admin/config/media/fe-paths';
}

/**
 * Form submit function for File Entity Paths configuration add/edit form.
 *
 * @param $form
 * @param $form_state
 */
function fe_paths_entity_edit_form_submit($form, &$form_state) {
  $config = $form_state['values'];
  fe_paths_prepare_config($config);
  fe_paths_config_save($config);
}

/**
 * Form builder for File Entity Paths configuration list table.
 *
 * @param $form
 * @param $form_state
 * @param $configs
 *
 * @return array
 */
function fe_paths_config_table_form($form, &$form_state, $configs) {
  $form_state['configs'] = $configs;
  $form = array(
    'config' => array(
      '#prefix' => '<div id="config-order-form">',
      '#suffix' => '</div>',
      '#tree' => TRUE,
      '#theme' => 'fe_paths_config_table'
    )
  );
  foreach ($configs as $name => $config) {
    $form['config'][$name]['label'] = array(
      '#markup' => check_plain($config->label),
    );
    $form['config'][$name]['weight'] = array(
      '#type' => 'textfield',
      '#default_value' => $config->weight,
      '#size' => 3,
      '#attributes' => array('class' => array('order-weight')),
    );
    $form['config'][$name]['machine_name'] = array(
      '#markup' => check_plain($config->machine_name),
    );
    $form['config'][$name]['status'] = array(
      '#markup' => $config->status ? t('Enabled') : t('Disabled'),
    );
    $form['config'][$name]['path'] = array(
      '#markup' => check_plain($config->path),
    );
    $form['config'][$name]['filename'] = array(
      '#markup' => check_plain($config->filename),
    );
    $form['config'][$name]['data'] = array(
      '#markup' => theme('fe_paths_config_data', array('config' => $config)),
    );
    $form['config'][$name]['link'] = array(
      '#markup' => l(t('Edit'), "admin/config/media/fe-paths/{$config->id}/edit") . '</br>' . l(t('Delete'), "admin/config/media/fe-paths/{$config->id}/delete"),
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Order'),
  );

  return $form;
}

/**
 * Form submit function for File Entity Paths table form.
 *
 * @param $form
 * @param $form_state
 */
function fe_paths_config_table_form_submit($form, &$form_state) {
  foreach ($form_state['configs'] as $id => $config) {
    $config->weight = $form_state['values']['config'][$id]['weight'];
    fe_paths_config_save($config);
  }
}

/**
 * Form build for configuration deleting form.
 *
 * @param $form
 * @param $form_state
 * @param $config
 *
 * @return mixed
 */
function fe_paths_config_delete_confirm($form, &$form_state, $config) {
  $form['id'] = array('#type' => 'value', '#value' => $config->id);

  return confirm_form($form,
    t('Delete File Entity Path configuration.'),
    'admin/config/media/fe-paths',
    t('Are you sure you want to delete %title configuration?', array('%title' => $config->label)),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Form submit function for configuration deleting form.
 *
 * @param $form
 * @param $form_state
 */
function fe_paths_config_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    fe_paths_config_delete($form_state['values']['id']);
    drupal_set_message(t('The configuration is deleted.'));
  }
  $form_state['redirect'] = 'admin/config/media/fe-paths';
}

/**
 * Page callback for admin/config/media/fe-paths page.
 *
 * @return array
 */
function fe_paths_global_page() {
  $configs = fe_paths_config_load_multiple();
  $build = array();

  $build['config_form'] = drupal_get_form('fe_paths_config_table_form', $configs);
  $build['global_form'] = drupal_get_form('fe_paths_admin_form');
  return $build;
}

/**
 * Page callback for configuration edit page.
 *
 * @param $config
 *
 * @return array|mixed
 */
function fe_paths_config_edit_page($config) {
  $build = drupal_get_form('fe_paths_entity_edit_form', $config);

  return $build;
}

/**
 * Theme function to build table from list of File Entity Paths config.
 *
 * @param $variables
 *
 * @return string
 */
function theme_fe_paths_config_table($variables) {
  $element = $variables['element'];
  drupal_add_tabledrag('form_id', 'order', 'sibling', 'order-weight');
  $header = array(
    'label' => t('Label'),
    'weight' => t('Weight'),
    'machine_name' => t('Machine name'),
    'status' => t('Status'),
    'path' => t('Path'),
    'filename' => t('Filename'),
    'data' => t('Settings'),
    'link' => t('Edit'),
  );

  $rows = array();
  foreach (element_children($element) as $key) {
    $row = array();

    $row['data'] = array();
    foreach ($header as $fieldname => $title) {
      $row['data'][] = drupal_render($element[$key][$fieldname]);
      $row['class'] = array('draggable'); // needed for table dragging
    }
    $rows[] = $row;
  }

  return theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => 'form_id'), // needed for table dragging
  ));
}
