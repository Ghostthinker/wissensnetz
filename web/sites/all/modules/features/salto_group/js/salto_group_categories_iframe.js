/**
 * @file
 */
(function ($) {

  Drupal.behaviors.salto_group_categories_iframe = {
    attach: function (context, settings) {
      window.addEventListener("message", this.receiveMessage, false);

    },
    receiveMessage: function (event) {

      if (event.data == "salto-submit") {
        $("form#taxonomy-overview-terms").submit();
      }

    }
  };

})(jQuery);

