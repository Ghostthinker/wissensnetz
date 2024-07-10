<?php

function media_derivatives_document_settings_page() {
  $form = array();

  $document_preview_settings = media_derivatives_service_get_document_preview_settings();

  $form ['media_derivatives_document_settings'] = [
    '#type' => 'fieldset',
    '#title' => t('Media derivatives document preview settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  ];

  $form['media_derivatives_document_settings']['gotenberg_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Url'),
    '#default_value' => $document_preview_settings['gotenberg_url'],
    '#description' => t("Gotenberg Url to convert the document to a pdf"),
  );

  $form ['media_derivatives_document_settings']['pdf_to_image_url'] = array(
    '#type' => 'textfield',
    '#title' => t('PDF2Image url'),
    '#default_value' => $document_preview_settings['pdf_to_image_url'],
    '#description' => t('PDF2Image url to convert the pdf to an image')
  );
  $form = system_settings_form($form);
  $form['#submit'][] = 'media_derivatives_document_settings_custom_submit';
return $form;

}

/**
 * Custom submit handler for media derivatives document settings form.
 */
function media_derivatives_document_settings_custom_submit($form, &$form_state) {
  // Get the form values.
  $values = $form_state['values']['media_derivatives_document_settings'];

  // Print the form values.
  drupal_set_message(t('Gotenberg URL: @url, PDF2Image URL: @pdf_url', [
    '@url' => $values['gotenberg_url'],
    '@pdf_url' => $values['pdf_to_image_url'],
  ]));

  $pdfPreviewService = new \Wissensnetz\File\PdfPreviewService();

  // Handle the result with drupal_set_message
  if ($pdfPreviewService->healthCheckGotenberg()) {
    // If successful, show a success message
    drupal_set_message(t('The Gotenberg service is healthy.'), 'status');
  } else {
    // If not successful, show an error message
    drupal_set_message(t('The Gotenberg service is not available or encountered an error.'), 'error');
  }

  // Handle the result with drupal_set_message
  if ($pdfPreviewService->healthCheckPdfToImage()) {
    // If successful, show a success message
    drupal_set_message(t('The Pdf2image service is healthy.'), 'status');
  } else {
    // If not successful, show an error message
    drupal_set_message(t('The Pdf2image service is not available or encountered an error.'), 'error');
  }
}
