<div class="panel-display salto-372" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['left'] || $content['middle'] || $content['right']): ?>
  <div class="row">
    <div class="panel-panel col-md-3">
      <div class="inside"><?php print $content['left']; ?></div>
    </div>
    <div class="panel-panel col-md-7 main-content">
      <div class="inside"><?php print $content['middle']; ?></div>
    </div>
    <div class="clearfix visible-sm"></div>
    <div class="panel-panel col-md-2">
      <div class="inside"><?php print $content['right']; ?></div>
    </div>
  </div>
  <?php endif ?>
</div>
