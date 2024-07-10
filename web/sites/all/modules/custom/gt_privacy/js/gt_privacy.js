Drupal.behaviors.gt_privacy = {
  attach: function (context, settings) {

    jQuery('.cookie-accept:not(.cookie-accept-processed)').click(function () {
      days = 182; //number of days to keep the cookie
      myDate = new Date();
      myDate.setTime(myDate.getTime() + (days * 24 * 60 * 60 * 1000));
      document.cookie = "comply_cookie = comply_yes; expires = " + myDate.toGMTString();
      jQuery("#cookies").slideUp("slow");
    }).addClass("cookie-accept-processed");

    jQuery('a[href="/cookies-tracking"]').on("click", function(event) {
      event.preventDefault();
      klaro.show();
    });
  }



};
