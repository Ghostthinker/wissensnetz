<?php

/**
 * @file
 * Postal code validation functions for Slovakia.
 */

/**
 * Implements _postal_code_validation_validate_COUNTRYCODE().
 */
function _postal_code_validation_validate_SK($postal_code) {
  $return = array('country' => 'SK');
  if (preg_match('/^([089]\d\d)[\s-]?(\d\d)$/', $postal_code, $matches)) {
    $return['postal_code'] = $matches[1] . ' ' . $matches[2];
  }
  else {
    $return['error'] = t('Invalid postal code. Postal codes in Slovakia are like "899 99" and must start with 0, 8 or 9.');
  }
  return $return;
}
