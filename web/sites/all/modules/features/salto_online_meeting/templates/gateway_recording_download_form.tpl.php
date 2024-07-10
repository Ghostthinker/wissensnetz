<div class="dialog-import-form-wrapper" style="
    border-bottom: 1px dashed #C8C8C8;
">
    <h2><?php print t("New recordings for this online meeting") ?></h2>
    <p><?php print $description ?></p>
    <table class="dialog-import-form">
      <?php foreach ($items as $item): ?>
          <tr>
              <td class="dialog-import-form-preview"> <?php print drupal_render($item['preview']); ?> </td>
              <td class="dialog-import-form-options">
                  <h4><?php print $item['#title'] ?></h4> <?php print drupal_render($item['options']); ?>
              </td>
          </tr>
      <?php endforeach ?>
    </table>
    <div class="pull-right">
      <?php print drupal_render_children($form); // probably useless ?>
    </div>
    <div style="clear:both"></div>
</div>

