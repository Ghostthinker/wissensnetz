<?php

namespace Helper;

// here you can define custom actions
// all public methods declared in helper class will be available in $I

use BlankCleanup;
use PHPUnit\Runner\Exception;

include_once DRUPAL_ROOT . '/sites/all/modules/features/salto_core/queue/CoreSystemQueue.php';

define('SALTO_INVITE_IV', '2e2a3c00279740e907ae94775dae574b');

class Wissensnetz extends \Codeception\Module {

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

        $themenfelder = salto_knowledgebase_get_themenfelder();
        variable_set('salto_default_category', $themenfelder[0]->tid);
        variable_set('salto_fallback_category', end($themenfelder)->tid);

        $this->disable_captcha();
        salto_organisation_set_default_custom_field_values();

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

    /**
     * clear the system, del content, types, og, users and ...
     */
    public function clearInstance() {
        salto_debug_cleaning();
        db_query("DELETE FROM file_managed WHERE uid NOT IN (SELECT u.uid FROM users u)")->execute();
        db_query("DELETE FROM mentions")->execute();
    }


    /**
     * Wrapper to create a single user
     * @param array $options
     * @return \stdClass
     * @throws \Exception
     */
    public function haveUser($options = []) {

        $account = bildungsnetz_api_create_user($options);
        if($options['mail']) {
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

    /**
     *
     */
    public static function clearFlood() {
        db_delete('flood')
                ->execute();
    }

    /*
    * Call this after defining content
    */
    public function completedSetup() {
        //we need to reset the cache that prevents the sending of new material und update material events
        drupal_static('onsite_notification_file_presave', NULL, TRUE);
    }


    public function haveOnlineMeeting($options) {
        return bildungsnetz_api_create_online_meeting($options);
    }

    public function havePost($options){
      $node = bildungsnetz_api_create_post($options);
      return $node;
    }

    public function haveMaterial($options){
        return bildungsnetz_api_create_material($options);
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

    /**
     * @param $user
     */
    public function deleteUser($user) {
        user_delete($user->uid);
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
                'Kategorie' => SALTO_KNOWLEDGEBASE_KB_EDUCATION_TID
        ];
        $options = array_merge($defaults, $options);

        $node = new \stdClass();
        $node->title = $options['title'];
        $node->type = 'group';
        $node->language = $options['language'];
        //$node->uid = $managerId;
        $node->field_group_categories[LANGUAGE_NONE][0]['tid'] = $options['Kategorie'];
        $node->body[LANGUAGE_NONE][0]['value'] = $options['body'];

        if($options['join_mode']){
          $node->field_group_join_mode[LANGUAGE_NONE][0]['value'] = $options['join_mode'];
        }

        if($options['org_id']){
          $node->field_group_join_org_refs[LANGUAGE_NONE][0]['target_id'] = $options['org_id'];
        }

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
        self::deleteCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_LICENSE_CORRECT_BY);
        self::deleteCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_MATERIAL_UPDATED);
        self::deleteCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_MATERIAL_CREATED);
        self::deleteCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_USER_MENTIONED);
        self::deleteCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_ONLINE_MEETING_SCHEDULED);

        $queue = \DrupalQueue::get('update_fetch_tasks');
        $queue->deleteQueue();
    }

    function startCoreSystemQueueForType($type, $timeout = 3) {
        switch ($type) {
            case MESSAGE_TYPE_NOTIFICATION_POST_CREATED:
                $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_knowledgebase_post_submitted'));
                sleep($timeout);
                $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_POST_CREATED));
                sleep($timeout);
                break;
            case MESSAGE_TYPE_NOTIFICATION_POST_CREATED_GROUP:
                $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_knowledgebase_post_submitted'));
                sleep($timeout);
                $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_POST_CREATED_GROUP));
                sleep($timeout);
                break;
            case MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT:
                $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_comment_insert'));
                sleep($timeout);
                $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_CREATE_COMMENT));
                sleep($timeout);
                break;
            case MESSAGE_TYPE_NOTIFICATION_LICENSE_MIGRATE:
                $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_LICENSE_MIGRATE));
                sleep($timeout);
                break;
            case MESSAGE_TYPE_NOTIFICATION_LICENSE_CORRECT_BY:
                $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_LICENSE_CORRECT_BY));
                sleep($timeout);
                break;
            case MESSAGE_TYPE_NOTIFICATION_MATERIAL_UPDATED:
                $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_MATERIAL_UPDATED));
                sleep($timeout);
                break;
            case MESSAGE_TYPE_NOTIFICATION_MATERIAL_CREATED:
                $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_MATERIAL_CREATED));
                sleep($timeout);
                break;
          case MESSAGE_TYPE_NOTIFICATION_USER_MENTIONED:
                $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_USER_MENTIONED));
                sleep($timeout);
                break;
          case MESSAGE_TYPE_NOTIFICATION_ONLINE_MEETING_SCHEDULED:
                $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_create_' . MESSAGE_TYPE_NOTIFICATION_ONLINE_MEETING_SCHEDULED));
                sleep($timeout);
                break;
            default:
                throw new Exception("unknown type $type");

        }
        $this->assertTrue(Wissensnetz::runCoreSystemQueue('onsite_notification_should_mail_immediately'));
        sleep($timeout);
    }

    public function addMemberToOrganisation($account, $organisation, $roles = []) {

        bildungsnetz_api_add_user_to_organisation($account, $organisation, $roles);
    }

    public function haveOrganisation($title, $options = []) {
        if (!array_key_exists('earemotes', $options)) {
            $ea = bildungsnetz_api_create_ea($options);
            $options['earemotes'] = [$ea->nid];
        }
        $node = bildungsnetz_api_create_organisation($title, $options);
        return $node;
    }

    public function createOrganisation($title, $options = []) {
        $node = bildungsnetz_api_create_organisation($title, $options);
        return $node;
    }


    private function disable_captcha() {
      salto_debug_disable_captcha();
    }

  public function createMentions($options){
    db_insert('mentions')
      ->fields(array(
        'entity_type' => $options['entity_type'],
        'entity_id' => $options['entity_id'],
        'uid' => $options['uid'],
        'auid' => $options['auid'],
        'created' => $options['created'] ?? time()
      ))
      ->execute();

  }

}
