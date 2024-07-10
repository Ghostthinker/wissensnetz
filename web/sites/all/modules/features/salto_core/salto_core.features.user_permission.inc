<?php

/**
 * @file
 * salto_core.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function salto_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access ckeditor link'.
  $permissions['access ckeditor link'] = array(
    'name' => 'access ckeditor link',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ckeditor_link',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access heartbeat activity profiles'.
  $permissions['access heartbeat activity profiles'] = array(
    'name' => 'access heartbeat activity profiles',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access piwik reports'.
  $permissions['access piwik reports'] = array(
    'name' => 'access piwik reports',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'piwik_reports',
  );

  // Exported permission: 'access printer-friendly version'.
  $permissions['access printer-friendly version'] = array(
    'name' => 'access printer-friendly version',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'book',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access statistics'.
  $permissions['access statistics'] = array(
    'name' => 'access statistics',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'access user contact forms'.
  $permissions['access user contact forms'] = array(
    'name' => 'access user contact forms',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access visitors'.
  $permissions['access visitors'] = array(
    'name' => 'access visitors',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'visitors',
  );

  // Exported permission: 'add content to books'.
  $permissions['add content to books'] = array(
    'name' => 'add content to books',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'book',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'admin heartbeat configure'.
  $permissions['admin heartbeat configure'] = array(
    'name' => 'admin heartbeat configure',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'heartbeat_ui',
  );

  // Exported permission: 'admin heartbeat delete all'.
  $permissions['admin heartbeat delete all'] = array(
    'name' => 'admin heartbeat delete all',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'admin heartbeat delete own'.
  $permissions['admin heartbeat delete own'] = array(
    'name' => 'admin heartbeat delete own',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'admin heartbeat streams'.
  $permissions['admin heartbeat streams'] = array(
    'name' => 'admin heartbeat streams',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'heartbeat_ui',
  );

  // Exported permission: 'admin heartbeat templates'.
  $permissions['admin heartbeat templates'] = array(
    'name' => 'admin heartbeat templates',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'admin_classes'.
  $permissions['admin_classes'] = array(
    'name' => 'admin_classes',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'admin_fields'.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_view_modes'.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'administer Terms and Conditions'.
  $permissions['administer Terms and Conditions'] = array(
    'name' => 'administer Terms and Conditions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'legal',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer book outlines'.
  $permissions['administer book outlines'] = array(
    'name' => 'administer book outlines',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'book',
  );

  // Exported permission: 'administer browscap'.
  $permissions['administer browscap'] = array(
    'name' => 'administer browscap',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'browscap',
  );

  // Exported permission: 'administer ckeditor link'.
  $permissions['administer ckeditor link'] = array(
    'name' => 'administer ckeditor link',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'ckeditor_link',
  );

  // Exported permission: 'administer clients connections'.
  $permissions['administer clients connections'] = array(
    'name' => 'administer clients connections',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'clients',
  );

  // Exported permission: 'administer clients resources'.
  $permissions['administer clients resources'] = array(
    'name' => 'administer clients resources',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'clients',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer contact forms'.
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer ctools access ruleset'.
  $permissions['administer ctools access ruleset'] = array(
    'name' => 'administer ctools access ruleset',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'ctools_access_ruleset',
  );

  // Exported permission: 'administer custom content'.
  $permissions['administer custom content'] = array(
    'name' => 'administer custom content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'ctools_custom_content',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer group'.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'og',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer less'.
  $permissions['administer less'] = array(
    'name' => 'administer less',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'less',
  );

  // Exported permission: 'administer mailsystem'.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'mailsystem',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'menu_attributes',
  );

  // Exported permission: 'administer menu_token'.
  $permissions['administer menu_token'] = array(
    'name' => 'administer menu_token',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'menu_token',
  );

  // Exported permission: 'administer message types'.
  $permissions['administer message types'] = array(
    'name' => 'administer message types',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'message',
  );

  // Exported permission: 'administer mini panels'.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodeaccess'.
  $permissions['administer nodeaccess'] = array(
    'name' => 'administer nodeaccess',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'nodeaccess',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer path breadcrumbs'.
  $permissions['administer path breadcrumbs'] = array(
    'name' => 'administer path breadcrumbs',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'path_breadcrumbs_ui',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer phpexcel'.
  $permissions['administer phpexcel'] = array(
    'name' => 'administer phpexcel',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'phpexcel',
  );

  // Exported permission: 'administer piwik reports'.
  $permissions['administer piwik reports'] = array(
    'name' => 'administer piwik reports',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'piwik_reports',
  );

  // Exported permission: 'administer privatemsg settings'.
  $permissions['administer privatemsg settings'] = array(
    'name' => 'administer privatemsg settings',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'administer profile types'.
  $permissions['administer profile types'] = array(
    'name' => 'administer profile types',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'administer realname'.
  $permissions['administer realname'] = array(
    'name' => 'administer realname',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'realname',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer salto invites'.
  $permissions['administer salto invites'] = array(
    'name' => 'administer salto invites',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'salto_invite',
  );

  // Exported permission: 'administer salto_invite types'.
  $permissions['administer salto_invite types'] = array(
    'name' => 'administer salto_invite types',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'salto_invite',
  );

  // Exported permission: 'administer security questions'.
  $permissions['administer security questions'] = array(
    'name' => 'administer security questions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'security_questions',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer statistics'.
  $permissions['administer statistics'] = array(
    'name' => 'administer statistics',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'administer stylizer'.
  $permissions['administer stylizer'] = array(
    'name' => 'administer stylizer',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'stylizer',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer unit tests'.
  $permissions['administer unit tests'] = array(
    'name' => 'administer unit tests',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'simpletest',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Admin' => 'Admin',
      'Support' => 'Support',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer visitors'.
  $permissions['administer visitors'] = array(
    'name' => 'administer visitors',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'visitors',
  );

  // Exported permission: 'administer_fe_paths'.
  $permissions['administer_fe_paths'] = array(
    'name' => 'administer_fe_paths',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'fe_paths',
  );

  // Exported permission: 'allow disabling privatemsg'.
  $permissions['allow disabling privatemsg'] = array(
    'name' => 'allow disabling privatemsg',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'assign categories'.
  $permissions['assign categories'] = array(
    'name' => 'assign categories',
    'roles' => array(
      'Admin' => 'Admin',
      'Gärtner' => 'Gärtner',
    ),
    'module' => 'salto_knowledgebase',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'bypass security questions'.
  $permissions['bypass security questions'] = array(
    'name' => 'bypass security questions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'security_questions',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change user status'.
  $permissions['change user status'] = array(
    'name' => 'change user status',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
    ),
    'module' => 'salto_user',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create messages'.
  $permissions['create messages'] = array(
    'name' => 'create messages',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'message',
  );

  // Exported permission: 'create mini panels'.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'create new books'.
  $permissions['create new books'] = array(
    'name' => 'create new books',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'book',
  );

  // Exported permission: 'create organisation content'.
  $permissions['create organisation content'] = array(
    'name' => 'create organisation content',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any help content'.
  $permissions['delete any help content'] = array(
    'name' => 'delete any help content',
    'roles' => array(
      'DOSB' => 'DOSB',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any organisation content'.
  $permissions['delete any organisation content'] = array(
    'name' => 'delete any organisation content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own help content'.
  $permissions['delete own help content'] = array(
    'name' => 'delete own help content',
    'roles' => array(
      'DOSB' => 'DOSB',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own organisation content'.
  $permissions['delete own organisation content'] = array(
    'name' => 'delete own organisation content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete privatemsg'.
  $permissions['delete privatemsg'] = array(
    'name' => 'delete privatemsg',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in organisation_responsibilities'.
  $permissions['delete terms in organisation_responsibilities'] = array(
    'name' => 'delete terms in organisation_responsibilities',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in profile_competencies'.
  $permissions['delete terms in profile_competencies'] = array(
    'name' => 'delete terms in profile_competencies',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in profile_interests'.
  $permissions['delete terms in profile_interests'] = array(
    'name' => 'delete terms in profile_interests',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in profile_sports'.
  $permissions['delete terms in profile_sports'] = array(
    'name' => 'delete terms in profile_sports',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any collaboration access'.
  $permissions['edit any collaboration access'] = array(
    'name' => 'edit any collaboration access',
    'roles' => array(
      'Admin' => 'Admin',
      'Support' => 'Support',
    ),
    'module' => 'salto_knowledgebase',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any help content'.
  $permissions['edit any help content'] = array(
    'name' => 'edit any help content',
    'roles' => array(
      'DOSB' => 'DOSB',
      'Support' => 'Support',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any main profile'.
  $permissions['edit any main profile'] = array(
    'name' => 'edit any main profile',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit any organisation content'.
  $permissions['edit any organisation content'] = array(
    'name' => 'edit any organisation content',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'Admin' => 'Admin',
      'DOSB' => 'DOSB',
      'Support' => 'Support',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own help content'.
  $permissions['edit own help content'] = array(
    'name' => 'edit own help content',
    'roles' => array(
      'DOSB' => 'DOSB',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own main profile'.
  $permissions['edit own main profile'] = array(
    'name' => 'edit own main profile',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own organisation content'.
  $permissions['edit own organisation content'] = array(
    'name' => 'edit own organisation content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit terms in organisation_responsibilities'.
  $permissions['edit terms in organisation_responsibilities'] = array(
    'name' => 'edit terms in organisation_responsibilities',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in profile_competencies'.
  $permissions['edit terms in profile_competencies'] = array(
    'name' => 'edit terms in profile_competencies',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in profile_interests'.
  $permissions['edit terms in profile_interests'] = array(
    'name' => 'edit terms in profile_interests',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in profile_sports'.
  $permissions['edit terms in profile_sports'] = array(
    'name' => 'edit terms in profile_sports',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'Admin' => 'Admin',
      'Support' => 'Support',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'features',
  );

  // Exported permission: 'grant deletable node permissions'.
  $permissions['grant deletable node permissions'] = array(
    'name' => 'grant deletable node permissions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'nodeaccess',
  );

  // Exported permission: 'grant editable node permissions'.
  $permissions['grant editable node permissions'] = array(
    'name' => 'grant editable node permissions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'nodeaccess',
  );

  // Exported permission: 'grant node permissions'.
  $permissions['grant node permissions'] = array(
    'name' => 'grant node permissions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'nodeaccess',
  );

  // Exported permission: 'grant own node permissions'.
  $permissions['grant own node permissions'] = array(
    'name' => 'grant own node permissions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'nodeaccess',
  );

  // Exported permission: 'import media'.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'media_bulk_upload',
  );

  // Exported permission: 'import users'.
  $permissions['import users'] = array(
    'name' => 'import users',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'salto_user',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'features',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'read all private messages'.
  $permissions['read all private messages'] = array(
    'name' => 'read all private messages',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'read privatemsg'.
  $permissions['read privatemsg'] = array(
    'name' => 'read privatemsg',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'reply only privatemsg'.
  $permissions['reply only privatemsg'] = array(
    'name' => 'reply only privatemsg',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: 'select text format for privatemsg'.
  $permissions['select text format for privatemsg'] = array(
    'name' => 'select text format for privatemsg',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'show format selection for comment'.
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for file'.
  $permissions['show format selection for file'] = array(
    'name' => 'show format selection for file',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for flagging'.
  $permissions['show format selection for flagging'] = array(
    'name' => 'show format selection for flagging',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for heartbeat_activity'.
  $permissions['show format selection for heartbeat_activity'] = array(
    'name' => 'show format selection for heartbeat_activity',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for message'.
  $permissions['show format selection for message'] = array(
    'name' => 'show format selection for message',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for message_type'.
  $permissions['show format selection for message_type'] = array(
    'name' => 'show format selection for message_type',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for message_type_category'.
  $permissions['show format selection for message_type_category'] = array(
    'name' => 'show format selection for message_type_category',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for og_membership'.
  $permissions['show format selection for og_membership'] = array(
    'name' => 'show format selection for og_membership',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for og_membership_type'.
  $permissions['show format selection for og_membership_type'] = array(
    'name' => 'show format selection for og_membership_type',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for privatemsg_message'.
  $permissions['show format selection for privatemsg_message'] = array(
    'name' => 'show format selection for privatemsg_message',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for profile2'.
  $permissions['show format selection for profile2'] = array(
    'name' => 'show format selection for profile2',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_config'.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for salto_invite'.
  $permissions['show format selection for salto_invite'] = array(
    'name' => 'show format selection for salto_invite',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'Admin' => 'Admin',
      'Support' => 'Support',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'use PHP for settings'.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'php',
  );

  // Exported permission: 'use PHP for title patterns'.
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'auto_nodetitle',
  );

  // Exported permission: 'use bulk exporter'.
  $permissions['use bulk exporter'] = array(
    'name' => 'use bulk exporter',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'bulk_export',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format comment_with_link'.
  $permissions['use text format comment_with_link'] = array(
    'name' => 'use text format comment_with_link',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format ds_code'.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format editor'.
  $permissions['use text format editor'] = array(
    'name' => 'use text format editor',
    'roles' => array(
      'Admin' => 'Admin',
      'Ghost' => 'Ghost',
      'Support' => 'Support',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format editor_comment'.
  $permissions['use text format editor_comment'] = array(
    'name' => 'use text format editor_comment',
    'roles' => array(
      'Admin' => 'Admin',
      'Ghost' => 'Ghost',
      'Support' => 'Support',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format machine'.
  $permissions['use text format machine'] = array(
    'name' => 'use text format machine',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format php_code'.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use tokens in privatemsg'.
  $permissions['use tokens in privatemsg'] = array(
    'name' => 'use tokens in privatemsg',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'view Node activity stream'.
  $permissions['view Node activity stream'] = array(
    'name' => 'view Node activity stream',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'view Single activity stream'.
  $permissions['view Single activity stream'] = array(
    'name' => 'view Single activity stream',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'view Site activity stream'.
  $permissions['view Site activity stream'] = array(
    'name' => 'view Site activity stream',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'view Terms and Conditions'.
  $permissions['view Terms and Conditions'] = array(
    'name' => 'view Terms and Conditions',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'legal',
  );

  // Exported permission: 'view User activity stream'.
  $permissions['view User activity stream'] = array(
    'name' => 'view User activity stream',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'view User relations activity stream'.
  $permissions['view User relations activity stream'] = array(
    'name' => 'view User relations activity stream',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'view Views activity stream'.
  $permissions['view Views activity stream'] = array(
    'name' => 'view Views activity stream',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'view any main profile'.
  $permissions['view any main profile'] = array(
    'name' => 'view any main profile',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view devel_node_access information'.
  $permissions['view devel_node_access information'] = array(
    'name' => 'view devel_node_access information',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'devel_node_access',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view heartbeat messages'.
  $permissions['view heartbeat messages'] = array(
    'name' => 'view heartbeat messages',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'heartbeat',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own main profile'.
  $permissions['view own main profile'] = array(
    'name' => 'view own main profile',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view post access counter'.
  $permissions['view post access counter'] = array(
    'name' => 'view post access counter',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Admin' => 'Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'write privatemsg'.
  $permissions['write privatemsg'] = array(
    'name' => 'write privatemsg',
    'roles' => array(
      'Admin' => 'Admin',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  return $permissions;
}
