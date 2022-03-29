<?php


class UserCest {
  /**
   * Always create this entities before every course
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {}

  public function _after(AcceptanceTester $I) {}


  /**
   * 360.06 DOSB - Benutzerverwaltung - Benutzerkonten löschen
   *
   * @see https://trello.com/c/ySviqmnc/1043-36006-dosb-benutzerverwaltung-benutzerkonten-l%C3%B6schen
   * @param \AcceptanceTester $I
   */
  public function U_01_0_delete_user(AcceptanceTester $I) {

    $I->wantTo('U360.06 - 360.06 DOSB - Benutzerverwaltung - Benutzerkonten löschen');

    $user = $I->haveUser([
      'firstname' => 'john',
      'lastname' => 'doe-' . time(),
    ]);

    $dosb_user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'dosb',
      'role_dosb' => TRUE,
    ]);

    $not_dosb_user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster',
    ]);

    $I->completedSetup();

    $I->loginAsUser($not_dosb_user);
    $I->checkAK('360.06', 'AK 1.1: Ausgenommen sind Personen die die Rolle DOSB oder Admin haben.');
    $I->amOnPage('/user/' . $user->uid);
    $I->dontSeeLink(t('Delete account'));
    $I->amOnPage('/user/' . $user->uid . '/delete');
    $I->getAccessDenied();
    // own account
    $I->checkAK('360.06', 'AK 3: Die Löschung erfolgt sonst analog zur eigenen Löschung.');
    $I->amOnPage('/user/account/edit');
    $I->see(t('Cancel my account'), '#edit-user-delete');
    $I->clickJS(t('Cancel my account'), '#edit-user-delete');
    $I->see(t('Are you sure you want to delete your Bildungsnetz Account?'));
    $I->see(t('Cancel my account'), 'button#edit-submit');
    $I->clickJS(t('Cancel my account'), 'button#edit-submit');

    $I->loginAsUser($dosb_user);
    $I->checkAK('360.06', 'AK 4: Wichtig Der DOSB erhält keinen Zugriff auf alle Details des Benutzerkontos insb. E-Mail oder Passwortfrage. (!= Benutzer verwalten)');
    $I->amOnPage('/user/' . $user->uid . '/edit');
    $I->getAccessDenied();
    $I->amOnPage('/user/' . $user->uid . '/edit/main');
    $I->getAccessDenied();
    $I->amOnPage('/user/' . $user->uid);
    $I->checkAK('360.06', 'AK 1: Bei jedem Profil wird mir via Aktionsschaltfläche "Benutzerkonto Löschen" (unter "Nachricht schreiben") als DOSB die Möglichkeit zum Löschen gegeben.');
    $I->seeLink(t('Delete account'));
    $I->clickJS(t('Delete account'), '#edit-user-delete');
    $I->notAccessDenied();
    $I->checkAK('360.06', 'AK 2: Der Löschvorgang muss via Dialog explizit bestätigt werden.');
    $I->see(t('Are you sure you want to delete your Bildungsnetz Account?'));
    $I->see(t('Cancel my account'), 'button#edit-submit');
    $I->checkAK('360.06', 'AK 3: Die Löschung erfolgt sonst analog zur eigenen Löschung.');
    $I->clickJS(t('Cancel my account'), 'button#edit-submit');
    $I->waitForText($user->name . ' wurde gelöscht.');
  }

}
