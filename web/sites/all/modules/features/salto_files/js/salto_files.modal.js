(function ($) {

  /*
   * snippet to allow you to bind events when dom elements are shown hidden with jQuery.
   */
  Drupal.behaviors.salto_files_modal = {
    attach: function (context, settings) {

      jQuery("a[href^='/file/DEACTIVATED']").once().bind('click', function (e) {
        e.preventDefault();
        var url = jQuery(this).attr('href');
        console.log(url);
        bootbox.dialog({
          message: "<iframe style='width:100%; height: 100%; border:none' src='" + url + "/modal'></iframe>",
          className: "image-modal"
        });
      });
    }
  }
})(jQuery);
