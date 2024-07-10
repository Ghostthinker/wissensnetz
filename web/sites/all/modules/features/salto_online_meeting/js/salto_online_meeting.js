(function ($) {

  Drupal.behaviors.salto_online_meetings = {
    attach: function (context, settings) {
      //hide show end date initially
      $('.form-item-field-online-meeting-date-und-0-show-todate').hide();

      this.set_render_mode_for_meeting_options();
      this.set_render_mode_time_selection();
      $("#edit-field-meeting-options-und").change(() => {
          this.set_render_mode_for_meeting_options();
        }
      );

      $("#edit-field-recurring-meeting-und").change(() => {
          this.set_render_mode_time_selection();
        }
      );

      $("#edit-field-online-meeting-date-und-0-value-datepicker-popup-0").change(() => {
          this.syncDateFields();
        }
      );


      //Remodel teh time picker
      $(".form-item-field-online-meeting-date-und-0-value2 > label").hide();
      $(".form-item-field-online-meeting-date-und-0-value2 .form-item-field-online-meeting-date-und-0-value2-date").hide();

      $("#field-online-meeting-date-add-more-wrapper").append("<label class='label-small'>Uhrzeit</label><div class=\"time-wrapper\"><span class='startTime'></span><span class='timeSeperator'> bis </span><span class='endTime'></span> Uhr</div>");
      const dateLabel = $(".form-item-field-online-meeting-date-und-0-value-date label");
      $("<label style=\"display:block\" class='label-small'>Datum</label>").insertAfter(dateLabel);
      dateLabel.html("Zeitpunkt");

      const timeWrapper = $("#field-online-meeting-date-add-more-wrapper").find('.time-wrapper');
      const timeStart = $("#edit-field-online-meeting-date-und-0-value-timepicker-popup-1");
      timeStart.appendTo(timeWrapper.find(".startTime"));

      const timeEnd = $("#edit-field-online-meeting-date-und-0-value2-timepicker-popup-1");
      timeEnd.appendTo(timeWrapper.find(".endTime"));

      $(".form-item.form-item-field-online-meeting-date-und-0-value-time").hide();
      $(".form-item.form-item-field-online-meeting-date-und-0-value2-time").hide();


      //Share meeting
      $('.salto-online-meeting-share-button .dropdown-toggle.action_share_meeting').click(function(e){
        e.preventDefault();
        e.stopPropagation();
        $(this).next('.salto-online-meeting-share-button .dropdown-menu').toggleClass('keep-open');
        $('.salto-online-meeting-share-link-text').select();
      });

      $('.salto-online-meeting-share-button .dropdown-menu').click(function(e){
        e.stopPropagation();
      });

      $(document).click(function(){
        $('.salto-online-meeting-share-button .dropdown-menu.keep-open').removeClass('keep-open');
      });



    },
    set_render_mode_for_meeting_options: function () {
      const meeting_options = $("#edit-field-meeting-options-und").val();
      if (meeting_options === "online_meeting") {
        $('#edit-field-webinar-size').hide();
        $('#edit-field-recurring-meeting').show();
      } else {
        $('#edit-field-webinar-size').show();
        $('#edit-field-recurring-meeting').hide();
      }
      this.set_render_mode_time_selection();
    },
    set_render_mode_time_selection: function () {
      const meeting_options = $("#edit-field-meeting-options-und").val();
      console.log("set_render_mode_time_selection");
      let recurring_meeting_checked = $("#edit-field-recurring-meeting-und-1").is(":checked");
      if (recurring_meeting_checked && meeting_options === "online_meeting") {
        $('#edit-field-online-meeting-date').hide();
      } else {
        $('#edit-field-online-meeting-date').show();
      }
    },
    syncDateFields: function () {

      const val = $("#edit-field-online-meeting-date-und-0-value-datepicker-popup-0").val();
      $("#edit-field-online-meeting-date-und-0-value2-datepicker-popup-0").val(val);
    }

  }
})(jQuery);


