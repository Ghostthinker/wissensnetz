<?php
/**
 * Created by PhpStorm.
 * User: linnie
 * Date: 28.11.18
 * Time: 14:42
 */

use Helper\Wissensnetz;

/**
 * all tests for start pages
 *
 * @see aus
 *   https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.vycihaij7dv9
 */
class NotificationSettingCest {

  public function _before(UnitTester $I) {
  }

  public function _after(UnitTester $I) {
  }

  /**
   * 350_00 - Benachrichtigung - Auto Subscribers
   * @Task https://trello.com/c/E1tg9G5b/350-sie-haben-eine-neue-benachrichtigung-erhalten
   *
   * @param \UnitTester $I
   */
  public function N_00_0_test_notification_testings(UnitTester $I) {

    $I->wantTo('350_00 - Benachrichtigung - Auto Subscribers');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $GAuthor = $I->haveUser([
      'firstname' => 'Founder',
      'lastname' => $microTime,
    ]);
    $AUser = $I->haveUser([
      'firstname' => 'AUser',
      'lastname' => $microTime,
    ]);
    $OUser = $I->haveUser([
      'firstname' => 'OUser',
      'lastname' => $microTime,
    ]);
    $OUser = user_load($OUser->uid);

    Wissensnetz::setProfileCategory($OUser,
      [SALTO_KNOWLEDGEBASE_KB_FALLBACK_TID]);
    Wissensnetz::setNotificationsCommunityOff($OUser->uid);
    Wissensnetz::setNotificationsDefaults($GAuthor->uid);
    Wissensnetz::setNotificationsDefaults($AUser->uid);

    $result = onsite_notification_get_users_that_have_enabled_message_type('general');
    $result = array_reverse($result);
    $I->assertContains((int) $AUser->uid, $result, 'uid is in');
    $I->assertContains((int) $GAuthor->uid, $result, 'uid is in');
    $I->assertNotContains((int) $OUser->uid, $result, 'uid is not in');

    $result = onsite_notification_get_users_that_have_enabled_message_type('community_area');
    $result = array_reverse($result);
    $I->assertContains((int) $AUser->uid, $result, 'uid is in');
    $I->assertContains((int) $GAuthor->uid, $result, 'uid is in');
    $I->assertNotContains((int) $OUser->uid, $result, 'uid is not in');

    $result = onsite_notification_get_users_that_have_enabled_message_type('notification_post_created');
    $result = array_reverse($result);
    $I->assertContains((int) $AUser->uid, $result, 'uid is in');
    $I->assertContains((int) $GAuthor->uid, $result, 'uid is in');
    $I->assertNotContains((int) $OUser->uid, $result, 'uid is not in');
  }

  /**
   * 32.359 - Gruppe - Einladungen - Mail
   * @Task https://trello.com/c/L4mFhfbe/359-gruppe-einladungen-mail
   *
   * @param \UnitTester $I
   *
   * @throws Exception
   */
  public function N32_359_group_invite(UnitTester $I) {

    $I->wantTo('350_00 - Benachrichtigung - Group invite');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $GAuthor = $I->haveUser([
      'firstname' => 'Founder',
      'lastname' => $microTime,
    ]);
    $AUser = $I->haveUser([
      'firstname' => 'AUser',
      'lastname' => $microTime,
    ]);
    $OUser = $I->haveUser([
      'firstname' => 'OUser',
      'lastname' => $microTime,
    ]);
    $OUser = user_load($OUser->uid);

    onsite_notification_settings_update($OUser->uid,
      'notification_group_invite_recieved', ['mail' => 0], 0);
    Wissensnetz::setNotificationsDefaults($GAuthor->uid);
    Wissensnetz::setNotificationsDefaults($AUser->uid);

    $result = onsite_notification_get_users_that_have_enabled_message_type('notification_group_invite_recieved');
    $result = array_reverse($result);
    $I->assertContains((int)$AUser->uid, $result, 'uid is in');
    $I->assertContains((int)$GAuthor->uid, $result, 'uid is in');
    $I->assertNotContains((int)$OUser->uid, $result, 'uid is not in');
  }

