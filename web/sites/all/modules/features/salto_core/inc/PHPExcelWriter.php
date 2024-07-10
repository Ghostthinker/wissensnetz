<?php


class PHPExcelWriter {

  var $typeRead;
  var $typeWrite;
  var $filePath;
  var $format;
  var $title;

  public function __construct($filePath, $format, $title = 'export') {
    $this->loadLibraries();

    $this->filePath = $filePath;
    $this->format = $format;
    $this->title = $title;
  }

  private function loadLibraries() {
    libraries_load('PHPExcel');
    libraries_load('PHPExcel_IOFactory');
  }

  /**
   * @param $loadFilePath
   * @param $writeFilePath
   * @throws PHPExcel_Reader_Exception
   * @throws PHPExcel_Writer_Exception
   */
  public function convertFromCSV($loadFilePath, $writeFilePath) {

    $objReader = PHPExcel_IOFactory::createReader('CSV');
    $objPHPExcel = $objReader->load($loadFilePath);
    $objWriter = self::create($objPHPExcel, $this->format);
    $objWriter->save($writeFilePath);
  }

  /**
   * @param $inputFiles
   * @param $outputFilePath
   * @throws PHPExcel_Reader_Exception
   * @throws PHPExcel_Writer_Exception
   */
  public function mergeFilesInSheets($inputFiles, $outputFilePath) {

    $objReader = PHPExcel_IOFactory::createReader('CSV');
    $inputFileName = array_shift($inputFiles);
    $objPHPExcel = $objReader->load($inputFileName);

    foreach($inputFiles as $sheet => $inputFileName) {
      $objReader->setSheetIndex($sheet+1);
      $objReader->loadIntoExisting($inputFileName, $objPHPExcel);
    }

    $objWriter = self::create($objPHPExcel, $this->format);
    $objWriter->save($outputFilePath);
  }

  static function create($excel, $format = "xlsx") {
    libraries_load('PHPExcel');
    libraries_load('PHPExcel_IOFactory');

    $format = strtolower($format);
    switch ($format) {
      case 'xlsx':
        $writer = new PHPExcel_Writer_Excel2007($excel);
        break;
      case 'csv':
        $writer = new PHPExcel_Writer_CSV($excel);
        break;
      case 'ods':
        $writer = new PHPExcel_Writer_OpenDocument($excel);
        break;
      default:
        $writer = new PHPExcel_Writer_Excel5($excel);
    }
    return $writer;
  }

  /**
   * Write data into an exists excel table
   * @param $data
   * @param $headers
   * @throws PHPExcel_Exception
   * @throws PHPExcel_Reader_Exception
   */
  function writeAppend($data, $headers) {

    global $user;
    $username = format_username($user);

    libraries_load('PHPExcel');
    // Initiate cache
    $cacheMethod = PHPExcel_CachedObjectStorageFactory::cache_to_phpTemp;
    $cacheSettings = array('memoryCacheSize' => '1000M');
    PHPExcel_Settings::setCacheStorageMethod($cacheMethod, $cacheSettings);

    // set up excel workbook
    $excel = PHPExcel_IOFactory::load($this->filePath);
    $excel->getProperties()
      ->setCreator($username)
      ->setLastModifiedBy($username)
      ->setTitle($this->title)
      ->setSubject($this->title)
      ->setDescription($this->title);
    $sheet = $excel->setActiveSheetIndex(0);
    $sheet->getDefaultRowDimension()->setRowHeight(-1);
    $row = $sheet->getHighestRow()+1;
    $sheet->fromArray($data, NULL, 'A' . $row);


    //get index of postal field, need to force displaying leading zeroes
    $upper_alphabet = range('A', 'Z');
    $postal_column_index = array_search("postal",array_keys($headers));
    $phone_column_index = array_search("phone",array_keys($headers));
    foreach($data as $key=>$value) {
      //only if key was found!!
      if($postal_column_index !== FALSE) {
        $sheet->setCellValueExplicit($upper_alphabet[$postal_column_index] . $row, $value['dosb_license_postal'], PHPExcel_Cell_DataType::TYPE_STRING);
      }
      //only if key was found!!
      if($phone_column_index !== FALSE) {
        $sheet->setCellValueExplicit($upper_alphabet[$phone_column_index] . $row, $value['dosb_license_phone'], PHPExcel_Cell_DataType::TYPE_STRING);
      }
      $row++;
    }

    $objWriter = self::create($excel, $this->format);
    $objWriter->save($this->filePath);
  }

