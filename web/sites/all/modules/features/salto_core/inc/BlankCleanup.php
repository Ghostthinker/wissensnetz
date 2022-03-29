<?php


class BlankCleanup {

  const OG_LSB_NIEDERSACHSEN_ID = 1066;

  const OG_DEUTSCHE_EISLAUF_UNION_ID = 1140;

  const OG_DEUTSCHE_REITERLICHE_VEREIN_ID = 1089;

  const OG_GHOSTTHINKER_ID = 104;

  const OG_FALLBACK_ID = 2943;

  const OG_DOSB_ID = 1756;

  const BLANCO_CLEANUP_TYPE = 'blanca_cleanup';

  /**
   * @return array
   */
  function getFixedUserIds() {
    $fixed = [
      0,      // guest
      1,      // admin
      241,    // sh
      278,    // jm
      279,    // sn
      315,    // Theme Developer
      870,    // bh
      1794,   // se
      1857,   // lk
      2,   // screencasts
      1003,   // screencasts
      546,   // screencasts
      549,   // screencasts
    ];
    $ghosties = $this->getUserIdsForOrganisation(self::OG_GHOSTTHINKER_ID);
    return array_unique(array_merge($fixed, $ghosties));
  }

  /**
   * @param $ogNid
   *
   * @return array
   */
  function getUserIdsForOrganisation($ogNid) {
    if ($ogNid == NULL) {
      return [];
    }

    try {
      $uids = salto_og_get_users_by_og($ogNid);
      $keep_uids = array_unique($uids);
      return $keep_uids;
    } catch (Exception $ex) {
      watchdog_exception(self::BLANCO_CLEANUP_TYPE, $ex);
      return [];
    }
  }

  function getAllUserIds($ogNids = [], $withGuest = FALSE) {
    $keep = [];
    foreach ($ogNids as $nid) {
      $keep = array_merge($keep, $this->getUserIdsForOrganisation($nid));
    }
    $fixed = $this->getFixedUserIds();
    $result = array_unique(array_merge($fixed, $keep));
    if (!$withGuest) {
      if (($key = array_search(0, $result)) !== FALSE) {
        unset($result[$key]);
      }
    }

    return $result;
  }


  function getAllNotificationsIds() {
    $message_mids = db_select('message', 'm')
      ->fields('m', ['mid'])
      ->condition('m.type', db_like('notification_') . '%', 'LIKE')
      ->execute()->fetchCol();

    return $message_mids;
  }

  function deleteNotifications($message_mids) {
    message_delete_multiple($message_mids);
  }

  /**
   * truncate db tables
   *
   * @return bool
   */
  function truncateTables() {
    
    $tables = [
      'accesslog',
      'browscap',
      'cache',
      'cache_admin_menu',
      'cache_block',
      'cache_bootstrap',
      'cache_browscap',
      'cache_clients',
      'cache_entity_message',
      'cache_entity_message_type',
      'cache_entity_message_type_category',
      'cache_entity_og_membership',
      'cache_entity_og_membership_type',
      'cache_features',
      'cache_feeds_http',
      'cache_field',
      'cache_filter',
      'cache_form',
      'cache_image',
      'cache_l10n_update',
      'cache_libraries',
      'cache_menu',
      'cache_page',
      'cache_panels',
      'cache_path',
      'cache_path_breadcrumbs',
      'cache_rules',
      'cache_search_api_solr',
      'cache_token',
      'cache_update',
      'cache_variable',
      'cache_views',
      'cache_views_data',
      'security_questions',
      'security_questions_answers',
      'security_questions_incorrect',
      'dosb_license',
      'dosb_license_consecutive_number',
      'dosb_license_data_revision',
      'dosb_license_deleted',
      'dosb_license_generator_tasks',
      'dosb_license_import_item',
      'dosb_license_invalids',
      'dosb_license_migration',
      'dosb_license_relations',
      'dosb_license_reservation',
      'dosb_license_revision',
      'dosb_license_validity_history',
      'heartbeat_activity',
      'lims_api_log',
      'lims_api_downloads',
      'sessions',
      'search_api_task',
      'visitors',
      'watchdog',
      'captcha_sessions'
    ];

    $result = TRUE;
    foreach ($tables as $table_name) {

      if(!db_table_exists($table_name)) continue;
      $result_loop = db_truncate($table_name)->execute();
      $result = $result && $result_loop;
    }

    return $result;
  }

  /**
   * revoke role Lizenzverantwortlicher from all users
   *
   * @return \DatabaseStatementInterface
   */
  function revokeLVRole() {
    $result = db_delete('users_roles')
      ->condition('rid', SALTO_ORGANISATION_OG_ROLE_LIZENZVERWALTER_RID) // global and og rid are the same (7)
      ->execute();

    return $result;
  }

  /**
   * delete unneeded files
   *
   * @param $userIds
   * @param bool $notIn
   *
   * @return bool
   */
  function deleteUserFiles($userIds, $notIn = FALSE) {
    if (empty($userIds)) {
      return FALSE;
    }

    $operator = 'IN';
    if ($notIn) {
      $operator = 'NOT IN';
    }

    $query = db_select('file_managed', 'm')
      ->fields('m', ['fid'])
      ->condition('m.uid', $userIds, $operator);

    $fids = $query->execute()->fetchCol();

    try {
      file_delete_multiple($fids);
    } catch (Exception $ex) {
      watchdog_exception(self::BLANCO_CLEANUP_TYPE, $ex);
    }
    return TRUE;
  }


