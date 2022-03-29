<?php

/**
 * Implementation of hook_wysiwyg_plugin().
 */
function salto_files_wysiwyg_plugin($editor, $version) {
  if ($editor == 'ckeditor') {
    return array('media_widget' => array(
      'path' => drupal_get_path('module', 'media_widget') .'/plugins/media_widget/',
      'load' => TRUE,
      'extensions' => array('Link' => t('CKEditor Link')),
    ));
  }
}