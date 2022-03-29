<?php


class SaltoCoreHelperCest {

  public function _before(UnitTester $I) {}

  public function _after(UnitTester $I) {}

  /**
   * @param UnitTester           $I
   * @param \Codeception\Example $example
   *
   * @throws Exception
   * @example { "cipher": null, "data": "My test is safe!", "key": "random"}
   * @example { "cipher": null, "data": "My test is safe!", "key": "d93050d89eb5d63d"}
   * @example { "cipher": "bf-cbc", "data": "My test is safe!", "key": "d93050d89eb5d63d"}
   * @example { "cipher": "bf-cbc", "data": "My test is safe!", "key": "random"}
   * @example { "cipher": "bf-cbc", "data": "{ 'id': 654, 'text': 'My test is safe!' }", "key": "random"}
   * @example { "cipher": "aes-128-cbc-hmac-sha256", "data": "My test is safe!", "key": "secret"}
   * @example { "cipher": "aes-256-cbc-hmac-sha256", "data": "My test is safe!", "key": "random"}
   * @example { "cipher": "aes-256-ctr", "data": "My test is safe!", "key": "random"}
   * @example { "cipher": "aes-256-ofb", "data": "My test is safe!", "key": "random"}
   * @example { "cipher": "bf-ofb", "data": "My test is safe!", "key": "random"}
   * @example { "cipher": "aria-256-cbc", "data": "My test is safe!", "key": "random"}
   * @example { "cipher": "camellia-256-cbc", "data": "My test is safe!", "key": "random"}
   * @example { "cipher": "cast5-cbc", "data": "My test is safe!", "key": "random"}
   * @example { "cipher": "des-cbc", "data": "My test is safe!", "key": "random"}
   * @example { "cipher": "des-ede-cbc", "data": "My test is safe!", "key": "random"}
   * @example { "cipher": "des-ede3-cbc", "data": "My test is safe!", "key": "random"}
   * @example { "cipher": "sea-128-cbc-hmac-sha652", "data": "My test is safe!", "key": "secret"}
   *
   * 24.02.2021 - 13:00 - LK: gcm, ecb mode is not supported, not yet
   */
  public function test_core_encrypt_ssl(UnitTester $I, \Codeception\Example $example) {

    $data = $example['data'];
    $key = $example['key'];
    $cipher = $example['cipher'];

    if ($key == 'random' && $cipher != null) {
      $ivlen = openssl_cipher_iv_length($cipher);
      $bytes = random_bytes($ivlen);
      $key = bin2hex($bytes);
    }
    $enc = core_encrypt_openssl($data, $key, $cipher);
    $dec = core_decrypt_openssl($enc, $key, $cipher);

    $I->assertEquals($data, $dec);
  }
}
