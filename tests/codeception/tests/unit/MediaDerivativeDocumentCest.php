<?php

class MediaDerivativeDocumentCest {

  public function _before(UnitTester $I) {  }

  public function _after(UnitTester $I) { }

  /**

   *
   * 270.11 #CR Datei Icons
   * @param UnitTester $I
   * @throws MediaDerivativesException
   */
  public function testCreateDerivative(UnitTester $I) {
    $I->wantTo("270.11 #CR Datei Icons");

    $I->expect('Test sample file has min. of size (bytes)');
    $file_path = realpath(drupal_get_path('module', 'media_derivatives_document') . '/samples/convertdoc/sample.pdf');
    $file = new \stdClass();
    $file->filename = 'sample.pdf';
    $file->uri = $file_path;

    $derivative = new \stdClass();
    $derivative->preset = new \stdClass();
    $derivative->preset->machine_name = 'document';

    $new_file = media_derivatives_document_media_derivatives_create_derivative($file, $derivative);

    $I->assertGreaterThanOrEqual(36500, filesize($new_file));

    $I->wantTo("270.11 #CR Datei Icons");

    $I->expect('Test sample file has min. of size (bytes)');
    $file_path = \Helper\Wissensnetz::getSampleFilePath('documents/sample.docx');
    $file = new \stdClass();
    $file->filename = 'sample.pdf';
    $file->uri = $file_path;

    $derivative = new \stdClass();
    $derivative->preset = new \stdClass();
    $derivative->preset->machine_name = 'document';

    $new_file = media_derivatives_document_media_derivatives_create_derivative($file, $derivative);

    $I->assertGreaterThanOrEqual(36500, filesize($new_file));
  }
}
