<?php

use Helper\Bildungsnetz;

/**
 * Class MaterialsCest
 * Alle Tests bezüglich Startseiten funktionalität
 *
 * @see aus https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.vycihaij7dv9
 *
 */
class MaterialsCest {

  /**
   * Always create this entities before every course
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {}

  public function _after(AcceptanceTester $I) {
    //cleanup is done in EdubreakHelper
  }

  /**
   * M0.00 - Materialien - Lehr-Lern-Materialien einstellen
   * @UserStory 250.15 - https://trello.com/c/j8KVSwgK/615-250-15-e-datei-upload-verbesserung
   *
   * @example { "file": "images/150524-19-50.jpg", "type": "image", "mime":"image/jpeg" }
   * @example { "file": "documents/sample.docx", "type": "document", "mime":"application/docx"}
   * @example { "file": "documents/sample.pdf", "type": "document", "mime":"application/pdf" }
   * @example { "file": "documents/sample.pptx", "type": "document", "mime":"application/pptx"  }
   * example { "file": "documents/sample.rtf", "type": "document", "mime":"text/rtf"  }
   * @example { "file": "documents/sample.xlsx", "type": "document", "mime":"application/xlsx"  }
   * example { "file": "audio/sample.aac", "type": "audio", "mime":"audio/aac" } -- triggers error
   * @example { "file": "audio/sample.mp3", "type": "audio", "mime":"audio/mp3" }
   * @example { "file": "audio/sample.ogg", "type": "audio", "mime":"audio/ogg" }
   * @example { "file": "audio/sample.wav", "type": "audio", "mime":"audio/wav" }
   * @example { "file": "audio/sample.wma", "type": "audio", "mime":"audio/wma" }
   *
   * @see https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.38zgedpun3ng
   * @param \AcceptanceTester $I
   */
  public function M_01_0_upload_single_file(AcceptanceTester $I, \Codeception\Example $example) {

    $I->wantTo('Upload an Image and list it in under Materials - ' . $example['mime']);

    $U1 = $I->haveUser(['firstname' => 'max', 'lastname' => 'muster']);
    $file_title = "Meine Datei " . time();

    $I->completedSetup();

    $I->expect("that I cannot upload materials as guest");

    $I->amOnPage("/materials");
    $I->dontSeeLink("Lehr-Lern-Materialien einstellen");
    $I->amOnPage('file/add_anything');
    //$I->getAccessDenied();
    $I->see(t('Access denied. You must log in to view this page.'));


    $I->expect("that I can upload materials as authenticated user");

    $I->loginAsUser($U1);
    $I->amOnPage("/materials");

    $I->click("Datei einstellen", '.main_layout_right');

    $I->seeLink("Hochladen");
    $I->seeLink("Dateien hinzufügen");
    $I->seeLink("Externer Link");

    $I->attachFile('input[type="file"]', $example['file']);
    $I->click('Übertragen beginnen');
    //$I->wait(1);
    $I->waitForText('1/1 Dateien hochgeladen');
    $I->click('Weiter');

    $I->expect("that I get warned about required fields");
    $I->waitForText('Speichern');
    $I->click('Speichern');
    $I->see("Das Feld „Themenfeld(er)” ist erforderlich.");
    if ($example['type'] == 'audio') {
      $I->see("Das Feld „Nutzungslizenz” ist erforderlich.");
    } else {
      $I->seeInField('#edit-field-file-license-type-und', 'CC BY Namensnennung');
    }
    //$I->see("Das Feld „Urheber” ist erforderlich.");
    $I->seeInField('#edit-field-file-originator-und-0-value', $U1->realname);

    $I->expect("Fill all required fields lets me save the file");

    //we have to decide here between imaeg and not image
    if($example['type'] == 'image') {
      $title_id = 'edit-field-file-image-title-text-und-0-value';
    }else{
      $title_id = 'edit-field-file-title-und-0-value';
    }

    $I->fillField('//*[@id="'.$title_id.'"]', $file_title);
    $I->executeJS('jQuery("label:contains(\"Noch nicht einsortiert\") input").click()');
    $I->selectOption('//*[@id="edit-field-file-license-type-und"]','CC_BY');
    $I->fillField('//*[@id="edit-field-file-originator-und-0-value"]', "Aristoteles Homer");
    $I->click('Speichern');
    $I->see("$file_title wurde aktualisiert");
    $I->seeLink("Datei bearbeiten");

    $I->expect("The file is now listed under Materials / noch nicht einsortiert");

    $I->amOnPage("/materials");
    $I->click("Noch nicht einsortiert", '.main_layout_left');
    $I->seeLink($file_title);

  }