  /**
   * 32.359 - Gruppe - Einladungen - Mail
   * @Task https://trello.com/c/L4mFhfbe/359-gruppe-einladungen-mail
   *
   * @param \UnitTester $I
   *
   * @throws Exception
   */
  public function N_01_0_subscribe_posts(UnitTester $I) {

    $I->wantTo('test that i can subscribe posts');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $UserSubscriber = $I->haveUser([
      'firstname' => 'subscriber',
      'lastname' => $microTime,
    ]);
    $UserAuthor = $I->haveUser([
      'firstname' => 'author',
      'lastname' => $microTime,
    ]);
    $UserCoAuthor = $I->haveUser([
      'firstname' => 'co author',
      'lastname' => $microTime,
    ]);
    $UserNedDabei = $I->haveUser([
      'firstname' => 'nicht dabei',
      'lastname' => $microTime,
    ]);

    $POST = $I->havePost([
      'user' => $UserAuthor,
      'authorList' => [$UserCoAuthor],
    ]);

    Wissensnetz::setNotificationsCommunityOff($UserSubscriber->uid);
    Wissensnetz::setNotificationsCommunityOff($UserAuthor->uid);
    Wissensnetz::setNotificationsCommunityOff($UserCoAuthor->uid);
    Wissensnetz::setNotificationsCommunityOff($UserNedDabei->uid);

    Wissensnetz::subscribeUserToEntity($UserSubscriber, $POST);

    $audience = _onsite_notification_node_get_subscribers($POST);

    $I->assertNotEmpty($audience[$UserSubscriber->uid]);
    $I->assertNotEmpty($audience[$UserAuthor->uid]);
    $I->assertNotEmpty($audience[$UserCoAuthor->uid]);
    $I->assertEmpty($audience[$UserNedDabei->uid]);

  }

  /**
   * 32.359 - Gruppe - Einladungen - Mail
   * @Task https://trello.com/c/L4mFhfbe/359-gruppe-einladungen-mail
   *
   * @param \UnitTester $I
   *
   * @throws Exception
   */
  public function N_01_1_subscribe_materials(UnitTester $I) {

    $I->wantTo('test that i can subscribe to materials');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $UserSubscriber = $I->haveUser([
      'firstname' => 'subscriber',
      'lastname' => $microTime,
    ]);

    $I->setProfileCategory($UserSubscriber, [THEMENFELD_GESUNDHEIT_MATERIAL]);

    $UserAuthor = $I->haveUser([
      'firstname' => 'author',
      'lastname' => $microTime,
    ]);

    $UserNedSubscriber = $I->haveUser([
      'firstname' => 'nicht dabei',
      'lastname' => $microTime,
    ]);

    $MATERIAL = $I->haveMaterial([
      'user' => $UserAuthor,
      'Kategorie' => THEMENFELD_GESUNDHEIT_MATERIAL,
    ]);

    Wissensnetz::subscribeUserToEntity($UserSubscriber, $MATERIAL);

    $audience = _onsite_notification_material_get_subscribers($MATERIAL);

    $I->assertNotEmpty($audience[$UserAuthor->uid]);
    $I->assertNotEmpty($audience[$UserSubscriber->uid]);
    $I->assertEmpty($audience[$UserNedSubscriber->uid]);

  }

  /**
   * 32.359 - Gruppe - Einladungen - Mail
   * @Task https://trello.com/c/L4mFhfbe/359-gruppe-einladungen-mail
   *
   * @param \UnitTester $I
   *
   * @throws Exception
   */
  public function N_01_2_auto_subscribe_posts(UnitTester $I) {

    $I->wantTo('test that i can auto subscribe to posts');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $UserSubscriber = $I->haveUser([
      'firstname' => 'subscriber',
      'lastname' => $microTime,
    ]);
    $UserAuthor = $I->haveUser([
      'firstname' => 'author',
      'lastname' => $microTime,
    ]);
    $UserCoAuthor = $I->haveUser([
      'firstname' => 'co author',
      'lastname' => $microTime,
    ]);
    $UserNedDabei = $I->haveUser([
      'firstname' => 'nicht dabei',
      'lastname' => $microTime,
    ]);

    $POST = $I->havePost([
      'user' => $UserAuthor,
      'authorList' => [$UserCoAuthor],
      'category' => THEMENFELD_GESUNDHEIT
    ]);

    $I->setProfileCategory($UserCoAuthor, [THEMENFELD_GESUNDHEIT]);
    $I->setProfileCategory($UserAuthor, [THEMENFELD_GESUNDHEIT]);
    $I->setProfileCategory($UserSubscriber, [THEMENFELD_GESUNDHEIT]);

    $audience = _onsite_notification_node_get_subscribers($POST);
    
    $I->assertNotEmpty($audience[$UserAuthor->uid]);
    $I->assertNotEmpty($audience[$UserSubscriber->uid]);
    $I->assertNotEmpty($audience[$UserCoAuthor->uid]);
    $I->assertEmpty($audience[$UserNedDabei->uid]);

  }

