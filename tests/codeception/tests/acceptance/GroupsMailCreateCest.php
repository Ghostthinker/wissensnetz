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
class GroupsMailCreateCest {

  private $GAuthor;
  private $GMember;
  private $AUser;

  /**
   * Always create this entities before every course
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {}

  public function _after(AcceptanceTester $I) {}

  /**
   * @skip test incomplete
   *
   * @group mail
   *
   * 270.05 Benachrichtigung - Einstellen eines Beitrags / Materials mit Auswahl einer Gruppe
   * @UserStory 270.05 - https://trello.com/c/WGfdfVK1/666-27005-benachrichtigung-einstellen-eines-beitrags-materials-mit-auswahl-einer-gruppe
   * @Task https://trello.com/c/dFSzN0ey/1037-27005-benachrichtigung-einstellen-eines-beitrags-materials-mit-auswahl-einer-gruppe
   *
   * @param \AcceptanceTester $I
   */
  public function GMC_01_0_check_post_mail_notifications(AcceptanceTester $I) {
    //disable $I->setMailSystem(); bug

    $I->wantTo('270.05 - Benachrichtigung - Einstellen eines Beitrags / Materials mit Auswahl einer Gruppe');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $this->GAuthor = $I->haveUser([
      'firstname' => 'Founder',
      'lastname' => $microTime,
      'mail' => 'jane.author+' . $microTime . '@example.de'
    ]);
    $this->GMember = $I->haveUser([
      'firstname' => 'GMember',
      'lastname' => $microTime,
      'mail' => 'john.doe+' . $microTime . '@example.de'
    ]);
    $this->AUser = $I->haveUser([
      'firstname' => 'AUser',
      'lastname' => $microTime,
      'mail' => 'billy.doe+' . $microTime . '@example.de',
      'role_api_user' => TRUE
    ]);

    $og = $I->haveOrganisation('NotificationTestOG-27005', ['body' => 'dummy og',]);
    $I->addMemberToOrganisation($this->AUser, $og, array(SALTO_ORGANISATION_OG_ROLE_LIZENZVERWALTER_RID));

    $I->loginAsUser($this->GAuthor);

    // Gruppe 1
    $I->expect('Founding a new group');
    $I->amOnPage('node/add/group');
    $I->checkCategoryEducation();
    $title = 'A Group GP270.05-' . $microTime;
    $I->submitForm('#group-node-form', ['title' => $title,]);

    //$I->setMailSystem(TestMailSystem::MAIL_SYSTEM_CLASS_ONSCREEN);
    $I->setMailSystem();

    $I->completedSetup();

    $I->amOnPage("/groups");
    $I->see($title, '.main_layout_right');
    $I->click($title, '.main_layout_right');
    $I->see("Datei einstellen", '.main_layout_right');
    $nodeId = $I->grabFromCurrentUrl('/node\/(\d+)/');

    $I->addMemberToGroup($this->GMember, $nodeId);

    $I->amOnPage("/posts");
    $I->seeLink("Beitrag erstellen");

    $title = "Test Title 270.05-" . $microTime;

    $I->createBeitrag([
      'Titel' => $title,
      'Inhalt' => "Test Inhalt 270_05",
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'Kategorie' => Bildungsnetz::KB_CATEGORY_EDUCATION,
    ]);

    $I->saveTestUsers(array('GAuthor' => $this->GAuthor, 'GMember' => $this->GMember, 'AUser' => $this->AUser));

    $I->resetMailSystem(TRUE);
  }

  /**
   * @skip test incomplete
   *
   * @group mail
   *
   * 32.359 - Gruppe - Einladungen - Mail
   * @Task https://trello.com/c/L4mFhfbe/359-gruppe-einladungen-mail
   *
   * @param \AcceptanceTester $I
   * @return bool
   */
  public function GMC_01_1_check_group_invite_mail_notification(AcceptanceTester $I) {
    //disable $I->setMailSystem(); bug

    $I->wantTo('32.359 - Gruppe - Einladungen - Mail');

    $microTime = microtime(TRUE);
    //gruppenbenutzer
    $this->GAuthor = $I->haveUser([
      'firstname' => 'Founder',
      'lastname' => $microTime,
      'mail' => 'jane.author+' . $microTime . '@example.de'
    ]);
    $this->GMember = $I->haveUser([
      'firstname' => 'GMember',
      'lastname' => $microTime,
      'mail' => 'john.doe+' . $microTime . '@example.de'
    ]);
    $this->AUser = $I->haveUser([
      'firstname' => 'AUser',
      'lastname' => $microTime,
      'mail' => 'billy.doe+' . $microTime . '@example.de',
      'role_dosb' => TRUE
    ]);
    $DOSBUser = $I->haveUser([
      'firstname' => 'DOSBUser',
      'lastname' => $microTime,
      'mail' => 'dosb.jeanie+' . $microTime . '@example.de',
      'role_dosb' => TRUE
    ]);
    $OUser = $I->haveUser([
      'firstname' => 'OUser',
      'lastname' => $microTime,
      'mail' => 'billy.jean+' . $microTime . '@example.de',
    ]);

    onsite_notification_settings_update($OUser->uid, 'notification_group_invite_recieved', array('mail' => 0), 0);
    onsite_notification_settings_update($DOSBUser->uid, 'notification_group_invite_recieved', array('mail' => 0), 0);

    $I->loginAsUser($this->GAuthor);

    // Gruppe 1
    $I->expect('Founding a new group');
    $I->amOnPage('node/add/group');
    $I->checkCategoryEducation();
    $title = 'A GroupTest GM32.359-' . $microTime;
    $I->submitForm('#group-node-form', ['title' => $title,]);

    //$I->setMailSystem(TestMailSystem::MAIL_SYSTEM_CLASS_ONSCREEN);
    $I->setMailSystem();

    $I->completedSetup();

    $I->amOnPage("/groups");
    $I->see($title, '.main_layout_right');
    $I->click($title, '.main_layout_right');
    $I->see('Personen einladen', '.main_layout_right');
    $I->click('Personen einladen', '.main_layout_right');

    $I->waitForElement('.search-query.edubreak-users-selector-processed');
    // add first user
    $I->fillField('.search-query.edubreak-users-selector-processed', $this->AUser->realname);
    $I->wait(3);
    $I->click('#edubreak_og_ui_searchlist .btn-add.edubreak-users-selector-processed');
    //
    $I->fillField('.search-query.edubreak-users-selector-processed', $this->GMember->realname);
    $I->wait(3);
    //$I->click('Hinzufügen');
    $I->click('#edubreak_og_ui_searchlist .btn-add.edubreak-users-selector-processed');
    //
    $I->fillField('.search-query.edubreak-users-selector-processed', $OUser->realname);
    $I->wait(3);
    $I->click('#edubreak_og_ui_searchlist .btn-add.edubreak-users-selector-processed');
    //
    $I->fillField('.search-query.edubreak-users-selector-processed', $DOSBUser->realname);
    $I->wait(3);
    $I->click('#edubreak_og_ui_searchlist .btn-add.edubreak-users-selector-processed');
    //
    $I->wait(6);
    $I->clickJS('Personen einladen', '#edit-submit');

    $I->saveTestUsers(array('GAuthor' => $this->GAuthor, 'GMember' => $this->GMember, 'AUser' => $this->AUser, 'OUser' => $OUser, 'DOSBUser' => $DOSBUser));

    $I->resetMailSystem(TRUE);
  }

}

