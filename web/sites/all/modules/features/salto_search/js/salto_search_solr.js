(function ($) {


  Drupal.behaviors.salto_search_solr = {
    attach: function (context, settings) {

      document.addEventListener('load', selfTarget());

      if (Drupal.settings.sync_words) {
        $('#salto-search-search-form').find('.salto-search').val(Drupal.settings.sync_words[0]);
        //set suggest on the menu block links
        $('ul.menu.nav a').each(function () {
          var $href = $(this).attr('href');
          var queryName = 'search_api_views_fulltext';
          $href = $href.substr(0, $href.indexOf(queryName));
          $(this).attr('href', $href + queryName + '=' + Drupal.settings.sync_words[0]);
        });
      }

      $('#saltoSearchName').text($('#salto-search-search-form').find('.salto-search').val());

      if (typeof Drupal.settings.mean_hide === 'undefined') {
        $('.view-header').find('.suggestion-link-org').hide();
      } else {
        $('.view-header').find('.suggestion-link-org').show();
      }
    }
  };

  function selfTarget() {
    $('.pane-content ul.menu.nav a').each(function () {
      console.log($(this));
      $(this).attr('target', '_self');
    });
  }

}(jQuery));
