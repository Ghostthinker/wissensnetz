<?php

/**
 * This field handler aggregates operations that can be done on a salto_invite
 * under a single field providing a more flexible way to present them in a view
 */
class salto_invite_handler_salto_invite_operations_field extends views_handler_field {

  function construct() {
    parent::construct();

    $this->additional_fields['salto_invite_id'] = 'salto_invite_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('salto_invite', 'admin/content/salto_invites/salto_invite', [$this->get_value($values, 'salto_invite_id')]);

    if (!empty($links)) {
      return theme('links', [
        'links' => $links,
        'attributes' => ['class' => ['links', 'inline', 'operations']],
      ]);
    }
  }

}
