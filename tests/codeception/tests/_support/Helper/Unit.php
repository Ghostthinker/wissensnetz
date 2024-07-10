<?php
namespace Helper;

// here you can define custom actions
// all public methods declared in helper class will be available in $I

class Unit extends \Codeception\Module {

  public function getOgWithLicenseExtensions($from) {
    return dosb_license_get_organisations_with_licenses_marked_for_extension($from);
  }

  public function getLicensesMarkedExtensions($og_nid, $from) {
    $marked_licenses_ids =  dosb_license_get_licenses_marked_for_extension($og_nid, $from);
    $marked_licenses = dosb_license_load_multiple($marked_licenses_ids);

    return $marked_licenses;
  }

  public function getSendReminder($time) {
    return dosb_license_send_reminder($time);
  }

  public function getDelVarBeforeSendReminder($time) {
    variable_del('cron_last_dosb_license_marked_for_extension_notification');
    return dosb_license_send_reminder($time);
  }

  public function getEdubreakMigrationOptions(){
    $config =  $this->getModule('\Helper\Unit')->config;

    return [
      'url' => $config['base_uri'],
      'credentials' => [
        'mail' => $config['mail'],
        'password' => $config['password'],
      ]
    ];

  }

}
