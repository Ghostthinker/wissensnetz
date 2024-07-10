<?php

namespace salto_core\service;

use Wissensnetz\Comment\DrupalComment;
use Wissensnetz\Core\Node\DrupalNode;
use Wissensnetz\Core\Node\Exception\DrupalNodeNotExistsException;
use Wissensnetz\Group\GroupDrupalNode;
use Wissensnetz\User\DrupalUser;

class MentionsService {

  private function getLatestMentionsByUser(DrupalUser $drupalUser, $limit = 0) {

    $result = db_select('mentions', 'm')
      ->distinct()
      ->fields('m', array('entity_type', 'entity_id', 'created'))
      ->condition('uid', $drupalUser->getUid())
      ->orderBy('created', 'DESC')
      ->range(0, $limit)
      ->groupBy('entity_type')
      ->groupBy('entity_id')
      ->execute()->fetchAll();

    return $result;

  }

  public function getMentionsForUserportal(DrupalUser $drupalUser){

    $mentions = $this->getLatestMentionsByUser($drupalUser, 5);

    if(empty($mentions)){
      return [];
    }

    $currentMentions = [];
    foreach($mentions as $mention){
      $currentMentions[] = $this->getMentionEntry($mention);
    }
    return $currentMentions;
  }

  private function getMentionEntry($mention){
    if($mention->entity_type == 'node'){
      $drupalNode = DrupalNode::make($mention->entity_id);
      return $this->createStructure($drupalNode);
    }

    $drupalComment = DrupalComment::make($mention->entity_id);
    return $this->createStructure($drupalComment);

  }

  private function createStructure($drupalCommentOrNode){
    global $conf;

    $base = $conf['site_name'];
    $instanceLabel = 'Gemeinschaftsbereich - ' . $base;
    if($drupalCommentOrNode->inOg()){
      $groupDrupalNode = GroupDrupalNode::make($drupalCommentOrNode->getOgNid());
      $instanceLabel = $groupDrupalNode->getTitle() . ' - ' . $base;
    }

    return [
      'title' => $drupalCommentOrNode->getTitle(),
      'created' => $drupalCommentOrNode->getCreatedDateISO(),
      'url' => $drupalCommentOrNode->getUrlAbsolute(),
      'instance' => $instanceLabel
    ];
  }

}
