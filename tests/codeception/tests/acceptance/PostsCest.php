<?php

use Helper\Wissensnetz;

/**
 * Class StartseiteCest
 * Alle Tests bezüglich Startseiten funktionalität
 *
 * @see aus https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.1aa149yk5ke
 *
 */
class PostsCest {

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
   * @UserStory 08.00 https://trello.com/c/EsIfwETv/44-0-12-80-benutzer-beitrag-artikel-erstellen-und-pflegen
   *
   * B1.01 - Beiträge - Beitrag erstellen (und auflisten)
   *
   * @see https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.yxbmkmnoq3vm
   * @param \AcceptanceTester $I
   */
  public function P_01_0_create_post(AcceptanceTester $I) {

    $I->wantTo('B1.01 - Beiträge - Beitrag erstellen (und auflisten)');

    $microTime = microtime(TRUE);
    $userTime = $I->haveUser([
      'firstname' => 'max',
      'lastname' => $microTime,
    ]);


    $I->completedSetup();


    $I->loginAsUser($userTime);

    $I->amOnPage("/posts");
    $I->seeLink("Beitrag erstellen");

    $title = "Test Title B1.01-" . $microTime;

    $I->createBeitrag([
      'Titel' => $title,
      'Inhalt' => "Test Inhalt B1_01",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'category' => SALTO_KNOWLEDGEBASE_KB_EDUCATION_TID,
      'user' => $userTime
    ]);

    $I->checkAK("08.00", "AK 1: Beiträge ohne Kategorie werden in der Übersicht gelistet.");

    $I->amOnPage("/posts");

    $I->see($title);
  }

