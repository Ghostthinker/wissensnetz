<div class="entityreference_duallistbox">
  <div class="selected">
    <h3><?php print t("Selected Items") ?></h3>
    <div class="pool-body">
      <input type="text" class="fulltext_filter"
             placeholder="<?php print t("Search") ?>"/>
      <div class="selected-items"></div>
    </div>
  </div>
  <div class="pool">
    <h3><?php print t("Available Items") ?></h3>

    <div class="pool-body">
      <input type="text" class="fulltext_filter"
             placeholder="<?php print t("Search") ?>"/>
      <div class="pool-items">
        <?php print drupal_render_children($form); ?>
      </div>
    </div>
  </div>
</div>
<div style="clear:both"></div>