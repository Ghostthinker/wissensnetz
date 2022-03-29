<div class="panel panel-default pane-salto-files-usage">
  <div class="panel-heading">
    <h3 class="panel-title">Datendetails</h3>
  </div>
  <div class="panel-body">
    <div class="panel-pane ">
      <div class="pane-content">
        <?php if (isset($file_metadata_format)) : ?>
          <span class="file-usage-label">Dateiformat</span>
          <?php echo $file_metadata_format; ?>
          <div class="pane-content-separator"></div>
        <?php endif ?>
        <?php if (isset($file_metadata_size)) : ?>
          <span class="file-usage-label">Dateigröße</span>
          <?php echo $file_metadata_size; ?>
          <div class="pane-content-separator"></div>
        <?php endif ?>
        <span class="file-usage-label">Erstellungsdatum</span>
        <?php echo $file_metadata_created; ?>
      </div>
      <div class="pane-separator"></div>
    </div>
  </div>
</div>
