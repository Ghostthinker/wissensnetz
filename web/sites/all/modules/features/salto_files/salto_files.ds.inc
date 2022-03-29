<?php

/**
 * @file
 * salto_files.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function salto_files_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|audio|default';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'audio';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'file_comments_form' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'file_views_count' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'files_rating_view' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_metadata' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_rating_action' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_usage_license' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'action_links' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:4:{s:4:"type";s:4:"file";s:7:"context";a:3:{i:0;s:5:"empty";i:1;s:5:"empty";i:2;s:25:"argument_entity_id:file_1";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:12:"action_links";s:7:"subtype";s:12:"action_links";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'classes' => 'pane-content',
        ),
      ),
    ),
    'field_file_license_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['file|audio|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|audio|listing';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'audio';
  $ds_fieldsetting->view_mode = 'listing';
  $ds_fieldsetting->settings = array(
    'download_link' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb' => 'Herunterladen',
        ),
      ),
    ),
    'file_title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'file_views_count' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'files_rating_view' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'submitted' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'submitted',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_file_license_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_file_originator' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['file|audio|listing'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|document|default';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'file_comments_form' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'file_title_heading' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'file_views_count' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'files_rating_view' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_metadata' => array(
      'weight' => '14',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_rating_action' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_usage_license' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'action_links' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:4:{s:4:"type";s:4:"file";s:7:"context";a:3:{i:0;s:5:"empty";i:1;s:5:"empty";i:2;s:25:"argument_entity_id:file_1";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:12:"action_links";s:7:"subtype";s:12:"action_links";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'classes' => 'pane-content',
        ),
      ),
    ),
    'field_file_license_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['file|document|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|document|listing';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'listing';
  $ds_fieldsetting->settings = array(
    'download_link' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb' => 'Herunterladen',
        ),
      ),
    ),
    'file_title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'file_views_count' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'files_rating_view' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'submitted' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'submitted',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_file_license_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_file_originator' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['file|document|listing'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|image|default';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'image';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'file_comments_form' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'file_title_heading' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'file_views_count' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'classes' => 'pane-content',
        ),
      ),
    ),
    'files_rating_view' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_metadata' => array(
      'weight' => '16',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_rating_action' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_usage_license' => array(
      'weight' => '15',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
    'action_links' => array(
      'weight' => '14',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:4:{s:4:"type";s:4:"file";s:7:"context";a:3:{i:0;s:5:"empty";i:1;s:5:"empty";i:2;s:25:"argument_entity_id:file_1";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:12:"action_links";s:7:"subtype";s:12:"action_links";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'classes' => 'pane-content',
        ),
      ),
    ),
    'field_file_license_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['file|image|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|image|listing';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'image';
  $ds_fieldsetting->view_mode = 'listing';
  $ds_fieldsetting->settings = array(
    'download_link' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb' => 'Herunterladen',
        ),
      ),
    ),
    'file_title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'file_views_count' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'files_rating_view' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'submitted' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'submitted',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_file_license_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_file_originator' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['file|image|listing'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|swf|default';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'swf';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'file_comments_form' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'file_title_heading' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'file_views_count' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'files_rating_view' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_metadata' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_rating_action' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_usage_license' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'action_links' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:4:{s:4:"type";s:4:"file";s:7:"context";a:3:{i:0;s:5:"empty";i:1;s:5:"empty";i:2;s:25:"argument_entity_id:file_1";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:12:"action_links";s:7:"subtype";s:12:"action_links";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'classes' => 'pane-content',
        ),
      ),
    ),
  );
  $export['file|swf|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|swf|listing';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'swf';
  $ds_fieldsetting->view_mode = 'listing';
  $ds_fieldsetting->settings = array(
    'download_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'file_title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'file_views_count' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'files_rating_view' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'submitted' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'submitted',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_file_license_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_file_originator' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['file|swf|listing'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|video|default';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'file_comments_form' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'file_title_heading' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'file_views_count' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'files_rating_view' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_metadata' => array(
      'weight' => '14',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_rating_action' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_usage_license' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'action_links' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:4:{s:4:"type";s:4:"file";s:7:"context";a:3:{i:0;s:5:"empty";i:1;s:5:"empty";i:2;s:25:"argument_entity_id:file_1";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";}s:4:"type";s:12:"action_links";s:7:"subtype";s:12:"action_links";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'classes' => 'pane-content',
        ),
      ),
    ),
    'field_file_license_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['file|video|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|video|listing';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'listing';
  $ds_fieldsetting->settings = array(
    'download_link' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb' => 'Herunterladen',
        ),
      ),
    ),
    'file_title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'file_views_count' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'files_rating_view' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'submitted' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'submitted',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_file_license_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['file|video|listing'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|webresource|default';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'webresource';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'file_comments_form' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'file_title_heading' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'file_views_count' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'files_rating_view' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_metadata' => array(
      'weight' => '14',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_rating_action' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'salto_files_usage_license' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'action_links' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:5:{s:4:"type";s:4:"file";s:7:"context";a:3:{i:0;s:5:"empty";i:1;s:5:"empty";i:2;s:25:"argument_entity_id:file_1";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:12:"action_links";s:7:"subtype";s:12:"action_links";}',
        'load_terms' => 0,
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'classes' => 'pane-content',
        ),
      ),
    ),
    'field_file_license_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['file|webresource|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'file|webresource|listing';
  $ds_fieldsetting->entity_type = 'file';
  $ds_fieldsetting->bundle = 'webresource';
  $ds_fieldsetting->view_mode = 'listing';
  $ds_fieldsetting->settings = array(
    'download_link' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb' => 'Herunterladen',
        ),
      ),
    ),
    'file_title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'h3',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'file_views_count' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'files_rating_view' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'submitted' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'submitted',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_file_license_type' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'pull-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['file|webresource|listing'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function salto_files_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'download_link';
  $ds_field->label = 'Download link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'file' => 'file',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
if (file_entity_access(\'download\', $entity)) {
$uri = file_entity_download_uri($entity);
print l(\'\', $uri[\'path\'], array(\'query\' => $uri[\'options\'][\'query\'], \'attributes\' => array("class" => "icon-download")));
}
',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['download_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'file_comments_form';
  $ds_field->label = 'Datei Kommentare Form';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'file' => 'file',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
if(!empty($entity->field_file_comments[LANGUAGE_NONE][0]["target_id"])) {
  $nid = $entity->field_file_comments[LANGUAGE_NONE][0]["target_id"];
  //print drupal_render(drupal_get_form("comment_node_file_comments_form", (object) array(\'nid\' => $nid)));

  $node = node_load($nid);
  $node_view = array("#node" => $node);
  $node_view = node_view($node);
  $node_view[\'comments\'] = comment_node_page_additions($node);
  //ajax_comments_node_view_alter($node_view);
  print drupal_render($node_view);
 
}

?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['file_comments_form'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'file_title';
  $ds_field->label = 'File Title Link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'file' => 'file',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php 
$title = entity_label(\'file\', $entity); 
print l($title, "file/" . $entity->fid);
?> ',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['file_title'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'file_title_heading';
  $ds_field->label = 'File Title Heading';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'file' => 'file',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php 
$title = entity_label(\'file\', $entity); 
print "<h2>" . $title . "</h2>";
?> ',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['file_title_heading'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'file_views_count';
  $ds_field->label = 'file_views_count';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'file' => 'file',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php

echo salto_files_render_views_count($entity->fid, true);

?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['file_views_count'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'files_rating_view';
  $ds_field->label = 'Files rating view';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'file' => 'file',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
       $field_info = field_info_field(\'field_content_rating\');
      $field_instance = field_info_instance(\'file\', \'field_content_rating\', $entity->type);

      $items = array();
      fivestar_field_prepare_view(\'file\', array($entity->fid => $entity), $field_info, array($entity->fid => $field_instance), LANGUAGE_NONE, $items);
      $items = current($items);


      //render outputs
      $average_output = \'<span>\' . _salto_knowledgebase_render_fivestar_stars(\'file\', $entity, $field_instance, $items, \'average\', \'none\', TRUE) . \'</span>\';


     return $average_output;
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['files_rating_view'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'salto_files_metadata';
  $ds_field->label = 'Datei Metadata';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'file' => 'file',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php

echo theme(\'salto_files_metadata\', array(\'file\' => $entity));

?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['salto_files_metadata'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'salto_files_rating_action';
  $ds_field->label = 'Files rating action';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'file' => 'file',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$field_instance = field_info_instance(\'file\', \'field_content_rating\', $file->type);
return _salto_knowledgebase_render_fivestar_user_stars(\'file\', $entity, $field_instance, $entity->field_content_rating[LANGUAGE_NONE]);
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['salto_files_rating_action'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'salto_files_usage_license';
  $ds_field->label = 'Datei Nutzung';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'file' => 'file',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php

echo theme(\'salto_files_usage_license\', array(\'file\' => $entity));

?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['salto_files_usage_license'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'submitted';
  $ds_field->label = 'submitted';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'file' => 'file',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$datetime = format_date($entity->timestamp);
$username = format_username(user_load($entity->uid));
$username = theme(\'username\', array("account" => user_load($entity->uid)));
print t(\'Submitted by !username on !datetime\', array(\'!datetime\' => $datetime, \'!username\' => $username));
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['submitted'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function salto_files_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|audio|default';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'panels-salto_93';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file',
        1 => 'field_post_tags',
        2 => 'field_file_lizenzstufe',
        3 => 'field_kb_kategorie',
        4 => 'field_file_description',
        5 => 'field_content_rating',
        6 => 'salto_files_rating_action',
        7 => 'file_views_count',
        8 => 'files_rating_view',
        9 => 'file_comments_form',
        10 => 'field_file_license_type',
      ),
      'right' => array(
        11 => 'action_links',
        12 => 'salto_files_usage_license',
        13 => 'salto_files_metadata',
        14 => 'flag_notification_ignore_material',
        15 => 'flag_notification_subscribe_material',
      ),
    ),
    'fields' => array(
      'file' => 'left',
      'field_post_tags' => 'left',
      'field_file_lizenzstufe' => 'left',
      'field_kb_kategorie' => 'left',
      'field_file_description' => 'left',
      'field_content_rating' => 'left',
      'salto_files_rating_action' => 'left',
      'file_views_count' => 'left',
      'files_rating_view' => 'left',
      'file_comments_form' => 'left',
      'field_file_license_type' => 'left',
      'action_links' => 'right',
      'salto_files_usage_license' => 'right',
      'salto_files_metadata' => 'right',
      'flag_notification_ignore_material' => 'right',
      'flag_notification_subscribe_material' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|audio|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|audio|listing';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'audio';
  $ds_layout->view_mode = 'listing';
  $ds_layout->layout = 'panels-file_listing';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file',
      ),
      'right' => array(
        1 => 'file_title',
        2 => 'submitted',
        3 => 'field_file_description',
        4 => 'download_link',
      ),
      'license_left' => array(
        5 => 'field_file_lizenzstufe',
      ),
      'license_middle' => array(
        6 => 'field_file_originator',
      ),
      'license_right' => array(
        7 => 'field_file_license_type',
      ),
      'tags' => array(
        8 => 'field_post_tags',
      ),
      'meta_left' => array(
        9 => 'files_rating_view',
      ),
      'meta_right' => array(
        10 => 'file_views_count',
      ),
    ),
    'fields' => array(
      'file' => 'left',
      'file_title' => 'right',
      'submitted' => 'right',
      'field_file_description' => 'right',
      'download_link' => 'right',
      'field_file_lizenzstufe' => 'license_left',
      'field_file_originator' => 'license_middle',
      'field_file_license_type' => 'license_right',
      'field_post_tags' => 'tags',
      'files_rating_view' => 'meta_left',
      'file_views_count' => 'meta_right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
      'license_left' => 'div',
      'license_middle' => 'div',
      'license_right' => 'div',
      'tags' => 'div',
      'meta_left' => 'div',
      'meta_right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|audio|listing'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|document|default';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'panels-salto_93';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file_title_heading',
        1 => 'file',
        2 => 'field_file_description',
        3 => 'field_file_lizenzstufe',
        4 => 'field_post_tags',
        5 => 'field_kb_kategorie',
        6 => 'field_content_rating',
        7 => 'salto_files_rating_action',
        8 => 'file_views_count',
        9 => 'files_rating_view',
        10 => 'file_comments_form',
        11 => 'field_file_license_type',
      ),
      'right' => array(
        12 => 'action_links',
        13 => 'salto_files_usage_license',
        14 => 'salto_files_metadata',
        15 => 'flag_notification_subscribe_material',
        16 => 'flag_notification_ignore_material',
      ),
    ),
    'fields' => array(
      'file_title_heading' => 'left',
      'file' => 'left',
      'field_file_description' => 'left',
      'field_file_lizenzstufe' => 'left',
      'field_post_tags' => 'left',
      'field_kb_kategorie' => 'left',
      'field_content_rating' => 'left',
      'salto_files_rating_action' => 'left',
      'file_views_count' => 'left',
      'files_rating_view' => 'left',
      'file_comments_form' => 'left',
      'field_file_license_type' => 'left',
      'action_links' => 'right',
      'salto_files_usage_license' => 'right',
      'salto_files_metadata' => 'right',
      'flag_notification_subscribe_material' => 'right',
      'flag_notification_ignore_material' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|document|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|document|listing';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'listing';
  $ds_layout->layout = 'panels-file_listing';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file',
      ),
      'right' => array(
        1 => 'file_title',
        2 => 'submitted',
        3 => 'field_file_description',
        4 => 'download_link',
      ),
      'license_left' => array(
        5 => 'field_file_lizenzstufe',
      ),
      'license_middle' => array(
        6 => 'field_file_originator',
      ),
      'license_right' => array(
        7 => 'field_file_license_type',
      ),
      'tags' => array(
        8 => 'field_post_tags',
      ),
      'meta_left' => array(
        9 => 'files_rating_view',
      ),
      'meta_right' => array(
        10 => 'file_views_count',
      ),
    ),
    'fields' => array(
      'file' => 'left',
      'file_title' => 'right',
      'submitted' => 'right',
      'field_file_description' => 'right',
      'download_link' => 'right',
      'field_file_lizenzstufe' => 'license_left',
      'field_file_originator' => 'license_middle',
      'field_file_license_type' => 'license_right',
      'field_post_tags' => 'tags',
      'files_rating_view' => 'meta_left',
      'file_views_count' => 'meta_right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
      'license_left' => 'div',
      'license_middle' => 'div',
      'license_right' => 'div',
      'tags' => 'div',
      'meta_left' => 'div',
      'meta_right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|document|listing'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|default';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'panels-salto_93';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file_title_heading',
        1 => 'file',
        2 => 'field_file_image_title_text',
        3 => 'field_file_image_alt_text',
        4 => 'field_file_description',
        5 => 'field_post_tags',
        6 => 'field_file_lizenzstufe',
        7 => 'field_kb_kategorie',
        8 => 'field_content_rating',
        9 => 'salto_files_rating_action',
        10 => 'file_views_count',
        11 => 'files_rating_view',
        12 => 'file_comments_form',
        13 => 'field_file_license_type',
      ),
      'right' => array(
        14 => 'action_links',
        15 => 'salto_files_usage_license',
        16 => 'salto_files_metadata',
        17 => 'flag_notification_subscribe_material',
        18 => 'flag_notification_ignore_material',
      ),
    ),
    'fields' => array(
      'file_title_heading' => 'left',
      'file' => 'left',
      'field_file_image_title_text' => 'left',
      'field_file_image_alt_text' => 'left',
      'field_file_description' => 'left',
      'field_post_tags' => 'left',
      'field_file_lizenzstufe' => 'left',
      'field_kb_kategorie' => 'left',
      'field_content_rating' => 'left',
      'salto_files_rating_action' => 'left',
      'file_views_count' => 'left',
      'files_rating_view' => 'left',
      'file_comments_form' => 'left',
      'field_file_license_type' => 'left',
      'action_links' => 'right',
      'salto_files_usage_license' => 'right',
      'salto_files_metadata' => 'right',
      'flag_notification_subscribe_material' => 'right',
      'flag_notification_ignore_material' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'right' => array(
        'pane-action-links' => 'pane-action-links',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|image|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|image|listing';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'image';
  $ds_layout->view_mode = 'listing';
  $ds_layout->layout = 'panels-file_listing';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file',
      ),
      'right' => array(
        1 => 'file_title',
        2 => 'submitted',
        3 => 'field_file_description',
        4 => 'download_link',
      ),
      'license_left' => array(
        5 => 'field_file_lizenzstufe',
      ),
      'license_middle' => array(
        6 => 'field_file_originator',
      ),
      'license_right' => array(
        7 => 'field_file_license_type',
      ),
      'tags' => array(
        8 => 'field_post_tags',
      ),
      'meta_left' => array(
        9 => 'files_rating_view',
      ),
      'meta_right' => array(
        10 => 'file_views_count',
      ),
    ),
    'fields' => array(
      'file' => 'left',
      'file_title' => 'right',
      'submitted' => 'right',
      'field_file_description' => 'right',
      'download_link' => 'right',
      'field_file_lizenzstufe' => 'license_left',
      'field_file_originator' => 'license_middle',
      'field_file_license_type' => 'license_right',
      'field_post_tags' => 'tags',
      'files_rating_view' => 'meta_left',
      'file_views_count' => 'meta_right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
      'license_left' => 'div',
      'license_middle' => 'div',
      'license_right' => 'div',
      'tags' => 'div',
      'meta_left' => 'div',
      'meta_right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|image|listing'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|swf|default';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'swf';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'panels-salto_93';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file_title_heading',
        1 => 'file',
        2 => 'field_file_description',
        3 => 'field_post_tags',
        4 => 'field_file_lizenzstufe',
        5 => 'field_kb_kategorie',
        6 => 'field_content_rating',
        7 => 'salto_files_rating_action',
        8 => 'file_views_count',
        9 => 'files_rating_view',
        10 => 'file_comments_form',
      ),
      'right' => array(
        11 => 'action_links',
        12 => 'salto_files_usage_license',
        13 => 'salto_files_metadata',
        14 => 'flag_notification_subscribe_material',
        15 => 'flag_notification_ignore_material',
      ),
    ),
    'fields' => array(
      'file_title_heading' => 'left',
      'file' => 'left',
      'field_file_description' => 'left',
      'field_post_tags' => 'left',
      'field_file_lizenzstufe' => 'left',
      'field_kb_kategorie' => 'left',
      'field_content_rating' => 'left',
      'salto_files_rating_action' => 'left',
      'file_views_count' => 'left',
      'files_rating_view' => 'left',
      'file_comments_form' => 'left',
      'action_links' => 'right',
      'salto_files_usage_license' => 'right',
      'salto_files_metadata' => 'right',
      'flag_notification_subscribe_material' => 'right',
      'flag_notification_ignore_material' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|swf|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|swf|listing';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'swf';
  $ds_layout->view_mode = 'listing';
  $ds_layout->layout = 'panels-file_listing';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file',
        1 => 'download_link',
      ),
      'right' => array(
        2 => 'file_title',
        3 => 'submitted',
        4 => 'field_file_description',
      ),
      'license_left' => array(
        5 => 'field_file_lizenzstufe',
      ),
      'license_middle' => array(
        6 => 'field_file_originator',
      ),
      'license_right' => array(
        7 => 'field_file_license_type',
      ),
      'tags' => array(
        8 => 'field_post_tags',
      ),
      'meta_left' => array(
        9 => 'files_rating_view',
      ),
      'meta_right' => array(
        10 => 'file_views_count',
      ),
    ),
    'fields' => array(
      'file' => 'left',
      'download_link' => 'left',
      'file_title' => 'right',
      'submitted' => 'right',
      'field_file_description' => 'right',
      'field_file_lizenzstufe' => 'license_left',
      'field_file_originator' => 'license_middle',
      'field_file_license_type' => 'license_right',
      'field_post_tags' => 'tags',
      'files_rating_view' => 'meta_left',
      'file_views_count' => 'meta_right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
      'license_left' => 'div',
      'license_middle' => 'div',
      'license_right' => 'div',
      'tags' => 'div',
      'meta_left' => 'div',
      'meta_right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['file|swf|listing'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|video|default';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'panels-salto_93';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file_title_heading',
        1 => 'file',
        2 => 'field_file_description',
        3 => 'field_post_tags',
        4 => 'field_file_lizenzstufe',
        5 => 'field_kb_kategorie',
        6 => 'field_content_rating',
        7 => 'salto_files_rating_action',
        8 => 'file_views_count',
        9 => 'files_rating_view',
        10 => 'file_comments_form',
        11 => 'field_file_license_type',
      ),
      'right' => array(
        12 => 'action_links',
        13 => 'salto_files_usage_license',
        14 => 'salto_files_metadata',
        15 => 'flag_notification_subscribe_material',
        16 => 'flag_notification_ignore_material',
      ),
    ),
    'fields' => array(
      'file_title_heading' => 'left',
      'file' => 'left',
      'field_file_description' => 'left',
      'field_post_tags' => 'left',
      'field_file_lizenzstufe' => 'left',
      'field_kb_kategorie' => 'left',
      'field_content_rating' => 'left',
      'salto_files_rating_action' => 'left',
      'file_views_count' => 'left',
      'files_rating_view' => 'left',
      'file_comments_form' => 'left',
      'field_file_license_type' => 'left',
      'action_links' => 'right',
      'salto_files_usage_license' => 'right',
      'salto_files_metadata' => 'right',
      'flag_notification_subscribe_material' => 'right',
      'flag_notification_ignore_material' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'right' => array(
        'pane-action-links' => 'pane-action-links',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|video|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|video|listing';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'listing';
  $ds_layout->layout = 'panels-file_listing';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file',
      ),
      'right' => array(
        1 => 'file_title',
        2 => 'submitted',
        3 => 'field_file_description',
        4 => 'download_link',
      ),
      'license_left' => array(
        5 => 'field_file_lizenzstufe',
      ),
      'license_middle' => array(
        6 => 'field_file_originator',
      ),
      'license_right' => array(
        7 => 'field_file_license_type',
      ),
      'tags' => array(
        8 => 'field_post_tags',
      ),
      'meta_left' => array(
        9 => 'files_rating_view',
      ),
      'meta_right' => array(
        10 => 'file_views_count',
      ),
    ),
    'fields' => array(
      'file' => 'left',
      'file_title' => 'right',
      'submitted' => 'right',
      'field_file_description' => 'right',
      'download_link' => 'right',
      'field_file_lizenzstufe' => 'license_left',
      'field_file_originator' => 'license_middle',
      'field_file_license_type' => 'license_right',
      'field_post_tags' => 'tags',
      'files_rating_view' => 'meta_left',
      'file_views_count' => 'meta_right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
      'license_left' => 'div',
      'license_middle' => 'div',
      'license_right' => 'div',
      'tags' => 'div',
      'meta_left' => 'div',
      'meta_right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|video|listing'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|webresource|default';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'webresource';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'panels-salto_93';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file_title_heading',
        1 => 'file',
        2 => 'field_file_description',
        3 => 'field_post_tags',
        4 => 'field_file_lizenzstufe',
        5 => 'field_content_rating',
        6 => 'salto_files_rating_action',
        7 => 'file_views_count',
        8 => 'files_rating_view',
        9 => 'file_comments_form',
        10 => 'field_file_license_type',
      ),
      'right' => array(
        11 => 'action_links',
        12 => 'salto_files_usage_license',
        13 => 'field_og_group',
        14 => 'salto_files_metadata',
        15 => 'flag_notification_subscribe_material',
        16 => 'flag_notification_ignore_material',
      ),
    ),
    'fields' => array(
      'file_title_heading' => 'left',
      'file' => 'left',
      'field_file_description' => 'left',
      'field_post_tags' => 'left',
      'field_file_lizenzstufe' => 'left',
      'field_content_rating' => 'left',
      'salto_files_rating_action' => 'left',
      'file_views_count' => 'left',
      'files_rating_view' => 'left',
      'file_comments_form' => 'left',
      'field_file_license_type' => 'left',
      'action_links' => 'right',
      'salto_files_usage_license' => 'right',
      'field_og_group' => 'right',
      'salto_files_metadata' => 'right',
      'flag_notification_subscribe_material' => 'right',
      'flag_notification_ignore_material' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|webresource|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'file|webresource|listing';
  $ds_layout->entity_type = 'file';
  $ds_layout->bundle = 'webresource';
  $ds_layout->view_mode = 'listing';
  $ds_layout->layout = 'panels-file_listing';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'file',
      ),
      'right' => array(
        1 => 'file_title',
        2 => 'submitted',
        3 => 'field_file_description',
        4 => 'download_link',
      ),
      'license_left' => array(
        5 => 'field_file_lizenzstufe',
      ),
      'license_middle' => array(
        6 => 'field_file_originator',
      ),
      'license_right' => array(
        7 => 'field_file_license_type',
      ),
      'tags' => array(
        8 => 'field_post_tags',
      ),
      'meta_left' => array(
        9 => 'files_rating_view',
      ),
      'meta_right' => array(
        10 => 'file_views_count',
      ),
    ),
    'fields' => array(
      'file' => 'left',
      'file_title' => 'right',
      'submitted' => 'right',
      'field_file_description' => 'right',
      'download_link' => 'right',
      'field_file_lizenzstufe' => 'license_left',
      'field_file_originator' => 'license_middle',
      'field_file_license_type' => 'license_right',
      'field_post_tags' => 'tags',
      'files_rating_view' => 'meta_left',
      'file_views_count' => 'meta_right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
      'license_left' => 'div',
      'license_middle' => 'div',
      'license_right' => 'div',
      'tags' => 'div',
      'meta_left' => 'div',
      'meta_right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['file|webresource|listing'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function salto_files_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'listing';
  $ds_view_mode->label = 'Listing';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['listing'] = $ds_view_mode;

  return $export;
}
