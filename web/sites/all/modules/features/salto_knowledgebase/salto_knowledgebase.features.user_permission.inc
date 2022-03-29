<?php

/**
 * @file
 * salto_knowledgebase.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function salto_knowledgebase_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'administer voting api'.
  $permissions['administer voting api'] = array(
    'name' => 'administer voting api',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'votingapi',
  );

  // Exported permission: 'clear leistungssport feeds'.
  $permissions['clear leistungssport feeds'] = array(
    'name' => 'clear leistungssport feeds',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'create feed content'.
  $permissions['create feed content'] = array(
    'name' => 'create feed content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create feed_item content'.
  $permissions['create feed_item content'] = array(
    'name' => 'create feed_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create post content'.
  $permissions['create post content'] = array(
    'name' => 'create post content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any feed content'.
  $permissions['delete any feed content'] = array(
    'name' => 'delete any feed content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any feed_item content'.
  $permissions['delete any feed_item content'] = array(
    'name' => 'delete any feed_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any post content'.
  $permissions['delete any post content'] = array(
    'name' => 'delete any post content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete knowledgebase categories'.
  $permissions['delete knowledgebase categories'] = array(
    'name' => 'delete knowledgebase categories',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
    ),
    'module' => 'salto_knowledgebase',
  );

  // Exported permission: 'delete own feed content'.
  $permissions['delete own feed content'] = array(
    'name' => 'delete own feed content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own feed_item content'.
  $permissions['delete own feed_item content'] = array(
    'name' => 'delete own feed_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own post content'.
  $permissions['delete own post content'] = array(
    'name' => 'delete own post content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in lehr_lern_material_kategorien'.
  $permissions['delete terms in lehr_lern_material_kategorien'] = array(
    'name' => 'delete terms in lehr_lern_material_kategorien',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in post_tags'.
  $permissions['delete terms in post_tags'] = array(
    'name' => 'delete terms in post_tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in wissensbasis_kategorien'.
  $permissions['delete terms in wissensbasis_kategorien'] = array(
    'name' => 'delete terms in wissensbasis_kategorien',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any feed content'.
  $permissions['edit any feed content'] = array(
    'name' => 'edit any feed content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any feed_item content'.
  $permissions['edit any feed_item content'] = array(
    'name' => 'edit any feed_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any post content'.
  $permissions['edit any post content'] = array(
    'name' => 'edit any post content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own feed content'.
  $permissions['edit own feed content'] = array(
    'name' => 'edit own feed content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own feed_item content'.
  $permissions['edit own feed_item content'] = array(
    'name' => 'edit own feed_item content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own post content'.
  $permissions['edit own post content'] = array(
    'name' => 'edit own post content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in lehr_lern_material_kategorien'.
  $permissions['edit terms in lehr_lern_material_kategorien'] = array(
    'name' => 'edit terms in lehr_lern_material_kategorien',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in post_tags'.
  $permissions['edit terms in post_tags'] = array(
    'name' => 'edit terms in post_tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in wissensbasis_kategorien'.
  $permissions['edit terms in wissensbasis_kategorien'] = array(
    'name' => 'edit terms in wissensbasis_kategorien',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'import leistungssport feeds'.
  $permissions['import leistungssport feeds'] = array(
    'name' => 'import leistungssport feeds',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'manage knowledgebase categories'.
  $permissions['manage knowledgebase categories'] = array(
    'name' => 'manage knowledgebase categories',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
    ),
    'module' => 'salto_knowledgebase',
  );

  // Exported permission: 'manage knowledgebase subcategories'.
  $permissions['manage knowledgebase subcategories'] = array(
    'name' => 'manage knowledgebase subcategories',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
    ),
    'module' => 'salto_knowledgebase',
  );

  // Exported permission: 'manage materials categories'.
  $permissions['manage materials categories'] = array(
    'name' => 'manage materials categories',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
    ),
    'module' => 'salto_knowledgebase',
  );

  // Exported permission: 'rate content'.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fivestar',
  );

  // Exported permission: 'unlock leistungssport feeds'.
  $permissions['unlock leistungssport feeds'] = array(
    'name' => 'unlock leistungssport feeds',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'feeds',
  );

  return $permissions;
}
