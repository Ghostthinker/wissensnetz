<?php

/**
 * @file
 * Simple filter to handle derivative types.
 */
class media_derivatives_handler_filter_derivative_type extends views_handler_filter {

  function option_definition() {
    $options = parent::option_definition();

    $options['value']['default'] = MEDIA_DERIVATIVE_FILE_TYPE_MANAGED;

    return $options;
  }

  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Derivative type'),
      '#options' => array(
        MEDIA_DERIVATIVE_FILE_TYPE_MANAGED => t('Managed file'),
        MEDIA_DERIVATIVE_FILE_TYPE_UNMANAGED => t('Unmanaged file'),
      ),
      '#default_value' => $this->value,
    );
  }

  function admin_summary() {
    return $this->value == MEDIA_DERIVATIVE_FILE_TYPE_MANAGED ? t('Managed file') : t('Unmanaged file');
  }

  function query() {
    $this->ensure_my_table();
    $field = "$this->table_alias.$this->real_field";

    $this->query->add_where($this->options['group'], $field, $this->value, '=');
  }
}