<?php

use Helper\Bildungsnetz;

/**
 * Class OrganisationCest
 * Alle Tests bezüglich funktionalität
 *
 */
class OrganisationsCest {

  /**
   * Always create this entities before every course
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {}

  public function _after(AcceptanceTester $I) {}

  /*
  * 280.08 #E DOSB - Verbesserte Bedienbarkeit direktes Einladen
  *
  * @UserStory 280.08 - https://trello.com/c/w9v2OpP2/994-28008-e-dosb-verbesserte-bedienbarkeit-direktes-einladen
  * @param \AcceptanceTester $I
  */
  public function O_03_0_dosb_direct_invites(AcceptanceTester $I) {
    $I->wantTo('280.08 #E DOSB - Verbesserte Bedienbarkeit direktes Einladen');

    $user = $I->haveDOSBUser();
    $title = 'Test280.08-' . time();
    $group = $I->createGroup($user, ['title' => $title]);
    $I->completedSetup();

    $I->loginAsUser($user);
    $I->checkAK('O280.08', 'AK 1: Dies soll beim Einladen unter https://bildungsnetz.dosb.de/organisation/invite gelten.');
    $I->amOnPage("/organisation/invite");

    $I->checkAK('O280.08', 'AK 3: Auswahl bzw. Übersicht bleibt erhalten, kann jedoch eben optional gefiltert werden.');
    $I->seeElement('#organisation_select_chosen');
    //$I->see(['css' => '#organisation-select']);
    $I->click('#organisation_select_chosen');
    $I->seeElement('.chosen-search');

    $I->checkAK('O280.08', 'AK 2: Es gibt eine Filtermöglichkeit bzw. Vorschläge nach Textausschnitten (technisch "enthält Zeichenketten" ).');
    $I->fillField('.chosen-search input', 'thinker');
    $I->see('Ghostthinker', '.chosen-results');

    $I->checkAK('O280.08', 'AK 2.1: Auf Groß / Kleinschreibung wird nicht geachtet (technisch "nicht case-sensitive").');
    $I->fillField('.chosen-search input', 'ghostthinker');
    $I->see('Ghostthinker', '.chosen-results');

    $I->checkAK('O280.08', 'AK 1.1: Zudem beim Einladen von neuen Personen in Gruppen (DOSB + Admins)');
    $I->amOnPage("/groups/" . $group->nid . "/people/invite");
    $I->seeElement('#organisation_select_chosen');
  }

