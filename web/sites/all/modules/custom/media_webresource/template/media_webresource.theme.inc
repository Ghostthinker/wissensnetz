<?php

/**
 * @file
 * Media_prezi/themes/media_prezi.theme.inc.
 *
 * Theme and preprocess functions for Media: Prezi.
 */

/**
 * Preprocess function for theme('media_prezi_presentation').
 */
function media_webresource_preprocess_media_webresource_youtube_player(&$variables) {

  // Add template variables for accessibility.
  $variables['title'] = check_plain($file_object->filename);
  $variables['width'] = $variables['options']['width'];
  $variables['height'] = $variables['options']['height'];

}