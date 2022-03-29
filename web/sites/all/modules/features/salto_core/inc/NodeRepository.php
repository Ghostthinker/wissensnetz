<?php


class NodeRepository {

  /**
   * @param $withoutNids
   *
   * @return mixed
   */
  function getNodeIdsWithout($withoutNids = []) {

    $nodes = db_select('node', 'n')
      ->fields('n', ['nid'])
      ->condition('n.nid', $withoutNids, 'NOT IN')
      ->execute()
      ->fetchCol();

    return $nodes;
  }

  /**
   * @param array $types
   * @param bool $notIn
   *
   * @return mixed
   */
  function getNodeIdsByType($types, $notIn = FALSE) {
    if (empty($types)) {
      return [];
    }

    $operator = 'IN';
    if ($notIn) {
      $operator = 'NOT IN';
    }

    $nodes = db_select('node', 'n')
      ->fields('n', ['nid'])
      ->condition('n.type', $types, $operator)
      ->execute()->fetchCol();

    return $nodes;
  }

  /**
   * @param array $userIds
   * @param bool $notIn
   *
   * @return mixed
   */
  function getNodeIdsByUsers($userIds, $notIn = FALSE) {
    if (empty($userIds)) {
      return [];
    }

    $operator = 'IN';
    if ($notIn) {
      $operator = 'NOT IN';
    }

    $nodes = db_select('node', 'n')
      ->fields('n', ['nid'])
      ->condition('n.uid', $userIds, $operator)
      ->execute()->fetchCol();

    return $nodes;
  }

  /**
   * Get an array with og/group nid by uid
   *
   * @param $uid
   * @param array $states
   *   limit to group states -  default is only active users
   *
   * @return mixed
   */
  function getGroupIdsByUser($uid, $states = [OG_STATE_ACTIVE]) {
    return $this->getGroupIdsByUsers([$uid], $states);
  }

  /**
   * Get an array with og/group nid by user ids
   *
   * @param $uids
   * @param array $states
   *   limit to group states -  default is only active users
   *
   * @return mixed
   */
  function getGroupIdsByUsers($uids, $states = [OG_STATE_ACTIVE]) {
    if (empty($uids)) {
      return [];
    }

    $query = db_select("og_membership", "ogm");
    $query->addField("ogm", 'gid', 'nid');
    $query->addField("ogm", 'gid', 'nid');
    $query->condition("ogm.etid", $uids, 'IN');
    $query->condition("ogm.state", $states, "IN");
    $query->condition("ogm.entity_type", 'user', "=");
    $query->condition('ogm.type', 'group_membership');

    return $query->execute()->fetchAllKeyed();
  }

}