  /**
   * Access check Personen einladen
   * wegen:
   * 290.01 #CR Eingeschränkte Weitergabe der Lizenzrechte
   * 260.02 LV - Lizenzen - API-Zugriff anfordern
   *
   * @param \AcceptanceTester $I
   */
  public function O_03_1_access_check_invite_users(AcceptanceTester $I) {

    $I->wantTo('O2xx - Access check invite users');

    $USER_DOSB = $I->haveUser([
      'role_dosb' => TRUE,
      'role_lizenzmanager' => TRUE,
    ]);
    //dosb user and in the og as lv
    $USER_DOSB2 = $I->haveDOSBUser();

    $USER_LICENSEMANAGER = $I->haveUser([]);
    $USER_TRAINER = $I->haveUser([]);

    $USER_NOT_IN_ORGANISATION = $I->haveUser();
    $USER_NOT_LICENSEMANAGER = $I->haveUser();

    $DV = $I->haveOrganisation('Dummy OG');
    $UV = $I->haveOrganisation('Dummy UG', ['parent' => $DV]);

    $I->addMemberToOrganisation($USER_LICENSEMANAGER, $DV, [SALTO_ROLE_LICENSE_MANAGER_RID]);
    $I->addMemberToOrganisation($USER_TRAINER, $DV, [SALTO_OG_ROLE_TRAINER_RID]);
    $I->addMemberToOrganisation($USER_DOSB2, $DV, [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);
    $I->addMemberToOrganisation($USER_NOT_LICENSEMANAGER, $DV);

    $ALLOWED_USERS_DV = [$USER_DOSB, $USER_TRAINER, $USER_LICENSEMANAGER, $USER_DOSB2];
    $ALLOWED_USERS_UV = [$USER_TRAINER, $USER_LICENSEMANAGER, $USER_DOSB2];
    $PROHIBITED_USERS = [$USER_NOT_IN_ORGANISATION, $USER_NOT_LICENSEMANAGER];

    $I->completedSetup();

    $I->expectTo("USER_NOT_IN_ORGANISATION, USER_NOT_LICENSEMANAGER see not the form");

    //prohibited users check
    $ogs = [$DV, $UV];
    foreach ($ogs as $og) {
      foreach ($PROHIBITED_USERS as $account) {
        $I->loginAsUser($account);
        $I->amOnPage("/node/" . $og->nid);
        $I->dontSee("Personen einladen");

        $I->amOnPage("/organisations/" . $og->nid . "/invite");
        $I->getAccessDenied();
      }
    }

    $I->expectTo("USER_DOSB, USER_LICENSEMANAGER, USER_TRAINER see the form");
    foreach ($ALLOWED_USERS_DV as $idx => $account) {
      $I->loginAsUser($account);
      $I->amOnPage("/node/" . $DV->nid);
      $I->click("Personen einladen");

      $I->waitForText("Alle Einladungen");
      $I->click('#edubreak_og_ui_searchlist #invite-by-account-button');
      if ($idx == 0) {
        //$I->waitForText('Lizenzen pflegen');
      }
      if ($idx == 2) {
        $I->wait(1);
        $I->dontSee('Organisation verwalten');
        $I->dontSee('Lizenzen pflegen');
      } else {
        $I->waitForText('Organisation verwalten');
      }
    }

    $I->expectTo("USER_LICENSEMANAGER, USER_TRAINER see the form in UG");
    foreach ($ALLOWED_USERS_UV as $idx => $account) {
      $I->loginAsUser($account);
      $I->amOnPage("/node/" . $UV->nid);
      $I->click("Personen einladen");

      $I->waitForText("Alle Einladungen");
      $I->click('#edubreak_og_ui_searchlist #invite-by-account-button');
      if ($idx == 2) {
        //$I->waitForText('Lizenzen pflegen');
      }
      if ($idx == 1) {
        $I->wait(1);
        $I->dontSee('Organisation verwalten');
        //$I->see('Lizenzen pflegen');
      } else {
        $I->waitForText('Organisation verwalten');
      }
    }

    //allowed dosb user check
    $I->expectTo("USER_DOSB dont see the form in UG");
    $I->loginAsUser($USER_DOSB);
    $I->amOnPage("/node/" . $UV->nid);
    $I->click("Personen einladen");

    $I->waitForText("Alle Einladungen");
    $I->click('#edubreak_og_ui_searchlist #invite-by-account-button');
    $I->waitForText('Organisation verwalten');
    $I->dontSee('Lizenzen pflegen');

  }

  /**
   * 150.13 Organisation-Manager - Organisation - Eigene Untergliederung löschen
   * @UserStory 150.13 - https://trello.com/c/Bhp3Ldc1/399-15013-organisation-manager-organisation-eigene-untergliederung-l%C3%B6schen
   * @param \AcceptanceTester $I
   */
  public function O_04_0_delete_suborganisation(AcceptanceTester $I) {

    $I->wantTo('150.13 Organisation-Manager - Organisation - Eigene Untergliederung löschen');

    $user = $I->haveUser([
      'firstname' => 'john',
      'lastname' => 'doe',
    ]);

    $userMA = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'manager',
    ]);

