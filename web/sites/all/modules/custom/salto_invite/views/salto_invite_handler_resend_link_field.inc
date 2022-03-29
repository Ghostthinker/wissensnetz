<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying links to entities
 * as fields.
 */
class salto_invite_handler_resend_link_field extends views_handler_field {

  function construct() {
    parent::construct();

    $this->additional_fields['salto_invite_id'] = 'salto_invite_id';
    $this->additional_fields['type'] = 'type';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = ['default' => '', 'translatable' => TRUE];
    $options['css_primary_button'] = [
      'default' => FALSE,
      'translatable' => FALSE,
    ];

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['text'] = [
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    ];

    $form['css_primary_button'] = [
      '#type' => 'checkbox',
      '#title' => t('Render as primary button'),
      '#description' => t('Add primary button classes to a tag (link)'),
      '#default_value' => $this->options['css_primary_button'],
      '#weight' => -10,
    ];
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');

    $salto_invite_id = $values->salto_invite_id;
    $used = $values->salto_invite_used;

    if ($used) {
      return '';
    }

    $crsf_token = drupal_get_token('invite');

    $options = [
      'attributes' => [],
      'query' => [
        'token' => $crsf_token,
        drupal_get_destination(),
      ],
    ];

    if ($this->options['css_primary_button']) {
      $options['attributes'] += ['class' => 'btn btn-primary'];
    }

    $result = l($text, 'salto_invite/' . $salto_invite_id . '/resend', $options);
    $result .= l("X", 'salto_invite/' . $salto_invite_id . '/delete', $options);

    return $result;
  }

}
