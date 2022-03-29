<div
  class="panel-display salto-93 <?php print $classes ?>" <?php if (!empty($css_id)) {
  print "id=\"$css_id\"";
} ?>>
  <?php if ($content['left'] || $content['middle'] || $content['right']): ?>
    <div class="row">
      <div class="panel-panel col-md-9">
        <div class="inside card">
          <div class="card-content">
            <div class="header">
              <?php $is_derivate = stripos($content['file']['#theme'], 'media_derivatives') !== FALSE; ?>
              <?php if ($is_derivate): ?>
                <div class="col-xs-6">
                  <?php print render($content['file']); ?>
                </div>
                <div class="col-md-6">
                  <?php print render($content['file_title_heading']); ?>
                  <?php print render($content['field_file_license_type']); ?>
                </div>
              <?php else: ?>
                <div class="col-md-12">
                  <?php print render($content['file_title_heading']); ?>
                  <?php print render($content['field_file_license_type']); ?>
                </div>
              <?php endif; ?>
            </div>
            <div class="group-content">
              <?php if (!$is_derivate): ?>
                <?php print render($content['file']); ?>
              <?php endif; ?>
              <?php print render($content['field_file_description']); ?>
              <?php print render($content['field_post_tags']); ?>
              <?php print render($content['field_kb_kategorie']); ?>
            </div>
            <div class="group-footer">
              <div class="foo-left">
                <?php print render($content['file_views_count']); ?>

                <div class="submit-date">
                  <?php print format_date($content['file']['#file']->timestamp); ?>
                </div>
              </div>
              <div class="foo-right">
                <?php print render($content['field_content_rating']); ?>
                <?php print render($content['salto_files_rating_action']); ?>
                <?php print render($content['files_rating_view']); ?>
              </div>
            </div>
          </div>
        </div>
        <?php if (!empty($content['file_comments_form'])): ?>
          <?php print render($content['file_comments_form']); ?>
        <?php endif; ?>
        <div class="accordion-container is-mobile">
          <button class="accordion-button">Nutzung</button>
          <div class="accordion-panel">
            <?php print render($content['salto_files_usage_license']); ?>
          </div>
        </div>
        <div class="accordion-container is-mobile">
          <button class="accordion-button">Datendetails</button>
          <div class="accordion-panel">
            <?php print render($content['salto_files_metadata']); ?>
          </div>
        </div>
        <script
          src="/sites/all/themes/salto2014/assets/md/src/accordion.js"></script>
      </div>
      <div class="panel-panel col-md-3">
        <div class="inside"><?php print $content['right']; ?></div>
      </div>
    </div>
  <?php endif ?>
</div>
