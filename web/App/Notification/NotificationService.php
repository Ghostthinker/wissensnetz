<?php


namespace Wissensnetz\Notification;

use Wissensnetz\Group\GroupDrupalNode;
use Wissensnetz\User\DrupalUser;

class NotificationService {

  public function getNewNotificationsCount($uid) {
    return count(onsite_notificaions_get_new_notifications($uid, 'data'));
  }
}
