<?php
ini_set("display_errors", 1);
ini_set("track_errors", 1);
ini_set("html_errors", 1);
error_reporting(E_ALL);

foreach(glob('./out/*') as $filename){
  $file= basename($filename);
  unlink('out/'.$file);
}
$ffmpeg = realpath('../bin/nix/ffmpeg');


/**
 * VIEDOS
 *
 */
?> <h1>Video</h1><?php

$options = "-vcodec libx264 -b:v 600k -acodec libvo_aacenc -ac 2 -ar 48000 -b:a 96k -map 0 -movflags +faststart";

foreach(glob('./video/*') as $filename){
  $file= basename($filename);
  if($file == "index.php") continue;

  //convert video
  $command = "$ffmpeg -i video/$file $options out/$file.mp4";

  $output = shell_exec($command)


  ?>
  <h2><?=$file?></h2>
  <video controls height="240">
  <source src="<?php print "out/".$file.".mp4"?>" type="video/mp4">
  </video>
  <pre>
  <?= $command ?>
  </pre>
  <pre>
  <?php print $output; ?>
  </pre>
<?php
}
?>
<h1>Audio</h1>
<?php

$options = "-b:a 192K -vn";

foreach(glob('./audio/*') as $filename){
  $file= basename($filename);
  if($file == "index.php") continue;

  //convert video
  $command = "$ffmpeg -i audio/$file $options out/$file.mp3";

  $output = shell_exec($command)


  ?>
  <h2><?=$file?></h2>
  <audio controls height="240">
  <source src="<?php print "out/".$file.".mp3"?>" type="audio/mp3">
  </audio>
  <pre>
  <?= $command ?>
  </pre>
  <pre>
  <?php print $output; ?>
  </pre>
<?php
}
?>
