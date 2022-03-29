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
class GroupsMailSendCest {

  /**
   * Always create this entities before every course
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {
   // $I->setMailSystem();
  }

  public function _after(AcceptanceTester $I) {
   // $I->resetMailSystem();
  }

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
   * @return bool
   */
  public function GMS_01_0_check_post_mail_notification(AcceptanceTester $I) {
    // TODO: fix the process, mail are fired/send after codeception run

    $I->wantTo('270.05 - Benachrichtigung - Einstellen eines Beitrags / Materials mit Auswahl einer Gruppe');

    $users = $I->getTestUsers();

    $I->loginAsUser($users['AUser']);

    $I->amOnPage("/posts");
    $I->mailWasSend($users['GAuthor']->mail, FALSE);
    $I->mailWasSend($users['AUser']->mail);
    $I->mailWasSend($users['GMember']->mail);
  }

  /**
   * @skip test incomplete
   *
   * @param AcceptanceTester $I
   * @return bool
   */
  public function GMS_01_1_check_invite_mail_notification(AcceptanceTester $I) {
    // TODO: fix the process, mail are fired/send after codeception run

    $I->wantTo('32.359 - Gruppe - Einladungen - Mail in list');

    $users = $I->getTestUsers();

    $I->loginAsUser($users['AUser']);

    $I->amOnPage("/posts");
    $I->mailWasSend($users['GAuthor']->mail, FALSE);
    $I->mailWasSend($users['OUser']->mail, FALSE);
    $I->mailWasSend($users['DOSBUser']->mail, FALSE);
    $I->mailWasSend($users['AUser']->mail);
    $I->mailWasSend($users['GMember']->mail);

    $I->cleanMailSystem();
  }

}

