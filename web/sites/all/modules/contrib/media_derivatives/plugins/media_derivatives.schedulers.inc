<?php

/**
 * @file
 *   Implementation of basic schedulers.
 */

/**
 * Implements hook_media_derivatives_triggers_info().
 */
function media_derivatives_media_derivatives_schedulers_info() {
  $schedulers = array();
  $schedulers['scheduler_immediate'] = array(
    'name' => t('Immediate scheduler'),
    'description' => t('Runs derivation immediatley (when a trigger happens).'),
    'callback' => '_media_derivatives_scheduler_immediate',
  );
  $schedulers['scheduler_time'] = array(
    'name' => t('Time scheduler'),
    'description' => t('Runs derivation at a fixed time.'),
    'callback' => '_media_derivatives_scheduler_time',
    'ui_callback' => '_media_derivatives_scheduler_time_ui',
  );
  $schedulers['scheduler_period'] = array(
    'name' => t('Period scheduler'),
    'description' => t('Runs derivation a fixed period of time after triggering has happened.'),
    'callback' => '_media_derivatives_scheduler_period',
    'ui_callback' => '_media_derivatives_scheduler_period_ui',
  );
  return $schedulers;
}

/**
 * Immediate scheduler callback.
 */
function _media_derivatives_scheduler_immediate($derivative) {
  return TRUE;
}

/**
 * Time scheduler callback.
 */
function _media_derivatives_scheduler_time($derivative) {
  return $derivative->preset->scheduler_settings['scheduled_time'];
}

/**
 * Preset configuration UI callback for fixed time scheduler.
 *
 * TODO: Make this more user friendly.
 */
function _media_derivatives_scheduler_time_ui() {
  $form = array();
  $form['scheduled_time'] = array(
    '#type' => 'textfield',
    '#title' => t('Timestamp'),
    '#description' => t('Unix timestamp of time when a derivation should be triggered.'),
  );
  return $form;
}

/**
 * Period scheduler callback.
 */
function _media_derivatives_scheduler_period($derivative) {
  return strtotime($derivative->preset->scheduler_settings['scheduled_period']);
}

/**
 * Preset configuration UI callback for period time scheduler.
 */
function _media_derivatives_scheduler_period_ui() {
  $form = array();
  $form['scheduled_period'] = array(
    '#type' => 'textfield',
    '#title' => t('Period'),
    '#description' => t('Enter period in PHP\'s <a href="!url">relative date format</a>.', array('!url' => 'http://www.php.net/manual/en/datetime.formats.relative.php')),
  );
  return $form;
}
