<?php

namespace Wissensnetz\Core\File;

use Wissensnetz\Core\Node\Exception\DrupalNodeNotExistsException;
use Wissensnetz\Group\GroupDrupalNode;
use Wissensnetz\OnlineMeeting\OnlineMeetingDrupalNode;
use Wissensnetz\User\DrupalUser;

class VideoDrupalFile extends DrupalFile {

  public function getMediaDerivativePreset(){
    if(!$this->file->media_derivatives['has_derivatives']){
      return FALSE;
    }

    return $this->file->media_derivatives['derivatives_list']['video_thumbnail'];

  }

  public function getFileIcon(){
    return url('/sites/all/static_files/video_chat.svg', ['absolute' => TRUE]);
  }


}
