<?php


class PostalValidationSaltoCest {

  public function _before(UnitTester $I) {  }

  public function _after(UnitTester $I) {  }


  /**
   * @example { "postal": "CH-1234", "valid": true, "supported": true}
   * example { "postal": "CH-12345", "valid": false, "supported": true}
   * @example { "postal": "LI-9485", "valid": true, "supported": false}
   * @example { "postal": "LI-9498", "valid": true, "supported": false}
   * example { "postal": "LI-9484", "valid": false, "supported": false}
   * example { "postal": "LI-9499", "valid": false, "supported": false}
   * example { "postal": "LI-1234", "valid": false, "supported": false}
   * @example { "postal": "BE-1234", "valid": true, "supported": true}
   * @example { "postal": "DK-3801", "valid": true, "supported": true}
   * @example { "postal": "AT-1234", "valid": true, "supported": true}
   * @example { "postal": "AT-12 34", "valid": false, "supported": true}
   * example { "postal": "AT-12345", "valid": false, "supported": true}
   * @example { "postal": "AU-1234", "valid": true, "supported": true}
   * example { "postal": "AU-12345", "valid": false, "supported": true}
   * @example { "postal": "IS-123", "valid": true, "supported": false}
   * @example { "postal": "IS-12 3", "valid": false, "supported": false}
   * @example { "postal": "IS-1234", "valid": true, "supported": false}
   * @example { "postal": "333", "valid": false, "supported": true}
   * @example { "postal": "4444", "valid": false, "supported": true}
   *
   */
  public function testPostalValidationLess5(UnitTester $I, \Codeception\Example $example) {

    $postal = $example["postal"];
    $isValid = $example["valid"];
    $isSupported = $example["supported"];

    $result = salto_core_validate_postal($postal);

    $I->assertEquals($isValid, $result);
  }

  /**
   * @example { "postal": "AT-12 34", "valid": true, "supported": true}
   * @example { "postal": "RU-123 456", "valid": true, "supported": true}
   * @example { "postal": "PT-1234678", "valid": true, "supported": true}
   * @example { "postal": "JP-1234567", "valid": true, "supported": true}
   * @example { "postal": "BR-12345678", "valid": true, "supported": true}
   * @example { "postal": "SE-12345", "valid": true, "supported": true}
   * @example { "postal": "SE-12 345", "valid": true, "supported": true}
   * @example { "postal": "SK-02345", "valid": true, "supported": true}
   * @example { "postal": "SK-02 345", "valid": true, "supported": true}
   * @example { "postal": "CZ-12345", "valid": true, "supported": true}
   * @example { "postal": "CZ-12 345", "valid": true, "supported": true}
   */
  public function testPostalValidationWithModify(UnitTester $I, \Codeception\Example $example) {

    $postal = $example["postal"];
    $isValid = $example["valid"];
    $isSupported = $example["supported"];

    $result = salto_core_validate_postal($postal, FALSE);

    $I->assertEquals($isValid, $result);
  }


  /**
   * @example { "postal": "12345", "valid": true, "supported": true}
   * @example { "postal": 12345, "valid": true, "supported": true}
   * @example { "postal": "DE-12345", "valid": true, "supported": true}
   * @example { "postal": "DE-12 345", "valid": false, "supported": true}
   * @example { "postal": "DE-123-45", "valid": false, "supported": true}
   * @example { "postal": "FR-12345", "valid": true, "supported": true}
   * @example { "postal": "MC-98012", "valid": true, "supported": true}
   * //@bad (bug) that isn't real valid
   * @example { "postal": "MC-12345", "valid": true, "supported": true}
   * @example { "postal": "IT-12345", "valid": true, "supported": true}
   * example { "postal": "AT-12345", "valid": false, "supported": true}
   * //@bad
   * @example { "postal": "T-42346", "valid": true, "supported": false}
   * example { "postal": "AT-333", "valid": false, "supported": true}
   * @example { "postal": "86157", "valid": true, "supported": true}
   * @example { "postal": 86157, "valid": true, "supported": true}
   * example { "postal": "A-3", "valid": false, "supported": false}
   * @example { "postal": "ÜL-12345", "valid": false, "supported": true}
   * @example { "postal": "Tü-42346", "valid": false, "supported": false}
   * @example { "postal": "TÜ-42346", "valid": false, "supported": false}
   * @example { "postal": "ABD-95222", "valid": false, "supported": false}
   * @example { "postal": "333", "valid": false, "supported": true}
   * @example { "postal": "4444", "valid": false, "supported": true}
   *
   */
  public function testPostalValidation5(UnitTester $I, \Codeception\Example $example) {

    $postal = $example["postal"];
    $isValid = $example["valid"];
    $isSupported = $example["supported"];

    $result = salto_core_validate_postal($postal);

    $I->assertEquals($isValid, $result);
  }

