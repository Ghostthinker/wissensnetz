(function ($) {

  /*
   * snippet to allow you to bind events when dom elements are shown hidden with jQuery.
   */
  Drupal.behaviors.salto_organisation_overview = {
    attach: function (context, settings) {

      //initial number of suborganisation to show
      var num_suborganisation = 3;

      $('.view-salto-organisations-overview .suborganisations-directory .view-content').once('salto_organisation_overview').each(function () {

        //hide suborganisation if its index is greater than num_suborganisation
        if ($(this).find('> div').length > num_suborganisation) {
          $(this).find('> div').each(function (index) {
            if (index >= num_suborganisation) {
              $(this).hide();
            }
          });

          //num of organisations which are hidden
          var count = $(this).find('> div').length - num_suborganisation;

          //show x more button
          var show_more = '</span><a href="#" class="show-more-suborganisations"><span class="arrow">' + count + ' weitere</a>';

          $(this).once('salto_organisation_overview_toggle').append(show_more);

          $('.show-more-suborganisations').once('salto_organisation_overview_toggle').click(function () {
            $(this).parent().find('> div').show();
            $(this).hide();
            return false;
          });
        }
      });
    }
  }
})(jQuery);
