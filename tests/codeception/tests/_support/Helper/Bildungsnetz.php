<?php

namespace Helper;

// here you can define custom actions
// all public methods declared in helper class will be available in $I

use BlankCleanup;
use PHPUnit\Runner\Exception;

include_once DRUPAL_ROOT . '/sites/all/modules/features/salto_core/queue/CoreSystemQueue.php';

define('SALTO_INVITE_IV', '2e2a3c00279740e907ae94775dae574b');

class Bildungsnetz extends \Codeception\Module {

  const KB_CATEGORY_DOSB_LIZENZMANAGMENT = 2643;
  const KB_CATEGORY_EDUCATION = SALTO_KNOWLEDGEBASE_KB_EDUCATION_TID;
  const KB_CATEGORY_FALLBACK = SALTO_KNOWLEDGEBASE_KB_FALLBACK_TID;
  const TIME_TO_WAIT_FOR_NOTIFICATIONS = 11;

  private $mailSystemOriginal = null;

  // HOOK: before each suite
  public function _beforeSuite($settings = array()) {
    variable_set('salto_protect_on_leave', 0);
    variable_set('jreject_enable', 0);
    variable_set('gt_privacy_cookie_banner_enabled', 0);

    $node = bildungsnetz_api_create_organisation('Fallback-OG');
    variable_set('salto_organisation_fallback_nid', $node->nid);

    //STOP YOU PUNK - do not remove this - we need a clear testing instance
    //after every test!
    $this->clearInstance();
  }

  // HOOK: after suite
  public function _afterSuite() {
    variable_set('salto_protect_on_leave', 1);
    variable_set('jreject_enable', 1);
  }

  public function fillEditor($text, $selector) {
    //$id = $this->getModule("WebDriver")->executeJs("return document.querySelector('#$selector').id");
    $this->getModule("WebDriver")->executeJs("CKEDITOR.instances['$selector'].setData(" . json_encode($text) . ")");
  }

  public function clearInstance() {
    //Clear dosb_licenses
    db_query("DELETE FROM {dosb_license}");
    $keepOgs = [BlankCleanup::OG_GHOSTTHINKER_ID, BlankCleanup::OG_FALLBACK_ID];
    $keepTypes = ['help', 'page', 'earemote'];
    // salto_debug_blank_cleanup_node_types(['earemote']);
    salto_debug_blank_cleanup_content($keepOgs);
    salto_debug_blank_cleanup_og_fallback();
    salto_debug_blank_cleanup_users($keepOgs);
    salto_debug_blank_cleanup_nodes_with_ogs($keepOgs, $keepTypes);
    db_query("DELETE FROM file_managed WHERE uid NOT IN (SELECT u.uid FROM users u)")->execute();

  }


  public static function getLicenseOptions($og_nid = 104) {
    return [
      'ankle' => '',
      'title' => '',
      'og_nid' => $og_nid,
      'firstname' => 'Jane',
      'lastname' => 'Doe',
      'birthdate' => 551270108,
      'gender' => 'weiblich',
      'street' => '123 fakestreet',
      'postal' => 42431,
      'city' => 'Hamburg',
      'ea_nid' => 336,
      "valid_until" => strtotime("now + 1 years"),
      "issue_date" => strtotime("now"),
      "issue_place" => "Hamburg ",
      "honor_code" => "1",
      "first_aid" => "0",
      "first_aid_date" => "",
      'prequalification_type' => 'nicht benötigt',
      'prequalification_number' => '',
      'custom_1' => 'Eine Test-Lizenz',
      'custom_2' => '',
    ];
  }

  public static function getLicenseOptionsWithoutEA($og_nid = 104) {
    return [
      "postal" => "42431",
      "organisation_id" => $og_nid,
      "mail" => "test@example.com",
      "training_course_id" => 376,
      "firstname" => "Förstnäme",
      "lastname" => "Laßtnöim",
      "academic_title" => "Dr.",
      "birthdate" => "539129794",
      "gender" => "w",
      "street" => "123 fakestreet",
      "city" => "Hamburg",
      "valid_until" => strtotime("now + 1 years"),
      "issue_date" => strtotime("now"),
      "issue_place" => "Hamburg ",
      "honor_code" => "1",
      "honor_code_date" => "1422742594",
      "first_aid" => "0",
      "first_aid_date" => ""
    ];
  }

