

///////////////////////////////////////////////////////////////
//      CKEDITOR_mentions helper class
///////////////////////////////////////////////////////////////

/*
 * Helper class needed to handle mentions.
 * This class is a singleton for each instance of CKEDITOR.
 *
 * @param {Object} editor An instance of a CKEDITOR
 * @returns {null}
 */
function CKEDITOR_mentions (editor) {
  this.editor = editor;
  this.observe = 0;
  this.char_input = [];
  this.timeout_id = null;

  if (CKEDITOR_mentions.caller !== CKEDITOR_mentions.get_instance) {
    throw new Error("This object cannot be instanciated");
  }
}

/*
 * Collection of pairs editor id / instance of CKEDITOR_mentions
 *
 * @type Array
 */
CKEDITOR_mentions.instances = [];

/*
 * Delay of the timeout between the last key pressed and the ajax query. It's use to prevent ajax flooding when user types fast.
 *
 * @type Number
 */

CKEDITOR_mentions.timeout_delay = 500;

/*
 * Minimum number of characters needed to start searching for users (includes the @).
 *
 * @type Number
 */

CKEDITOR_mentions.start_observe_count = 3;

/*
 * Method used to get an instance of CKEDITOR_mentions linked to an instance of CKEDITOR.
 * Its design is based on the singleton design pattern.
 *
 * @param {Object} editor An instance of a CKEDITOR
 * @returns An instance of CKEDITOR_mentions
 */
CKEDITOR_mentions.get_instance = function (editor) {
  // we browse our collection of instances
  for (var i in this.instances) {
    // if we find an CKEDITOR instance in our collection
    if (this.instances[i].id === editor.id) {
      // we return the instance of CKEDITOR_mentions that match
      return this.instances[i].instance;
    }
  }

  // if no match was found, we add a row in our collection with the current CKEDITOR id and we instanciate CKEDITOR_mentions
  this.instances.push({
    id: editor.id,
    instance: new CKEDITOR_mentions(editor)
  });
  // we return the instance of CKEDITOR_mentions that was just created
  return this.instances[this.instances.length - 1].instance;
};

/*
 * This method delete the div containing the suggestions
 *
 * @returns {null}
 */
CKEDITOR_mentions.prototype.delete_tooltip = function () {
  jQuery('.mention-suggestions').remove();
};

/*
 * This method start the observation of the typed characters
 *
 * @returns {null}
 */
CKEDITOR_mentions.prototype.start_observing = function () {
  this.observe = 1;
};

/*
 * This method halts the observation of the typed characters and flush the properties used by CKEDITOR_mentions
 *
 * @returns {null}
 */
CKEDITOR_mentions.prototype.stop_observing = function () {
  this.observe = 0;
  this.char_input = [];
  this.delete_tooltip();
};

/*
 * This methods send an ajax query to durpal ckeditor_mentions module and retrieve matching user.
 *
 * @param {Object} selection result of CKEDITOR.editor.getSelection()
 * @returns {null}
 */
CKEDITOR_mentions.prototype.get_people = function (selection) {
  if (null !== this.timeout_id) {
    clearTimeout(this.timeout_id);
  }
  this.timeout_id = setTimeout(this.timeout_callback, CKEDITOR_mentions.timeout_delay, [this, selection]);
}

CKEDITOR_mentions.set_suggestions_to_cursor_position = function (editor, suggestions){
  var dummyElement = editor.document.createElement( 'img',
    {
      attributes :
        {
          src : 'null',
          width : 0,
          height : 0
        }
    });

  editor.insertElement( dummyElement );

  var x = 0;
  var y  = 0;

  var obj = dummyElement.$;

  while (obj.offsetParent){
    x += obj.offsetLeft;
    y  += obj.offsetTop;
    obj    = obj.offsetParent;
  }
  x += obj.offsetLeft;
  y  += obj.offsetTop;

  dummyElement.remove();

  var newtop = 70 + y;
  var newleft = 5 + x;
  suggestions.css('top', newtop +'px');
  suggestions.css('left', newleft + 'px' );


};