  /**
   * M0.01 - Materialien - Materialien hochladen (extern)
   *
   * @example { "link": "https://www.dosb.de", "title": "Der Deutsche Olympische Sportbund", "type" : "link" }
   * @example { "link": "https://www.youtube.com/watch?v=jNQXAC9IVRw", "title": "Me at the zoo - YouTube", "type" : "youtube" }
      *
   * @see https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.yg9e7bodnfw1
   * @param \AcceptanceTester $I
   */
  public function M_01_1_upload_external_material(AcceptanceTester $I, \Codeception\Example $example) {

    $I->wantTo('M0.01 - Materialien - Exteres Material einstellen');

    $U1 = $I->haveUser(['firstname' => 'max', 'lastname' => 'muster']);

    $external_link = $example['link'];
    $external_title = $example['title'];
    $external_type = $example['type'];

    $I->completedSetup();

    $I->expect("Fill all required fields lets me save the file");
    $I->loginAsUser($U1);

    $I->amOnPage("/file/add_anything");
    $I->click("Externer Link");
    $I->fillField('embed_code', $external_link);
    $I->click('#media-internet-add-upload button[type=submit]');

    $I->see('Externes Material ' . $external_title . ' was uploaded.');

    $I->executeJS('jQuery("label:contains(\"Noch nicht einsortiert\") input").click()');
    $I->submitForm("#file-entity-edit",[
      'field_file_originator[und][0][value]' => 'codecept',
      'field_file_license_type[und]' => 'CC_BY',
    ]);

    //$I->click("Speichern");
    $I->see('Externes Material ' . $external_title . ' wurde aktualisiert');

    $I->expect("The file is now listed under Materials / noch nicht einsortiert");

    $I->amOnPage("/materials");
    $I->click("Noch nicht einsortiert", '.main_layout_left');
    $I->seeLink($external_title);
  }

  /**
   * WIP - comment materials
   * @param \AcceptanceTester $I
   */
  public function M_02_0_create_comment_file(AcceptanceTester $I) {

    $I->wantTo('Create a comment a file');

    $U1 = $I->haveUser(['firstname' => 'max', 'lastname' => 'muster']);
    $U2 = $I->haveUser(['firstname' => 'max', 'lastname' => 'commenter']);

    $I->completedSetup();

    $I->expect("that I can create a comment to my own file");

    $I->loginAsUser($U1);
    $file_data = ['title' => 'My file '.time(), 'access_read' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_PUBLIC, 'access_write' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS];
    $file_id = $I->createFile($file_data);
    $I->amOnPage('file/' . $file_id);

    $comment_text = "my comment ".time();

    $I->fillField('//*[@id="edit-comment-body-und-0-value"]', $comment_text);
    $I->click('Speichern');
    //$I->waitForAjax();
    $I->waitForText("Ihr Kommentar wurde erstellt.");
   // $I->seeLink('Löschen', '.ajax-comment-wrapper a');
    $I->see('Bearbeiten', '.ajax-comment-wrapper a');
    $I->see('Antworten', '.ajax-comment-wrapper a');

    $I->expect("that as authentcateduser, I can create a comment public files");

    $I->loginAsUser($U2);

    $I->amOnPage('file/' . $file_id);

    $I->dontSee('Bearbeiten', '.ajax-comment-wrapper a');
    $I->see('Antworten', '.ajax-comment-wrapper a');

    $comment_text2 = "my second comment ".time();

    $I->fillField('//*[@id="edit-comment-body-und-0-value"]', $comment_text2);
    $I->click('Speichern');
    //$I->waitForAjax();
    $I->waitForText("Ihr Kommentar wurde erstellt.");
    $I->see($comment_text, '.field-name-comment-body');
  }

  /**
   * M270.10 - #CR Begrifflichkeit "Lehr-Lern-Materialien"
   * @UserStory 270.10 - https://trello.com/c/P1tlMHfY/976-27010-cr-begrifflichkeit-lehr-lern-materialien
   *
   * @param \AcceptanceTester $I
   */
  public function M_03_0_check_material_descriptions(AcceptanceTester $I) {

    $I->wantTo('M270.10 - #CR Begrifflichkeit "Lehr-Lern-Materialien');

    $dosbUser = $I->haveDOSBUser();
    $U1 = $I->haveUser(['firstname' => 'max', 'lastname' => 'shower']);

    //create new empty Category
    $I->loginAsUser($dosbUser);
    $title = "B2.00-" . microtime(TRUE);
    $I->amOnPage("/posts");
    $I->click("Struktur verwalten");

    $I->click("Neues Element");
    $I->fillField('name', $title);
    $I->fillEditor("Lorem Fulltext", 'edit-description-value');
    $I->click("Beziehungen");
    $I->selectOption('parent[]', 0);
    $I->click("Speichern");

    $I->completedSetup();

    $I->loginAsUser($U1);

    $I->checkAK('270.10', "AK 1: Als Überschrift von Materialien (Lehr-Lern-Materialien -> Materialien)");
    $I->amOnPage("/materials", '.main_layout_left');
    $I->dontSee("Lehr-Lern-Materialien", 'h2.pane-title');
    $I->see('Materialien', 'h2.pane-title');

    $I->checkAK('270.10', "AK 2: Im orangenen Menüpunkt (Lehr-Lern-Materialien einstellen -> Datei einstellen)");
    $I->dontSeeLink("Lehr-Lern-Materialien einstellen");
    $I->see('Datei einstellen', 'a.action_link');

    $I->checkAK('270.10', "AK 3: Wenn nichts eingestellt (Keine Lehr-Lern-Materialien verfügbar -> Keine Materialien verfügbar)");


    $I->amOnPage("/materials");
    $I->see($title);
    $I->click($title, '.main_layout_left');
    $I->see("Keine Materialien verfügbar.");
    $I->dontSee("Keine Lehr-Lern-Materialien verfügbar.");

    $I->checkAK('270.10', "AK 4: Bitte auch Breadcrumb beachten. [21.09.2017 - 10:42 - JM]");
    $I->dontSee("Lehr-Lern-Materialien", '.breadcrumb');
    $I->see('Materialien', '.breadcrumb');
    $I->amOnPage("/materials/1915");
    $I->dontSee("Lehr-Lern-Materialien", '.breadcrumb');
    $I->see('Materialien', '.breadcrumb');

    $I->expect('Don\'t see general Lehr-Lern-Materialien' );
    $I->amOnPage("/materials");
    $I->dontSee("Lehr-Lern-Materialien");

    //$I->seeElement('.col-md-12.main_right h2');
  }

