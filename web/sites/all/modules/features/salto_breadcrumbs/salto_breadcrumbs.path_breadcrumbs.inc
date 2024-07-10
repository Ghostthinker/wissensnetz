<?php

/**
 * @file
 * salto_breadcrumbs.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function salto_breadcrumbs_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'beitraege_node_add';
  $path_breadcrumb->name = 'Beiträge: Node Add';
  $path_breadcrumb->path = 'node/add/post';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Beiträge',
    ),
    'paths' => array(
      0 => 'posts',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -29;
  $export['beitraege_node_add'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'beitraege_node_edit';
  $path_breadcrumb->name = 'Beiträge: Node Edit';
  $path_breadcrumb->path = 'node/%node/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Beiträge',
    ),
    'paths' => array(
      0 => 'posts',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Beitrag: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'post' => 'post',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -32;
  $export['beitraege_node_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'beitraege_node_view';
  $path_breadcrumb->name = 'Beiträge: Node View';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Beiträge',
      1 => '%node:field-og-group:title',
    ),
    'paths' => array(
      0 => 'posts',
      1 => 'node/%node:field-og-group:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Beitrag: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'post' => 'post',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -31;
  $export['beitraege_node_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'beitraege_node_view_in_group';
  $path_breadcrumb->name = 'Beiträge: Node View in Gruppe';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:field-og-group:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:field-og-group:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if node is OG Content',
            'php' => '$node = $contexts[\'node\']->data;
if (isset($node ->field_og_group[LANGUAGE_NONE][0][\'target_id\'])) {
 return true ;
}
return  false;
',
          ),
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'post' => 'post',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -34;
  $export['beitraege_node_view_in_group'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'beitraege_overview';
  $path_breadcrumb->name = 'Beiträge: Übersicht';
  $path_breadcrumb->path = 'posts/%term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Beiträge',
    ),
    'paths' => array(
      0 => 'posts',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'term' => array(
        'position' => 1,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            7 => '7',
            2 => 0,
            1 => 0,
            6 => 0,
            8 => 0,
            4 => 0,
            3 => 0,
            5 => 0,
          ),
          'breadcrumb' => 1,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -30;
  $export['beitraege_overview'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'category_assign';
  $path_breadcrumb->name = 'Category assign';
  $path_breadcrumb->path = 'category/assign/%type/%eid';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Startseite',
    ),
    'paths' => array(
      0 => '<front>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'type' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Zeichenkette',
        ),
      ),
      'eid' => array(
        'position' => 3,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Zeichenkette',
          'use_tail' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -25;
  $export['category_assign'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'dosb_licenses_all';
  $path_breadcrumb->name = 'DOSB Licenses all';
  $path_breadcrumb->path = 'licenses/all';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
    ),
    'paths' => array(
      0 => 'licenses',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -26;
  $export['dosb_licenses_all'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'dosb_licenses_all_stats';
  $path_breadcrumb->name = 'DOSB Licenses all stats';
  $path_breadcrumb->path = 'licenses/all/statistics';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
    ),
    'paths' => array(
      0 => 'licenses',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -26;
  $export['dosb_licenses_all_stats'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'file_add_in_group';
  $path_breadcrumb->name = 'file add: in group';
  $path_breadcrumb->path = 'file/add_anything';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
    ),
    'paths' => array(
      0 => 'groups',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        1 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Group context',
            'php' => 'if(!empty($_GET[\'field_og_group\'])) {
  return TRUE;
}
return FALSE;',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -88;
  $export['file_add_in_group'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'file_edit_in_group';
  $path_breadcrumb->name = 'File Edit in Group';
  $path_breadcrumb->path = 'file/%file/edit/%ref';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%ref:field-og-group:title',
      2 => '%file:name',
      3 => '%ref:title',
      4 => 'Anhänge',
    ),
    'paths' => array(
      0 => 'groups',
      1 => '%ref:field-og-group:url',
      2 => 'file/%file:fid/edit/%ref:nid',
      3 => 'node/%ref:nid',
      4 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'file' => array(
        'position' => 1,
        'argument' => 'entity_id:file',
        'settings' => array(
          'identifier' => 'Datei: ID',
        ),
      ),
      'ref' => array(
        'position' => 3,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Beitrag: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -99;
  $export['file_edit_in_group'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'files';
  $path_breadcrumb->name = 'Files';
  $path_breadcrumb->path = 'file/%file';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Materialien',
    ),
    'paths' => array(
      0 => 'materials',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'file' => array(
        'position' => 1,
        'argument' => 'entity_id:file',
        'settings' => array(
          'identifier' => 'File: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -72;
  $export['files'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'files_attachments';
  $path_breadcrumb->name = 'Files - Attachments';
  $path_breadcrumb->path = 'file/%file/%ref';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
      1 => '%ref:book:pb-join:name',
      2 => '%ref:title',
      3 => 'Anhänge',
    ),
    'paths' => array(
      0 => 'knowledge',
      1 => '%ref:book:pb-join:url',
      2 => 'node/%ref:nid',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'file' => array(
        'position' => 1,
        'argument' => 'entity_id:file',
        'settings' => array(
          'identifier' => 'File: ID',
        ),
      ),
      'ref' => array(
        'position' => 2,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kb_article' => 'kb_article',
            ),
          ),
          'context' => 'ref',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -68;
  $export['files_attachments'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'files_attachments_edit';
  $path_breadcrumb->name = 'Files - Attachments - Edit';
  $path_breadcrumb->path = 'file/%file/edit/%ref';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
      1 => '%ref:book:pb-join:name',
      2 => 'Anhänge',
    ),
    'paths' => array(
      0 => 'knowledge',
      1 => '%ref:book:pb-join:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'file' => array(
        'position' => 1,
        'argument' => 'entity_id:file',
        'settings' => array(
          'identifier' => 'File: ID',
        ),
      ),
      'ref' => array(
        'position' => 3,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kb_article' => 'kb_article',
            ),
          ),
          'context' => 'ref',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -67;
  $export['files_attachments_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'files_attachments_experience';
  $path_breadcrumb->name = 'Files - Attachments - Erfahrungsberichte';
  $path_breadcrumb->path = 'file/%file/%ref';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
      1 => 'Erfahrungsberichte',
      2 => '%ref:title',
      3 => 'Anhänge',
    ),
    'paths' => array(
      0 => 'knowledge',
      1 => 'knowledge/experience',
      2 => 'node/%ref:nid',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'file' => array(
        'position' => 1,
        'argument' => 'entity_id:file',
        'settings' => array(
          'identifier' => 'File: ID',
        ),
      ),
      'ref' => array(
        'position' => 2,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kb_report' => 'kb_report',
            ),
          ),
          'context' => 'ref',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -66;
  $export['files_attachments_experience'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'files_attachments_experience_edit';
  $path_breadcrumb->name = 'Files - Attachments - Erfahrungsberichte - Edit';
  $path_breadcrumb->path = 'file/%file/edit/%ref';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
      1 => 'Erfahrungsberichte',
      2 => '%ref:title',
      3 => 'Anhänge',
    ),
    'paths' => array(
      0 => 'knowledge',
      1 => 'knowledge/experience',
      2 => 'node/%ref:nid',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'file' => array(
        'position' => 1,
        'argument' => 'entity_id:file',
        'settings' => array(
          'identifier' => 'File: ID',
        ),
      ),
      'ref' => array(
        'position' => 3,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kb_report' => 'kb_report',
            ),
          ),
          'context' => 'ref',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -65;
  $export['files_attachments_experience_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'files_attachments_questions';
  $path_breadcrumb->name = 'Files - Attachments - Fragen';
  $path_breadcrumb->path = 'file/%file/%ref';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
      1 => 'Fragen',
      2 => '%ref:title',
      3 => 'Anhänge',
    ),
    'paths' => array(
      0 => 'knowledge',
      1 => 'knowledge/questions',
      2 => 'node/%ref:nid',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'file' => array(
        'position' => 1,
        'argument' => 'entity_id:file',
        'settings' => array(
          'identifier' => 'File: ID',
        ),
      ),
      'ref' => array(
        'position' => 2,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kb_question' => 'kb_question',
            ),
          ),
          'context' => 'ref',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -64;
  $export['files_attachments_questions'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'files_attachments_questions_edit';
  $path_breadcrumb->name = 'Files - Attachments - Fragen - Edit';
  $path_breadcrumb->path = 'file/%file/edit/%ref';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
      1 => 'Fragen',
      2 => '%ref:title',
      3 => 'Anhänge',
    ),
    'paths' => array(
      0 => 'knowledge',
      1 => 'knowledge/questions',
      2 => 'node/%ref:nid',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'file' => array(
        'position' => 1,
        'argument' => 'entity_id:file',
        'settings' => array(
          'identifier' => 'File: ID',
        ),
      ),
      'ref' => array(
        'position' => 3,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kb_question' => 'kb_question',
            ),
          ),
          'context' => 'ref',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -60;
  $export['files_attachments_questions_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'files_clone';
  $path_breadcrumb->name = 'Files in group';
  $path_breadcrumb->path = 'file/%file';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%file:field-og-group:title',
      2 => 'Dateien',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%file:field-og-group:nid',
      2 => 'groups/%file:field-og-group:nid/files/term',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'file' => array(
        'position' => 1,
        'argument' => 'entity_id:file',
        'settings' => array(
          'identifier' => 'File: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if node is OG Content',
            'php' => '$file= $contexts[\'file\']->data;
if (isset($file->field_og_group[LANGUAGE_NONE][0][\'target_id\'])) {
 return true ;
}
else{
return  false;
}',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -71;
  $export['files_clone'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'files_group';
  $path_breadcrumb->name = 'Files in Group';
  $path_breadcrumb->path = 'file/%file/%ref';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%ref:field-og-group:title',
      2 => '%ref:title',
      3 => 'Anhänge',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%ref:field-og-group:nid',
      2 => 'node/%ref:nid',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'file' => array(
        'position' => 1,
        'argument' => 'entity_id:file',
        'settings' => array(
          'identifier' => 'File: ID',
        ),
      ),
      'ref' => array(
        'position' => 2,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Beitrag: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => '',
            'php' => '$node = $contexts[\'ref\']->data;
if (isset($node ->field_og_group[LANGUAGE_NONE][0][\'target_id\'])) {
 return true ;
}
return  false;
',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -70;
  $export['files_group'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_categories';
  $path_breadcrumb->name = 'Group Categories';
  $path_breadcrumb->path = 'groups/%node/category';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -79;
  $export['group_categories'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_content';
  $path_breadcrumb->name = 'Group Content';
  $path_breadcrumb->path = 'groups/%node/posts/%term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
      'term' => array(
        'position' => 3,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            2 => 0,
            10 => 0,
            1 => 0,
            15 => 0,
            18 => 0,
            19 => 0,
            20 => 0,
            21 => 0,
            22 => 0,
            23 => 0,
            6 => 0,
            8 => 0,
            4 => 0,
            3 => 0,
            5 => 0,
            11 => 0,
            7 => 0,
          ),
          'breadcrumb' => 0,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -80;
  $export['group_content'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_edit';
  $path_breadcrumb->name = 'Group: Edit';
  $path_breadcrumb->path = 'node/%node/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'group' => 'group',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -94;
  $export['group_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_file_download';
  $path_breadcrumb->name = 'Group File Download';
  $path_breadcrumb->path = 'groups/%node/files/download';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
      2 => 'Download',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
      2 => 'groups/%node:nid/files/download',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['group_file_download'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_file_edit';
  $path_breadcrumb->name = 'Group File Edit';
  $path_breadcrumb->path = 'groups/%node/files/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
      2 => 'Edit',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
      2 => 'groups/%node:nid/files/edit',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['group_file_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_files';
  $path_breadcrumb->name = 'Group Files';
  $path_breadcrumb->path = 'groups/%node/files/term/%term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
      'term' => array(
        'position' => 4,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vocabularies' => array(
            'ea_sport' => 0,
            'ea_training_course' => 0,
            'ea_profile' => 0,
            'ea_discipline' => 0,
            'ea_focus' => 0,
            'profile_competencies' => 0,
            'profile_interests' => 0,
            'lehr_lern_material_kategorien' => 0,
            'post_tags' => 0,
            'profile_sports' => 0,
            'group_category_1836' => 0,
            'group_category_1843' => 0,
            'group_category_1937' => 0,
            'group_category_1946' => 0,
            'group_category_2092' => 0,
            'group_category_2095' => 0,
            'group_category_2103' => 0,
            'group_category_2158' => 0,
            'group_category_2181' => 0,
            'group_category_2193' => 0,
            'group_category_2194' => 0,
            'group_category_2232' => 0,
            'group_category_2233' => 0,
            'group_category_2247' => 0,
            'group_category_2248' => 0,
            'group_category_2249' => 0,
            'group_category_2260' => 0,
            'group_category_2268' => 0,
            'group_category_2323' => 0,
            'group_category_2326' => 0,
            'group_category_2327' => 0,
            'group_category_2328' => 0,
            'group_category_2333' => 0,
            'group_category_2337' => 0,
            'group_category_2351' => 0,
            'group_category_2432' => 0,
            'group_category_2484' => 0,
            'group_category_2491' => 0,
            'group_category_2511' => 0,
            'group_category_2541' => 0,
            'group_category_2542' => 0,
            'group_category_2570' => 0,
            'group_category_2583' => 0,
            'group_category_2614' => 0,
            'group_category_2633' => 0,
            'group_category_2712' => 0,
            'group_category_2713' => 0,
            'group_category_2737' => 0,
            'group_category_2738' => 0,
            'group_category_2763' => 0,
            'group_category_2764' => 0,
            'group_category_2816' => 0,
            'group_category_2914' => 0,
            'group_category_2965' => 0,
            'group_category_3002' => 0,
            'group_category_3042' => 0,
            'group_category_3185' => 0,
            'group_category_3231' => 0,
            'group_category_3247' => 0,
            'group_category_3273' => 0,
            'group_category_3496' => 0,
            'group_category_3569' => 0,
            'group_category_3596' => 0,
            'group_category_3648' => 0,
            'group_category_5379' => 0,
            'group_category_5564' => 0,
            'group_category_5568' => 0,
            'group_category_5856' => 0,
            'group_category_5857' => 0,
            'group_category_7715' => 0,
            'group_category_7719' => 0,
            'group_category_8270' => 0,
            'group_category_8339' => 0,
            'group_category_8572' => 0,
            'group_category_10280' => 0,
            'group_category_10724' => 0,
            'group_category_materials_1836' => 0,
            'group_category_materials_1843' => 0,
            'group_category_materials_1937' => 0,
            'group_category_materials_1946' => 0,
            'group_category_materials_2092' => 0,
            'group_category_materials_2095' => 0,
            'group_category_materials_2103' => 0,
            'group_category_materials_2158' => 0,
            'group_category_materials_2181' => 0,
            'group_category_materials_2194' => 0,
            'group_category_materials_2233' => 0,
            'group_category_materials_2247' => 0,
            'group_category_materials_2248' => 0,
            'group_category_materials_2249' => 0,
            'group_category_materials_2260' => 0,
            'group_category_materials_2268' => 0,
            'group_category_materials_2323' => 0,
            'group_category_materials_2333' => 0,
            'group_category_materials_2337' => 0,
            'group_category_materials_2351' => 0,
            'group_category_materials_2432' => 0,
            'group_category_materials_2484' => 0,
            'group_category_materials_2491' => 0,
            'group_category_materials_2511' => 0,
            'group_category_materials_2542' => 0,
            'group_category_materials_2570' => 0,
            'group_category_materials_2583' => 0,
            'group_category_materials_2614' => 0,
            'group_category_materials_2633' => 0,
            'group_category_materials_2712' => 0,
            'group_category_materials_2713' => 0,
            'group_category_materials_2763' => 0,
            'group_category_materials_2816' => 0,
            'group_category_materials_2914' => 0,
            'group_category_materials_2965' => 0,
            'group_category_materials_3002' => 0,
            'group_category_materials_3042' => 0,
            'group_category_materials_3185' => 0,
            'group_category_materials_3231' => 0,
            'group_category_materials_3247' => 0,
            'group_category_materials_3273' => 0,
            'group_category_materials_3496' => 0,
            'group_category_materials_3569' => 0,
            'group_category_materials_3596' => 0,
            'group_category_materials_3648' => 0,
            'group_category_materials_5379' => 0,
            'group_category_materials_5564' => 0,
            'group_category_materials_5568' => 0,
            'group_category_materials_5857' => 0,
            'group_category_materials_7715' => 0,
            'group_category_materials_7719' => 0,
            'group_category_materials_8270' => 0,
            'group_category_materials_8339' => 0,
            'group_category_materials_8572' => 0,
            'group_category_materials_10280' => 0,
            'group_category_materials_10724' => 0,
            'tags' => 0,
            'wissensbasis_kategorien' => 0,
            'organisation_responsibilities' => 0,
          ),
          'breadcrumb' => 0,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -78;
  $export['group_files'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_files_overview';
  $path_breadcrumb->name = 'Group Files Overview';
  $path_breadcrumb->path = 'groups/%node/files/term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -82;
  $export['group_files_overview'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_invite_add';
  $path_breadcrumb->name = 'Group  Invite';
  $path_breadcrumb->path = 'groups/%node/people/invite';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
      2 => 'Personen',
    ),
    'paths' => array(
      0 => 'groups',
      1 => '%node:url',
      2 => 'groups/%node:nid/people',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'group' => 'group',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -62;
  $export['group_invite_add'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_memebrship_cancel';
  $path_breadcrumb->name = 'Group Membership Cancelation';
  $path_breadcrumb->path = 'groups/%node/people/remove/%user';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
      2 => 'Personen',
    ),
    'paths' => array(
      0 => 'groups',
      1 => '%node:url',
      2 => 'groups/%node:nid/people',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
      'user' => array(
        'position' => 4,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Benutzer: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'group' => 'group',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -63;
  $export['group_memebrship_cancel'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_people';
  $path_breadcrumb->name = 'Group People';
  $path_breadcrumb->path = 'groups/%node/people';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -83;
  $export['group_people'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'group_shared';
  $path_breadcrumb->name = 'Group Shared';
  $path_breadcrumb->path = 'groups/%node/shared';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -81;
  $export['group_shared'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'groups';
  $path_breadcrumb->name = 'Groups';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'group' => 'group',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -96;
  $export['groups'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'groups_info';
  $path_breadcrumb->name = 'Groups Info';
  $path_breadcrumb->path = 'node/%node/info';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'group' => 'group',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -95;
  $export['groups_info'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'knowledgebase_dosb_category_add';
  $path_breadcrumb->name = 'Knowledgebase DOSB Kategorie hinzufügen';
  $path_breadcrumb->path = 'knowledge/files/category/add';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
      1 => 'Materialien',
    ),
    'paths' => array(
      0 => 'knowledge',
      1 => 'knowledge/files',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -37;
  $export['knowledgebase_dosb_category_add'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'knowledgebase_dosb_category_edit';
  $path_breadcrumb->name = 'Knowledgebase DOSB Kategorie bearbeiten';
  $path_breadcrumb->path = 'knowledge/files/category/%taxonomy_term/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
      1 => 'Materialien',
    ),
    'paths' => array(
      0 => 'knowledge',
      1 => 'knowledge/files',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'taxonomy_term' => array(
        'position' => 3,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            6 => '6',
            2 => 0,
            1 => 0,
            4 => 0,
            3 => 0,
            5 => 0,
          ),
          'breadcrumb' => 0,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -42;
  $export['knowledgebase_dosb_category_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'knowledgebase_dosb_category_overview';
  $path_breadcrumb->name = 'Knowledgebase DOSB Kategorie Übersicht';
  $path_breadcrumb->path = 'knowledge/files/category';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
      1 => 'Materialien',
    ),
    'paths' => array(
      0 => 'knowledge',
      1 => 'knowledge/files',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -39;
  $export['knowledgebase_dosb_category_overview'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'knowledgebase_dosb_category_overview_clone';
  $path_breadcrumb->name = 'Knowledgebase DOSB Kategorie hinzufügen';
  $path_breadcrumb->path = 'knowledge/files/category/add';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
      1 => 'Materialien',
    ),
    'paths' => array(
      0 => 'knowledge',
      1 => 'knowledge/files',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -38;
  $export['knowledgebase_dosb_category_overview_clone'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'knowledgebase_dosb_content_category_add';
  $path_breadcrumb->name = 'Knowledgebase DOSB Beitragskategorie hinzufügen';
  $path_breadcrumb->path = 'knowledge/content/category/add';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
      1 => 'Kategorien verwalten',
    ),
    'paths' => array(
      0 => 'knowledge',
      1 => 'knowledge/content/category',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -36;
  $export['knowledgebase_dosb_content_category_add'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'knowledgebase_dosb_content_category_overview';
  $path_breadcrumb->name = 'Knowledgebase DOSB Beitragskategorie Übersicht';
  $path_breadcrumb->path = 'knowledge/content/category';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
    ),
    'paths' => array(
      0 => 'knowledge',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -41;
  $export['knowledgebase_dosb_content_category_overview'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'knowledgebase_dosb_content_overview';
  $path_breadcrumb->name = 'Knowledgebase DOSB Beiträge Übersicht';
  $path_breadcrumb->path = 'knowledge/content';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
    ),
    'paths' => array(
      0 => 'knowledge',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -40;
  $export['knowledgebase_dosb_content_overview'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'knowledgebase_files_overview';
  $path_breadcrumb->name = 'Knowledgebase Files Overview';
  $path_breadcrumb->path = 'knowledge/files';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
    ),
    'paths' => array(
      0 => 'knowledge',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -75;
  $export['knowledgebase_files_overview'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'knowledgebase_node_add';
  $path_breadcrumb->name = 'Knowledgebase Node Add';
  $path_breadcrumb->path = 'node/add/%type';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Wissensbasis',
    ),
    'paths' => array(
      0 => 'knowledge',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'type' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
          'use_tail' => 0,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => 'regex',
            'value' => '@(kb\\-question|kb\\-article|kb\\-report)@',
            'case' => 0,
          ),
          'context' => 'type',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -77;
  $export['knowledgebase_node_add'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'knowledgebase_upload_file_multiple';
  $path_breadcrumb->name = 'Files multiple upload';
  $path_breadcrumb->path = 'admin/content/file/edit-multiple/%file';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Materialien',
    ),
    'paths' => array(
      0 => 'materials',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'file' => array(
        'position' => 4,
        'argument' => 'entity_id:file',
        'settings' => array(
          'identifier' => 'Datei: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -58;
  $export['knowledgebase_upload_file_multiple'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'license_ausbildungsgang';
  $path_breadcrumb->name = 'Lizenz Ausbildungsgang';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
      1 => 'Ausbildungsgänge',
    ),
    'paths' => array(
      0 => 'licenses',
      1 => 'licenses/ea',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'earemote' => 'earemote',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -76;
  $export['license_ausbildungsgang'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'license_ausbildungskonzept';
  $path_breadcrumb->name = 'Lizenz Ausbildungskonzept';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
      1 => '%node:field-educoncept-organisation',
    ),
    'paths' => array(
      0 => 'licenses',
      1 => 'node/%node:field-educoncept-organisation:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'ausbildungskonzept' => 'ausbildungskonzept',
            ),
          ),
          'context' => 'nid',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -93;
  $export['license_ausbildungskonzept'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'license_ausbildungskonzept_edit';
  $path_breadcrumb->name = 'Lizenz Ausbildungskonzept Edit';
  $path_breadcrumb->path = 'node/%node/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
      1 => '%node:field-educoncept-organisation',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => 'licenses',
      1 => 'node/%node:field-educoncept-organisation:nid',
      2 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'ausbildungskonzept' => 'ausbildungskonzept',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -87;
  $export['license_ausbildungskonzept_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'license_node_add';
  $path_breadcrumb->name = 'Lizenz Node Add';
  $path_breadcrumb->path = 'node/add/%type';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
    ),
    'paths' => array(
      0 => 'licenses',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'type' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
          'use_tail' => 0,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => 'regex',
            'value' => '@(ausbildungskonzept|weiterbildungsmassnahme)@',
            'case' => 0,
          ),
          'context' => 'type',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Organisation Context',
            'php' => 'if(!empty($_GET[\'field_educoncept_organisation\']) || !empty($_GET[\'field_wbm_organisation\'])) {
  return TRUE;
}
return FALSE;',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -84;
  $export['license_node_add'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'license_view';
  $path_breadcrumb->name = 'Lizenz Ansicht';
  $path_breadcrumb->path = 'dosb_license/%license';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
      1 => '%license:wbm:field-wbm-organisation',
      2 => 'Lehrgänge',
      3 => '%license:wbm:title',
    ),
    'paths' => array(
      0 => 'licenses',
      1 => '<none>',
      2 => 'licenses/%license:wbm:field-wbm-organisation:nid',
      3 => 'node/%license:wbm:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'license' => array(
        'position' => 1,
        'argument' => 'entity_id:dosb_license',
        'settings' => array(
          'identifier' => 'DOSB license: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -90;
  $export['license_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'license_wbm';
  $path_breadcrumb->name = 'Lizenz Lehrgang';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
      1 => '%node:field-wbm-organisation',
      2 => 'Lehrgänge',
    ),
    'paths' => array(
      0 => 'licenses',
      1 => '<none>',
      2 => 'licenses/%node:field-wbm-organisation:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'weiterbildungsmassnahme' => 'weiterbildungsmassnahme',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -91;
  $export['license_wbm'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'license_wbm_import';
  $path_breadcrumb->name = 'Lizenz Lehrgang Import';
  $path_breadcrumb->path = 'node/%node/import_licenses';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
      1 => '%node:field-wbm-organisation',
      2 => 'Lehrgänge',
      3 => '%node:title',
    ),
    'paths' => array(
      0 => 'licenses',
      1 => '<none>',
      2 => 'licenses/%node:field-wbm-organisation:nid',
      3 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'weiterbildungsmassnahme' => 'weiterbildungsmassnahme',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -92;
  $export['license_wbm_import'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'materials_download';
  $path_breadcrumb->name = 'Materials Download';
  $path_breadcrumb->path = 'materials/download/%taxonomy_term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Materials',
      1 => 'Download',
    ),
    'paths' => array(
      0 => 'materials',
      1 => 'materials/download',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'taxonomy_term' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vocabularies' => array(
            'ea_sport' => 0,
            'ea_training_course' => 0,
            'ea_profile' => 0,
            'ea_discipline' => 0,
            'ea_focus' => 0,
            'profile_competencies' => 0,
            'profile_interests' => 0,
            'lehr_lern_material_kategorien' => 0,
            'post_tags' => 0,
            'profile_sports' => 0,
            'group_category_materials_38380' => 0,
            'group_category_86910' => 0,
            'group_category_38466' => 0,
            'group_category_materials_38466' => 0,
            'group_category_materials_86910' => 0,
            'group_category_38476' => 0,
            'group_category_materials_38476' => 0,
            'group_category_87072' => 0,
            'group_category_38561' => 0,
            'group_category_materials_38561' => 0,
            'group_category_materials_87072' => 0,
            'group_category_38808' => 0,
            'group_category_87216' => 0,
            'group_category_materials_38808' => 0,
            'group_category_materials_87216' => 0,
            'group_category_1836' => 0,
            'group_category_38875' => 0,
            'group_category_87217' => 0,
            'group_category_1843' => 0,
            'group_category_materials_38875' => 0,
            'group_category_materials_87217' => 0,
            'group_category_1937' => 0,
            'group_category_39210' => 0,
            'group_category_87218' => 0,
            'group_category_1946' => 0,
            'group_category_materials_39210' => 0,
            'group_category_materials_87218' => 0,
            'group_category_2092' => 0,
            'group_category_39245' => 0,
            'group_category_87219' => 0,
            'group_category_2095' => 0,
            'group_category_materials_39245' => 0,
            'group_category_materials_87219' => 0,
            'group_category_2103' => 0,
            'group_category_39256' => 0,
            'group_category_87221' => 0,
            'group_category_2158' => 0,
            'group_category_materials_39256' => 0,
            'group_category_materials_87221' => 0,
            'group_category_2181' => 0,
            'group_category_39534' => 0,
            'group_category_87222' => 0,
            'group_category_2193' => 0,
            'group_category_materials_39534' => 0,
            'group_category_materials_87222' => 0,
            'group_category_2194' => 0,
            'group_category_39547' => 0,
            'group_category_87224' => 0,
            'group_category_2232' => 0,
            'group_category_materials_39547' => 0,
            'group_category_materials_87224' => 0,
            'group_category_2233' => 0,
            'group_category_39771' => 0,
            'group_category_87225' => 0,
            'group_category_2247' => 0,
            'group_category_materials_39771' => 0,
            'group_category_materials_87225' => 0,
            'group_category_2248' => 0,
            'group_category_39844' => 0,
            'group_category_87226' => 0,
            'group_category_2249' => 0,
            'group_category_materials_39844' => 0,
            'group_category_materials_87226' => 0,
            'group_category_2260' => 0,
            'group_category_39952' => 0,
            'group_category_87227' => 0,
            'group_category_2268' => 0,
            'group_category_materials_39952' => 0,
            'group_category_materials_87227' => 0,
            'group_category_2323' => 0,
            'group_category_39960' => 0,
            'group_category_87229' => 0,
            'group_category_2326' => 0,
            'group_category_materials_39960' => 0,
            'group_category_materials_87229' => 0,
            'group_category_2327' => 0,
            'group_category_87230' => 0,
            'group_category_2328' => 0,
            'group_category_39962' => 0,
            'group_category_materials_87230' => 0,
            'group_category_2333' => 0,
            'group_category_materials_39962' => 0,
            'group_category_87232' => 0,
            'group_category_2337' => 0,
            'group_category_40017' => 0,
            'group_category_materials_87232' => 0,
            'group_category_2351' => 0,
            'group_category_materials_40017' => 0,
            'group_category_87235' => 0,
            'group_category_2432' => 0,
            'group_category_40132' => 0,
            'group_category_materials_87235' => 0,
            'group_category_2484' => 0,
            'group_category_materials_40132' => 0,
            'group_category_87240' => 0,
            'group_category_2491' => 0,
            'group_category_40682' => 0,
            'group_category_materials_87240' => 0,
            'group_category_2511' => 0,
            'group_category_materials_40682' => 0,
            'group_category_87242' => 0,
            'group_category_2541' => 0,
            'group_category_40956' => 0,
            'group_category_materials_87242' => 0,
            'group_category_2542' => 0,
            'group_category_materials_40956' => 0,
            'group_category_87244' => 0,
            'group_category_2570' => 0,
            'group_category_40996' => 0,
            'group_category_materials_87244' => 0,
            'group_category_2583' => 0,
            'group_category_materials_40996' => 0,
            'group_category_87246' => 0,
            'group_category_2614' => 0,
            'group_category_41018' => 0,
            'group_category_materials_87246' => 0,
            'group_category_materials_41018' => 0,
            'group_category_87248' => 0,
            'group_category_41019' => 0,
            'group_category_materials_87248' => 0,
            'group_category_materials_41019' => 0,
            'group_category_87250' => 0,
            'group_category_41039' => 0,
            'group_category_materials_87250' => 0,
            'group_category_2633' => 0,
            'group_category_materials_41039' => 0,
            'group_category_87252' => 0,
            'group_category_2712' => 0,
            'group_category_41069' => 0,
            'group_category_materials_87252' => 0,
            'group_category_2713' => 0,
            'group_category_materials_41069' => 0,
            'group_category_87254' => 0,
            'group_category_2737' => 0,
            'group_category_41103' => 0,
            'group_category_materials_87254' => 0,
            'group_category_2738' => 0,
            'group_category_materials_41103' => 0,
            'group_category_87255' => 0,
            'group_category_2763' => 0,
            'group_category_41160' => 0,
            'group_category_materials_87255' => 0,
            'group_category_2764' => 0,
            'group_category_materials_41160' => 0,
            'group_category_87256' => 0,
            'group_category_41161' => 0,
            'group_category_materials_87256' => 0,
            'group_category_2816' => 0,
            'group_category_materials_41161' => 0,
            'group_category_87260' => 0,
            'group_category_2914' => 0,
            'group_category_41175' => 0,
            'group_category_materials_87260' => 0,
            'group_category_2965' => 0,
            'group_category_materials_41175' => 0,
            'group_category_87263' => 0,
            'group_category_3002' => 0,
            'group_category_41376' => 0,
            'group_category_materials_87263' => 0,
            'group_category_3042' => 0,
            'group_category_materials_41376' => 0,
            'group_category_87266' => 0,
            'group_category_3185' => 0,
            'group_category_41611' => 0,
            'group_category_materials_87266' => 0,
            'group_category_3231' => 0,
            'group_category_materials_41611' => 0,
            'group_category_87268' => 0,
            'group_category_3247' => 0,
            'group_category_41719' => 0,
            'group_category_materials_87268' => 0,
            'group_category_3273' => 0,
            'group_category_materials_41719' => 0,
            'group_category_87271' => 0,
            'group_category_3496' => 0,
            'group_category_41738' => 0,
            'group_category_materials_87271' => 0,
            'group_category_3569' => 0,
            'group_category_materials_41738' => 0,
            'group_category_87273' => 0,
            'group_category_3596' => 0,
            'group_category_42227' => 0,
            'group_category_materials_87273' => 0,
            'group_category_3648' => 0,
            'group_category_materials_42227' => 0,
            'group_category_87276' => 0,
            'group_category_5379' => 0,
            'group_category_42343' => 0,
            'group_category_materials_87276' => 0,
            'group_category_5564' => 0,
            'group_category_materials_42343' => 0,
            'group_category_87279' => 0,
            'group_category_5568' => 0,
            'group_category_43332' => 0,
            'group_category_materials_87279' => 0,
            'group_category_5856' => 0,
            'group_category_materials_43332' => 0,
            'group_category_87281' => 0,
            'group_category_5857' => 0,
            'group_category_43412' => 0,
            'group_category_materials_87281' => 0,
            'group_category_7715' => 0,
            'group_category_materials_43412' => 0,
            'group_category_87284' => 0,
            'group_category_7719' => 0,
            'group_category_43517' => 0,
            'group_category_materials_87284' => 0,
            'group_category_8270' => 0,
            'group_category_materials_43517' => 0,
            'group_category_87287' => 0,
            'group_category_8339' => 0,
            'group_category_43587' => 0,
            'group_category_materials_87287' => 0,
            'group_category_8572' => 0,
            'group_category_materials_43587' => 0,
            'group_category_87291' => 0,
            'group_category_10280' => 0,
            'group_category_43817' => 0,
            'group_category_materials_87291' => 0,
            'group_category_10724' => 0,
            'group_category_materials_43817' => 0,
            'group_category_87408' => 0,
            'group_category_materials_1836' => 0,
            'group_category_44079' => 0,
            'group_category_materials_87408' => 0,
            'group_category_materials_1843' => 0,
            'group_category_materials_44079' => 0,
            'group_category_87409' => 0,
            'group_category_materials_1937' => 0,
            'group_category_44183' => 0,
            'group_category_materials_87409' => 0,
            'group_category_materials_1946' => 0,
            'group_category_materials_44183' => 0,
            'group_category_87424' => 0,
            'group_category_materials_2092' => 0,
            'group_category_44275' => 0,
            'group_category_materials_87424' => 0,
            'group_category_materials_2095' => 0,
            'group_category_materials_44275' => 0,
            'group_category_87425' => 0,
            'group_category_materials_2103' => 0,
            'group_category_45421' => 0,
            'group_category_materials_87425' => 0,
            'group_category_materials_2158' => 0,
            'group_category_materials_45421' => 0,
            'group_category_87446' => 0,
            'group_category_materials_2181' => 0,
            'group_category_45812' => 0,
            'group_category_materials_87446' => 0,
            'group_category_materials_2194' => 0,
            'group_category_materials_45812' => 0,
            'group_category_87458' => 0,
            'group_category_materials_2233' => 0,
            'group_category_materials_87458' => 0,
            'group_category_materials_2247' => 0,
            'group_category_45814' => 0,
            'group_category_87517' => 0,
            'group_category_materials_2248' => 0,
            'group_category_materials_45814' => 0,
            'group_category_materials_87517' => 0,
            'group_category_materials_2249' => 0,
            'group_category_45884' => 0,
            'group_category_87518' => 0,
            'group_category_materials_2260' => 0,
            'group_category_materials_45884' => 0,
            'group_category_materials_87518' => 0,
            'group_category_materials_2268' => 0,
            'group_category_46480' => 0,
            'group_category_87533' => 0,
            'group_category_materials_2323' => 0,
            'group_category_materials_46480' => 0,
            'group_category_materials_87533' => 0,
            'group_category_materials_2333' => 0,
            'group_category_46481' => 0,
            'group_category_87534' => 0,
            'group_category_materials_2337' => 0,
            'group_category_materials_46481' => 0,
            'group_category_materials_87534' => 0,
            'group_category_materials_2351' => 0,
            'group_category_46606' => 0,
            'group_category_87549' => 0,
            'group_category_materials_2432' => 0,
            'group_category_materials_46606' => 0,
            'group_category_materials_87549' => 0,
            'group_category_materials_2484' => 0,
            'group_category_46870' => 0,
            'group_category_87550' => 0,
            'group_category_materials_2491' => 0,
            'group_category_materials_46870' => 0,
            'group_category_materials_87550' => 0,
            'group_category_materials_2511' => 0,
            'group_category_46885' => 0,
            'group_category_87565' => 0,
            'group_category_materials_2542' => 0,
            'group_category_materials_46885' => 0,
            'group_category_materials_87565' => 0,
            'group_category_materials_2570' => 0,
            'group_category_46955' => 0,
            'group_category_87566' => 0,
            'group_category_materials_2583' => 0,
            'group_category_materials_46955' => 0,
            'group_category_materials_87566' => 0,
            'group_category_materials_2614' => 0,
            'group_category_47120' => 0,
            'group_category_87597' => 0,
            'group_category_materials_2633' => 0,
            'group_category_materials_47120' => 0,
            'group_category_materials_87597' => 0,
            'group_category_materials_2712' => 0,
            'group_category_47181' => 0,
            'group_category_87619' => 0,
            'group_category_materials_2713' => 0,
            'group_category_materials_47181' => 0,
            'group_category_materials_87619' => 0,
            'group_category_materials_2763' => 0,
            'group_category_47273' => 0,
            'group_category_87625' => 0,
            'group_category_materials_2816' => 0,
            'group_category_materials_47273' => 0,
            'group_category_materials_87625' => 0,
            'group_category_materials_2914' => 0,
            'group_category_47401' => 0,
            'group_category_materials_2965' => 0,
            'group_category_materials_47401' => 0,
            'group_category_materials_3002' => 0,
            'group_category_47444' => 0,
            'group_category_materials_3042' => 0,
            'group_category_materials_47444' => 0,
            'group_category_materials_3185' => 0,
            'group_category_47445' => 0,
            'group_category_materials_3231' => 0,
            'group_category_materials_47445' => 0,
            'group_category_materials_3247' => 0,
            'group_category_47470' => 0,
            'group_category_materials_3273' => 0,
            'group_category_materials_47470' => 0,
            'group_category_materials_3496' => 0,
            'group_category_47471' => 0,
            'group_category_materials_3569' => 0,
            'group_category_materials_47471' => 0,
            'group_category_materials_3596' => 0,
            'group_category_47506' => 0,
            'group_category_materials_3648' => 0,
            'group_category_materials_47506' => 0,
            'group_category_materials_5379' => 0,
            'group_category_47594' => 0,
            'group_category_materials_5564' => 0,
            'group_category_materials_47594' => 0,
            'group_category_materials_5568' => 0,
            'group_category_47890' => 0,
            'group_category_materials_5857' => 0,
            'group_category_materials_47890' => 0,
            'group_category_materials_7715' => 0,
            'group_category_50216' => 0,
            'group_category_materials_50216' => 0,
            'group_category_materials_7719' => 0,
            'group_category_50718' => 0,
            'group_category_materials_8270' => 0,
            'group_category_materials_50718' => 0,
            'group_category_materials_8339' => 0,
            'group_category_50851' => 0,
            'group_category_materials_8572' => 0,
            'group_category_materials_50851' => 0,
            'group_category_51148' => 0,
            'group_category_materials_51148' => 0,
            'group_category_51838' => 0,
            'group_category_materials_10280' => 0,
            'group_category_materials_51838' => 0,
            'group_category_materials_10724' => 0,
            'group_category_52626' => 0,
            'group_category_11692' => 0,
            'group_category_materials_52626' => 0,
            'group_category_materials_11692' => 0,
            'group_category_55982' => 0,
            'group_category_12046' => 0,
            'group_category_materials_55982' => 0,
            'group_category_materials_12046' => 0,
            'group_category_58089' => 0,
            'group_category_12538' => 0,
            'group_category_materials_58089' => 0,
            'group_category_materials_12538' => 0,
            'group_category_62775' => 0,
            'group_category_13327' => 0,
            'group_category_materials_62775' => 0,
            'group_category_materials_13327' => 0,
            'group_category_65563' => 0,
            'group_category_14486' => 0,
            'group_category_materials_65563' => 0,
            'group_category_materials_14486' => 0,
            'group_category_65894' => 0,
            'group_category_14621' => 0,
            'group_category_materials_65894' => 0,
            'group_category_materials_14621' => 0,
            'group_category_68089' => 0,
            'group_category_15077' => 0,
            'group_category_materials_68089' => 0,
            'group_category_materials_15077' => 0,
            'group_category_68885' => 0,
            'group_category_15381' => 0,
            'group_category_materials_68885' => 0,
            'group_category_materials_15381' => 0,
            'group_category_69116' => 0,
            'group_category_15620' => 0,
            'group_category_materials_69116' => 0,
            'group_category_materials_15620' => 0,
            'group_category_69818' => 0,
            'group_category_16319' => 0,
            'group_category_materials_69818' => 0,
            'group_category_materials_16319' => 0,
            'group_category_70517' => 0,
            'group_category_16362' => 0,
            'group_category_materials_70517' => 0,
            'group_category_materials_16362' => 0,
            'group_category_70630' => 0,
            'group_category_16660' => 0,
            'group_category_materials_70630' => 0,
            'group_category_materials_16660' => 0,
            'group_category_71583' => 0,
            'group_category_16955' => 0,
            'group_category_materials_71583' => 0,
            'group_category_materials_16955' => 0,
            'group_category_73869' => 0,
            'group_category_17070' => 0,
            'group_category_materials_73869' => 0,
            'group_category_materials_17070' => 0,
            'group_category_74192' => 0,
            'group_category_17516' => 0,
            'group_category_materials_74192' => 0,
            'group_category_materials_17516' => 0,
            'group_category_74547' => 0,
            'group_category_17553' => 0,
            'group_category_materials_74547' => 0,
            'group_category_materials_17553' => 0,
            'group_category_75382' => 0,
            'group_category_17995' => 0,
            'group_category_materials_75382' => 0,
            'group_category_materials_17995' => 0,
            'group_category_75399' => 0,
            'group_category_17996' => 0,
            'group_category_materials_75399' => 0,
            'group_category_materials_17996' => 0,
            'group_category_75440' => 0,
            'group_category_18031' => 0,
            'group_category_materials_75440' => 0,
            'group_category_materials_18031' => 0,
            'group_category_75465' => 0,
            'group_category_18596' => 0,
            'group_category_materials_75465' => 0,
            'group_category_materials_18596' => 0,
            'group_category_75528' => 0,
            'group_category_18644' => 0,
            'group_category_materials_75528' => 0,
            'group_category_materials_18644' => 0,
            'group_category_75761' => 0,
            'group_category_18645' => 0,
            'group_category_materials_75761' => 0,
            'group_category_materials_18645' => 0,
            'group_category_76696' => 0,
            'group_category_19023' => 0,
            'group_category_materials_76696' => 0,
            'group_category_materials_19023' => 0,
            'group_category_19288' => 0,
            'group_category_77570' => 0,
            'group_category_materials_19288' => 0,
            'group_category_19563' => 0,
            'group_category_materials_77570' => 0,
            'group_category_materials_19563' => 0,
            'group_category_20035' => 0,
            'group_category_77924' => 0,
            'group_category_materials_20035' => 0,
            'group_category_20084' => 0,
            'group_category_materials_77924' => 0,
            'group_category_materials_20084' => 0,
            'group_category_20392' => 0,
            'group_category_78586' => 0,
            'group_category_materials_20392' => 0,
            'group_category_20764' => 0,
            'group_category_materials_78586' => 0,
            'group_category_materials_20764' => 0,
            'group_category_20765' => 0,
            'group_category_materials_20765' => 0,
            'group_category_21112' => 0,
            'group_category_78748' => 0,
            'group_category_materials_21112' => 0,
            'group_category_21514' => 0,
            'group_category_materials_78748' => 0,
            'group_category_materials_21514' => 0,
            'group_category_22425' => 0,
            'group_category_79866' => 0,
            'group_category_materials_22425' => 0,
            'group_category_22768' => 0,
            'group_category_materials_79866' => 0,
            'group_category_materials_22768' => 0,
            'group_category_22823' => 0,
            'group_category_80296' => 0,
            'group_category_materials_22823' => 0,
            'group_category_23374' => 0,
            'group_category_materials_80296' => 0,
            'group_category_materials_23374' => 0,
            'group_category_23744' => 0,
            'group_category_81082' => 0,
            'group_category_materials_23744' => 0,
            'group_category_24035' => 0,
            'group_category_materials_81082' => 0,
            'group_category_materials_24035' => 0,
            'group_category_24187' => 0,
            'group_category_81110' => 0,
            'group_category_materials_24187' => 0,
            'group_category_24917' => 0,
            'group_category_materials_81110' => 0,
            'group_category_materials_24917' => 0,
            'group_category_25459' => 0,
            'group_category_81136' => 0,
            'group_category_materials_25459' => 0,
            'group_category_26328' => 0,
            'group_category_materials_81136' => 0,
            'group_category_materials_26328' => 0,
            'group_category_26442' => 0,
            'group_category_81532' => 0,
            'group_category_materials_26442' => 0,
            'group_category_27076' => 0,
            'group_category_materials_81532' => 0,
            'group_category_materials_27076' => 0,
            'group_category_27172' => 0,
            'group_category_81570' => 0,
            'group_category_materials_27172' => 0,
            'group_category_29145' => 0,
            'group_category_materials_81570' => 0,
            'group_category_materials_29145' => 0,
            'group_category_32850' => 0,
            'group_category_81574' => 0,
            'group_category_materials_32850' => 0,
            'group_category_33086' => 0,
            'group_category_materials_81574' => 0,
            'group_category_materials_33086' => 0,
            'group_category_33456' => 0,
            'group_category_81578' => 0,
            'group_category_materials_33456' => 0,
            'group_category_35847' => 0,
            'group_category_materials_81578' => 0,
            'group_category_materials_35847' => 0,
            'group_category_36697' => 0,
            'group_category_84082' => 0,
            'group_category_materials_36697' => 0,
            'group_category_36698' => 0,
            'group_category_materials_84082' => 0,
            'group_category_materials_36698' => 0,
            'group_category_37211' => 0,
            'group_category_84274' => 0,
            'group_category_materials_37211' => 0,
            'group_category_37660' => 0,
            'group_category_materials_84274' => 0,
            'group_category_materials_37660' => 0,
            'group_category_84276' => 0,
            'group_category_37749' => 0,
            'group_category_materials_37749' => 0,
            'group_category_materials_84276' => 0,
            'group_category_38268' => 0,
            'group_category_materials_38268' => 0,
            'group_category_85718' => 0,
            'group_category_38365' => 0,
            'group_category_materials_38365' => 0,
            'group_category_materials_85718' => 0,
            'group_category_38380' => 0,
            'tags' => 0,
            'wissensbasis_kategorien' => 0,
            'organisation_responsibilities' => 0,
          ),
          'breadcrumb' => 1,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['materials_download'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'materials_download_home';
  $path_breadcrumb->name = 'Materials Download Home';
  $path_breadcrumb->path = 'materials/download';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Materials',
      1 => 'Download',
    ),
    'paths' => array(
      0 => 'materials',
      1 => 'materials/download',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['materials_download_home'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'materials_download_home_clone';
  $path_breadcrumb->name = 'Materials Edit Home';
  $path_breadcrumb->path = 'materials/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Materials',
      1 => 'Edit',
    ),
    'paths' => array(
      0 => 'materials',
      1 => 'materials/edit',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['materials_download_home_clone'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'materials_edit';
  $path_breadcrumb->name = 'Materials Edit';
  $path_breadcrumb->path = 'materials/edit/%taxonomy_term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Materials',
      1 => 'Edit',
    ),
    'paths' => array(
      0 => 'materials',
      1 => 'materials/edit',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'taxonomy_term' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vocabularies' => array(
            'ea_sport' => 0,
            'ea_training_course' => 0,
            'ea_profile' => 0,
            'ea_discipline' => 0,
            'ea_focus' => 0,
            'profile_competencies' => 0,
            'profile_interests' => 0,
            'lehr_lern_material_kategorien' => 0,
            'post_tags' => 0,
            'profile_sports' => 0,
            'group_category_materials_38380' => 0,
            'group_category_86910' => 0,
            'group_category_38466' => 0,
            'group_category_materials_38466' => 0,
            'group_category_materials_86910' => 0,
            'group_category_38476' => 0,
            'group_category_materials_38476' => 0,
            'group_category_87072' => 0,
            'group_category_38561' => 0,
            'group_category_materials_38561' => 0,
            'group_category_materials_87072' => 0,
            'group_category_38808' => 0,
            'group_category_87216' => 0,
            'group_category_materials_38808' => 0,
            'group_category_materials_87216' => 0,
            'group_category_1836' => 0,
            'group_category_38875' => 0,
            'group_category_87217' => 0,
            'group_category_1843' => 0,
            'group_category_materials_38875' => 0,
            'group_category_materials_87217' => 0,
            'group_category_1937' => 0,
            'group_category_39210' => 0,
            'group_category_87218' => 0,
            'group_category_1946' => 0,
            'group_category_materials_39210' => 0,
            'group_category_materials_87218' => 0,
            'group_category_2092' => 0,
            'group_category_39245' => 0,
            'group_category_87219' => 0,
            'group_category_2095' => 0,
            'group_category_materials_39245' => 0,
            'group_category_materials_87219' => 0,
            'group_category_2103' => 0,
            'group_category_39256' => 0,
            'group_category_87221' => 0,
            'group_category_2158' => 0,
            'group_category_materials_39256' => 0,
            'group_category_materials_87221' => 0,
            'group_category_2181' => 0,
            'group_category_39534' => 0,
            'group_category_87222' => 0,
            'group_category_2193' => 0,
            'group_category_materials_39534' => 0,
            'group_category_materials_87222' => 0,
            'group_category_2194' => 0,
            'group_category_39547' => 0,
            'group_category_87224' => 0,
            'group_category_2232' => 0,
            'group_category_materials_39547' => 0,
            'group_category_materials_87224' => 0,
            'group_category_2233' => 0,
            'group_category_39771' => 0,
            'group_category_87225' => 0,
            'group_category_2247' => 0,
            'group_category_materials_39771' => 0,
            'group_category_materials_87225' => 0,
            'group_category_2248' => 0,
            'group_category_39844' => 0,
            'group_category_87226' => 0,
            'group_category_2249' => 0,
            'group_category_materials_39844' => 0,
            'group_category_materials_87226' => 0,
            'group_category_2260' => 0,
            'group_category_39952' => 0,
            'group_category_87227' => 0,
            'group_category_2268' => 0,
            'group_category_materials_39952' => 0,
            'group_category_materials_87227' => 0,
            'group_category_2323' => 0,
            'group_category_39960' => 0,
            'group_category_87229' => 0,
            'group_category_2326' => 0,
            'group_category_materials_39960' => 0,
            'group_category_materials_87229' => 0,
            'group_category_2327' => 0,
            'group_category_87230' => 0,
            'group_category_2328' => 0,
            'group_category_39962' => 0,
            'group_category_materials_87230' => 0,
            'group_category_2333' => 0,
            'group_category_materials_39962' => 0,
            'group_category_87232' => 0,
            'group_category_2337' => 0,
            'group_category_40017' => 0,
            'group_category_materials_87232' => 0,
            'group_category_2351' => 0,
            'group_category_materials_40017' => 0,
            'group_category_87235' => 0,
            'group_category_2432' => 0,
            'group_category_40132' => 0,
            'group_category_materials_87235' => 0,
            'group_category_2484' => 0,
            'group_category_materials_40132' => 0,
            'group_category_87240' => 0,
            'group_category_2491' => 0,
            'group_category_40682' => 0,
            'group_category_materials_87240' => 0,
            'group_category_2511' => 0,
            'group_category_materials_40682' => 0,
            'group_category_87242' => 0,
            'group_category_2541' => 0,
            'group_category_40956' => 0,
            'group_category_materials_87242' => 0,
            'group_category_2542' => 0,
            'group_category_materials_40956' => 0,
            'group_category_87244' => 0,
            'group_category_2570' => 0,
            'group_category_40996' => 0,
            'group_category_materials_87244' => 0,
            'group_category_2583' => 0,
            'group_category_materials_40996' => 0,
            'group_category_87246' => 0,
            'group_category_2614' => 0,
            'group_category_41018' => 0,
            'group_category_materials_87246' => 0,
            'group_category_materials_41018' => 0,
            'group_category_87248' => 0,
            'group_category_41019' => 0,
            'group_category_materials_87248' => 0,
            'group_category_materials_41019' => 0,
            'group_category_87250' => 0,
            'group_category_41039' => 0,
            'group_category_materials_87250' => 0,
            'group_category_2633' => 0,
            'group_category_materials_41039' => 0,
            'group_category_87252' => 0,
            'group_category_2712' => 0,
            'group_category_41069' => 0,
            'group_category_materials_87252' => 0,
            'group_category_2713' => 0,
            'group_category_materials_41069' => 0,
            'group_category_87254' => 0,
            'group_category_2737' => 0,
            'group_category_41103' => 0,
            'group_category_materials_87254' => 0,
            'group_category_2738' => 0,
            'group_category_materials_41103' => 0,
            'group_category_87255' => 0,
            'group_category_2763' => 0,
            'group_category_41160' => 0,
            'group_category_materials_87255' => 0,
            'group_category_2764' => 0,
            'group_category_materials_41160' => 0,
            'group_category_87256' => 0,
            'group_category_41161' => 0,
            'group_category_materials_87256' => 0,
            'group_category_2816' => 0,
            'group_category_materials_41161' => 0,
            'group_category_87260' => 0,
            'group_category_2914' => 0,
            'group_category_41175' => 0,
            'group_category_materials_87260' => 0,
            'group_category_2965' => 0,
            'group_category_materials_41175' => 0,
            'group_category_87263' => 0,
            'group_category_3002' => 0,
            'group_category_41376' => 0,
            'group_category_materials_87263' => 0,
            'group_category_3042' => 0,
            'group_category_materials_41376' => 0,
            'group_category_87266' => 0,
            'group_category_3185' => 0,
            'group_category_41611' => 0,
            'group_category_materials_87266' => 0,
            'group_category_3231' => 0,
            'group_category_materials_41611' => 0,
            'group_category_87268' => 0,
            'group_category_3247' => 0,
            'group_category_41719' => 0,
            'group_category_materials_87268' => 0,
            'group_category_3273' => 0,
            'group_category_materials_41719' => 0,
            'group_category_87271' => 0,
            'group_category_3496' => 0,
            'group_category_41738' => 0,
            'group_category_materials_87271' => 0,
            'group_category_3569' => 0,
            'group_category_materials_41738' => 0,
            'group_category_87273' => 0,
            'group_category_3596' => 0,
            'group_category_42227' => 0,
            'group_category_materials_87273' => 0,
            'group_category_3648' => 0,
            'group_category_materials_42227' => 0,
            'group_category_87276' => 0,
            'group_category_5379' => 0,
            'group_category_42343' => 0,
            'group_category_materials_87276' => 0,
            'group_category_5564' => 0,
            'group_category_materials_42343' => 0,
            'group_category_87279' => 0,
            'group_category_5568' => 0,
            'group_category_43332' => 0,
            'group_category_materials_87279' => 0,
            'group_category_5856' => 0,
            'group_category_materials_43332' => 0,
            'group_category_87281' => 0,
            'group_category_5857' => 0,
            'group_category_43412' => 0,
            'group_category_materials_87281' => 0,
            'group_category_7715' => 0,
            'group_category_materials_43412' => 0,
            'group_category_87284' => 0,
            'group_category_7719' => 0,
            'group_category_43517' => 0,
            'group_category_materials_87284' => 0,
            'group_category_8270' => 0,
            'group_category_materials_43517' => 0,
            'group_category_87287' => 0,
            'group_category_8339' => 0,
            'group_category_43587' => 0,
            'group_category_materials_87287' => 0,
            'group_category_8572' => 0,
            'group_category_materials_43587' => 0,
            'group_category_87291' => 0,
            'group_category_10280' => 0,
            'group_category_43817' => 0,
            'group_category_materials_87291' => 0,
            'group_category_10724' => 0,
            'group_category_materials_43817' => 0,
            'group_category_87408' => 0,
            'group_category_materials_1836' => 0,
            'group_category_44079' => 0,
            'group_category_materials_87408' => 0,
            'group_category_materials_1843' => 0,
            'group_category_materials_44079' => 0,
            'group_category_87409' => 0,
            'group_category_materials_1937' => 0,
            'group_category_44183' => 0,
            'group_category_materials_87409' => 0,
            'group_category_materials_1946' => 0,
            'group_category_materials_44183' => 0,
            'group_category_87424' => 0,
            'group_category_materials_2092' => 0,
            'group_category_44275' => 0,
            'group_category_materials_87424' => 0,
            'group_category_materials_2095' => 0,
            'group_category_materials_44275' => 0,
            'group_category_87425' => 0,
            'group_category_materials_2103' => 0,
            'group_category_45421' => 0,
            'group_category_materials_87425' => 0,
            'group_category_materials_2158' => 0,
            'group_category_materials_45421' => 0,
            'group_category_87446' => 0,
            'group_category_materials_2181' => 0,
            'group_category_45812' => 0,
            'group_category_materials_87446' => 0,
            'group_category_materials_2194' => 0,
            'group_category_materials_45812' => 0,
            'group_category_87458' => 0,
            'group_category_materials_2233' => 0,
            'group_category_materials_87458' => 0,
            'group_category_materials_2247' => 0,
            'group_category_45814' => 0,
            'group_category_87517' => 0,
            'group_category_materials_2248' => 0,
            'group_category_materials_45814' => 0,
            'group_category_materials_87517' => 0,
            'group_category_materials_2249' => 0,
            'group_category_45884' => 0,
            'group_category_87518' => 0,
            'group_category_materials_2260' => 0,
            'group_category_materials_45884' => 0,
            'group_category_materials_87518' => 0,
            'group_category_materials_2268' => 0,
            'group_category_46480' => 0,
            'group_category_87533' => 0,
            'group_category_materials_2323' => 0,
            'group_category_materials_46480' => 0,
            'group_category_materials_87533' => 0,
            'group_category_materials_2333' => 0,
            'group_category_46481' => 0,
            'group_category_87534' => 0,
            'group_category_materials_2337' => 0,
            'group_category_materials_46481' => 0,
            'group_category_materials_87534' => 0,
            'group_category_materials_2351' => 0,
            'group_category_46606' => 0,
            'group_category_87549' => 0,
            'group_category_materials_2432' => 0,
            'group_category_materials_46606' => 0,
            'group_category_materials_87549' => 0,
            'group_category_materials_2484' => 0,
            'group_category_46870' => 0,
            'group_category_87550' => 0,
            'group_category_materials_2491' => 0,
            'group_category_materials_46870' => 0,
            'group_category_materials_87550' => 0,
            'group_category_materials_2511' => 0,
            'group_category_46885' => 0,
            'group_category_87565' => 0,
            'group_category_materials_2542' => 0,
            'group_category_materials_46885' => 0,
            'group_category_materials_87565' => 0,
            'group_category_materials_2570' => 0,
            'group_category_46955' => 0,
            'group_category_87566' => 0,
            'group_category_materials_2583' => 0,
            'group_category_materials_46955' => 0,
            'group_category_materials_87566' => 0,
            'group_category_materials_2614' => 0,
            'group_category_47120' => 0,
            'group_category_87597' => 0,
            'group_category_materials_2633' => 0,
            'group_category_materials_47120' => 0,
            'group_category_materials_87597' => 0,
            'group_category_materials_2712' => 0,
            'group_category_47181' => 0,
            'group_category_87619' => 0,
            'group_category_materials_2713' => 0,
            'group_category_materials_47181' => 0,
            'group_category_materials_87619' => 0,
            'group_category_materials_2763' => 0,
            'group_category_47273' => 0,
            'group_category_87625' => 0,
            'group_category_materials_2816' => 0,
            'group_category_materials_47273' => 0,
            'group_category_materials_87625' => 0,
            'group_category_materials_2914' => 0,
            'group_category_47401' => 0,
            'group_category_materials_2965' => 0,
            'group_category_materials_47401' => 0,
            'group_category_materials_3002' => 0,
            'group_category_47444' => 0,
            'group_category_materials_3042' => 0,
            'group_category_materials_47444' => 0,
            'group_category_materials_3185' => 0,
            'group_category_47445' => 0,
            'group_category_materials_3231' => 0,
            'group_category_materials_47445' => 0,
            'group_category_materials_3247' => 0,
            'group_category_47470' => 0,
            'group_category_materials_3273' => 0,
            'group_category_materials_47470' => 0,
            'group_category_materials_3496' => 0,
            'group_category_47471' => 0,
            'group_category_materials_3569' => 0,
            'group_category_materials_47471' => 0,
            'group_category_materials_3596' => 0,
            'group_category_47506' => 0,
            'group_category_materials_3648' => 0,
            'group_category_materials_47506' => 0,
            'group_category_materials_5379' => 0,
            'group_category_47594' => 0,
            'group_category_materials_5564' => 0,
            'group_category_materials_47594' => 0,
            'group_category_materials_5568' => 0,
            'group_category_47890' => 0,
            'group_category_materials_5857' => 0,
            'group_category_materials_47890' => 0,
            'group_category_materials_7715' => 0,
            'group_category_50216' => 0,
            'group_category_materials_50216' => 0,
            'group_category_materials_7719' => 0,
            'group_category_50718' => 0,
            'group_category_materials_8270' => 0,
            'group_category_materials_50718' => 0,
            'group_category_materials_8339' => 0,
            'group_category_50851' => 0,
            'group_category_materials_8572' => 0,
            'group_category_materials_50851' => 0,
            'group_category_51148' => 0,
            'group_category_materials_51148' => 0,
            'group_category_51838' => 0,
            'group_category_materials_10280' => 0,
            'group_category_materials_51838' => 0,
            'group_category_materials_10724' => 0,
            'group_category_52626' => 0,
            'group_category_11692' => 0,
            'group_category_materials_52626' => 0,
            'group_category_materials_11692' => 0,
            'group_category_55982' => 0,
            'group_category_12046' => 0,
            'group_category_materials_55982' => 0,
            'group_category_materials_12046' => 0,
            'group_category_58089' => 0,
            'group_category_12538' => 0,
            'group_category_materials_58089' => 0,
            'group_category_materials_12538' => 0,
            'group_category_62775' => 0,
            'group_category_13327' => 0,
            'group_category_materials_62775' => 0,
            'group_category_materials_13327' => 0,
            'group_category_65563' => 0,
            'group_category_14486' => 0,
            'group_category_materials_65563' => 0,
            'group_category_materials_14486' => 0,
            'group_category_65894' => 0,
            'group_category_14621' => 0,
            'group_category_materials_65894' => 0,
            'group_category_materials_14621' => 0,
            'group_category_68089' => 0,
            'group_category_15077' => 0,
            'group_category_materials_68089' => 0,
            'group_category_materials_15077' => 0,
            'group_category_68885' => 0,
            'group_category_15381' => 0,
            'group_category_materials_68885' => 0,
            'group_category_materials_15381' => 0,
            'group_category_69116' => 0,
            'group_category_15620' => 0,
            'group_category_materials_69116' => 0,
            'group_category_materials_15620' => 0,
            'group_category_69818' => 0,
            'group_category_16319' => 0,
            'group_category_materials_69818' => 0,
            'group_category_materials_16319' => 0,
            'group_category_70517' => 0,
            'group_category_16362' => 0,
            'group_category_materials_70517' => 0,
            'group_category_materials_16362' => 0,
            'group_category_70630' => 0,
            'group_category_16660' => 0,
            'group_category_materials_70630' => 0,
            'group_category_materials_16660' => 0,
            'group_category_71583' => 0,
            'group_category_16955' => 0,
            'group_category_materials_71583' => 0,
            'group_category_materials_16955' => 0,
            'group_category_73869' => 0,
            'group_category_17070' => 0,
            'group_category_materials_73869' => 0,
            'group_category_materials_17070' => 0,
            'group_category_74192' => 0,
            'group_category_17516' => 0,
            'group_category_materials_74192' => 0,
            'group_category_materials_17516' => 0,
            'group_category_74547' => 0,
            'group_category_17553' => 0,
            'group_category_materials_74547' => 0,
            'group_category_materials_17553' => 0,
            'group_category_75382' => 0,
            'group_category_17995' => 0,
            'group_category_materials_75382' => 0,
            'group_category_materials_17995' => 0,
            'group_category_75399' => 0,
            'group_category_17996' => 0,
            'group_category_materials_75399' => 0,
            'group_category_materials_17996' => 0,
            'group_category_75440' => 0,
            'group_category_18031' => 0,
            'group_category_materials_75440' => 0,
            'group_category_materials_18031' => 0,
            'group_category_75465' => 0,
            'group_category_18596' => 0,
            'group_category_materials_75465' => 0,
            'group_category_materials_18596' => 0,
            'group_category_75528' => 0,
            'group_category_18644' => 0,
            'group_category_materials_75528' => 0,
            'group_category_materials_18644' => 0,
            'group_category_75761' => 0,
            'group_category_18645' => 0,
            'group_category_materials_75761' => 0,
            'group_category_materials_18645' => 0,
            'group_category_76696' => 0,
            'group_category_19023' => 0,
            'group_category_materials_76696' => 0,
            'group_category_materials_19023' => 0,
            'group_category_19288' => 0,
            'group_category_77570' => 0,
            'group_category_materials_19288' => 0,
            'group_category_19563' => 0,
            'group_category_materials_77570' => 0,
            'group_category_materials_19563' => 0,
            'group_category_20035' => 0,
            'group_category_77924' => 0,
            'group_category_materials_20035' => 0,
            'group_category_20084' => 0,
            'group_category_materials_77924' => 0,
            'group_category_materials_20084' => 0,
            'group_category_20392' => 0,
            'group_category_78586' => 0,
            'group_category_materials_20392' => 0,
            'group_category_20764' => 0,
            'group_category_materials_78586' => 0,
            'group_category_materials_20764' => 0,
            'group_category_20765' => 0,
            'group_category_materials_20765' => 0,
            'group_category_21112' => 0,
            'group_category_78748' => 0,
            'group_category_materials_21112' => 0,
            'group_category_21514' => 0,
            'group_category_materials_78748' => 0,
            'group_category_materials_21514' => 0,
            'group_category_22425' => 0,
            'group_category_79866' => 0,
            'group_category_materials_22425' => 0,
            'group_category_22768' => 0,
            'group_category_materials_79866' => 0,
            'group_category_materials_22768' => 0,
            'group_category_22823' => 0,
            'group_category_80296' => 0,
            'group_category_materials_22823' => 0,
            'group_category_23374' => 0,
            'group_category_materials_80296' => 0,
            'group_category_materials_23374' => 0,
            'group_category_23744' => 0,
            'group_category_81082' => 0,
            'group_category_materials_23744' => 0,
            'group_category_24035' => 0,
            'group_category_materials_81082' => 0,
            'group_category_materials_24035' => 0,
            'group_category_24187' => 0,
            'group_category_81110' => 0,
            'group_category_materials_24187' => 0,
            'group_category_24917' => 0,
            'group_category_materials_81110' => 0,
            'group_category_materials_24917' => 0,
            'group_category_25459' => 0,
            'group_category_81136' => 0,
            'group_category_materials_25459' => 0,
            'group_category_26328' => 0,
            'group_category_materials_81136' => 0,
            'group_category_materials_26328' => 0,
            'group_category_26442' => 0,
            'group_category_81532' => 0,
            'group_category_materials_26442' => 0,
            'group_category_27076' => 0,
            'group_category_materials_81532' => 0,
            'group_category_materials_27076' => 0,
            'group_category_27172' => 0,
            'group_category_81570' => 0,
            'group_category_materials_27172' => 0,
            'group_category_29145' => 0,
            'group_category_materials_81570' => 0,
            'group_category_materials_29145' => 0,
            'group_category_32850' => 0,
            'group_category_81574' => 0,
            'group_category_materials_32850' => 0,
            'group_category_33086' => 0,
            'group_category_materials_81574' => 0,
            'group_category_materials_33086' => 0,
            'group_category_33456' => 0,
            'group_category_81578' => 0,
            'group_category_materials_33456' => 0,
            'group_category_35847' => 0,
            'group_category_materials_81578' => 0,
            'group_category_materials_35847' => 0,
            'group_category_36697' => 0,
            'group_category_84082' => 0,
            'group_category_materials_36697' => 0,
            'group_category_36698' => 0,
            'group_category_materials_84082' => 0,
            'group_category_materials_36698' => 0,
            'group_category_37211' => 0,
            'group_category_84274' => 0,
            'group_category_materials_37211' => 0,
            'group_category_37660' => 0,
            'group_category_materials_84274' => 0,
            'group_category_materials_37660' => 0,
            'group_category_84276' => 0,
            'group_category_37749' => 0,
            'group_category_materials_37749' => 0,
            'group_category_materials_84276' => 0,
            'group_category_38268' => 0,
            'group_category_materials_38268' => 0,
            'group_category_85718' => 0,
            'group_category_38365' => 0,
            'group_category_materials_38365' => 0,
            'group_category_materials_85718' => 0,
            'group_category_38380' => 0,
            'tags' => 0,
            'wissensbasis_kategorien' => 0,
            'organisation_responsibilities' => 0,
          ),
          'breadcrumb' => 1,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['materials_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'materials_file_add';
  $path_breadcrumb->name = 'Materialien: File add';
  $path_breadcrumb->path = 'file/add_anything';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Materialien',
    ),
    'paths' => array(
      0 => 'materials',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -27;
  $export['materials_file_add'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'materials_overview';
  $path_breadcrumb->name = 'Materialien: Übersicht';
  $path_breadcrumb->path = 'materials/%term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Materialien',
    ),
    'paths' => array(
      0 => 'materials',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'term' => array(
        'position' => 1,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            6 => '6',
            2 => 0,
            1 => 0,
            8 => 0,
            4 => 0,
            3 => 0,
            5 => 0,
            7 => 0,
          ),
          'breadcrumb' => 1,
          'transform' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -28;
  $export['materials_overview'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'newsletter_export';
  $path_breadcrumb->name = 'Newsletter Export';
  $path_breadcrumb->path = 'newsletter/export';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'DOSB-Team',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -35;
  $export['newsletter_export'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'node_add_group';
  $path_breadcrumb->name = 'Node add: group';
  $path_breadcrumb->path = 'node/add/%type';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
    ),
    'paths' => array(
      0 => 'groups',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'type' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
          'use_tail' => 0,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => 'regex',
            'value' => '@(group)@',
            'case' => 0,
          ),
          'context' => 'type',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -85;
  $export['node_add_group'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'node_add_group_content';
  $path_breadcrumb->name = 'Node add: group content';
  $path_breadcrumb->path = 'node/add/%type';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
    ),
    'paths' => array(
      0 => 'groups',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'type' => array(
        'position' => 2,
        'argument' => 'node_add',
        'settings' => array(
          'identifier' => 'Node add form: node type',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        1 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Group context',
            'php' => 'if(!empty($_GET[\'field_og_group\'])) {
  return TRUE;
}
return FALSE;',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -89;
  $export['node_add_group_content'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'node_add_organisation_content';
  $path_breadcrumb->name = 'Node add: Organisation content';
  $path_breadcrumb->path = 'node/add/%type';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Organisationen',
    ),
    'paths' => array(
      0 => 'organisations',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'type' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Zeichenkette',
          'use_tail' => 0,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'organisation',
            'case' => 0,
          ),
          'context' => 'type',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -86;
  $export['node_add_organisation_content'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'node_edit_in_group';
  $path_breadcrumb->name = 'Node Edit in Group';
  $path_breadcrumb->path = 'node/%node/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:field-og-group:title',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => '%node:field-og-group:url',
      2 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'post' => 'post',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if node is OG Content',
            'php' => 'if(!empty($contexts[\'node\']->data->field_og_group)) {
  return TRUE;
}
return FALSE;',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -98;
  $export['node_edit_in_group'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'node_revisions_in_group';
  $path_breadcrumb->name = 'Node Revisions in Group';
  $path_breadcrumb->path = 'node/%node/revisions';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:field-og-group:title',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => '%node:field-og-group:url',
      2 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'kb_article' => 'kb_article',
              'kb_question' => 'kb_question',
              'kb_report' => 'kb_report',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if node is OG Content',
            'php' => 'if(!empty($contexts[\'node\']->data->field_og_group)) {
  return TRUE;
}
return FALSE;',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -100;
  $export['node_revisions_in_group'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'notifications_group_subscriptions';
  $path_breadcrumb->name = 'Notifications: Group Subsciptions';
  $path_breadcrumb->path = 'notifications/group/subscriptions';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Benachrichtigungen',
    ),
    'paths' => array(
      0 => 'notifications',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -56;
  $export['notifications_group_subscriptions'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'notifications_overview';
  $path_breadcrumb->name = 'Notifications: Overview';
  $path_breadcrumb->path = 'notifications/all';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Benachrichtigungen',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -54;
  $export['notifications_overview'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'notifications_overview_settings';
  $path_breadcrumb->name = 'Notifications: Settings';
  $path_breadcrumb->path = 'notifications/settings';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Benachrichtigungen',
    ),
    'paths' => array(
      0 => 'notifications',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -53;
  $export['notifications_overview_settings'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'notifications_overview_uid';
  $path_breadcrumb->name = 'Notifications: Overview';
  $path_breadcrumb->path = 'notifications/all/%uid';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Benachrichtigungen',
    ),
    'paths' => array(
      0 => 'notifications',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'uid' => array(
        'position' => 2,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -54;
  $export['notifications_overview_uid'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'notifications_subscriptions';
  $path_breadcrumb->name = 'Notifications: Subsciptions';
  $path_breadcrumb->path = 'notifications/subscriptions';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Benachrichtigungen',
    ),
    'paths' => array(
      0 => 'notifications',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -56;
  $export['notifications_subscriptions'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations';
  $path_breadcrumb->name = 'Organisation';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Organisationen',
    ),
    'paths' => array(
      0 => 'organisations',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'organisation' => 'organisation',
            ),
          ),
          'context' => 'nid',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -61;
  $export['organisations'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations_by_user';
  $path_breadcrumb->name = 'Organisations by user';
  $path_breadcrumb->path = 'organisations/%user';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Organisationen',
    ),
    'paths' => array(
      0 => 'organisations',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'user' => array(
        'position' => 2,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Benutzer: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -51;
  $export['organisations_by_user'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations_edit';
  $path_breadcrumb->name = 'Organisation Edit';
  $path_breadcrumb->path = 'node/%node/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Organisationen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'organisations',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'organisation' => 'organisation',
            ),
          ),
          'context' => 'nid',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -59;
  $export['organisations_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations_invite';
  $path_breadcrumb->name = 'Organisations Invite';
  $path_breadcrumb->path = 'organisations/%node/admin/membership/add';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Organisationen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'organisations',
      1 => '%node:url',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 2,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'organisation' => 'organisation',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -55;
  $export['organisations_invite'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations_invite_add';
  $path_breadcrumb->name = 'Organisations: Add people';
  $path_breadcrumb->path = 'organisations/%node/invite';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Organisationen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'organisations',
      1 => '%node:url',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 2,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'organisation' => 'organisation',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -57;
  $export['organisations_invite_add'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations_licenses_actions';
  $path_breadcrumb->name = 'Organisations: Licenses';
  $path_breadcrumb->path = 'organisations/%node/licenses/%task';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'licenses',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Beitrag: ID',
        ),
      ),
      'task' => array(
        'position' => 3,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Aktion',
          'use_tail' => 1,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -43;
  $export['organisations_licenses_actions'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations_licenses_actions_status';
  $path_breadcrumb->name = 'Organisations: Licenses Action by Status';
  $path_breadcrumb->path = 'organisations/%node/licenses/%task/%status';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'licenses',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Beitrag: ID',
        ),
      ),
      'task' => array(
        'position' => 3,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Aktion',
          'use_tail' => 1,
        ),
      ),
      'status' => array(
        'position' => 4,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -47;
  $export['organisations_licenses_actions_status'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations_licenses_import_inventory';
  $path_breadcrumb->name = 'Organisations: Licenses Import Inventory';
  $path_breadcrumb->path = 'organisations/%node/licenses/import/%string';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'licenses',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Beitrag: ID',
        ),
      ),
      'string' => array(
        'position' => 4,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Zeichenkette',
          'use_tail' => 1,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -46;
  $export['organisations_licenses_import_inventory'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations_licenses_overview';
  $path_breadcrumb->name = 'Organisations: Licenses';
  $path_breadcrumb->path = 'organisations/%node/licenses';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'licenses',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Beitrag: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -44;
  $export['organisations_licenses_overview'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations_licenses_statistics';
  $path_breadcrumb->name = 'Organisations: Licensestatistics';
  $path_breadcrumb->path = 'organisations/%node/licenses/statistics';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Lizenzen',
      1 => '%node:title',
      2 => 'Lizenzstatistik',
    ),
    'paths' => array(
      0 => 'licenses',
      1 => 'node/%node:nid',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Beitrag: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -45;
  $export['organisations_licenses_statistics'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations_overview';
  $path_breadcrumb->name = 'Organisations Overview';
  $path_breadcrumb->path = 'organisations';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Organisationen',
    ),
    'paths' => array(
      0 => 'organisations',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -52;
  $export['organisations_overview'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organisations_people';
  $path_breadcrumb->name = 'Organisations: People';
  $path_breadcrumb->path = 'organisations/%node/people';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Organisationen',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'organisations',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Beitrag: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -50;
  $export['organisations_people'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'search';
  $path_breadcrumb->name = 'Suche';
  $path_breadcrumb->path = 'search/%subregion';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Suche',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'subregion' => array(
        'position' => 1,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
          'use_tail' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -48;
  $export['search'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'shared_posts_node_view_in_group';
  $path_breadcrumb->name = 'Geteilte Beiträge: in Gruppe';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Gruppen',
      1 => '%node:field-og-group:title',
    ),
    'paths' => array(
      0 => 'groups',
      1 => 'node/%node:field-og-group:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Check if node is OG Content',
            'php' => '$node = $contexts[\'node\']->data;
if (isset($node ->field_og_group[LANGUAGE_NONE][0][\'target_id\'])) {
 return true ;
}
return  false;
',
          ),
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'shared_post' => 'shared_post',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -33;
  $export['shared_posts_node_view_in_group'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'statistics_subregion';
  $path_breadcrumb->name = 'Statistics Subregion';
  $path_breadcrumb->path = 'statistics/%subregion';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Statistiken',
    ),
    'paths' => array(
      0 => 'statistics',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'subregion' => array(
        'position' => 1,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
          'use_tail' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -49;
  $export['statistics_subregion'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'users';
  $path_breadcrumb->name = 'Users';
  $path_breadcrumb->path = 'user/%user';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Personen',
    ),
    'paths' => array(
      0 => 'people',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'User: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/*/edit
user/*/edit/*',
          ),
          'context' => 'empty',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -74;
  $export['users'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'users_clone';
  $path_breadcrumb->name = 'Users organisations';
  $path_breadcrumb->path = 'user/%user/organisations';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%user:name',
      1 => 'Zugehörigkeit pflegen',
    ),
    'paths' => array(
      0 => 'people',
      1 => 'user/%user:uid/organisations',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'User: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/*/edit
user/*/edit/*',
          ),
          'context' => 'empty',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -74;
  $export['users_clone'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'users_edit';
  $path_breadcrumb->name = 'Users';
  $path_breadcrumb->path = 'user/%user/%sub';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Personen',
      1 => '%user:name',
    ),
    'paths' => array(
      0 => 'people',
      1 => 'user/%user:uid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'User: ID',
        ),
      ),
      'sub' => array(
        'position' => 2,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -73;
  $export['users_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'users_edit_profile';
  $path_breadcrumb->name = 'Users';
  $path_breadcrumb->path = 'user/%user';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Personen',
      1 => '%user:name',
    ),
    'paths' => array(
      0 => 'people',
      1 => 'user/%user:uid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'User: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -69;
  $export['users_edit_profile'] = $path_breadcrumb;

  return $export;
}
