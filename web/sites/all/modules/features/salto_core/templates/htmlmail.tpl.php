<div id="outer" style="width:100%; background-color: #f0f0f0; ">
  <table style="border:none;padding:0 18px;margin: 0 auto;width:520px">
    <tbody>
    <tr width="100%" height="60">
      <?php if ($logo_fix_size) : ?>
        <td valign="top" align="left"
            style="background:#f0f0f0;padding:0;text-align:center">
          <img height="80" width="502" src="<?php print $logo ?>"
               title="<?php print variable_get('site_name', ''); ?>"
               style="font-weight:bold;font-size:18px;color:#fff;vertical-align:top">
        </td>
      <?php else: ?>
        <td valign="top" align="left"
            style="background:#ffffff;text-align:left;padding:18px">
          <img src="<?php print $logo ?>"
               title="<?php print variable_get('site_name', ''); ?>"
               style="font-weight:bold;font-size:18px;color:#fff;vertical-align:top">
        </td>
      <?php endif; ?>
    </tr>
    <tr width="100%">
      <td valign="top" align="left" style="background:#ffffff;padding:18px">
        <h1 style="font-size:20px;margin:0"><?php print $title ?></h1>
        <hr
          style="clear:both;min-height:1px;border:0;border:none;width:100%;background:#dcdcdc;color:#dcdcdc;margin:18px 0;padding:0">
        <div>
          <?php print $content ?>
        </div>
      </td>
    </tr>
    <tr width="100%">
      <td valign="top" align="left"
          style="background: #1b1b1b; color:#fff;padding:16px;font-size:14px;line-height:1.25em; min-height:100px">
        <?php print $footer ?>
      </td>
    </tr>
    </tbody>
  </table>
</div>


