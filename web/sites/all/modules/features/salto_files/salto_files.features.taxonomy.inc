<?php

/**
 * @file
 * salto_files.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function salto_files_taxonomy_default_vocabularies() {
  return array(
    'lehr_lern_material_kategorien' => array(
      'name' => 'Lehr-Lern-Material-Kategorien',
      'machine_name' => 'lehr_lern_material_kategorien',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