  /**
   * @example { "postal": "CN-123456", "valid": true, "supported": true}
   * @example { "postal": "EC-123456", "valid": true, "supported": false}
   * example { "postal": "IN-123456", "valid": true, "supported": true}
   * @example { "postal": "KZ-123456", "valid": true, "supported": false}
   * @example { "postal": "CO-123456", "valid": true, "supported": false}
   * @example { "postal": "NG-123456", "valid": true, "supported": false}
   * @example { "postal": "PA-123456", "valid": true, "supported": false}
   * @example { "postal": "RO-123456", "valid": true, "supported": false}
   * @example { "postal": "RU-123456", "valid": true, "supported": true}
   * @example { "postal": "RU-123 456", "valid": false, "supported": true}
   * @example { "postal": "RU-123-456", "valid": false, "supported": true}
   * example { "postal": "RU-12345", "valid": false, "supported": true}
   * @example { "postal": "ABD-95222", "valid": false, "supported": false}
   */
  public function testPostalValidation6(UnitTester $I, \Codeception\Example $example) {

    $postal = $example["postal"];
    $isValid = $example["valid"];
    $isSupported = $example["supported"];

    $result = salto_core_validate_postal($postal);

    $I->assertEquals($isValid, $result);
  }

  /**
   * //@bad
   * @example { "postal": "T-42346", "valid": true, "supported": false}
   * example { "postal": "AT-333", "valid": false, "supported": true}
   * example { "postal": "A-3", "valid": false, "supported": false}
   * @example { "postal": "ÜL-12345", "valid": false, "supported": true}
   * @example { "postal": "Tü-42346", "valid": false, "supported": false}
   * @example { "postal": "TÜ-42346", "valid": false, "supported": false}
   * @example { "postal": "ABD-95222", "valid": false, "supported": false}
   * @example { "postal": "333", "valid": false, "supported": true}
   * @example { "postal": "4444", "valid": false, "supported": true}
   *
   */
  public function testPostalValidationNegatives(UnitTester $I, \Codeception\Example $example) {

    $postal = $example["postal"];
    $isValid = $example["valid"];
    $isSupported = $example["supported"];

    $result = salto_core_validate_postal($postal);

    $I->assertEquals($isValid, $result);
  }

  /**
   * @example { "postal": "AR-B1636FDA", "valid": true, "supported": true}
   * @example { "postal": "AR-123456", "valid": false, "supported": true}
   * example { "postal": "MT-VLT 1117", "valid": true, "supported": false}
   * @example { "postal": "MT-1117 VLT", "valid": false, "supported": false}
   * @example { "postal": "CA-A0A 0A0", "valid": true, "supported": true}
   * @example { "postal": "CA-123456", "valid": false, "supported": true}
   * @example { "postal": "NL-1234 AB", "valid": true, "supported": true}
   * @example { "postal": "NL-123456", "valid": false, "supported": true}
   * @example { "postal": "NL-AB 123", "valid": false, "supported": true}
   * @example { "postal": "GB-EC1A 1BB", "valid": true, "supported": true}
   * @example { "postal": "GB-W1A 0AX", "valid": true, "supported": true}
   * @example { "postal": "GB-B33 8TH", "valid": true, "supported": true}
   * @example { "postal": "GB-M1 1AE", "valid": true, "supported": true}
   * @example { "postal": "GB-CR2 6XH", "valid": true, "supported": true}
   * @example { "postal": "GB-DN55 1PT", "valid": true, "supported": true}
   * @example { "postal": "GB-123456", "valid": false, "supported": true}
   * example { "postal": "IR-A65 F4E2", "valid": true, "supported": false}
   * example { "postal": "IR-123456", "valid": false, "supported": false}
   * @example { "postal": "AD-AD501", "valid": true, "supported": true}
   * example { "postal": "AD-501", "valid": false, "supported": true}
   * example { "postal": "AT-12345", "valid": false, "supported": true}
   * GB
   * The following regular expression can be used for the purpose of validation:
   * ^([A-Za-z][A-Ha-hJ-Yj-y]?[0-9][A-Za-z0-9]? [0-9][A-Za-z]{2}|[Gg][Ii][Rr] 0[Aa]{2})$
   *  If you can accept a lack of space between the Outward and Inward codes use the following:
   * ^([A-Za-z][A-Ha-hJ-Yj-y]?[0-9][A-Za-z0-9]? ?[0-9][A-Za-z]{2}|[Gg][Ii][Rr] ?0[Aa]{2})$
   */
  public function testPostalValidationAlphanumeric(UnitTester $I, \Codeception\Example $example) {

    $postal = $example["postal"];
    $isValid = $example["valid"];
    $isSupported = $example["supported"];

    $result = salto_core_validate_postal($postal);

    $I->assertEquals($isValid, $result);
  }

