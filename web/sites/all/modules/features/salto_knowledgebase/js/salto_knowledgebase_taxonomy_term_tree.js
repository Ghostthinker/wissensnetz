(function ($) {

  Drupal.behaviors.salto_knowlegebase_term_reference_tree = {
    attach: function (context, settings) {

      $('.term-reference-tree .form-checkbox').change(function (event) {
        var event_target = $(event.target);

        var children = event_target.closest("li").find("ul").find('input[type="checkbox"]');
        if (event_target.attr('checked')) {

          $(this).parent().prev().removeClass('term-reference-tree-collapsed');
          $(this).parent().prev().siblings('ul').slideDown('fast');
        } else {


          $(children).prop("checked", false);

          $(this).parent().prev().addClass('term-reference-tree-collapsed');
          $(this).parent().prev().siblings('ul').slideUp('fast');

        }
      });

    }
  }
})(jQuery);
