<?php
/**
 * @file
 * salto_share.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function salto_share_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_shared_post|default';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_shared_post';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'message_flags' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'notification_content_preview' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_shared_post|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_shared_post|message_mail';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_shared_post';
  $ds_fieldsetting->view_mode = 'message_mail';
  $ds_fieldsetting->settings = array(
    'notification_content_preview' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_shared_post|message_mail'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function salto_share_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_shared_post|default';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_shared_post';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'message__message_text__0',
        1 => 'message_flags',
        2 => 'notification_content_preview',
      ),
    ),
    'fields' => array(
      'message__message_text__0' => 'ds_content',
      'message_flags' => 'ds_content',
      'notification_content_preview' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['message|notification_shared_post|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_shared_post|membership_compact';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_shared_post';
  $ds_layout->view_mode = 'membership_compact';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'message__message_text__0',
      ),
    ),
    'fields' => array(
      'message__message_text__0' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['message|notification_shared_post|membership_compact'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_shared_post|message_mail';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_shared_post';
  $ds_layout->view_mode = 'message_mail';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'message__message_text__0',
        1 => 'notification_content_preview',
      ),
    ),
    'fields' => array(
      'message__message_text__0' => 'ds_content',
      'notification_content_preview' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['message|notification_shared_post|message_mail'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function salto_share_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'shared_post';
  $ds_view_mode->label = 'shared_post';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['shared_post'] = $ds_view_mode;

  return $export;
}
