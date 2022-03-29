<?php


/**
 * Implements hook_file_download().
 */
function salto_user_file_download($uri) {
  $files = file_load_multiple([], ['uri' => $uri]);
  foreach ($files as $file) {
    $usage = file_usage_list($file);
    if (isset($usage['imagefield_crop'])) {
      return [
        'Content-Type' => $file->filemime,
        'Content-Length' => $file->filesize,
      ];
    }
  }
}
