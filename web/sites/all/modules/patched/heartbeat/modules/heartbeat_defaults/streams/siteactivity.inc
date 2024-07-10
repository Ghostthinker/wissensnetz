<?php

/**
 * @file
 *   Public heartbeat activity access object
 */


/**
 * Class PublicHeartbeat
 * Concrete class to prepare messages for all
 * users in the site of whom the heartbeat is
 * set to public
 *
 */
class SiteActivity extends HeartbeatStream {

  /**
   * Implementation of queryAlter().
   */
  protected function queryAlter() {

    //get active user's themenfelder and preprocess for query IN condition

    $users_themenfelder = salto_user_get_themenfelder($this->getViewed());

    $users_themenfelder_tids = array();
    foreach($users_themenfelder as $ti) {
      $users_themenfelder_tids[] = $ti->tid;
    }

    if($this->config->beforeTimestamp){
      $this->query->condition('ha.timestamp', $this->config->beforeTimestamp, '<=' );
    }

    if($this->config->limit){
      $this->query->limit($this->config->limit);
    }

    //root logic not changed
    $this->query->condition('ha.access', 0, '>=');

    //outer join - taxonomy themenfeld data of the posts
    $this->query->leftJoin('field_data_field_kb_content_category', 'fd', 'fd.entity_id = ha.nid AND fd.deleted = 0');
    $this->query->isNotNull('fd.field_kb_content_category_tid');
    //outer join - node data
    $this->query->leftJoin('node', 'n', 'n.nid = ha.nid');
    $this->query->condition('n.status', 1);
    //outer join - og data
    $this->query->leftJoin('og_membership', 'ogm', 'ogm.etid = ha.nid');



    //Acticity is
    //1. Group post
    //2. Knwoledgabase Post which matches the users interests
    //3. node type != post => show all remaining activities (e.g. weiterbildungsmassnahme, account,...)
    $og_and_node_type_or_condition = db_or();
    $og_membership_and_condition = db_and();
    //1.
    $og_membership_and_condition->condition('ogm.entity_type', 'node');
    $og_membership_and_condition->isNotNull("ogm.id"); //group  post

    $og_and_node_type_or_condition->condition($og_membership_and_condition);


    if(!empty($users_themenfelder_tids)) {
      //get posts taxonomy and it's parents depth 4
      //see: /admin/structure/views/view/knowledgebase_content_by_category/edit/panel_all
      $taxonomy_subquery = db_select('taxonomy_index', 'tn');
      $taxonomy_subquery->addField('tn', 'nid');
      $taxonomy_subquery->leftJoin('taxonomy_term_hierarchy', 'th', 'th.tid = tn.tid');
      $taxonomy_subquery->leftJoin('taxonomy_term_hierarchy', 'th1', 'th1.tid = th.parent');
      $taxonomy_subquery->leftJoin('taxonomy_term_hierarchy', 'th2', 'th2.tid = th1.parent');
      $taxonomy_subquery->leftJoin('taxonomy_term_hierarchy', 'th3', 'th3.tid = th2.parent');
      $taxonomy_subquery->leftJoin('taxonomy_term_hierarchy', 'th4', 'th4.tid = th3.parent');


      //conditions
      //tid is set and one of depth 4 parents matches
      $taxonomy_and_condition = db_and();

      $taxonomy_sq_or_condition = db_or();
      $taxonomy_sq_or_condition->condition('tn.tid', $users_themenfelder_tids, "IN");
      $taxonomy_sq_or_condition->condition('th1.tid', $users_themenfelder_tids, "IN");
      $taxonomy_sq_or_condition->condition('th2.tid', $users_themenfelder_tids, "IN");
      $taxonomy_sq_or_condition->condition('th3.tid', $users_themenfelder_tids, "IN");
      $taxonomy_sq_or_condition->condition('th4.tid', $users_themenfelder_tids, "IN");

      $taxonomy_and_condition->condition($taxonomy_sq_or_condition);
      $taxonomy_subquery->condition($taxonomy_and_condition);

      //2.
      $og_and_node_type_or_condition->condition('n.nid', $taxonomy_subquery, 'IN'); //has taxonomy term user is interested in

    }

    //3.
    $og_and_node_type_or_condition->condition('n.type', 'post', '<>');

    $this->query->condition($og_and_node_type_or_condition);

  }

  /**
   * Function to add a part of a sql to a query built by views.
   * @param object $view
   *   The view handler object by reference to add our part to the query
   */
  public function viewsQueryAlter(&$view) {
    $view->query->condition('ha.access', 0, '>=');
  }
}
