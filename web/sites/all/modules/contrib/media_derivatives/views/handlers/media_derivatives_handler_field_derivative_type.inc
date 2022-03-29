<?php

/**
 * @file
 * A handler to provide output of type column.
 */
class media_derivatives_handler_field_derivative_type extends views_handler_field {

  function render($values) {
    $value = $this->get_value($values);
    return $value == MEDIA_DERIVATIVE_FILE_TYPE_MANAGED ? t('Managed file') : t('Unmanaged file');
  }

}
