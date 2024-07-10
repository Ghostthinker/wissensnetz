<?php

namespace Wissensnetz\Group;

use Wissensnetz\Core\Node\DrupalNode;
use Wissensnetz\User\DrupalUser;

class GroupDrupalNode extends DrupalNode {

  static function current() {
    $og = og_context();
    if(empty($og['gid'])){
      return NULL;
    }
    return self::make($og['gid']);
  }

  static function getNidAndTitleFromAllGroups(){
    $query = "SELECT node.nid, node.title
    FROM {node} node
    WHERE (node.type in ('group'))
    AND (node.status = 1)
    ORDER BY node.title ASC
    ";

    $result = db_query($query)->fetchAllKeyed();
    if (empty($result)) {
      return [];
    }

    return $result;

  }

  public function getMeetingReadAccess(){
    return $this->node->field_meeting_collaboration[LANGUAGE_NONE][0]['read'];
  }

  public function getMeetingEditAccess(){
    return $this->node->field_meeting_collaboration[LANGUAGE_NONE][0]['edit'];
  }

  public function getJoinMode(){
    return $this->node->field_group_join_mode[LANGUAGE_NONE][0]['value'];
  }

}
