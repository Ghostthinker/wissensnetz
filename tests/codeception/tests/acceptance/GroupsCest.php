<?php

use Helper\Wissensnetz;

/**
 * Class GroupsCest
 *
 */
class GroupsCest {

  /**
   * Always create this entities before every course
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {  }

  public function _after(AcceptanceTester $I) {
    //cleanup is done in EdubreakHelper
  }

  /**
   * G260.14 #CR Gruppen - Gruppeneinladungen
   *
   * @UserStory 260.14 https://trello.com/c/y5FH36fi/974-26014-cr-gruppen-gruppeneinladungen
   * @param \AcceptanceTester $I
   */
  public function G_01_0_create_group_and_invite(AcceptanceTester $I) {

    $I->wantTo('G260.14 - #CR Gruppen - Gruppeneinladungen');

    $user1 = $I->haveUser([
      'firstname' => 'Inviter',
      'lastname' => microtime(true),
      'role_dosb' => TRUE,
    ]);

    $user2 = $I->haveUser([
      'firstname' => 'GroupieChecker',
      'lastname' => microtime(true),
    ]);

    $I->completedSetup();

    $I->loginAsUser($user1);

    // Gruppe 1
    $I->expect('Founding a group (first)');
    $I->amOnPage("/groups");
    $I->click('Gruppe gründen');
    $I->checkFirstCategory();
    $title1 = 'Gruppe1 G260_14' . microtime(true);
    $I->submitForm('#group-node-form', [
      'title' => $title1,
    ]);
    $I->see($title1);
    $I->click($title1, '.main_layout_right');
    $I->click('Personen einladen', '.main_layout_right');

    $I->waitForElement('.search-query.edubreak-users-selector-processed');
    $I->fillField('.search-query.edubreak-users-selector-processed', $user2->realname);
    $I->wait(3);
    //$I->click('Hinzufügen');
    $I->click('#edubreak_og_ui_searchlist .btn-add.edubreak-users-selector-processed');
    $I->click('Personen einladen');

    // Gruppe 2
    $I->expect('Founding a group (second)');
    $I->amOnPage("/groups");
    $I->click('Gruppe gründen');
    $I->checkFirstCategory();
    $title2 = 'Gruppe2 G260_14' . microtime(true);
    $I->submitForm('#group-node-form', [
      'title' => $title2,
    ]);
    $I->see($title2);
    $I->click($title2, '.main_layout_right');
    $I->click('Personen einladen', '.main_layout_right');

    $I->waitForElement('.search-query.edubreak-users-selector-processed');
    $I->fillField('.search-query.edubreak-users-selector-processed', $user2->realname);
    $I->wait(3);
    //$I->click('Hinzufügen');
    $I->click('#edubreak_og_ui_searchlist .btn-add.edubreak-users-selector-processed');
    $I->click('Personen einladen');

    // Gruppe 3
    $I->expect('Founding a group (third)');
    $I->amOnPage("/groups");
    $I->click('Gruppe gründen');
    $I->checkFirstCategory();
    $title3 = 'Gruppe3 G260_14' . microtime(true);
    $I->submitForm('#group-node-form', [
      'title' => $title3,
    ]);
    $I->see($title3);
    $I->click($title3, '.main_layout_right');
    $I->click('Personen einladen', '.main_layout_right');

    $I->waitForElement('.search-query.edubreak-users-selector-processed');
    $I->fillField('.search-query.edubreak-users-selector-processed', $user2->realname);
    $I->wait(3);
    //$I->click('Hinzufügen');
    $I->click('#edubreak_og_ui_searchlist .btn-add.edubreak-users-selector-processed');
    $I->click('Personen einladen');

    $I->loginAsUser($user2);
    $I->checkAK('260.14', 'AK 1: Offene Einladungen werden direkt auf der Startseite prominent angezeigt (zwischen Navigation und Inhalt)');
    $I->amOnPage("/");
    $I->see('Sie wurden in die Gruppen ' . $title1 . ', ' . $title2 . ' und ' . $title3 . ' eingeladen.');
    $I->see('Durch Klick auf den Gruppennamen können Sie die Einladung annehmen oder ablehnen.');

    $I->checkAK('260.14', 'AK 1.1: Gruppen sind verlinkt und zeigen direkt auf die Annahme / Ablehnung der Einladung (analog zu den On-Site-Benachrichtigungen).');
    $I->click($title1);
    $I->see('Annehmen');
    $I->see('Ablehnen');
    $I->click('Ablehnen');
    $I->see('Sie haben die Mitgliedschaft zu ' . $title1 . ' abgewiesen!');

    $I->checkAK('260.14', 'AK 2: Die Anzeige verschwindet erst, wenn man die Einladung angenommen oder abgelehnt hat.');
    $I->amOnPage("/");
    $I->dontSee('Sie wurden in die Gruppen ' . $title1 . ', ' . $title2 . ' und ' . $title3 . ' eingeladen.');
    $I->see('Sie wurden in die Gruppen ' . $title2 . ' und ' . $title3 . ' eingeladen.');
    $I->see('Durch Klick auf den Gruppennamen können Sie die Einladung annehmen oder ablehnen.');
    $I->click($title2);
    $I->see('Annehmen');
    $I->click('Annehmen');

    $I->amOnPage("/");
    $I->dontSee('Sie wurden in die Gruppe ' . $title2 . ' und ' . $title3 . ' eingeladen.');
    $I->see('Sie wurden in die Gruppe ' . $title3 . ' eingeladen.');
    $I->see('Durch Klick auf den Gruppennamen können Sie die Einladung annehmen oder ablehnen.');
    $I->click($title3);
    $I->see('Annehmen');
    $I->click('Annehmen');

    $I->amOnPage("/");
    $I->dontSee('Sie wurden in die Gruppen ' . $title1 . ', ' . $title2 . ' und ' . $title3 . ' eingeladen.');
    $I->dontSee('Sie wurden in die Gruppen ' . $title2 . ' und ' . $title3 . ' eingeladen.');
    $I->dontSee('Sie wurden in die Gruppe ' . $title3 . ' eingeladen.');
    $I->dontSee('Durch Klick auf den Gruppennamen können Sie die Einladung annehmen oder ablehnen.');

    //clean user for mistaken identity in invite form
    $I->deleteUser($user2);
    $I->deleteUser($user1);
  }


