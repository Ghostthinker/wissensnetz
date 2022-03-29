<?php

/**
 * @file
 * Postal code validation functions for Poland.
 */

/**
 * Implements _postal_code_validation_validate_COUNTRYCODE().
 */
function _postal_code_validation_validate_PL($postal_code) {
  $return = array('country' => 'PL');
  if (preg_match('/^([0-9]{2})(-[0-9]{3})?$/', $postal_code, $matches)) {
    $return['postal_code'] = $postal_code;
  }
  else {
    $return['error'] = t('Invalid postal code. Postal codes in Poland are like "33-170".');
  }
  return $return;
}