  /**
   * Wrapper to create a single user
   * @param array $options
   * @return \stdClass
   * @throws \Exception
   */
  public function haveUser($options = []) {

    $account = bildungsnetz_api_create_user($options);
    if ($options['mail']) {
      $this->setMailNotificationImmediate($account->uid);
    }

    return $account;
  }

  /**
   * Create a comment to a node or a file
   * @param $entity
   * @param array $options
   *
   * @return false
   */
  public function haveComment($entity, $options = []) {

    if(!empty($entity->fid)) {
      $nid = $entity->field_file_comments[LANGUAGE_NONE][0]['target_id'];
      $node = node_load($nid);
    }else{
      $node = $entity;
    }

    return bildungsnetz_api_add_add_comment($node, $options);
  }

  public function setMailNotificationImmediate($uid) {
    onsite_notification_settings_update($uid, 'general', array("mail_frequency" => NOTIFICATION_FREQUENCY_IMIDIATE));
  }

  public function haveAdmin() {
    $account = $this->haveUser();
    $account->roles[ROLE_ADMIN_RID] = ROLE_ADMIN_RID;
    $account = user_save($account);
    return $account;
  }

  public static function createOrganisation($title, $options = []) {

    $node = bildungsnetz_api_create_organisation($title, $options);
    return $node;
  }


  /**
   *
   */
  public static function clearFlood() {
    db_delete('flood')
      ->execute();
  }

  /**
   * Generate valid sample data for a license request
   * @param $VERBAND
   * @return array
   */
  public static function generateLicenseRandomSampleRequestData($VERBAND) {

    $default_name = _salto_debug_generate_name();

    $license_data_client = [
      "postal" => "42431",
      "organisation_id" => $VERBAND->nid,
      "mail" => "test@example.com",
      "training_course_id" => end($VERBAND->field_organisation_earemotes[LANGUAGE_NONE])['target_id'],
      'firstname' => $default_name['first'],
      'lastname' => $default_name['last'],
      "birthdate" => "539129794",
      "gender" => array_rand(array_flip(array("w", "m"))),
      "street" => "123 fakestreet",
      "city" => "Hamburg",
      "valid_until" => strtotime("now + 1 years"),
      "issue_date" => strtotime("now"),
      "issue_place" => "Hamburg ",
      "honor_code" => "1",
      "honor_code_date" => "1422742594",
      "first_aid" => "0",
      "first_aid_date" => "",
      "license_holder_uuid" => "sn-2018-04-26-" . $default_name['first'] . "-" . $default_name['last'],
    ];

    return $license_data_client;
  }

  ///////////////////////////////////////////
  // New test style 03.08.2017 - 13:32 - SH
  //////////////////////////////////////////
  /*
  * Call this after defining content
  */
  public function completedSetup() {
    //we need to reset the cache that prevents the sending of new material und update material events
    drupal_static('onsite_notification_file_presave', NULL, TRUE);
  }

  public function haveDOSBUser($organisation = null) {
    $password = md5(time());
    $account = bildungsnetz_api_create_user([
      'pass' => $password,
      'role_dosb' => TRUE
    ]);
    $account->password_cleartext = $password;

    if ($organisation !== null) {
      bildungsnetz_api_add_user_to_organisation($account, $organisation, array(SALTO_ORGANISATION_OG_ROLE_LIZENZVERWALTER_RID));
    }

    return $account;
  }

  public function haveAPIUser($organisation) {

    $password = md5(time());
    $account = bildungsnetz_api_create_user([
      'pass' => $password,
      'role_api_user' => TRUE
    ]);

    $account->password_cleartext = $password;

    bildungsnetz_api_add_user_to_organisation($account, $organisation, array(SALTO_ORGANISATION_OG_ROLE_LIZENZVERWALTER_RID));

    return $account;
  }


