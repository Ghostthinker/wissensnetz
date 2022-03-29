(function ($) {
  namespace('Drupal.media.browser');

  // Helper code & functions.
  // Get querystring as an array split on "&"
  var querystring = location.search.replace('?', '').split('&');
  var queryObj = {};
  // Loop through each name-value pair and populate object
  for (var i=0; i < querystring.length; i++) {
    queryObj[querystring[i].split('=')[0]] = querystring[i].split('=')[1];
  }

  var selToVal = function(sel) {
    return (sel) ? sel.join(',') : '';
  };

  var isNumericString = function(val) {
    return (parseInt(val) + "" == val);
  }
  //~Helper functions.

  Drupal.behaviors.imagefieldFocusMediaViews = {
    attach: function (context, settings) {
      console.log('binding');
      $('.view-content .media-item').bind('click', Drupal.media.browser.library.prototype.focus);
    }
  }

  var render = Drupal.media.browser.library.prototype.render;
  Drupal.media.browser.library.prototype.render = function(renderElement) {
    if (this.mediaFiles.length < 1) {
      $('<div id="media-empty-message" class="media-empty-message"></div>').appendTo(renderElement)
        .html(this.emptyMessage);
      return;
    }
    else {
      var mediaList = $('#media-browser-library-list', renderElement);
      // If the list doesn't exist, bail.
      if (mediaList.length === 0) {
        throw('Cannot continue, list element is missing');
      }
    }

    while (this.cursor < this.mediaFiles.length) {
      var mediaFile = this.getNextMedia();

      var data = {};
      data.obj = this;
      data.file = mediaFile;

      var listItem = $('<li></li>').appendTo(mediaList)
        .attr('id', 'media-item-' + mediaFile.fid)
        .html(mediaFile.preview)
        .bind('click', data, this.clickFunction)
        .bind('click', data, this.focus);
    }

    // If a query string exists, auto select the given file.
    if (isNumericString(queryObj['imagefield_focus_fid'])) {
      $('#media-item-' + queryObj['imagefield_focus_fid']).click();
    }

  }

  Drupal.media.browser.library.prototype.focus = function() {
    var that = $(this);
    var fid = $(this).attr('id').split('-').pop() || $(this).closest('a[data-fid]').data('fid');

    var closeCropFocusForm = function() {
      $('#imagefield-focus-crop-focus-media-form').slideUp(function(){
        that.closest('#scrollbox').animate({marginRight: '0'}, 250);
        $(this).remove();
      });
    }

    // Display the crop and focus form in the correct location.
    var gotFocusForm = function (data, status) {
      if (data.success) {
        // Close the focus form if it's open.
        $('#imagefield-focus-crop-focus-media-form').remove();

        // Add the html for the form and adjust some styles.
        var scrollbox = that.closest('#scrollbox');
        that.closest('#container').css('position', 'relative');
        scrollbox.after(data.markup).css({marginRight: '45%'});
        $('#imagefield-focus-crop-focus-media-form').height(scrollbox.innerHeight()).slideDown();

        // Setup the close button.
        $('#imagefield-focus-crop-focus-media-form .close-button').click(closeCropFocusForm);

        // Whenever the crop or focus data changes, save the change. This is a
        // more streamlined workflow when working within the media module.
        $('#imagefield-focus-crop-focus-media-form .focus-box > img').bind('change.focus-box', function() {
          var cropRect = $(this).closest('form').find('input[name="crop_rect"]');
          var focusRect = $(this).closest('form').find('input[name="focus_rect"]');
          var postData = {
            'crop_rect' : cropRect.hasClass('active') ? selToVal($(this).imgfocus('selection')) : cropRect.val(),
            'focus_rect' : focusRect.hasClass('active') ? selToVal($(this).imgfocus('selection')) : focusRect.val()
          };

          $.ajax({
            url: '/imagefield_focus/file/' + fid + '/save',
            data: postData,
            type: 'POST',
            error: function() { alert(Drupal.t('The focus and crop settings could not be saved.')); }
          });
        });
      }
      else {
        closeCropFocusForm();
      }

      // Make sure all imagefield_focus behaviors have been instantiated. We
      // cannot use Drupal.attachBehaviors() because the media module will
      // incorrectly re-add buttons. @see media.js ~line 64
      Drupal.behaviors.imagefield_focus.attach();
    };

    // Display an error if the crop and focus form could not be loaded.
    var errorCallback = function () {
      alert(Drupal.t('Error loading the image focus form.'));
    };

    $.ajax({
      url: '/imagefield_focus/file/' + fid + '/media', //imagefield_focus/form/%fid/%key
      type: 'GET',
      error: errorCallback,
      success: gotFocusForm
    });
  }

}(jQuery));
