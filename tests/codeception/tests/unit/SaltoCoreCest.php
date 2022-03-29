<?php


class SaltoCoreCest {

  public function _before(UnitTester $I) {
  }

  public function _after(UnitTester $I) {
  }


  /**
   * @example { "postal": "AT-1234", "valid": true}
   * @example { "postal": "12345", "valid": true}
   * @example { "postal": 12345, "valid": true}
   * @example { "postal": "86157", "valid": true}
   * @example { "postal": "ÜL-12345", "valid": false}
   * @example { "postal": "Tü-42346", "valid": false}
   * @example { "postal": "TÜ-42346", "valid": false}
   * @example { "postal": "ABD-95222", "valid": false}
   * @example { "postal": "333", "valid": false}
   * @example { "postal": "4444", "valid": false}
   * 21.11.2018 - 12:30 - LK: FALSE, now
   * 09.04.2019 - 09:30 - LK: TRUE, by active old validate
   * @example { "postal": "AT-12345", "valid": true}
   * @example { "postal": "AT-333", "valid": true}
   * @example { "postal": "A-3", "valid": true}
   * 21.01.2019 - 17:30 - LK: is correct, (new) mapping T => TR
   * @example { "postal": "T-42346", "valid": true}
   *
   */
  public function test_salto_core_validate_postal(UnitTester $I, \Codeception\Example $example) {

    $postal = $example["postal"];
    $is_valid = $example["valid"];

    $validation_result = salto_core_validate_postal($postal);

    $I->assertEquals($is_valid, $validation_result);

  }
}