  public function haveWBM($organisation, $options = []) {
    $node = bildungsnetz_api_create_lehrgang($organisation, $options);
    return $node;
  }


  public function haveOrganisation($title, $options = []) {
    if (!array_key_exists('earemotes', $options)) {
      if (module_exists('dosb_license')) {
        $ea = bildungsnetz_api_create_ea($options);
        $options['earemotes'] = [$ea->nid];
      }
    }
    $node = bildungsnetz_api_create_organisation($title, $options);
    return $node;
  }

  public function haveEA( $options = []) {
      return bildungsnetz_api_create_ea($options);
  }

  public function haveOnlineMeeting($options) {
      return bildungsnetz_api_create_online_meeting($options);
  }

  public function havePost($options){
      return bildungsnetz_api_create_post($options);
  }

public function haveMaterial($options){
    return bildungsnetz_api_create_material($options);
}

  public function initASLicenseManager($optionsUser = [], $optionsOG = []) {

    $user = $this->haveUser($optionsUser + ['role_lizenzmanager' => TRUE,]);

    $microTime = microtime(TRUE);

    $title = "LicenseTestOG-" . $microTime;
    $og = $this->haveOrganisation($title, [
        'body' => 'dummy license og',
        'earemotes' => $optionsOG['earemotes'] ? $optionsOG['earemotes'] : [335, 336, 337],
        'obscure' => $optionsOG['obscure'] ? $optionsOG['obscure'] : 0,
        'dv_license_settings' => $optionsOG['dv_license_settings'] ? $optionsOG['dv_license_settings'] : 'full', //none/read/full
        'parent' => $optionsOG['parent'] ? $optionsOG['parent'] : null,
        'language' => $optionsOG['language'] ? $optionsOG['language'] : 'en',
      ]
    );

    $this->addMemberToOrganisation($user, $og, [SALTO_ROLE_LICENSE_MANAGER_RID]);

    return ['user' => $user, 'og' => $og];
  }

  /**
   * Get the full path of a file in teh _sample folder
   * @param null $filename
   * @return string
   * @throws \Exception
   */
  public static function getSampleFilePath($filename = NULL) {
    $filepath = realpath(dirname(__FILE__) . "/../../_data/" . $filename);

    if (!file_exists($filepath)) {
      throw new Exception("File $filepath does not exist in sample folder");
    }
    return $filepath;
  }

  public function addMemberToOrganisation($account, $organisation, $roles = []) {

    bildungsnetz_api_add_user_to_organisation($account, $organisation, $roles);
  }

  public function haveDOSBLicense($organisation, $options = []) {

    $options['og_nid'] = $organisation->nid;
    $license = dosb_license_create($options);

    $license->save();
    return $license;
  }

  /**
   * Generate a sample valid license with a random ea_nid from the  organisation
   * @param $organisation
   * @param array $options_override  override options
   * @return mixed
   */
  public function haveAValidDOSBLicense($organisation, $options_override = array()) {

    //get sample data from here and chaneg some values
    $data = Bildungsnetz::generateLicenseRandomSampleRequestData($organisation);
    $data['og_nid'] = $data['organisation_id'];
    unset($data['organisation_id']);
    $data['ea_nid'] = $data['training_course_id'];
    unset($data['training_course_id']);

    if (empty($data['gender'])){
    $data['gender'] = array_rand(array_flip(array("weiblich", "männlich", "unbekannt")));
    }

    //apply overrides
    $data = array_merge($data, $options_override);

    if ($options_override['first_issue_date']) {
      $data['first_issue_date'] = $options_override['first_issue_date'];
      $data['origin'] = DOSB_LICENSE_ORIGIN_INVENTORY;
    }

    $license = dosb_license_create($data);
    $license->save();
    return $license;
  }

