<?php
/**
 * @file some views extensions for users
 */

/**
 * Implementation of hook_views_data().
 */
function salto_group_views_data() {
    // Group member count boolean (virtual field).
  $data['users']['group_member_count'] = array(
    'title' => t('Group size'),
    'help' => t('Filters member count'),
    'filter' => array(
      'handler' => 'salto_group_handler_filter_group_member_count',
      'label' => t('Group size'),
    ),
  );

  return $data;
}
