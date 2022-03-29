/**
 * @file
 */
(function ($) {

  Drupal.behaviors.salto_share = {
    attach: function (context, settings) {

      $('#edit-field-og-group-und-0-default').once('change').click(function () {

        //get group id
        var group_id = $("#edit-field-og-group-und-0-default option:selected").val();

        //get node id
        var node_id = $(".shared_post_preview").attr('data-nid');

        var self = $(this);
        var container = $("#salto-share-status-message-container");
        var url = "/node/" + node_id + "/share_check/group/" + group_id;
        var html_spin = '  <i class="icon glyphicon glyphicon-refresh glyphicon-spin pull-right" aria-hidden="true"></i>';

        //check if ajax request is neededd
        if (!$.isNumeric(group_id)) {
          //_none selected - not sharing with group
          container.hide();
          return true;
        }

        var spinner_temp = $('.form-item-field-og-group-und-0-default > label').after(html_spin);

        $.ajax({
          type: "GET",
          url: url,
          success: function (response) {

            if (response !== 'ok') {

              container.html(response);
              container.show();

              //remove spinner
              $('.form-item-field-og-group-und-0-default .glyphicon-spin').remove();
            } else {
              container.hide();
              $('.form-item-field-og-group-und-0-default .glyphicon-spin').remove();
            }
          }
        });
        return false;
      });
    }
  }
})(jQuery);

