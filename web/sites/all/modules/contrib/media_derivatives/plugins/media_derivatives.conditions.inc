<?php

/**
 * @file
 *   Implementation of some basic conditions.
 */

/**
 * Implements hook_media_derivatives_conditions_info().
 */
function media_derivatives_media_derivatives_conditions_info() {
  $conditions = array();

  $conditions['file_type'] = array(
    'name' => t('File type'),
    'description' => t('Checks file type.'),
    'callback' => 'media_derivatives_type_support',
    'ui_callback' => 'media_derivatives_type_support_ui',
    'negatable' => TRUE,
  );
  $conditions['mime_type'] = array(
    'name' => t('Mime type'),
    'description' => t("Checks file's mime."),
    'callback' => 'media_derivatives_mime_support',
    'ui_callback' => 'media_derivatives_mime_support_ui',
    'negatable' => TRUE,
  );
  $conditions['stream_wrapper'] = array(
    'name' => t('Stream wrapper'),
    'description' => t('Checks stream wrapper.'),
    'callback' => 'media_derivatives_stream_support',
    'ui_callback' => 'media_derivatives_stream_support_ui',
    'negatable' => TRUE,
  );
  $conditions['derivatives_of_derivatives'] = array(
    'name' => t('Derivatives of derivatives'),
    'description' => t('Should this preset be used for derivatives of derivatives?'),
    'callback' => 'media_derivatives_derivative_support',
    'ui_callback' => 'media_derivatives_derivative_support_ui',
  );

  return $conditions;
}


/**
 * Checks if preset was configured to encode this file type.
 */
function media_derivatives_type_support($file, $preset) {
  return $file->type == $preset->conditions_settings['type'];
}

/**
 * UI callback for File type derivation condition.
 */
function media_derivatives_type_support_ui() {
  $form = array();
  if (function_exists('file_info_file_types')) {
    $types = file_info_file_types();
  }
  elseif (function_exists('file_type_load_all')) {
    $types = file_type_load_all();
  }
  else {
    $types = file_type_get_all_types();
  }

  foreach ($types as $key => $type) {
    $types[$key] = is_array($type) ? check_plain($type['label']) : check_plain($type->label);
  }

  $form['type'] = array(
    '#type' => 'select',
    '#title' => t('File type'),
    '#options' => $types,
    '#description' => t('Type of file that will be processed with this preset.'),
  );

  return $form;
}

/**
 * Checks if preset was configured to encode this file mime.
 */
function media_derivatives_mime_support($file, $preset) {
  $settings = $preset->conditions_settings;

  if (empty($settings['mime_types'])) {
    return TRUE;
  }
  else {

    // Convert to array if only one value.
    $data = array();
    if (is_string($settings['mime_types'])) {
      $data[] = $settings['mime_types'];
    }
    else {
      $data = $settings['mime_types'];
    }

    $mime = FALSE;
    foreach ($data as $item) {
      $pattern = preg_quote($item, '/');
      $pattern = preg_replace('/\\\\\*/', '[a-zA-Z0-9\-]*', $pattern);
      $pattern = '/' . $pattern . '/';
      $mime |= preg_match($pattern, $file->filemime);
    }

    return $mime;
  }
}

/**
 * UI callback for Mime type derivation condition.
 */
function media_derivatives_mime_support_ui() {
  $form = array();
  $form['mime_types'] = array(
    '#type' => 'textarea',
    '#title' => t('Mime types'),
    '#description' => t('List of supported mime types, each in own line. Wildcard (*) can be used. Examples: video/mp4, video/*, *.'),
    '#element_validate' => array(
      'media_derivatives_mime_support_ui_validate'
    ),
    '#process' => array(
      'media_derivatives_mime_support_ui_process'
    ),
  );
  return $form;
}

function media_derivatives_mime_support_ui_validate($element, &$form_state) {
  $mime = explode("\n", $form_state['values']['mime_types']);
  foreach ($mime as &$item) {
    $item = trim($item);
  }
  $form_state['values']['mime_types'] = $mime;
}

function media_derivatives_mime_support_ui_process($element, &$form_state) {
  if (isset($element['#default_value']) && is_array($element['#default_value'])) {
    $element['#default_value'] = implode("\n", $element['#default_value']);
    $element['#value'] = $element['#default_value'];
  }

  return $element;
}

/**
 * Checks if preset was configured to encode this stream.
 */
function media_derivatives_stream_support($file, $preset) {
  $settings = $preset->conditions_settings;

  if (empty($settings['stream_wrappers'])) {
    return TRUE;
  }
  else {

    // Convert to array if only one value.
      $data = array();
    if (is_string($settings['stream_wrappers'])) {
      $data[] = $settings['stream_wrappers'];
    }
    else {
      $data = $settings['stream_wrappers'];
    }

    $stream = FALSE;
    foreach ($data as $item) {
      $pattern = preg_quote($item, '/');
      $pattern = '/' . $pattern . '/';
      $stream |= preg_match($pattern, $file->uri);
    }

    return $stream;
  }
}

/**
 * UI callback for Stream wrapper derivation condition.
 */
function media_derivatives_stream_support_ui() {
  $streams = array_keys(file_get_stream_wrappers());
  $options = array();
  foreach ($streams as &$item) {
    $options[$item . '://'] = $item . '://';
  }

  $form = array();
  $form['stream_wrappers'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Stream wrappers'),
    '#description' => t('Select stream schemes that this preset should support for source files.'),
    '#options' => $options,
    '#element_validate' => array(
      'media_derivatives_stream_support_ui_validate',
    ),
  );

  return $form;
}

function media_derivatives_stream_support_ui_validate($element, &$form_state) {
  $form_state['values']['stream_wrappers'] = array_values(array_filter($form_state['values']['stream_wrappers']));
}


/**
 * Checks if preset was configured to encode files that are already derivatives.
 */
function media_derivatives_derivative_support($file, $preset) {
  $ret = $file->media_derivatives['is_derivative'] && isset($preset->conditions_settings['encode_derivatives']) && $preset->conditions_settings['encode_derivatives'];

  // If this file is a derivative check if it was encoded with
  // same preset (prevent loops).
  if ($ret) {
    $derivative = $file->media_derivatives['derivative_object'];
    $ret = $derivative->preset->machine_name != $preset->machine_name;
  }

  $ret |= !$file->media_derivatives['is_derivative'];

  return $ret;
}

/**
 * UI callback for Derivatives of derivatives derivation rule.
 */
function media_derivatives_derivative_support_ui() {
  $form = array();
  $form['encode_derivatives'] = array(
    '#type' => 'checkbox',
    '#title' => t('Encode derivatives'),
    '#description' => t('Check this if you want this preset to create derivatives of derivatives.'),
  );
  return $form;
}
