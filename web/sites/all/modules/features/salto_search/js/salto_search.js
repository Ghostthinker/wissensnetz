(function ($) {


  Drupal.behaviors.salto_search = {
    attach: function (context, settings) {

      if ($('.breadcrumb a[href="/licenses"]').length) {
        $("#block-salto-search-salto-block-search").css('display', 'none');
      }


      //fix form-control problem on file/%fid
      $('#salto-search-search-form input[type="text"]:not([class*="form-control"])').addClass('form-control');

      //show results container when search input length > 0
      $('#salto-search-search-form').find('.salto-search').bind('input propertychange', function () {
        salto_search_show_hide_results_container();
      });

      $('#salto-search-search-form').find('.salto-search').change(function () {
        if ($(this).val().length > 0) {
          salto_search_show_hide_results_container();
          openSearch();
        }
      });

      $('#salto-search-search-form--2').find('.salto-search').change(function () {
        if ($(this).val().length > 0) {
          openSearch();
        }
      });

      $(document).bind('click', function (event) {
        // Check if we have not clicked on the search box
        if (!($(event.target).parents().andSelf().is('#salto-search-search-form'))) {
          $('#salto-search-search-form').find('.salto-search-result-container').hide();
        } else {
          salto_search_show_hide_results_container();
        }
      });

      function openSearch() {
        var search_val = $('#salto-search-search-form').find('.salto-search').val();
        if (!search_val) {
          search_val = $('#salto-search-search-form--2').find('.salto-search').val();
        }
        if (location.pathname.indexOf('search/file') > -1) {
          window.open("/search/file?search_api_views_fulltext=" + search_val, "_self");
        } else if (location.pathname.indexOf('search/comment') > -1) {
          window.open("/search/comment?search_api_views_fulltext=" + search_val, "_self");
        } else {
          window.open("/search/node?search_api_views_fulltext=" + search_val, "_self");
        }
      }

      // submit search via ENTER
      $('#salto-search-search-form').keyup(function (event) {
        if (event.keyCode === 13 && $('.salto-search').is(':focus')) {
          openSearch();
        }
      });
      $('#salto-search-search-form--2').keyup(function (event) {
        if (event.keyCode === 13 && $('.salto-search').is(':focus')) {
          openSearch();
        }
      });
    }
  };

  /**
   *
   */
  function salto_search_show_hide_results_container() {
    var search_val = $('#salto-search-search-form').find('.salto-search').val();
    if (search_val.length > 0) {
      $('#salto-search-search-form').find('.salto-search-result-container').show();
      //replace placeholder
      $('#salto-search-search-form').find('.salto-search-result-container .search-item-placeholder').html(search_val);


      $('#salto-search-search-form').find('.salto-search-result-container a').each(function (index) {
        var href_old = $(this).attr('href-old');
        if (typeof href_old === 'undefined') {
          //save old href state in href-old attribute
          $(this).attr('href-old', $(this).attr('href'));
          href_old = $(this).attr('href-old');
        }
        //attach query get parameter to all search links
        var query = 'search_api_views_fulltext=' + search_val;
        //? occurs in query
        if ($(this).attr('href-old').indexOf('?') != -1) {
          query = '&' + query;
        } else {
          query = '?' + query;
        }
        $(this).attr('href', $(this).attr('href-old') + query);

      });


    } else {
      $('#salto-search-search-form').find('.salto-search-result-container').hide();
    }
  }

}(jQuery));
