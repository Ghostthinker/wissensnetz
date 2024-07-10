<?php

use salto_core\service\DailyDigestService;
use Wissensnetz\User\DrupalUser;

class DailyDigestUnitCest {

  public function _before(UnitTester $I) {

  }

  public function _after(UnitTester $I) {

  }

  /**
   * @param \UnitTester $I
   * @return void
   */
  public function testLatestPosts(UnitTester $I) {

    $I->wantTo('get the latest post for a user');

    $user_member = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'member',
    ]);

    $user_author = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'author',
    ]);

    $GROUP = $I->createGroup($user_author);
    $I->addMemberToGroup($user_member, $GROUP->nid);
    $drupalUser = DrupalUser::make($user_member->uid);

    $dailyDigestService = new DailyDigestService($drupalUser);

    $I->expect('no results for posts without group context');

    $GROUP_POST_NO_GROUP = $I->havePost([
      'Titel' => 'outside of a group',
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
      'publishing' => POST_PUBLISH_IMMEDIATE,
      'created' => time() - 10000
    ]);

    $res = $dailyDigestService->getLatestActivitiesByUser();
    $I->assertEmpty($res['news']);

    $I->expect('to get the latest post');

    $GROUP_POST = $I->havePost([
      'Titel' => 'post in group ',
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
      'publishing' => POST_PUBLISH_IMMEDIATE,
      'group' => $GROUP->nid,
      'created' => time() - 9000
    ]);

    $GROUP_POST_LATEST = $I->havePost([
      'Titel' => 'group_post_immediate more latest then the other one',
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
      'publishing' => POST_PUBLISH_IMMEDIATE,
      'group' => $GROUP->nid,
      'created' => time() - 8000
    ]);


    $res = $dailyDigestService->getLatestActivitiesByUser();
    $I->assertEquals($GROUP_POST_LATEST->title, $res['news']['title']);

    $I->expect('that posts i have no access will not appear ');

    $GROUP_POST_NO_ACCESS = $I->havePost([
      'Titel' => 'group no access',
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
      'publishing' => POST_PUBLISH_IMMEDIATE,
      'group' => $GROUP->nid,
      'created' => time() - 7000
    ]);

    $res = $dailyDigestService->getLatestActivitiesByUser();
    $I->assertEquals($GROUP_POST_LATEST->title, $res['news']['title']);

    $I->expect('that posts in draft status will not appear ');

    $POST_DRAFT = $I->havePost([
      'Titel' => 'post_draft',
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'category' => SALTO_KNOWLEDGEBASE_KB_DIGITAL_TID,
      'user' => $user_author,
      'publishing' => POST_PUBLISH_DRAFT,
      'group' => $GROUP->nid,
      'created' => time() - 6000
    ]);

    $res = $dailyDigestService->getLatestActivitiesByUser();
    $I->assertEquals($GROUP_POST_LATEST->title, $res['news']['title']);

  }

  /**
   * @param \UnitTester $I
   * @return void
   */
  public function testLatestOnlineTreffen(UnitTester $I) {

    $I->wantTo('get the latest post for a user');

    $user_member = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'member',
    ]);

    $user_author = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'author',
    ]);

    $GROUP = $I->createGroup($user_author);
    $I->addMemberToGroup($user_member, $GROUP->nid);
    $drupalUser = DrupalUser::make($user_member->uid);

    $dailyDigestService = new DailyDigestService($drupalUser);

    $I->expect('no results for past online treffen');

    $ONLINE_TREFFEN_PAST = $I->haveOnlineMeeting([
      'user' => $user_author,
      'title' => 'Online treffen past',
      'group' => $GROUP,
      'startDate' => strtotime('now - 3 hours'),
      'endDate' => strtotime('now + 2 hours'),
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
    ]);

    $res = $dailyDigestService->getLatestActivitiesByUser();
    $I->assertEmpty($res['dialog']);

    $I->expect('to get the latest online treffen');

    $ONLINE_TREFFEN = $I->haveOnlineMeeting([
      'user' => $user_author,
      'title' => 'online treffen',
      'group' => $GROUP,
      'startDate' => strtotime('now + 13 hours'),
      'endDate' => strtotime('now + 22 hours'),
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
    ]);

    $ONLINE_TREFFEN_NEXT = $I->haveOnlineMeeting([
      'user' => $user_author,
      'title' => 'Online treffen next',
      'group' => $GROUP,
      'startDate' => strtotime('now + 12 hours'),
      'endDate' => strtotime('now + 22 hours'),
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
    ]);

    $res = $dailyDigestService->getLatestActivitiesByUser();
    $I->assertEquals($ONLINE_TREFFEN_NEXT->title, $res['dialog']['title']);

    $I->expect('that posts i have no access will not appear ');

    $ONLINE_TREFFEN_NO_ACCESS = $I->haveOnlineMeeting([
      'user' => $user_author,
      'title' => 'Online treffen no access',
      'group' => $GROUP,
      'startDate' => strtotime('now + 10 hours'),
      'endDate' => strtotime('now + 22 hours'),
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
    ]);

    $res = $dailyDigestService->getLatestActivitiesByUser();
    $I->assertEquals($ONLINE_TREFFEN_NEXT->title, $res['dialog']['title']);

  }

}
