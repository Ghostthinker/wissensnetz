<?php if (!empty($content['toolbar'])): print render($content['toolbar']); endif; ?>
<div
  class="panel-display salto-363 node-add-wrapper" <?php if (!empty($css_id)) {
  print "id=\"$css_id\"";
} ?>>
  <div class="row">
    <div class="panel-panel col-md-9">
      <div class="inside mobile">
        <?php print $main_content ?>

        <?php if ($body): ?>
          <?php print $body ?>
        <?php endif ?>

        <?php if ($attachment): ?>
          <?php print $attachment ?>
        <?php endif ?>

        <?php print $accordions ?>
      </div>
    </div>

    <div class="panel-panel col-md-3">
      <div class="inside legacy">
        <?php print $sidebar_content ?>
      </div>

      <?php if (!empty($content['side']['accordions'])): ?>
        <?php foreach ($content['side']['accordions'] as $acc): ?>
          <?php print $acc; ?>
        <?php endforeach ?>
      <?php endif; ?>
    </div>
  </div>
</div>
<?php if (!empty($content['floating_button'])): ?>
  <div class="floating-button-wrapper">
    <?php print render($content['floating_button']); ?>
  </div>
<?php endif; ?>
