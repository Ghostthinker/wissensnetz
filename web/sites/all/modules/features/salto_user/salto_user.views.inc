<?php
/**
 * @file some views extensions for users
 */

/**
 * Implementation of hook_views_data().
 */
function salto_user_views_data() {
    // Is user online boolean (virtual field).
  $data['users']['is_online'] = array(
    'title' => t('Is online'),
    'help' => t('Shows whether the user is online'),
    'field' => array(
      'handler' => 'salto_user_handler_field_is_online',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'salto_user_handler_sort_is_online',
    ),
    'filter' => array(
      'handler' => 'salto_user_handler_filter_is_online',
      'label' => t('Online'),
    ),
  );
  $data['users']['membership_request_button'] = array(
    'title' => t('Membership request button'),
    'help' => t('For accept or decline of request'),
    'field' => array(
      'handler' => 'salto_user_handler_field_membership_request_button',
      'click sortable' => FALSE,
    )
  );
  return $data;
}
