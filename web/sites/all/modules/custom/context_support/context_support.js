/**
 * @file

 *  Creates a tab by the scrollbar for help
 */
(function ($) {

  Drupal.behaviors.context_support = {
    attach: function (context, settings) {


      $('.contact-form:not(.spc-processed)', context).addClass('spc-processed').each(function (index, el) {
        $('.contact-form', context).closest('form').data('confirmed', false);

        $(this).keydown(function (event) {
          if (event.keyCode == 13) {
          }
        });

        $(this).find(":input").change(function () {
          $(this).closest('form').data('changed', true);
        });

        $(this).on('submit', function (event) {
          event.preventDefault();
        });
      });
    }
  };
})(jQuery);
