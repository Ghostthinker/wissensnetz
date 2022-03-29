<?php

/**
 * @file
 * onsite_notification.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function onsite_notification_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_base|default';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_base';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'message_flags' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_base|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_base|full';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_base';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'message_flags' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_base|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_create_comment_reply|default';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_create_comment_reply';
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
  $export['message|notification_create_comment_reply|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_create_comment_reply|message_mail';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_create_comment_reply';
  $ds_fieldsetting->view_mode = 'message_mail';
  $ds_fieldsetting->settings = array(
    'notification_content_preview' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_create_comment_reply|message_mail'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_create_comment|default';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_create_comment';
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
  $export['message|notification_create_comment|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_create_comment|message_mail';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_create_comment';
  $ds_fieldsetting->view_mode = 'message_mail';
  $ds_fieldsetting->settings = array(
    'notification_content_preview' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_create_comment|message_mail'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_group_invite_recieved|default';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_group_invite_recieved';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'notification_content_preview' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_group_invite_recieved|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_group_invite_recieved|membership_compact';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_group_invite_recieved';
  $ds_fieldsetting->view_mode = 'membership_compact';
  $ds_fieldsetting->settings = array(
    'notification_content_preview' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_group_invite_recieved|membership_compact'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_group_invite_recieved|message_mail';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_group_invite_recieved';
  $ds_fieldsetting->view_mode = 'message_mail';
  $ds_fieldsetting->settings = array(
    'notification_content_preview' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_group_invite_recieved|message_mail'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_group_post_created|default';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_group_post_created';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'message_flags' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_group_post_created|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_material_updated|default';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_material_updated';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'notification_content_preview' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_material_updated|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_private_message_received|message_mail';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_private_message_received';
  $ds_fieldsetting->view_mode = 'message_mail';
  $ds_fieldsetting->settings = array(
    'notification_content_preview' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_private_message_received|message_mail'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_revision_created|default';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_revision_created';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'message_flags' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_revision_created|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'message|notification_revision_created|full';
  $ds_fieldsetting->entity_type = 'message';
  $ds_fieldsetting->bundle = 'notification_revision_created';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'message_flags' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['message|notification_revision_created|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function onsite_notification_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'message_flags';
  $ds_field->label = 'message_flags';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'message' => 'message',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
print onsite_notification_message_node_flags($entity)
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['message_flags'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'notification_content_preview';
  $ds_field->label = 'message_content_preview';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'message' => 'message',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
print onsite_notification_context_preview($entity, $view_mode);
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['notification_content_preview'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function onsite_notification_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_base|default';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_base';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'message__message_text__0',
        1 => 'message_flags',
      ),
    ),
    'fields' => array(
      'message__message_text__0' => 'ds_content',
      'message_flags' => 'ds_content',
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
  $export['message|notification_base|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_base|full';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_base';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'message__message_text__0',
        1 => 'message_flags',
      ),
    ),
    'fields' => array(
      'message__message_text__0' => 'ds_content',
      'message_flags' => 'ds_content',
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
  $export['message|notification_base|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_create_comment_reply|default';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_create_comment_reply';
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
  $export['message|notification_create_comment_reply|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_create_comment_reply|membership_compact';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_create_comment_reply';
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
  $export['message|notification_create_comment_reply|membership_compact'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_create_comment_reply|message_mail';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_create_comment_reply';
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
  $export['message|notification_create_comment_reply|message_mail'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_create_comment|default';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_create_comment';
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
  $export['message|notification_create_comment|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_create_comment|membership_compact';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_create_comment';
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
  $export['message|notification_create_comment|membership_compact'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_create_comment|message_mail';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_create_comment';
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
  $export['message|notification_create_comment|message_mail'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_group_invite_recieved|default';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_group_invite_recieved';
  $ds_layout->view_mode = 'default';
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
  $export['message|notification_group_invite_recieved|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_group_invite_recieved|membership_compact';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_group_invite_recieved';
  $ds_layout->view_mode = 'membership_compact';
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
  $export['message|notification_group_invite_recieved|membership_compact'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_group_invite_recieved|message_mail';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_group_invite_recieved';
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
  $export['message|notification_group_invite_recieved|message_mail'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_group_post_created|default';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_group_post_created';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'message__message_text__0',
        1 => 'message_flags',
      ),
    ),
    'fields' => array(
      'message__message_text__0' => 'ds_content',
      'message_flags' => 'ds_content',
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
  $export['message|notification_group_post_created|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_material_updated|default';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_material_updated';
  $ds_layout->view_mode = 'default';
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
    'layout_disable_css' => FALSE,
  );
  $export['message|notification_material_updated|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_private_message_received|default';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_private_message_received';
  $ds_layout->view_mode = 'default';
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
  $export['message|notification_private_message_received|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_private_message_received|membership_compact';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_private_message_received';
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
  $export['message|notification_private_message_received|membership_compact'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_private_message_received|message_mail';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_private_message_received';
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
  $export['message|notification_private_message_received|message_mail'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_revision_created|default';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_revision_created';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'message__message_text__0',
        1 => 'message_flags',
      ),
    ),
    'fields' => array(
      'message__message_text__0' => 'ds_content',
      'message_flags' => 'ds_content',
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
  $export['message|notification_revision_created|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_revision_created|form';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_revision_created';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_notification_audience',
        1 => 'field_notification_link',
        2 => 'field_notification_node_ref',
        3 => 'field_notification_comment_ref',
      ),
    ),
    'fields' => array(
      'field_notification_audience' => 'ds_content',
      'field_notification_link' => 'ds_content',
      'field_notification_node_ref' => 'ds_content',
      'field_notification_comment_ref' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
  );
  $export['message|notification_revision_created|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'message|notification_revision_created|full';
  $ds_layout->entity_type = 'message';
  $ds_layout->bundle = 'notification_revision_created';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'message__message_text__0',
        1 => 'message_flags',
      ),
    ),
    'fields' => array(
      'message__message_text__0' => 'ds_content',
      'message_flags' => 'ds_content',
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
  $export['message|notification_revision_created|full'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function onsite_notification_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'membership_compact';
  $ds_view_mode->label = 'compact';
  $ds_view_mode->entities = array(
    'heartbeat_activity' => 'heartbeat_activity',
    'message' => 'message',
    'node' => 'node',
    'og_membership' => 'og_membership',
  );
  $export['membership_compact'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'message_mail';
  $ds_view_mode->label = 'Mail';
  $ds_view_mode->entities = array(
    'message' => 'message',
  );
  $export['message_mail'] = $ds_view_mode;

  return $export;
}
