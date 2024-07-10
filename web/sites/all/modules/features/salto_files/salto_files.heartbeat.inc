<?php

/**
 * @file
 * salto_files.heartbeat.inc
 */

/**
 * Implements hook_heartbeat_template_info().
 */
function salto_files_heartbeat_template_info() {
  $export = array();

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'heartbeat_video_add';
  $heartbeatmessagetemplate->description = 'When a user uploads a video';
  $heartbeatmessagetemplate->message = '!username hat das Video !title hochgeladen.';
  $heartbeatmessagetemplate->message_concat = '!username hat das Video %title% hochgeladen.';
  $heartbeatmessagetemplate->perms = 4;
  $heartbeatmessagetemplate->group_type = 'summary';
  $heartbeatmessagetemplate->concat_args = array(
    'group_by' => 'user',
    'group_target' => 'title',
    'group_by_target' => 'username',
    'group_num_max' => '4',
    'merge_separator' => ', ',
    'merge_end_separator' => ' und ',
    'roles' => array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!username' => '',
    '!title' => '',
  );
  $heartbeatmessagetemplate->attachments = array();
  $export['heartbeat_video_add'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'heartbeat_video_react';
  $heartbeatmessagetemplate->description = 'When a user reacts to a video';
  $heartbeatmessagetemplate->message = '!username hat mit !emoji auf das Video !title reagiert.';
  $heartbeatmessagetemplate->message_concat = '%username% haben auf das Video !title reagiert.';
  $heartbeatmessagetemplate->perms = 4;
  $heartbeatmessagetemplate->group_type = 'summary';
  $heartbeatmessagetemplate->concat_args = array(
    'group_by' => 'node',
    'group_target' => 'username',
    'group_by_target' => 'title',
    'group_num_max' => '4',
    'merge_separator' => ', ',
    'merge_end_separator' => ' und ',
    'roles' => array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!username' => '',
    '!emoji' => '',
    '!title' => '',
  );
  $heartbeatmessagetemplate->attachments = array();
  $export['heartbeat_video_react'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'heartbeat_video_update';
  $heartbeatmessagetemplate->description = 'When a user updates a video';
  $heartbeatmessagetemplate->message = '!username hat das Video !title aktualisiert.';
  $heartbeatmessagetemplate->message_concat = '!username hat das Video %title% aktualisiert.';
  $heartbeatmessagetemplate->perms = 4;
  $heartbeatmessagetemplate->group_type = 'summary';
  $heartbeatmessagetemplate->concat_args = array(
    'group_by' => 'user',
    'group_target' => 'title',
    'group_by_target' => 'username',
    'group_num_max' => '4',
    'merge_separator' => ', ',
    'merge_end_separator' => ' und ',
    'roles' => array(
      2 => '2',
      1 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!username' => '',
    '!title' => '',
  );
  $heartbeatmessagetemplate->attachments = array();
  $export['heartbeat_video_update'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'heartbeat_videocomment_add';
  $heartbeatmessagetemplate->description = 'When a user creates a videocomment';
  $heartbeatmessagetemplate->message = '<span>!username hat das Video !videotitle an der Stelle !timecode kommentiert</span><cite><blockquote>!comment</blockquote></cite>';
  $heartbeatmessagetemplate->message_concat = '';
  $heartbeatmessagetemplate->perms = 4;
  $heartbeatmessagetemplate->group_type = 'single';
  $heartbeatmessagetemplate->concat_args = array(
    'group_by' => 'none',
    'group_target' => '',
    'group_by_target' => '',
    'group_num_max' => '',
    'merge_separator' => '',
    'merge_end_separator' => '',
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!username' => '',
    '!videotitle' => '',
    '!timecode' => '',
    '!comment' => '',
  );
  $heartbeatmessagetemplate->attachments = array();
  $export['heartbeat_videocomment_add'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'heartbeat_videocomment_react';
  $heartbeatmessagetemplate->description = 'When a user reacts to a videocomment';
  $heartbeatmessagetemplate->message = '<span>!username hat mit !emoji auf den Videokommentar an der Stelle !timecode des Videos !videotitle reagiert.</span><cite><blockquote>!comment</blockquote></cite>';
  $heartbeatmessagetemplate->message_concat = '<span>%username% haben auf den Videokommentar an der Stelle !timecode des Videos !videotitle reagiert.</span><cite><blockquote>!comment</blockquote></cite>';
  $heartbeatmessagetemplate->perms = 4;
  $heartbeatmessagetemplate->group_type = 'summary';
  $heartbeatmessagetemplate->concat_args = array(
    'group_by' => 'user-user',
    'group_target' => 'username',
    'group_by_target' => 'cid',
    'group_num_max' => '4',
    'merge_separator' => ', ',
    'merge_end_separator' => ' und ',
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!username' => '',
    '!emoji' => '',
    '!timecode' => '',
    '!videotitle' => '',
    '!comment' => '',
  );
  $heartbeatmessagetemplate->attachments = array();
  $export['heartbeat_videocomment_react'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'heartbeat_videocomment_recomment';
  $heartbeatmessagetemplate->description = 'When a user recomments';
  $heartbeatmessagetemplate->message = '<span>!username hat auf den Videokommentar an der Stelle !timecode des Videos !videotitle geantwortet.</span><cite><blockquote>!comment</blockquote></cite>';
  $heartbeatmessagetemplate->message_concat = '';
  $heartbeatmessagetemplate->perms = 4;
  $heartbeatmessagetemplate->group_type = 'single';
  $heartbeatmessagetemplate->concat_args = array(
    'group_by' => 'none',
    'group_target' => '',
    'group_by_target' => '',
    'group_num_max' => '',
    'merge_separator' => '',
    'merge_end_separator' => '',
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
      4 => 0,
      5 => 0,
      6 => 0,
      7 => 0,
      8 => 0,
      9 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!username' => '',
    '!timecode' => '',
    '!videotitle' => '',
    '!comment' => '',
  );
  $heartbeatmessagetemplate->attachments = array();
  $export['heartbeat_videocomment_recomment'] = $heartbeatmessagetemplate;

  return $export;
}
