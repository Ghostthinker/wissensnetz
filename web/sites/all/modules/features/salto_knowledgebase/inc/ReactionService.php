<?php

class ReactionService {

  const THUMB_UP = '👍';
  const CLAPPING = '👏';
  const SUPPORT = '🙌';
  const WONDERFUL = '💛';
  const INSPIRING = '💡';
  const THOUGHTFUL = '🤔';

  /**
   * @param $reactiontag
   * @param $entity_id
   * @param string $entity_type
   * @param null $uid
   */
  function saveReaction($reactiontag, $entity_id, $entity_type = "node", $uid = null) {

    $user_criteria = $this->getUserIdentifier($uid);

    $criteria = [
        'entity_type' => $entity_type,
        'entity_id' => $entity_id,
        'value_type' => "int",
        'tag' => $reactiontag,
      ] + $user_criteria;

    $user_vote = votingapi_select_votes($criteria);

    // check if user did already vote
    if (count($user_vote) > 0) {
      // remove vote
      votingapi_delete_votes($user_vote);
      $response = $this->getReactionsCount($entity_id);
      module_invoke_all('reaction_remove', $criteria);
    } else {
      //save (additional) reaction
      $vote_data = $criteria + array('value' => 1);
      votingapi_set_votes($vote_data, []);

      $response = $this->getReactionsCount($entity_id);
      module_invoke_all('reaction_add', $criteria);
    }



    // recalculate before getting new values
    votingapi_recalculate_results($entity_type, $entity_id);

    return $response;
  }

  /**
   * @param $entity_id
   * @param string $entity_type
   *
   * @return mixed
   */
  function getReactionsCount($entity_id, $entity_type = 'node') {
    $query = db_select('votingapi_vote', 'v')
      ->fields('v', array('tag'))
      ->condition('v.entity_id', $entity_id)
      ->groupBy('v.tag');

    $query->addExpression('COUNT(v.tag)', 'count');

    return $query->execute()->fetchAll();
  }

  /**
   * @param $entity_id
   * @param string $entity_type
   * @param null $uid
   */
  function getReactionsByEntityAndUser($entity_id, $entity_type = "node", $uid = null) {
    $user_criteria = $this->getUserIdentifier($uid);

    $criteria = [
        'entity_type' => $entity_type,
        'entity_id' => $entity_id,
      ] + $user_criteria;

    $user_votes = votingapi_select_votes($criteria);

    return $user_votes;
  }

  /**
   * @param $entity_id
   * @param string $entity_type
   *
   * @return mixed
   */
  function getReactionsByEntity($entity_id, $entity_type = "node") {
    $criteria = [
      'entity_type' => $entity_type,
      'entity_id' => $entity_id,
    ];

    $users_votes = votingapi_select_votes($criteria);

    return $users_votes;

  }

  /**
   * @param $uid
   *
   * @return array
   */
  private function getUserIdentifier($uid) {
    return $uid ? ['uid' => $uid] : votingapi_current_user_identifier();
  }

  public static function getUnicodeForEmoji($emojiTag){

    switch ($emojiTag){
      case 'like':
        return self::THUMB_UP;
      case 'clapping':
        return self::CLAPPING;
      case 'support':
        return self::SUPPORT;
      case 'wonderful':
        return self::WONDERFUL;
      case 'inspiring':
        return self::INSPIRING;
      case 'thoughtful':
        return self::THOUGHTFUL;
    }

    return '';

  }

}
