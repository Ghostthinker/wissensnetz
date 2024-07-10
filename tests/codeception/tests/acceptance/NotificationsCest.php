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

    Wissensnetz::setProfileCategory($DOSBUser, [salto_knowledgebase_get_fallback_kb_category_tid()]);
    Wissensnetz::setNotificationsCommunityOff($DOSBUser->uid);

    Wissensnetz::setProfileCategory($OUser, [salto_knowledgebase_get_fallback_kb_category_tid()]);
    Wissensnetz::setNotificationsCommunityOff($OUser->uid);
    Wissensnetz::setNotificationsDefaults($GAuthor->uid);
    Wissensnetz::setNotificationsDefaults($AUser->uid);
    Wissensnetz::setProfileCategory($GAuthor, [salto_knowledgebase_get_default_kb_category_tid()]);
    Wissensnetz::setProfileCategory($AUser, [salto_knowledgebase_get_default_kb_category_tid()]);

    Wissensnetz::cleanCoreSystemQueue();

    $I->loginAsUser($GAuthor);
    $title = "Test Title 270.05-" . $microTime;

    $I->createBeitrag([
      'user' => $GAuthor,
      'Titel' => $title,
      'Inhalt' => "Test Inhalt 270_05",
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'Kategorie' => salto_knowledgebase_get_default_kb_category_tid(),
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
  public function N350_01_abo_off(AcceptanceTester $I) {

    $I->wantTo('N351.00 - Benachrichtigung - Maintenance abo off');
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

    Wissensnetz::setProfileCategory($DOSBUser, [salto_knowledgebase_get_fallback_kb_category_tid()]);
    Wissensnetz::setNotificationsCommunityOff($DOSBUser->uid);
    Wissensnetz::setProfileCategory($OUser, [salto_knowledgebase_get_fallback_kb_category_tid()]);
    Wissensnetz::setNotificationsCommunityOff($OUser->uid);
    Wissensnetz::setNotificationsDefaults($GAuthor->uid);
    Wissensnetz::setNotificationsDefaults($AUser->uid);
    Wissensnetz::setProfileCategory($GAuthor, [salto_knowledgebase_get_default_kb_category_tid()]);
    Wissensnetz::setProfileCategory($AUser, [salto_knowledgebase_get_default_kb_category_tid()]);

    $I->loginAsUser($GAuthor);

    $title = "Test Title 270.05-" . $microTime;

    $POST = $I->createBeitrag([
      'user' => $GAuthor,
      'Titel' => $title,
      'Inhalt' => "Test Inhalt 270_05",
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'Kategorie' => salto_knowledgebase_get_default_kb_category_tid(),
    ]);

    $I->completedSetup();
    $I->loginAsUser($OUser);

    $I->amOnPage("/node/" . $POST->nid);
    $I->dontSee('Auto-Abonniert', '.main_layout_right .flag-outer');
    $I->see('Abonnieren', '.main_layout_right .flag-outer');

    $I->loginAsUser($DOSBUser);
    $I->amOnPage("/node/" . $POST->nid);
    $I->dontSee('Auto-Abonniert', '.main_layout_right .flag-outer');
    $I->see('Abonnieren', '.main_layout_right .flag-outer');

    $I->loginAsUser($GAuthor);
    $I->amOnPage("/node/" . $POST->nid);
    $I->see('Auto-Abonniert', '.main_layout_right .flag-outer');
    $I->dontSee('Abonnieren', '.main_layout_right .flag-outer');

    $I->loginAsUser($AUser);
    $I->amOnPage("/node/" . $POST->nid);
    $I->see('Auto-Abonniert', '.main_layout_right .flag-outer');
    $I->dontSee('Abonnieren', '.main_layout_right .flag-outer');
  }

}

