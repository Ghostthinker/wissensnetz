<?php
/**
 * @file
 * salto_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function salto_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'use search_api_autocomplete for salto_search'.
  $permissions['use search_api_autocomplete for salto_search'] = array(
    'name' => 'use search_api_autocomplete for salto_search',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_autocomplete',
  );

  // Exported permission: 'use search_api_autocomplete for search_api_views_salto_search'.
  $permissions['use search_api_autocomplete for search_api_views_salto_search'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_salto_search',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_autocomplete',
  );

  // Exported permission: 'use search_api_autocomplete for search_api_views_salto_search_comment'.
  $permissions['use search_api_autocomplete for search_api_views_salto_search_comment'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_salto_search_comment',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_autocomplete',
  );

  // Exported permission: 'use search_api_autocomplete for search_api_views_salto_search_file'.
  $permissions['use search_api_autocomplete for search_api_views_salto_search_file'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_salto_search_file',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_autocomplete',
  );

  // Exported permission: 'use search_api_autocomplete for search_api_views_salto_search_node'.
  $permissions['use search_api_autocomplete for search_api_views_salto_search_node'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_salto_search_node',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_autocomplete',
  );

  return $permissions;
}
