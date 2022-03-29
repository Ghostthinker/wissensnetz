/**
 * @file
 */
(function ($) {

  Drupal.behaviors.salto_help_quick_guide = {
    attach: function (context, settings) {
      var videos = document.querySelectorAll('#quick-guide video');
      for (var video of videos) {
        video.removeAttribute('controls');
        video.removeAttribute('height');
        video.removeAttribute('width');
      }

      //flagging
      $('#quick-guide .show-not-more').once('quick-guide').click(function () {
        //ajax response
        salto_help_quick_guide_panel_action();
        return false;
      });


      function salto_help_quick_guide_panel_action() {
        var flag = false;
        var url = '/salto/help/feedback/quick/' + flag + '/';

        setTimeout(function () {
          $.ajax({
            type: "GET",
            url: url,
            success: function (response) {
              var el = document.querySelector('.quick-guide-wrapper');
              el.classList.add('hidden');
            }
          });
        }, 1000);

        return false;
      }

    }
  };

})(jQuery);

