<?php

use Helper\Wissensnetz;


/**
 * Inherited Methods
 * @method void wantToTest($text)
 * @method void wantTo($text)
 * @method void execute($callable)
 * @method void expectTo($prediction)
 * @method void expect($prediction)
 * @method void amGoingTo($argumentation)
 * @method void am($role)
 * @method void lookForwardTo($achieveValue)
 * @method void comment($description)
 * @method \Codeception\Lib\Friend haveFriend($name, $actorClass = NULL)
 *
 * @SuppressWarnings(PHPMD)
*/
class AcceptanceTester extends \Codeception\Actor
{
    use _generated\AcceptanceTesterActions;
    use \Traits\EditorTrait;

   /**
    * Define custom actions here
    */

  public function loginAsUser($account) {

    $I = $this;
    $I->logout();
    $I->amOnPage('/');

    $I->submitForm('#desktop-login-form #user-login-form', [
      'name' => $account->mail,
      'pass' => $account->password
    ]);
  }

  public function logout() {
    $I = $this;
    $I->amOnPage('user/logout');
  }

  public function createBeitrag($options = array()) {
      $node = bildungsnetz_api_create_post($options);
      return $node;
  }

  public function createGroupBeitrag($options = array(), $gid) {
    $I = $this;
    $defaults = [
      'Titel' => "test",
      'Schlagworte' => "Test",
      'Inhalt' => "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.",
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'Änderungszugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
    ];
    $options = array_merge($defaults, $options);

    $I->amOnPage('node/add/post?field_og_group=' . $gid);
    $I->fillfield('title', $options['Titel']);
    $I->fillCkEditorById('1_contents', $options['Inhalt']);

    if (empty($options['Kategorie'])){
      //check first group themenfeld
      $I->executeJS("return document.querySelector('.select-parents.form-checkbox').click()");
    }else if($options['Kategorie']){
      $I->click('.form-item-field-kb-content-category-und-0-' .$options['Kategorie']. '-' .$options['Kategorie'] . ' .checkmark');
    }else{
      $I->click('.form-item-field-kb-content-category-und-0-1781-1781 .checkmark');
    }

    $I->click('Speichern');

    $I->waitForText($options['Titel'], 20);
    $I->see($options['Inhalt'], 'p');
  }


  public function createFile($options = array()) {

    $I = $this;

    $defaults = [
      'title' => 'Sample file',
      'file' => 'images/150524-19-50.jpg',
      'type' => 'image',
      'access_read' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS,
      'access_write' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_AUTHORS
    ];

    $options = array_merge($defaults, $options);

    $I->amOnPage('file/add_anything');

    $I->attachFile('input[type="file"]', $options['file']);
    $I->click('Weiter');
    $I->wait(1);

    //we have to decide here between imaeg and not image
    if($options['type'] == 'image') {
      $title_id = 'edit-field-file-image-title-text-und-0-value';
    }else{
      $title_id = 'edit-field-file-title-und-0-value';
    }

    $I->fillField('//*[@id="'. $title_id . '"]', $options['title']);
    $I->executeJS('jQuery("label:contains(\"Digitalisierung\") input").click()');
    $I->selectOption('//*[@id="edit-field-file-license-type-und"]','CC_BY');
    $I->fillField('//*[@id="edit-field-file-originator-und-0-value"]', "Aristoteles Homer");

    $I->selectOption('//*[@id="edit-field-post-collaboration-und-0-read"]', $options['access_read']);
    $I->selectOption('//*[@id="edit-field-post-collaboration-und-0-edit"]', $options['access_write']);

    $I->click('Speichern');

    $I->see("{$options['title']} wurde aktualisiert");
    $I->seeLink("Datei bearbeiten");
      $file_id = $I->grabFromCurrentUrl('/file\/(\d+)/');
    return $file_id;
  }
  //endregion

  public function seeDate($timestamp, $selector = null) {

    $validDate = date("d.m.Y", $timestamp);

    if ($selector !== null) {
      $this->see($validDate, $selector);
    } else {
      $this->see($validDate);
    }
  }

  public function checkAK($userStory, $ak) {
    return $this->comment("I check $userStory  -> $ak ");
  }

  function getAccessDenied() {
    $this->see(t('You are not authorized to access this page.'));
  }

  function notAccessDenied() {
    $this->dontSee(t('You are not authorized to access this page.'));
  }

  function clickJS($title, $selector) {
    $this->executeJS('var els = document.querySelectorAll("' . $selector . '");
      for (var i = 0; i < els.length; i++) {
        if (els[i].innerHTML.indexOf("' . $title . '") != -1) { 
          els[i].click();
          break;
        }
      }
    ');
    $this->wait(5);
  }

  function clickJQuery($title, $selector) {
    $selector = $selector .':contains(' . $title . ')';
    $this->executeJS('jQuery("' . $selector . '").trigger("click");');
    $this->wait(3);
  }

  function checkFirstCategory() {
    $this->executeJS("return document.querySelector('#edit-field-group-categories-und .form-checkbox').click()");
  }

}
