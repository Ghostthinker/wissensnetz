<?php


function l_primary_lg($text, $path, array $options = []) {

  $options['attributes']['class'][] = 'btn';
  $options['attributes']['class'][] = 'btn-primary';
  $options['attributes']['class'][] = 'btn-lg';
  $options['attributes']['role'] = 'button';

  return l($text, $path, $options);
}

function l_primary($text, $path, array $options = []) {

  $options['attributes']['class'][] = 'btn';
  $options['attributes']['class'][] = 'btn-primary';
  $options['attributes']['role'] = 'button';

  return l($text, $path, $options);
}


/**
 * Return an ajax callback for client error handler
 *
 * @param  [type]  $message [description]
 * @param integer $status [description]
 *
 * @return [type]           [description]
 */
function drupal_json_output_error($message, $status = 403) {
  if ($status == 403) {
    drupal_add_http_header('Status', '403 Forbidden');
  }
  return drupal_json_output(['message' => $message]);
}


function taxonomy_get_nested_tree($terms = [], $max_depth = NULL, $parent = 0, $parents_index = [], $depth = 0) {
  if (is_int($terms)) {
    $terms = taxonomy_get_tree($terms);
  }

  if (empty($terms)){
    return NULL;
  }

  foreach ($terms as $term) {
    foreach ($term->parents as $term_parent) {
      if ($term_parent == $parent) {
        $return[$term->tid] = $term;
      }
      else {
        $parents_index[$term_parent][$term->tid] = $term;
      }
    }
  }

  foreach ($return as &$term) {
    if (isset($parents_index[$term->tid]) && (is_null($max_depth) || $depth < $max_depth)) {
      $term->children = taxonomy_get_nested_tree($parents_index[$term->tid], $max_depth, $term->tid, $parents_index, $depth + 1);
    }
  }

  return $return;
}

/**
 * Make all relative urls absolute
 *
 * @param $html
 *
 * @return mixed
 */
function make_urls_absolute($html) {

  $html = preg_replace_callback(
    '~((href|src)\s*=\s*[\"\'])([^\"\']+)~i',
    'make_urls_absolute_replace',
    $html);
  return $html;
}

/**
 * sub function for absolute link generation
 *
 * @param $x
 *
 * @return string
 */
function make_urls_absolute_replace($x) {
  $url = $x[3];
  $url = url($url, ["absolute" => TRUE]);
  return $x[1] . $url;
}

/**
 * Validate a phone number. Actually means allow numbers and {space} / + an d -
 *
 * @param $phone_string
 *
 * @return mixed
 */
function valid_phone_number($phone_string) {
  return preg_match('/^([0-9\s_.+-\/]{3,})+$/', $phone_string);
}

/**
 * Helper to sort a keyed array by another array
 *
 * @param array $array
 * @param array $orderArray
 *
 * @return array
 */
function sortArrayByArray(array $array, array $orderArray) {
  $ordered = [];
  foreach ($orderArray as $key) {
    if (array_key_exists($key, $array)) {
      $ordered[$key] = $array[$key];
      unset($array[$key]);
    }
  }
  return $ordered + $array;
}

/**
 * Write data into an excel table
 *
 * @param $data
 * @param $headers
 * @param $path
 * @param $filename
 * @param string $format
 * @param string $title
 */
