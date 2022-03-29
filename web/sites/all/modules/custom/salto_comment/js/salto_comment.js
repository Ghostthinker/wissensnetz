(function ($) {
  Drupal.behaviors.salto_comment = {
    attach: function (context, settings) {

      //add toggle bar
      var toggle_comments_bar = '<div class="salto_comment_toggle_comments expanded" >' + Drupal.t('Toggle comments') + '<span class="arrow"></span></div>';
      var processed_comments = new Array();

      $.each($('.ajax-comment-wrapper.indented'), function (index) {
        var parent = $(this).closest('[id^=comment-wrapper-nid-]>.ajax-comment-wrapper');
        if ($.inArray(parent, processed_comments) === -1) {
          processed_comments.push();
          var toggle_comments_bars = parent.find('>.comment').once('salto_comment').after(toggle_comments_bar);

          $(toggle_comments_bars).parent().find('.salto_comment_toggle_comments').click(function () {
            $(this).parent().find('.ajax-comment-wrapper').slideToggle();
            $(this).toggleClass('expanded').toggleClass('collapsed');
          });
        }
      });
    }
  };

  /**
   * Own Bind Ajax behavior for comment links.
   */
  Drupal.behaviors.salto_comment_delete = {
    attach: function (context, settings) {
      $('.use-ajax-comments.ajax-comments-delete').once(function () {
        var link = $(this).get(0);
        $(this).mousedown(function (event) {
          var message = Drupal.t('Are you sure you want to delete the comment?') +
            " \n\n" + Drupal.t('This action cannot be undone.');
          event.preventDefault();
          var commentWrap = $(this).parents('.comment.ajax-comment-wrapper').get(0);
          bootbox.confirm({
            title: Drupal.t('Delete the comment?'),
            message: message,
            buttons: {
              confirm: {
                label: Drupal.t('Yes'),
                className: "btn-danger"
              },
              cancel: {
                label: Drupal.t('No'),
                className: "btn-cancel"
              }
            },
            callback: function (result) {
              if (result) {
                var content = '<p>' + Drupal.t('Comment delete.') + '</p>';
                $(commentWrap).find('.content .field-item p').replaceWith(content);
                var user = '<span class="username">Gast (nicht überprüft)</span>';
                $(commentWrap).find('.submitted a').replaceWith(user);
                $(commentWrap).find('.links .ajax-comments-reply').remove();
                $(commentWrap).find('.links .ajax-comments-edit').remove();
                $(commentWrap).find('.links .ajax-comments-delete').remove();

                $.ajax({url: link.href}).done(function (data) {
                  for (var k = 0; k < data.length; k++) {
                    if (data[k].command === 'insert') {
                      $(data[k].selector).parent().prepend(data[k].data);
                    }
                    if (data[k].command === 'remove') {
                      $(data[k].selector).remove();
                    }
                  }
                });
              }
            }
          });
        });
      });
    }
  };

}(jQuery));
