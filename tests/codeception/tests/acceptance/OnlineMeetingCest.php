<?php

use Helper\Bildungsnetz;

class OnlineMeetingCest {

  /**
   * Always create this entities before every course
   *
   * @param \AcceptanceTester $I
   */
  public function _before(UnitTester $I) {
    variable_set('online_meeting_enabled', TRUE);
  }

  public function _after(UnitTester $I) {
    variable_set('online_meeting_enabled', FALSE);
  }

  /**
   * @param \AcceptanceTester $I
   */
  public function OM_01_0_group_page_check_menu(AcceptanceTester $I) {

    $I->wantTo('To see a "Online-Treffen" menu point on a group page');

    $upcomingPaneClass = '.pane-group-online-meetings-panel-pane-1';
    $recurringPaneClass = '.pane-group-online-meetings-panel-pane-3';
    $passedPaneClass = '.pane-group-online-meetings-panel-pane-2';

    $og = $I->haveOrganisation('OnlineMeetingOrganisation_1', [
        'body' => 'OnlineMeetingOrganisation_1',
        'parent' => null,
        'language' => 'en'
      ]
    );
    $user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'meeting',
    ]);

    $group = $I->createGroup($user);
    $I->addMemberToGroup($user, $group->nid);
    $I->addMemberToOrganisation($user, $og, array(SALTO_OG_ROLE_MANAGER_RID));

    //past event
    for($i = 1; $i <= 11; $i++){
      $I->haveOnlineMeeting([
        'user' => $user,
        'title' => 'past meeting'.$i,
        'group' => $group,
        'startDate' => strtotime('now - '.($i+1).' hours'),
        'endDate' => strtotime('now - '.$i.' hour'),
      ]);
    }
    //upcoming
    for($i = 1; $i <= 11; $i++){
      $I->haveOnlineMeeting([
        'user' => $user,
        'title' => 'upcoming meeting'.$i,
        'group' => $group,
        'startDate' => strtotime('now +'.$i.' hours'),
        'endDate' => strtotime('now + '.($i+1).' hours'),
      ]);
    }
    //recurring
    for($i = 1; $i <= 11; $i++){
      $I->haveOnlineMeeting([
        'user' => $user,
        'title' => 'recurring meeting'.$i,
        'group' => $group,
        'recurring_meeting' => 1
      ]);
    }

    $I->completedSetup();

    $I->loginAsUser($user);

    $I->checkAK('01.09e', 'AK 1: Es gibt einen neuen Bereich "Online-Treffen" in Gruppen mit entsprechenden Menüpunkt unter “Dateien”.');

    $I->amOnPage('groups/'.$group->nid.'/online-meetings/status');

    $I->checkAK('01.09e', 'AK 1.1: Hier sind jeweils bis zu drei Meetings nach Anstehend, Wiederkehrend und Vergangene gruppiert.');
    $I->checkAK('01.09e', 'AK 4: In der Übersicht (Main-Content) werden die Online-Treffen als Karten angezeigt (siehe Bildschirmentwurf)');

    $I->see('Online-Treffen', '.main_layout_left .pane-content');

    $I->seeNumberOfElements($upcomingPaneClass.' article.node-online-meeting', 3);
    $I->seeNumberOfElements($passedPaneClass.' article.node-online-meeting', 3);
    $I->seeNumberOfElements($recurringPaneClass.' article.node-online-meeting', 3);

    $I->checkAK('01.09e', 'AK 1.2: Die Sortierung ist nach Startdatum und zwar das nächste Online-Treffen als erstes…');

    for($i = 1; $i <= 3; $i++){
      $I->see('past meeting'.$i, $passedPaneClass.' .view-content .views-row:nth-child('.$i.')');
    }
    for($i = 1; $i <= 3; $i++){
      $I->see('upcoming meeting'.$i, $upcomingPaneClass.' .view-content .views-row:nth-child('.$i.')');
    }

    $I->checkAK('01.09e', 'AK 2: Es gibt für Anstehende, Wiederkehrende und Vergangene auch Unterbereiche links. Dort werden dann alle passenden Online-Treffen angezeigt.');

    $I->see('Anstehende', '.main_layout_left .pane-content');
    $I->see('Wiederkehrend', '.main_layout_left .pane-content');
    $I->see('Vergangene', '.main_layout_left .pane-content');

    $I->checkAK('01.09e', 'AK 2.1: Sortierung chronologisch absteigend (neueste zuerst)');
    $I->checkAK('01.09e', 'AK 2.2: 10 Online-Treffen pro Seite, entsprechender Pager ');

    $I->click('Anstehende', '.main_layout_left .pane-content');
    for($i = 1; $i <= 10; $i++){
      $I->see('upcoming meeting'.$i, $upcomingPaneClass.' .view-content .views-row:nth-child('.$i.')');
    }
    $I->seeNumberOfElements('.view-group-online-meetings .views-row', 10);
    $I->seeElement('.pagination');
    $I->seeNumberOfElements('ul.pagination li', 4);//Meeting Pages + Next/Last Page
    $I->click('2', '.pagination');
    $I->waitForJS("return jQuery.active == 0;", 10);
    $I->seeNumberOfElements('.view-group-online-meetings .views-row', 1);

    $I->click('Vergangene', '.main_layout_left .pane-content');
    for($i = 1; $i <= 10; $i++){
      $I->see('past meeting'.$i, $passedPaneClass.' .view-content .views-row:nth-child('.$i.')');
    }
    $I->seeNumberOfElements('.view-group-online-meetings .views-row', 10);
    $I->seeElement('.pagination');
    $I->seeNumberOfElements('ul.pagination li', 4);//Meeting Pages + Next/Last Page
    $I->click('2', '.pagination');
    $I->waitForJS("return jQuery.active == 0;", 10);
    $I->seeNumberOfElements('.view-group-online-meetings .views-row', 1);

    $I->click('Wiederkehrend', '.main_layout_left .pane-content');
    $I->seeNumberOfElements('.view-group-online-meetings .views-row', 10);
    $I->seeElement('.pagination');
    $I->seeNumberOfElements('ul.pagination li', 4);//Meeting Pages + Next/Last Page
    $I->click('2', '.pagination');
    $I->waitForJS("return jQuery.active == 0;", 10);
    $I->seeNumberOfElements('.view-group-online-meetings .views-row', 1);

    $I->checkAK('01.09e', 'AK 3: Rechts befindet sich eine Box mit den aktuell laufenden Online-Treffen');

    $I->amOnPage('groups/'.$group->nid.'/online-meetings/status');

    $I->checkAK('01.09e', 'AK 3.0: Der Status “Laufend” richtet sich danach ob das Online-Treffen tatsächlich gestartet wurde und nicht nach dem Zeitraum.');
    $I->checkAK('01.09e', 'AK 3.1: Über den Link “Teilnehmen” kann direkt in das Online-Treffen betreten werden.');
    //TODO AK 3.0: Andere US
    //TODO AK 3.1: Andere US
  }

  public function OM_02_0_plan_online_meeting(AcceptanceTester $I) {

    $I->wantTo('To see plan a "Online-Treffen"');

    $upcomingPaneClass = '.pane-group-online-meetings-panel-pane-1';
    $recurringPaneClass = '.pane-group-online-meetings-panel-pane-3';
    $passedPaneClass = '.pane-group-online-meetings-panel-pane-2';

    $og = $I->haveOrganisation('OnlineMeetingOrganisation_1', [
        'body' => 'OnlineMeetingOrganisation_1',
        'parent' => null,
        'language' => 'en'
      ]
    );
    $user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'meeting',
    ]);

    $group = $I->createGroup($user);
    $I->addMemberToGroup($user, $group->nid);
    $I->addMemberToOrganisation($user, $og, array(SALTO_OG_ROLE_MANAGER_RID));

    $I->completedSetup();

    $I->loginAsUser($user);

    $I->checkAK('01.09a', 'AK 1: In der Gruppe gibt es oben rechts bei den Aktionen ein neue Schaltfläche “Online-Treffen erstellen” unter “Datei einstellen”');

    $I->amOnPage('groups/'.$group->nid.'/online-meetings/status');

    $I->see('Online-Treffen erstellen', '.main_layout_right .pane-content');
    $I->click('Online-Treffen erstellen', '.main_layout_right .pane-content');

    $I->checkAK('01.09e', 'AK 2: Das Formular zum erstellen von Online-Treffen hat die Felder');
    $I->checkAK('01.09e', 'AK 2.1: Titel*, Textfeld');

    $I->seeElement('input[name="title"][type="text"]');

    $I->checkAK('01.09e', 'AK 2.2: Typ* (Meeting oder Webinar), Auswahl');

    $I->seeElement('select[name="field_meeting_options[und]"]');

    $I->checkAK('01.09e', 'AK 2.2: Zeitpunkt* (Feldgruppe)');
    $I->checkAK('01.09e', 'AK 2.2.1: Datum, Datepicker');
    $I->checkAK('01.09e', 'AK 2.2.2: Uhrzeit, Nummerneingabe Startuhrzeit bis Enduhrzeit');

    $I->seeElement('input[name="field_online_meeting_date[und][0][value][date]"]');
    $I->seeElement('input[name="field_online_meeting_date[und][0][value][time]"]');
    $I->seeElement('input[name="field_online_meeting_date[und][0][value2][time]"]');

    $I->checkAK('01.09e', 'AK 2.5: Inhalt, RichTextfeld (analog zu Beiträgen)');
    $I->seeElement('div.field-type-text-with-summary');

    //Alles Leer
    $I->fillField('input[name="title"][type="text"]', '');
    $I->fillField('div.start-date-wrapper input[name="field_online_meeting_date[und][0][value][date]"]', '');
    $I->fillField('input[name="field_online_meeting_date[und][0][value][time]"]', '');
    $I->fillField('input[name="field_online_meeting_date[und][0][value2][time]"]', '');
    $I->click('Speichern');
    $I->see('Das Feld „Titel” ist erforderlich.');
    $I->see('Für das Feld "Zeitpunkt Start date" wird ein gültiger Datumswert benötigt.');

    $I->checkAK('01.09e', 'AK 3: Felder die Dynamisch nur bei Online-Meetings angezeigt werden');
    $I->checkAK('01.09e', 'AK 3.1: “Nicht wiederkehrend” (vorauswahl), “Wiederkehrend”, Radiobottun');

    $I->seeCheckboxIsChecked('#edit-field-recurring-meeting-und-0');
    $I->dontSeeCheckboxIsChecked('#edit-field-recurring-meeting-und-1');

    $I->checkAK('01.09e', 'AK 4: Felder die Dynamisch nur bei Webinaren angezeigt werden');

    $I->selectOption('form select[name="field_meeting_options[und]"]', 'webinar');

    $I->checkAK('01.09e', 'AK 4.1: “Größe”, Auswahl mit Werten 1..100, 101..500, 501..1000');

    $I->seeElement('select[name="field_webinar_size[und]"]');
    $I->see('1..100', 'select[name="field_webinar_size[und]"] option[value="100"]');
    $I->see('101..500', 'select[name="field_webinar_size[und]"] option[value="500"]');
    $I->see('501..1000', 'select[name="field_webinar_size[und]"] option[value="1000"]');

    $I->checkAK('01.09e', 'AK 5: Analog zu Beiträgen kann Berechtigung bzgl. Lese- und Änderungszugriff rechts festgelegt werden.');

    $I->see('Lesezugriff', 'div.field-type-salto-collaboration');
    $I->see('Änderungszugriff', 'div.field-type-salto-collaboration');
    $I->seeElement('select[name="field_post_collaboration[und][0][read]"]');
    $I->seeElement('select[name="field_post_collaboration[und][0][edit]"]');

    $I->checkAK('01.09e', 'AK 6: Bei einem Webinar muss das Startdatum 2h in der Zukunft liegen. (Validierung).');

    $I->click('Speichern');
    $I->see('Das Startdatum muss 2 Stunden in der Zukunft liegen');

    $I->checkAK('01.09e', 'AK 7 Abgrenzung: Es gibt kein Vorschaubild und erst einmal keine Aktivitäten rund um Online-Treffen,');//Was?
  }

  public function OM_03_0_check_online_meeting_access(AcceptanceTester $I) {

    $I->wantTo('check the access of an Online Meeting');

    $og = $I->haveOrganisation('OnlineMeetingOrganisation_1', [
        'body' => 'OnlineMeetingOrganisation_1',
        'parent' => null,
        'language' => 'en'
      ]
    );
    $user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'meeting',
    ]);

    $group = $I->createGroup($user);
    $I->addMemberToGroup($user, $group->nid);
    $I->addMemberToOrganisation($user, $og, array(SALTO_OG_ROLE_MANAGER_RID));

    $I->completedSetup();

    $I->loginAsUser($user);

    $I->checkAK('01.09a', 'AK 1: In der Gruppe gibt es oben rechts bei den Aktionen ein neue Schaltfläche “Online-Treffen erstellen” unter “Datei einstellen”');

    $I->amOnPage('groups/'.$group->nid.'/online-meetings/status');

    $I->see('Online-Treffen erstellen', '.main_layout_right .pane-content');
    $I->click('Online-Treffen erstellen', '.main_layout_right .pane-content');

    $I->fillField('input[name="title"][type="text"]', 'Test Meeting');
    $I->fillField('div.start-date-wrapper input[name="field_online_meeting_date[und][0][value][date]"]', format_date(strtotime('+2 DAY'), 'custom', "d.m.Y"));
    $I->fillField('input[name="field_online_meeting_date[und][0][value2][time]"]', format_date(strtotime('+2 hours'), 'custom', "HH:mm"));

    $I->fillEditor('My custom body', "edit-body-und-0-value");

    $I->clickWithLeftButton('#edit-field-post-collaboration-und-0-read');
    $I->dontSee("öffentlich");
    $I->see('Alle Wissensnetz-Mitglieder');
    $I->see('Nur die Organisationen der Autoren');
    $I->see('Nur Autoren und Gruppenmanager');
    $I->see('Nur Gruppe "' . $group->title . '"');

    $I->selectOption("field_post_collaboration[und][0][read]", "1");

    $I->click('Speichern');

    $I->expect('that i get redirected in ');
    $MEETING_NID = $I->grabFromCurrentUrl('/node\/(\d+)/');
    $I->seeCurrentPageIs("/node/" . $MEETING_NID);

  }
}
