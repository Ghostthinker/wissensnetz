<?php

/**
 * Implements hook_views_data_alter().
 */
function views_bulk_operations_multipage_views_data_alter(&$data) {
  foreach (entity_get_info() as $entity_type => $info) {
    if (isset($info['base table']) && isset($data[$info['base table']]['table'])) {
      $handler = &$data['views_entity_' . $entity_type]['views_bulk_operations']['field']['handler'];
      $handler = 'views_bulk_operations_multipage_handler_field_operations';
    }
    if (isset($info['revision table']) && isset($data[$info['revision table']]['table'])) {
      $handler = &$data[$info['revision table']]['views_bulk_operations']['field']['handler'];
      $handler = 'views_bulk_operations_multipage_handler_field_operations';
    }
  }
}
