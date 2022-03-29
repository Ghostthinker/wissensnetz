<?php

/**
 * @file
 * salto_organisation.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function salto_organisation_taxonomy_default_vocabularies() {
  return array(
    'organisation_responsibilities' => array(
      'name' => 'Responsibilities',
      'machine_name' => 'organisation_responsibilities',
      'description' => 'The Responsibilities of a person in an organisation',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 10,
    ),
  );
}
