<?php

/**
 * @file
 * is user online sort handler.
 */

/**
 * Is user online sort handler.
 */
class salto_user_handler_sort_is_online extends views_handler_sort {

  function query() {
    $this->ensure_my_table();
    // Currently Views has no support for/information on the {sessions} table.
    $join = new views_join;
    $join->construct('sessions', $this->table_alias, 'uid', 'uid', []);
    $session = $this->query->ensure_table('sessions', NULL, $join);

    // We use an IF for MySQL/PostgreSQL compatibility. Otherwise PostgreSQL
    // would return 'f' and 't'.
    $sql_if_part = "IF((" . REQUEST_TIME . " - $session.timestamp) < " . variable_get('salto_user_online_seconds', 300) . ", 1, 0)";
    $this->query->add_orderby(NULL, $sql_if_part, $this->options['order'], $this->table_alias . '_' . $this->field, ['function' => 'max']);
  }

}
