<?php

$basePath = base_path() . drupal_get_path('module', 'salto_knowledgebase') . '/webcomponents/GTReactions/svg';
?>

<?php if($material_cards): ?>
<?php if($preview_image_class): ?>
<div class="salto-file-card <?php print $preview_image_class; ?>" style="background-image: linear-gradient(180deg, rgba(84, 86, 95, 0.00) 0.26%, rgba(84, 86, 95, 0.27) 23.54%, rgba(84, 86, 95, 0.61) 42.35%, rgba(84, 86, 95, 0.85) 58.87%, rgba(84, 86, 95, 0.95) 99.74%),url(<?php print $preview_image; ?>); background-size: cover; background-position: center;">
  <?php else: ?>
<div class="salto-file-card">
  <?php endif; ?>
  <?php if($icon): ?>
  <div class="icon">
    <div class="icon-mask"
         style="mask-image: url(<?php print $icon; ?>);">
    </div>
  </div>
  <?php endif; ?>
  <a href="<?php print $link; ?>" class="content-container">
    <div class="content-info">
      <div class="content-title"><?php print $title; ?></div>
      <div class="content-body"><?php print $content['description']; ?></div>
  </div>
  </a>
  <div class="footer-container">
    <div class="statistics">
      <?php if ($reactions_enabled): ?>
      <div class="reaction-footer">
      <div class="reaction-summary" data-entity-type="file" data-entity-id="<?php print $file->fid ?>"><?php print $reactionsSerialized ?></div>
      </div>
      <?php endif; ?>
    <span><i
        class="icon-eye"></i><?php print $statistics['num_views']; ?></span>
    <div class="statistics-comment">
      <a target="_blank"
         href="/file/<?php print $fid; ?>/#comments">
      <div class="comment-button-icon-mask"
           style="mask-image: url(<?php echo url($basePath . '/commentButton.svg', ['absolute' => TRUE]) ?>);">
      </div>
        <?php print $statistics['num_comments']; ?></a>

    </div>
    </div>
    <div class="action-buttons">
      <div class="left-side">
        <div class="footer-icon">
          <gt-reactions-button data-entity-type="file" data-entity-id="<?php print $file->fid ?>">
            <div class="icon-mask like-button"
                 style="mask-image: url(<?php print $basePath . '/likeButton.svg'; ?>);">
            </div>
          </gt-reactions-button>
        </div>
        <div class="footer-icon">
          <a target="_blank" href="<?php print url('/file/' . $file->fid, ['absolute' => TRUE, 'fragment' => 'comment-anchor']) ?>">
          <div class="icon-mask comment-button"
               style="mask-image: url(<?php print $basePath . '/commentButton.svg'; ?>);">
          </div>
          </a>
        </div>
      </div>
      <div class="right-side">
        <?php if($download_link): ?>
         <a href="<?php print $download_link; ?>" class="footer-icon">
          <div class="button-image-card"
               style="mask-image: url(<?php print $downloadIcon; ?>);">
          </div>
        </a>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>

<?php else: ?>

<div class="salto_file_listing <?php echo implode($classes_array, ' '); ?> "

  <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>
>

  <div class="card">
    <div class="card-content">
      <div class="header">
        <div class="col-md-3" id="file-image">
          <?php print $content['left']; ?>
        </div>
        <div class="col-md-9">
          <?php print render($content['file_title']); ?>
          <?php if ($field_file_license_type[0]['value'] != 'unlicensed') { print $content['license_right']; } ?>
          <?php print render($content['download_link']); ?>
        </div>

      </div>
      <div class="group-content">
        <?php print $content['description']; ?>
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
            <div class="footer-links"><?php print render($content['links']['statistics']); ?> <?php print render($content['links']['attachments']); ?>
            <?php if ($svs_enabled) : ?>
              <?php unset($content['links']['comment']['#links']['comment-comments']); ?>
            <?php endif; ?>
              <?php if(!empty($content['links']['comment']['#links']['comment-comments'])): ?>
                <img
                  class="comment-button-icon"
                  src="<?php echo $basePath . '/commentButton.svg' ?>">
                <?php endif; ?>
              <?php print render($content['links']['comment']); ?></div>


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
                <?php else: ?>
                  <span class="comment-text"><?php print l('<img class="comment-button" src="' . $basePath . '/commentButton.svg">' . t("Comment"), "/file/" . $file->fid, [
                      'fragment' => 'comment-anchor',
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
    <?php if (isset($publishing_label)): ?>
      <span class="file-publishing-icon-listing">
                <?php print $publishing_label; ?>
            </span>
    <?php endif; ?>
  </div>
</div>
<?php endif; ?>