  public function createDOSBLicenseWithValidHistory($organisation, $options_override = array(), $history = array()) {

    $license = $this->haveAValidDOSBLicense($organisation, $options_override);
    //$license->createFirstHistoryEntryForInventory();
    $license->request();
    $license->lock();

    foreach ($history as $key => $array) {
      $license->issue_date = $array['issue_date'];
      $license->valid_until = $array['valid_until'];
      if ($array['requested']) {
        $license->extend(TRUE);
        $license->request();
      } else {
        $license->extend(FALSE);
      }
    }
    return $license;
  }

  public static function createLicense($options = []) {
    $license = dosb_license_create($options);
    $license->save();
    return $license;
  }

  public function seeAnAPiLog($uid, $response = NULL) {

    $query = db_select("lims_api_log")
      ->fields(lims_api_log)
      ->condition("uid", $uid);

    if($response) {
      $query->condition("response", $response);
    }

    $res = $query->execute();
    if(!$res->fetch()) {
      throw new \Exception("no api log found");
    }

  }

  /**
   * Get current url from WebDriver
   * @throws \Codeception\Exception\ModuleException
   */
  public function seeCurrentPageIs($url_expected) {
    $url =  $this->getModule('WebDriver')->_getCurrentUri();

    $this->assertEquals($url_expected, $url);
  }

  public function userIsInFallbackOG($user) {
    $account = clone $user;
    $this->assertTrue(salto_user_is_in_fallback_organisation($account));
  }

  public function userIsNotInFallbackOG($user) {
    $account = clone $user;
    $this->assertFalse(salto_user_is_in_fallback_organisation($account));
  }

  public function createItems($uid, $ogNid, $countValid = 10, $countInvalid = 20) {
    $array = array();
    for($k = 0; $k < $countValid; $k++)  {
      $array[] = $this->createImportItem($uid, $ogNid, $k);
    }

    $failIdx = array_flip([1, 2, 3, 4, 5, 6]);
    for($k = 0; $k < $countInvalid; $k++) {
      $item = $this->createImportItem($uid, $ogNid, $k + count($array));
      $idx = array_rand($failIdx);
      switch ($idx) {
        case 1:
          $item->firstname = '';
          break;
        case 2:
          $item->lastname = '';
          break;
        case 3:
          //310.04 #CR LV
          //issue date > valid_until
          $item->valid_until = date("d.m.Y", (strtotime($item->issue_date) - 3600));
          break;
        case 4:
          $item->issue_date = '';
          break;
        case 5:
          $item->birthdate = strtotime('now + 2 days');
          $item->birthdate = date('d.m.Y', $item->birthdate);
          break;
        case 6:
          $item->gender = '';
          break;
      }
      $array[] = $item;
    }

    return $array;
  }

  protected function createImportItem($uid, $ogNid, $count = 1) {

    $import_item = new \stdClass();
    $import_item->firstname = 'Sascha ' . $count;
    $import_item->lastname = 'Import ' . time();
    $year = array_rand(array_flip(range(20, 40)));
    $import_item->birthdate = strtotime('now - ' . $year . ' years');
    $import_item->birthdate = date('d.m.Y', $import_item->birthdate);
    $import_item->gender = array_rand(array_flip(array("weiblich", "männlich")));
    $import_item->mail = 'sascha@test.com';
    $import_item->street = 'TestWeg 53';
    $import_item->ea_nid = '376';
    $import_item->postal = '55550';
    $import_item->city = 'Mekka';
    $import_item->phone = '0160-5643210';
    $import_item->og_nid = $ogNid;
    $year = array_rand(array_flip(range(1, 20)));
    $import_item->first_issue_date = strtotime('now - ' . $year . ' years');
    $import_item->first_issue_date = date('d.m.Y', $import_item->first_issue_date);
    $year = array_rand(array_flip(array(0,1,2,3)));
    $import_item->valid_until = strtotime('now + ' . $year . ' years');
    $import_item->valid_until = date('d.m.Y', $import_item->valid_until);
    $import_item->issue_date = strtotime('now - ' . $year . ' years');
    $import_item->issue_date = date('d.m.Y', $import_item->issue_date);
    $import_item->issue_place = 'Johannesburg';
    $import_item->honor_code = array_rand(array(0, 1));
    if ($import_item->honor_code == 1) {
      $year = array_rand(array_flip(array(1,2,3,4)));
      $import_item->honor_code_date = strtotime('now - ' . $year . ' years');
      $import_item->honor_code_date = date('d.m.Y', $import_item->honor_code_date);
    } else {
      $import_item->honor_code_date = '';
    }
    $import_item->first_aid = array_rand(array(0, 1));
    if ($import_item->first_aid == 1) {
      $year = array_rand(array_flip(array(1,2,3,4)));
      $import_item->first_aid_date = strtotime('now - '. $year .' years');
      $import_item->first_aid_date = date('d.m.Y', $import_item->first_aid_date);
    } else {
      $import_item->first_aid_date = '';
    }
    $import_item->license_number_organisation = 'TESTNumber' . $ogNid;
    $import_item->prequalification_type = 'nicht benötigt';
    $import_item->prequalification_number = NULL;
    $import_item->custom_1 = 'Zusatzfeld 1';
    $import_item->custom_2 = 'Zusatzfeld 2';
    $import_item->uid = $uid;

    return $import_item;
  }

