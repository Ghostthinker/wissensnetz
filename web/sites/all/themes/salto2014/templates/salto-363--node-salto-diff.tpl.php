<div
  class="panel-display salto-363 <?php echo implode($classes_array, ' '); ?> " <?php if (!empty($css_id)) {
  print "id=\"$css_id\"";
} ?>>
  <?php if ($content['left'] || $content['middle'] || $content['right']): ?>
    <div class="row">
      <div class="panel-panel col-md-3 col-sm-4">
        <div class="inside"><?php print $content['left']; ?></div>
      </div>
      <div class="panel-panel col-md-6 col-sm-8 floater main-content">
        <?php
        $node_view = node_view($node, 'full');
        unset($node_view['comments']);
        unset($node_view['links']);
        ?>
        <div class="inside"><?php print render($node_view); ?></div>
      </div>

      <div class="panel-panel col-md-3 col-sm-4">
        <div class="inside"><?php print $content['right']; ?></div>
      </div>
    </div>
  <?php endif ?>
</div>
