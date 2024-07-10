<?php

use Helper\Wissensnetz;

/**
 * all tests for start pages
 * @see aus https://docs.google.com/document/d/16Q330F3AdIB_QFMBmXBt2qGGVCmDAKgkNWfm8NTXf1c/edit#heading=h.vycihaij7dv9
 */
class GroupsMaterialsCest {

  /**
   * Always create this entities before every course
   * @param \AcceptanceTester $I
   */
  public function _before(AcceptanceTester $I) {}

  public function _after(AcceptanceTester $I) {}

  /**
   * 310.08 #CR Dateien in Gruppe hochladen
   * @UserStory 310.08 - https://trello.com/c/eYfNoE95/748-31008-cr-dateien-in-gruppe-hochladen
   * @Task https://trello.com/c/iIfOoDbK/1036-31008-cr-dateien-in-gruppe-hochladen
   *
   * @example { "file": "images/150524-19-50.jpg", "type": "image", "mime":"image/jpeg" }
   *
   * @param \AcceptanceTester $I
   * @param \Codeception\Example $example
   */
  public function GM_01_0_upload_image_to_materials(AcceptanceTester $I, \Codeception\Example $example) {

    $I->wantTo('GM310_08 - Upload an Image and list it in under Materials - ' . $example['mime']);

    //gruppenbenutzer
    $GROUPMANAGER = $I->haveUser([
      'firstname' => 'Founder',
      'lastname' => microtime(true),
    ]);
    $fileTitle = "Meine Datei " . time();

    $I->loginAsUser($GROUPMANAGER);

    // Gruppe 1
    $I->expect('Founding a new group');
    $I->amOnPage("/groups");
    $I->click('Gruppe gründen');
    $I->checkFirstCategory();
    $title = 'Group GM310_08_CR_upload_single-' . microtime(true);
    $I->submitForm('#group-node-form', ['title' => $title,]);

    $I->completedSetup();

    $I->amOnPage("/groups");
    $I->see($title);
    $I->click($title, '.main_layout_right');

    $I->checkAK("310.08", "AK 1: Beim Hochladen einer Datei einer einer Gruppe bleibt der Kontext erhalten.");
    $I->see("Datei einstellen", '.main_layout_right');
    $nodeId = $I->grabFromCurrentUrl('/node\/(\d+)/');
    $I->click("Datei einstellen", '.main_layout_right');

    $I->seeLink("Hochladen");
    $I->seeLink("Dateien hinzufügen");
    $I->seeLink("Externer Link");

    $I->attachFile('input[type="file"]', $example['file']);
    $I->click('Übertragen beginnen');
    //$I->wait(1);
    $I->waitForText('1/1 Dateien hochgeladen');
    $I->click('Weiter');

    $I->waitForText('Speichern');

    $I->expect("Fill all required fields lets me save the file");
    $I->seeInField('#edit-field-file-license-type-und', 'CC BY Namensnennung');
    $I->seeInField('#edit-field-file-originator-und-0-value', $GROUPMANAGER->realname);
    //we have to decide here between image or not image
    $titleId = 'edit-field-file-image-title-text-und-0-value';

    $I->fillField('//*[@id="'.$titleId.'"]', $fileTitle);
    $I->executeJS('jQuery("label:contains(\"Noch nicht einsortiert\") input").click()');
    $I->selectOption('//*[@id="edit-field-file-license-type-und"]','CC_BY');
    $I->fillField('//*[@id="edit-field-file-originator-und-0-value"]', "Aristoteles Homer");
    $I->click('Speichern');
    $I->checkAK("310.08", "AK 1.1: Nach Abschluss der Uploads wird der Nutzer in die zuletzt aktive Gruppe umgeleitet.");
    $I->see("$fileTitle wurde aktualisiert");
    $I->seeInCurrentUrl('/groups/' . $nodeId . '/files/term/');

    // not group context
    $I->expect("With no group context, is redirect to file");
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
    $I->wait(1);
    $I->see('Das Feld „Themenfeld(er)” ist erforderlich.');
    $I->seeInField('#edit-field-file-license-type-und', 'CC BY Namensnennung');

    //$I->see("Das Feld „Urheber” ist erforderlich.");
    $I->seeInField('#edit-field-file-originator-und-0-value', $GROUPMANAGER->realname);

    $I->expect("Fill all required fields lets me save the file");
    //we have to decide here between image or not image
    $titleId = 'edit-field-file-image-title-text-und-0-value';

    $I->fillField('//*[@id="'.$titleId.'"]', $fileTitle);
    $I->executeJS('jQuery("label:contains(\"Noch nicht einsortiert\") input").click()');
    $I->selectOption('//*[@id="edit-field-file-license-type-und"]','CC_BY');
    $I->fillField('//*[@id="edit-field-file-originator-und-0-value"]', "Aristoteles Homer");
    $I->click('Speichern');
    $I->see("$fileTitle wurde aktualisiert");
    $I->seeInCurrentUrl('/file');
    $I->seeLink("Datei bearbeiten");
  }

