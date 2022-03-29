<?php print render($page['content']); ?>
<style>
  #admin-menu,
  #skip-link,
  #block-salto-search-salto-block-search {
    display: none;
  !important;
  }

  body > *:not(.region-content),
  .context-support-tab {
    display: none !important;
  }

  html body.admin-menu {
    margin-top: 0 !important;
  }

  body.html:before {
    display: none;
  }

  .container:before {
    display: table;
  }

  .col-md-9 {
    padding: 0;
  }
</style>

<script>
  jQuery(document).ready(function () {
  });

  jQuery("body").on("click", "a", function (event) {
    jQuery(this).attr("target", "_parent");
  });
</script>
