<?php

/**
 * @file
 * Postal code validation functions for Czech Republic.
 */

/**
 * Implements _postal_code_validation_validate_COUNTRYCODE().
 */
function _postal_code_validation_validate_CZ($postal_code) {
  $return = array('country' => 'CZ');
  if (preg_match('/^([1-7]\d\d)[\s-]?(\d\d)$/', $postal_code, $matches)) {
    $return['postal_code'] = $matches[1] . ' ' . $matches[2];
  }
  else {
    $return['error'] = t('Invalid postal code. Postal codes in Czech Republic are like "199 99" and must start with a digit between 1 and 7.');
  }
  return $return;
}
