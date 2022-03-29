(function ($) {
  Drupal.salto_core_edit_protection = {};
  var salto_core_protection_click = false; // Allow Submit/Edit button
  var salto_core_protection_edit = false; // Dirty form flag
  /*
   * snippet to allow you to bind events when dom elements are shown hidden with jQuery.
   */
  Drupal.behaviors.salto_core_protection = {
    attach: function (context, settings) {
      $('.region-content :input').not('.salto-search').each(function () {
        $(this).bind('input', function () {
          salto_core_protection_edit = true;
          salto_core_protection_click = false;
        });
      });

      // Let all form submit buttons through
      $("[type='submit']").each(function () {
        $(this).addClass('node-edit-protection-processed');
        $(this).mousedown(function () {
          salto_core_protection_click = true;
          salto_core_protection_edit = false;
        });
      });

      // Catch all links and buttons EXCEPT for "#" links
      $("a, button, input[type='submit']:not(.node-edit-protection-processed)")
        .each(function () {
          $(this).click(function () {
            // return when a "#" link is clicked so as to skip the
            // window.onbeforeunload function
            if (salto_core_protection_edit && $(this).attr("href") != "#") {
              return 0;
            }
          });
        });

      //handle clicks on profile image
      $('.image-widget-data').click(function () {
        salto_core_protection_edit = true;
        salto_core_protection_click = false;
      });

      //handle clicks on plupload add button
      $('.plupload_add, .plupload_start').on('mousedown', function () {
        salto_core_protection_edit = true;
        salto_core_protection_click = false;
      });

      ////////////////////
      //normal file field
      //////////////////////
      $('.file-widget  .form-submit').on('mousedown', function () {
        salto_core_protection_edit = true;
        salto_core_protection_click = false;
      });
      $('.form-file').on('change', function () {
        salto_core_protection_edit = true;
        salto_core_protection_click = false;
      });


      //general plupload change event
      $(".plupload_filelist").bind("DOMSubtreeModified", function () {
        if (salto_core_protection_click) {
          salto_core_protection_edit = true;
        }

      });

      // Handle backbutton, exit etc.
      window.onbeforeunload = function () {
        if (typeof (CKEDITOR) != 'undefined' && typeof (CKEDITOR.instances) != 'undefined') {
          for (var i in CKEDITOR.instances) {
            if (CKEDITOR.instances[i].checkDirty()) {
              salto_core_protection_edit = true;
              break;
            }
          }
        }
        if (salto_core_protection_edit && !salto_core_protection_click) {
          salto_core_protection_click = false;
          return (Drupal.t("You will lose all unsaved work."));
        }
      }
    }
  }
})(jQuery);
