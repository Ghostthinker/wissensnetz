<?php

namespace salto_core\tasks;

abstract class ScheduledTask {


  /**
   * @var false
   */
  public $hasRun;

  /**
   * @var string
   */
  public $key;


  public function __construct() {
    $this->hasRun = FALSE;
    $this->key = $this->getKey();
  }


  abstract function getKey();

  public function resetSchedule() {
    variable_del($this->key);
  }

  public function shouldRun(): bool {

    return FALSE;
  }


  public function run() {
    $this->handle();
    $this->hasRun = TRUE;
    $this->setLastRuntime();
  }

  protected function lastRunOlderThan($seconds) {

    $NOW = time();

    $lastRunTimestamp = $this->getLastRuntime();

    if (is_null($lastRunTimestamp)) {
      return TRUE;
    }
    $secondsSinceLastRun = $NOW - $lastRunTimestamp;

    if ($secondsSinceLastRun > $seconds) {
      return TRUE;
    }
    return FALSE;
  }

  protected function lastRunOlderThanADay() {
    return $this->lastRunOlderThanDays(1);
  }

  protected function lastRunOlderThanDays($days = 1) {
    return $this->lastRunOlderThan($days * 86400);
  }

  public function setLastRuntime($timestamp = NULL) {
    variable_set($this->key, $timestamp ?? time());
  }

  public function getLastRuntime() {
    return variable_get($this->key, 0);
  }

  protected function shouldRunAtHour($hour = 0) {
    $is_hour_to_send = (int) date('H', time()) == $hour;
    if ($is_hour_to_send) {
      return TRUE;
    }
    return FALSE;
  }


}
