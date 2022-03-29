<?php

/**
 * Implements hook_file_access_records().
 *
 * Set grants for al file
 *
 * @param $file
 *
 * @return array
 */

function hook_file_access_records($file) {
  $grant = [
    'gid' => 0,
    'realm' => 'file_all',
    'grant_view' => 1,
    'grant_download' => 1,
    'grant_update' => 0,
    'grant_delete' => 0,
    'priority' => 0,
  ];

  $grants = [];
  $grants[] = $grant;
  return $grants;
}

/**
 * @param $grants
 *
 * @param $file
 *
 * @return mixed
 */
function hook_file_access_records_alter(&$grants, $file) {
  return $grants;
}

/**
 * Implements hook_file_grants().
 */
function hook_file_grants($account, $op) {
  $grants = [];

  if ($account->uid > 0) {
    $grants['file_all'] = $account->uid;
  }

  return $grants;
}
