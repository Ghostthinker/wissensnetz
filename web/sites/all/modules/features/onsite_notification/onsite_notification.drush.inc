<?php

include_once DRUPAL_ROOT . '/modules/system/system.queue.inc';
include_once DRUPAL_ROOT . '/sites/all/modules/features/salto_core/queue/CoreSystemQueue.php';

function onsite_notification_drush_command() {
  $items = [];
  $items['onsite_notification_run_core_queue'] = [
    'callback' => "onsite_notification_run_core_queue",
    'description' => "Execute the core system queue for mail notifications (module)",
    'arguments' => [
      'module' => dt('Module name (comming soon)'),
    ],
    'examples' => [
      'Execute' => 'drush notify-rcq',
    ],
    'aliases' => ['notify-rcq'],
    'core' => [7],
  ];
  return $items;
}

/**
 * Should crontab (every 7 minutes)
 * => *'/7 *   * * *    wissensnetz   cd web/ && bash/drush notify-rcq
 * or via bash script
 * => *'/7 *   * * *    wissensnetz   bash
 * /home/wissensnetz/salto_bn/scripts/run-notify-rcq.sh
 * ===> cd web/; drush notify-rcq;
 */
function onsite_notification_run_core_queue() {
  \CoreSystemQueue::executeByModule('onsite_notification');
}
