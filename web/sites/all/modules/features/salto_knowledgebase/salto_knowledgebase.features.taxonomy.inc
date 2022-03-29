<?php

/**
 * @file
 * salto_knowledgebase.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function salto_knowledgebase_taxonomy_default_vocabularies() {
  return array(
    'post_tags' => array(
      'name' => 'Post Tags',
      'machine_name' => 'post_tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'wissensbasis_kategorien' => array(
      'name' => 'Wissensbasis-Kategorien',
      'machine_name' => 'wissensbasis_kategorien',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
