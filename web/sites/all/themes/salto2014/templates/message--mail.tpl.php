<?php if ($single): ?>
<table>
  <?php endif ?>
  <tr>
    <td><?php print $user_picture; ?></td>
    <td>
      <a class="message-link" href="<?php print $url ?>"
         style="color: #9b9b9b;">
        <?php print $main_content ?>
      </a>
    </td>
  </tr>
  <?php if (!empty($content_preview)) : ?>
    <tr>
      <td></td>
      <td
        style="border: 1px solid #ccc; background: #f0f0f0; padding: 8px 10px;">
        <?php print($content_preview); ?>
      </td>
    </tr>
  <?php endif ?>
  <?php if ($single): ?>
</table>
<?php endif ?>
