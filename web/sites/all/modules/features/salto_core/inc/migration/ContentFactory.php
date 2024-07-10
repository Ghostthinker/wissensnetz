<?php

namespace salto_core\migration;


class ContentFactory {

 public static function getWrapper($type){

   switch ($type) {
     case 'group':
       return new ContentGroup();
     case 'user':
       return new ContentUser();
     case 'news':
     case 'blog':
       return new ContentPost();
     case 'video':
       return new ContentVideo();
     case 'cmap':
       return new ContentMaterial();
     default:
       throw new \Exception('Invalid type: ' . $type);
   }
}

}
