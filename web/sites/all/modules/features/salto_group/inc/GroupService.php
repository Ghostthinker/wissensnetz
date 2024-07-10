<?php

namespace salto_group;

use Wissensnetz\User\DrupalUser;
use Wissensnetz\User\Exception\DrupalUserNotExistsException;

class GroupService {


  public function __construct() {
  }

  public function getGroupList($guid) {
    try {
      $drupalUser = DrupalUser::byGuid($guid);

      global $conf;

      $ogs = $this->getGroupNidsByUser($drupalUser->getUser());

      $groupList[] = [
        'iconUrl' => url("/" . drupal_get_path('module', 'wn_blanko') . "/images/" . $conf['wn_blanko']['favicon'], ['absolute' => TRUE]),
        'name' => $conf['site_name'],
        'domainUrl' => $conf['site_url'],
        'type' => 'community',
        'ogs' => $this->createGroupList($ogs),
      ];
      return $groupList;
    } catch (\Exception $e) {
      watchdog_exception('groupService', $e);
      return [];
    }
  }

  private function createGroupList($ogs) {

    $groupList = [];

    foreach ($ogs as $ogNid) {

      $ogNode = node_load($ogNid);

      $groupList[] = [
        'title' => $ogNode->title,
        'url' => url('node/' . $ogNid, [
          'absolute' => TRUE,
        ])
      ];
    }
    return $groupList;
  }

  private function getGroupNidsByUser($getUser) {
    if (empty($getUser->field_user_groups[LANGUAGE_NONE])) {
      return [];
    }

    $result = [];
    foreach ($getUser->field_user_groups[LANGUAGE_NONE] as $nid) {
      $roles = og_get_user_roles('node', $nid['target_id'], $getUser->uid);
      if ($roles[5]) {
        $result[] = $nid['target_id'];
      }
    }

    return $result;
  }

}
