<?php

use Helper\Wissensnetz;

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
  public function _before(AcceptanceTester $I) {
  }

  public function _after(AcceptanceTester $I) {}

  /**
   * 150.13 Organisation-Manager - Organisation - Eigene Untergliederung löschen
   * @UserStory 150.13 - https://trello.com/c/Bhp3Ldc1/399-15013-organisation-manager-organisation-eigene-untergliederung-l%C3%B6schen
   * @param \AcceptanceTester $I
   */
  public function O_01_0_delete_suborganisation(AcceptanceTester $I) {

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

    $og = $I->createOrganisation('TestSV', [
        'body' => 'dummy sv og',
        'earemotes' => [],
        'obscure' => 0,
        'dv_license_settings' => 'full', //none/read/full
        'parent' => null,
        'language' => 'en'
      ]
    );

    $og1 = $I->createOrganisation('TestVerband', [
        'body' => 'dummy verband og',
        'earemotes' => [],
        'obscure' => 0,
        'dv_license_settings' => 'full', //none/read/full
        'parent' => $og,
        'language' => 'en'
      ]
    );

    $og2 = $I->createOrganisation('TestVerbandUV', [
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
    $I->see('Bitte beachten Sie, dass die');

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


  public function O_02_0_Organisation_custom_form_fields_and_filters(AcceptanceTester $I) {

    $I->wantTo('check if custom organisation form fields and filters are shown and hidden correctly');
    variable_set('salto_admin_ip_enabled', FALSE);

    $admin = $I->haveAdmin();

    $userLM = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'license',
    ]);

    $og = $I->createOrganisation('TestSV', [
        'body' => 'dummy sv og',
        'earemotes' => [],
        'obscure' => 0,
        'dv_license_settings' => 'full', //none/read/full
        'parent' => null,
        'language' => 'en'
      ]
    );

    $I->addMemberToOrganisation($userLM, $og, [SALTO_OG_ROLE_LICENSE_MANAGER_RID]);

    $I->completedSetup();

    $I->expect('that as admin i can set default values to organisation');
    $I->loginAsUser($admin);
    $I->amOnPage('/admin/config/salto/organisation');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_parent][filter_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_parent][form_field_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_category][form_field_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_category][filter_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_bundesland][form_field_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_bundesland][filter_enabled]"]');
    $I->uncheckOption('form input[name="organisation_custom_fields[field_org_plz][form_field_enabled]"]');
    $I->uncheckOption('form input[name="organisation_custom_fields[field_org_plz][filter_enabled]"]');
    $I->uncheckOption('form input[name="organisation_custom_fields[field_organisation_sportkreis][form_field_enabled]"]');
    $I->uncheckOption('form input[name="organisation_custom_fields[field_organisation_sportkreis][filter_enabled]"]');
    $I->click('Konfiguration speichern');

    $I->expect('that all default fields and filters are shown');
    $I->loginAsUser($userLM);
    $I->amOnPage("/node/" . $og->nid .'/edit');
    $I->see('Verbändegruppe');
    $I->see('Bundesland');
    $I->dontSee('PLZ');
    $I->dontSee('Sportkreis');

    $I->fillField('title', "My new Organisation");
    $I->click('Speichern');
    $I->amOnPage('organisations');
    $I->see('Verbändegruppe');
    $I->see('Bundesland');
    $I->dontSee('PLZ');
    $I->dontSee('Sportkreis');

    $I->expect('that as admin i can set custom values to fields and filter in organisation');
    $I->loginAsUser($admin);
    $I->amOnPage('/admin/config/salto/organisation');
    $I->fillField('organisation_custom_fields[field_organisation_sportkreis_options]', 'Holzbein Kiel
FC Süderbrarup and Friends');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_parent][filter_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_parent][form_field_enabled]"]');
    $I->uncheckOption('form input[name="organisation_custom_fields[field_organisation_category][form_field_enabled]"]');
    $I->uncheckOption('form input[name="organisation_custom_fields[field_organisation_category][filter_enabled]"]');
    $I->uncheckOption('form input[name="organisation_custom_fields[field_organisation_bundesland][form_field_enabled]"]');
    $I->uncheckOption('form input[name="organisation_custom_fields[field_organisation_bundesland][filter_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_org_plz][form_field_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_org_plz][filter_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_sportkreis][form_field_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_sportkreis][filter_enabled]"]');
    $I->click('Konfiguration speichern');

    $I->expect('that all custom fields and filters are shown');
    $I->loginAsUser($userLM);
    $I->amOnPage("/node/" . $og->nid .'/edit');
    $I->dontSee('Verbändegruppe');
    $I->dontSee('Bundesland');
    $I->see('PLZ');
    $I->see('Sportkreis');

    $I->fillField('title', "My new Organisation");
    $I->click('Speichern');
    $I->amOnPage('organisations');
    $I->dontSee('Verbändegruppe');
    $I->dontSee('Bundesland');
    $I->see('PLZ');
    $I->see('Sportkreis');

    //reset to normal config
    $I->loginAsUser($admin);
    $I->amOnPage('/admin/config/salto/organisation');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_parent][filter_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_parent][form_field_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_category][form_field_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_category][filter_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_bundesland][form_field_enabled]"]');
    $I->checkOption('form input[name="organisation_custom_fields[field_organisation_bundesland][filter_enabled]"]');
    $I->uncheckOption('form input[name="organisation_custom_fields[field_org_plz][form_field_enabled]"]');
    $I->uncheckOption('form input[name="organisation_custom_fields[field_org_plz][filter_enabled]"]');
    $I->uncheckOption('form input[name="organisation_custom_fields[field_organisation_sportkreis][form_field_enabled]"]');
    $I->uncheckOption('form input[name="organisation_custom_fields[field_organisation_sportkreis][filter_enabled]"]');
    $I->click('Konfiguration speichern');
  }

}
