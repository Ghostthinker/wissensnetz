<?php


class IPv6ValidationCest {

  public function _before(UnitTester $I) {  }

  public function _after(UnitTester $I) {  }

  /**
   * @example { "ip": "2a02:8106:205:9e00:5160:a544:3026:9543", "valid": true}
   * @example { "ip": "2a02:908:e36:a8c0:6e97:84ab:bbb9:54e4", "valid": true}
   * @example { "ip": "2a02:908:e38:1820:225c:b39b:88c2:a9a9", "valid": true}
   * @example { "ip": "1a02:908:e36:a8c0:6e97:84ab:bbb9:54e4", "valid": false}
   * @example { "ip": "2a02:908:e37:a8c0:6e97:84ab:bbb9:54e4", "valid": true}
   * @example { "ip": "2a02:908:e40:a8c0:6e97:84ab:bbb9:54e4", "valid": false}
   * @example { "ip": "192.168.178.10", "valid": null}
   */
  public function testValidationIPv6(UnitTester $I, \Codeception\Example $example) {

    variable_set('wn_security_admin_ip_whitelist', [
      '2a02:8106:205:9e00:5160:a544:3026:9543',
      '2a02:908:e36:a8c0:6e97:84ab:bbb9:54e4',
      '2a02:908:e36::/44',
    ]);

    $isValid = $example["valid"];

    $result = salto_user_check_whitelist_ipv6($example["ip"]);

    $I->assertEquals($isValid, $result);
  }

}
