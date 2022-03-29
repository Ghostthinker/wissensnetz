(function ($) {

  /**
   * onsite notification js settings and actions
   */

  Drupal.behaviors.onsite_notifications = {
    attach: function (context, settings) {

      //override mobile behavior
      $('.userbar .notifications-dropdown-link').one('click', function (event) {
        document.location.href = $(this).attr('href');
        return false;
      });

      //check mobile resolution
      //popover for desktop only
      $('.notifications-dropdown-link').one('click', function (e) {
        Drupal.OnsiteNotification.loadNotificationsAjax();
      });


      //mark as read actions - add classes
      $('.entity-message .flag-notification-mark-as-read a').once().bind('click', function (e) {
        if ($(this).hasClass('unflag-action')) {
          $(this).closest('.entity-message').removeClass('message-read');
          $(this).closest('.entity-message').addClass('message-unread');
        } else {
          $(this).closest('.entity-message').removeClass('message-unread');
          $(this).closest('.entity-message').addClass('message-read');
        }

      });

      //
      $('.notification-settings-row .mail input').once().bind('change', function (e) {
        if (this.checked == 1) {
          $(this).closest('.notification-settings-row').find('.status input').attr('checked', 'checked');
        }
      });

      //
      $('.notification-settings-row .status input').once().bind('change', function (e) {
        if (this.checked == 1) {
          $(this).closest('.notification-settings-row').find('.mail input').removeAttr('disabled');
        } else {
          $(this).closest('.notification-settings-row').find('.mail input').removeAttr('checked').attr('disabled', 'disabled');
        }
      });

      //
      $('.notifications-actions a').once().bind('click', function (event) {
        event.preventDefault();
        var token = Drupal.OnsiteNotification.getURLParameter($(this).attr('href'), 'token');

        Drupal.OnsiteNotification.MarkNotificationsAsRead(token, 'token');
        $('.notifications-dropdown .notifications-actions').hide();
        return false;
      });

    }
  }


  Drupal.OnsiteNotification = Drupal.OnsiteNotification || {};

  /**
   * Load the new onsite notification ajax content
   * @return {[type]} [description]
   */
  Drupal.OnsiteNotification.loadNotificationsAjax = function () {
    $.ajax({
      url: Drupal.settings.basePath + 'notifications/js/load',
      type: 'GET',
      dataType: 'json',
    })
      .done(function (data) {

        $('.notifications-dropdown .notifications-content').html(data.output);
        if (parseInt(data.count) > 0) {

          $('.notifications-dropdown .notifications-actions').show();
        }
      })
      .fail(function () {

      })
      .always(function () {

      });
  };
  //mark all as read -
  Drupal.OnsiteNotification.MarkNotificationsAsRead = function (token) {

    jQuery('.flag-notification-mark-as-read a.flag-action').click();
    $.ajax({
      url: Drupal.settings.basePath + 'notifications/js/markasread?token=' + token,
      type: 'GET',
      dataType: 'json',
    })
      .done(function (data) {

        $('.notifications-dropdown .notifications-content').html(data.output);
      })
      .fail(function () {
        console.log('error');
      })
      .always(function () {
        console.log('complete');
      });

    $('.notifications-dropdown-link').html(Drupal.t('Notifications'));
  };

  Drupal.OnsiteNotification.getURLParameter = function (url, name) {
    name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
    var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
      results = regex.exec(url);
    return results == null ? '' : decodeURIComponent(results[1].replace(/\+/g, ' '));
  };
})(jQuery);
