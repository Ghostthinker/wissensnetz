<?php if (!empty($actions)): ?>
  <div class="dropdown salto-og-action-links">
    <a class="btn btn-primary" data-toggle="dropdown"
       href="#"><?php print t('Manage') ?></a>
    <ul class="dropdown-menu" role="menu" aria-labelledby="dLabel">
      <?php foreach ($actions as $key => $al) : ?>
        <?php if ($key == 'divider'): ?>
          <li role="separator" class="divider"></li>
        <?php else: ?>
          <li role="presentation"><a role="menuitem" tabindex="-1"
                                     href="#"><?php print $al ?></a></li>
        <?php endif; ?>

      <?php endforeach ?>
    </ul>
  </div>
<?php endif ?>