<?php


/**
 * A new notification has been created
 * @param  [type] $message [description]
 * @return [type]          [description]
 */
function hook_onsite_notification_created($message) {
  drupal_set_message(t('default message'), 'status', FALSE);
}

/**
 * The content preview for messages
 * @param  [type] $message [description]
 * @return [type]         [description]
 */
function hook_onsite_notification_content_preview($message) {
  if($message->type == "default_message_type") {
    return "default message text";
  }
}
