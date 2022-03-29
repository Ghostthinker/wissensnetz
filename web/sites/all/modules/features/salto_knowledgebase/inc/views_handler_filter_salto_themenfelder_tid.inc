<?php
/**
 * Created by PhpStorm.
 * User: Sergej
 * Date: 05.04.2017
 * Time: 17:42
 */

/**
 * Filter by term id.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_salto_themenfelder_tid extends views_handler_filter_in_operator {

  function value_form(&$form, &$form_state) {

    $themenfelder = salto_knowledgebase_get_themenfelder();
    $themenfelder_tids = [];
    foreach ($themenfelder as $themenfeld) {
      $themenfelder_tids[$themenfeld->tid] = $themenfeld->name;
    }

    $options = $themenfelder_tids;


    $form['value'] = [
      '#type' => 'select',
      '#title' => t("Themenfelder"),
      '#multiple' => TRUE,
      '#options' => $options,
      '#size' => min(9, count($options)),
    ];


  }

  function value_submit($form, &$form_state) {
    $form_state['values']['options']['value'] = $form['value']['#value'];
  }

  /**
   * Render our chunk of the exposed filter form when selecting
   * You can override this if it doesn't do what you expect.
   */
  function exposed_form(&$form, &$form_state) {
    if (empty($this->options['exposed'])) {
      return;
    }

    // Build the exposed form, when its based on an operator.
    if (!empty($this->options['expose']['use_operator']) && !empty($this->options['expose']['operator_id'])) {
      $operator = $this->options['expose']['operator_id'];
      $this->operator_form($form, $form_state);
      $form[$operator] = $form['operator'];
      $form[$operator]['#title'] = $this->options['expose']['operator_label'];
      $form[$operator]['#title_display'] = 'invisible';

      $this->exposed_translate($form[$operator], 'operator');

      unset($form['operator']);
    }

    // Build the form and set the value based on the identifier.
    if (!empty($this->options['expose']['identifier'])) {
      $value = $this->options['expose']['identifier'];
      $this->value_form($form, $form_state);
      $form[$value] = $form['value'];

      if (isset($form[$value]['#title']) && !empty($form[$value]['#type']) && $form[$value]['#type'] != 'checkbox') {
        unset($form[$value]['#title']);
      }

      $this->exposed_translate($form[$value], 'value');

      if (!empty($form['#type']) && ($form['#type'] == 'checkboxes' || ($form['#type'] == 'select' && !empty($form['#multiple'])))) {
        unset($form[$value]['#default_value']);
      }

      if (!empty($form['#type']) && $form['#type'] == 'select' && empty($form['#multiple'])) {
        $form[$value]['#default_value'] = 'All';
      }

      $form[$value]['#default_value'] = -1;

      reset($form[$value]["#options"]);
      $option_all_key = key($form[$value]["#options"]);
      $option_all = [$option_all_key => $form[$value]["#options"][$option_all_key]];
      unset($form[$value]["#options"][$option_all_key]);

      $option_mine = [-1 => t("- Mine -")];

      $form[$value]["#options"] = $option_mine + $form[$value]["#options"] + $option_all;

      if ($value != 'value') {
        unset($form['value']);
      }


    }
  }

  function query() {

    $value = $this->value;

    if ($this->value[0] == -1 || empty($this->value)) {
      $users_themenfelder = salto_user_get_themenfelder();
      $users_themenfelder_tids = [];
      foreach ($users_themenfelder as $ti) {
        $users_themenfelder_tids[] = $ti->tid;
      }
      $value = $users_themenfelder_tids;
    }

    $this->ensure_my_table();
    $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field", $value, "IN");

  }

  function validate() {
    return TRUE;
  }

}