  /**
   * 32.359 - Gruppe - Einladungen - Mail
   * @Task https://trello.com/c/L4mFhfbe/359-gruppe-einladungen-mail
   *
   * @param \UnitTester $I
   *
   * @throws Exception
   */
  public function N_01_3_auto_subscribe_materials(UnitTester $I) {

    $I->wantTo('test that i can auto subscribe to materials');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $UserAuthor = $I->haveUser([
      'firstname' => 'Author',
      'lastname' => $microTime,
    ]);
    $UserSubscriber = $I->haveUser([
      'firstname' => 'subscriber',
      'lastname' => $microTime,
    ]);
    $UserFalschesThemenfeld = $I->haveUser([
      'firstname' => 'nicht dabei',
      'lastname' => $microTime,
    ]);
    $UserHatThemenfeldKeinAutoAbo = $I->haveUser([
      'firstname' => 'nicht dabei',
      'lastname' => $microTime,
    ]);

    $MATERIAL = $I->haveMaterial([
      'user' => $UserAuthor,
      'Kategorie' => THEMENFELD_GESUNDHEIT_MATERIAL
    ]);


    Wissensnetz::setProfileCategory($UserSubscriber, [THEMENFELD_GESUNDHEIT]);
    Wissensnetz::setProfileCategory($UserHatThemenfeldKeinAutoAbo, [THEMENFELD_GESUNDHEIT]);
    Wissensnetz::setNotificationsCommunityOff($UserHatThemenfeldKeinAutoAbo->uid,'file');

    $audience = _onsite_notification_material_get_subscribers($MATERIAL);

    $I->assertNotEmpty($audience[$UserAuthor->uid]);
    $I->assertNotEmpty($audience[$UserSubscriber->uid]);
    $I->assertEmpty($audience[$UserFalschesThemenfeld->uid]);
    $I->assertEmpty($audience[$UserHatThemenfeldKeinAutoAbo->uid]);

  }

  /**
   * 32.359 - Gruppe - Einladungen - Mail
   * @Task https://trello.com/c/L4mFhfbe/359-gruppe-einladungen-mail
   *
   * @param \UnitTester $I
   *
   * @throws Exception
   */
  public function N_02_1_subscribe_materials_update(UnitTester $I) {

    $I->wantTo('test that i get notifications when a subscribed material is updated');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $UserSubscriber = $I->haveUser([
      'firstname' => 'subscriber',
      'lastname' => $microTime,
    ]);

    $I->setProfileCategory($UserSubscriber, [THEMENFELD_GESUNDHEIT_MATERIAL]);

    $UserAuthor = $I->haveUser([
      'firstname' => 'author',
      'lastname' => $microTime,
    ]);

    $MATERIAL = $I->haveMaterial([
      'user' => $UserAuthor,
      'Kategorie' => THEMENFELD_GESUNDHEIT_MATERIAL,
    ]);

    Wissensnetz::subscribeUserToEntity($UserSubscriber, $MATERIAL);

    $I->completedSetup();

    $audience = _onsite_notification_material_get_subscribers($MATERIAL);

    $I->assertNotEmpty($audience[$UserAuthor->uid]);
    $I->assertNotEmpty($audience[$UserSubscriber->uid]);

    $I->expect("that there will no onsite when there is no update");

    file_save($MATERIAL);

    $I->startCoreSystemQueueForType(MESSAGE_TYPE_NOTIFICATION_MATERIAL_UPDATED,0);

    $newNotifications = Wissensnetz::getUnreadNotificationsForUser($UserSubscriber);
    $I->assertCount(0, $newNotifications);

    $I->expect("that there will be an onsite notification after an update to the file");


    $MATERIAL->field_file_image_title_text[LANGUAGE_NONE][0]['value'] = "title new";

    file_save($MATERIAL);

    $I->startCoreSystemQueueForType(MESSAGE_TYPE_NOTIFICATION_MATERIAL_UPDATED, 0);

    $newNotifications = Wissensnetz::getUnreadNotificationsForUser($UserSubscriber);
    $lastNotification = end($newNotifications);
    $I->assertCount(1, $newNotifications);
    $I->assertEquals(MESSAGE_TYPE_NOTIFICATION_MATERIAL_UPDATED, $lastNotification->type);
  }

