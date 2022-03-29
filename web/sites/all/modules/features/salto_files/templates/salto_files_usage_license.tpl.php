<div class="panel panel-default pane-salto-files-usage">
  <div class="panel-heading">
    <h3 class="panel-title">Nutzung</h3>
  </div>
  <div class="panel-body">
    <div class="panel-pane ">
      <div class="pane-content">
        <span class="file-usage-label">Autor</span>
        <?php echo $file_author; ?>
      </div>
      <div class="pane-content-separator"></div>

      <span class="file-usage-label">Nutzungslizenz</span><br/>
      <img src="<?php echo $file_license_img_src; ?>" data-html="true" data-original-title="<?php echo "<h3>$file_license_title</h3>".$file_license_desc; ?>" rel="tooltip">

      <div class="pane-content-separator"></div>

      <span class="file-usage-label">Urheber</span><br/>
      <?php echo $file_originator; ?>

    </div>
    <div class="pane-separator"></div>
  </div>
</div>
