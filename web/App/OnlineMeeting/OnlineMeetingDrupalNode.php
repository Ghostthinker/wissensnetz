<?php

namespace Wissensnetz\OnlineMeeting;

use Wissensnetz\Core\Node\DrupalNode;

class OnlineMeetingDrupalNode extends DrupalNode
{

  public function getStartDateISO() {
    return $this->node->field_online_meeting_date[LANGUAGE_NONE][0]['value'];
  }

  public function getStartDate(){
    return date("d.m.Y", strtotime($this->node->field_online_meeting_date[LANGUAGE_NONE][0]['value']));
  }

  public function getStartTime(){
    return date("H:i", strtotime($this->node->field_online_meeting_date[LANGUAGE_NONE][0]['value']));
  }

}
