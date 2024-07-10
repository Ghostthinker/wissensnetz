<?php

use Helper\Wissensnetz;

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
   *
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {
  }

  public function _after(AcceptanceTester $I) {
    //cleanup is done in EdubreakHelper
  }

  /**
   * M0.00 - Materialien - Lehr-Lern-Materialien einstellen
   *
   * @UserStory 250.15 - https://trello.com/c/j8KVSwgK/615-250-15-e-datei-upload-verbesserung
   *
   * @param \AcceptanceTester $I
   *
   * @see https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.38zgedpun3ng
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

    //$I->see("Das Feld „Urheber” ist erforderlich.");
    $I->seeInField('#edit-field-file-originator-und-0-value', $U1->realname);

    $I->expect("Fill all required fields lets me save the file");

    //we have to decide here between imaeg and not image
    if ($example['type'] == 'image') {
      $title_id = 'edit-field-file-image-title-text-und-0-value';
    }
    else {
      $title_id = 'edit-field-file-title-und-0-value';
    }

    $I->fillField('//*[@id="' . $title_id . '"]', $file_title);
    $I->executeJS('jQuery("label:contains(\"Digitalisierung\") input").click()');
    $I->selectOption('//*[@id="edit-field-file-license-type-und"]', 'CC_BY');
    $I->fillField('//*[@id="edit-field-file-originator-und-0-value"]', "Aristoteles Homer");
    $I->click('Speichern');
    $I->seeLink("Datei bearbeiten");

    $I->expect("The file is now listed under Materials / Digitalisierung");

    $I->amOnPage("/materials");
    $I->click("Digitalisierung", '.main_layout_left');
    $I->seeLink($file_title);

  }

  /**
   * M0.01 - Materialien - Materialien hochladen (extern)
   *
   * @param \AcceptanceTester $I
   *
   * @see https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.yg9e7bodnfw1
   * @example { "link": "https://www.dosb.de", "title": "Der Deutsche Olympische Sportbund", "type" : "link" }
   * @example { "link": "https://www.youtube.com/watch?v=jNQXAC9IVRw", "title": "Me at the zoo - YouTube", "type" : "youtube" }
   *
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


    $I->executeJS('jQuery("label:contains(\"Digitalisierung\") input").click()');
    $I->submitForm("#file-entity-edit", [
      'field_file_originator[und][0][value]' => 'codecept',
      'field_file_license_type[und]' => 'CC_BY',
    ]);

  }

  /**
   * WIP - comment materials
   *
   * @param \AcceptanceTester $I
   */
  public function M_02_0_create_comment_file(AcceptanceTester $I) {

    $I->wantTo('Create a comment a file');

    $U1 = $I->haveUser(['firstname' => 'max', 'lastname' => 'muster']);
    $U2 = $I->haveUser(['firstname' => 'max', 'lastname' => 'commenter']);

    $I->completedSetup();

    $I->expect("that I can create a comment to my own file");

    $I->loginAsUser($U1);
    $file_data = [
      'title' => 'My file ' . time(),
      'access_read' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_PUBLIC,
      'access_write' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS
    ];
    $file_id = $I->createFile($file_data);
    $I->amOnPage('file/' . $file_id);

    $comment_text = "my comment " . time();

    $I->fillField('//*[@id="edit-comment-body-und-0-value"]', $comment_text);
    $I->click('Speichern');
    //$I->waitForAjax();

    // $I->seeLink('Löschen', '.ajax-comment-wrapper a');
    $I->see('Bearbeiten', '.ajax-comment-wrapper a');
    $I->see('Antworten', '.ajax-comment-wrapper a');

    $I->expect("that as authentcateduser, I can create a comment public files");

    $I->loginAsUser($U2);

    $I->amOnPage('file/' . $file_id);

    $I->dontSee('Bearbeiten', '.ajax-comment-wrapper a');
    $I->see('Antworten', '.ajax-comment-wrapper a');

    $comment_text2 = "my second comment " . time();

    $I->fillField('//*[@id="edit-comment-body-und-0-value"]', $comment_text2);
    $I->click('Speichern');

    $I->see($comment_text, '.field-name-comment-body');
  }

}
