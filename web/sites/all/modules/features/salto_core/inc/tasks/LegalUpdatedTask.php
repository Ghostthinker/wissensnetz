<?php

namespace salto_core\tasks;

class LegalUpdatedTask extends ScheduledTask {

  private const LEGAL_PAST_DURATION_IN_DAYS = 14 * 60 * 60 * 24;

  public function shouldRun(): bool {
    if ($this->shouldRunAtHour()) {
      return $this->lastRunOlderThan(3600);
    }
    return FALSE;
  }

  public function handle() {

    $legalService = new \salto_core\service\LegalService();
    $legalUpdatedDate = format_date($legalService->getLegalUpdatedTime() - self::LEGAL_PAST_DURATION_IN_DAYS, 'custom', 'd.m.Y');
    $conditions = legal_get_conditions('de');

    if(format_date($conditions['date'], 'custom', 'd.m.Y') == $legalUpdatedDate){
      salto_debug_log_to_slack('Legal', 'Still legal not updated for ' . url('',['absolute' => TRUE]) );
    }

  }


  function getKey() {
    return "Task:" . self::class;
  }

}
