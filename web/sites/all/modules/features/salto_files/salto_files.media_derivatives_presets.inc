<?php

/**
 * @file
 * salto_files.media_derivatives_presets.inc
 */

/**
 * Implements hook_media_derivatives_presets().
 */
function salto_files_media_derivatives_presets() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->machine_name = 'audio_mp3';
  $preset->engine = 'media_derivatives_ffmpeg';
  $preset->engine_settings = array(
    'ffmpeg_options' => '',
    'ffmpeg_out_options' => '-b:a 192K -vn',
    'ffmpeg_extension' => 'mp3',
  );
  $preset->conditions = array(
    0 => 'file_type',
    1 => 'mime_type',
  );
  $preset->conditions_settings = array(
    'type' => 'audio',
    'file_type_negate' => 0,
    'mime_types' => array(
      0 => 'audio/*',
    ),
    'mime_type_negate' => 0,
  );
  $preset->events = array(
    0 => 'file_insert',
    1 => 'field_insertupdate',
  );
  $preset->events_settings = array(
    'field_insertupdate_allowed_fields' => array(
      'field_post_attachment' => 'field_post_attachment',
      'field_user_picture' => 0,
      'field_page_attachment' => 0,
      'field_educoncept_file' => 0,
    ),
  );
  $preset->scheduler = 'scheduler_immediate';
  $preset->scheduler_settings = array();
  $preset->settings = array(
    'type' => '0',
    'recursive_delete' => 1,
    'delete_source' => 0,
    'user' => '0',
  );
  $export['audio_mp3'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->machine_name = 'document';
  $preset->engine = 'media_derivatives_document';
  $preset->engine_settings = array(
    'bildungsnetz_convert_endpoint' => '',
    'document_output' => '',
    'document_extension' => 'jpg',
  );
  $preset->conditions = array(
    0 => 'file_type',
    1 => 'mime_type',
  );
  $preset->conditions_settings = array(
    'type' => 'document',
    'file_type_negate' => 0,
    'mime_types' => array(
      0 => '',
    ),
    'mime_type_negate' => 0,
  );
  $preset->events = array(
    0 => 'file_insert',
    1 => 'field_insertupdate',
  );
  $preset->events_settings = array(
    'field_insertupdate_allowed_fields' => array(
      'field_post_attachment' => 'field_post_attachment',
      'field_user_picture' => 0,
      'field_page_attachment' => 0,
      'field_educoncept_file' => 0,
    ),
  );
  $preset->scheduler = 'scheduler_immediate';
  $preset->scheduler_settings = array(
    'immediate_skip_bp' => 1,
  );
  $preset->settings = array(
    'type' => '0',
    'recursive_delete' => 1,
    'delete_source' => 0,
    'user' => '0',
  );
  $export['document'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->machine_name = 'video_mp4';
  $preset->engine = 'media_derivatives_ffmpeg';
  $preset->engine_settings = array(
    'ffmpeg_options' => '',
    'ffmpeg_out_options' => '-metadata:s:v rotate="0"  -vf "scale=1280:720:force_original_aspect_ratio=decrease,pad=1280:720:(ow-iw)/2:(oh-ih)/2" -threads 10  -pix_fmt yuv420p -crf 20 -ab 128k -ac 2 -vcodec libx264',
    'ffmpeg_extension' => 'mp4',
  );
  $preset->conditions = array(
    0 => 'file_type',
    1 => 'mime_type',
  );
  $preset->conditions_settings = array(
    'type' => 'video',
    'file_type_negate' => 0,
    'mime_types' => array(
      0 => '',
    ),
    'mime_type_negate' => 0,
  );
  $preset->events = array(
    0 => 'file_insert',
    1 => 'field_insertupdate',
  );
  $preset->events_settings = array(
    'field_insertupdate_allowed_fields' => array(
      'field_post_attachment' => 'field_post_attachment',
      'field_user_picture' => 0,
      'field_page_attachment' => 0,
      'field_educoncept_file' => 0,
    ),
  );
  $preset->scheduler = 'scheduler_immediate';
  $preset->scheduler_settings = array();
  $preset->settings = array(
    'type' => '0',
    'recursive_delete' => 1,
    'delete_source' => 0,
    'user' => '0',
  );
  $export['video_mp4'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->machine_name = 'video_thumbnail';
  $preset->engine = 'media_derivatives_ffmpeg';
  $preset->engine_settings = array(
    'ffmpeg_options' => '',
    'ffmpeg_out_options' => '-an -ss 00:00:01 -r 1 -vframes 1 -y',
    'ffmpeg_extension' => 'jpg',
  );
  $preset->conditions = array(
    0 => 'file_type',
    1 => 'mime_type',
  );
  $preset->conditions_settings = array(
    'type' => 'video',
    'file_type_negate' => 0,
    'mime_types' => array(
      0 => '',
    ),
    'mime_type_negate' => 0,
  );
  $preset->events = array(
    0 => 'file_insert',
    1 => 'field_insertupdate',
  );
  $preset->events_settings = array(
    'field_insertupdate_allowed_fields' => array(
      'field_post_attachment' => 'field_post_attachment',
      'field_user_picture' => 0,
      'field_page_attachment' => 0,
      'field_educoncept_file' => 0,
    ),
  );
  $preset->scheduler = 'scheduler_immediate';
  $preset->scheduler_settings = array(
    'immediate_skip_bp' => 1,
  );
  $preset->settings = array(
    'type' => '0',
    'recursive_delete' => 1,
    'delete_source' => 0,
    'user' => '0',
  );
  $export['video_thumbnail'] = $preset;

  return $export;
}
