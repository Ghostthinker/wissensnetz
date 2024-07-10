<?php

namespace salto_core\service;

use Wissensnetz\Core\Node\DrupalNode;
use Wissensnetz\User\DrupalUser;

class OnlineTreffenService {

  public function getLatestDialogByUser(DrupalUser $drupalUser) {

    $query = "SELECT DISTINCT(node.nid) AS nid, node.nid
    FROM {node} node
    INNER JOIN {field_data_field_online_meeting_date} omd ON node.nid = omd.entity_id
    WHERE (node.type in ('online_meeting'))
    AND NOW() < CAST(omd.field_online_meeting_date_value as DATETIME)
    AND (node.status = 1)
    ORDER BY omd.field_online_meeting_date_value ASC
    ";

    $result = db_query($query)->fetchAllKeyed();
    if (empty($result)) {
      return NULL;
    }

    foreach ($result as $nid) {
      $drupalNode = DrupalNode::make($nid);
      if ($drupalNode->hasViewAccess($drupalUser)) {
        return $drupalNode;
      }

    }

    return NULL;
  }

}
