<?php

namespace salto_core\service;

use Wissensnetz\Core\Node\DrupalNode;
use Wissensnetz\Core\Node\Exception\DrupalNodeNotExistsException;
use Wissensnetz\User\DrupalUser;

class PostService {

  public function getLatestNewsByUser(DrupalUser $drupalUser): ?DrupalNode {

    $ogs = $drupalUser->getOgNids();

    if(empty($ogs)){
      return NULL;
    }

    $query = "SELECT DISTINCT(node.nid) AS nid, node.nid
    FROM {node} node
    INNER JOIN {og_membership} og_membership
    ON node.nid = og_membership.etid
    INNER JOIN {field_data_field_publishing_options} fpo ON node.nid = fpo.entity_id
    WHERE (node.type in ('post'))
    AND fpo.field_publishing_options_value != 'draft'
    AND (node.status = 1)
    AND (og_membership.gid in ( :og ) )
    ORDER BY node.created DESC
    ";

    $result = db_query($query, [":og" => $ogs])->fetchAllKeyed();
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
