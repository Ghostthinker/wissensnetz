<?php /**
 * @file a theme for buttongroups
 *
 * $class - the class of the group
 * $type - button or icon
 * $title - title of the group
 * $items
 */
?>
<div class="btn-group <?php print $class ?>">

  <?php if (!empty($title)) : ?>
    <a
      class="btn btn-primary btn-actions dropdown-toggle title <?php print $button_class ?>"
      data-toggle="dropdown" href="#"><?php print $title ?>
      <span class="caret"></span>
    </a>
  <?php else : ?>
    <a class=" dropdown-toggle title" data-toggle="dropdown" href="#"></a>
  <?php endif ?>
  <ul class="dropdown-menu">
    <?php foreach ($items as $item) : ?>
      <?php if ($item == '--'): ?>
        <li class="divider"></li>
      <?php else : ?>
        <li><?php print $item ?></li>
      <?php endif ?>
    <?php endforeach ?>
  </ul>
</div>
