(function($) {

  /**
   * Attaches the Plupload behavior to each Plupload form element.
   */
  Drupal.behaviors.salto_files_wysiwyg = {
    attach: function(context, settings){

      //console.log(CKEDITOR.instances);
      //CKEDITOR Modifications


      for (var i in CKEDITOR.instances) {
        CKEDITOR.instances[i].on('change', function(e,c) {
        	var m = $(this).find(".media-element");
        	m.toggle();
        	var ed = e.editor;
        	//console.log(ed.getData());
        });
    }

      // wait until the editor has done initializing
      CKEDITOR.on("instanceReady",function(event) {
        // insert code to run after editor is ready
        var editor = event.editor;



        CKEDITOR.plugins.addExternal( 'simplebox', 'https://steff.bn.ghostthinker.de/sites/all/libraries/ckeditor/plugins/media_widget', 'plugin.js' );

/*
        console.log(editor.id);
        editor.on('change', function(ee) {
        	console.log(ee.editor.container.$);


        	ee.editor.container.$('.media-element').on("click",function(event) {
        		$(this).append("sss");
        		console.log("test");
        	});
        });


        CKEDITOR.replace( editor.id, {
			extraPlugins: 'media_widget'
		} );*/

        if(editor.getData() === '') {
            editor.setData('<p> </p>', function(){
              editor.updateElement();
              editor.resetDirty();
            });

            //reset dirty state on init
            //console.log(editor.checkDirty());
        }

        $('#'+editor.name).once('salto-files', function(){




          //$('iframe.cke_wysiwyg_frame').webkitimageresize().webkittableresize().webkittdresize();
          $('iframe.cke_wysiwyg_frame').webkittableresize().webkittdresize();

          //remove image property item
          //editor.removeMenuItem
          if ( editor.contextMenu )
          {

            //console.log("rest");
            //console.log()
            //context menu group
            editor.addMenuGroup( 'salto_media' );

            //context menu items
            //Media Browser Item
            var icon = Drupal.settings.basePath + "sites/all/modules/features/salto_files/wysiwyg/icons/wysiwyg-media.gif";
            salto_files_editor_add_contextmenu_item(editor, icon, Drupal.t('Media'), 'mediaBrowser', function(){
              //call media browser

              //CKEDITOR.tools.callFunction(52, this);
              $('a.cke_button__media').click();
            //$().attr("onclick")
            });

            salto_files_editor_add_contextmenu_item(editor, icon, Drupal.t('Video Properties'), 'mediaBrowser2', function(){
              //call media browser

              //CKEDITOR.tools.callFunction(52, this);
              $('a.cke_button__media').click();
            //$().attr("onclick")
            });


            //Align left
            icon = Drupal.settings.basePath + "sites/all/modules/features/salto_files/wysiwyg/icons/left.gif";
            salto_files_editor_add_contextmenu_item(editor, icon, Drupal.t('Align left'), 'alignLeft', function(){
              //call media browser
              //console.log('align left');

              var element = _salto_getSelectedImage(editor);
              if ( element ) {
                element.setStyle( 'float', 'left' );
                element.setStyle( 'margin', '0px 10px 10px 0' );
              }

            //console.log(element);
            //console.log(_salto_getImageAlignment(element));
            });

            //Align right
            icon = Drupal.settings.basePath + "sites/all/modules/features/salto_files/wysiwyg/icons/right.gif";
            salto_files_editor_add_contextmenu_item(editor, icon, Drupal.t('Align right'), 'alignRight', function(){
              //call media browser
              //console.log('align right');
              var element = _salto_getSelectedImage(editor);
              if ( element ) {
                element.setStyle( 'float', 'right' );
                element.setStyle( 'margin', '0px 0px 10px 10px' );
              }
            });

            //Edit Margin
            icon = Drupal.settings.basePath + "sites/all/modules/features/salto_files/wysiwyg/icons/remove-margin.gif";
            salto_files_editor_add_contextmenu_item(editor, icon, Drupal.t('Remove padding'), 'removeMargin', function(){
              //call media browser
              //onsole.log('remove Margin!');

              var element = _salto_getSelectedImage(editor);
              if ( element ) {
                element.setStyle( 'margin', '0' );
              }

            });


            //Remove Position and margin
            icon = Drupal.settings.basePath + "sites/all/modules/features/salto_files/wysiwyg/icons/remove-style.gif";
            salto_files_editor_add_contextmenu_item(editor, icon, Drupal.t('Clear formatting'), 'clearPositionAndMargin', function(){
              //call media browser
              //console.log('remove styles!');

              var element = _salto_getSelectedImage(editor);
              if ( element ) {
                element.removeStyle( 'margin');
                element.removeStyle( 'float');
              }

            });

                 //Align left
            icon = Drupal.settings.basePath + "sites/all/modules/features/salto_files/wysiwyg/icons/left.gif";
            salto_files_editor_add_contextmenu_item(editor, icon, Drupal.t(' Set Size: Small'), 'sizeSmall', function(){
              //call media browser
              //console.log('align left');

              var element = _salto_getSelectedImage(editor);
              if ( element ) {
                element.setStyle( 'width', '120px' );
                element.setStyle( 'height', 'auto' );
              }
         	});
         	    icon = Drupal.settings.basePath + "sites/all/modules/features/salto_files/wysiwyg/icons/left.gif";
            salto_files_editor_add_contextmenu_item(editor, icon, Drupal.t(' Set Size: Medium'), 'sizeMedium', function(){
              //call media browser
              //console.log('align left');

              var element = _salto_getSelectedImage(editor);
              if ( element ) {
                element.setStyle( 'width', '240px' );
                element.setStyle( 'height', 'auto' );
              }
         	});

         	    icon = Drupal.settings.basePath + "sites/all/modules/features/salto_files/wysiwyg/icons/left.gif";
            salto_files_editor_add_contextmenu_item(editor, icon, Drupal.t(' Set Size: Large'), 'sizeLarge', function(){
              //call media browser
              //console.log('align left');

              var element = _salto_getSelectedImage(editor);
              if ( element ) {
                element.setStyle( 'width', '380px' );
                element.setStyle( 'height', 'auto' );
              }
         	});
          }


        /*
        console.log($('iframe').contents().find('img'));
        var media_images = $('iframe').contents().find('img');
        $.each(media_images, function(i,l){
          //check, if embedded img is a media-element
          if($(l).hasClass('media-element')){
            //console.log('appending');
            var img_tools = $('body').prepend('<div class="salto-files-media-toolbar" style="position:absolute;">img tools</div>');
            console.log($('iframe').offset());
            img_tools.offset($('iframe').offset()+$(l).offset());
          }
        });
         */
        });


      });
    }

  }
  function salto_files_editor_add_contextmenu_item(_editor, _icon, _lbl, _cmd, _callback){
    _editor.addCommand(_cmd, {
      exec : function( _editor )
      {
        _callback();
      }
    });

    /*
    var newCommand = {
      label : _lbl,
      command : _cmd,
      group : 'salto'
    };
    */

    _editor.contextMenu.addListener( function( element, selection ) {

      if ( _salto_getSelectedImage( _editor, element ) ) {
        var obj = {};
        obj[_cmd] = CKEDITOR.TRISTATE_OFF
        //console.log(obj);
        return obj;
      }
    });

    var obj2 = {};
    obj2[_cmd] = {
      label : _lbl,
      icon : _icon,
      command : _cmd,
      group : 'salto_media',
      order : 1
    }
    _editor.addMenuItems(obj2);

  }


  function _salto_getSelectedImage( editor, element ) {
    if ( !element ) {
      var sel = editor.getSelection();
      element = sel.getSelectedElement();
    }

    if ( element && element.is( 'img' ) && !element.data( 'cke-realelement' ) && !element.isReadOnly() )
      return element;
  }


  function _salto_getImageAlignment( element ) {
    var align = element.getStyle( 'float' );

    if ( align == 'inherit' || align == 'none' )
      align = 0;

    if ( !align )
      align = element.getAttribute( 'align' );

    return align;
  }








})(jQuery);
