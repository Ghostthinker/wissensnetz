<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */


class salto_invite_handler_edit_link_field extends salto_invite_handler_link_field {

  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }

  function render($values) {
    $type = $values->{$this->aliases['type']};

    //Creating a dummy salto_invite to check access against
    $dummy_salto_invite = (object) ['type' => $type];
    if (!salto_invite_access('edit', $dummy_salto_invite)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $salto_invite_id = $values->{$this->aliases['salto_invite_id']};

    return l($text, 'admin/content/salto_invites/salto_invite/' . $salto_invite_id . '/edit');
  }

}
