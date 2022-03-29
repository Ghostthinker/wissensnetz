<div class="col-md-12 invitelist-item" id="invitelist-item-<?php print $id; ?>">
  <div class="row col-md-12 invitelist-row">
    <div class="col-md-2 col-xs-3 item-label user-info-item">
      <?php print $image ?>
    </div>
    <div class="col-md-3 col-xs-8 name">
      <?php print $name ?>
    </div>
    <?php if (!empty($organisation)): ?>
      <?php print "<div class=\"col-md-3 col-xs-8 permissions checkbox-mark\">" ?>
    <?php else: ?>
      <?php print "<div class=\"col-md-6 col-xs-8 permissions checkbox-mark\">" ?>
    <?php endif ?>
    <?php if (!empty($permissions)): ?>
      <?php foreach ($permissions as $rid => $permission) : ?>
        <label class="container">
          <input type="checkbox" class="item-rid" value="<?php echo $rid; ?>"><?php echo $permission['permission'] ?>
          <span class="checkmark"></span>
        </label>
      <?php endforeach; ?>
    <?php endif ?>
  </div>
  <?php if (!empty($organisation)): ?>
    <?php print "<div class=\"col-md-3 col-xs-8\">" ?>
    <?php print $organisation->title; ?>
    <?php print "</div>" ?>
  <?php endif ?>
  <div class="col-md-1 col-xs-1 remove">
    <button class="btn btn-remove icon-only grey"
            id="remove-icon"
            type="button"><i class="fa fa-trash"></i></button>
  </div>
</div>
</div>
