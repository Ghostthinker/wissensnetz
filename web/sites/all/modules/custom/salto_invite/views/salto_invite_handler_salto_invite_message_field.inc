<?php

/**
 * The inviet message is serealized in the data field
 */
class salto_invite_handler_salto_invite_message_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['salto_invite_id'] = 'salto_invite_id';
    $this->additional_fields['data'] = 'data';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $data = unserialize($values->salto_invite_data);
    return $data['invite'];
  }
}
