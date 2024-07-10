(function ($) {
  // Funktion zum Initialisieren von Chosen
  Drupal.behaviors.ogSelectorChosen = {
    attach: function (context, settings) {
      $('#organisation-select', context).once('chosen', function () {
        $(this).chosen({
          disable_search: false,
          search_contains: true
        });
        $('.form-item-organisation .chosen-single span').text('- Bitte Organisation auswählen -');
      });
    }
  };
})(jQuery);
