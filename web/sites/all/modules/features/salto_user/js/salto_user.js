(function ($) {

  var salto_user_crop_description = '';

  Drupal.behaviors.salto_user = {
    attach: function (context, settings) {

      $('[id^=edit-profile-main-field-user-picture-und-0-remove-button]').once('salto_user_remove').mousedown(function () {


        $(document).ajaxComplete(function (event, xhr, settings) {
          if (settings.url.indexOf('/file/ajax/profile_main/field_user_picture/') >= 0) {
            $('.image-widget-data .user-picture img').attr('src', '/system/files/uploads/image/user.jpg').css('width', '100%');
          }
        });

        //when removing the image crop_description is also beeing removed, so we need to reset the variable
        salto_user_crop_description = '';
      });


      // start uploading after profile picture file was selected
      $('[id^=edit-profile-main-field-user-picture-und-0-upload]').once('salto_user').change(function () {
        // select the form and submit

        //show processing throbber
        var html = '';
        html += '  <div id="modal-throbber">';
        html += '    <div class="modal-throbber-wrapper">';
        html += Drupal.settings.CToolsModal.throbber;
        html += '    </div>';
        html += '  </div>';

        $(this).parent().find('img').css('visibility', 'hidden');
        $(this).parent().prepend(html);

        //trigger upload event
        $(this).parent().find('[type=submit]').mousedown();


        var new_preview = $('img.imgfocus-img').clone();


      });


      //Bind change profile picture button event
      $('#user-profile-form  .image-preview').once('salto_user').click(function () {

        var self = $(this);
        //hide preview div
        self.hide();

        //show focus widget
        $('#user-profile-form .image-widget-data .imagefield-focus').show();
        $('#user-profile-form .image-widget-data .imagefield-focus').css('visibility', 'visible');
        $('#user-profile-form .image-widget-data .imagefield-focus').css('position', 'relative');
        //show buttons (remove button)
        $('#user-profile-form .image-widget-data input').show();
        $('#user-profile-form .image-widget-data button').show();


        if (salto_user_crop_description === '') {
          salto_user_crop_description = '<div id="salto_user_crop_description" style="background-color:#eee; z-index:25; color:#333; display:block; position:absolute; bottom:-74px; padding:10px;">' + Drupal.t('Click on the image to crop') + '</div>'
          salto_user_crop_description = $('#user-profile-form .image-widget-data').after(salto_user_crop_description).parent().find('#salto_user_crop_description');

          salto_user_crop_description.width($('#user-profile-form .imgfocus-wrapper').width() - 20 + 2);

          $('#user-profile-form .image-widget').css('position', 'relative');
        }

        $(salto_user_crop_description).show();

        var hide_crop_widget_button = $('<button class="btn btn-primary form-submit hide-crop-widget-button"><span class="icon-check"></span>OK</button>');
        $('#user-profile-form .image-widget-data').prepend(hide_crop_widget_button);

        hide_crop_widget_button.once('salto_user').click(function () {
          self.show();

          $('#user-profile-form .image-widget-data .imagefield-focus').hide();
          $('#user-profile-form .image-widget-data .imagefield-focus').css('visibility', 'hidden');
          $('#user-profile-form .image-widget-data input').hide(); //input for admin interface
          $('#user-profile-form .image-widget-data button').hide(); //button for bootstrap theme


          //no selection box set
          $(salto_user_crop_description).hide();

          if ($('#user-profile-form .imgfocus-box.imgfocus-selbox').css('display') === 'none') {
            return false;
          }

          //crop live preview image
          var preview_width = $('#user-profile-form div.image-preview').first().width();
          var preview_height = $('#user-profile-form div.image-preview').first().height();

          var focus_sel_box = $('#user-profile-form .imgfocus-box.imgfocus-selbox');
          var focus_img_wrapper = focus_sel_box.parent();

          var new_preview = $('img.imgfocus-img').last().wrap('<div class="salto-user-profile-preview"></div>').parent();
          new_preview = $(new_preview).wrap(new_preview);
          new_preview.css('width', preview_width);
          new_preview.css('height', preview_height);

          //relation in crop view -> rel to preview img size
          var rel_w = parseInt(focus_sel_box.css('width')) / preview_width;
          var rel_h = parseInt(focus_sel_box.css('height')) / preview_height;

          new_preview.find('img').css('margin-top', '-' + parseInt(focus_sel_box.css('top')) / rel_w + 'px');
          new_preview.find('img').css('margin-left', '-' + parseInt(focus_sel_box.css('left')) / rel_h + 'px');
          new_preview.find('img').css('width', focus_img_wrapper.width() / rel_w);
          new_preview.find('img').css('height', focus_img_wrapper.height() / rel_h);
          new_preview.find('img').css('max-width', 'none');
          new_preview.find('img').css('opacity', '1');
          new_preview.css('display', 'block');
          new_preview.css('position', 'relative');


          //remove old img/preview, replace by live preview
          $('#user-profile-form .image-preview img').remove();
          $('#user-profile-form .image-preview .salto-user-profile-preview').remove();
          $('#user-profile-form .image-preview').prepend(new_preview);


          return false;

        });

      });


    }
  };


}(jQuery));