    $userLM = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'license',
    ]);

    $og = $I->haveOrganisation('TestSV', [
        'body' => 'dummy sv og',
        'earemotes' => [],
        'obscure' => 0,
        'dv_license_settings' => 'full', //none/read/full
        'parent' => null,
        'language' => 'en'
      ]
    );

    $og1 = $I->haveOrganisation('TestVerband', [
        'body' => 'dummy verband og',
        'earemotes' => [],
        'obscure' => 0,
        'dv_license_settings' => 'full', //none/read/full
        'parent' => $og,
        'language' => 'en'
      ]
    );

    $og2 = $I->haveOrganisation('TestVerbandUV', [
        'body' => 'dummy verband uv og',
        'earemotes' => [],
        'obscure' => 0,
        'dv_license_settings' => 'full', //none/read/full
        'parent' => $og1,
        'language' => 'en'
      ]
    );
    $I->addMemberToOrganisation($userMA, $og, [SALTO_OG_ROLE_TRAINER_RID]);
    $I->addMemberToOrganisation($userLM, $og, [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);
    $I->addMemberToOrganisation($userLM, $og1, [SALTO_OG_ROLE_TRAINER_RID]);
    $I->addMemberToOrganisation($userLM, $og2, [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);

    $I->completedSetup();
    $I->checkAK('150.13', 'AK 1.1: Nur für Mitglieder mit "Haus" der Dachorganisation');

    $I->expect('Normale User haben keinen Zugriff.');
    $I->loginAsUser($user);
    $I->amOnPage("/node/" . $og2->nid .'/edit');
    $I->dontSee('Löschen');
    $I->getAccessDenied();

    $I->expect('Member haben keinen Zugriff.');
    $I->addMemberToOrganisation($user, $og1, []);
    $I->addMemberToOrganisation($user, $og2, []);
    $user = user_load($user->uid);

    $I->amOnPage("/node/" . $og2->nid .'/edit');
    $I->dontSee('Löschen');
    $I->getAccessDenied();

    $I->checkAK('150.13', 'AK 1: Unter "Organisation bearbeiten" gibt es neben "Speichern" einen zusätzlichen orangenen Menu-Button "Löschen" (analog zu Lehrgänge)');
    $I->loginAsUser($userLM);
    $I->amOnPage("/node/" . $og2->nid .'/edit');
    $I->see('Speichern');
    $I->see('Löschen');
    $I->notAccessDenied();

    $I->click('Löschen');

    $I->checkAK('150.13', 'AK 2: Riesiger Warnhinweis "WARNUNG: Sind sie wirklich sicher, dass Sie diese ...');
    $I->see('WARNUNG');

    $I->checkAK('150.13', 'AK 5: Bei der Bestätigung des Löschens lautet der Breadcrumb "Organisation löschen?" am Ende (ansonsten analog zu Bearbeiten)');
    $I->see('Organisation löschen?', '.breadcrumb');
    $I->see($og2->title, '.breadcrumb');
    $I->see('Organisationen', '.breadcrumb');
    $I->see('Personen', '.breadcrumb');

    $I->see('Abbrechen');
    $I->see('Löschen');
    $I->click('Löschen');

    $I->waitForText('Die Organisation ' . $og2->title . ' wurde erfolgreich gelöscht!');

    $I->amOnPage("/node/" . $og2->nid);
    $I->see('Leider ist der Inhalt nicht verfügbar');

    $I->loginAsUser($userMA);
    $I->amOnPage("/node/" . $og1->nid .'/edit');
    $I->see('Löschen');
    $I->click('Löschen');

    $I->expect('Lösche direkte Untergliederung des Dach-/Spitzenverbandes');
    $I->see('Abbrechen');
    $I->see('Löschen');
    $I->click('Löschen');

    $I->waitForText('Die Organisation ' . $og1->title . ' wurde erfolgreich gelöscht!');

    $I->amOnPage("/node/" . $og1->nid);
    $I->see('Leider ist der Inhalt nicht verfügbar');

    $I->checkAK('150.13', 'AK 4: Die Mitglieder der gelöschten Organisation werden (sofern sie keiner anderen Organisation angehören) automatisch in die Auffangorganisation verschoben');
    //$I->userIsInFallbackOG($user);

  }

}
