<?php

/**
 * @file
 *   Implementation of basic events.
 */


/**
 * Implements hook_media_derivatives_events_info().
 */
function media_derivatives_media_derivatives_events_info() {
  $events = array();
  $events['file_insert'] = array(
    'name' => t('File insert derivative event'),
    'description' => t('Derivative event that will be executed when a new file is saved.'),
    'validation_callbacks' => array(),
  );
  $events['field_presave'] = array(
    'name' => t('Field presave derivative event'),
    'description' => t('Derivative event that will be executed before an entity with file fields is saved. It will create derivatives for files in those fields.'),
    'validation_callbacks' => array(
      '_media_derivatives_field_presave_validation'
    ),
    'ui_callback' => '_media_derivatives_field_presave_ui',
  );
  $events['field_insertupdate'] = array(
    'name' => t('Field insert or update derivative event'),
    'description' => t('Derivative event that will be executed when an entity with file fields is inserted or updated in the database. It will create derivatives for files in those fields.'),
    'validation_callbacks' => array(
      '_media_derivatives_field_insertupdate_validation'
    ),
    'ui_callback' => '_media_derivatives_field_insertupdate_ui',
  );
  return $events;
}

/**
 * Event validation function for field_presave event. Checks if preset allows files
 * from this field to be derivated.
 */
function _media_derivatives_field_presave_validation($file, $preset, $context) {
  return in_array($context['field'], array_filter($preset->events_settings['field_presave_allowed_fields']));
}

/**
 * UI callback for field_presave event.
 */
function _media_derivatives_field_presave_ui() {
  $allowed = media_derivatives_supported_fields();

  $fields = array();
  foreach ($allowed as $name => $item) {
    $fields[$name] = $name;
  }

  $form = array();
  $form['field_presave_allowed_fields'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Allowed fields'),
    '#description' => t('Select fields that should event creation of a derivative.'),  //FIXME
    '#options' => $fields,
  );
  return $form;
}

/**
 * Implements hook_entity_presave().
 *
 * File (media, ...) fields must be recognized and field-triggered encodings started.
 */
function media_derivatives_entity_presave($entity, $type) {
  // Recognize fields in this entity.
  // Check if encoding needs to be started.
  foreach (media_derivatives_supported_fields() as $field => $fid) {
    if ($values = field_get_items($type, $entity, $field)) {
      foreach ($values as $item) {
        $file = file_load($item[$fid]);
        media_derivatives_create_all_derivatives($file, 'field_presave', array('field' => $field));
      }
    }
  }
}

/**
 * Event validation function for field_insertupdate event. Checks if preset allows files
 * from this field to be derivated.
 */
function _media_derivatives_field_insertupdate_validation($file, $preset, $context) {
  return (in_array($context['field'], $preset->events_settings['field_insertupdate_allowed_fields']) &&
   is_string($preset->events_settings['field_insertupdate_allowed_fields'][$context['field']]) );
}

/**
 * UI callback for field_insertupdate event.
 */
function _media_derivatives_field_insertupdate_ui() {
  $allowed = media_derivatives_supported_fields();

  $fields = array();
  foreach ($allowed as $name => $item) {
    $fields[$name] = $name;
  }

  $form = array();
  $form['field_insertupdate_allowed_fields'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Allowed fields'),
    '#description' => t('Select fields that should event creation of a derivative.'),  //FIXME
    '#options' => $fields,
  );
  return $form;
}

/**
 * Implements hook_entity_insert().
 */
function media_derivatives_entity_insert($entity, $type) {
  media_derivatives_entity_update($entity, $type);
}

/**
 * Implements hook_entity_update().
 *
 * File (media, ...) fields must be recognized and field-triggered encodings started.
 */
function media_derivatives_entity_update($entity, $type) {
  // Recognize fields in this entity.
  // Check if encoding needs to be started.
  foreach (media_derivatives_supported_fields() as $field => $fid) {
    if ($values = field_get_items($type, $entity, $field)) {
      foreach ($values as $item) {
        $file = file_load($item[$fid]);
        media_derivatives_create_all_derivatives($file, 'field_insertupdate', array('field' => $field, 'item' => $item));
      }
    }
  }
}


/**
 * Implements hook_file_insert().
 */
function media_derivatives_file_insert($file) {
  // Add media derivatives info to file object.
  if (empty($file->media_derivatives)) {
    $file->media_derivatives['is_derivative'] = FALSE;
    $file->media_derivatives['has_derivatives'] = FALSE;
  }

  // Check if file needs a derivative.
  // Handle temporary files later
  if ($file->status == FILE_STATUS_PERMANENT) {
    media_derivatives_create_all_derivatives($file, 'file_insert');
  }
  else {

    // Get data about temporary files from cache.
    // TODO: Are static variables better than cache here?
    if ($tmp_data = cache_get('media_derivatives_handle_temp', 'cache')) {
      $tmp_data = $tmp_data->data;
    }
    else {
      $tmp_data = array();
    }

    // Add data about this file.
    $tmp_data[$file->fid] = array(
        'filesize' => $file->filesize,
        'filemime' => $file->filemime,
        'timestamp' => $file->timestamp,
    );

    // Save to cache.
    cache_set('media_derivatives_handle_temp', $tmp_data, 'cache', CACHE_PERMANENT);

  }
}



/**
 * Implements hook_file_update().
 */
function media_derivatives_file_update($file) {
  // Check if this file is one of previously saved temporary files,
  // which has now become a permanent one.
  if ($tmp_data = cache_get('media_derivatives_handle_temp', 'cache')) {

    $tmp_data = $tmp_data->data;
    if (isset($tmp_data[$file->fid]) && $file->status == FILE_STATUS_PERMANENT) {

      // Create derivatives for this file.
      media_derivatives_create_all_derivatives($file, 'file_insert');

      // Remove file from temporary files registry.
      unset($tmp_data[$file->fid]);

      // Update temporary files registry.
      if (empty($tmp_data)) {
        cache_clear_all('media_derivatives_handle_temp', 'cache');
      }
      else {
        cache_set('media_derivatives_handle_temp', $tmp_data, 'cache', CACHE_PERMANENT);
      }

    }

  }
}