  /**
   * 260.13 Gruppen-ManagerIn - Gruppen - Organisationsstruktur von Beiträgen & Dateien
   *
   *
   * @UserStory 260.13 https://trello.com/c/cbdIagwh/642-26013-gruppen-managerin-gruppen-organisationsstruktur-von-beitr%C3%A4gen-dateien
   *
   * @example { "file": "images/150524-19-50.jpg", "type": "image", "mime":"image/jpeg" }
   *
   * @param \AcceptanceTester $I
   */

  public function G_02_0_groups_file_upload(AcceptanceTester $I,  \Codeception\Example $example) {
    $I->wantTo('Gruppen-ManagerIn - Gruppen - Organisationsstruktur von Beiträgen & Dateien');

    //gruppenbenutzer
    $GROUPMANAGER = $I->haveUser([
      'firstname' => 'Inviter',
      'lastname' => microtime(true),
    ]);

    $I->loginAsUser($GROUPMANAGER);

    // Gruppe 1
    $I->expect('Founding a new group');
    $I->amOnPage("/groups");
    $I->click('Gruppe gründen');
    $I->checkFirstCategory();
    $title = 'Gruppe G260_14' . microtime(true);
    $I->submitForm('#group-node-form', [
      'title' => $title,
    ]);


    $I->completedSetup();

    $I->amOnPage("/groups");
    $I->see($title);
    $I->click($title, '.main_layout_right');

    $I->checkAK("260.13", "AK 1: Über \"Struktur verwalten\" kann ich mir in meiner Gruppe eine eigene Ordnerstruktur anlegen.");
    $I->checkAK("260.13", "AK 1.1: analog zu aktuell \"Themenfelder verwalten\" in Beiträge");

    $I->click("Struktur verwalten", '.main_layout_right');


    //breadcrumb
    $I->see(t("Manage categories"));
    //manage post structure
    $I->see("Beiträge");
    //manage materials structure
    $I->see("Materialien");

    //add new taxonomy terms
    //post
    //switch to iframe
    $I->switchToIframe("group-structure-posts");
    $I->click("Neues Element");
    $I->fillfield('name', 'Beitrags-Kategorie');
    $I->click("Speichern");

    //switch to iframe
    $I->switchToIframe("group-structure-materials");
    $I->click("Neues Element");
    $I->fillfield('name', 'Materialien-Kategorie');
    $I->click("Speichern");

    //get back to group via breadcrumb
    $I->click($title);

    //check if we see the new menu items
    $I->see("Beitrags-Kategorie");
    $I->see("Materialien-Kategorie");


    $I->checkAK("260.13", "AK 3: Beim Einstellen einer Datei in einer Gruppe wird man gefragt, wo diese einsortiert werden soll (analog zu Beiträge in Gruppe)");
    $I->checkAK("260.13", "AK 4: Beim Erstellen eines Beitrages soll \"Kategorie (Gruppe) = Struktur (Gruppe)\"");

    $I->click("Datei einstellen", '.main_layout_right');
    $I->attachFile('input[type="file"]', $example['file']);


    $I->click("Weiter");

    $image_name = "Ein schönes Testbild";
    $title_id = 'edit-field-file-image-title-text-und-0-value';
    $I->waitForElement('#' . $title_id);
    $I->fillField('//*[@id="'.$title_id.'"]', $image_name);

    $option = $I->grabTextFrom('#edit-og-vocabulary select option:nth-child(2)');
    $I->selectOption('#edit-og-vocabulary select', $option);


    $I->click('Speichern');
    $I->see($image_name);

  }

