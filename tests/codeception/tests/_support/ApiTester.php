<?php


/**
 * Inherited Methods
 * @method void wantToTest($text)
 * @method void wantTo($text)
 * @method void execute($callable)
 * @method void expectTo($prediction)
 * @method void expect($prediction)
 * @method void amGoingTo($argumentation)
 * @method void am($role)
 * @method void lookForwardTo($achieveValue)
 * @method void comment($description)
 * @method \Codeception\Lib\Friend haveFriend($name, $actorClass = NULL)
 *
 * @SuppressWarnings(PHPMD)
*/
class ApiTester extends \Codeception\Actor
{
    use _generated\ApiTesterActions;

  /**
   * Define custom actions here
   */

  /**
   * @param $license
   * @param $ogNid
   */
  public function makeMigrationRequest($license, $ogNid) {

    $license_data_client = [
      "license_number_dosb" => $license->license_number_dosb,
      "organisation_id" => $ogNid,
    ];

    $this->sendPOST('/migration_request', $license_data_client);
    $response = $this->getResponseArray();
    $this->assertEquals(t("Your request has been submitted."), $response['migration_status']);
  }
}
