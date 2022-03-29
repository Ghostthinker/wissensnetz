<?php

/**
 * @file
 * User Stats is user online sort handler.
 */

/**
 * Is user online filter handler.
 */
class salto_user_handler_filter_is_online extends views_handler_filter_boolean_operator {

  function query() {
    $this->ensure_my_table();
    $join = new views_join;
    $join->construct('sessions', $this->table_alias, 'uid', 'uid', []);
    $session = $this->query->ensure_table('sessions', NULL, $join);

    // We have to make sure this field is in the query, and Views knows to
    // create GROUP BY's.
    $sql_if_part = "IF((" . REQUEST_TIME . " - $session.timestamp) < " . variable_get('user_block_seconds_online', 900) . ", 1, 0)";
    $sql = $sql_if_part . " = :value";

    $this->query->add_where_expression($this->options['group'], $sql, [':value' => $this->value]);
  }

  /**
   * Override default True/False options.
   */
  function get_value_options() {
    $this->value_options = [
      1 => t('Online'),
      0 => t('Offline'),
    ];
  }

}
