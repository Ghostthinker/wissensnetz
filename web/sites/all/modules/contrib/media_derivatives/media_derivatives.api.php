<?php

/**
 * @file
 *   Hooks specification.
 *
 * @author Janez Urevc <janez@janezurevc.name>
 */

/**
 * Returns engine information. Must return an array with
 * following data (keys):
 *
 *  - name: engine's human readable name
 *  - type: file type that engine handles,
 *  - mime_types (optional): array of supported mime types (use * for wildcard) -
 *  		all mime types will be supported if omitted,
 *  - stream_wrappers (optional): an array of supported sream wrappers -
 *  		all stream wrappers will be supported if omitted.
 */
function hook_media_derivatives_engine_info() {
  return array(
    'name' => t('Engine name'),
    'type' => 'video',
    'stream_wrappers' => array('public://', 'private://'),
  );
}

/**
 * Allows module to alter engines registry.
 */
function hook_media_derivatives_engine_info_alter($engines) {
  $engines['some_engine']['stream_wrappers'][] = 'youtube://';
}

/**
 * This is technically not hook, but a callback function. Every
 * derivate engine should implement this function to enable media encodings.
 *
 * Function should throw an istance of MediaDerivativesException if an error
 * occurs. Derivative's ID and error message should be passed with exception.
 *
 * @params $file
 * 	File to be used as the original (file object).
 *
 * @params $derivate
 * 	Derivate object. Settings can be found in $derivate->setings.
 *
 * @return string/file object
 * 	Derivate's URI or full file object ready to be saved to {file_managed}
 *  table. It is this function's responsibility to return unused and valid file URI.
 *
 * @see MediaDerivativesException()
 */
function hook_media_derivatives_create_derivate($file, $derivative) {
  $ffmpeg_path = variable_get('ffmpeg_path', '/usr/bin/ffmpeg');
  $new_file = 'public://' . $file->filename . '-derivate.mp4';

  $old_path = drupal_realpath($file->uri);
  $new_path = drupal_realpath($new_file);

  system($ffmpeg_path . ' -i ' . $path . ' ' . $new_path);

  // media_derivatives_set_progress() can be used if one runs
  // encoding process using background_process().
  // Check http://drupal.org/project/background_process
  media_derivatives_set_progress(0.5, t('Processing file example.mp4 ...'));

  return $new_file;
}

/**
 * This hook allows one to create media_derivate configuration presets.
 * Ctools export api is used to handle exporting, overriding, ...
 *
 * Preset is created by returning an array of preset objects. Each preset object
 * can have the following arguments:
 *
 *  - api_version: set it to 1, since there is currently only one API version
 *  - machine_name: machine name of your preset (must be unique)
 *  - settings: array of settings with following keys availible
 *    - user => derivate owner selection policy. Possible values:
 *    		- MEDIA_DERIVATIVE_OWNER_FILE - derivate will have the same owner as original file (default),
 *        - MEDIA_DERIVATIVE_OWNER_DERIVATIVE - user that triggered creation of derivate will also be it's owner,
 *        - MEDIA_DERIVATIVE_OWNER_STATIC - owner can be statically chosen.
 *    - user_uid => owner uid if 'user' was set to MEDIA_DERIVATIVE_OWNER_STATIC
 *    - recursive_delete: delete derivate if source file was deleted (defaults to FALSE)
 *    - delete_source: will delete source file when a derivative was sucessfully created (defaults to FALSE)
 *    - type: MEDIA_DERIVATIVES_FILE_TYPE_UNMANAGED or MEDIA_DERIVATIVES_FILE_TYPE_MANAGED, defines if a derivative should
 *            be a managed or unmanaged file, (defaults to MEDIA_DERIVATIVES_TYPE_UNMANAGED)
 *  - engine: engine name to be used to create derivatives
 *  - engine_settings: custom engine settings that will be passed to engine
 *  - scheduler: machine name of scheduler to be used with this preset; API itself implements 'scheduler_immediate',
 *               'scheduler_time'and 'scheduler_period'. Others may be implemented by other modules.
 *  - scheduler_settings: array of settings, used by scheduler (refer scheduler documentation)
 *  - conditions: array of conditions to be used with this preset. All conditions must return TRUE, if a derivative is to be created.
 *           API itself implements 'file_type', 'mime_type', 'stream_wrapper' and 'derivatives_of_derivatives'.
 *           Other conditions may be implemented by other modules.
 *  - conditions_settings: array of settings, used by conditions (refer condition documentation)
 *  - events: array of events that this preset reacts on. API itself implements 'file_insert' and 'field_presave'.
 *           Other events may be implemented by other modules.
 *  - events_settings: array of settings, used by event validators (refer events documentation)
 *
 * Before implementing this function one must implement hook_ctools_plugin_api().
 * Example (it can be simply copy-pased for most use cases):
 *
 * @code
 * function hook_ctools_plugin_api($owner, $api) {
 *   if ($owner == 'media_derivatives' && $api == 'media_derivatives_presets') {
 *     return array('version' => 1);
 *   }
 * }
 * @endcode
 *
 * @see hook_ctools_plugin_api()
 * @see hook_media_derivatives_conditions_info()
 * @see hook_media_derivatives_events_info()
 * @see hook_media_derivatives_schedulers_info()
 */
