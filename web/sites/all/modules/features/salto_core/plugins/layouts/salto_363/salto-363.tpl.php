<?php if (!empty($content['toolbar'])): print render($content['toolbar']); endif; ?>
<div
  class="panel-display salto-363 <?php echo implode($classes_array, ' '); ?> " <?php if (!empty($css_id)) {
  print "id=\"$css_id\"";
} ?>>
  <?php if ($content['left'] || $content['middle'] || $content['right']): ?>
    <div class="row">
      <div class="panel-panel col-md-3 col-sm-4 main_layout_left">
        <div class="inside"><?php print $content['left']; ?></div>
      </div>
      <div class="panel-panel col-md-6 col-sm-8 main-content floater">
        <?php if (!empty($owngroups)): ?>
          <div class="accordion-container owngroups is-mobile">
            <button
              class="accordion-button"><?php print render($owngroups['title']); ?></button>
            <div class="accordion-panel">
              <?php print render($owngroups['content']); ?>
            </div>
          </div>
        <?php endif; ?>
        <div class="inside"><?php print $content['middle']; ?></div>
        <?php if (!empty($additional)): ?>
          <div
            class="inside"><?php print $additional['content']; ?></div><?php endif; ?>
        <?php if (!empty($attachment)): ?>
          <div id="attachments" class="accordion-container attachments">
            <button
              class="accordion-button"><?php print render($attachment['title']); ?></button>
            <div class="accordion-panel">
              <?php print render($attachment['content']); ?>
            </div>
          </div>
        <?php endif; ?>
        <?php if (!empty($authors)): ?>
          <div class="accordion-container collaboration">
            <button
              class="accordion-button"><?php print render($authors['title']); ?></button>
            <div class="accordion-panel">
              <?php print render($authors['content']); ?>
            </div>
          </div>
        <?php endif; ?>
        <?php if (!empty($attachment) || !empty($authors) || !empty($owngroups)): ?>
          <script
            src="/sites/all/themes/salto2014/assets/md/src/accordion.js"></script>
        <?php endif; ?>
      </div>

      <div class="panel-panel col-md-3 col-sm-4 main_layout_right">
        <div class="inside"><?php print $content['right']; ?></div>
      </div>
    </div>
  <?php endif ?>
</div>
<?php if (!empty($modals['content'])): print render($modals['content']); endif; ?>
