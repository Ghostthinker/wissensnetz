<?php

/**
 * @file
 *   Views integration.
 */

/**
 * Implements hook_views_data().
 */
function media_derivatives_views_data() {
  $data = array();

  // ----------------------------------------------------------------
  // media_derivatives table
  $data['media_derivatives']['table']['group'] = t('Media derivatives');

  $data['media_derivatives']['table']['base'] = array(
    'field' => 'mdid',
    'title' => t('Media derivatives'),
    'weight' => -10,
    'access query tag' => 'node_access',
    'defaults' => array(
      'field' => 'mdid',
    ),
  );

  // mdid
  $data['media_derivatives']['mdid'] = array(
    'title' => t('Mdid'),
    'help' => t('The derivative ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // uid
  $data['media_derivatives']['uid'] = array(
    'title' => t('UID'),
    'help' => t("This derivative's owner UID."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // type
  $data['media_derivatives']['type'] = array(
    'title' => t('File type'),
    'help' => t("Derivative file type (managed/unmanaged)."),
    'field' => array(
      'handler' => 'media_derivatives_handler_field_derivative_type',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'media_derivatives_handler_filter_derivative_type',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // source_fid
  $data['media_derivatives']['source_fid'] = array(
    'title' => t('Source file FID'),
    'help' => t("This derivative's direct source file FID."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array(
      'group' => t('File'),
      'title' => t('source file'),
      'base' => 'file_managed',
      'base field' => 'fid',
      'label' => t('source file'),
    ),
  );

  // root_source_fid
  $data['media_derivatives']['root_source_fid'] = array(
    'title' => t('Root source file FID'),
    'help' => t("This derivative's root source file FID."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'relationship' => array(
      'group' => t('File'),
      'title' => t('root source file'),
      'base' => 'file_managed',
      'base field' => 'fid',
      'label' => t('root source file'),
    ),
  );

  // derivative_fid
  $data['media_derivatives']['derivative_fid'] = array(
    'title' => t('Derivative file FID'),
    'help' => t("The derivative file FID."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // engine
  $data['media_derivatives']['engine'] = array(
    'title' => t('Engine used'),
    'help' => t("Engine name that was used to create this derivative."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // event
  $data['media_derivatives']['event'] = array(
    'title' => t('Event'),
    'help' => t("Event that started creation of this derivative."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // scheduler
  $data['media_derivatives']['scheduler'] = array(
    'title' => t('Scheduler'),
    'help' => t("Scheduler that was used to create this derivative."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // status
  $data['media_derivatives']['status'] = array(
    'title' => t('Status'),
    'help' => t('The derivative current status.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // created
  $data['media_derivatives']['created'] = array(
    'title' => t('Created date'),
    'help' => t('Date and time when a derivative object was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // changed
  $data['media_derivatives']['changed'] = array(
    'title' => t('Changed date'),
    'help' => t('Date and time when a derivative object was last changed.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // log
  $data['media_derivatives']['log'] = array(
    'title' => t('Log output'),
    'help' => t("Debug log of derivative creation process."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['media_derivatives_unmanaged']['table']['group'] = t('Unmanaged media derivatives');

  $data['media_derivatives_unmanaged']['table']['join']['media_derivatives'] = array(
    'left_field' => 'mdid',
    'field' => 'mdid',
  );

  // unmanaged uri
  $data['media_derivatives_unmanaged']['uri'] = array(
    'title' => t('Unmanaged URI'),
    'help' => t("URI of a derivative file if a derivative id unmanaged file."),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function media_derivatives_views_data_alter(&$data) {
  // derivative relationship - implemented as a default join: is this ok? FIXME
  $data['file_managed']['derivative_rel'] = array(
    'group' => t('Media derivatives'),
    'title' => t('Derivative'),
    'help' => t('Derivative object, if this is a derivative.'),
    'real field' => 'fid',
    'relationship' => array(
      'base' => 'media_derivatives',
      'base field' => 'derivative_fid',
      'relationship field' => 'fid',
      'label' => t('derivative'),
    ),
  );

  // derivative source relationship
  $data['file_managed']['derivative_source_rel'] = array(
    'group' => t('Media derivatives'),
    'title' => t('Derivative source'),
    'help' => t('Derivative object, if this is a source for a derivative.'),
    'real field' => 'fid',
    'relationship' => array(
      'base' => 'media_derivatives',
      'base field' => 'source_fid',
      'relationship field' => 'fid',
      'label' => t('derivative source'),
    ),
  );

  // derivative root relationship
  $data['file_managed']['derivative_root_source_rel'] = array(
    'group' => t('Media derivatives'),
    'title' => t('Derivative root source'),
    'help' => t('Derivative object, if this is a root source for a derivative.'),
    'real field' => 'fid',
    'relationship' => array(
      'base' => 'media_derivatives',
      'base field' => 'root_source_fid',
      'relationship field' => 'fid',
      'label' => t('derivative root source'),
    ),
  );

  // file_managed and user tables must tell us how to join on them
  $data['file_managed']['table']['join'] = array(
    'media_derivatives' => array(
      'left_field' => 'derivative_fid',
      'field' => 'fid',
    ),
  );
  $data['users']['table']['join'] = array(
    'media_derivatives' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );
}
