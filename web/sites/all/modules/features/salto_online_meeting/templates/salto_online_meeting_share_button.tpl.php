<div class="btn-group salto-online-meeting-share-button">
    <div class="action-links">
        <a class="btn btn-primary dropdown-toggle title action_share_meeting" data-toggle="dropdown" href="#">
          <span class="link-title">
            <?php print $title ?>
          </span>
          <span class="caret"></span>
        </a>
      <ul class="dropdown-menu">
        <li>
          <input type="text" class="salto-online-meeting-share-link-text" value="<?php print $share_link_url  ?>" />
          <span><?php print $share_link_info ?></span>
        </li>
      </ul>
      <div class="triangle"></div>

    </div>
</div>
<div class="alert alert-info salto-online-meeting-share-button-info"><?php print $share_link_access ?></div>
