<?php

use Helper\Wissensnetz;

/**
 * Class StartseiteCest
 * Alle Tests bezüglich Startseiten funktionalität
 *
 * @see aus https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.1aa149yk5ke
 *
 */
class HomepageCest {

  /**
   * Always create this entities before every course
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {  }

  public function _after(AcceptanceTester $I) {
    //cleanup is done in EdubreakHelper
  }

  /**
   * S0.00 Login Block Anmeldung mit Email und Passwort
   *
   * @see https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.p1gkju6wd6ig
   * @param \AcceptanceTester $I #
   */
  public function HP_01_00_login(AcceptanceTester $I) {

    $I->wantTo('S0.00 - Login Block - Anmeldung mit Email und Passwort');

    $user1 = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster',
    ]);

    $I->completedSetup();

    $I->amOnPage("/");
    $I->see("E-Mail");
    $I->loginAsUser($user1);
    $I->seeLink("max muster");
    $I->seeLink("Nachrichten");
    $I->seeLink("Beitrag erstellen");
  }

  /**
   * S0.01 - Login Block - Neues Passwort anfordern
   *
   * @see https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.el9gw712w3m1
   * @param \AcceptanceTester $I
   */
  public function HP_01_1_request_password(AcceptanceTester $I) {

    $I->wantTo('S0.01 - Login Block - Neues Passwort anfordern');

    $user1 = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster',
    ]);

    $I->completedSetup();

    $I->amOnPage("/");
    $I->click("Neues Passwort anfordern", '#desktop-login-form');
    $I->fillField('name', $user1->mail);
    $I->click('Neues Passwort per E-Mail zuschicken');
    $I->see("Das Passwort und weitere Hinweise wurden an die angegebene E-Mail-Adresse gesendet.");
  }

  /**
   * S2.00 - Aktivitätsstorm - Neuste öffentliche Beiträge erscheinen im Stream
   *
   * @see https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.aqpt35h2blst
   * @param \AcceptanceTester $I
   */
  public function HP_02_0_stream_posts_positive(AcceptanceTester $I) {

    $I->wantTo('S2.00 - Aktivitätsstorm - Neuste öffentliche Beiträge erscheinen im Stream');

    $user1 = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster',
    ]);

    $I->completedSetup();

    $I->loginAsUser($user1);

    $titel = "Test Titel S2_00 " . time();

    $I->createBeitrag([
      'Titel' => $titel,
      'Inhalt' => "Test Inhalt S2_00",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'category' => SALTO_KNOWLEDGEBASE_KB_EDUCATION_TID,
      'user' => $user1
    ]);

    $I->amOnPage("/");
    $I->see($user1->realname . " hat den Beitrag $titel erstellt.");
    //$I->see("Gespeichert von " . $user1->realname . " am ");
  }

  /**
   * S2.01 - Aktivitätsstorm - Neuste private Beiträge erscheinen nicht im Stream
   *
   * @see https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.x4ix9l36qu8u
   * @param \AcceptanceTester $I
   */
  public function HP_02_1_stream_posts_negative(AcceptanceTester $I) {

    $I->wantTo('S2.01 - Aktivitätsstorm - Neuste private Beiträge erscheinen nicht im Stream');

    $user1 = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster',
    ]);
    $I->completedSetup();

    $I->loginAsUser($user1);

    $titel = "Test Titel S2_01 " . time();

    $I->createBeitrag([
      'Titel' => $titel,
      'Inhalt' => "Test Inhalt S2_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'category' => SALTO_KNOWLEDGEBASE_KB_EDUCATION_TID,
      'user' => $user1
    ]);

    $I->amOnPage("/");
    $I->see($user1->realname . " hat den Beitrag $titel erstellt.");

    $user2 = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster2',
    ]);
    $I->loginAsUser($user2);

    $I->amOnPage("/");
    $I->dontSee($user1->realname . " hat den Beitrag $titel erstellt.");

  }

  /**
   * S230.14 #CR Änderung des Beitragstitels und der Inhaltsvorschau auch in Aktivitätenstrom übernehmen
   * Test 1 - Title
   *
   * @UserStory 230.14 https://trello.com/c/SoaeFBaC/560-23014-cr-%C3%A4nderung-des-beitragstitels-und-der-inhaltsvorschau-auch-in-aktivit%C3%A4tenstrom-%C3%BCbernehmen
   * @param \AcceptanceTester $I
   */
  public function HP_02_3_stream_latest_post_title(AcceptanceTester $I) {

    $I->wantTo('I want to check if the stream always shows the latest node titles and bodies on edit activity event');

    $user1 = $I->haveUser([
      'firstname' => 'Streamer',
      'lastname' => '1',
    ]);

    $user2 = $I->haveUser([
      'firstname' => 'Streamer',
      'lastname' => '2',
    ]);

    $I->completedSetup();

    $I->loginAsUser($user1);

    $timestamp = strtotime('-1 day'); //time();
    $titel = "Beitrag 1 alt " . $timestamp;

    $I->createBeitrag([
      'Titel' => $titel,
      'Inhalt' => "Test S230_14_1",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'category' => SALTO_KNOWLEDGEBASE_KB_EDUCATION_TID,
      'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'user' => $user1
    ]);

    $I->checkAK('230.14', 'AK 1: Geänderter Titel eines Beitrags erscheint auch in Aktivitätenstrom');

    $I->amOnPage("/");
    $I->see($user1->realname . " hat den Beitrag $titel erstellt.");
    $newTitle1 = $titel;

    $I->loginAsUser($user2);

    $I->amOnPage("/");
    $I->see($user1->realname . " hat den Beitrag $newTitle1 erstellt.");
    $I->click($newTitle1);

    $I->see('Beitrag bearbeiten');
    $I->click('Beitrag bearbeiten');

    $newTitle2 = "Beitrag 1 renew " . $timestamp;
    $I->submitForm("#post-node-form",['title' => $newTitle2]);

    $I->amOnPage("/");
    $I->see($user1->realname . " hat den Beitrag $newTitle2 erstellt.");
    $I->see($user2->realname . " hat den Beitrag $newTitle2 aktualisiert.");
    $I->dontSee($user1->realname . " hat den Beitrag $newTitle1 erstellt.");
    $I->dontSee($user1->realname . " hat den Beitrag $newTitle1 aktualisiert.");
    $I->dontSee($user2->realname . " hat den Beitrag $newTitle1 aktualisiert.");

    $I->loginAsUser($user1);

    $I->amOnPage("/");
    $I->see($user1->realname . " hat den Beitrag $newTitle2 erstellt.");
    $I->see($user2->realname . " hat den Beitrag $newTitle2 aktualisiert.");
    $I->click($newTitle2);
    $I->see('Beitrag bearbeiten');
    $I->click('Beitrag bearbeiten');

    $newTitle3 = "Beitrag 1 newer " . $timestamp;
    $I->submitForm("#post-node-form",['title' => $newTitle3]);
    $I->see($newTitle3, 'h2');

    $I->amOnPage("/");
    $I->see($user1->realname . " hat den Beitrag $newTitle3 erstellt.");
    $I->see($user2->realname . " hat den Beitrag $newTitle3 aktualisiert.");
    $I->dontSee($user1->realname . " hat den Beitrag $newTitle3 aktualisiert.");

  }

  /**
   * S230.14 #CR Änderung des Beitragstitels und der Inhaltsvorschau auch in Aktivitätenstrom übernehmen
   * Test 2 - Text/Body
   *
   * @UserStory 230.14 https://trello.com/c/SoaeFBaC/560-23014-cr-%C3%A4nderung-des-beitragstitels-und-der-inhaltsvorschau-auch-in-aktivit%C3%A4tenstrom-%C3%BCbernehmen
   * @param \AcceptanceTester $I
   */
  public function HP_02_4_stream_latest_post_body(AcceptanceTester $I) {

    $I->wantTo('I want to check if the stream always shows the latest node titles and bodies on edit activity event');

    $user1 = $I->haveUser([
      'firstname' => 'Streamer1',
      'lastname' => 'Text',
    ]);

    $user2 = $I->haveUser([
      'firstname' => 'Streamer2',
      'lastname' => 'Text',
    ]);

    $I->completedSetup();

    $I->loginAsUser($user1);

    $timestamp = strtotime('-1 day'); //time();
    $title = "Beitrag 2 Text" . $timestamp;
    $content = "Test content S230_14_2 create " . $timestamp;

    $POST = $I->havePost([
      'Titel' => $title,
      'Inhalt' => $content,
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'category' => SALTO_KNOWLEDGEBASE_KB_EDUCATION_TID,
      'user' => $user1
    ]);

    $I->amOnPage("node/" . $POST->nid);
    $I->see($content);

  }

  /**
   * S4.00 - Bildungsnetzteam - Wird nur für Rolle DOSB angezeigt
   *
   * @see https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.s9jnvxg8frta
   * @param \AcceptanceTester $I
   */
  public function HP_03_0_dosb_role_visibility(AcceptanceTester $I) {

    $I->wantTo('S4.00 - Bildungsnetzteam - Wird nur für Rolle DOSB angezeigt');

    $dosb_user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster',
      'role_dosb' => TRUE,
    ]);
    $I->completedSetup();

    $I->loginAsUser($dosb_user);

    $I->amOnPage("/");
    $I->seeLink("Statistiken");
    $I->seeLink("E-Mail-Verteiler");

    $not_dosb_user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster',
    ]);
    $I->loginAsUser($not_dosb_user);

    $I->amOnPage("/");
    $I->dontSeeLink("Statistiken");
    $I->dontSeeLink("E-Mail-Verteiler");
    $I->dontSee("Wissensnetz Team", "h2");
  }

  /**
   * @skip Dieser test macht eigentlich das selbe wie HP_01_0
   *
   * S0.00 Login Block Anmeldung mit Email und Passwort
   *
   * @see
   * @param \AcceptanceTester $I #
   */
  public function HP_05_0(AcceptanceTester $I) {

    $I->wantTo('S5.00 - Login Block - Anmeldung mit Email und Passwort');

    $user1 = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster',
    ]);

    $I->completedSetup();

    $I->amOnPage("/licenses");
    $I->dontSee("Lizenzen");
    $I->submitForm('#user-login', [
      'name' => $user1->mail,
      'pass' => $user1->password
    ]);

    $I->see("Lizenzen");
  }

}
