<div
  class="panel-display salto-93 <?php print $classes ?>" <?php if (!empty($css_id)) {
  print "id=\"$css_id\"";
} ?>>
  <?php if ($content['left'] || $content['middle'] || $content['right']): ?>
    <div class="row">
      <div class="panel-panel col-md-9">
        <div class="inside"><?php print $content['left']; ?></div>
      </div>
      <div class="panel-panel col-md-3">
        <div class="inside"><?php print $content['right']; ?></div>
      </div>
    </div>
  <?php endif ?>
</div>
