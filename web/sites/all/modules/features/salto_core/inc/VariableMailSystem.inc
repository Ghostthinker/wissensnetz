<?php
/**
 * Created by PhpStorm.
 * User: linnie
 * Date: 12.02.19
 * Time: 14:54
 */

class VariableMailSystem extends TestMailSystem {

  const TEST_EMAIL_COLLECTOR_NAME_WN = 'wn_test_email_collector';

  /**
   * Accept an e-mail message and store it in a variable.
   *
   * @param $message
   *   An e-mail message.
   *
   * @return bool
   */
  public function mail(array $message) {
    parent::mail($message);

    $captured_emails = variable_get(self::TEST_EMAIL_COLLECTOR_NAME_WN, []);
    $captured_emails[] = $message;
    variable_set(self::TEST_EMAIL_COLLECTOR_NAME_WN, $captured_emails);

    return TRUE;
  }

}
