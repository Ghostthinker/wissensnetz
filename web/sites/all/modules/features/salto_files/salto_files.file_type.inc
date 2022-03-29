<?php

/**
 * @file
 * salto_files.file_type.inc
 */

/**
 * Implements hook_file_default_types().
 */
function salto_files_file_default_types() {
  $export = array();

  $file_type = new stdClass();
  $file_type->disabled = FALSE; /* Edit this to true to make a default file_type disabled initially */
  $file_type->api_version = 1;
  $file_type->type = 'swf';
  $file_type->label = 'Flash Film';
  $file_type->description = '';
  $file_type->mimetypes = array(
    0 => 'application/x-shockwave-flash',
  );
  $export['swf'] = $file_type;

  $file_type = new stdClass();
  $file_type->disabled = FALSE; /* Edit this to true to make a default file_type disabled initially */
  $file_type->api_version = 1;
  $file_type->type = 'webresource';
  $file_type->label = 'Webresource';
  $file_type->description = 'A generic web resource.';
  $file_type->mimetypes = array(
    0 => 'webresource/*',
  );
  $export['webresource'] = $file_type;

  return $export;
}