  /**
   * @param $user
   */
  public function deleteUser($user) {
    user_delete($user->uid);
  }


  public function getEAsByOrganisation($og) {
    return salto_licenses_get_earemotes_by_organisation($og);
  }

  public function getUserByMail($mail) {
    return user_load_by_mail($mail);
  }

  public function getPostsFromUser($user) {
    $nodes = salto_knowledgebase_get_nids_by_uid($user->uid);
    if (empty($nodes)) {
      return array();
    }
    return node_load_multiple(array_keys($nodes));
  }

  public static function getDOSBLicenseRepository() {
    return new \DOSBLicenseRepository();
  }

  public static function getDOSBLicenseValidityHistory($license) {
    return new \DOSBLicenseValidityHistory($license);
  }

  public static function rebuildValidityHistory($license) {
    dosb_license_validity_history_rebuild($license);
  }

  public static function getHistory($string) {
    $history = array();
    if (stripos($string, 'switchAndLast') !== false) {
      $history[] = array(
        'issue_date' => strtotime('01.04.2013'),
        'valid_until' => strtotime('30.04.2016'),
        'requested' => true
      );
      $history[] = array(
        'issue_date' => strtotime('29.04.2015'),
        'valid_until' => strtotime('30.04.2013'),
        'requested' => true
      );
      $history[] = array(
        'issue_date' => strtotime('30.04.2016'),
        'valid_until' => strtotime('30.12.2015'),
        'requested' => true
      );
    }
    if (stripos($string, 'extend') !== false) {
      $history[] = array(
        'issue_date' => strtotime('30.04.2016'),
        'valid_until' => strtotime('30.04.2020'),
        'requested' => true
      );
    }
    return $history;
  }

  public function setMailSystem($system = \TestMailSystem::MAIL_SYSTEM_CLASS_VARIABLE) {
    if ($this->mailSystemOriginal == null) {
      $this->mailSystemOriginal = variable_get('mail_system', array());
    }
    // Use the test mail class instead of the default mail handler class.
    $mailSystem = array(
      "default-system" => $system,
      "onsite_notification" => $system,
    );
    variable_set("mail_system", $mailSystem);
  }

  public function resetMailSystem($hard) {
    $mailSystem = $this->mailSystemOriginal;
    if ($this->mailSystemOriginal == null || $hard) {
      $mailSystem = array(
        "default-system" => \TestMailSystem::MAIL_SYSTEM_CLASS_SALTO,
        "onsite_notification" => \TestMailSystem::MAIL_SYSTEM_CLASS_SALTO,
      );
    }
    // Use the test mail class instead of the default mail handler class.
    variable_set("mail_system", $mailSystem);
  }

  public function cleanMailSystem() {
    $this->resetMailSystem(TRUE);
    variable_del(\VariableMailSystem::TEST_EMAIL_COLLECTOR_NAME_WN);
    variable_del('drupal_test_email_collector');
  }

  public function getMailFromVariableSystem() {
    return variable_get(\VariableMailSystem::TEST_EMAIL_COLLECTOR_NAME_WN, array());
  }

