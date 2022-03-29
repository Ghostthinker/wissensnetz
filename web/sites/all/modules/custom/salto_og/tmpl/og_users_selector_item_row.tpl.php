<li class="row col-md-12 col-xs-12 item user-info-list" id="user-item-<?php print $uid ?>">
  <div class="col-md-2 col-xs-3 item-label user-info-item"><?php print $image ?></div>
  <div class="col-md-9 col-xs-8 item-label user-info-item">
    <?php print $name ?><br>
    <?php if (!empty($mail)) : ?>
      <span class="user-mail mail">
          <?php print $mail ?>
        </span>
    <?php endif ?>
  </div>
  <div class="col-md-1 col-xs-1 user-info-item">
    <button class="btn btn-add icon-only primary"
            id="invite-by-account-button"
            type="button"><i class="fa fa-plus-circle"></i></button>
  </div>
</li>