  static function writeNativeCSV($filepath, $data, $mode = 'a') {
    libraries_load('PHPExcel');
    libraries_load('PHPExcel_IOFactory');

    if(!file_exists($filepath)) { return false; }
    $csvFile = fopen($filepath, $mode);

    foreach($data as $row){
      fputcsv($csvFile, $row);
    }
    return true;
  }

  /**
   * Write data into an excel table with style options
   * Examples:
   *  $headers['style'] = array('color' => RGB_COLOR_EXPORT_HEADER, 'startCell' => 'A1', 'endCell' => 'D1');
   *  $result[$dv] = array($dv, array('color' => RGB_COLOR_EXPORT_VERBAENDE_HEADLINE, 'startColumn' => 'A', 'endColumn' => 'D', 'fontSize' => 14));
   *
   * @param        $data
   * @param        $headers
   * @param array  $file
   * @param string $title
   *
   * @throws PHPExcel_Exception
   * @throws PHPExcel_Writer_Exception
   * @internal param $path
   * @internal param $filename
   * @internal param string $format
   */
  static function writeStyle($data, $headers, $file = [], $title = "export") {
    libraries_load('PHPExcel');
    libraries_load('PHPExcel_IOFactory');

    global $user;
    $username = format_username($user);

    array_unshift($data, $headers);

    // Initiate cache
    $cacheMethod = PHPExcel_CachedObjectStorageFactory::cache_to_phpTemp;
    $cacheSettings = array('memoryCacheSize' => '1000M');
    PHPExcel_Settings::setCacheStorageMethod($cacheMethod, $cacheSettings);

    // set up excel workbook
    $excel = new PHPExcel();
    $excel->getProperties()
      ->setCreator($username)
      ->setLastModifiedBy($username)
      ->setTitle($title)
      ->setSubject($title)
      ->setDescription($title);
    $excel->createSheet(0);
    $excel->setActiveSheetIndex(0);
    $excel->getActiveSheet()->fromArray($data);

    $sheet = $excel->getActiveSheet();

    if ($headers['style']) {
      $cells = $headers['style']['startCell'] . ':' . $headers['style']['endCell'];
      $sheet->getStyle($cells)
        ->getFill()
        ->setFillType(PHPExcel_Style_Fill::FILL_SOLID)
        ->getStartColor()
        ->setRGB($headers['style']['color']);

      $sheet->getStyle($cells)->getAlignment()
        ->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_LEFT)
        ->setVertical(PHPExcel_Style_Alignment::VERTICAL_TOP);

      if ($headers['style']['font']['color']) {
        $font = $headers['style']['font'];
        if ($font['color']) {
          $sheet->getStyle($cells)->getFont()->getColor()->setRGB($font['color']);
        }
        if ($font['bold']) {
          $sheet->getStyle($cells)->getFont()->setBold($font['bold']);
        }
      }

      foreach ($headers['style']['columns'] as $column => $width) {
        $sheet->getColumnDimension($column)->setWidth($width);
      }
      foreach ($headers['style']['rows'] as $row => $height) {
        $sheet->getRowDimension($row)->setRowHeight($height);
      }
    }

    $row = 1;
    foreach($data as $key=>$value) {
      if($row == 1){
        //ignore header values
        $row++;
        continue;
      }
      foreach ($value as $idx => $style) {
        if (strlen($style['color']) == 6) {
          $cells = $style['startColumn'] . $row . ':' . $style['endColumn'] . $row;
          $sheet->getStyle($cells)
            ->getFill()
            ->setFillType(PHPExcel_Style_Fill::FILL_SOLID)
            ->getStartColor()
            ->setRGB($style['color']);
        }
        if (!empty($style['fontSize'])) {
          $cells = $style['startColumn'] . $row;
          $sheet->getStyle($cells)->getFont()->setSize($style['fontSize']);
          $sheet->getRowDimension($row)->setRowHeight($style['fontSize'] + 5);
        }
      }
      $row++;
    }
    self::writerOnDemand($excel, $file['filename'], $file['format']);
  }

  /**
   * @param        $excel
   * @param        $filename
   * @param string $format
   *
   * @throws PHPExcel_Writer_Exception
   */
  static function writerOnDemand($excel, $filename, $format = "xlsx") {
    libraries_load('PHPExcel');
    libraries_load('PHPExcel_IOFactory');
    $writer = self::create($excel, $format);

    $filename = str_replace(array('ä'), array('ae'), $filename);

    header("Pragma: public");
    header("Expires: 0");
    header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
    header("Content-Type: application/force-download");
    header("Content-Type: application/octet-stream");
    header("Content-Type: application/download");;
    header("Content-Disposition: attachment;filename=\"$filename\"");
    header("Content-Transfer-Encoding: binary ");

    $writer->save('php://output');
  }

}
