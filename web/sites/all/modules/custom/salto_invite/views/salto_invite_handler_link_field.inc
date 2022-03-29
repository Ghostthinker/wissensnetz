<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying links to entities
 * as fields.
 */

class salto_invite_handler_link_field extends views_handler_field {

  function construct() {
    parent::construct();

    $this->additional_fields['salto_invite_id'] = 'salto_invite_id';
    $this->additional_fields['type'] = 'type';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = ['default' => '', 'translatable' => TRUE];

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = [
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    ];
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $salto_invite_id = $values->{$this->aliases['salto_invite_id']};

    return l($text, 'salto_invite/' . $salto_invite_id);
  }

}
