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
 * @see aus https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.vycihaij7dv9
 */
class GroupsPostCest {

  /**
   * Always create this entities before every course
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {}

  public function _after(AcceptanceTester $I) {}

  /**
   * 270.05 Benachrichtigung - Einstellen eines Beitrags / Materials mit Auswahl einer Gruppe
   * @UserStory 270.05 - https://trello.com/c/WGfdfVK1/666-27005-benachrichtigung-einstellen-eines-beitrags-materials-mit-auswahl-einer-gruppe
   * @Task https://trello.com/c/dFSzN0ey/1037-27005-benachrichtigung-einstellen-eines-beitrags-materials-mit-auswahl-einer-gruppe
   *
   * @param \AcceptanceTester $I
   */
  public function GP_01_0_groups_post_notifications(AcceptanceTester $I) {

    $I->wantTo('270.05 - Benachrichtigung - Einstellen eines Beitrags / Materials mit Auswahl einer Gruppe');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $GAuthor = $I->haveUser([
      'firstname' => 'Founder',
      'lastname' => $microTime,
      //'mail' => 'jane.author@byom.de'
    ]);
    $GMember = $I->haveUser([
      'firstname' => 'GMember',
      'lastname' => $microTime,
      //'mail' => 'john.doe@byom.de'
    ]);
    $GOMember = $I->haveUser([
      'firstname' => 'GOMember',
      'lastname' => $microTime,
      //'mail' => 'billy.doe@byom.de'
    ]);
    $AUser = $I->haveUser([
      'firstname' => 'AUser',
      'lastname' => $microTime,
      //'mail' => 'john.area@byom.de'
    ]);
    $OUser = $I->haveUser([
      'firstname' => 'OUser',
      'lastname' => $microTime,
      //'mail' => 'john.outarea@byom.de'
    ]);

    Wissensnetz::setNotificationsDefaults($GAuthor->uid);
    Wissensnetz::setNotificationsDefaults($GMember->uid);
    Wissensnetz::setNotificationsDefaults($GOMember->uid);
    Wissensnetz::setNotificationsDefaults($AUser->uid);
    Wissensnetz::setNotificationsDefaults($OUser->uid);
    Wissensnetz::setProfileCategory($OUser, [Wissensnetz::KB_CATEGORY_FALLBACK]);
    Wissensnetz::setProfileCategory($GOMember, [Wissensnetz::KB_CATEGORY_FALLBACK]);
    Wissensnetz::setProfileCategory($GAuthor, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);
    Wissensnetz::setProfileCategory($GMember, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);
    Wissensnetz::setProfileCategory($AUser, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);

    Wissensnetz::reloadNotificationSettings($AUser->uid);
    Wissensnetz::reloadNotificationSettings($OUser->uid);
    Wissensnetz::reloadNotificationSettings($GOMember->uid);
    Wissensnetz::reloadNotificationSettings($GMember->uid);
    Wissensnetz::reloadNotificationSettings($GAuthor->uid);
    Wissensnetz::cleanCoreSystemQueue();

    $I->completedSetup();

    $I->loginAsUser($GAuthor);

    // Gruppe 1
    $I->expect('Founding a new group');
    $I->amOnPage('node/add/group');
    $I->checkFirstCategory();
    $title = 'Group GP270.05-' . $microTime;
    $I->submitForm('#group-node-form', ['title' => $title,]);

    $I->completedSetup();

    $I->amOnPage("/groups");
    $I->see($title, '.main_layout_right');
    $I->click($title, '.main_layout_right');
    $I->see("Datei einstellen", '.main_layout_right');
    $nodeId = $I->grabFromCurrentUrl('/node\/(\d+)/');

    Wissensnetz::addMemberToGroup($GMember, $nodeId);
    Wissensnetz::addMemberToGroup($GOMember, $nodeId);

    $I->amOnPage("/posts");
    $I->seeLink("Beitrag erstellen");

    $title = "Test Title 270.05-" . $microTime;

    $I->createBeitrag([
      'Titel' => $title,
      'Inhalt' => "Test Inhalt 270_05",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'category' => SALTO_KNOWLEDGEBASE_KB_SPORT_TID,
      'group' => $nodeId,
      'user' => $GAuthor
    ]);

    $I->amOnPage('/node/' . $nodeId);
    $I->see($title);
    // $I->see("Gespeichert von " . $GAuthor->firstname);

    $I->startCoreSystemQueueForType(MESSAGE_TYPE_NOTIFICATION_POST_CREATED);

    $I->checkAK('270.05', 'AK 1: Es wird an alle Betroffenen eine Nachricht versandt');

    $I->loginAsUser($OUser);
    $I->amOnPage('notifications/all');
    $I->dontSee($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');

    $I->checkAK('270.05', 'AK 1.1: Mitglieder der Gruppe');

    $I->loginAsUser($GMember);
    $I->amOnPage('notifications/all');
    $I->see($title, '.views-row-1');
    $I->checkAK('270.05', 'AK 2: Doppelte Benachrichtigungen Gruppen und Gemeinschaftsbereich sollen nicht rausgeschickt werden.');
    $I->dontSee($title, '.views-row-2');

    $I->loginAsUser($GOMember);
    $I->amOnPage('notifications/all');
    $I->see($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');

    $I->checkAK('270.05', 'AK 1.2: Alle, die das Themenfeld XY ausgewählt haben (WENN: Leserecht "Alle Wissensnetz-Mitglieder"');

    $I->loginAsUser($OUser);
    $I->amOnPage('notifications/all');
    $I->dontSee($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');

    $I->loginAsUser($AUser);
    $I->amOnPage('notifications/all');
    $I->see($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');
  }

  public function GP_01_1_public_post_notifications(AcceptanceTester $I) {

    $I->wantTo('270.05 - Benachrichtigung - Einstellen eines Beitrags / Materials mit Auswahl einer Gruppe');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $GAuthor = $I->haveUser([
      'firstname' => 'Founder',
      'lastname' => $microTime,
    ]);
    $GMember = $I->haveUser([
      'firstname' => 'GMember',
      'lastname' => $microTime,
    ]);
    $GOMember = $I->haveUser([
      'firstname' => 'GOMember',
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

    Wissensnetz::setNotificationsDefaults($GAuthor->uid);
    Wissensnetz::setNotificationsDefaults($GMember->uid);
    Wissensnetz::setNotificationsDefaults($GOMember->uid);
    Wissensnetz::setNotificationsDefaults($AUser->uid);
    Wissensnetz::setNotificationsDefaults($OUser->uid);

    Wissensnetz::setProfileCategory($OUser, [Wissensnetz::KB_CATEGORY_FALLBACK]);
    Wissensnetz::setProfileCategory($GOMember, [Wissensnetz::KB_CATEGORY_FALLBACK]);
    Wissensnetz::setProfileCategory($GAuthor, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);
    Wissensnetz::setProfileCategory($GMember, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);
    Wissensnetz::setProfileCategory($AUser, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);

    Wissensnetz::reloadNotificationSettings($AUser->uid);
    Wissensnetz::reloadNotificationSettings($OUser->uid);
    Wissensnetz::reloadNotificationSettings($GOMember->uid);
    Wissensnetz::reloadNotificationSettings($GMember->uid);
    Wissensnetz::reloadNotificationSettings($GAuthor->uid);
    Wissensnetz::cleanCoreSystemQueue();

    $I->completedSetup();

    $I->loginAsUser($GAuthor);

    // Gruppe 1
    $I->expect('Founding a new group');
    $I->amOnPage('node/add/group');
    $I->checkFirstCategory();
    $title = 'Group GP270.05-' . $microTime;
    $I->submitForm('#group-node-form', ['title' => $title,]);

    $I->completedSetup();

    $I->amOnPage("/groups");
    $I->see($title, '.main_layout_right');
    $I->click($title, '.main_layout_right');
    $I->see("Datei einstellen", '.main_layout_right');
    $nodeId = $I->grabFromCurrentUrl('/node\/(\d+)/');

    Wissensnetz::addMemberToGroup($GMember, $nodeId);
    Wissensnetz::addMemberToGroup($GOMember, $nodeId);

    $I->amOnPage("/posts");
    $I->seeLink("Beitrag erstellen");

    $title = "Test Title 270.05-" . $microTime;

    $I->createBeitrag([
      'Titel' => $title,
      'Inhalt' => "Test Inhalt 270_05",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'category' => SALTO_KNOWLEDGEBASE_KB_SPORT_TID,
      'user' => $GAuthor
    ]);

    $I->startCoreSystemQueueForType(MESSAGE_TYPE_NOTIFICATION_POST_CREATED);

    $I->loginAsUser($OUser);
    $I->amOnPage('notifications/all');
    $I->dontSee($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');

    $I->loginAsUser($GMember);
    $I->amOnPage('notifications/all');
    $I->see($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');

    $I->loginAsUser($GOMember);
    $I->amOnPage('notifications/all');
    $I->dontsee($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');

    $I->loginAsUser($AUser);
    $I->amOnPage('notifications/all');
    $I->see($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');
  }

}