  public function G_03_0_create_and_delete_group_categories(AcceptanceTester $I) {
    $I->wantTo('Gruppen-ManagerIn - Gruppen - Organisationsstruktur von Beiträgen & Dateien');

    //gruppenbenutzer
    $GROUPMANAGER = $I->haveUser([
      'firstname' => 'Founder',
      'lastname' => microtime(true),
    ]);

    $I->loginAsUser($GROUPMANAGER);

    // Gruppe 1
    $I->expect('Founding a new group');
    $I->amOnPage("/groups");
    $I->click('Gruppe gründen');
    $I->checkFirstCategory();
    $title = 'Gruppe G260_14_delete_element' . microtime(true);
    $I->submitForm('#group-node-form', ['title' => $title,]);


    $I->completedSetup();

    $I->amOnPage("/groups");
    $I->see($title);
    $I->click($title, '.main_layout_right');

    $I->click("Struktur verwalten", '.main_layout_right');

    //breadcrumb
    $I->see(t("Manage categories"));
    //manage post structure
    $I->see("Beiträge");
    //manage materials structure
    $I->see("Materialien");

    //add new taxonomy terms
    //post
    //switch to iframe
    $I->switchToIframe("group-structure-posts");
    $I->click("Neues Element");
    $I->fillfield('name', 'Beitrags-Kategorie');
    $I->click("Speichern");

    //check if we see the new menu items
    $I->see("Beitrags-Kategorie");
    $I->switchToIframe("group-structure-posts");
    $I->see("Löschen");
    $I->click("Löschen");

    $I->see('Löschen der Kategorie "Beitrags-Kategorie" bestätigen!');
    $I->see('Kategorie löschen');
    $I->click('Kategorie löschen');
    $I->wait(1);
    $I->dontSee("Beitrags-Kategorie");
  }


  /**
   * 310.09 #CR BenutzerIn - Gruppen - Gruppenmitglieder sortieren
   *
   * @UserStory 310.09 https://trello.com/c/jLNwSmrD/1041-31009-benutzerin-gruppen-gruppenmitglieder-sortieren
   * @Task https://trello.com/c/jLNwSmrD/1041-31009-benutzerin-gruppen-gruppenmitglieder-sortieren
   *
   * @param \AcceptanceTester $I
   */

  public function G_04_0_sort_group_members(AcceptanceTester $I) {
    $I->wantTo('310.09 BenutzerIn - Gruppen - Gruppenmitglieder sortieren');

    $microTime = microtime(TRUE);

    //gruppenbenutzer
    $U1 = $I->haveUser([
      'firstname' => 'daxi',
      'lastname' => 'rebmem',
    ]);

    //gruppenbenutzer
    $U2 = $I->haveUser([
      'firstname' => 'maxi',
      'lastname' => 'member',
    ]);

    $og1 = $I->createOrganisation('TestOG');
    $og2 = $I->createOrganisation('TestOG2');

    $I->addMemberToOrganisation($U1, $og1, [SALTO_OG_ROLE_MANAGER_RID]);
    $I->addMemberToOrganisation($U2, $og2, [SALTO_OG_ROLE_MANAGER_RID]);

    $I->loginAsUser($U1);

    // Gruppe 1
    $I->expect('Founding a new group');
    $I->amOnPage('node/add/group');

    $I->checkFirstCategory();
    $title = 'Group G310-' . $microTime;
    $I->submitForm('#group-node-form', ['title' => $title,]);
    $I->see($title);
    $gid1 = $I->grabFromCurrentUrl('/node\/(\d+)/');

    $I->addMemberToGroup($U1, $gid1);
    $I->addMemberToGroup($U2, $gid1);

    $I->completedSetup();

    $I->checkAK('310.09', 'AK 1: Übernahme der Sortierfunktion aus "Personen"');
    $I->amOnPage('/groups/' . $gid1 . '/people');

    $I->checkAK('310.09', 'AK 2: Sortierbarkeit nach');
    $I->see("Sortieren nach");
    $I->seeElement('#edit-sort-by');
    $I->seeElement('#edit-sort-order');

    $I->checkAK('310.09', 'AK 2.1: Name');
    $I->click('#edit-sort-by');
    $I->see("Nachname");
    $I->selectOption('form select[name=sort_by]', 'Nachname');
    $I->click('Anwenden');
    $I->see($U2->realname, '.views-row-1');
    $I->see($U1->realname, '.views-row-2');

    $I->checkAK('310.09', 'AK 2.2: Vorname');
    $I->click('#edit-sort-by');
    $I->see("Vorname");
    $I->selectOption('form select[name=sort_by]', 'Vorname');
    $I->click('Anwenden');
    $I->see($U1->realname, '.views-row-1');
    $I->see($U2->realname, '.views-row-2');

    $I->checkAK('310.09', 'AK 2.3: Mitgliedsorganisation');
    $I->click('#edit-sort-by');
    $I->see("Mitgliedsorganisation");
    $I->selectOption('form select[name=sort_by]', 'Mitgliedsorganisation');
    $I->click('Anwenden');
    $I->see($U1->realname, '.views-row-1');
    $I->see($U2->realname, '.views-row-2');

    $I->click('#edit-sort-order');
    $I->selectOption('form select[name=sort_order]', 'Absteigend');
    $I->click('Anwenden');
    $I->see($U2->realname, '.views-row-1');
    $I->see($U1->realname, '.views-row-2');

  }

