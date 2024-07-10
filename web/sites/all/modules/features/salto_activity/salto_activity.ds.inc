<?php

/**
 * @file
 * salto_activity.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function salto_activity_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'heartbeat_activity|heartbeat_add_comment|default';
  $ds_fieldsetting->entity_type = 'heartbeat_activity';
  $ds_fieldsetting->bundle = 'heartbeat_add_comment';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'heartbeat_content_preview' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'heartbeat_type_symbol' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'test3' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['heartbeat_activity|heartbeat_add_comment|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'heartbeat_activity|heartbeat_add_comment|membership_compact';
  $ds_fieldsetting->entity_type = 'heartbeat_activity';
  $ds_fieldsetting->bundle = 'heartbeat_add_comment';
  $ds_fieldsetting->view_mode = 'membership_compact';
  $ds_fieldsetting->settings = array(
    'heartbeat_type_symbol' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['heartbeat_activity|heartbeat_add_comment|membership_compact'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'heartbeat_activity|heartbeat_add_node|default';
  $ds_fieldsetting->entity_type = 'heartbeat_activity';
  $ds_fieldsetting->bundle = 'heartbeat_add_node';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'heartbeat_content_preview' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'heartbeat_type_symbol' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'test3' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['heartbeat_activity|heartbeat_add_node|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'heartbeat_activity|heartbeat_add_node|membership_compact';
  $ds_fieldsetting->entity_type = 'heartbeat_activity';
  $ds_fieldsetting->bundle = 'heartbeat_add_node';
  $ds_fieldsetting->view_mode = 'membership_compact';
  $ds_fieldsetting->settings = array(
    'heartbeat_type_symbol' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['heartbeat_activity|heartbeat_add_node|membership_compact'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'heartbeat_activity|heartbeat_edit_account|default';
  $ds_fieldsetting->entity_type = 'heartbeat_activity';
  $ds_fieldsetting->bundle = 'heartbeat_edit_account';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'heartbeat_content_preview' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'heartbeat_type_symbol' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'test3' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['heartbeat_activity|heartbeat_edit_account|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'heartbeat_activity|heartbeat_edit_node|default';
  $ds_fieldsetting->entity_type = 'heartbeat_activity';
  $ds_fieldsetting->bundle = 'heartbeat_edit_node';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'heartbeat_content_preview' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'heartbeat_type_symbol' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'test3' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['heartbeat_activity|heartbeat_edit_node|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'heartbeat_activity|heartbeat_edit_node|membership_compact';
  $ds_fieldsetting->entity_type = 'heartbeat_activity';
  $ds_fieldsetting->bundle = 'heartbeat_edit_node';
  $ds_fieldsetting->view_mode = 'membership_compact';
  $ds_fieldsetting->settings = array(
    'heartbeat_type_symbol' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['heartbeat_activity|heartbeat_edit_node|membership_compact'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'heartbeat_activity|heartbeat_tweet|default';
  $ds_fieldsetting->entity_type = 'heartbeat_activity';
  $ds_fieldsetting->bundle = 'heartbeat_tweet';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'heartbeat_content_preview' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'heartbeat_type_symbol' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'test3' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['heartbeat_activity|heartbeat_tweet|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function salto_activity_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'heartbeat_content_preview';
  $ds_field->label = 'heartbeat_content_preview';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'heartbeat_activity' => 'heartbeat_activity',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php 
  print check_markup($entity->variables[\'!node_preview\'], "editor");
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['heartbeat_content_preview'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'heartbeat_type_symbol';
  $ds_field->label = 'heartbeat_type_symbol';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'heartbeat_activity' => 'heartbeat_activity',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php 
print salto_core_heartbeat_type_symbol($entity); 
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['heartbeat_type_symbol'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'test3';
  $ds_field->label = 'heartbeat_avatar_field';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'heartbeat_activity' => 'heartbeat_activity',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php 
//dpm( $entity);
$account= $entity->actor;
$link_text = theme(\'user_picture\', array(\'account\' => $account, \'style\' => \'user_60x60\'));

print $link_text;
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['test3'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function salto_activity_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'heartbeat_activity|heartbeat_add_comment|membership_compact';
  $ds_layout->entity_type = 'heartbeat_activity';
  $ds_layout->bundle = 'heartbeat_add_comment';
  $ds_layout->view_mode = 'membership_compact';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'heartbeat_type_symbol',
        1 => 'message',
        2 => 'time',
      ),
    ),
    'fields' => array(
      'heartbeat_type_symbol' => 'ds_content',
      'message' => 'ds_content',
      'time' => 'ds_content',
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
  $export['heartbeat_activity|heartbeat_add_comment|membership_compact'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'heartbeat_activity|heartbeat_add_node|membership_compact';
  $ds_layout->entity_type = 'heartbeat_activity';
  $ds_layout->bundle = 'heartbeat_add_node';
  $ds_layout->view_mode = 'membership_compact';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'heartbeat_type_symbol',
        1 => 'message',
        2 => 'time',
      ),
    ),
    'fields' => array(
      'heartbeat_type_symbol' => 'ds_content',
      'message' => 'ds_content',
      'time' => 'ds_content',
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
  $export['heartbeat_activity|heartbeat_add_node|membership_compact'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'heartbeat_activity|heartbeat_edit_node|membership_compact';
  $ds_layout->entity_type = 'heartbeat_activity';
  $ds_layout->bundle = 'heartbeat_edit_node';
  $ds_layout->view_mode = 'membership_compact';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'heartbeat_type_symbol',
        1 => 'message',
        2 => 'time',
      ),
    ),
    'fields' => array(
      'heartbeat_type_symbol' => 'ds_content',
      'message' => 'ds_content',
      'time' => 'ds_content',
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
  $export['heartbeat_activity|heartbeat_edit_node|membership_compact'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function salto_activity_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'heartbeat_compact';
  $ds_view_mode->label = 'heartbeat_compact';
  $ds_view_mode->entities = array(
    'heartbeat_activity' => 'heartbeat_activity',
  );
  $export['heartbeat_compact'] = $ds_view_mode;

  return $export;
}
