<?php

/**
 * @file
 * Providing extra functionality for the Model UI via views.
 */


/**
 * Implements hook_views_data()
 */
function salto_invite_views_data_alter(&$data) {
  $data['salto_invite']['link_salto_invite'] = [
    'field' => [
      'title' => t('Link'),
      'help' => t('Provide a link to the salto_invite.'),
      'handler' => 'salto_invite_handler_link_field',
    ],
  ];
  $data['salto_invite']['link_salto_resend_invite'] = [
    'field' => [
      'title' => t('Resend invite Link'),
      'help' => t('Provide a resend link to the salto_invite.'),
      'handler' => 'salto_invite_handler_resend_link_field',
    ],
  ];
  $data['salto_invite']['edit_salto_invite'] = [
    'field' => [
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the salto_invite.'),
      'handler' => 'salto_invite_handler_edit_link_field',
    ],
  ];
  $data['salto_invite']['delete_salto_invite'] = [
    'field' => [
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the salto_invite.'),
      'handler' => 'salto_invite_handler_delete_link_field',
    ],
  ];
  // This content of this field are decided based on the menu structure that
  // follows salto_invites/salto_invite/%salto_invite_id/op
  $data['salto_invite']['operations'] = [
    'field' => [
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this salto_invite.'),
      'handler' => 'salto_invite_handler_salto_invite_operations_field',
    ],
  ];
  $data['salto_invite']['acccept_salto_invite'] = [
    'field' => [
      'title' => t('Accept/Decline invite links'),
      'help' => t('Display an accept invite link.'),
      'handler' => 'salto_invite_handler_salto_invite_accept_field',
    ],
  ];
  $data['salto_invite']['salto_invite_message'] = [
    'field' => [
      'title' => t('Invite message'),
      'help' => t('The invite message'),
      'handler' => 'salto_invite_handler_salto_invite_message_field',
    ],
  ];
}


/**
 * Implements hook_views_default_views().
 */
function salto_invite_views_default_views() {
  $views = [];
  $view = new view();
  $view->name = 'salto_invites';
  $view->description = 'A list of all salto_invites';
  $view->tag = 'salto_invites';
  $view->base_table = 'salto_invite';
  $view->human_name = 'Salto Invites';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;


  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Models';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create any salto_invite type';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'nächste Seite ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = [
    'name' => 'name',
    'model_id' => 'salto_invite_id',
  ];
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = [
    'name' => [
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ],
    'salto_invite_id' => [
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ],
  ];

  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['content'] = 'No salto_invites have been created yet';

  $handler->display->display_options['fields']['salto_invite_id']['id'] = 'salto_invite_id';
  $handler->display->display_options['fields']['salto_invite_id']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['salto_invite_id']['field'] = 'salto_invite_id';

  $handler->display->display_options['fields']['code']['id'] = 'code';
  $handler->display->display_options['fields']['code']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['code']['field'] = 'code';

  $handler->display->display_options['fields']['link_salto_invite']['id'] = 'link_salto_invite';
  $handler->display->display_options['fields']['link_salto_invite']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['link_salto_invite']['field'] = 'link_salto_invite';
  $handler->display->display_options['fields']['link_salto_invite']['label'] = 'View';

  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'salto_invite';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';

  $handler = $view->new_display('page', 'Page', 'salto_invites_admin_page');
  $handler->display->display_options['path'] = 'admin/content/salto_invites/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Salto Invites';
  $handler->display->display_options['tab_options']['description'] = 'Manage salto_invite';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['salto_invites'] = [
    t('Master'),
    t('Models'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('nächste Seite ›'),
    t('letzte Seite »'),
    t('Empty '),
    t('No salto_invites have been created yet'),
    t('Salto invite ID'),
    t('.'),
    t(','),
    t('Code'),
    t('View'),
    t('Operations links'),
    t('Page'),
  ];

  $views[] = $view;
  return $views;

}
