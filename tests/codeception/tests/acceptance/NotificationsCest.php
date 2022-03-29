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
class NotificationsCest {

  /**
   * Always create this entities before every course
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {
    $I->setMailSystem(TestMailSystem::MAIL_SYSTEM_CLASS_ONSCREEN);
  }

  public function _after(AcceptanceTester $I) {
    $I->resetMailSystem(false);
    $I->cleanMailSystem();
  }

  /**
   * 350_00 - Benachrichtigung - Maintenance
   * @Task https://trello.com/c/E1tg9G5b/350-sie-haben-eine-neue-benachrichtigung-erhalten
   *
   * @param \AcceptanceTester $I
   */
  public function N350_00_main(AcceptanceTester $I) {

    $I->wantTo('N350.00 - Benachrichtigung - Maintenance');

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
    $DOSBUser = $I->haveUser([
      'firstname' => 'DOSBUser',
      'lastname' => $microTime,
      'role_dosb' => TRUE
    ]);

    Bildungsnetz::setProfileCategory($DOSBUser, [SALTO_KNOWLEDGEBASE_KB_FALLBACK_TID]);
    Bildungsnetz::setNotificationsCommunityOff($DOSBUser->uid);

    Bildungsnetz::setProfileCategory($OUser, [SALTO_KNOWLEDGEBASE_KB_FALLBACK_TID]);
    Bildungsnetz::setNotificationsCommunityOff($OUser->uid);
    Bildungsnetz::setNotificationsDefaults($GAuthor->uid);
    Bildungsnetz::setNotificationsDefaults($AUser->uid);
    Bildungsnetz::setProfileCategory($GAuthor, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);
    Bildungsnetz::setProfileCategory($AUser, [SALTO_KNOWLEDGEBASE_KB_SPORT_TID]);

    Bildungsnetz::cleanCoreSystemQueue();

    $I->loginAsUser($GAuthor);

    $I->amOnPage("/posts");
    $I->seeLink("Beitrag erstellen");

    $title = "Test Title 270.05-" . $microTime;

    $I->createBeitrag([
      'Titel' => $title,
      'Inhalt' => "Test Inhalt 270_05",
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'Kategorie' => SALTO_KNOWLEDGEBASE_KB_SPORT_TID,
    ]);

    $I->completedSetup();

    $I->startCoreSystemQueueForType(MESSAGE_TYPE_NOTIFICATION_POST_CREATED);

    $I->loginAsUser($OUser);
    $I->dontSee($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');

    $I->loginAsUser($DOSBUser);
    $I->amOnPage('notifications/all');
    $I->dontSee($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');

    $I->loginAsUser($GAuthor);
    $I->amOnPage('notifications/all');
    $I->dontsee($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');

    $I->loginAsUser($AUser);
    $I->amOnPage('notifications/all');
    $I->see($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');

    $I->click($title, '.views-row-1');
    $I->wait(1);

    $myComment = 'Test-Kommentar für die Benachrichtigung evtl Probleme mit den Einstellungen.';
    $I->fillfield(["name" => "comment_body[und][0][value]"], $myComment);
    $I->click('Speichern');

    $I->waitForText("Ihr Kommentar wurde erstellt.", 20);
    $I->see('Gespeichert von ' . 'AUser');
    $I->see($myComment);

    $I->startCoreSystemQueueForType(MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT);

    $I->loginAsUser($GAuthor);
    $I->amOnPage('notifications/all');
    $I->see($myComment, '.views-row-1');
    $I->dontSee($myComment, '.views-row-2');

    $I->loginAsUser($AUser);
    $I->amOnPage('notifications/all');
    $I->see($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');
    $I->dontsee($myComment, '.views-row-1');
    $I->dontSee($myComment, '.views-row-2');

    $I->loginAsUser($OUser);
    $I->amOnPage('notifications/all');
    $I->dontSee($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');
    $I->dontsee($myComment, '.views-row-1');
    $I->dontSee($myComment, '.views-row-2');

    $I->loginAsUser($DOSBUser);
    $I->amOnPage('notifications/all');
    $I->dontSee($title, '.views-row-1');
    $I->dontSee($title, '.views-row-2');
    $I->dontsee($myComment, '.views-row-1');
    $I->dontSee($myComment, '.views-row-2');
  }

  /**
   * 350_00 - Benachrichtigung - Maintenance
   * @Task https://trello.com/c/E1tg9G5b/350-sie-haben-eine-neue-benachrichtigung-erhalten
   *
   * @param \AcceptanceTester $I
   */
  public function N350_00_abo_off(AcceptanceTester $I) {

    $I->wantTo('N350.00 - Benachrichtigung - Maintenance abo off');

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
    $DOSBUser = $I->haveUser([
      'firstname' => 'DOSBUser',
      'lastname' => $microTime,
      'role_dosb' => TRUE
    ]);

    Bildungsnetz::setProfileCategory($DOSBUser, [SALTO_KNOWLEDGEBASE_KB_FALLBACK_TID]);
    Bildungsnetz::setNotificationsCommunityOff($DOSBUser->uid);
    Bildungsnetz::setProfileCategory($OUser, [SALTO_KNOWLEDGEBASE_KB_FALLBACK_TID]);
    Bildungsnetz::setNotificationsCommunityOff($OUser->uid);
    Bildungsnetz::setNotificationsDefaults($GAuthor->uid);
    Bildungsnetz::setNotificationsDefaults($AUser->uid);

    $I->loginAsUser($GAuthor);

    $I->amOnPage("/posts");
    $I->seeLink("Beitrag erstellen");

    $title = "Test Title 270.05-" . $microTime;

    $I->createBeitrag([
      'Titel' => $title,
      'Inhalt' => "Test Inhalt 270_05",
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'Kategorie' => SALTO_KNOWLEDGEBASE_KB_EDUCATION_TID,
    ]);

    $I->completedSetup();

    $postId = $I->grabFromCurrentUrl('/node\/(\d+)/');

    $I->loginAsUser($OUser);
    $I->amOnPage("/node/" . $postId);
    $I->dontSee('Auto-Aboniert', '.main_layout_right .flag-outer');
    $I->see('Abonnieren', '.main_layout_right .flag-outer');

    $I->loginAsUser($DOSBUser);
    $I->amOnPage("/node/" . $postId);
    $I->dontSee('Auto-Aboniert', '.main_layout_right .flag-outer');
    $I->see('Abonnieren', '.main_layout_right .flag-outer');

    $I->loginAsUser($GAuthor);
    $I->amOnPage("/node/" . $postId);
    $I->see('Abonniert', '.main_layout_right .flag-outer');
    //$I->see('Auto-Aboniert', '.main_layout_right .flag-outer');
    $I->dontSee('Abonnieren', '.main_layout_right .flag-outer');

    $I->loginAsUser($AUser);
    $I->amOnPage("/node/" . $postId);
    $I->see('Abonniert', '.main_layout_right .flag-outer');
    //$I->see('Auto-Aboniert', '.main_layout_right .flag-outer');
    $I->dontSee('Abonnieren', '.main_layout_right .flag-outer');
  }

}

