<ul>
  <li><?php print l('sample', 'admin/appearance/showcase/grid') ?></li>
  <li><?php print l('363', 'admin/appearance/showcase/grid/bs-363') ?></li>
  <li><?php print l('282', 'admin/appearance/showcase/grid/bs-282') ?></li>
  <li><?php print l('273', 'admin/appearance/showcase/grid/bs-273') ?></li>
</ul>
<?php
$sample_main_content = 'Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum.<br> Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua.
    At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.';
?>
<?php if ($layout == 'sample'): ?>
  <div class="row show-grid">
    <div class="col-md-1">.col-md-1</div>
    <div class="col-md-1">.col-md-1</div>
    <div class="col-md-1">.col-md-1</div>
    <div class="col-md-1">.col-md-1</div>
    <div class="col-md-1">.col-md-1</div>
    <div class="col-md-1">.col-md-1</div>
    <div class="col-md-1">.col-md-1</div>
    <div class="col-md-1">.col-md-1</div>
    <div class="col-md-1">.col-md-1</div>
    <div class="col-md-1">.col-md-1</div>
    <div class="col-md-1">.col-md-1</div>
    <div class="col-md-1">.col-md-1</div>
  </div>
  <div class="row show-grid">
    <div class="col-md-8">.col-md-8</div>
    <div class="col-md-4">.col-md-4</div>
  </div>
  <div class="row show-grid">
    <div class="col-md-4">.col-md-4</div>
    <div class="col-md-4">.col-md-4</div>
    <div class="col-md-4">.col-md-4</div>
  </div>
  <div class="row show-grid">
    <div class="col-md-6">.col-md-6</div>
    <div class="col-md-6">.col-md-6</div>
  </div>
<? endif ?>

<?php if ($layout == 'bs-363'): ?>
  <div class="row show-grid">
    <div class="col-md-3">.col-md-3</div>
    <div class="col-md-6"><?php print $sample_main_content ?></div>
    <div class="col-md-3">.col-md-3</div>
  </div>
<? endif ?>

<?php if ($layout == 'bs-282'): ?>
  <div class="row show-grid">
    <div class="col-md-2">.col-md-2</div>
    <div class="col-md-8"><?php print $sample_main_content ?>  </div>
    <div class="col-md-2">.col-md-2</div>
  </div>
<? endif ?>

<?php if ($layout == 'bs-273'): ?>
  <div class="row show-grid">
    <div class="col-md-2">.col-md-2</div>
    <div class="col-md-7"><?php print $sample_main_content ?>  </div>
    <div class="col-md-3">.col-md-3</div>
  </div>
<? endif ?>

<?php if ($layout == 'bs-363-mkeep'): ?>
  <div class="row show-grid">
    <div class="col-sm-4 col-md-3">left</div>
    <div class="col-sm-8 col-md-6">Main</div>
    <div class="col-md-3 col-sm-offset-2">right</div>
  </div>
<? endif ?>