function hook_media_derivatives_presets() {
  $export = array();

  $preset = new stdClass;
  $preset->api_version = 1;
  $preset->machine_name = 'some_preset';
  $preset->engine = 'media_derivatives_ffmpeg_ex';
  $preset->engine_settings = array();
  $preset->scheduler = 'scheduler_immediate';
  $preset->scheduler_settings = array();
  $preset->conditions = array('file_type', 'mime_type', 'derivatives_of_derivatives');
  $preset->conditions_settings = array(
    'type' => 'video',
    'stream_wrappers' => array('public://', 'temporary://'),
  );
  $preset->events = array('field_presave', 'file_insert');
  $preset->events_settings = array(
    'field_presave_allowed_fields' => array('field_example'),
  );
  $preset->settings = array(
    'recursive_delete' => TRUE,
  );

  $export['example_preset'] = $preset;
  return $export;
}

/**
 * Inform Media derivatives API about field types that can store files. Hooks
 * must return array of field_type => fid_column pairs. Key represents field type
 * and value represents name of columnt where fid is stored.
 */
function hook_media_derivatives_field_types() {
  return array(
    'file' => 'fid',
    'media' => 'fid',
    'image' => 'fid',
  );
}

/**
 * Return info about derivation conditions implemented by a module.
 *
 * @return
 * Array of conditions, implemented by a module. Each element should contain the
 * following elements:
 *  - name: Human-readable name of a condition,
 *  - description: condition's long description,
 *  - callback: name of callback function that implements the condition. This function
 *              will recieve two arguments: source file object and preset object.
 *              Callback function should return TRUE, if file should be derivated
 *              by given preset and FALSE otherwise. Refer media_derivatives_type_support(),
 *              media_derivatives_mime_support(), media_derivatives_stream_support() and
 *              media_derivatives_derivative_support() as examples of condition callback functions.
 */
function hook_media_derivatives_conditions_info() {
  $conditions = array();
  $conditions['example_condition'] = array(
    'name' => t('Example derivation condition'),
    'description' => t('In-depth description of example condition'),
    'callback' => 'mymodule_mycondition_callback',
  );
  return $conditions;
}

/**
 * Alter hook that allows module to make changes to conditions registry.
 */
function hook_media_derivates_conditions_info_alter($conditions) {
  // Change condition callback function.
  $conditions['some_condition']['callback'] = 'mymodule_new_callback_function';
}


