<?php

use Helper\Wissensnetz;

/**
 *
 */
class ReactionCest {

  /**
   * Always create this entities before every course
   *
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {
  }

  public function _after(AcceptanceTester $I) {

  }

  /**
   * S0.00 Login Block Anmeldung mit Email und Passwort
   *
   * @param \AcceptanceTester $I #
   */
  public function S0_00(AcceptanceTester $I) {

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
   * R0.01 - Reaction basic test
   *
   * @param \AcceptanceTester $I
   */
  public function R0_01(AcceptanceTester $I) {

    $I->wantTo('test the reactions');

    $user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster',
    ]);

    $POST = $I->havePost([
      'user' => $user,
      'authorList' => [$user],
    ]);


    $I->completedSetup();

    $I->loginAsUser($user);

    $I->amOnPage('node/' . $POST->nid);

    $I->executeJS('document.querySelector("div > div > div.reaction-footer > div.reaction-actions > gt-reactions-button").shadowRoot.querySelector("#react-btn").click()');
    $I->executeJS('document.querySelector("div > div > div.reaction-footer > div.reaction-actions > gt-reactions-button").shadowRoot.querySelector("#gt-reactions-container > button:nth-child(1) > img").click()');

    $I->wait(5);

    $value = $I->executeJS("return document.querySelector('.reaction-summary').textContent");
    $I->assertEquals('   1', $value);

    $I->executeJS('document.querySelector("div > div > div.reaction-footer > div.reaction-actions > gt-reactions-button").shadowRoot.querySelector("#react-btn").click()');
    $I->executeJS('document.querySelector("div > div > div.reaction-footer > div.reaction-actions > gt-reactions-button").shadowRoot.querySelector("#gt-reactions-container > button:nth-child(6) > img").click()');

    $I->wait(5);

    $value = $I->executeJS("return document.querySelector('.reaction-summary').textContent");
    $I->assertEquals('   2', $value);

    $I->executeJS('document.querySelector("div > div > div.reaction-footer > div.reaction-actions > gt-reactions-button").shadowRoot.querySelector("#react-btn").click()');
    $I->executeJS('document.querySelector("div > div > div.reaction-footer > div.reaction-actions > gt-reactions-button").shadowRoot.querySelector("#gt-reactions-container > button:nth-child(6) > img").click()');

    $I->wait(5);

    $value = $I->executeJS("return document.querySelector('.reaction-summary').textContent");
    $I->assertEquals('   1', $value);

    $I->executeJS('document.querySelector("div > div > div.reaction-footer > div.reaction-actions > gt-reactions-button").shadowRoot.querySelector("#react-btn").click()');
    $I->executeJS('document.querySelector("div > div > div.reaction-footer > div.reaction-actions > gt-reactions-button").shadowRoot.querySelector("#gt-reactions-container > button:nth-child(1) > img").click()');

    $I->wait(5);

    $value = $I->executeJS("return document.querySelector('.reaction-summary').textContent");
    $I->assertEquals('', $value);

  }

  /**
   * R0.02 - Reaction comments test
   *
   * @param \AcceptanceTester $I
   */
  public function R0_02(AcceptanceTester $I) {

    $I->wantTo('test the reactions on node comments');

    $user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster',
    ]);

    $POST = $I->havePost([
      'user' => $user,
      'authorList' => [$user],
    ]);

    $I->haveComment($POST, ['user' => $user]);

    $I->completedSetup();

    $I->loginAsUser($user);

    $I->amOnPage('node/' . $POST->nid);

    // rate / reacte
    $I->executeJS('document.querySelector("#comments div.reaction-actions gt-reactions-button").shadowRoot.querySelector("#gt-reactions-container > button:nth-child(1) > img").click()');

    $value = $I->executeJS("return document.querySelector('#comments .reaction-summary').textContent");
    $I->assertEquals('   1', $value);

    $I->executeJS('document.querySelector("#comments div.reaction-actions gt-reactions-button").shadowRoot.querySelector("#gt-reactions-container > button:nth-child(6) > img").click()');

    $value = $I->executeJS("return document.querySelector('#comments .reaction-summary').textContent");
    $I->assertEquals('   2', $value);

  }

}
