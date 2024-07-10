<?php


use salto_core\migration\MigrationService;

class SaltoEdubreakAPICest {

  public function _before(UnitTester $I) {
  }

  public function _after(UnitTester $I) {
  }


  public function test_migration_service(UnitTester $I, $scenario) {
    #drush bb
    #zum wiederherstellen der db drush bam-restore db manual Wissensnetz-2023-02-20T16-40-02.mysql.gz
    $options = $I->getEdubreakMigrationOptions();

    if (empty($options['url'])){
      $scenario->skip("skip test, when no config is available");
    }

    $GROUP_MEMBER1 = $I->haveUser([
      'firstname' => 'Founder',
      'lastname' => 'tester',
      'mail' => 'jane.author@example.de'
    ]);

    $I->actAsUser($GROUP_MEMBER1);


    $migrationService = new MigrationService($options);
    print_r($migrationService->migrate(213, FALSE));

  }

}
