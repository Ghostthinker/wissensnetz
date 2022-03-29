/*
  Custom configuration for ckeditor.

  Configuration options can be set here. Any settings described here will be
  overridden by settings defined in the $settings variable of the hook. To
  override those settings, do it directly in the hook itself to $settings.
*/
CKEDITOR.editorConfig = function( config )
{

  //media tags getting broken by ckeditor
  //adapting configuration to fix this issue
  config.forcePasteAsPlainText = false
  config.entities = true;
  config.allowedContent = true
  config.entities_latin = false;
  config.entities_greek = false;
  config.entities_processNumerical = false;
  config.extraPlugins = 'stylesheetparser,media_widget,image2';
  config.removePlugins = 'forms,image';

  config.fillEmptyBlocks = function (element) {
    return true;
  };

}
