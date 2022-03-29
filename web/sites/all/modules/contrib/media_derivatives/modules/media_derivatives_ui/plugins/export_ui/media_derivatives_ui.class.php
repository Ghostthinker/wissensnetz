<?php

/**
 * @file
 *   Media derivatives UI preset management interface handler.
 */


class media_derivatives_ui extends ctools_export_ui {
  /**
   * Overriden add_page() form.
   */
  function add_page($js, $input, $step = NULL) {
    $data = parent::add_page($js, $input, $step);
    dpm($data);
    return $data;
  }
}
