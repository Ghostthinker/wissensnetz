(function ($) {

  /**
   * Overriding the standard password strength check
   */
  Drupal.behaviors.salto_user_password = {
    attach: function (context, settings) {
      // Set a default for our pw_status.
      pw_status = {
        strength: 0,
        message: '',
        indicatorText: ''
      }

      $('input.password-field', context).once('salto_user_password', function () {
        passwordInput = $(this);
        passwordCheck = function (e) {

          e.stopImmediatePropagation();

          if (passwordInput.val() != passwordInput.data('value')) {
            passwordInput.addClass('salto_user_password_changed');
          }
          passwordInput.data('value', passwordInput.val());

          if (Drupal.salto_user_password_check_request) {
            Drupal.salto_user_password_check_request.abort();
          }

          Drupal.salto_user_password_check_request = $.post(
            '/salto/user_password/check',
            {
              password: encodeURIComponent(passwordInput.val())
            },
            function (data) {
              pw_status = data;

              user_passwordCheck();

            });
        };
        passwordInput.keyup(passwordCheck);//.focusin(passwordCheck);
        passwordInput.focusin(passwordCheck);
      });

      // We are overriding the normal evaluatePasswordStrength and instead are
      // just returning the current status.
      Drupal.evaluatePasswordStrength = function (password, translate) {
        return pw_status;
      };

      //fix password-suggestions description container
      //prevent from showing up if empty (no response yet from server)
      $('div.password-suggestions').on('show', function (e) {
        if ($(this).is(':empty')) {
          $(this).css('visibility', 'hidden');
          $(this).css('position', 'absolute');
        } else {
          $(this).css('visibility', 'visible');
          $(this).css('position', 'relative');
        }
      });

      /*
       * reusing from user.js
       */

      // Check the password strength.
      function user_passwordCheck() {
        var passwordDescription = $('div.password-suggestions', outerWrapper);
        var innerWrapper = $('input.password-field').parent();
        var outerWrapper = $('input.password-field').parent();

        // Evaluate the password strength.
        var result = Drupal.evaluatePasswordStrength(passwordInput.val(), settings.password);

        // Update the suggestions for how to improve the password.
        if (passwordDescription.html() != result.message) {
          passwordDescription.html(result.message);
        }

        // Only show the description box if there is a weakness in the password.
        if (result.strength == 100) {
          passwordDescription.hide();
        } else {
          passwordDescription.show();
        }

        // Adjust the length of the strength indicator.
        $(innerWrapper).find('.indicator').css('width', result.strength + '%');

        // Update the strength indication text.
        $(innerWrapper).find('.password-strength-text').html(result.indicatorText);

        // trigger keyup event to render the new status
        if (passwordInput.hasClass('salto_user_password_changed')) {
          passwordInput.removeClass('salto_user_password_changed');
          passwordInput.keyup();
        }

      };
    }
  };

  // We are overriding the normal evaluatePasswordStrength and instead are
  // just returning the current status.
  Drupal.evaluatePasswordStrength = function (password, translate) {
    return Drupal.settings.pw_status;
  };


})(jQuery);
