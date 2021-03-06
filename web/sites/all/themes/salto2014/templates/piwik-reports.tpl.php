<?php
/**
 * @file
 * Default implementation of the visitors overview report template.
 *
 * Available variables:
 * - $data_url: complete url with params to get selected report.
 */
foreach ($data_url as $data) {
  if (!is_null($data['empty_text'])) {
    print $data['empty_text'];
  }
  else {
    ?>
    <h2><?php print $data['title']; ?></h2>
    <div class="widgetIframe">
      <iframe width="100%"
              height="<?php print $data['iframe_height'] . '" src="' . $data['url']; ?>"
              scrolling="yes" frameborder="0" marginheight="0"
              marginwidth="0"></iframe>
    </div>
  <?php }
}
