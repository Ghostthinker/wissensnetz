<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['compability']: Browser Compability Messges JS/Cookies
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */

?>
<meta name="auth-token" content="<?php print  $_SESSION['sso']['access_token']?>">
<meta name="tum-url" content="<?php print $global_header['tumUrl'];?>">
<?php if(!$show_global_header): ?>
  <div
    class="userbar-desktop <?php print $wn_blanko_instance_key ? $wn_blanko_instance_key : ''; ?>">
    <div class="container">
      <div class="navbar-collapse collapse navbar-user pull-right">
        <?php if (!empty($secondary_nav)): ?>
          <?php print render($secondary_nav); ?>
        <?php endif; ?>
      </div>
    </div>
  </div>



<?php else: ?>
  <div id="global-header">
    <script src="<?php print $global_header['global_header_url']; ?>" type="module"></script>
    <style></style>
    <global-header
      logo="<?php print $global_header['logoUrl']; ?>"
      backendUrl="<?php print $global_header['backendUrl']; ?>"
      ogTitle="<?php print $global_header['ogTitle'] ?>"
      localMenu="<?php print $global_header['localMenu'] ?>"
      hideLogo
    >
    </global-header>
  </div>
<?php endif; ?>
<?php if (WN_TESTS_RUNNING === FALSE): ?>
  <div class="userbar">
    <div class="container">
      <div class="navbar-header">
        <?php if ($logo): ?>
          <a class="logo navbar-btn pull-left"
             href="<?php print $front_page; ?>"
             title="<?php print t('Home'); ?>">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
          </a>
        <?php endif; ?>
      </div>
      <div class="flex-align-center right">
        <div class="navbar-collapse collapse navbar-user pull-right">
          <?php if (!empty($secondary_nav)): ?>
            <?php print render($secondary_nav); ?>
          <?php endif; ?>
        </div>
        <div class="navbar-burger">
          <button type="button" class="navbar-toggle" data-toggle="collapse"
                  data-target="#navbar-primary">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar spin"></span>
            <span class="icon-bar spin"></span>
            <span class="icon-bar spin"></span>
          </button>
        </div>
      </div>
    </div>
  </div>
<?php endif; ?>
<header id="navbar" role="banner"
        class="<?php print $navbar_classes; ?> <?php print $wn_blanko_instance_key ? $wn_blanko_instance_key : ''; ?>">
  <div class="container">

    <div class="navbar-header">

      <div class="navbar-header">
        <?php if ($logo): ?>
          <a class="logo" href="<?php print $front_page; ?>"
             title="<?php print t('Home'); ?>">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
          </a>
        <?php endif; ?>
      </div>

      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <div id="navbar-primary" class="navbar-collapse collapse">

          <?php if (!empty($page['search'])): ?>
            <nav role="search">
              <?php print $page['search']; ?>
            </nav>
          <?php endif; ?>

          <nav role="navigation">
            <?php if (!empty($primary_nav)): ?>
              <?php print render($primary_nav); ?>
            <?php endif; ?>

            <?php if (!empty($page['navigation'])): ?>
              <?php print render($page['navigation']); ?>
            <?php endif; ?>
          </nav>
        </div>

      <?php endif; ?>
    </div>
</header>

<div
  class="main-container container <?php print $wn_blanko_instance_key ? $wn_blanko_instance_key : ''; ?>">

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header>

  <div class="row">

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>
    <?php endif; ?>

    <section<?php print $content_column_class; ?>>
      <?php if (!empty($page['highlighted'])): ?>
        <div
          class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif; ?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php if (!empty($page['toolbar'])): print render($page['toolbar']); endif; ?>
      <?php print render($page['content']); ?>

      <?php if (!empty($floating_button['content'])): ?>
        <div class="floating-button-wrapper">
          <?php print render($floating_button['content']); ?>
        </div>
      <?php endif; ?>
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>

      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>
    <?php endif; ?>

    <?php if (!empty($page['content_footer'])): ?>
      <section class="content_footer col-sm-12">
        <div class="content_footer_content">
          <?php print render($page['content_footer']); ?>
        </div>
      </section>
    <?php endif; ?>
  </div>

</div>

<footer
  class="footer container <?php print $wn_blanko_instance_key ? $wn_blanko_instance_key : ''; ?>">
  <?php print render($page['footer']); ?>
</footer>
