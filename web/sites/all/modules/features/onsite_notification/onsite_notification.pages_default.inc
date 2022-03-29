<?php

/**
 * @file
 * onsite_notification.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function onsite_notification_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'group_subscriptions';
  $page->task = 'page';
  $page->admin_title = 'group subscriptions';
  $page->admin_description = 'An overview of all user notifications';
  $page->path = 'notifications/group/subscriptions/!user';
  $page->access = array(
    'logic' => 'or',
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Check notification access',
          'php' => '$account = $contexts[\'argument_entity_id:user_1\']->data;
return onsite_notification_access($account);',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view own notifications',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Abonnierte Gruppen',
    'name' => 'onsite_notifications',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'onsite_notifications',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'Benutzer: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_group_subscriptions__panel_context_938b6c6f-3a3d-493e-b4ae-52863ec53dbb';
  $handler->task = 'page';
  $handler->subtask = 'group_subscriptions';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Manage Subscriptions',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'salto_39';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Abonierte Beiträge';
  $display->uuid = 'aed38059-eb31-4095-b678-f88ba54eea16';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_group_subscriptions__panel_context_938b6c6f-3a3d-493e-b4ae-52863ec53dbb';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-30219d7a-2efe-462d-90f5-754b5de7bba0';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'onsite_notifications';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'onsite_notifications',
    'parent_mlid' => 'onsite_notifications:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => 0,
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '30219d7a-2efe-462d-90f5-754b5de7bba0';
  $display->content['new-30219d7a-2efe-462d-90f5-754b5de7bba0'] = $pane;
  $display->panels['left'][0] = 'new-30219d7a-2efe-462d-90f5-754b5de7bba0';
  $pane = new stdClass();
  $pane->pid = 'new-5737d237-ee20-42fc-b7d1-a168acceb2fb';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'subsciptions-panel_pane_groups_subscriptions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'subscriptions_view',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5737d237-ee20-42fc-b7d1-a168acceb2fb';
  $display->content['new-5737d237-ee20-42fc-b7d1-a168acceb2fb'] = $pane;
  $display->panels['right'][0] = 'new-5737d237-ee20-42fc-b7d1-a168acceb2fb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['group_subscriptions'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'material_subscriptions';
  $page->task = 'page';
  $page->admin_title = 'material subscriptions';
  $page->admin_description = 'An overview of all user notifications';
  $page->path = 'notifications/material/subscriptions/!user';
  $page->access = array(
    'logic' => 'or',
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Check notification access',
          'php' => '$account = $contexts[\'argument_entity_id:user_1\']->data;
return onsite_notification_access($account);',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view own notifications',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Abonnierte Materialien',
    'name' => 'onsite_notifications',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'onsite_notifications',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'Benutzer: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_material_subscriptions__panel_context_bc73f138-ec93-4ad3-bcaa-3877b55a3e5e';
  $handler->task = 'page';
  $handler->subtask = 'material_subscriptions';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Manage Subscriptions',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'salto_39';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Abonierte Beiträge';
  $display->uuid = 'aed38059-eb31-4095-b678-f88ba54eea16';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_material_subscriptions__panel_context_bc73f138-ec93-4ad3-bcaa-3877b55a3e5e';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-30219d7a-2efe-462d-90f5-754b5de7bba0';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'onsite_notifications';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'onsite_notifications',
    'parent_mlid' => 'onsite_notifications:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => 0,
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '30219d7a-2efe-462d-90f5-754b5de7bba0';
  $display->content['new-30219d7a-2efe-462d-90f5-754b5de7bba0'] = $pane;
  $display->panels['left'][0] = 'new-30219d7a-2efe-462d-90f5-754b5de7bba0';
  $pane = new stdClass();
  $pane->pid = 'new-618bc22c-3359-4311-a6a2-8f06605ef83a';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'subscriptions_materials-panel_material_subscription_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'subscriptions_view',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '618bc22c-3359-4311-a6a2-8f06605ef83a';
  $display->content['new-618bc22c-3359-4311-a6a2-8f06605ef83a'] = $pane;
  $display->panels['right'][0] = 'new-618bc22c-3359-4311-a6a2-8f06605ef83a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['material_subscriptions'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'newsletter_export';
  $page->task = 'page';
  $page->admin_title = 'Newsletter Export';
  $page->admin_description = '';
  $page->path = 'newsletter/export';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 6,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_newsletter_export_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'newsletter_export';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'salto_93';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'E-Mail-Verteiler';
  $display->uuid = '04c1a1f6-1c9a-468b-8ed6-9259fe8c97c2';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_newsletter_export_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-86b06bff-626f-46c9-8f81-55ec6745da1a';
  $pane->panel = 'left';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Text mit Anzahl der jeweiligen E-Mail-Adressen',
    'title' => '',
    'body' => '<?php
$bildungsreferenten = onsite_notification_get_bildungsreferenten_for_newsletter_export();
$trainer = 0; //todo, as soon as we have the user role

$all_users = $bildungsreferenten + $trainer;
?>

<p>
Aktuell <?php echo format_plural($all_users, \'hat ein\', \'haben @count\');?> Benutzer im Bildungsnetz die Newsletter abonniert.
</p>
<p>
Es <?php echo format_plural($bildungsreferenten, \'wird eine E-Mail-Adresse\', \'werden @count E-Mail-Adressen\');?> exportiert und dabei <?php echo $trainer ?> E-Mail-Adressen von Trainern ignoriert.
</p>

',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '86b06bff-626f-46c9-8f81-55ec6745da1a';
  $display->content['new-86b06bff-626f-46c9-8f81-55ec6745da1a'] = $pane;
  $display->panels['left'][0] = 'new-86b06bff-626f-46c9-8f81-55ec6745da1a';
  $pane = new stdClass();
  $pane->pid = 'new-5cf31456-8448-4c87-8fc0-910b4ed8cc3c';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Export Button',
    'title' => '',
    'body' => '<?php 
$query = request_uri();
$query = substr($query, strpos($query, \'?\'));
?>
<a class="btn btn-primary action_link action_export" href="/newsletter/export/xls<?=$query?>" style="float:right;">E-Mail-Adressen exportieren (XLS)</a>',
    'format' => 'php_code',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5cf31456-8448-4c87-8fc0-910b4ed8cc3c';
  $display->content['new-5cf31456-8448-4c87-8fc0-910b4ed8cc3c'] = $pane;
  $display->panels['right'][0] = 'new-5cf31456-8448-4c87-8fc0-910b4ed8cc3c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5cf31456-8448-4c87-8fc0-910b4ed8cc3c';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['newsletter_export'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'notifications';
  $page->task = 'page';
  $page->admin_title = 'notifications';
  $page->admin_description = 'An overview of all user notifications';
  $page->path = 'notifications/all/!user';
  $page->access = array(
    'logic' => 'or',
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Check notification access',
          'php' => '$account = $contexts[\'argument_entity_id:user_1\']->data;

if(empty($account)) {
  $account = is_numeric(arg(2)) ? user_load(arg(2)) : null;
}
return onsite_notification_access($account);',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view any notifications',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Benachrichtigungen',
    'name' => 'onsite_notifications',
    'weight' => '-10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'onsite_notifications',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'Benutzer: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_notifications_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'notifications';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'View',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'salto_363';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Benachrichtigungen';
  $display->uuid = 'aecf45c7-86df-4404-9480-bd657dbf428e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_notifications_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4fa20771-a7e8-4b15-bc8d-ed04c6e7b393';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'onsite_notifications';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'onsite_notifications',
    'parent_mlid' => 'onsite_notifications:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => 0,
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4fa20771-a7e8-4b15-bc8d-ed04c6e7b393';
  $display->content['new-4fa20771-a7e8-4b15-bc8d-ed04c6e7b393'] = $pane;
  $display->panels['left'][0] = 'new-4fa20771-a7e8-4b15-bc8d-ed04c6e7b393';
  $pane = new stdClass();
  $pane->pid = 'new-5fdf5d86-9050-4301-b58b-1c6ddf158ba8';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views--exp-notifications-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'inherit_path' => 1,
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'blockpanel',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5fdf5d86-9050-4301-b58b-1c6ddf158ba8';
  $display->content['new-5fdf5d86-9050-4301-b58b-1c6ddf158ba8'] = $pane;
  $display->panels['left'][1] = 'new-5fdf5d86-9050-4301-b58b-1c6ddf158ba8';
  $pane = new stdClass();
  $pane->pid = 'new-3f432629-f50d-49f9-b3bb-47ed39e12c71';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'notifications-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:user_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'subscriptions_view',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3f432629-f50d-49f9-b3bb-47ed39e12c71';
  $display->content['new-3f432629-f50d-49f9-b3bb-47ed39e12c71'] = $pane;
  $display->panels['middle'][0] = 'new-3f432629-f50d-49f9-b3bb-47ed39e12c71';
  $pane = new stdClass();
  $pane->pid = 'new-8a55cbfe-5878-40f7-9e78-59fa79b1d365';
  $pane->panel = 'right';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Action links',
    'title' => '',
    'body' => '<a href="#" class="btn btn-primary btn-markallasread" onclick="Drupal.OnsiteNotification.MarkNotificationsAsRead(\'<?php print drupal_get_token() ?>\');">Alle als gelesen markieren</a>',
    'format' => 'php_code',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'pane-action-links',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8a55cbfe-5878-40f7-9e78-59fa79b1d365';
  $display->content['new-8a55cbfe-5878-40f7-9e78-59fa79b1d365'] = $pane;
  $display->panels['right'][0] = 'new-8a55cbfe-5878-40f7-9e78-59fa79b1d365';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['notifications'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'subscriptions';
  $page->task = 'page';
  $page->admin_title = 'subscriptions';
  $page->admin_description = 'An overview of all user notifications';
  $page->path = 'notifications/subscriptions/!user';
  $page->access = array(
    'logic' => 'or',
    'plugins' => array(
      0 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Check notification access',
          'php' => '$account = $contexts[\'argument_entity_id:user_1\']->data;
return onsite_notification_access($account);',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view own notifications',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Abonnierte Beiträge',
    'name' => 'onsite_notifications',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'onsite_notifications',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'Benutzer: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_subscriptions_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'subscriptions';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Manage Subscriptions',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'salto_39';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Abonierte Beiträge';
  $display->uuid = 'aed38059-eb31-4095-b678-f88ba54eea16';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_subscriptions_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-30219d7a-2efe-462d-90f5-754b5de7bba0';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'onsite_notifications';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'onsite_notifications',
    'parent_mlid' => 'onsite_notifications:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => 0,
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '30219d7a-2efe-462d-90f5-754b5de7bba0';
  $display->content['new-30219d7a-2efe-462d-90f5-754b5de7bba0'] = $pane;
  $display->panels['left'][0] = 'new-30219d7a-2efe-462d-90f5-754b5de7bba0';
  $pane = new stdClass();
  $pane->pid = 'new-9d3896eb-b0b9-477d-b13a-08cce4de1c71';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'subsciptions-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'subscriptions_view',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9d3896eb-b0b9-477d-b13a-08cce4de1c71';
  $display->content['new-9d3896eb-b0b9-477d-b13a-08cce4de1c71'] = $pane;
  $display->panels['right'][0] = 'new-9d3896eb-b0b9-477d-b13a-08cce4de1c71';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['subscriptions'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'subscriptions_ignored';
  $page->task = 'page';
  $page->admin_title = 'subscriptions_ignored';
  $page->admin_description = 'An overview of all user notifications';
  $page->path = 'notifications/ignored/!user';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      2 => array(
        'name' => 'auto_subscribe_enabled',
        'settings' => array(
          'entity_type' => 'post',
        ),
        'context' => array(
          0 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Ignorierte Beiträge',
    'name' => 'onsite_notifications',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'onsite_notifications',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'Benutzer: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_subscriptions_ignored__panel_context_8b1e075c-134a-4b4d-b0d9-cd281e5254a4';
  $handler->task = 'page';
  $handler->subtask = 'subscriptions_ignored';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Manage Subscriptions',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'salto_39';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Abonierte Beiträge';
  $display->uuid = 'aed38059-eb31-4095-b678-f88ba54eea16';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_subscriptions_ignored__panel_context_8b1e075c-134a-4b4d-b0d9-cd281e5254a4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-30219d7a-2efe-462d-90f5-754b5de7bba0';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'onsite_notifications';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'onsite_notifications',
    'parent_mlid' => 'onsite_notifications:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => 0,
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '30219d7a-2efe-462d-90f5-754b5de7bba0';
  $display->content['new-30219d7a-2efe-462d-90f5-754b5de7bba0'] = $pane;
  $display->panels['left'][0] = 'new-30219d7a-2efe-462d-90f5-754b5de7bba0';
  $pane = new stdClass();
  $pane->pid = 'new-a397e428-2d70-46f3-bb60-1f89ce9cf7a9';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'subsciptions-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'subscriptions_view',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a397e428-2d70-46f3-bb60-1f89ce9cf7a9';
  $display->content['new-a397e428-2d70-46f3-bb60-1f89ce9cf7a9'] = $pane;
  $display->panels['right'][0] = 'new-a397e428-2d70-46f3-bb60-1f89ce9cf7a9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['subscriptions_ignored'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'subscriptions_ignored_material';
  $page->task = 'page';
  $page->admin_title = 'subscriptions_ignored_material';
  $page->admin_description = 'An overview of all user notifications';
  $page->path = 'notifications/material/ignored/!user';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      2 => array(
        'name' => 'auto_subscribe_enabled',
        'settings' => array(
          'entity_type' => 'file',
        ),
        'context' => array(
          0 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Ignorierte Materialen',
    'name' => 'onsite_notifications',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'onsite_notifications',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'Benutzer: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_subscriptions_ignored_material__panel_context_4aaf039b-799c-4e4c-8f89-5c67f1ba2206';
  $handler->task = 'page';
  $handler->subtask = 'subscriptions_ignored_material';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Manage Subscriptions',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'salto_39';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Abonierte Beiträge';
  $display->uuid = 'aed38059-eb31-4095-b678-f88ba54eea16';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_subscriptions_ignored_material__panel_context_4aaf039b-799c-4e4c-8f89-5c67f1ba2206';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-30219d7a-2efe-462d-90f5-754b5de7bba0';
  $pane->panel = 'left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'onsite_notifications';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'menu_name' => 'onsite_notifications',
    'parent_mlid' => 'onsite_notifications:0',
    'title_link' => 0,
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => 0,
    'expanded' => 0,
    'sort' => 0,
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '30219d7a-2efe-462d-90f5-754b5de7bba0';
  $display->content['new-30219d7a-2efe-462d-90f5-754b5de7bba0'] = $pane;
  $display->panels['left'][0] = 'new-30219d7a-2efe-462d-90f5-754b5de7bba0';
  $pane = new stdClass();
  $pane->pid = 'new-90399ffa-522b-4a03-8895-7913e89e09e8';
  $pane->panel = 'right';
  $pane->type = 'views_panes';
  $pane->subtype = 'subscriptions_materials-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'subscriptions_view',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '90399ffa-522b-4a03-8895-7913e89e09e8';
  $display->content['new-90399ffa-522b-4a03-8895-7913e89e09e8'] = $pane;
  $display->panels['right'][0] = 'new-90399ffa-522b-4a03-8895-7913e89e09e8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['subscriptions_ignored_material'] = $page;

  return $pages;

}
