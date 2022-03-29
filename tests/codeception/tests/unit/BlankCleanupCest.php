<?php

class BlankCleanupCest {

  public function _before(UnitTester $I) {  }

  public function _after(UnitTester $I) { }


  /**
   * get user ids by og and groups by users
   * @param UnitTester $I
   * @throws Exception
   */
  public function testBasic(UnitTester $I) {
    $og = $I->haveOrganisation('BlankClaenupCest-testBasic');

    $users = [];
    $userIds = [];
    for($k = 0; $k < 10; $k++) {
      $user = $I->haveUser([
            'firstname' => 'max' . $k,
            'lastname' => 'meeting_no_author' . $k,
      ]);
      $I->addMemberToOrganisation($user, $og);
      $users[] = $user;
      $userIds[$user->uid] = $user->uid;
    }

    $I->expectTo('User ids are equal, count!');
    $blank = \Helper\Bildungsnetz::getBlankCleanup();
    $ids = $blank->getUserIdsForOrganisation($og->nid);
    $I->assertEquals(count($ids), count($users));

    $I->expectTo('No Group is found by users!');
    $repo = \Helper\Bildungsnetz::getNodeRepository();
    $groups = $repo->getGroupIdsByUsers($userIds);
    $I->assertEquals(0, count($groups));

    $group1 = \Helper\Bildungsnetz::createGroup($users[0]);
    for($k = 0; $k < count($users)/2; $k++) {
      \Helper\Bildungsnetz::addMemberToGroup($users[$k], $group1->nid);
    }

    $I->expectTo('A Group is found by users!');
    $repo = \Helper\Bildungsnetz::getNodeRepository();
    $groups = $repo->getGroupIdsByUsers($userIds);
    $I->assertEquals(1, count($groups));
    $I->assertEquals($group1->nid, $groups[$group1->nid]);

    // with user ids from og
    $I->expectTo('A Group is found by user ids from og!');
    $groups = $repo->getGroupIdsByUsers($ids);
    $I->assertEquals(1, count($groups));
    $I->assertEquals($group1->nid, $groups[$group1->nid]);

    $group2 = \Helper\Bildungsnetz::createGroup($users[0]);
    for($k = count($users)/2; $k < count($users); $k++) {
      \Helper\Bildungsnetz::addMemberToGroup($users[$k], $group2->nid);
    }
    $I->expectTo('Two groups are found by users!');
    $groups = $repo->getGroupIdsByUsers($userIds);
    $I->assertEquals(2, count($groups));
    $I->assertEquals($group1->nid, $groups[$group1->nid]);
    $I->assertEquals($group2->nid, $groups[$group2->nid]);

    $I->expectTo('No Group is found by users, after delete!');
    $I->assertTrue($blank->deleteNodes($groups));
    $groups = $repo->getGroupIdsByUsers($userIds);
    $I->assertEquals(0, count($groups));

    $I->expectTo('Delete OG is ok!');
    $I->assertTrue($blank->deleteNodes([$og->nid]));

    // clean test data
    user_delete_multiple($ids);
  }

}
