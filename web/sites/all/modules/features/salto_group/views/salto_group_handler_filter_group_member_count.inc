<?php

/**
 * @file
 * User Stats is user online sort handler.
 */

/**
 * Is user online filter handler.
 */
class salto_group_handler_filter_group_member_count extends views_handler_filter_group_by_numeric {

  function query() {
    $this->ensure_my_table();

    //Add subquery for custom views handler to select groups by member count (1 = All)
    if ($this->value['value'] != "1") {
      if ($this->value['value'] == "5"){
        $this->query->add_where_expression($this->options['group'], "(SELECT COUNT(*) FROM og_membership ogm WHERE ogm.entity_type = 'user' AND node.nid = ogm.gid) < :value", array(':value' => $this->value['value']));
      }elseif ($this->value['value'] == "50"){
        $this->query->add_where_expression($this->options['group'], "(SELECT COUNT(*) FROM og_membership ogm WHERE ogm.entity_type = 'user' AND node.nid = ogm.gid) > :value", array(':value' => $this->value['value']));
      }else{
        $subquery = "(SELECT COUNT(*) FROM og_membership ogm WHERE ogm.entity_type = 'user' AND node.nid = ogm.gid)";
        $this->query->add_where_expression($this->options['group'], "$subquery > :min AND $subquery < :max", array(':min' => $this->value['min'], ':max' => $this->value['max']));
      }
    }
  }

}
