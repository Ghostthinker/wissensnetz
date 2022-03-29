(function ($) {


  Drupal.behaviors.salto_search_facetapi_chosen = {
    attach: function (context, settings) {
      jQuery('.facetapi-multiselect', context).each(function () {
        jQuery(this).chosen({
        });
      });
    }
  }
}(jQuery));