  /**
   * 32.359 - Gruppe - Einladungen - Mail
   * @Task https://trello.com/c/L4mFhfbe/359-gruppe-einladungen-mail
   *
   * @param \UnitTester $I
   *
   * @throws Exception
   */
  public function N_02_2_subscribe_materials_comment(UnitTester $I) {

    $I->wantTo('test that i get notifications when a subscribed material is commented');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $UserSubscriber = $I->haveUser([
      'firstname' => 'subscriber',
      'lastname' => $microTime,
    ]);

    $I->setProfileCategory($UserSubscriber, [salto_knowledgebase_get_default_kb_category_tid()]);

    $UserAuthor = $I->haveUser([
      'firstname' => 'author',
      'lastname' => $microTime,
    ]);

    $MATERIAL = $I->haveMaterial([
      'user' => $UserAuthor,
      'Kategorie' => salto_knowledgebase_get_default_kb_category_tid(),
    ]);

    Wissensnetz::subscribeUserToEntity($UserSubscriber, $MATERIAL);

    $audience = _onsite_notification_material_get_subscribers($MATERIAL);

    $I->assertNotEmpty($audience[$UserAuthor->uid]);
    $I->assertNotEmpty($audience[$UserSubscriber->uid]);

    $I->expect("that there will an onsite notification when there is a new comment");

    Wissensnetz::haveComment($MATERIAL, ['user' => $UserAuthor]);

    $I->startCoreSystemQueueForType(MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT, 0);

    $newNotifications = Wissensnetz::getUnreadNotificationsForUser($UserSubscriber);
    $lastNotification = end($newNotifications);
    $I->assertCount(1, $newNotifications);
    $I->assertEquals(MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT, $lastNotification->type);
  }

  /**
   * 32.359 - Gruppe - Einladungen - Mail
   * @Task https://trello.com/c/L4mFhfbe/359-gruppe-einladungen-mail
   *
   * @param \UnitTester $I
   *
   * @throws Exception
   */
  public function N_02_3_notification_materials_create(UnitTester $I) {

    $I->wantTo('test that i get notifications material is created for my interested category');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $UserSubscriber = $I->haveUser([
      'firstname' => 'subscriber',
      'lastname' => $microTime,
    ]);

    $I->setProfileCategory($UserSubscriber, [THEMENFELD_GESUNDHEIT]);

    $UserHatThemenfeldKeinAutoAbo = $I->haveUser([
      'firstname' => 'nicht dabei',
      'lastname' => $microTime,
    ]);

    Wissensnetz::setNotificationsCommunityOff($UserHatThemenfeldKeinAutoAbo->uid, 'file');
    $I->setProfileCategory($UserHatThemenfeldKeinAutoAbo, [THEMENFELD_GESUNDHEIT]);


    Wissensnetz::setNotificationsCommunityOff($UserHatThemenfeldKeinAutoAbo->uid, 'file');
    $I->setProfileCategory($UserHatThemenfeldKeinAutoAbo, [THEMENFELD_GESUNDHEIT]);


    $UserFalschesThemenfeld = $I->haveUser([
      'firstname' => 'nicht dabei',
      'lastname' => $microTime,
    ]);


    $UserAuthor = $I->haveUser([
      'firstname' => 'author',
      'lastname' => $microTime,
    ]);

    $MATERIAL = $I->haveMaterial([
      'user' => $UserAuthor,
      'Kategorie' => THEMENFELD_GESUNDHEIT_MATERIAL,
    ]);

    $I->completedSetup();

    $I->expect("that there will an onsite notification a new material is created for the user that has matching category and auto subscribe enabled");


    $I->startCoreSystemQueueForType(MESSAGE_TYPE_NOTIFICATION_MATERIAL_CREATED, 0);

    $newNotifications = Wissensnetz::getUnreadNotificationsForUser($UserSubscriber);
    $lastNotification = end($newNotifications);
    $I->assertCount(1, $newNotifications);
    $I->assertEquals(MESSAGE_TYPE_NOTIFICATION_MATERIAL_CREATED, $lastNotification->type);

    $I->expect("that there will an onsite notification a new material is created for the user that has matching category and auto subscribe disabled");

    $newNotifications = Wissensnetz::getUnreadNotificationsForUser($UserHatThemenfeldKeinAutoAbo);
    $I->assertCount(1, $newNotifications);
    $I->assertEquals(MESSAGE_TYPE_NOTIFICATION_MATERIAL_CREATED, $lastNotification->type);

    $I->expect("that there will no onsite notification a new material is created for the user that has no matching category");

    $newNotifications = Wissensnetz::getUnreadNotificationsForUser($UserFalschesThemenfeld);
    $I->assertEmpty($newNotifications);

    $I->expect("that the author will not get a notification for his own new content");

    $newNotifications = Wissensnetz::getUnreadNotificationsForUser($UserAuthor);
    $I->assertEmpty($newNotifications);
  }



}

