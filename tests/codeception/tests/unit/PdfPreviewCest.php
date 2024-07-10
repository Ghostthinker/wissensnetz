<?php

class PdfPreviewCest {

  public function _before(UnitTester $I) {  }

  public function _after(UnitTester $I) { }

  /**
   *
   * 270.11 #CR Datei Icons
   * @example { "file": "documents/sample.docx", "type": "document", "mime":"application/docx"}
   * example { "file": "documents/sample.pdf", "type": "document", "mime":"application/pdf" }
   * example { "file": "documents/sample.pptx", "type": "document", "mime":"application/pptx"  }
   * example { "file": "documents/sample.rtf", "type": "document", "mime":"text/rtf"  }
   * example { "file": "documents/sample.xlsx", "type": "document", "mime":"application/xlsx"  }
   * example { "file": "images/150524-19-50.jpg", "type": "image", "mime":"image/jpeg" }
   * @param UnitTester $I
   */
  public function testConvertFile(UnitTester $I, \Codeception\Example $example) {
    $I->wantTo("270.11 #CR Datei Icons");

    $filepath = \Helper\Wissensnetz::getSampleFilePath($example['file']);


    $dir = 'private://convert_test';
    file_prepare_directory($dir, FILE_CREATE_DIRECTORY);

    $filepathPdf = "test2.pdf";
    $filepathPdf = file_destination($dir."/". $filepathPdf, TRUE);




    $pdfPreviewService = new \Wissensnetz\File\PdfPreviewService();
    $new_file = $pdfPreviewService->convertDocument2Pdf($filepath, $filepathPdf);

    $new_file_path = file_stream_wrapper_get_instance_by_uri($new_file)->realpath();


    //convert to jpeg
    $pdfPreviewService->convertPdf2Image($new_file_path, $new_file_path . "jpg");



  }
}
