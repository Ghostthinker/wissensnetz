<?php

use Helper\Bildungsnetz;


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



  public function addEAtoOrganisation($ea_ids = [], $og_id = 104) {
    $this->amOnPage('node/' . $og_id . '/edit');
    foreach ($ea_ids as $id) {
      $this->click('.form-item-field-organisation-earemotes-und-'.$id.' .checkmark');
    }

    $this->see('Speichern');
    $this->click('Speichern');
  }

  //region Content creation
  public function createLicenseWithPrequalifications($og) {

    $options = \Helper\Bildungsnetz::getLicenseOptions($og->nid);
    $c = ['ea_nid' => 335];
    $c = array_merge($options, $c);
    $licenseC = $this->haveDOSBLicense($og, $c);
    $licenseC = dosb_license_load($licenseC->lid);
    $licenseC->request();
    $licenseC->lock();

    $b = [
      'ea_nid' => 336,
      //"valid_until" => strtotime("now + 1 years"),
      'prequalification_type' => 'DOSB',
      'prequalification_number' => $licenseC->license_number_dosb,
    ];
    $b = array_merge($options, $b);
    $licenseB = $this->haveDOSBLicense($og, $b);
    $licenseB = dosb_license_load($licenseB->lid);
    $licenseB->request();
    $licenseB->lock();

    $a = [
      'ea_nid' => 337,
      //"valid_until" => strtotime("now + 1 months"),
      'prequalification_type' => 'DOSB',
      'prequalification_number' => $licenseB->license_number_dosb,
    ];
    $a = array_merge($options, $a);
    $licenseA = $this->haveDOSBLicense($og, $a);
    $licenseA = dosb_license_load($licenseA->lid);
    $licenseA->request();
    $licenseA->lock();

    return array('licenseA' => $licenseA, 'licenseB' => $licenseB, 'licenseC' => $licenseC);
  }

  public function createWBM($options = array(), $wbm_og = '104') {
    $this->amOnPage('node/add/lehrgang?field_wbm_organisation=' . $wbm_og);

    $date = new DateTime();
    $date->setTimestamp(strtotime('now + 1 years'));
    $this->submitForm("#weiterbildungsmassnahme-node-form",[
      'title' => $options['title'],
      'field_wbm_ort[und][0][value]' => $options['ort'],
      'field_wbm_time[und][0][value2][date]' => $date->format('d.m.Y'),
      'field_wbm_additional_info[und][0][value]' => $options['additional'],
    ]);

    $this->see($options['title']);
    $node_id = $this->grabFromCurrentUrl('/node\/(\d+)/');
    return $node_id;
  }

  public function createBeitrag($options = array()) {
    $I = $this;
    $defaults = [
      'Titel' => "test",
      'Kategorie' => 1781,
      'Schlagworte' => "Test",
      'Inhalt' => "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.",
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'Änderungszugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'Gruppenzugriff' => '_none',
    ];
    $options = array_merge($defaults, $options);

    $I->amOnPage('node/add/post');

    //$I->fillEditor($options['Inhalt'], '#cke_1_contents body p');//'edit-body-und-0-value');
    $I->fillCkEditorById('1_contents', $options['Inhalt']);

    $I->click('.form-item-field-kb-content-category-und-0-' .$options['Kategorie']. '-' .$options['Kategorie'] . ' .checkmark');
    //$I->checkOption('field_kb_content_category[und][0]['.$options['Kategorie'].']['.$options['Kategorie'].']');

    $I->submitForm("#post-node-form",[
      'title' => $options['Titel'],
      //'field_kb_content_category[und][0]['.$options['Kategorie'].']['.$options['Kategorie'].']' => 1,
      'field_post_tags[und]' => $options['Schlagworte'],
      'field_post_collaboration[und][0][read]' => $options['Lesezugriff'],
      'field_post_collaboration[und][0][edit]' => $options['Änderungszugriff'],
      // 'body[und][0][value]' => $options['Inhalt'],
      'field_og_group[und][0][default]' => $options['Gruppenzugriff'],
    ]);

    // i dont know why submitForm is break, fixing: submit with click
    //$I->seeElement('.btn.btn-success.form-submit');
    if ($options['Lesezugriff'] == 1) {
      $I->seeElement('#edit-submit');
      $I->see('Speichern');
      $I->click('Speichern');
    }

    $I->waitForText($options['Titel'], 20);
    $I->see($options['Inhalt'], 'p');
  }

  public function createGroupBeitrag($options = array(), $gid) {
    $I = $this;
    $defaults = [
      'Titel' => "test",
      'Kategorie' => 1781,
      'Schlagworte' => "Test",
      'Inhalt' => "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.",
      'Lesezugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
      'Änderungszugriff' => SALTO_KNOWLEDGEBASE_ACCESS_OPTION_ALL,
    ];
    $options = array_merge($defaults, $options);

    $I->amOnPage('node/add/post?field_og_group=' . $gid);

    //$I->fillEditor($options['Inhalt'], '#cke_1_contents body p');//'edit-body-und-0-value');
    $I->fillCkEditorById('1_contents', $options['Inhalt']);

    $I->click('.form-item-field-kb-content-category-und-0-' .$options['Kategorie']. '-' .$options['Kategorie'] . ' .checkmark');
    //$I->checkOption('field_kb_content_category[und][0]['.$options['Kategorie'].']['.$options['Kategorie'].']');

    $I->submitForm("#post-node-form",[
      'title' => $options['Titel'],
      //'field_kb_content_category[und][0]['.$options['Kategorie'].']['.$options['Kategorie'].']' => 1,
      'field_post_tags[und]' => $options['Schlagworte'],
      'field_post_collaboration[und][0][read]' => $options['Lesezugriff'],
      'field_post_collaboration[und][0][edit]' => $options['Änderungszugriff'],
      // 'body[und][0][value]' => $options['Inhalt'],
    ]);

    $I->waitForText($options['Titel'], 20);
    $I->see($options['Inhalt'], 'p');
  }

  public function submitDOSBLicenseForm($ogNid, $options = array()) {
    $defaults = \Helper\Bildungsnetz::getLicenseOptions();
    $options = array_merge($defaults, $options);

    if (is_numeric($options['issue_date'])) {
      $options['issue_date'] = date('d.m.Y', $options['issue_date']);
    }
    if (is_numeric($options['valid_until'])) {
      $options['valid_until'] = date('d.m.Y', $options['valid_until']);
    }
    if (is_numeric($options['birthdate'])) {
      $options['birthdate'] = date('d.m.Y', $options['birthdate']);
    }

    $this->amOnPage('organisations/' . $ogNid . '/licenses/created?og_ref=' . $ogNid . '');
    $this->waitForElement('.btn-details-row', 20);
    //$this->click('//a[@class="btn btn-details-row"][1]');//'.btn-details-row');
    //$this->executeJS('jQuery("a.btn.btn-details-row").click()');
    //dosb_license/106854/edit?destination=organisations/104/licenses/created
    $lid = $this->grabAttributeFrom('.btn.btn-view-row', 'data-lid');
    $this->amOnPage('dosb_license/'. $lid . '/edit?destination=dosb_license/'. $lid . '');
    //$this->waitForText('Lizenzdaten', 30, '#dosb-license-edit-form');
    $this->see('Lizenzdaten', '#dosb-license-edit-form');

    if (!empty($options['prequalification_number'])) {
      $this->selectOption('//*[@name="prequalification_type"]', $options['prequalification_type']);
    }

    $this->submitForm("#dosb-license-edit-form",[
      'firstname' => $options['firstname'],
      'lastname' => $options['lastname'],
      'title' => $options['title'],
      'birthdate[date]' => $options['birthdate'],
      'gender' => $options['gender'],
      'street' => $options['street'],
      'postal' => $options['postal'],
      'city' => $options['city'],
      'ea_nid' => $options['ea_nid'],
      'valid_until[date]' => $options['valid_until'],
      'issue_date[date]' => $options['issue_date'],
      'issue_place' => $options['issue_place'],
      'honor_code' => $options['honor_code'],
      'first_aid' => $options['first_aid'],
      'prequalification_type' => $options['prequalification_type'],
      'prequalification_number' => $options['prequalification_number'],
      'custom_1' => $options['custom_1'],
      'custom_2' => $options['custom_2'],
    ]);
  }

  public function createSingleLicense($ogNid, $options = array(), $asStub = TRUE) {
    $this->submitDOSBLicenseForm($ogNid, $options);

    $this->dontSee(t("Please change licence holder information and prequalification number in two differen"));

    $this->see($options['firstname'], 'td');
    $this->see($options['birthdate'], 'td');

    //return $this->grabTextFrom('.entity-dosb-license.dosb-license-dosb-license h2');
    $lid = $this->grabFromCurrentUrl('/dosb_license\/(\d+)/');
    if ($asStub) { return $lid; }

    $license = dosb_license_load($lid);
    $license->request();
    $license->lock();
    return $license;
  }

  public function editSingleLicense($options = array()) {
    $defaults = \Helper\Bildungsnetz::getLicenseOptions();
    $options = array_merge($defaults, $options);

    /* @var DOSBLicense $license */
    //$license = \Helper\Bildungsnetz::createLicense($options);
    $license = $this->haveDOSBLicense(null, $options);

    $license->status = LICENSE_STATUS_CREATED;
    $license->request();

    //$this->amOnPage('organisations/' . $og_id . '/licenses/created?og_ref=' . $og_id . '');
    //dosb_license/106854/edit?destination=organisations/104/licenses/created
    $this->amOnPage('dosb_license/'. $license->lid . '/edit?destination=dosb_license/'. $license->lid . '');

    $this->submitForm("#dosb-license-edit-form",[
      'firstname' => $options['firstname'],
      'lastname' => $options['lastname'],
      'title' => $options['title'],
      //'birthdate[date]' => $options['birthdate'],
      'gender' => $options['gender'],
      'street' => $options['street'],
      'postal' => $options['postal'],
      'city' => $options['city'],
      'ea_nid' => $options['ea_nid'],
      //'valid_until[date]' => $options['valid_until'],
      //'issue_date[date]' => $options['issue_date'],
      'issue_place' => $options['issue_place'],
      'honor_code' => $options['honor_code'],
      'first_aid' => $options['first_aid'],
      'prequalification_type' => $options['prequalification_type'],
      'prequalification_number' => $options['prequalification_number'],
      'custom_1' => $options['custom_1'],
      'custom_2' => $options['custom_2'],
    ]);

    $this->see($options['firstname'], 'td');
    $date = getdate($options['birthdate']);

    $birthDate = $date['mday'] . '.' . $date['mon'] . '.' . $date['year'];
    if ($date['mon'] < 10) {
      $birthDate = $date['mday'] . '.0' . $date['mon'] . '.' . $date['year'];
    }
    $this->see($birthDate, 'td');
    $this->see($license->license_number_dosb, 'td');

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
    $I->executeJS('jQuery("label:contains(\"Noch nicht einsortiert\") input").click()');
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

  public function anewRequestLicense() {
    $I = $this;
    $I->see('Lizenz neu anfordern');
    $I->click('Lizenz neu anfordern');

    $I->submitForm("#dosb-license-request-form", [
      'license_format' => '2'
    ]);

    $I->see('OK', 'button');
    $I->click('OK');
  }

  public function checkAK($userStory, $ak) {
    return $this->comment("I check $userStory  -> $ak ");
  }

  public function unsetNotificationLicenseMarkedForExtension($user) {
    $I = $this;
    $I->loginAsUser($user);
    $I->amOnPage("/notifications/settings");
    $I->seeCheckboxIsChecked('#edit-notification-licenses-marked-for-extension-status');
    $I->seeCheckboxIsChecked('#edit-notification-licenses-marked-for-extension-mail');
    $I->click('.form-item-notification-licenses-marked-for-extension-status .checkmark');
    $I->click('.form-item-notification-licenses-marked-for-extension-mail .checkmark');
    $I->dontSeeCheckboxIsChecked('#edit-notification-licenses-marked-for-extension-status');
    $I->dontSeeCheckboxIsChecked('#edit-notification-licenses-marked-for-extension-mail');
    $I->click('Speichern');
  }

  function clickOnLicenseInGrid($lid) {
    $I = $this;
    //$I->see('Lizenz neu anfordern');
    //$I->click('Lizenz neu anfordern');
    $I->clickWithLeftButton('a[data-lid='.$lid.']');
  }

  function getAccessDenied() {
    $this->see(t('You are not authorized to access this page.'));
  }

  function notAccessDenied() {
    $this->dontSee(t('You are not authorized to access this page.'));
  }

/*
  public function addMemberToGroup($account, $gid) {
    //join group and respond with new action link
    og_group('node', $gid, [
      'entity_type' => 'user',
      'entity' => $account,
      'membership type' => 'group_membership',
    ]);
  }
*/

  /**
   * @param $selector
   * @param $offsetX
   */
  public function scrollHandsomeTableRight($selector) {
    $this->executeJS('var width = jQuery("' . $selector . ' .wtHolder").width();
        var widthProg = 0;
        var stepWidth = width/50;
        
        var interval = setInterval(function() {
            widthProg = widthProg+stepWidth;
            if(widthProg >= width) {
                widthProg = width;
                clearInterval(interval);
            }
            jQuery("#dosb_license_table").scrollLeft(widthProg);
        }, 50);
      ');
    $this->wait(3);

  }

  public function scrollHandsomeTable($selector, $posX) {
    $this->executeJS('var width = jQuery("' . $selector . ' .wtHolder").width();
        var widthProg = 0;
        var stepWidth = width/50;
        
        var interval = setInterval(function() {
            widthProg = widthProg+stepWidth;
            if(widthProg >= width) {
                widthProg = width;
                clearInterval(interval);
            }
            jQuery("#dosb_license_table").scrollLeft("' . $posX . '");
        }, 50);
      ');
    $this->wait(3);
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

  function checkCategoryEducation() {
    $linkCss = '.form-item-field-group-categories-und-';
    $linkCss .= Bildungsnetz::KB_CATEGORY_EDUCATION;
    $linkCss .= ' .control-label';
    $this->click($linkCss, '#edit-field-group-categories');
  }

}