  /**
   * Be careful! This wipes out all user data from a dev system before a
   * versiondump is made Keeps all admins, though
   *
   * @param $keepUids
   *
   * @return bool [type] [description]
   */
  function executeCleanUserData($keepUids) {
    if (empty($keepUids)) {
      return FALSE;
    }

    $data = db_query('SELECT uid,uid FROM {users} WHERE uid not in (:uids)', [':uids' => $keepUids])->fetchAllKeyed();

    try {
      user_delete_reassign_multiple($data);
    } catch (Exception $ex) {
      dpm("Could not reassign: " . $ex->getMessage());
      watchdog_exception(self::BLANCO_CLEANUP_TYPE, $ex);
    }

    foreach ($data as $uid) {
      try {
        user_delete($uid);
      } catch (Exception $ex) {
        dpm("Could not delete: " . $ex->getMessage());
        watchdog_exception(self::BLANCO_CLEANUP_TYPE, $ex);
      }
    }
    drupal_set_message('deleted users: ' . count($data), 'status', FALSE);

    return TRUE;
  }

  /**
   * 1. Scenario delete nodes
   *   => delete all nodes in array
   * 2. Scenario delete nodes keep
   *   => delete all other nodes (which nodes not in array)
   *
   * @param array $nids
   * @param bool $keep
   * @param bool $delPerDb
   *
   * @return bool
   */
  function deleteNodes($nids, $keep = FALSE, $delPerDb = FALSE) {
    if (empty($nids)) {
      return FALSE;
    }

    $nodes = $nids;
    $operator = 'IN';
    if ($keep) {
      $repository = new NodeRepository();
      $nodes = $repository->getNodeIdsWithout($nids);
      $operator = 'NOT IN';
    }

    if (!$delPerDb) {
      foreach ($nodes as $nid) {
        try {
          node_delete($nid);
        } catch (Exception $ex) {
          watchdog_exception(self::BLANCO_CLEANUP_TYPE, $ex);
        }
      }
    }

    if ($delPerDb) {
      $this->deleteNodesInDb($nodes, $operator);
    }
    return TRUE;
  }

  /**
   * 1. Scenario delete types
   *   => delete all types in array
   * 2. Scenario delete types keep
   *   => delete all other types (which types not in array)
   *
   * @param array $types
   * @param bool $keep
   * @param bool $delPerDb
   *
   * @return bool
   */
  function deleteNodesByTypes($types, $keep = FALSE, $delPerDb = FALSE) {
    if (empty($types)) {
      return FALSE;
    }
    $repository = new NodeRepository();
    $nodes = $repository->getNodeIdsByType($types, $keep);

    $operator = 'IN';
    if ($keep) {
      $operator = 'NOT IN';
    }

    if (!$delPerDb) {
      foreach ($nodes as $nid) {
        try {
          node_delete($nid);
        } catch (Exception $ex) {
          watchdog_exception(self::BLANCO_CLEANUP_TYPE, $ex);
        }
      }
    }

    if ($delPerDb) {
      $this->deleteNodesInDb($nodes, $operator);
    }
    return TRUE;
  }

  /**
   * @param $nodes
   * @param $operator
   */
  private function deleteNodesInDb($nodes, $operator) {
    db_delete('node')
      ->condition('nid', $nodes, $operator)
      ->execute();

    db_delete('node_revision')
      ->condition('nid', $nodes, $operator)
      ->execute();
  }

  function cleanupFallbackOG($deleteOG = FALSE) {
    $users = $this->getUserIdsForOrganisation(self::OG_FALLBACK_ID);
    $keep = $this->getFixedUserIds();

    foreach ($users as $uid) {
      if (in_array($uid, $keep)) {
        continue;
      }
      try {
        if ($this->deleteFallbackMembership($uid)) {
          continue;
        }
        user_delete($uid);
      } catch (Exception $ex) {
        watchdog_exception(self::BLANCO_CLEANUP_TYPE, $ex);
        watchdog(self::BLANCO_CLEANUP_TYPE, '$user cannot delete:' . $uid, WATCHDOG_ERROR);
      }
    }

    if ($deleteOG) {
      $this->deleteNodes([self::OG_FALLBACK_ID]);
    }
  }

  /**
   * user is in one or more ogs, then delete membership with fallback og
   *
   * @param $uid
   *
   * @return bool
   */
  function deleteFallbackMembership($uid) {
    $account = user_load($uid, TRUE);
    if ($account === NULL) {
      return FALSE;
    }

    $organisations = $account->field_user_organisations[LANGUAGE_NONE];
    $ogCount = !empty($organisations) ? count($organisations) : 0;
    if ($ogCount < 2) {
      return FALSE;
    }

    // check if fallback organisation is set
    foreach ($organisations as $ogItem) {
      if ($ogItem['target_id'] == self::OG_FALLBACK_ID) {
        $og_membership = og_get_membership('node', self::OG_FALLBACK_ID, 'user', $account->uid);
        og_membership_delete($og_membership->id);

        watchdog(self::BLANCO_CLEANUP_TYPE, 'User <em>%name</em> has been removed from fallback organisation <em>%fallback_title</em>.', [
          '%name' => $account->realname,
        ], WATCHDOG_INFO);
        return TRUE;
      }
    }
    return FALSE;
  }

  function getSaltoInviteIds() {
    return db_select('salto_invite', 's')
      ->fields('s', ['salto_invite_id'])
      ->execute()
      ->fetchCol();
  }

  function deleteSaltoInvites() {
    $invites = $this->getSaltoInviteIds();
    salto_invite_delete_multiple($invites);
  }

}
