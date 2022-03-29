<?php

/**
 * @file
 * user online handler.
 */

/**
 * Is user online handler.
 */
class salto_user_handler_field_is_online extends views_handler_field_boolean {

  function query() {
    $this->ensure_my_table();
    // Currently Views has no support for/information on the {sessions} table.
    $join = new views_join;
    $join->construct('sessions', $this->table_alias, 'uid', 'uid', []);
    $session = $this->query->ensure_table('sessions', NULL, $join);

    // We use an IF for MySQL/PostgreSQL compatibility. Otherwise PostgreSQL
    // would return 'f' and 't'.
    $sql_if_part = "IF((" . REQUEST_TIME . " - $session.timestamp) < " . variable_get('salto_user_online_seconds', 300) . ", 1, 0)";

    // We liberally steal from views_handler_sort_formula and
    // views_handler_filter_search here.
    $this->field_alias = $this->query->add_field(NULL, $sql_if_part, $this->table_alias . '_' . $this->field, ['function' => 'max']);
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['type'] = ['default' => 'online-offline-icon'];

    return $options;
  }

  /**
   * Add the online-offline type to options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['type']['#options']['online-offline-text'] = t('Online/Offline text');
    $form['type']['#options']['online-offline-icon'] = t('Online/Offline icon');
  }

  function render($values) {
    $value = $values->{$this->field_alias};
    if (!empty($this->options['not'])) {
      $value = !$value;
    }
    if ($this->options['type'] == 'online-offline-text') {
      return $value ? '<span class="user-stat-online">' . t('Online') . '</span>' : '<span class="user-stat-offline">' . t('Offline') . '</span>';
    }
    elseif ($this->options['type'] == 'online-offline-icon') {
      $icon_online_url = drupal_get_path('module', 'salto_user') . '/assets/online.png';
      $icon_online = '<img width="12px" height="12px" src="' . $icon_online_url . '" alt="' . t('Online') . '" title="' . t('This user is online') . '" />';
      return $value ? '<span class="user-stat-icon user-stat-online">' . $icon_online . '</span>' : '<span class="user-stat-icon user-stat-offline"></span>';
    }
    else {
      return parent::render($values);
    }
  }

}