  public function mailWasSend($to, $positive = TRUE) {
    $mail = NULL;
    $mails = $this->getMailFromVariableSystem();
    foreach ($mails as $idx => $array) {
      //var_dump($array['to']);
      if (stripos($array['to'], $to) !== FALSE) {
        $mail = $array['to'];
        break;
      }
    }

    if ($positive) {
      $this->assertNotNull($mail);
    } else {
      $this->assertNull($mail);
    }
    return FALSE;
  }

  public function seeMailWasSent($options = array()) {
    return $this->_seeMailWasSentOrNot($options);
  }

  public function seeMailWasNotSent($options = array()) {
    return $this->_seeMailWasSentOrNot($options, TRUE);
  }

  private function _seeMailWasSentOrNot($options = array(), $negate = FALSE) {

    $webDriver = $this->getModule('WebDriver');

    $mails_raw = $this->getModule('WebDriver')->_findElements('.onscreenmail');

    $mails = array();

    /** @var RemoteWebElement $i */
    foreach ($mails_raw as $i) {
      $str = $i->getAttribute("innerHTML");
      $mails[] = json_decode($str);
    }

    $mail_we_want = NULL;

    foreach ($mails as $mail) {

      $found_mail = FALSE;
      foreach ($options as $k => $v) {
        if($k == '%body%'){
          if(strpos($mail->body, $v) !== false){
            $found_mail = TRUE;
          }
        }
        elseif ($mail->$k == $v) {
          $found_mail = TRUE;
        }
        else {
          $found_mail = FALSE;
        }
      }
      if ($found_mail) {
        $mail_we_want = $mail;
        break;
      }
    }
    if ($negate) {
      $this->assertNull($mail_we_want);
    }
    else {
      $this->assertNotNull($mail_we_want);
    }
  }

  public function saveTestUsers(array $users) {
    variable_del('wn_test_user');
    variable_set('wn_test_user', $users);
  }

  public function getTestUsers() {
    return variable_get('wn_test_user', array());
  }

  public function startPdfRecordTask($account, $ogNid, $wbmId, $licenseIds, $output = 'single') {
    $task_data = array();
    //generate licenses for the following license ids
    $task_data['dosb_license_ids'] = $licenseIds;
    //track which license ids have already been generated
    $task_data['completed_dosb_license_ids'] = array();
    //define the output format: single|zip
    $task_data['output_format'] = $output;
    //define the license format dina4|card
    $task_data['license_format'] = 'dina4';
    //$task_data['print_urkunde'] = $print_urkunde;

    $task_record = array(
      //initial state
      "status" => DOSB_LICENSE_GENERATOR_STATUS_CREATED,
      //user who starts the task
      "uid" => $account->uid,
      "created" => time(),
      "changed" => time(),
      //wbm or organisation nid
      "nid" => $wbmId,
      //flag if the file has already been downloaded
      "downloaded" => 0,
      "data" => serialize($task_data),
      //current handler of the background process
      "bp_handle_id" => NULL,
      //current task progress
      "progress" => 0,
    );

    dosb_license_process_pdf_generation_start($task_record, $account, $ogNid);
  }

  public static function getActiveDialogs($groupNid) {
    return salto_online_meeting_get_active_dialogs($groupNid);
  }

  public static function setProfileCategory($user, $arrayOfTid = []) {
    $profile = profile2_load_by_user($user, 'main');

    $profile->field_profile_categories[LANGUAGE_NONE] = [];

    foreach ($arrayOfTid as $tid) {
      $profile->field_profile_categories[LANGUAGE_NONE][]['tid'] = (string) $tid;
    }

    profile2_save($profile);
  }

  public static function setNotificationsCommunityOff($uid,$type = 'post') {
    onsite_notification_settings_update($uid, 'general', array('mail_frequency' => NOTIFICATION_FREQUENCY_IMIDIATE), 0);
    if($type == 'post'){
      onsite_notification_settings_update($uid, 'community_area', array('auto_subscribe' => '0'), 0);
    }
    else{
      onsite_notification_settings_update($uid, 'community_area', array('auto_subscribe_materials' => '0'), 0);
    }

   // onsite_notification_settings_update($uid, 'notification_post_created', array('mail' => 0), 0);
    drupal_static_reset();
  }

