(function ($) {

  Drupal.behaviors.dialog_gateway = {
    attach: function (context, settings) {

      $('#salto-online-meeting-group-active:not(.salto-online-meeting-group-active-processed)').each(function () {
        Drupal.SaltoOnlineMeetingsActiveListener.init(this);
      }).addClass('salto-online-meeting-group-active-processed');


      $('#dialog_status:not(.dialog_status-processed)').each(function () {
        Drupal.SaltoOnlineMeetingJoinLinkListener.init(this);
      }).addClass('dialog_status-processed');

      $('.salto-online-meeting-recordings-wrapper:not(.salto-online-meeting-recordings-wrapper-processed)').each(function () {
        Drupal.SaltoOnlineMeetingRecording.init(this);
      }).addClass('salto-online-meeting-recordings-wrapper-processed');

    }
  };

  Drupal.SaltoOnlineMeetingsActiveListener = {
    initCompleted: false,
    init: function (elem) {
      this.$elem = $(elem);

      if (this.initCompleted) {
        return;
      }
      this.group_nid = this.$elem.data('gid');
      this.url = Drupal.settings.basePath + 'online-meetings/ajax/status';
      if(this.group_nid){
        this.url += '?og_nid=' + this.group_nid;
      }

      this.check_status();
      this.initCompleted = true;
    },
    poll: function () {
      let timeout = Drupal.settings.online_meeting.ajax_poll_interval * 1000;
      timeout = timeout < 500 ? 500 : timeout;
      setTimeout(() => {
        this.check_status()

      }, parseInt(timeout));
    },
    check_status: function () {
      if (document.hasFocus()) {
        $.ajax({
          type: 'POST',
          url: this.url,
          data: {},
          dataType: 'json',
          success: (response) => {
            this.$elem.html(response);
          },
          complete: () => {

          },
        });
      }
      this.poll();
    }
  };

  Drupal.SaltoOnlineMeetingJoinLinkListener = {
    initCompleted: false,
    init: function (elem) {
      this.$elem = $(elem);

      if (this.initCompleted) {
        return;
      }
      this.online_meeting_nid = this.$elem.data('nid');
      this.url = Drupal.settings.basePath + 'node/' + this.online_meeting_nid + '/dialog/ajax/status';
      this.check_status();
      this.initCompleted = true;

      const mql = window.matchMedia('(max-width: 1024px)');
      mql.addEventListener('change', (e) => {
        this.checkResponsive(e.matches === true);
      });

      this.checkResponsive(window.matchMedia('(max-width: 1024px)').matches);
    },
    checkResponsive: function (isMobile) {
      if (isMobile) {
        $('#dialog_status').appendTo('.panel-pane.pane-node-content');
      } else {
        $('#dialog_status').appendTo('.dialog-status-pane .pane-content');

      }
    },
    poll: function () {

      let timeout = Drupal.settings.online_meeting.ajax_poll_interval * 1000;
      timeout = timeout < 500 ? 500 : timeout;

      //poll with a larger frequency when there is no focus
      if (!document.hasFocus()) {
        timeout = 30000;
      }

      setTimeout(() => {
        this.check_status()

      }, parseInt(timeout));
    },
    check_status: function () {

      $.ajax({
        type: 'POST',
        url: this.url,
        data: {},
        dataType: 'json',
        success: (response) => {
          if (response.hasOwnProperty('status') && response.hasOwnProperty('joinlink')) {
            this.$elem.html(response.joinlink);
          }

        },
        complete: () => {
        },
      });

      this.poll();
    },
  };

  Drupal.SaltoOnlineMeetingRecording = {
    initCompleted: false,
    init: function (elem) {
      this.$elem = $(elem);

      if (this.initCompleted) {
        return;
      }
      this.group_nid = this.$elem.data('nid');

      this.check_recordings();
      this.initCompleted = true;
    },
    check_recordings: function () {

      const wrapper = $('.salto-online-meeting-recordings-wrapper');

      if (wrapper.length == 0) {
        return;
      }

      var nid = this.group_nid;
      var url = Drupal.settings.basePath + "node/" + nid + "/dialog/ajax/recordings";

      wrapper.parent().hide();

      $.ajax({
        type: "POST",
        url: url,
        data: {},
        dataType: 'json',
        success: function (response) {
          if (response.content != ''){
            wrapper.html(response.content);
            wrapper.parent().fadeIn('slow');

            //add click lock on video import
            var clickLock = 0;

            $('.salto-online-meeting-recordings-wrapper .form-submit').on('click', function(){
              if (clickLock === 0) {
                clickLock = 1;
              }else{
                $('.salto-online-meeting-recordings-wrapper .form-submit').attr('disabled', 'disabled');
              }
            });


          }
        }
      });
    }
  };

})(jQuery);
