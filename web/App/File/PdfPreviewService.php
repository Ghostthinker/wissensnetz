<?php

namespace Wissensnetz\File;

use TheCodingMachine\Gotenberg\Client;
use TheCodingMachine\Gotenberg\DocumentFactory;
use TheCodingMachine\Gotenberg\OfficeRequest;

class PdfPreviewService {


  public function __construct() {
    $document_preview_settings = media_derivatives_service_get_document_preview_settings();

    $this->convert_endpoint_gotenberg = $document_preview_settings['gotenberg_url'];
    $this->convert_endpoint_pdf2image = $document_preview_settings['pdf_to_image_url'];
  }

  public function healthCheckGotenberg(){
    $convertUrl = $this->convert_endpoint_gotenberg;
    // Create a Guzzle client with a 2-second timeout
    $client = new \GuzzleHttp\Client([
      'timeout' => 2, // Set timeout to 2 seconds
    ]);
    try {
      // Make a GET request to /ping
      $response = $client->request('GET', $convertUrl . '/ping');

      // Check if the response is successful (status code 200)
      if ($response->getStatusCode() === 200) {
        // Return true if the response is successful
        return true;
      } else {
        // Return false if the response is not successful
        return false;
      }
    } catch (\Exception $e) {
      // An error occurred, return false
      return false;
    }
  }
  public function healthCheckPdfToImage(){
    $serviceUrl = $this->convert_endpoint_pdf2image;
    // Create a Guzzle client with a 2-second timeout
    $client = new \GuzzleHttp\Client([
      'timeout' => 2, // Set timeout to 2 seconds
    ]);
    try {
      // Make a GET request to /ping
      $response = $client->request('GET', $serviceUrl . '/status');

      // Check if the response is successful (status code 200)
      if ($response->getStatusCode() === 200) {
        // Return true if the response is successful
        return true;
      } else {
        // Return false if the response is not successful
        return false;
      }
    } catch (\Exception $e) {
      // An error occurred, return false
      return false;
    }
  }


  public function convertDocument2Pdf($filePathInput, $filePathOutput) {

    $convertUrl = $this->convert_endpoint_gotenberg;

    $client = new Client($convertUrl, new \Http\Adapter\Guzzle7\Client());

    $filePathInput = drupal_realpath($filePathInput);

    $fileInfo = pathinfo($filePathInput);
    $files = [
      DocumentFactory::makeFromPath($fileInfo['basename'], $filePathInput),
    ];
    $request = new OfficeRequest($files);
    $request->setWaitTimeout(30.0);

    try {
      $client->store($request, drupal_realpath($filePathOutput));
      return $filePathOutput;
    } catch (\Exception $e) {

      watchdog_exception("pdf preview", $e);
      return FALSE;
    }
  }

  public function convertPdf2Image($pdfFilePath, $jpegOutputPath){

    $client = new \GuzzleHttp\Client();
    $pdfFilePath = drupal_realpath($pdfFilePath);

    $pdfFileName = basename($pdfFilePath);

    $serviceUrl = $this->convert_endpoint_pdf2image  . '/convert-pdf';

    try {
      // Open file handle

      $contents = file_get_contents($pdfFilePath);

      $response = $client->request('POST', $serviceUrl, [
        'multipart' => [
          [
            'name'     => 'file',
            'filename' => $pdfFileName,
            'contents' => $contents
          ]
        ]
      ]);



      // Save the received JPEG image
      $jpegContent = $response->getBody()->getContents();

      file_put_contents(drupal_realpath($jpegOutputPath), $jpegContent);
      return $jpegOutputPath;
    } catch (RequestException $e) {
    }
  }

}
