<?php
/**
 * @file
 * Admin forms for this module.
 */

/**
 * Form builder.
 */
function imagecache_external_admin_form($form, $form_state) {
  $form = array();

  $form['imagecache_directory'] = array(
    '#type' => 'textfield',
    '#title' => t('Imagecache Directory'),
    '#required' => TRUE,
    '#description' => t('Where, withing the files directory, should the downloaded images be stored?'),
    '#default_value' => variable_get('imagecache_directory', 'externals'),
  );

  $form['imagecache_default_extension'] = array(
    '#type' => 'select',
    '#options' => array('' => 'none', '.jpg' => 'jpg', '.png' => 'png', '.gif' => 'gif', '.jpeg' => 'jpeg'),
    '#title' => t('Imagecache default extension'),
    '#required' => FALSE,
    '#description' => t('If no extension is provided by the external host, specify a default extension'),
    '#default_value' => variable_get('imagecache_default_extension', '.jpg'),
  );

  $form['imagecache_external_management'] = array(
    '#type' => 'radios',
    '#title' => t('How should Drupal handle the files?'),
    '#description' => t('Managed files can be re-used elsewhere on the site, for instance in the Media Library if you use the Media module. Unmanaged files are not saved to the database, but can be cached using Image Styles.'),
    '#options' => array(
      'unmanaged' => t('Unmanaged: Only save the images to the files folder to be able to cache them. This is  default.'),
      'managed' => t('Managed: Download the images and save its metadata to the database.'),
    ),
    '#default_value' => variable_get('imagecache_external_management', 'unmanaged'),
  );

  $form['imagecache_external_use_whitelist'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use whitelist'),
    '#description' => t('By default, all images are blocked except for images served from white-listed hosts. You can define hosts below.'),
    '#default_value' => variable_get('imagecache_external_use_whitelist', TRUE),
  );

  $form['imagecache_external_hosts'] = array(
    '#type' => 'textarea',
    '#title' => t('Imagecache External hosts'),
    '#description' => t('Add one host per line. You can use top-level domains to whitelist subdomains. Ex: staticflickr.com to whitelist farm1.staticflickr.com and farm2.staticflickr.com'),
    '#default_value' => variable_get('imagecache_external_hosts', ''),
    '#states' => array(
      'visible' => array(
        ':input[name="imagecache_external_use_whitelist"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['imagecache_fallback_image'] = array(
    '#type' => 'managed_file',
    '#name' => 'imagecache_fallback_image',
    '#title' => t('Fallback image'),
    '#description' => t("When an external image couldn't be found, use this image as a fallback."),
    '#default_value' => variable_get('imagecache_fallback_image', ''),
    '#upload_location' => 'public://'
  );

  return system_settings_form($form);
}

/**
 * Validate callback for the admin form.
 */
function imagecache_external_admin_form_validate($form, $form_state) {
  $scheme = file_default_scheme();
  $directory = $scheme . '://' . $form_state['values']['imagecache_directory'];
  if (!file_prepare_directory($directory, FILE_CREATE_DIRECTORY)) {
    form_set_error('imagecache_directory', t('The directory %directory does not exist or is not writable.', array('%directory' => $directory)));
    watchdog('imagecache_external', 'The directory %directory does not exist or is not writable.', array('%directory' => $directory), WATCHDOG_ERROR);
  }
}

/**
 * Form builder.
 */
function imagecache_external_flush_form($form, $form_state) {
  return confirm_form($form,
    t('Flush all external images?'),
    'admin/config/media/imagecache_external',
    t('Are you sure? This cannot be undone.'),
    t('Flush'),
    t('Cancel')
  );
}

/**
 * Submit handler.
 */
function imagecache_external_flush_form_submit($form, &$form_state) {
  if (imagecache_external_flush_cache()) {
    drupal_set_message(t('Flushed external images'));
  }
  else {
    drupal_set_message(t('Could not flush external images'), 'error');
  }
  $form_state['redirect'] = 'admin/config/media/imagecache_external';
}
