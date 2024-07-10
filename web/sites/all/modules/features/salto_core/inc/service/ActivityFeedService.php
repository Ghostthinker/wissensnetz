<?php

namespace salto_core\service;

use HeartbeatStreamFactory;
use Wissensnetz\Core\Node\DrupalNode;
use Wissensnetz\User\DrupalUser;

class ActivityFeedService {

  public function getActivityFeedForUser(DrupalUser $drupalUser, $time, $limit) {
    global $user, $conf;

    $streamConfig = heartbeat_stream_config_load('siteactivity');
    $streamConfig->beforeTimestamp = $time;
    $streamConfig->limit = $limit;
    $streamConfig->noGroup = TRUE;
    $page = NULL;
    $account = user_load($drupalUser->getUid());
    $user = $account;
    $heartbeatStream = HeartbeatStreamFactory::getStream($streamConfig, $page, $drupalUser->getUser());
    heartbeat_stream_build($heartbeatStream);
    $activities = $heartbeatStream->getMessages();
    return [
      'context' => [
        "title" => $conf['site_name'],
        "iconUrl" => url("/" . drupal_get_path('module', 'wn_blanko') . "/images/" . $conf['wn_blanko']['favicon'], ['absolute' => TRUE]),
        "url" => url('', ['absolute' => TRUE]),
        "type" => 'community'
      ],
      "activities" => $this->prepareActivities($activities),
    ];
    return $activities;

  }

  private function prepareActivities($activities) {
    $result = [];
    foreach ($activities as $activity) {
      $drupalUser = DrupalUser::make($activity->uid);
      $drupalNode = DrupalNode::make($activity->nid);
      $info = [];
      $info['instance'] = url('', ['absolute' => TRUE]);
      $message = $activity->message;
      $message = str_replace('<a', '<a class="activity-feed-a" ', $message);
      $message = str_replace('href=""', 'href="' . $drupalNode->getUrlAbsolute() . '"', $message);
      $message = str_replace('href="node', 'href="' . url('', ['absolute' => TRUE]) . 'node', $message);
      $message = str_replace('<blockquote>', '<blockquote class="activity-feed-blockquote">', $message);
      $info['message'] = str_replace('href="/', 'href="' . url('', ['absolute' => TRUE]), $message);
      $info['targetUrl'] = $drupalNode->getUrlAbsolute();
      $info['created'] = format_date($activity->timestamp, 'custom', 'Y-m-d H:i:s');
      $info['author'] = [
        'image' => $drupalUser->getProfileImageUrl(),
        'url' => $drupalUser->getUserUrl()
      ];

      $result[] = $info;
    }

    return $result;

  }

}
