<?php

use Helper\Wissensnetz;

class UsersCest {

  const KB_CATEGORY_NICHT_SORTIERT = SALTO_KNOWLEDGEBASE_KB_FALLBACK_TID;

  private $dosb_user = NULL;
  private $user = NULL;
  /**
   * Always create this entities before every course
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {


  }

  public function _after(AcceptanceTester $I) {
    //cleanup is done in EdubreakHelper
  }

  /**
   * @skip
   * @param \AcceptanceTester $I
   *
   * @return void
   */
  public function U_01_0_sync_user(AcceptanceTester $I) {

    $I->wantTo('test that i can login with a synced user to the tum, but unknown in keycloak');

    variable_set('salto_sso', ['sso_mode' => 'tum']);
    $microTime = microtime(TRUE);
    $password = user_password(8);
    $user = $I->haveUser([
      'firstname' => $password,
      'lastname' => $microTime,
      'pass' => $password
    ]);

    $I->completedSetup();

    $I->amOnPage("/");

    $I->executeJS('document.querySelector("#user-login-form > div > div > div.salto-sso-login-top > div.salto-sso-login-right.form-actions.form-wrapper.form-group > a").click()');

    $I->fillField('#username', $user->mail . ' ' . $password);
    $I->fillField('#password', $password . 'incorrect');

    $I->click('Anmelden');

    $I->see('Falscher Benutzername oder Passwort');
    $I->fillField('#password', $password);
    $I->click('Anmelden');
    $I->see('Terms and Conditions');
  }




}