  /**
   * WN-77 Dateien in Gruppe hochladen
   * @UserStory 77 - https://ghostthinker.atlassian.net/browse/WN-77
   * @Task https://ghostthinker.atlassian.net/browse/WN-77
   *
   * @example { "file": "images/150524-19-50.jpg", "type": "image", "mime":"image/jpeg" }
   *
   * @param \AcceptanceTester $I
   * @param \Codeception\Example $example
   */
  public function GM_02_0_subscribe_to_material(AcceptanceTester $I, \Codeception\Example $example) {

    $I->wantTo('WN-77 - Subscribe to a material - ' . $example['mime']);

    //gruppenbenutzer
    $USER_WITH_MATERIAL_ABO = $I->haveUser([
      'firstname' => '$USER_WITH_MATERIAL_ABO',
      'lastname' => microtime(true),
    ]);

    $USER_WITH_MATERIAL= $I->haveUser([
      'firstname' => 'USER_MATERIAL',
      'lastname' => microtime(true),
    ]);

    $fileTitle = "Meine Datei " . time();

    $I->loginAsUser($USER_WITH_MATERIAL);

    $title = 'Group WN-77' . microtime(true);

    $group = $I->createGroup($USER_WITH_MATERIAL,[
      'title' => $title,
    ]);

    $I->addMemberToGroup($USER_WITH_MATERIAL_ABO, $group->nid);

    $I->completedSetup();

    $I->amOnPage("/groups");
    $I->see($title);
    $I->click($title, '.main_layout_right');

    $I->checkAK("310.08", "AK 1: Beim Hochladen einer Datei einer einer Gruppe bleibt der Kontext erhalten.");
    $I->see("Datei einstellen", '.main_layout_right');
    $nodeId = $I->grabFromCurrentUrl('/node\/(\d+)/');
    $I->click("Datei einstellen", '.main_layout_right');

    $I->seeLink("Hochladen");
    $I->seeLink("Dateien hinzufügen");
    $I->seeLink("Externer Link");

    $I->attachFile('input[type="file"]', $example['file']);
    $I->click('Übertragen beginnen');
    //$I->wait(1);
    $I->waitForText('1/1 Dateien hochgeladen');
    $I->click('Weiter');

    $I->waitForText('Speichern');

    $I->expect("Fill all required fields lets me save the file");
    $I->seeInField('#edit-field-file-license-type-und', 'CC BY Namensnennung');
    $I->seeInField('#edit-field-file-originator-und-0-value', $USER_WITH_MATERIAL->realname);
    //we have to decide here between image or not image
    $titleId = 'edit-field-file-image-title-text-und-0-value';
    $sumID = $I->grabFromCurrentUrl('/edit-multiple\/(\d+)/');

    $I->fillField('//*[@id="'.$titleId.'"]', $fileTitle);
    $I->executeJS('jQuery("label:contains(\"Noch nicht einsortiert\") input").click()');
    $I->selectOption('//*[@id="edit-field-file-license-type-und"]','CC_BY');
    $I->fillField('//*[@id="edit-field-file-originator-und-0-value"]', "Aristoteles Homer");
    $I->click('Speichern');
    $I->checkAK("310.08", "AK 1.1: Nach Abschluss der Uploads wird der Nutzer in die zuletzt aktive Gruppe umgeleitet.");
    $I->see("$fileTitle wurde aktualisiert");
    $I->seeInCurrentUrl('/groups/' . $nodeId . '/files/term/');

    $I->loginAsUser($USER_WITH_MATERIAL_ABO);
    $I->amOnPage("/file/".$sumID);
    $I->seeElement('.flag-outer-notification-subscribe-material');
    $I->see('Abonnieren');
    $I->dontSeeElement('.flag-outer-notification-subscribe-material .action-unflag');

    //click abonnieren
    $I->click('Abonnieren');
    $I->see('Abonniert');
    $I->seeElement('.flag-outer-notification-subscribe-material .action-unflag');

    //Deabonnieren
    $I->click('.flag-outer-notification-subscribe-material .action-unflag a');
    $I->see('Abonnieren');
    $I->dontSee('Abonniert');

    $I->expect('to get a notification');
    $I->click('Abonnieren');
    $I->loginAsUser($USER_WITH_MATERIAL);
    $I->amOnPage("/file/".$sumID);
    $I->click('Datei bearbeiten');
    $I->fillField('//*[@id="'.$titleId.'"]', 'new title');
    $I->click('Speichern');

  }

