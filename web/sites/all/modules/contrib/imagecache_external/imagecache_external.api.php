<?php

/**
 * @file
 * Documentation of Imagecache External hooks.
 */

/**
 * Add custom image refresh logic.
 *
 * Use this hook to add extra validation(s) whether to refresh images.
 */
function hook_imagecache_external_needs_refresh_alter(&$needs_refresh, $filepath) {
  // Example: refresh images at least once a week.
  if (filemtime($filepath) > REQUEST_TIME - 60 * 60 * 24 * 7) {
    $needs_refresh = TRUE;
  }
}

/**
 * Add possibility to alter the directory.
 *
 * Use this hook to change the folder the images are stored in.
 */
function hook_imagecache_external_directory_alter(&$directory, $filename, $url) {
  // Example: create subfolders for the first two characters of the filename.
  $regex = '#(\w\w)#';
  preg_match($regex, $filename, $matches);
  if (!empty($matches[1])) {
    $directory = $directory . "/" . $matches[1];
  }
}
