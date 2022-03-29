<?php

class SaltoMailSystem__SmtpMailSystem implements MailSystemInterface {

  protected $formatClass;

  protected $mailClass;

  public function __construct() {
    if (drupal_autoload_class('SaltoMailSystem')) {
      $this->formatClass = new SaltoMailSystem;
    }
    else {
      $this->formatClass = new DefaultMailSystem;
    }
    if (drupal_autoload_class('SmtpMailSystem')) {
      $this->mailClass = new SmtpMailSystem;
    }
    else {
      $this->mailClass = new DefaultMailSystem;
    }
  }

  public function format(array $message) {
    return $this->formatClass->format($message);
  }

  public function mail(array $message) {
    return $this->mailClass->mail($message);
  }

}
