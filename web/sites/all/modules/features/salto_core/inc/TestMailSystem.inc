<?php
/**
 * Created by PhpStorm.
 * User: linnie
 * Date: 12.02.19
 * Time: 14:53
 */

/**
 * A simple testing mail system that logs mails on screen
 */
class TestMailSystem extends \DefaultMailSystem {

  const MAIL_SYSTEM_CLASS_SALTO = 'SaltoMailSystem';
  const MAIL_SYSTEM_CLASS_VARIABLE = 'VariableMailSystem';
  const MAIL_SYSTEM_CLASS_ONSCREEN = 'OnScreenMailSystem';

  public function mail(array $message) {

    $mail = array(
      'receiver' => $message['to'],
      'subject' => $message['subject'],
      'body' => $message['body']
    );

    watchdog('wn_test_mail_system_notify', 'mail was sent to !receiver: <pre>!mail</pre>', array(
      '!receiver' => $message['to'],
      '!mail' => print_r($mail, TRUE)
    ));

    return $mail;
  }
}

