/**
 * @file

 *  Creates a tab by the scrollbar for help
 */
(function ($) {
  Drupal.behaviors.salto_tagcloud = {
    attach: function (context, settings) {
      var word_list = settings.salto_tagcloud.word_list;

      $("#salto_tagcloud").once("tagcloud").jQCloud(word_list, {
        autoResize: true,
        removeOverflowing: true
      });
    }
  };
})(jQuery);
