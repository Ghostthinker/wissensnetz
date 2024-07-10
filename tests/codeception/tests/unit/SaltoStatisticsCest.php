<?php

class SaltoStatisticsCest {

  public function _before(UnitTester $I) {

  }

  public function _after(UnitTester $I) {

  }

  /**
   * @param \UnitTester $I
   * @return void
   */
  public function testCountStatisticPosts(UnitTester $I) {

    $I->wantTo('check that the statistic counts the post correctly');


    $user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'statistic',
    ]);

    $statiticOld = salto_statistics_create_daily_statistics_node();

    $oldPosts = $statiticOld->field_beitraege->value();

    $I->havePost([]);
    $I->haveOnlineMeeting([]);

    $statiticNew = salto_statistics_create_daily_statistics_node();

    $newposts = $statiticNew->field_beitraege->value();

    $I->assertEquals($oldPosts+1, $newposts);
  }

  /**
   * @param \UnitTester $I
   * @return void
   */
  public function testCountActiveUsers(UnitTester $I) {

    $I->wantTo('check that the statistic counts the users correctly');


    $user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'statistic',
    ]);

    $user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'statistic',
    ]);

    $userSoonInactive = $I->haveUser([
      'firstname' => 'will',
      'lastname' => 'be disabled',
    ]);


    $statiticOld = salto_statistics_create_daily_statistics_node();

    $oldUsers = $statiticOld->field_registrated_users->value();

    salto_user_deactivate_action($userSoonInactive);

    $statiticNew = salto_statistics_create_daily_statistics_node();

    $newUsers = $statiticNew->field_registrated_users->value();

    $I->assertEquals($oldUsers-1, $newUsers);
  }

}