/**
 * Return info about derivation events implemented by a module.
 *
 * Module can event a derivation event by calling media_derivatives_create_all_derivatives($file, $event, $context)
 * (loads all presets and tries to create one derivative of a source file for each of them) or
 * media_derivatives_create_derivative($file, $preset, $event, $context) (tries to create only one derivative, using $preset),
 * where are:
 *   - $file: source file object
 *   - $event: events machine name
 *   - $context (optional): array of context variables that will be passed to event validation callback
 *   - $preset: preset to be used for derivation (used only with media_derivatives_create_derivative()).
 *
 * Refer media_derivatives_file_insert() as an implementation of a event.
 *
 * @return
 * Array of events, implemented by a module. Each element should contain the
 * following elements:
 *  - name: Human-readable name of the event,
 *  - description: event's long description,
 *  - validation_callbacks (optional): array of validation callbacks that need to be run when this event
 *  						happens. Each validation function will recieve three arguments: source file object,
 *              preset object and an array of context variables, passed by event.
 *              Validation function should return TRUE, if file derivation should be trigered
 *              and FALSE otherwise. Refer _media_derivatives_field_presave_validation() as an example
 *              of validation callback function.
 */
function hook_media_derivatives_events_info() {
  $events = array();
  $events['file_insert'] = array(
    'name' => t('File insert derivative event'),
    'description' => t('Derivative event that will be executed when a new file is saved.'),
    'validation_callbacks' => array(
      '_media_derivatives_file_insert_validation'
    ),
  );
  return $events;
}


/**
 * Alter hook that allows module to make changes to events registry.
 */
function hook_media_derivates_events_info_alter($events) {
  // Add another validation callback to some event.
  $events['some_event']['validation_callbacks'][] = 'mymodule_another_validation_callback';
}


/**
 * Return info about derivation schedulers implemented by a module.
 *
 * @return
 * Array of schedulers, implemented by a module. Each element should contain the
 * following elements:
 *  - name: Human-readable name of a scheduler,
 *  - description: scheduler's long description,
 *  - callback: name of callback function that implements the scheduler. This function
 *              will recieve derivative object as an argument.
 *              Callback function should return TRUE, if file should be derivated
 *              immediatley; UNIX timestamp, if a derivative should be scheduled for a future
 *              derivation or FALSE, if a derivative should not be processed yet (callback function
 *              will be called again at next cron).
 *
 *              Scheduler callback functions are called immediatley after derivative creation and at
 *              each cron run. If will be called until it returns TRUE or a UNIX timestamp.
 *
 *              Refer _media_derivatives_scheduler_immediate(), _media_derivatives_scheduler_time(),
 *              _media_derivatives_scheduler_period() as examples of scheduler callback functions.
 */
function hook_media_derivatives_schedulers_info() {
  $schedulers = array();
  $schedulers['example_scheduler'] = array(
    'name' => t('Example scheduler'),
    'description' => t('Dummy example scheduler.'),
    'callback' => '_media_derivatives_example_scheduler',
  );
  return $schedulers;
}

/**
 * Alter hook that allows module to make changes to schedulers registry.
 */
function hook_media_derivates_schedulers_info_alter($schedulers) {
  // Change callback function for some scheduler.
  $schedulers['some_scheduler']['callback'] = 'mymodule_custom_scheduler_callback';
}

/**
 * Acts on a new derivative before being inserted into database.
 *
 * @param $derivative Derivative object.
 */
function hook_media_derivatives_derivative_insert($derivative) {

}


/**
 * Acts on a new or existing derivative before being saved into database.
 *
 * @param $derivative Derivative object.
 */
function hook_media_derivatives_derivative_presave($derivative) {

}


/**
 * Acts on a derivative being loaded from database.
 *
 * @param $derivative Derivative object.
 */
function hook_media_derivatives_derivative_load($derivative) {

}


/**
 * Acts on a derivative after being sucessfully encoded.
 *
 * @param $derivative Derivative object.
 */
function hook_media_derivatives_derivative_postencode($derivative) {

}