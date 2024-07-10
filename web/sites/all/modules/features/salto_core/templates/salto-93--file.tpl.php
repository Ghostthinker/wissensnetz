<?php

$basePath = base_path() . drupal_get_path('module', 'salto_knowledgebase') . '/webcomponents/GTReactions/svg';
?>

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
                  <?php if (isset($publishing_label)): ?>
                    <span class="file-publishing-icon">
                  <?php print $publishing_label; ?>
                    </span>
                  <?php endif; ?>
                </div>
              <?php endif; ?>
            </div>
            <?php if ($svs_enabled): ?>
              <div id="comment-anchor"></div>
            <?php endif; ?>
            <div class="group-content">
              <?php if (!$is_derivate): ?>
                <?php print render($content['file']); ?>
              <?php endif; ?>
              <?php print render($content['field_file_description']); ?>
              <?php print render($content['field_post_tags']); ?>
              <?php print render($content['field_kb_kategorie']); ?>
            </div>
            <?php if ($reactions_enabled): ?>
              <?php
              $content['links']['comment2'] = array_replace([],$content['links']['comment']);
              unset( $content['links']['comment2']['#links']['comment-comments']);
              unset( $content['links']['comment']['#links']['comment-add']);

              $comment_link = drupal_render($content['links']['comment2']);
              ?>


              <div class="reaction-footer">
                <div class="footer-meta">
                  <div class="reaction-summary" data-entity-type="file" data-entity-id="<?php print $file->fid ?>"><?php print $reactionsSerialized ?></div>
                  <div class="footer-links"><?php print render($content['links']['statistics']); ?> <?php print render($content['links']['attachments']); ?></div>
                </div>
                <?php if ($user->uid > 0): ?>
                  <div class="reaction-actions">
                    <gt-reactions-button data-entity-type="file" data-entity-id="<?php print $file->fid ?>"><img
                        class="like-button"
                        src="<?php echo $basePath . '/likeButton.svg' ?>"><span
                        class="like-text"><?php print t("Like"); ?></span>
                    </gt-reactions-button>
                    <div class="comment-button">
                      <?php if (!$svs_enabled): ?>
                      <span class="comment-text"><?php print l('<img class="comment-button" src="' . $basePath . '/commentButton.svg">' . t("Comment"), "/file/" . $file->fid, [
                          'fragment' => 'edit-comment-body',
                          'html' => TRUE,
                        ]) ?></span>
                      <?php endif; ?>

                    </div>
                  </div>
                <?php endif; ?>
              </div>
            <?php else: ?>

              <div class="group-footer">
                <div class="foo-left">

                  <?php print render($content['links']); ?>

                  <?php if ($submit_date): ?>
                    <div class="submit-date">
                      <?php print $submit_date; ?>
                    </div>
                  <?php endif; ?>
                </div>
                <div class="foo-right">
                  <?php print render($content['links_right']); ?>
                </div>
              </div>
            <?php endif; ?>
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