/*
* This methods send an ajax query to durpal ckeditor_mentions module and retrieve matching user.
*
* @param {Array} args An Array of parameters containing the current instance of CKEDITOR_mentions and selection (cf. CKEDITOR_mentions.prototype.get_people)
* @returns {null}
*/
CKEDITOR_mentions.prototype.timeout_callback = function (args) {
  var mentions   = args[0];
  var selection  = args[1];
  var str        = mentions.char_input.join('');

  //if less than 3 char are input (including @) we don't try to get people
  if (str.length < CKEDITOR_mentions.start_observe_count) {
    mentions.delete_tooltip();
    return;
  }

  var $ = jQuery;

  var editor       = mentions.editor;
  var element_id   = editor.element.getId();
  var range        = selection.getRanges()[0];
  var startOffset  = parseInt(range.startOffset - str.length) || 0;
  var element      = range.startContainer.$;

  $.get(Drupal.settings.basePath + 'saltockeditor/mentions', {typed: str}, function(rsp) {

    var ckel = $('#' + element_id);
    var par = ckel.parent();

    $('.mention-suggestions').remove();

    if (rsp) {
      var suggestions = '';
      $.each(rsp, function() {
        suggestions += '<li class="textcomplete-item" data-index="0">' + this + '</li>' ;
      });

      $('<ul class="mention-suggestions dropdown-menu">' + suggestions + '</ul>').insertBefore(par);
      $('.textcomplete-item').eq(0).addClass('active');


      CKEDITOR_mentions.set_suggestions_to_cursor_position(editor, $('.mention-suggestions'));

      editor.on("key", function (event) {
        if($('.mention-suggestions').is(":visible") == false){
          return true;
        }
        if (event.data.keyCode === 38){
          if ($('.textcomplete-item.active').prev().hasClass('textcomplete-item')) {
            $('.textcomplete-item.active').removeClass('active').prev().addClass('active');
          }
          return false;
        }
        else if (event.data.keyCode === 40){
          if ($('.textcomplete-item.active').next().hasClass('textcomplete-item')){
            $('.textcomplete-item.active').removeClass('active').next().addClass('active');
          }
          return false;
        }
        else if(event.data.keyCode == 13){
          $('.textcomplete-item.active .mentions-autocomplete-list').click();
          return false;
        }

        CKEDITOR_mentions.set_suggestions_to_cursor_position(editor, $('.mention-suggestions'));
      } );
    }

    $('.mentions-autocomplete-list').click(function(e) {
      e.preventDefault();

      var mentions = CKEDITOR_mentions.get_instance(editor);
      mentions.stop_observing();

      // Keep the text originally inserted after the new tag.
      var after_text = element.textContent.substr(startOffset + str.length);

      // Shorten text node
      element.textContent = element.textContent.substr(0, startOffset);

      // Create link
      var link = document.createElement('a');
      link.href = Drupal.settings.basePath + 'user/' + $(this).data('uid');
      link.textContent = '@' + $(this).data('realname') + '[' + $(this).data('uid') + ']';

      // Insert link after text node
      // this is used when the link is inserted not at the end of the text
      if ( element.nextSibling ) {
        element.parentNode.insertBefore(link, element.nextSibling);
      }
      // at the end of the editor text
      else {
        element.parentNode.appendChild(link);
      }

      // Add the text which was present after the tag.
      if ($.trim(after_text).length) {
        element.parentNode.appendChild(document.createTextNode(after_text));
      }

      if ( $.browser.msie ) {
        // so basically, due to some weird behaviour by ckeditor IE triggers an error on focus,
        // which in turn causes any additonal mentions to be inserted wrong.
        // By turning this off, IE users will have to click manually on the editor to get back.
        // https://drupal.org/node/2033739
      } else {
        editor.focus();
        var range = editor.createRange(),
          el = new CKEDITOR.dom.element(link.parentNode);
        range.moveToElementEditablePosition(el, link.parentNode.textContent.length);
        range.select();
      }

    });
  });

};

/*
 * This method returns if a char should stop the observation.
 *
 * @param {int} charcode A character key code
 * @returns {Boolean} Whether or not the char should stop the observation
 */
CKEDITOR_mentions.prototype.break_on = function (charcode) {
  // 13 = enter
  // 37 = left key
  // 38 = up key
  // 39 = right key
  // 40 = down key
  // 46 = delete
  // 91 = home/end (?)
  //var special = [13, 37, 38, 39, 40, 46, 91];
  var special = [37, 39, 46, 91];
  for (var i = 0; i < special.length; i++) {
    if (special[i] == charcode) {
      return true;
    }
  }
  return false;
};


///////////////////////////////////////////////////////////////
//      Plugin implementation
///////////////////////////////////////////////////////////////
(function($){
  CKEDITOR.plugins.add('ckeditor_mentions', {
    icons: '',
    init: function(editor) {
      var mentions = CKEDITOR_mentions.get_instance(editor);

      /* The only way (it seems) to get a reliable, cross-browser and platform return for which key was pressed,
       * is using the jquery which function onkeypress. On keydown or up returns different values!
       * see also: http://jsfiddle.net/SpYk3/NePCm/
       */
      editor.on('contentDom', function(e) {
        var editable = editor.editable();

        /* we need the keyup listener to detect things like backspace,
         * which does not register on keypress... javascript is weird...
         */
        editable.attachListener(editable, 'keyup', function(evt) {
          if (evt.data.$.which === 8) { // 8 == backspace
            mentions.char_input.pop();
            var selection = this.editor.getSelection();
            mentions.get_people(selection);
          }

          // things which should trigger a stop observing, like Enter, home, etc.
          if (mentions.break_on(evt.data.$.which)) {
            mentions.stop_observing();
          }

        });

        editable.attachListener(editable, 'keypress', function(evt) {
          // btw: keyIdentifier is webkit only.

          var typed_char = String.fromCharCode(evt.data.$.which);

          if (typed_char === '@' || mentions.observe === 1) {
            mentions.start_observing();
            /* Things which should trigger "stop observing":
             * if at this point no result and still a unicode, return false
             * OR detect another @ while we are already observing
             * OR the length is longer than 11
             */
            if ((mentions.char_input.length > 0 && typed_char === '@') || mentions.char_input.length > 11) {
              mentions.stop_observing();
            } else {
              mentions.char_input.push(typed_char);
              var selection = this.editor.getSelection();
              mentions.get_people(selection);
            }
          }
        });
      }); // end editor.on
    } // end init function
  });
})(jQuery);

