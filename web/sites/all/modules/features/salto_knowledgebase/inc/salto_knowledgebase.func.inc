<?php
/**
 * @file functions and helper for salto_knowledgebase
 */

/**
 * Get all authors of a node
 *
 * @param  [type] $node [description]
 *
 * @return [type]       [description]
 */
function salto_knowledgebase_post_get_authors($node) {

  $data = &drupal_static(__FUNCTION__);
  if (empty($data[$node->nid])) {
    $authors = [];
    if (!empty($node->field_post_authors[LANGUAGE_NONE])) {
      foreach ($node->field_post_authors[LANGUAGE_NONE] as $key => $value) {
        if (!empty($value['target_id'])) {
          //ignore deleted and anonymous
          $authors[$value['target_id']] = $value['target_id'];
        }
      }
    }
    $data[$node->nid] = $authors;
  }
  return $data[$node->nid];
}

/**
 * Get all   revisions authors of a node. sorted alphabetically
 *
 * @param  [type] $nid [description]
 *
 * @return [type]      [description]
 */
function salto_knowledgebase_post_get_revision_authors($nid) {
  $query = db_select('users', 'u');
  $query->join('realname', 'rn', 'rn.uid = u.uid');
  $query->join('node_revision', 'nr', 'nr.uid = u.uid');

  $result = $query->fields('nr', ['uid'])
    ->condition('nr.nid', $nid, '=')
    ->condition('nr.status', 0, '>')
    ->condition('u.uid', 1, '!=')
    ->condition('u.uid', 0, '!=')
    ->groupBy('nr.uid')
    ->orderBy('rn.realname', 'ASC')
    ->execute()
    ->fetchAllKeyed();

  return array_keys($result);
}

/**
 * Get all revisions and authors of a node in a specified timespan
 *
 * @param  [type] $nid [description]
 *
 * @return [type]      [description]
 */
function salto_knowledgebase_post_get_revision_and_authors($nid, $created_from = NULL) {
  $query = db_select('users', 'u');
  $query->join('realname', 'rn', 'rn.uid = u.uid');
  $query->join('node_revision', 'nr', 'nr.uid = u.uid');

  $query->fields('nr', ['nid', 'uid'])
    ->condition('nr.nid', $nid, '=')
    ->condition('nr.status', 0, '>')
    // ->condition('rid', 5,'!=') //exclude ghost roles
    ->condition('u.uid', 1, '!=') //exclude admin
    ->condition('u.uid', 0, '!='); //exclude guest

  //set created from
  if ($created_from > 0) {
    $query->condition('nr.crated', $created_from, '>='); //created > created_from
  }

  $result = $query->groupBy('nr.uid')
    ->orderBy('rn.realname', 'ASC')
    ->execute()
    ->fetchAllKeyed();

  return $result;
}

/**
 * Get a list of all organisations of the authors in the array.
 *
 * @param array $authors an array with uids
 *
 * @return [type]          [description]
 */
function salto_knowledgebase_get_author_organisations($authors) {
  $ogs = [];

  if (empty($authors)) {
    return [];
  }

  foreach ($authors as $account) {
    $groups = og_get_entity_groups('user', $account);

    if (!empty($groups['node'])) {
      $ogs_all = array_values($groups['node']);

      foreach ($ogs_all as $key => $nid) {
        //check nid type
        $type = db_query('Select type from node where nid = :nid', [':nid' => $nid])->fetchField();
        if ($type == 'organisation') {
          $ogs[$nid] = $nid;
        }
      }
    }
  }

  return $ogs;
}
