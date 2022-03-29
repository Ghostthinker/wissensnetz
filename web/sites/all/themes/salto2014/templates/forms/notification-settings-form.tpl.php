<?php if (!empty($content['toolbar'])): print render($content['toolbar']); endif; ?>
<div
  class="panel-display salto-363 node-add-wrapper" <?php if (!empty($css_id)) {
  print "id=\"$css_id\"";
} ?>>
  <div class="row">
    <div class="panel-panel col-md-3">
      <div class="inside">
        <?php print $sidebar_left ?>
      </div>
    </div>
    <div class="panel-panel col-md-6">
      <div class="inside">
        <fieldset class="panel panel-default form-wrapper" id="edit-events">
          <legend class="panel-heading">
            <div
              class="panel-title fieldset-legend"><?php print t('Notification events') ?> </div>
          </legend>
          <div class="panel-body">
            <?php print $main_content ?>
            <p
              class="help-block"><?php print t('Here you can set if and how you want to be notified by event type.') ?></p>
          </div>
        </fieldset>
        <?php print $secondary_content ?>
      </div>
    </div>

    <div class="panel-panel col-md-3">
      <div class="inside">
        <?php print $sidebar_right ?>
      </div>
    </div>
  </div>
</div>
<?php if (!empty($modals['content'])): print render($modals['content']); endif; ?>
