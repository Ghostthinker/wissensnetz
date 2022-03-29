<?php


/**
 * Implements hook_query_privatemsg_autocomplete_alter().
 */
function salto_user_query_privatemsg_autocomplete_alter(SelectQueryInterface $query) {


  $conditions = &$query->conditions();
  foreach ($conditions as $key => &$condition) {
    //add a % to the like query in order to be abel to search for real last names
    if (isset($condition['field']) && is_string($condition['field']) && $condition['field'] == 'r.realname' && $condition['operator'] == 'LIKE') {
      $condition['value'] = '%' . $condition['value'];
    }
  }

}
