<?php

/**
 * Implements hook_views_plugins().
 */
function salto_core_views_plugins() {
  return array(
    'module' => 'salto_core',
    'argument default' => array(
      'taxonomy_parent_tid' => array(
        'title' => t('Taxonomy parent term ID from URss'),
        'handler' => 'views_arg_parent_term_plugin_argument_default_parent_taxonomy_tid',
        'path' => drupal_get_path('module', 'salto_core') . '/inc',
        'parent' => 'fixed',
      ),
    ),
  );
}