  /**
   * B1.02 - Beiträge - Beitrag löschen
   *
   * @see https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.vn3kaupfhn6h
   * @param \AcceptanceTester $I
   */
  public function P_01_1_delete_post(AcceptanceTester $I) {

    $I->wantTo('B1.02 - Beiträge - Beitrag löschen');

    $AUTH_USER = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster',
    ]);

    $title = "Test Title B1.02-" . microtime(TRUE);
    $I->completedSetup();

    $I->loginAsUser($AUTH_USER);

    $I->createBeitrag([
      'Titel' => $title,
      'Inhalt' => "Test Inhalt B1_02",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'category' => salto_knowledgebase_get_default_kb_category_tid(),
      'user' => $AUTH_USER
    ]);

    $I->expect("that the newly created post is listed under \"Nicht einsortiert\"");

    $I->amOnPage("/posts");
    $term = taxonomy_term_load(salto_knowledgebase_get_default_kb_category_tid());

    $I->click($term->name, '.main_layout_left');
    $I->click($title);

    $I->expect("that I can delete the post");

    $I->click("Beitrag bearbeiten");

    $I->click("Löschen");
    $I->click("Löschen");

    $I->see("Beitrag " . $title . " wurde gelöscht.");
    $I->dontSee("Leider ist der Inhalt nicht verfügbar");
    $I->seeCurrentPageIs("/posts");
  }

  /**
   * B250.23 #E Vereinfachtes Aktualisieren von Anhängen in Beiträgen
   *
   * @UserStory 250.03 - https://trello.com/c/0T6MAMok/969-25023-e-vereinfachtes-aktualisieren-von-anh%C3%A4ngen-in-beitr%C3%A4gen
   *
   * @example { "file": "images/150524-19-50.jpg", "type": "image", "mime":"image/jpeg" }
   * @example { "file": "documents/sample.pdf", "type": "document", "mime":"application/pdf" }
   *
   * @param \AcceptanceTester $I
   */
  public function P_02_1_change_post_attachment(AcceptanceTester $I, \Codeception\Example $example) {

    $I->wantTo('B250.23 #E Vereinfachtes Aktualisieren von Anhängen in Beiträgen - ' . $example['mime']);

    $user1 = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster'
    ]);

    $user2 = $I->haveUser([
      'firstname' => 'maxi',
      'lastname' => 'master'
    ]);
    $I->loginAsUser($user1);

    $title = "Test Title B250.23_1-" . microtime(TRUE);
    $POST = $I->createBeitrag([
      'Titel' => $title,
      'Inhalt' => "Test Inhalt BB250.23_1",
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'Kategorie' => SALTO_KNOWLEDGEBASE_KB_EDUCATION_TID,
      'user' => $user1
    ]);

    $I->completedSetup();

    $postId = $POST->nid;

    $I->checkAK("250.23", "AK 1: Die Anzeige von Aktionen für die jeweilige Datei unter Beitragsanhänge wird um die Schaltflächen \"Datei bearbeiten\", \"Datei ersetzen\" und \"Aus Beitrag entfernen\" konsolidiert bzw. erweitert:");

    $I->amOnPage("/node/" . $postId . '/edit');
    $I->seeLink("Dateien durchsuchen oder hochladen");
    $I->click("Dateien durchsuchen oder hochladen");

    $I->waitForElement('#mediaBrowser', 10);
    $I->seeElement('#mediaBrowser');
    $driver = $I->executeInSelenium(function(\Facebook\WebDriver\Remote\RemoteWebDriver $webDriver) {
      $webDriver->switchTo()->frame(
        $webDriver->findElement(\Facebook\WebDriver\WebDriverBy::cssSelector('#mediaBrowser'))
      );
      return $webDriver;
    });

    $I->performOn('#media-tabs-wrapper', \Codeception\Util\ActionSequence::build()
      ->see("Hochladen")
    );

    $I->attachFile('input[type="file"]', $example['file']);
    $I->click('Übertragen beginnen');
    $I->waitForText('1/1 Dateien hochgeladen', 20);
    $I->click('Weiter');

    /* only if "Bulk upload is on (checked)
    //$I->see('B2.00-1500277990.9211');
    //$I->seeElement('#edit-field-kb-kategorie-und-0-4466-4466');
    //$I->click('#edit-field-kb-kategorie-und-0-4466-4466');

    $I->see('Noch nicht einsortiert');
    $I->checkOption('Noch nicht einsortiert');

    $I->selectOption('Nutzungslizenz', 'CC BY Namensnennung');
    $I->fillField('Urheber', $user1->realname);

    $I->seeElement("#edit-submit");
    $I->click("#edit-submit");
    $I->wait(1);
    */
    $driver->switchTo()->defaultContent();

    $I->waitForText('Dateiname');
    $I->see('Aus Beitrag entfernen');
    $I->wait(2);
    $I->seeLink('Datei bearbeiten');
    $I->seeLink('Datei ersetzen');
    $I->see('Anzeige in "Materialien"');
    $I->dontSeeCheckboxIsChecked('#edit-field-post-attachment-und-0-file-attachment-status');

    $fid = $I->grabMultiple('div.media-item', 'data-fid');
    $I->click('Speichern');

    $I->checkAK("250.23", "AK 1.1: Über die ersten beiden Aktionen (Datei bearbeiten und ersetzen) wird der gleiche (bereits bestehende Dialog) aufgerufen.");
    $I->amOnPage("/node/" . $postId . '/edit');

    $I->click(['link' => 'Datei bearbeiten']);
    $I->wait(1);
    //$I->seeInCurrentUrl('file/' . $fid[0] . '/edit');
    $I->see('Diese Datei wird in folgenden Beiträgen verwendet: ' . $title);

    $I->amOnPage("/node/" . $postId . '/edit');
    $I->click(['link' => 'Datei ersetzen']);
    $I->wait(1);
    //$I->seeInCurrentUrl('file/' . $fid[0] . '/edit');
    $I->see('Diese Datei wird in folgenden Beiträgen verwendet: ' . $title);

    $I->checkAK("250.23", "AK 1.2: Bei \"Datei ersetzen\" wird über dem Datei-Formular der Hinweis angezeigt \"Um eine neue Version dieser Datei hochzuladen wählen Sie diese bitte unter \"Datei auswählen\" aus. Bitte beachten Sie, dass die bestehende Datei dadurch dauerhaft überschrieben wird.\"");
    $I->see('Um eine neue Version dieser Datei hochzuladen wählen Sie diese bitte unter "Datei auswählen" aus. Bitte beachten Sie, dass die bestehende Datei dadurch dauerhaft überschrieben wird.');

    $I->checkAK("250.23", "AK 2: Die ersten beiden Schaltflächen werden nur angezeigt, wenn die agierende Person dazu die entsprechenden Berechtigungen hat.");
    $I->loginAsUser($user2);
    $I->amOnPage("/node/" . $postId . '/edit');
    $I->dontSeeLink('Datei bearbeiten');
    $I->dontSeeLink('Datei ersetzen');

    $I->checkAK("250.23", "AK 2.1: Ein Entfernen der Datei aus dem Beitrag ist immer möglich (wenn man den Beitrag bearbeiten kann - klar).");
    $I->see('Aus Beitrag entfernen');
    $I->click('Aus Beitrag entfernen');
    //$I->dontSeeElement('.form-item');
    //$I->dontSeeElement('.form-item-field-post-attachment-und-0-description');
    $I->wait(2);
    $I->dontSeeElement('#edit-field-post-attachment-und-table');
  }


  /**
   *
   * @example { "file": "images/150524-19-50.jpg", "type": "image", "mime":"image/jpeg" }
   *
   * @param \AcceptanceTester $I
   */
  public function P_02_2_post_attachment_access(AcceptanceTester $I, \Codeception\Example $example) {

    $I->wantTo('B250.23 #E Vereinfachtes Aktualisieren von Anhängen in Beiträgen - ' . $example['mime']);

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

    //check first group themenfeld
    $I->executeJS("return document.querySelector('#edit-field-group-categories-und .form-type-checkbox .form-checkbox').click()");

    $title = 'Group G310-' . $microTime;
    $I->submitForm('#group-node-form', ['title' => $title,]);

    $I->see($title);
    $gid1 = $I->grabFromCurrentUrl('/node\/(\d+)/');

    $I->addMemberToGroup($U1, $gid1);
    $I->addMemberToGroup($U2, $gid1);


    $title = "Test Title B250.23_1-" . microtime(TRUE);
    $I->createGroupBeitrag([
      'Titel' => $title,
      'Inhalt' => "Test Inhalt BB250.23_1",
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'user' => $U1
    ],$gid1);

    $I->completedSetup();

    $postId = $I->grabFromCurrentUrl('/node\/(\d+)/');

    $I->amOnPage("/node/" . $postId . '/edit');
    $I->seeLink("Dateien durchsuchen oder hochladen");
    $I->click('.cke_button__media');

    $I->waitForElement('#mediaBrowser', 10);
    $I->seeElement('#mediaBrowser');
    $driver = $I->executeInSelenium(function(\Facebook\WebDriver\Remote\RemoteWebDriver $webDriver) {
      $webDriver->switchTo()->frame(
        $webDriver->findElement(\Facebook\WebDriver\WebDriverBy::cssSelector('#mediaBrowser'))
      );
      return $webDriver;
    });

    $I->performOn('#media-tabs-wrapper', \Codeception\Util\ActionSequence::build()
      ->see("Hochladen")
    );

    $I->attachFile('input[type="file"]', $example['file']);
    $I->click('Übertragen beginnen');
    $I->waitForText('1/1 Dateien hochgeladen', 20);
    $I->click('Weiter');

    $driver->switchTo()->defaultContent();



    $I->executeJS("return document.querySelector('.select-parents.form-checkbox').click()");

    $I->click('Speichern');
    $file_usage = salto_file_usage_by_nid($postId);

    $fid = key($file_usage);

    $I->amOnPage("/file/" . $fid);
    $I->notAccessDenied();


    $I->expect('as ' . $U2->realname . ' that i can see the post image');
    $I->loginAsUser($U2);

    $I->amOnPage("/file/" . $fid);
    $I->notAccessDenied();
  }


  /**
   * B2.01 - Kategorien - Kategorien bearbeiten
   *
   * @see https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.1pd29wujglcr
   * @param \AcceptanceTester $I
   */
  /*
  public function B_03_2_change_category(AcceptanceTester $I) {

    $I->wantTo('B2.01 - Kategorien - Kategorien bearbeiten');

    $title_themenfeld = "B2.01-" . microtime(TRUE);
    $title_arbeitsgebiet = "B2.01-" . microtime(TRUE);

    $dosb_user = $DOSB_USER;

    $I->loginAsUser($dosb_user);


    $I->amOnPage("/posts");
    $I->click("Themenfelder verwalten");
    $I->click("Neues Element");
    $I->fillField('name', $title_themenfeld);
    $I->fillEditor("Lorem Fulltext", 'edit-description-value');
    $I->click("Beziehungen");
    $I->selectOption('parent[]', 0);
    $I->click("Speichern");

    $I->amOnPage("/posts");
    $I->click("Themenfelder verwalten");
    $I->click("Neues Element");
    $I->fillField('name', $title_arbeitsgebiet);
    $I->fillEditor("Lorem Fulltext", 'edit-description-value');
    $I->click("Beziehungen");
    $I->selectOption('parent[]', 0);
    $I->click("Speichern");


    //synchronisierung
    $I->amOnPage("/posts");
    $I->see($title_themenfeld);
    $I->amOnPage("/materials");
    $I->see($title_themenfeld);

    $I->amOnPage("materials/category");

    //click edit button



  }*/

  /**
   * B260.10 BenutzerIn - Kommentar - Kommentar löschen
   *
   * @UserStory 260.10 - https://trello.com/c/Fc0clCcb/975-26010-benutzerin-kommentar-kommentar-l%C3%B6schen
   *
   * @param \AcceptanceTester $I
   */
  public function P_04_0_post_comments(AcceptanceTester $I) {

    $I->wantTo('B260.10 BenutzerIn - Kommentar - Kommentar löschen');
    $I->checkAK("260.10", "AK 5.1: Gilt für Beiträge und.. [21.09.2017 - 10:30 - SH]");

    $user1 = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster'
    ]);

    $user2 = $I->haveUser([
      'firstname' => 'maxi',
      'lastname' => 'master'
    ]);
    $I->loginAsUser($user1);

    $title = "Test Title B260.10_1-" . microtime(TRUE);
    $POST = $I->createBeitrag([
      'Titel' => $title,
      'Inhalt' => "Test Inhalt BB260.10_1",
      'readAccess' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'category' => SALTO_KNOWLEDGEBASE_KB_EDUCATION_TID,
      'user' => $user1
    ]);

    $I->completedSetup();

    $I->checkAK("260.10", "AK 1: Neben \"Bearbeiten\" erscheint auch \"Löschen\"");

    $I->amOnPage("/node/" . $POST->nid);
    $I->wait(3);
    $I->seeElement('#ajax-comments-reply-form-' . $POST->nid . '-0-0');
    $I->fillfield(["name" => "comment_body[und][0][value]"], 'Test-Kommentar');
    $I->click('Speichern');

    $I->see("Antworten", 'ul.links');
    $I->see('Bearbeiten', 'ul.links');
    $I->see('Löschen', 'ul.links');
    $I->see('Gespeichert von ' . $user1->realname);
    $I->see('Test-Kommentar');

    $I->checkAK("260.10", "AK 3 Hinweis: Geht natürlich weiterhin nur mit meinen eigenen Kommentaren");
    $I->loginAsUser($user2);

    $I->amOnPage('/node/' . $POST->nid);
    $I->seeElement('#ajax-comments-reply-form-' . $POST->nid . '-0-0');
    $I->see('Antworten', 'ul.links');
    $I->dontSee('Bearbeiten', 'ul.links');
    $I->dontSee('Löschen', 'ul.links');

    $I->click('Antworten');
    //$I->fillfield(['css' => '#edit-comment-body-und-0-value--3'], 'Neuer Test-Kommentar');
    $I->fillfield(['xpath' => '//textarea[@name="comment_body[und][0][value]"][1]'], 'Neuer Test-Kommentar');
    //$I->fillfield(["name" => "comment_body[und][0][value]"], 'Neuer Test-Kommentar');
    $I->click('Speichern');


    $I->see('Gespeichert von ' . $user2->realname);
    $I->see('Neuer Test-Kommentar');

    $I->checkAK("260.10", "AK 2: Kommentar wird nach kurzer Rückfrage \"Möchten Sie den Kommentar wirklich löschen? Dieser Vorgang kann nicht rückgängig gemacht werden! Ja/Abbrechen\" einfach gelöscht.");
    $I->loginAsUser($user1);

    $I->amOnPage("/node/" . $POST->nid);
    $hrefEdit = $I->grabAttributeFrom('.comment-edit a', 'href');
    $hrefReply = $I->grabAttributeFrom('.comment-reply a', 'href');
    $hrefDelete = $I->grabAttributeFrom('.comment-delete a', 'href');
    $I->see('Löschen', 'ul.links');
    $I->click('Löschen');
    $I->see('Diesen Kommentar löschen?');

    $I->checkAK("260.10", "AK 4: Wenn der Kommentar Antworten hat, wird dieser nur logisch gelöscht und dann als \"Gelöschter Kommentar\" angezeigt.");
    $I->click('Ja');
    $I->see('Gelöschter Kommentar.');

    $I->checkAK("260.10", "AK 4.3 Info: In diesem Fall bleib der Kommentar inhaltlich bestehen!");
    $I->checkAK("260.10", "AK 4.2: Der Autor des Kommentars wird dann Gast.");
    $I->see('Gast');
    $I->checkAK("260.10", "AK 4.1: Ein Bearbeiten ist danach nicht mehr möglich.");
    $I->dontSee($hrefReply);
    $I->dontSee($hrefEdit);
    $I->dontSee($hrefDelete);

    $I->expect('Nein/Abbrechen im Modal Dialog');
    $I->click('Antworten');
    $newComment = "Aller neuer Test-Kommentar";
    $I->fillfield(['xpath' => '//textarea[@name="comment_body[und][0][value]"][1]'], $newComment);
    //$I->fillfield(["name" => "comment_body[und][0][value]"], $newComment);
    $I->click('.ajax-comments-form-reply .form-submit');

    $I->waitforText($newComment);

    $I->see('Löschen', 'ul.links');
    $I->click('Löschen');
    $I->see('Diesen Kommentar löschen?');
    $I->click('Nein');
    $I->waitforText($newComment);
  }
  /**
   * B270.03 #E Beitrag - Anhang erleichtert anfügen
   *
   * @UserStory 270.03 - https://trello.com/c/Hd7agzvs/655-27003-e-beitrag-anhang-erleichtert-anf%C3%BCgen
   *
   * @example { "file": "images/150524-19-50.jpg", "type": "image", "mime":"image/jpeg" }
   * @example { "file": "documents/sample.pdf", "type": "document", "mime":"application/pdf" }
   *
   * @param \AcceptanceTester $I
   */
  public function P_05_0_add_and_change_attachments(AcceptanceTester $I, \Codeception\Example $example) {

    $I->wantTo('B270.03 #E Beitrag - Anhang erleichtert anfügen - ' . $example['mime']);

    $user = $I->haveUser([
      'firstname' => 'max',
      'lastname' => 'muster'
    ]);

    $user2 = $I->haveUser([
      'firstname' => 'maxi',
      'lastname' => 'master'
    ]);

    $I->completedSetup();
    $I->loginAsUser($user);

    $I->amOnPage("/posts");
    $I->seeLink("Beitrag erstellen");
    $I->click("Beitrag erstellen");

    $I->executeJS('jQuery("label:contains(\"Noch nicht einsortiert\") input").click()');
    $I->executeJS('jQuery("label:contains(\"Schule\") input").click()');

    $I->seeLink("Dateien durchsuchen oder hochladen");
    $I->click("Dateien durchsuchen oder hochladen");

    $I->waitForElement('#mediaBrowser', 10);
    $I->seeElement('#mediaBrowser');
    $driver = $I->executeInSelenium(function(\Facebook\WebDriver\Remote\RemoteWebDriver $webDriver) {
      $webDriver->switchTo()->frame(
        $webDriver->findElement(\Facebook\WebDriver\WebDriverBy::cssSelector('#mediaBrowser'))
      );
      return $webDriver;
    });

    $I->performOn('#media-tabs-wrapper', \Codeception\Util\ActionSequence::build()
      ->see("Hochladen")
    );

    $I->attachFile('input[type="file"]', $example['file']);
    $I->click('Übertragen beginnen');
    $I->waitForText('1/1 Dateien hochgeladen', 20);
    $I->click('Weiter');

    $driver->switchTo()->defaultContent();

    $I->checkAK("270.03", "AK 1: Statt wie bisher das Feld \"Beschreibung\" bei Anhängen anzuzeigen, soll hier \"Dateiname\" stehen und auch sinngemäß den Dateinamen ändern.");
    $I->waitForText("Dateiname");

    $I->wait(2);

    $I->checkAK("270.03", "AK 1.1: Direkt nach dem Einbinden einer Datei als Anhang eines Beitrags, lässt sich der Dateiname verändern #NeueDatei.");

    $title = 'Test B270_03_1 ' . microtime(true);
    $I->fillField('title', $title);
    $I->fillField('field_post_tags[und]', 'Test');
    $I->fillCkEditorById('1_contents', 'Test B270_03_1');

    $attachTitle = 'Anhang B270_03_1 ' . microtime(true);
    $I->fillField('#edit-field-post-attachment [id*="file-attachment-title"]', $attachTitle);

    $I->see("Speichern");
    $I->click("Speichern");

    $I->see('Test B270_03_1', "p");
    $I->see($title, "h2");
    $I->see($attachTitle);

    $postId = $I->grabFromCurrentUrl('/node\/(\d+)/');

    // per ctools modal
    $I->checkAK("270.03", "AK 2: Voreinstellungen beim Hochladen");
    $I->checkAK("270.03", "AK 2.1: Themenfelder/Kategorie -> gleiche wie Kategorie des Beitrags");
    $I->amOnPage("/node/" . $postId . '/edit');
    $I->see('Datei bearbeiten', 'td.insertLink');
    $I->click('Datei bearbeiten', 'td.insertLink');
    $I->wait(2);
    //Verknüpfte Kategorie auf dem Test-System
    //$I->seeCheckboxIsChecked('#edit-field-kb-kategorie-und-0-4715-4715'); //Noch nicht einsortiert

    $li = $I->executeJS('return jQuery("#edit-field-kb-kategorie-und ul .checkbox label:contains(\'Noch nicht einsortiert\')").attr(\'for\')');
    $I->seeCheckboxIsChecked('#' . $li); //Noch nicht einsortiert

    $I->checkAK("270.03", "AK 2.2: Nutzungslizenzen -> CCBY");
    $I->seeInField('#edit-field-file-license-type-und', 'CC BY Namensnennung');

    $I->checkAK("270.03", "AK 2.3: Urheber -> Nutzer (agierender Benutzer / Autor des Beitrages)");
    $I->seeInField('#edit-field-file-originator-und-0-value', $user->realname);

    $I->checkAK("270.03", "AK 3.1: Bitte Felder \"Lizenzstufe\", \"File Attachment Status\" und \"Beitrag Themenfelder sync)\" aus der Liste entfernen = Ausblenden");
    $I->dontSeeElement('#edit-field-file-lizenzstufe');
    $I->dontSeeElement('#edit-field-file-attachment-status');
    $I->dontSeeElement('#edit-field-file-attachment-post-ref');

    $I->see("Speichern", '#modalContent');
    $I->click("Speichern", '#modalContent');

    //$I->checkAK("270.03", "AK 1.2: Bei bestehenden Anhängen kann ich den Dateinamen nur ändern, wenn ich über die notwendigen Berechtigungen verfüge.");

    $I->loginAsUser($user2);
    $I->amOnPage("/node/" . $postId . '/edit');
    $I->seeElement('#edit-field-post-attachment-und-0-file-attachment-title');
    $dis = $I->grabAttributeFrom('#edit-field-post-attachment-und-0-file-attachment-title', 'disabled');
    //var_dump($dis);

    $I->checkAK("270.03", "AK 3.2. \"Lizenzstufe\" auch unter Materalien als Filter entfernen.");
    $I->amOnPage("/materials");
    $I->dontSee('Lizenzstufe', 'label');
    $I->dontSeeElement('#edit-field-file-lizenzstufe-value');
  }


}
