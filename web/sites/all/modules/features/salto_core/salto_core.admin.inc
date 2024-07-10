<?php

use salto_core\migration\MigrationService;
use salto_core\service\SettingsService;

function salto_core_admin_settings($form, &$form_state) {


  $form['general'] = [
    '#type' => 'fieldset',
    '#title' => 'General Settings',
    '#description' => t('General settings for salto-bip'),
  ];

  $form['general']['salto_protect_on_leave'] = [
    '#type' => 'checkbox',
    '#title' => 'Protect forms on leave',
    '#description' => t('Protect forms on leave'),
    '#default_value' => variable_get('salto_protect_on_leave', TRUE),
  ];

  $form['general']['salto_core_frontpage_slider_interval'] = [
    '#type' => 'textfield',
    '#title' => 'Frontpage slider interval',
    '#description' => t('Frontpage slider interval in milliseconds.'),
    '#default_value' => variable_get('salto_core_frontpage_slider_interval', 6000),
  ];

  $form['user'] = [
    '#type' => 'fieldset',
    '#title' => 'User Settings',
    '#description' => t('General settings for salto-bip'),
  ];

  $form['user']['salto_user_online_seconds'] = [
    '#type' => 'textfield',
    '#title' => 'Online time',
    '#description' => t('Seconds that must pass after the last action of a user to appear offline. IN SECONDS'),
    '#default_value' => variable_get('salto_user_online_seconds', 300),
  ];
  $form['user']['salto_user_direct_group_invite'] = [
    '#type' => 'checkbox',
    '#title' => 'Direct group invite',
    '#description' => t('When check, users that are invited via a group (not oragnisation) are directly added to the group. If not checked, invites are generated'),
    '#default_value' => variable_get('salto_user_direct_group_invite', FALSE),
  ];

  $form['user']['salto_user_keep_group'] = [
    '#type' => 'textfield',
    '#title' => 'Keep User Group',
    '#description' => t('The nid of the group where members are not deleted when replicating live.'),
    '#default_value' => variable_get('salto_user_keep_group', 2194),
  ];

  $form['user']['salto_default_category'] = [
    '#type' => 'textfield',
    '#title' => 'Default category nid',
    '#description' => t('Category nid used as default category for users'),
    '#default_value' => salto_knowledgebase_get_default_kb_category_tid(),
  ];

  $form['user']['salto_fallback_category'] = [
    '#type' => 'textfield',
    '#title' => 'Fallback category nid',
    '#description' => t('Fallback nid used as fallback category for users'),
    '#default_value' => salto_knowledgebase_get_fallback_kb_category_tid(),
  ];

  $form['user']['field_instance_label_overrides'] = [
    '#type' => 'textarea',
    '#title' => "Profile: field instance labels",
    '#description' => "Caution: wn_blanko module needs to be enabled for this feature to work properly. Override filed instance labels. Start new line for new entry. Syntax **key => value**. example **field_profile_categories => Themenfeld(er)**",
    '#default_value' => variable_get('field_instance_label_overrides', ''),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $form['organisation'] = [
    '#type' => 'fieldset',
    '#title' => 'Organisations Settings',
    '#description' => t('General settings for organisations'),
  ];
  $form['organisation']['salto_organisation_fallback_nid'] = [
    '#type' => 'textfield',
    '#title' => 'Organisation fallback nid',
    '#description' => t('Organisation nid used as fallback organisation for users which are removed from their last organisation'),
    '#default_value' => salto_organisation_get_fallback_nid(),
  ];

  $form['filter'] = [
    '#type' => 'fieldset',
    '#title' => 'Filter Settings',
    '#description' => t('Settings for Filter'),
  ];

  $form['filter']['themenfelder_filter_default_value_override'] = [
    '#type' => 'checkbox',
    '#title' => 'Override default value Themenfeld Filter',
    '#description' => t('Overrides the default value from -mine- to -all- if checked'),
    '#default_value' => salto_core_get_default_value_themenfeld_filter(),
  ];


  $form['filter']['users_filter_by_organisation'] = [
    '#type' => 'checkbox',
    '#title' => 'Users: Add Filter by Organisation',
    '#description' => t('Caution: Use this only on instances with a little number of organisations. Otherwise enabling this filter may lead to performance issues.'),
    '#default_value' => salto_core_get_users_filter_by_organisation(),
  ];


  $form['posts'] = [
    '#type' => 'fieldset',
    '#title' => 'Posts',
    '#description' => t('Settings for posts'),
  ];

  $form['posts']['salto_core_get_posts_show_active_category_only'] = [
    '#type' => 'checkbox',
    '#title' => 'Show posts which are in the active category only',
    '#description' => t('Only posts which match the selected themenfield will be filtered. All child terms will not be visible.'),
    '#default_value' => salto_core_get_posts_show_active_category_only(),
  ];

  $form['posts']['salto_core_posts_send_notification_default_value'] = [
    '#type' => 'checkbox',
    '#title' => 'Override the default value for notification setting on node edit',
    '#description' => t('If checkbox is enabled, the notification checkbox on edit node, to send notifications, will be enabled by default.'),
    '#default_value' => salto_core_posts_send_notification_default_value(),
  ];


  if (module_exists('wn_blanko')) {
    $form['#submit'][] = 'wn_blanko_admin_settings_submit_handler';
  }


  return system_settings_form($form);
}

/**
 * @param $form
 * @param $form_state
 */
function salto_core_admin_settings_validate($form, &$form_state) {
  $fallback_og = node_load($form_state['values']['salto_organisation_fallback_nid']);
  if (!$fallback_og || $fallback_og->type !== 'organisation') {
    form_set_error('salto_organisation_fallback_nid', t('Please enter a valid organisation nid'));
  }
}

function salto_core_migration_form($form_state, $domain = [], $arguments = []) {

  $form = [];

  $form['domain'] = [
    '#type' => 'fieldset',
    '#title' => t('Migration a Community from Edubreak'),
    '#collapsible' => FALSE,
  ];

  $form['domain']['domain_url'] = [
    '#type' => 'textfield',
    '#title' => t('Domain url'),
    '#size' => 40,
    '#maxlength' => 80,
    '#required' => TRUE,
    '#description' => t('For example https://eb.de/api/rest/'),
  ];

  $form['domain']['domain_id'] = [
    '#type' => 'textfield',
    '#title' => t('The domain ID to migrate'),
    '#size' => 40,
    '#maxlength' => 80,
    '#required' => TRUE,
  ];

  $form['domain']['domain_courses'] = [
    '#type' => 'textarea',
    '#title' => t('Specific courses to migrate'),
    '#size' => 40,
    '#rows' => 5,
    '#description' => t('A list of courses'),
  ];

  $form['domain']['mail'] = [
    '#type' => 'textfield',
    '#title' => t('Mail'),
    '#size' => 40,
    '#maxlength' => 80,
    '#required' => TRUE,
  ];

  $form['domain']['password'] = [
    '#type' => 'password',
    '#title' => t('Password'),
    '#size' => 40,
    '#maxlength' => 80,
    '#required' => TRUE,
  ];

  $form['domain']['dryRun'] = [
    '#type' => 'checkbox',
    '#title' => t('Dry run'),
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Migrate Community'),
  ];

  return $form;
}

/**
 * Submit callback for domain processing
 *
 * @param $form
 * @param $form_state
 *
 * @return null
 */
function salto_core_migration_form_submit($form, $form_state) {
  $base_url = $form_state['values']['domain_url'];
  $domain_id = $form_state['values']['domain_id'];
  $mail = $form_state['values']['mail'];
  $password = $form_state['values']['password'];
  $dryRun = $form_state['values']['dryRun'];
  $domain_courses = $form_state['values']['domain_courses'];

  if (!empty($domain_courses)) {
    $domain_courses = explode("\r\n", $domain_courses);
  }

  $options = [
    'url' => $base_url,
    'credentials' => [
      'mail' => $mail,
      'password' => $password,
    ],
    'domain_courses' => $domain_courses ?? [],
  ];

  $migrationService = new MigrationService($options);
  $response = $migrationService->migrate($domain_id, $dryRun, $domain_courses);
  if ($dryRun) {
    dpm($response);
  }

}

function salto_core_graylog_settings_form() {

  $form ['salto_core_graylog_settings'] = [
    '#type' => 'fieldset',
    '#title' => t('Graylog'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Configure graylog logging'),
    '#tree' => TRUE,
  ];

  $graylogService = new \Wissensnetz\Log\GraylogService();
  $graylog_settings = $graylogService->get_graylog_settings();

  $form['salto_core_graylog_settings']['enabled'] = [
    '#type' => 'checkbox',
    '#title' => t('Graylog enabled'),
    '#description' => t('Enable graylog logging'),
    '#default_value' => $graylog_settings['enabled'],
  ];

  $form['salto_core_graylog_settings']['host'] = [
    '#type' => 'textfield',
    '#title' => t('Graylog host'),
    '#description' => t('The graylog host. Remember to test if your ip %ip is allowed in the log servers firewall', ['%ip' => $_SERVER['SERVER_ADDR']]),
    '#default_value' => $graylog_settings['host'],
  ];

  $form['salto_core_graylog_settings']['port'] = [
    '#type' => 'textfield',
    '#title' => t('Graylog port'),
    '#description' => t('The graylog port'),
    '#default_value' => $graylog_settings['port'],
  ];

  $form['salto_core_graylog_settings']['transport'] = [
    '#type' => 'select',
    '#title' => t('Transport Layer'),
    '#options' => ['udp' => 'udp', 'tcp' => 'tcp'],
    '#description' => t('It is strongly recommended that you use the <b>udp</b> transport layer because it wont block or slow down'),
    '#default_value' => $graylog_settings['transport'],
  ];

  $form['salto_core_graylog_settings']['channel'] = [
    '#type' => 'textfield',
    '#title' => t('Log channel'),
    '#description' => t('The log channel is important in order to determine the log stream in graylog'),
    '#default_value' => $graylog_settings['channel'],
  ];

  return system_settings_form($form);
}

function salto_core_customization_settings_form($form, &$form_state){

  $settings = variable_get('customization_settings', []);

  $form ['customization_settings'] = [
    '#type' => 'fieldset',
    '#title' => t('Customization'),
    '#collapsible' => FALSE,
    '#tree' => TRUE,
  ];

  $form['customization_settings']['fast_navigation'] = [
    '#type' => 'textarea',
    '#title' => t('Fast navigation content'),
    '#size' => 40,
    '#rows' => 5,
    '#description' => t('HTML Text for the fast navigation'),
    '#default_value' => $settings['fast_navigation'],
    ];

  $form['customization_settings'][SettingsService::SUB_SETTING_ASSIGN_GROUPS_RETROSPECTIVELY] = [
    '#type' => 'checkbox',
    '#title' => t('Community manager assign groups retrospectively'),
    '#description' => t('Community manager assign groups retrospectively. This will rebuild the nodeaccess for posts'),
    '#default_value' => $settings[SettingsService::SUB_SETTING_ASSIGN_GROUPS_RETROSPECTIVELY],
  ];

  $form['customization_settings'][SettingsService::SUB_SETTING_POST_TEASER_IMAGE_ENABLED] = [
    '#type' => 'checkbox',
    '#title' => t('Enable teaser images for posts'),
    '#description' => t('Enable selecting teaser images for posts'),
    '#default_value' => $settings[SettingsService::SUB_SETTING_POST_TEASER_IMAGE_ENABLED],
  ];

  $form['customization_settings'][SettingsService::SUB_SETTING_KNOWLEDGEBASE_FALLBACK_TID] = [
    '#type' => 'textfield',
    '#title' => t('Knowledgebase Fallback tid'),
    '#description' => t('Set the fallback tid'),
    '#default_value' => $settings[SettingsService::SUB_SETTING_KNOWLEDGEBASE_FALLBACK_TID],
  ];

  $form['customization_settings'][SettingsService::SUB_SETTING_RELEVANT_GROUP_FILTER] = [
    '#type' => 'checkbox',
    '#title' => t('Relevant group filter'),
    '#description' => t('When enabled, only show groups where the user can interact'),
    '#default_value' => $settings[SettingsService::SUB_SETTING_RELEVANT_GROUP_FILTER],
  ];


  $form['customization_settings']['mail_enable_preview_images'] = [
    '#type' => 'checkbox',
    '#title' => t('Mail enable preview images'),
    '#description' => t('When enabled, preview images are rendered in mail templates.'),
    '#default_value' => $settings['mail_enable_preview_images'],
  ];

  $form['customization_settings'][SettingsService::SUB_SETTING_MANAGE_USER_ORGANISATIONS] = [
    '#type' => 'checkbox',
    '#title' => t('Manage user organisations'),
    '#description' => t('When enabled, admins and community manager can edit the organisations from the user'),
    '#default_value' => $settings[SettingsService::SUB_SETTING_MANAGE_USER_ORGANISATIONS],
  ];

  $form['customization_settings'][SettingsService::SUB_SETTING_MANAGE_FORMAT_MATERIAL_TITLE] = [
    '#type' => 'checkbox',
    '#title' => t('Dateititel leer lassen = manuelles setzen erzwingen'),
    '#default_value' => $settings[SettingsService::SUB_SETTING_MANAGE_FORMAT_MATERIAL_TITLE],
  ];

  $fallbackNid = \salto_core\service\SettingsService::getFallbackOrganisationNid();
  $form['organisation_default_nid'] = [
    '#type' => 'textfield',
    '#title' => t('Default organisation nid'),
    '#description' => t('The nid for the fallback organisation'),
    '#default_value' => $fallbackNid,
  ];


  $settings = \salto_core\service\SettingsService::getSelectOrganisationOptions();
  $form [SettingsService::SETTING_ORGANISATION_SELECT] = array(
    '#type' => 'fieldset',
    '#title' => t('Invite organisation select'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $form[SettingsService::SETTING_ORGANISATION_SELECT][SettingsService::SUB_SETTING_ORGANISATION_SELECT_ENABLED] = [
    '#type' => 'checkbox',
    '#title' => t('Select Organisation'),
    '#default_value' => $settings[SettingsService::SUB_SETTING_ORGANISATION_SELECT_ENABLED],
    '#description' => t('Enable that the user can select the organisation when he gets invited')
  ];

  $form[SettingsService::SETTING_ORGANISATION_SELECT][SettingsService::SUB_SETTING_ORGANISATION_SELECT_FALLBACK_ORGANISATION_DISABLED] = [
    '#type' => 'checkbox',
    '#title' => t('Disable selecting the fallback organisation'),
    '#default_value' => $settings[SettingsService::SUB_SETTING_ORGANISATION_SELECT_FALLBACK_ORGANISATION_DISABLED],
  ];

  $form[SettingsService::SETTING_ORGANISATION_SELECT][SettingsService::SUB_SETTING_ORGANISATION_SELECT_INFO_TEXT_MAIL_TARGET] = [
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => $settings[SettingsService::SUB_SETTING_ORGANISATION_SELECT_INFO_TEXT_MAIL_TARGET],
    '#description' => 'This mail will be placed in the info text'
  ];


  $settings = \salto_core\service\SettingsService::getThemenfelderAsCard();
  $form ['themenfelder_as_card'] = array(
    '#type' => 'fieldset',
    '#title' => t('Themenfelder as card'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $form['themenfelder_as_card']['enabled'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable card view for materials'),
    '#default_value' => $settings['enabled'],
  ];

  $form['themenfelder_as_card']['default_logo'] = [
    '#type' => 'textfield',
    '#title' => t('Default logo for material cards'),
    '#default_value' => $settings['default_logo'],
  ];

  $form['themenfelder_as_card']['default_icon'] = [
    '#type' => 'textfield',
    '#title' => t('Default icon for material cards'),
    '#default_value' => $settings['default_icon'],
  ];

  $form['themenfelder_as_card']['taxonomy_id'] = [
    '#type' => 'textfield',
    '#title' => t('Default root taxonomy id'),
    '#default_value' => $settings['taxonomy_id'],
  ];



  $settings = \salto_core\service\SettingsService::getSocialVideoHelp();

  $form ['social_video_help'] = array(
    '#type' => 'fieldset',
    '#title' => t('Social video help info'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $form ['social_video_help']['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show social video help info'),
    '#default_value' => $settings['enabled'],
  );

  $form ['social_video_help']['panel_heading'] = array(
    '#type' => 'textfield',
    '#title' => t('Panel heading'),
    '#default_value' => $settings['panel_heading'],
    '#description' => t('The heading for the panel in the startpage')
  );

  $form ['social_video_help']['gif_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Gif destination'),
    '#default_value' => $settings['gif_url'],
    '#description' => t('The url where the gif can be loaded')
  );

  $form ['social_video_help']['target_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Help video'),
    '#default_value' => $settings['target_url'],
    '#description' => t('The url to redirect behind the gif')
  );

  $form['#submit'][] = 'salto_core_customization_settings_form_submit';

    return system_settings_form($form);
}

function salto_core_customization_settings_form_submit($form, &$form_state){

  $nodeaccessPost = variable_get('nodeaccess_post', []);
  $newAccessPost = [];

  $oldSetting = \salto_core\service\SettingsService::assignGroupsRetrospectivelyEnabled();
  $newSetting = $form_state['values']['customization_settings']['assign_groups_retrospectively'];
  if($oldSetting == $newSetting){
    return;
  }

  foreach($nodeaccessPost as $grant){

    if($grant['gid'] == 6){
      $grant['grant_view'] = $form_state['values']['customization_settings']['assign_groups_retrospectively'] ?? 0;
      $grant['grant_update'] = $form_state['values']['customization_settings']['assign_groups_retrospectively'] ?? 0;
    }

    $newAccessPost[] = $grant;
  }

  variable_set('nodeaccess_post', $newAccessPost);
  salto_debug_rebuild_node_access_by_type('post');
  drupal_set_message('Grants successfully rebuilded');
}