    public function G_05_0_delete_group(AcceptanceTester $I) {
        $I->wantTo('310.09 BenutzerIn - Gruppen - Gruppe löschen');

        //gruppenbenutzer
        $user = $I->haveUser([
          'firstname' => 'daxi',
          'lastname' => 'rebmem',
        ]);

        $group = \Helper\Wissensnetz::createGroup($user);

        $I->addMemberToGroup($user, $group->nid);

        $I->loginAsUser($user);
        $I->amOnPage('/node/' . $group->nid . '/edit');
        $I->checkFirstCategory();
        $I->click("Löschen");
        $I->click("Löschen");
        $I->see('Gruppe ' . $group->title . ' wurde gelöscht.');

    }

  /**
   * 260.13 Gruppen-ManagerIn - Gruppen - Organisationsstruktur von Beiträgen & Dateien
   *
   *
   * @UserStory 260.13 https://trello.com/c/cbdIagwh/642-26013-gruppen-managerin-gruppen-organisationsstruktur-von-beitr%C3%A4gen-dateien
   *
   * @example { "file": "images/150524-19-50.jpg", "type": "image", "mime":"image/jpeg" }
   *
   * @param \AcceptanceTester $I
   */

  public function G_06_0_group_member_view(AcceptanceTester $I,  \Codeception\Example $example) {
    $I->wantTo('check that group members are correctly shown on group overview page');

    //gruppenbenutzer
    $GROUPMANAGER = $I->haveUser([
      'firstname' => 'Inviter',
      'lastname' => microtime(true),
    ]);

    $I->loginAsUser($GROUPMANAGER);
    $I->amOnPage('/user/' . $GROUPMANAGER->uid . '/edit/main?destination=user/' . $GROUPMANAGER->uid . '#');
    $I->attachFile('//input[@name="files[profile_main_field_user_picture_und_0]"]', 'images/default_user.jpg');

    $I->executeJS("return document.querySelector('#edit-profile-main-field-profile-categories-und .form-checkbox').click()");

    $I->click('Speichern');


    $group = \Helper\Wissensnetz::createGroup($GROUPMANAGER);


    for ($i=0; $i<5; $i++){
      $USER = $I->haveUser([
        'firstname' => 'maximilian' . $i,
        'lastname' => 'mustermann',
      ]);

      $I->addMemberToGroup($USER, $group);

      $I->loginAsUser($USER);
      $I->amOnPage('/user/' . $USER->uid . '/edit/main?destination=user/' . $USER->uid . '#');
      $I->attachFile('//input[@name="files[profile_main_field_user_picture_und_0]"]', 'images/default_user.jpg');

      $I->executeJS("return document.querySelector('#edit-profile-main-field-profile-categories-und .form-checkbox').click()");

      $I->click('Speichern');
    }

    for($i=0; $i<12;$i++){
      $I->haveMaterial([
        'user' => $GROUPMANAGER,
        'group' => $group,
        'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
        'editAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      ]);
    }

    $I->loginAsUser($GROUPMANAGER);

    for($i=0; $i<4;$i++){
      $I->createGroupBeitrag([
        'Titel' => 'Beitrag_' . $i,
        'Inhalt' => "body",
        'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
        'user' => $GROUPMANAGER
      ],$group->nid);
    }


    $I->completedSetup();

    $I->amOnPage('/node/' . $group->nid . '/edit');
    $I->checkFirstCategory();
    $I->click('Speichern');

    $I->amOnPage("groups");

    $I->fillField('title', $group->title);
    $I->selectOption('form select[name=field_group_themenfelder_tid]', 'All');
    $I->click('#edit-submit-groups');

    $I->expect('to see all new group node view details');
    $I->see('4 Beiträge');
    $I->see('12 Dateien');
    $I->see('6 Mitglieder');
    $I->see('+ 3');

  }

}
