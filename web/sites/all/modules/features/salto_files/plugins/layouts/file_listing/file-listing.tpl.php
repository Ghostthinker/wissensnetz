<div class="salto_file_listing <?php echo implode($classes_array, ' '); ?> "
  <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>
>
  <div class="card">
    <div class="card-content">
      <div class="header">
        <div class="col-md-3" id="file-image">
          <?php print $content['left']; ?>
        </div>
        <div class="col-md-9">
          <?php print render($content['file_title']); ?>
          <?php print $content['license_right']; ?>
          <?php print render($content['download_link']); ?>
        </div>
      </div>
      <div class="group-content">
        <?php print $content['description']; ?>
      </div>
      <div class="group-footer">
          <div class="row tag_row foo-left">
              <?php print $content['meta_right']; ?>

              <?php if ($content['submit_date']): ?>
                <div class="submit-date">
                  <?php print $content['submit_date']; ?>
                </div>
              <?php endif; ?>
          </div>
          <div class="row last_row foo-right">
            <?php print $content['meta_left']; ?>
          </div>
      </div>
    </div>
  </div>
</div>
