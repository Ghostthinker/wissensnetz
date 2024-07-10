<?php

function media_webresource_settings_page() {
  $form = array();

  $url2info_settings = media_webresource_service_get_url2info_settings();

  $form ['media_webresource_url2info_settings'] = [
    '#type' => 'fieldset',
    '#title' => t('Media webresource url2info settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  ];

  $form['media_webresource_url2info_settings']['url'] = array(
    '#type' => 'textfield',
    '#title' => t('Url'),
    '#default_value' => $url2info_settings['url'],
    '#description' => t("Url to get infos from an external websites"),
  );

  $form['media_webresource_url2info_settings']['proxy_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Image Proxy Url'),
    '#default_value' => $url2info_settings['proxy_url']
  );

  $form['media_webresource_url2info_settings']['proxy_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Image Proxy Secret'),
    '#default_value' => $url2info_settings['proxy_secret']
  );



  $form = system_settings_form($form);
  $form['#submit'][] = 'media_webresource_metadata_custom_submit';
  return $form;

}

/**
 * Custom submit handler for media derivatives document settings form.
 */
function media_webresource_metadata_custom_submit($form, &$form_state) {
  // Get the form values.
  $values = $form_state['values']['media_webresource_url2info_settings'];

  // Print the form values.
  drupal_set_message(t('URL: @url', [
    '@url' => $values['url'],
  ]));

  $pdfPreviewService = new \Wissensnetz\File\Url2InfoService();

  // Handle the result with drupal_set_message
  if ($pdfPreviewService->healthCheckUrl2Info()) {
    // If successful, show a success message
    drupal_set_message(t('The url2info service is healthy.'), 'status');
  } else {
    // If not successful, show an error message
    drupal_set_message(t('The url2info service is not available or encountered an error.'), 'error');
  }

  // Handle the result with drupal_set_message
  if ($pdfPreviewService->healthCheckProxy()) {
    // If successful, show a success message
    drupal_set_message(t('The image proxy is healthy.'), 'status');
  } else {
    // If not successful, show an error message
    drupal_set_message(t('The image proxy is not available or encountered an error.'), 'error');
  }
}
