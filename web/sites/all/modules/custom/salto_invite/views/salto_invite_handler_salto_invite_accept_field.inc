<?php

/**
 * This field handler aggregates operations that can be done on a salto_invite
 * under a single field providing a more flexible way to present them in a view
 */
class salto_invite_handler_salto_invite_accept_field extends views_handler_field {

  function construct() {
    parent::construct();

    $this->additional_fields['salto_invite_id'] = 'salto_invite_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $crsf_token = drupal_get_token('invite_use');

    $link = [
      '#theme' => 'link',
      '#text' => t('Accept'),
      '#path' => 'salto_invite/' . $values->salto_invite_id . '/accept',
      '#options' => [
        'query' => ['token' => $crsf_token] + drupal_get_destination(),
        'attributes' => [
          'title' => t('Accept the invite and become member.'),
          'class' => ['btn', 'btn-primary action_link'],
        ],
        'html' => TRUE,
      ],
    ];
    $links[] = render($link);

    $link = [
      '#theme' => 'link',
      '#text' => t('Decline'),
      '#path' => 'salto_invite/' . $values->salto_invite_id . '/decline',
      '#options' => [
        'query' => ['token' => $crsf_token] + drupal_get_destination(),
        'attributes' => [
          'title' => t('Decline the invite.'),
          'class' => ['btn', 'btn-warning action_link'],
        ],
        'html' => TRUE,
      ],
    ];
    $links[] = render($link);

    if (!empty($links)) {
      return '<div class="accept_buttons">' . implode("", $links) . '</div>';
    }
  }

}
