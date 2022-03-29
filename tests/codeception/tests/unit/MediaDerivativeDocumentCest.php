<?php

class MediaDerivativeDocumentCest {

  public function _before(UnitTester $I) {  }

  public function _after(UnitTester $I) { }

  /**
   * @skip fail converting
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
    $derivative->preset->engine_settings['document_extension'] = 'jpg';
    $derivative->preset->engine_settings['document_output'] = 'private://media_converted_document_test';

    $new_file = media_derivatives_document_media_derivatives_create_derivative($file, $derivative);

    $I->assertGreaterThanOrEqual(36500, filesize($new_file));

    $I->expect('Test broken file path');
    $file_path = realpath(drupal_get_path('module', 'media_derivatives_document') . '/samples/convertdoc/sampl.pdf');
    $file2 = new \stdClass();
    $file2->filename = 'sampl.pdf';
    $file2->uri = $file_path;

    try {
      $new_file = media_derivatives_document_media_derivatives_create_derivative($file2, $derivative);
    } catch (MediaDerivativesException $ex) {
      $I->assertEquals($ex->getMessage(), "Unable to find document", "Path is not correct");
    }

    $I->expect('Test broken license file sample');
    $file_path = realpath(drupal_get_path('module', 'media_derivatives_document') . '/samples/convertdoc/GT-JL--0000025-DINA4.pdf');
    $file3 = new \stdClass();
    $file3->filename = 'gt-license-sample.pdf';
    $file3->uri = $file_path;

    try {
      $new_file = media_derivatives_document_media_derivatives_create_derivative($file3, $derivative);
    } catch (MediaDerivativesException $ex) {
      $I->assertEquals($ex->getMessage(), t("File was successfully uploaded, unfortunately the preview image could not be generated from the source file."), "Image is not converted");
    }

  }
}
