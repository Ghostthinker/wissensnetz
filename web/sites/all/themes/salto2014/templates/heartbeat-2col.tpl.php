<?php

/**
 * @file
 * Display Suite 2 column template for heartbeat activity.
 */
$basePath = base_path() . drupal_get_path('module', 'salto_knowledgebase') . '/webcomponents/GTReactions/svg';

$previewImageClass = $activity_content['preview_image'] ? 'image' : 'no-image';
?>



<?php if ($type == 'heartbeat_add_node'): ?>
  <div
    class="<?php print $previewImageClass . ' ' . $classes ; ?> clearfix hearbeat-activity-stream-new nid-<?php print $activity_content['nid']; ?>"
    style="background-image:linear-gradient(180deg, rgba(84, 86, 95, 0.00) 0.26%, rgba(84, 86, 95, 0.27) 23.54%, rgba(84, 86, 95, 0.61) 42.35%, rgba(84, 86, 95, 0.85) 58.87%, rgba(84, 86, 95, 0.95) 99.74%), url(<?php print $activity_content['preview_image'];?>)"
  >
    <div class="activity-stream-left">
      <div>
        <a href="<?php print $chip_info['user_url']; ?>" target="_blank">
        <div class="activity-stream-chip">
          <img src="<?php print $chip_info['picture']; ?>">
          <div class="content-info">
            <span><b><?php print $chip_info['name']; ?></b></span>
            <span class="chip-info-date"><?php print $chip_info['date']; ?></span>
          </div>
        </div>
        </a>
        <div class="activity-stream-heading">
          <?php print $activity_heading; ?>
        </div>
        <div class="activity-stream-content">
          <blockquote><?php print $activity_content['content']; ?></blockquote>
        </div>
      </div>
      <div class="footer-container">
        <div class="statistics">
        <span><i
            class="icon-eye"></i><?php print $activity_content['num_views']; ?></span>
          <div class="statistics-comment">
            <a target="_blank"
               href="/node/<?php print $activity_content['nid']; ?>/#comments">

              <div class="comment-button-icon-mask"
                   style="mask-image: url(<?php echo url($basePath . '/commentButton.svg', ['absolute' => TRUE]) ?>);">
              </div>
              <?php print $activity_content['num_comments']; ?>
            </a>
          </div>
        </div>
      </div>
    </div>

    <div class="activity-stream-right <?php print $activity_content['preview_image'] ? 'image' : 'no-image' ?>">
      <span class="stream-icon heartbeat-activity-type-post"></span>
      <?php if (!empty($activity_content['preview_image'])): ?>
        <img class="chip-img"
             src="<?php print $activity_content['preview_image']; ?>"
             width="100%">
      <?php endif; ?>
    </div>

  </div>
<?php elseif ($type == 'heartbeat_add_comment'): ?>
  <div
    class="<?php print $previewImageClass . ' ' . $classes ; ?>  clearfix hearbeat-activity-stream-new nid-<?php print $activity_content['nid']; ?>"
    style="background-image:linear-gradient(180deg, rgba(84, 86, 95, 0.00) 0.26%, rgba(84, 86, 95, 0.27) 23.54%, rgba(84, 86, 95, 0.61) 42.35%, rgba(84, 86, 95, 0.85) 58.87%, rgba(84, 86, 95, 0.95) 99.74%), url(<?php print $activity_content['preview_image'];?>)"
  >
    <div class="activity-stream-left">
      <div>
        <a href="<?php print $chip_info['user_url']; ?>" target="_blank">
      <div class="activity-stream-chip">
        <img src="<?php print $chip_info['picture']; ?>">
        <div class="content-info">
          <span><b><?php print $chip_info['name']; ?></b></span>
          <span class="chip-info-date"><?php print $chip_info['date']; ?></span>
        </div>
      </div>
        </a>
      <div class="activity-stream-heading">
        <?php print $activity_heading; ?>
      </div>
      <div class="activity-stream-content">
        <blockquote><?php print $activity_content['content']; ?></blockquote>
      </div>
      </div>
    </div>
      <div class="activity-stream-right <?php print $activity_content['preview_image'] ? 'image' : 'no-image' ?>">
        <span class="stream-icon heartbeat-activity-comment"></span>
        <?php if (!empty($activity_content['preview_image'])): ?>
        <img class="chip-img"
             src="<?php print $activity_content['preview_image']; ?>"
             width="100%">
        <?php endif; ?>
      </div>
  </div>


<?php else: ?>
  <div class="<?php print $previewImageClass . ' ' . $classes ; ?>  clearfix hearbeat-activity-stream card">
    <?php if (isset($title_suffix['contextual_links'])): ?>
      <?php print render($title_suffix['contextual_links']); ?>
    <?php endif; ?>

    <div class="card-content">
      <div class="heartbeat-group-header header">
        <?php if ($heartbeat_left): ?>
          <div class="group-left<?php print $heartbeat_left_classes; ?>">
            <?php print $heartbeat_left; ?>
          </div>
        <?php endif; ?>
        <?php if ($heartbeat_message): ?>
          <div
            class="group-right message-content<?php print $heartbeat_message_classes; ?>">
            <?php print $heartbeat_message; ?>
          </div>
        <?php endif; ?>
      </div>

      <div class="heartbeat-group-content">
        <?php if ($heartbeat_content): ?>
          <div class="group-content<?php print $heartbeat_content_classes; ?>">
            <?php print $heartbeat_content; ?>
          </div>
        <?php endif; ?>

        <?php if ($heartbeat_footer): ?>
          <div class="group-footer<?php print $heartbeat_footer_classes; ?>">
            <?php print $heartbeat_footer; ?>
          </div>
        <?php endif; ?>
      </div>
    </div>

  </div>
<?php endif; ?>