  /**
   * WN-77 Dateien in Gruppe hochladen
   * @UserStory 77 - https://ghostthinker.atlassian.net/browse/WN-77
   * @Task https://ghostthinker.atlassian.net/browse/WN-77
   *
   * @example { "file": "images/150524-19-50.jpg", "type": "image", "mime":"image/jpeg" }
   *
   * @param \AcceptanceTester $I
   * @param \Codeception\Example $example
   */
  public function GM78_autosubscribe_to_material(AcceptanceTester $I, \Codeception\Example $example) {
    return TRUE;
    $I->wantTo('WN-78 - Autosubscribe to a material - ' . $example['mime']);

    //gruppenbenutzer
    $USER_WITH_MATERIAL_ABO = $I->haveUser([
      'firstname' => '$USER_WITH_MATERIAL_ABO',
      'lastname' => microtime(true),
    ]);

    $USER_WITH_MATERIAL= $I->haveUser([
      'firstname' => 'USER_MATERIAL',
      'lastname' => microtime(true),
    ]);

    $fileTitle = "Meine Datei " . time();

    $I->loginAsUser($USER_WITH_MATERIAL);

    $title = 'Group WN-77' . microtime(true);

    $group = $I->createGroup($USER_WITH_MATERIAL,[
      'title' => $title,
    ]);

    $I->addMemberToGroup($USER_WITH_MATERIAL_ABO, $group->nid);

    $I->completedSetup();

    $I->amOnPage("/groups");
    $I->see($title);
    $I->click($title, '.main_layout_right');

    $I->see("Datei einstellen", '.main_layout_right');
    $nodeId = $I->grabFromCurrentUrl('/node\/(\d+)/');
    $I->click("Datei einstellen", '.main_layout_right');

    $I->seeLink("Hochladen");
    $I->seeLink("Dateien hinzufügen");
    $I->seeLink("Externer Link");

    $I->attachFile('input[type="file"]', $example['file']);
    $I->click('Übertragen beginnen');
    //$I->wait(1);
    $I->waitForText('1/1 Dateien hochgeladen');
    $I->click('Weiter');

    $I->waitForText('Speichern');

    $I->expect("Fill all required fields lets me save the file");
    $I->seeInField('#edit-field-file-license-type-und', 'CC BY Namensnennung');
    $I->seeInField('#edit-field-file-originator-und-0-value', $USER_WITH_MATERIAL->realname);
    //we have to decide here between image or not image
    $titleId = 'edit-field-file-image-title-text-und-0-value';
    $sumID = $I->grabFromCurrentUrl('/edit-multiple\/(\d+)/');

    $I->fillField('//*[@id="'.$titleId.'"]', $fileTitle);
    $I->executeJS('jQuery("label:contains(\"Bildung\") input").click()');
    $I->selectOption('//*[@id="edit-field-file-license-type-und"]','CC_BY');
    $I->fillField('//*[@id="edit-field-file-originator-und-0-value"]', "Aristoteles Homer");
    $I->click('Speichern');
    $I->see("$fileTitle wurde aktualisiert");
    $I->seeInCurrentUrl('/groups/' . $nodeId . '/files/term/');

    $I->loginAsUser($USER_WITH_MATERIAL_ABO);
    $I->amOnPage('notifications/settings');
    $I->selectOption('//*[@id="edit-community-area-auto-subscribe-materials-0"]','1');
    $I->click('Speichern');


    $I->amOnPage("/file/".$sumID);
    $I->seeElement('.flag-outer-notification-ignore-post');

    $I->see('Auto-Aboniert');
    $I->seeElement('.flag-outer-notification-ignore-post .action-unflag');

    //click ignorieren
    $I->click('.flag-outer-notification-ignore-post .action-unflag a');
    $I->see('Ignoriert');
    $I->dontSeeElement('.flag-outer-notification-ignore-post .action-unflag');

    $I->expect('that the material is now listed in ignored materials');
    $I->amOnPage('notifications settings');
    $I->click('Ignored materials');
    $I->see('Titel');
    $I->see('Typ');
    $I->see('Letzte Aktualisierung');
    $I->see('Wieder Benachrichtigen');
    $I->dontSee('Sie haben keine Materialien ignoriert.');
    $I->see($fileTitle);

  }
}
