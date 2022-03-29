<?php
/**
 * @file
 * salto_activity.heartbeat.inc
 */

/**
 * Implements hook_heartbeat_stream_info().
 */
function salto_activity_heartbeat_stream_info() {
  $export = array();

  $heartbeatstream = new HeartbeatStreamConfig();
  $heartbeatstream->disabled = FALSE; /* Edit this to true to make a default heartbeatstream disabled initially */
  $heartbeatstream->api_version = 1;
  $heartbeatstream->class = 'kbactivity';
  $heartbeatstream->real_class = 'siteactivity';
  $heartbeatstream->name = 'Site activity';
  $heartbeatstream->module = 'heartbeat_defaults';
  $heartbeatstream->title = 'Knowledge base activity';
  $heartbeatstream->path = 'streams/siteactivity.inc';
  $heartbeatstream->settings = array(
    'settings__active_tab' => 'edit-settings-fs-blocks',
    'messages_denied' => array(
      'heartbeat_edit_account' => 'heartbeat_edit_account',
      'heartbeat_tweet' => 'heartbeat_tweet',
      'heartbeat_add_node' => 0,
      'heartbeat_add_comment' => 0,
      'heartbeat_edit_node' => 0,
    ),
    'skip_active_user' => 0,
    'show_message_times' => 1,
    'show_message_times_grouped' => 1,
    'poll_messages' => '0',
    'poll_messages_type' => '0',
    'num_load_max' => '40',
    'grouping_seconds' => '7200',
    'has_block' => 1,
    'block_items_max' => '20',
    'block_show_pager' => '2',
    'block_view_mode' => 'membership_compact',
    'stream_path' => '',
    'stream_profile_path' => '',
    'page_items_max' => '8',
    'page_show_pager' => 1,
    'page_pager_ajax' => 1,
    'page_view_mode' => 'full',
    'exclude_og' => 0,
  );
  $heartbeatstream->variables = array();
  $export['kbactivity'] = $heartbeatstream;

  return $export;
}
