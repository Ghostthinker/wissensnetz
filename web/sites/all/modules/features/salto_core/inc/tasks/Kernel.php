<?php

namespace salto_core\tasks;

class Kernel {


  /**
   * @var array
   */
  protected $currenttasks;

  public function __construct() {
    $this->make(LegalUpdatedTask::class);
  }


  public function cron() {

    foreach ($this->currenttasks as $task) {
      try {
        if ($task->shouldRun()) {
          $task->run();
        }
      } catch (\Throwable $t) {
        watchdog('scheduled_task', 'Scheduled task failed to run: !data', ['!data' => $t->getMessage()], WATCHDOG_ERROR);
      }
    }

  }

  private function make($classname): ScheduledTask {
    $task = new $classname();
    $this->currenttasks[] = $task;
    return new $task;
  }

  public function getRunnedtasks() {

    if (empty($this->currenttasks)) {
      return [];
    }

    return array_filter($this->currenttasks, function (ScheduledTask $task) {
      return $task->hasRun == TRUE;
    });
  }


  public function resetSchedules() {
    foreach ($this->currenttasks as $task) {
      $task->resetSchedule();
    }
  }


}
