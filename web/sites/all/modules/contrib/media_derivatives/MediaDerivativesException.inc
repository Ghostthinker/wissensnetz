<?php

/**
 * @file
 * Implements MediaDerivativesException class, which is an
 * extended PHP Exception class.
 */

class MediaDerivativesException extends Exception {

  /* Media derivative that this exception belongs to. */
  protected $mdid;

  /* Constructor. Besides default arguments accepts also derivative id. */
  function __construct($mdid, $message, $code = 0, $previous = NULL) {
    parent::__construct($message, $code);
    $this->mdid = $mdid;
  }

  /* Returns ID of derivative that caused this exception. */
  function getDerivativeID() {
    return $this->mdid;
  }

  /* Returns object of derivative that caused this exception. */
  function getDerivative() {
    return media_derivatives_load($this->mdid);
  }
}