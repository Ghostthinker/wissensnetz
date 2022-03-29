<?php

/**
 * @file
 * Postal code validation functions for South Korea.
 */

/**
 * Implements _postal_code_validation_validate_COUNTRYCODE().
 */
function _postal_code_validation_validate_KR($postal_code) {
  $return = array('country' => 'KR');
  if (preg_match('/^[0-9]{5}$/', $postal_code)) {
    $return['postal_code'] = $postal_code;
  }
  else {
    $return['error'] = t('Invalid postal code. Postal codes in South Korea are like "99999".');
  }
  return $return;
}
