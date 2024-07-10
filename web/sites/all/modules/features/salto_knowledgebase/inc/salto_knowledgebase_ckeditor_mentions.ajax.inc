<?php

/**
 * @file
 * Callback which request the view 'ckeditor_mentions' and inject the typed value as a realname filter.
 */

function salto_knowledgebase_ckeditor_mentions_getpeople() {
  $typed = $_REQUEST['typed'];

  if (strlen($typed) <= 12 && $typed[0] == '@') {
    $typed = substr($typed, 1);

    mentions_autocomplete($typed);
    drupal_exit();

  }
}
