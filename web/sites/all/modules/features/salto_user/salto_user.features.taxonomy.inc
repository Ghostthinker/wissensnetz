<?php
/**
 * @file
 * salto_user.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function salto_user_taxonomy_default_vocabularies() {
  return array(
    'profile_competencies' => array(
      'name' => 'competencies',
      'machine_name' => 'profile_competencies',
      'description' => 'The competencies of a person.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'profile_interests' => array(
      'name' => 'Interests',
      'machine_name' => 'profile_interests',
      'description' => 'The interests of a user.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'profile_sports' => array(
      'name' => 'Sports',
      'machine_name' => 'profile_sports',
      'description' => 'The sports of a user.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