  public static function setNotificationsDefaults($uid) {
    $types = onsite_notification_get_notification_types();
    foreach ($types as $type) {
      onsite_notification_settings_update($uid, $type->name, array("mail" => 1), 1);
    }
    onsite_notification_settings_update($uid, 'general', array("mail_frequency" => variable_get('salto_notification_mail_frequency', NOTIFICATION_FREQUENCY_DAILY)));
    //onsite_notification_settings_update($uid, 'community_area', array('auto_subscribe' => '1','auto_subscribe_materials' => '1'), 0);
    onsite_notification_settings_update($uid, 'community_area', array('auto_subscribe' => '1'), 0);
    drupal_static_reset();
  }

  public static function setNotificationsMigrateOff($uid) {
    onsite_notification_settings_update($uid, 'notification_license_migrate', array('mail' => 0), 0);
    drupal_static_reset();
  }

  public static function setNotificationsMigrateOn($uid) {
    onsite_notification_settings_update($uid, 'notification_license_migrate', array('mail' => 1), 1);
    drupal_static_reset();
  }

  /**
   * @param $uid
   *
   * @return array
   */
  public static function reloadNotificationSettings($uid) {
    drupal_static_reset('onsite_nottification_settings_load');
    return onsite_nottification_settings_load($uid);
  }

  /**
   * Help function for auto subscribe
   * because break is db like "auto_subscribe\";i:1 in test(s)
   * if 'auto_subscribe' => 1
   * normally is "auto_subscribe";s:1:"1"
   * if 'auto_subscribe' => '1'
   * (must watching on live)
   *
   * @param $uid
   * @return mixed
   */
  public static function isNotificationAutoSubscribe($uid) {
    $result = onsite_notification_autosubscribe_enabled($uid);
    if (!$result) {
      $sql = 'SELECT uid FROM {notification_setting} WHERE uid = :uid AND message_type=\'community_area\' AND data like \'%\"auto_subscribe\";i:1%\'';
      $result = db_query($sql, array(':uid' => $uid))->fetchField();
      $cache[$uid] = !empty($result);

      return $cache[$uid];
    }

    return $result;
  }

  public static function getBlankCleanup() {
    return new \BlankCleanup();
  }

  public static function subscribeUserToEntity($user, $entity) {
    if (!empty($entity->nid)) {
      flag('flag', 'notification_subscribe_node', $entity->nid, $user);
    }
    if (!empty($entity->fid)) {
      flag('flag', 'notification_subscribe_material', $entity->fid,
        $user);
    }
  }

  public static function getNodeRepository() {
    return new \NodeRepository();
  }

  public function actAsUser($account) {
    global $user;
    $user = $account;

  }

  public static function addMemberToGroup($account, $gid) {
    //join group
    og_group('node', $gid, [
      'entity_type' => 'user',
      'entity' => $account,
      'membership type' => 'group_membership',
      'state' => OG_STATE_ACTIVE,
    ]);
  }

  /**
   * @param $USER
   */
  static function getUnreadNotificationsForUser($USER) {
    $notifications = onsite_notificaions_get_new_notifications($USER->uid, 'data');

    if (empty($notifications)) {
      return [];
    }
    $mids = array_map(function ($item) {
      return $item->mid;
    }, $notifications);
    return message_load_multiple($mids);

  }

  static function createGroup($manager, $options = []) {
    global $user;
    $userTmp = clone $user;
    $user = $manager;

    $defaults = [
      'key' => empty($options['parent']) ? 'TEST': null,
      'title' => 'TestGroup-' . time(),
      'language' => LANGUAGE_NONE,
    ];
    $options = array_merge($defaults, $options);

    $node = new \stdClass();
    $node->title = $options['title'];
    $node->type = 'group';
    $node->language = $options['language'];
    //$node->uid = $managerId;
    $node->field_group_categories[LANGUAGE_NONE][0]['tid'] = 4513;
    $node->body[LANGUAGE_NONE][0]['value'] = $options['body'];

    node_save($node);

    $user = $userTmp;

    return $node;
  }

