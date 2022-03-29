<?php
/**
 * @file display all screenshots from test results. There should not bot anything on live sites!!!
 */


$images = array();

foreach(glob('./*') as $filename){
  $file= basename($filename);
  if($file == "index.php") continue;
  //print  "<h3>$file</h3><img src='$file'' /><br>";

  //get the testname
  $details = explode("-_-", $file);
  if(count($details) != 2) continue;

  $name = substr($details[1], 0,-4);
  $images[$details[0]][$name] = $file;


}
?>

<h1>screenshots from tests</h1>
<table style="width:50%; border: 1px solid black">
<?php

foreach($images as $name => $data):
?>
<tr>
  <td><?php print $name?> </td>
  <?php foreach($data as $mode => $url): ?>
  <td><a href="<?php print $url;?>"><?php print $mode ?></a></td>
  <?php endforeach ?>
</tr>
<?php endforeach ?>
</table>