function phpexcel_fast_write($data, $headers, $path, $filename, $format = "xls", $title = "export") {

  global $user;

  array_unshift($data, $headers);

  $username = format_username($user);

  libraries_load('PHPExcel');

  // Initiate cache
  $cacheMethod = PHPExcel_CachedObjectStorageFactory::cache_to_phpTemp;
  $cacheSettings = ['memoryCacheSize' => '1000M'];
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

  //get index of postal field, need to force displaying leading zeroes
  $upper_alphabet = range('A', 'Z');
  $postal_column_index = array_search("postal", array_keys($headers));
  $phone_column_index = array_search("phone", array_keys($headers));
  $row = 1;
  foreach ($data as $key => $value) {
    if ($row == 1) {
      //ignore header values
      $row++;
      continue;
    }

    if ($postal_column_index !== FALSE) {
      $excel->getActiveSheet()
        ->setCellValueExplicit($upper_alphabet[$postal_column_index] . $row, $value['dosb_license_postal'], PHPExcel_Cell_DataType::TYPE_STRING);
    }

    if ($phone_column_index !== FALSE) {
      $excel->getActiveSheet()
        ->setCellValueExplicit($upper_alphabet[$phone_column_index] . $row, $value['dosb_license_phone'], PHPExcel_Cell_DataType::TYPE_STRING);
    }
    $row++;
  }

  phpexcel_writer($excel, $path, $filename, $format);
}

/**
 * Write data into an excel table with style options
 * Examples:
 *  $headers['style'] = array('color' => RGB_COLOR_EXPORT_HEADER, 'startCell'
 * => 'A1', 'endCell' => 'D1');
 *  $result[$dv] = array($dv, array('color' =>
 * RGB_COLOR_EXPORT_VERBAENDE_HEADLINE, 'startColumn' => 'A', 'endColumn' =>
 * 'D', 'fontSize' => 14));
 *
 * @param $data
 * @param $headers
 * @param array $file
 * @param string $title
 *
 * @internal param $path
 * @internal param $filename
 * @internal param string $format
 */
function phpexcel_write_style($data, $headers, $file = [], $title = "export") {

  global $user;
  $username = format_username($user);

  array_unshift($data, $headers);

  // Initiate cache
  $cacheMethod = PHPExcel_CachedObjectStorageFactory::cache_to_phpTemp;
  $cacheSettings = ['memoryCacheSize' => '1000M'];
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
    $sheet->getColumnDimension('A')->setWidth(35);
    $sheet->getColumnDimension('B')->setWidth(25);
    $sheet->getColumnDimension('C')->setWidth(25);
    $sheet->getColumnDimension('D')->setWidth(25);
    $sheet->getRowDimension(1)->setRowHeight(30);

    $sub = substr($headers['style']['endCell'], 0, 1);
    $alphabet = range('A', $sub);
    foreach ($alphabet as $char) {
      $sheet->getStyle($char . '1')
        ->getBorders()
        ->getRight()
        ->setBorderStyle(TRUE);
    }
  }

  $startColumn = NULL;
  $endColumn = NULL;
  $row = 1;
  foreach ($data as $key => $value) {
    if ($row == 1) {
      //ignore header values
      $row++;
      continue;
    }
    foreach ($value as $idx => $style) {
      if (strlen($style['color']) == 6) {
        $startColumn = $style['startColumn'];
        $endColumn = $style['endColumn'];
        $cells = $style['startColumn'] . $row . ':' . $style['endColumn'] . $row;
        $sheet->getStyle($cells)
          ->getFill()
          ->setFillType(PHPExcel_Style_Fill::FILL_SOLID)
          ->getStartColor()
          ->setRGB($style['color']);
        $sheet->getStyle($cells)->getBorders()->getTop()->setBorderStyle(TRUE);
        $sheet->getStyle($cells)
          ->getBorders()
          ->getBottom()
          ->setBorderStyle(TRUE);
      }
      if (!empty($style['fontSize'])) {
        $cells = $style['startColumn'] . $row;
        $sheet->getStyle($cells)->getFont()->setSize($style['fontSize']);
        $sheet->getRowDimension($row)->setRowHeight($style['fontSize'] + 5);
      }
    }
    $row++;
  }

  // border outer
  if ($startColumn !== NULL) {
    $cells = $startColumn . '1:' . $startColumn . $row;
    $sheet->getStyle($cells)->getBorders()->getLeft()->setBorderStyle(TRUE);

    $cells = $endColumn . '1:' . $endColumn . $row;
    $sheet->getStyle($cells)->getBorders()->getRight()->setBorderStyle(TRUE);

    $cells = $startColumn . '1:' . $endColumn . '1';
    $sheet->getStyle($cells)->getBorders()->getTop()->setBorderStyle(TRUE);

    $cells = $startColumn . $row . ':' . $endColumn . $row;
    $sheet->getStyle($cells)->getBorders()->getBottom()->setBorderStyle(TRUE);
  }

  phpexcel_writer($excel, $file['path'], $file['filename'], $file['format']);

}