  /**
   * inspired by / claim from drupal_run_cron
   * @param $name
   *
   * @return bool
   */
  static function runCoreSystemQueue($name) {
    $queues = module_invoke_all('cron_queue_info');
    $info = $queues[$name];
    if (empty($info)) {
      //var_dump($queues);
      return false;
    }
    watchdog('Helper::runCoreSystemQueue', 'data: %data', ['%data' => print_r($info, TRUE)]);

    $callback = $info['worker callback'];
    $end = time() + (isset($info['time']) ? $info['time'] : 15);
    $queue = \CoreSystemQueue::create($name);
    while (time() < $end && ($item = $queue->claimItem())) {
      try {
        call_user_func($callback, $item->data);
        $queue->deleteItem($item);
      }
      catch (\Exception $e) {
        // In case of exception log it and leave the item in the queue
        // to be processed again later.
        watchdog_exception('cron', $e);
      }
    }
    return true;
  }

  static function deleteCoreSystemQueue($name) {
    $queue = \CoreSystemQueue::create($name);
    $queue->deleteQueue();
  }

  static function cleanCoreSystemQueue() {
    self::deleteCoreSystemQueue('onsite_notification_should_mail_immediately');
    self::deleteCoreSystemQueue('onsite_notification_knowledgebase_post_submitted');
    self::deleteCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_POST_CREATED);
    self::deleteCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_POST_CREATED_GROUP);
    self::deleteCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT);
    self::deleteCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT_REPLY);
    self::deleteCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_LICENSE_CORRECT_BY);
    self::deleteCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_LICENSE_MIGRATE);

    $queue = \DrupalQueue::get('update_fetch_tasks');
    $queue->deleteQueue();
  }

  function startCoreSystemQueueForType($type, $timeout = 3) {
    switch ($type) {
      case MESSAGE_TYPE_NOTIFICATION_POST_CREATED:
        $this->assertTrue(Bildungsnetz::runCoreSystemQueue('onsite_notification_knowledgebase_post_submitted'));
        sleep($timeout);
        $this->assertTrue(Bildungsnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_POST_CREATED));
        sleep($timeout);
        break;
      case MESSAGE_TYPE_NOTIFICATION_POST_CREATED_GROUP:
        $this->assertTrue(Bildungsnetz::runCoreSystemQueue('onsite_notification_knowledgebase_post_submitted'));
        sleep($timeout);
        $this->assertTrue(Bildungsnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_POST_CREATED_GROUP));
        sleep($timeout);
        break;
      case MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT:
        $this->assertTrue(Bildungsnetz::runCoreSystemQueue('onsite_notification_comment_insert'));
        sleep($timeout);
        $this->assertTrue(Bildungsnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT));
        sleep($timeout);
        break;
      case MESSAGE_TYPE_NOTIFICATION_LICENSE_MIGRATE:
        $this->assertTrue(Bildungsnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_LICENSE_MIGRATE));
        sleep($timeout);
        break;
      case MESSAGE_TYPE_NOTIFICATION_LICENSE_CORRECT_BY:
        $this->assertTrue(Bildungsnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_LICENSE_CORRECT_BY));
        sleep($timeout);
        break;
      case MESSAGE_TYPE_NOTIFICATION_MATERIAL_UPDATED:
        $this->assertTrue(Bildungsnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_MATERIAL_UPDATED));
        sleep($timeout);
        break;
      case MESSAGE_TYPE_NOTIFICATION_MATERIAL_CREATED:
        $this->assertTrue(Bildungsnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_MATERIAL_CREATED));
        sleep($timeout);
        break;
      default:
        throw new Exception("unknown type $type");

    }
    $this->assertTrue(Bildungsnetz::runCoreSystemQueue('onsite_notification_should_mail_immediately'));
    sleep($timeout);
  }

}
