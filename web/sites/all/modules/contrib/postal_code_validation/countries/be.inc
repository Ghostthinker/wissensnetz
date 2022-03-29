<?php

/**
 * @file
 * Postal code validation functions for Belgium.
 */

/**
 * Implements _postal_code_validation_validate_COUNTRYCODE().
 */
function _postal_code_validation_validate_BE($postal_code) {
  $return = array('country' => 'BE');
  if (preg_match('/^[1-9][0-9]{3}$/', $postal_code)) {
    $return['postal_code'] = $postal_code;

    $postal_code = (int) $postal_code;
    foreach (array(
      1299 => 'BRU',
      1499 => 'BBW',
      1999 => 'VBB',
      2999 => 'ANT',
      3499 => 'VBB',
      3999 => 'LIM',
      4999 => 'LIE',
      5999 => 'NAM',
      6599 => 'HAI',
      6999 => 'LUX',
      7999 => 'HAI',
      8999 => 'WVL',
      9999 => 'OVL',
    ) as $this_code => $province) {
      if ($postal_code <= $this_code) {
        $return['province'] = $province;
        break;
      }
    }
  }
  else {
    $return['error'] = t('Invalid postal code. Postal codes in Belgium are like "9999" and never start with zero.');
  }
  return $return;
}