/**
 * @param $excel
 * @param $path
 * @param $filename
 * @param string $format
 */
function phpexcel_writer($excel, $path, $filename, $format = "xls") {

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

  //write to file
  if ($path) {
    $writer->save($path);
    return;
  }

  $filename = str_replace(['ä'], ['ae'], $filename);

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

/**
 * @param $nid
 * @param $expires
 * @param $secret
 * @param bool $uid
 *
 * @return string
 */
function core_path_hashed($nid, $expires, $secret, $uid = FALSE) {
  $timestamp = REQUEST_TIME;
  return "/$nid/$timestamp/$expires/" . core_hmac_base64($secret, $expires, $timestamp, $uid);
}

function core_hmac_base64($pepper, $expires, $timestamp = NULL, $uid = FALSE) {
  if ($timestamp === NULL) {
    $timestamp = time();
  }
  return drupal_hmac_base64($timestamp . $expires . $uid, drupal_get_hash_salt() . $pepper);
}

function core_hmac_base64_verify($hash, $hash_expires, $pepper, $expires, $timestamp, $uid = FALSE) {
  if ($hash_expires > $expires) {
    return FALSE;
  }

  $gen = core_hmac_base64($pepper, $expires, $timestamp, $uid);
  if ($gen == $hash) {
    return TRUE;
  }
  return FALSE;
}

/**
 * default cipher is blowfish with cbc
 *
 * recommend are block cipher with cbc
 * also ctr or ofb
 * but for the modes is the fix iv (SALTO_INVITE_IV)
 * a security issue => need random
 * e.q.
 *  $ivlen = openssl_cipher_iv_length($cipher_method);
 *  $iv = openssl_random_pseudo_bytes($ivlen);
 *  or
 *  $iv = random_bytes($ivlen);
 *
 * $iv + $key must save for decrypt
 *
 * gcm, ecb (not safe) mode is not supported, not yet
 *
 * @param        $data
 * @param        $key
 * @param string $cipher
 *
 * @return false|string
 */
function core_encrypt_openssl($data, $key, $cipher = 'bf-cbc') {
  if (!in_array($cipher, openssl_get_cipher_methods())) {
    $cipher = 'bf-cbc';
  }

  $ivlen = openssl_cipher_iv_length($cipher);
  $iv = substr(SALTO_INVITE_IV, 0, $ivlen);
  return openssl_encrypt($data, $cipher, $key, $options = 0, $iv);
}

/**
 * default cipher is blowfish with cbc
 *
 * @param        $data
 * @param        $key
 * @param string $cipher
 *
 * @return false|string
 */
function core_decrypt_openssl($data, $key, $cipher = 'bf-cbc') {
  if (!in_array($cipher, openssl_get_cipher_methods())) {
    $cipher = 'bf-cbc';
  }

  $ivlen = openssl_cipher_iv_length($cipher);
  $iv = substr(SALTO_INVITE_IV, 0, $ivlen);
  return openssl_decrypt($data, $cipher, $key, $options = 0, $iv);
}

function array_insert_after_key(&$array, $key, $data = NULL) {
  if (($offset = array_search($key, array_keys($array))) === FALSE){
    $offset = count($array);
  }
  $offset++;
  $array = array_merge(array_slice($array, 0, $offset), (array) $data, array_slice($array, $offset));
}