  /**
   * M260.10 BenutzerIn - Kommentar - Kommentar löschen
   *
   * @UserStory 260.10 - https://trello.com/c/Fc0clCcb/975-26010-benutzerin-kommentar-kommentar-l%C3%B6schen
   *
   * @param \AcceptanceTester $I
   */
  public function M_04_0_delete_materials_comment(AcceptanceTester $I) {

    $I->wantTo('B260.10 BenutzerIn - Kommentar - Kommentar löschen');
    $I->checkAK("260.10", "AK 5.2: .. und Dateien [21.09.2017 - 10:30 - SH]");

    $user1 = $I->haveUser(['firstname' => 'max', 'lastname' => 'muster']);
    $user2 = $I->haveUser(['firstname' => 'maxi', 'lastname' => 'master']);
    $I->loginAsUser($user1);

    $file_data = [
      'title' => 'My file '.time(),
      'access_read' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_PUBLIC,
      'access_write' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS
    ];
    $file_id = $I->createFile($file_data);

    $I->completedSetup();

    $I->checkAK("260.10", "AK 1: Neben \"Bearbeiten\" erscheint auch \"Löschen\"");

    $I->amOnPage('file/' . $file_id);
    //$I->seeElement('#ajax-comments-reply-form-' . $file_id . '-0-0');
    //$I->fillfield('#edit-comment-body-und-0-value', 'Test-Kommentar');
    $I->fillfield(["name" => "comment_body[und][0][value]"], 'Test-Kommentar');
    $I->click('Speichern');

    $I->waitForText("Ihr Kommentar wurde erstellt.");
    $I->see("Antworten", 'ul.links');
    $I->see('Bearbeiten', 'ul.links');
    $I->see('Löschen', 'ul.links');
    $I->see('Gespeichert von ' . $user1->realname);
    $I->see('Test-Kommentar');

    $I->checkAK("260.10", "AK 3 Hinweis: Geht natürlich weiterhin nur mit meinen eigenen Kommentaren");
    $I->loginAsUser($user2);

    $I->amOnPage('file/' . $file_id);
    //$I->seeElement('#ajax-comments-reply-form-' . $file_id . '-0-0');
    $I->see("Antworten", 'ul.links');
    $I->dontSee('Bearbeiten', 'ul.links');
    $I->dontSee('Löschen', 'ul.links');

    $I->click('Antworten');
    //$I->fillfield(['css' => '#edit-comment-body-und-0-value--3'], 'Neuer Test-Kommentar');
    $I->fillfield(['xpath' => '//textarea[@name="comment_body[und][0][value]"]'], 'Neuer Test-Kommentar');
    //$I->fillfield(["name" => "comment_body[und][0][value]"], 'Neuer Test-Kommentar');
    $I->click('Speichern');

    $I->waitForText("Ihr Kommentar wurde erstellt.", 20);
    $I->see('Gespeichert von ' . $user2->realname);
    $I->see('Neuer Test-Kommentar');

    $I->checkAK("260.10", "AK 2: Kommentar wird nach kurzer Rückfrage \"Möchten Sie den Kommentar wirklich löschen? Dieser Vorgang kann nicht rückgängig gemacht werden! Ja/Abbrechen\" einfach gelöscht.");
    $I->loginAsUser($user1);

    $I->amOnPage('file/' . $file_id);
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
    $newComment = 'Neussster Test-Kommentar';
    $I->fillfield(['xpath' => '//textarea[@name="comment_body[und][0][value]"]'], $newComment);
    $I->click('Speichern');
    $I->waitForText("Ihr Kommentar wurde erstellt.", 20);

    $I->see('Löschen', 'ul.links');
    $I->click('Löschen');
    $I->see('Diesen Kommentar löschen?');
    $I->click('Nein');
    $I->see('Gespeichert von ' . $user1->realname);
    $I->see($newComment);
  }


  //TODO - commenting materias
  //TODO - material visibility checks (read/write)
  //TODO - Kategorien <> "noch nict einsortiert" prüfen


}
