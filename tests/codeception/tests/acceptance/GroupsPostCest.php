<?php
/**
 * Created by PhpStorm.
 * User: linnie
 * Date: 28.11.18
 * Time: 14:42
 */

use Helper\Bildungsnetz;

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

    Bildungsnetz::setNotificationsDefaults($GAuthor->uid);
    Bildungsnetz::setNotificationsDefaults($GMember->uid);
    Bildungsnetz::setNotificationsDefaults($GOMember->uid);
    Bildungsnetz::setNotificationsDefaults($AUser->uid);
    Bildungsnetz::setNotificationsDefaults($OUser->uid);
    Bildungsnetz::setProfileCategory($OUser, [Bildungsnetz::KB_CATEGORY_FALLBACK]);
    Bildungsnetz::setProfileCategory($GOMember, [Bildungsnetz::KB_CATEGORY_FALLBACK]);
    Bildungsnetz::setProfileCategory($GAuthor, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);
    Bildungsnetz::setProfileCategory($GMember, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);
    Bildungsnetz::setProfileCategory($AUser, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);

    Bildungsnetz::reloadNotificationSettings($AUser->uid);
    Bildungsnetz::reloadNotificationSettings($OUser->uid);
    Bildungsnetz::reloadNotificationSettings($GOMember->uid);
    Bildungsnetz::reloadNotificationSettings($GMember->uid);
    Bildungsnetz::reloadNotificationSettings($GAuthor->uid);
    Bildungsnetz::cleanCoreSystemQueue();

    $I->completedSetup();

    $I->loginAsUser($GAuthor);

    // Gruppe 1
    $I->expect('Founding a new group');
    $I->amOnPage('node/add/group');
    $I->checkCategoryEducation();
    $title = 'Group GP270.05-' . $microTime;
    $I->submitForm('#group-node-form', ['title' => $title,]);

    $I->completedSetup();

    $I->amOnPage("/groups");
    $I->see($title, '.main_layout_right');
    $I->click($title, '.main_layout_right');
    $I->see("Datei einstellen", '.main_layout_right');
    $nodeId = $I->grabFromCurrentUrl('/node\/(\d+)/');

    Bildungsnetz::addMemberToGroup($GMember, $nodeId);
    Bildungsnetz::addMemberToGroup($GOMember, $nodeId);

    $I->amOnPage("/posts");
    $I->seeLink("Beitrag erstellen");

    $title = "Test Title 270.05-" . $microTime;

    $I->createBeitrag([
      'Titel' => $title,
      'Inhalt' => "Test Inhalt 270_05",
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'Kategorie' => SALTO_KNOWLEDGEBASE_KB_SPORT_TID,
      'Gruppenzugriff' => $nodeId,
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

    $I->checkAK('270.05', 'AK 1.2: Alle, die das Themenfeld XY ausgewählt haben (WENN: Leserecht "Alle Bildungsnetz-Mitglieder"');

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

    Bildungsnetz::setNotificationsDefaults($GAuthor->uid);
    Bildungsnetz::setNotificationsDefaults($GMember->uid);
    Bildungsnetz::setNotificationsDefaults($GOMember->uid);
    Bildungsnetz::setNotificationsDefaults($AUser->uid);
    Bildungsnetz::setNotificationsDefaults($OUser->uid);

    Bildungsnetz::setProfileCategory($OUser, [Bildungsnetz::KB_CATEGORY_FALLBACK]);
    Bildungsnetz::setProfileCategory($GOMember, [Bildungsnetz::KB_CATEGORY_FALLBACK]);
    Bildungsnetz::setProfileCategory($GAuthor, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);
    Bildungsnetz::setProfileCategory($GMember, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);
    Bildungsnetz::setProfileCategory($AUser, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);

    Bildungsnetz::reloadNotificationSettings($AUser->uid);
    Bildungsnetz::reloadNotificationSettings($OUser->uid);
    Bildungsnetz::reloadNotificationSettings($GOMember->uid);
    Bildungsnetz::reloadNotificationSettings($GMember->uid);
    Bildungsnetz::reloadNotificationSettings($GAuthor->uid);
    Bildungsnetz::cleanCoreSystemQueue();

    $I->completedSetup();

    $I->loginAsUser($GAuthor);

    // Gruppe 1
    $I->expect('Founding a new group');
    $I->amOnPage('node/add/group');
    $I->checkCategoryEducation();
    $title = 'Group GP270.05-' . $microTime;
    $I->submitForm('#group-node-form', ['title' => $title,]);

    $I->completedSetup();

    $I->amOnPage("/groups");
    $I->see($title, '.main_layout_right');
    $I->click($title, '.main_layout_right');
    $I->see("Datei einstellen", '.main_layout_right');
    $nodeId = $I->grabFromCurrentUrl('/node\/(\d+)/');

    Bildungsnetz::addMemberToGroup($GMember, $nodeId);
    Bildungsnetz::addMemberToGroup($GOMember, $nodeId);

    $I->amOnPage("/posts");
    $I->seeLink("Beitrag erstellen");

    $title = "Test Title 270.05-" . $microTime;

    $I->createBeitrag([
      'Titel' => $title,
      'Inhalt' => "Test Inhalt 270_05",
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'Kategorie' => SALTO_KNOWLEDGEBASE_KB_SPORT_TID,
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