  /**
   * @example { "postal": "PL-12-345", "valid": true, "supported": true}
   * example { "postal": "PL-12345", "valid": false, "supported": true}
   * @example { "postal": "PL-123-45", "valid": false, "supported": true}
   * @example { "postal": "CL-123-4567", "valid": true, "supported": true}
   * @example { "postal": "CL-1234567", "valid": false, "supported": true}
   * @example { "postal": "CL-1234-567", "valid": false, "supported": true}
   * @example { "postal": "US-12345-6789", "valid": true, "supported": true}
   * @example { "postal": "US-123456789", "valid": false, "supported": true}
   * @example { "postal": "US-123-456789", "valid": false, "supported": true}
   * @example { "postal": "US-123456-789", "valid": false, "supported": true}
   * @example { "postal": "PT-1234-678", "valid": true, "supported": true}
   * @example { "postal": "PT-1234678", "valid": false, "supported": true}
   * @example { "postal": "PT-12346-78", "valid": false, "supported": true}
   * @example { "postal": "PT-123-4678", "valid": false, "supported": true}
   * @example { "postal": "JP-123-4567", "valid": true, "supported": true}
   * @example { "postal": "JP-1234567", "valid": false, "supported": true}
   * @example { "postal": "JP-1234-567", "valid": false, "supported": true}
   * @example { "postal": "BR-12345-678", "valid": true, "supported": true}
   * @example { "postal": "BR-12345678", "valid": false, "supported": true}
   * @example { "postal": "BR-123-45678", "valid": false, "supported": true}
   */
  public function testPostalValidationHyphen(UnitTester $I, \Codeception\Example $example) {

    $postal = $example["postal"];
    $isValid = $example["valid"];
    $isSupported = $example["supported"];

    $result = salto_core_validate_postal($postal);

    $I->assertEquals($isValid, $result);
  }

  /**
   * @example { "postal": "SE-123 45", "valid": true, "supported": true}
   * example { "postal": "SE-12345", "valid": false, "supported": true}
   * @example { "postal": "SE-12 345", "valid": false, "supported": true}
   * @example { "postal": "SK-023 45", "valid": true, "supported": true}
   * example { "postal": "SK-02345", "valid": false, "supported": true}
   * @example { "postal": "SK-02 345", "valid": false, "supported": true}
   * @example { "postal": "CZ-123 45", "valid": true, "supported": true}
   * example { "postal": "CZ-12345", "valid": false, "supported": true}
   * @example { "postal": "CZ-12 345", "valid": false, "supported": true}
   */
  public function testPostalValidationSpace(UnitTester $I, \Codeception\Example $example) {

    $postal = $example["postal"];
    $isValid = $example["valid"];
    $isSupported = $example["supported"];

    $result = salto_core_validate_postal($postal);

    $I->assertEquals($isValid, $result);
  }

  /**
   * example { "postal": "NL-6294", "valid": false, "supported": true}
   * @example { "postal": "A-6923", "valid": true, "supported": true}
   * @example { "postal": "D-09116", "valid": true, "supported": true}
   * @example { "postal": "F-57350", "valid": true, "supported": true}
   */
  public function testPostalValidationHangover(UnitTester $I, \Codeception\Example $example) {

    $postal = $example["postal"];
    $isValid = $example["valid"];
    $isSupported = $example["supported"];

    $result = salto_core_validate_postal($postal);

    $I->assertEquals($isValid, $result);
  }
}
