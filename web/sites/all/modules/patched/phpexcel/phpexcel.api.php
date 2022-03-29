<?php

/**
 * @file
 * Module API documentation.
 */

/**
 * @defgroup phpexcel_api PHPExcel API
 * @{
 * PHPExcel (the library) is a powerful PHP library to export and import data
 * to and from Excel file. It is very flexible, and well built. The PHPExcel
 * Drupal module, on the other hand, provides a "wrapper", a simpler API that
 * behaves in a "Drupal" way. This module simplifies the export or import of
 * data, abstracting much of the complexity, at the cost of flexibility.
 *
 * @section export Exporting data
 *
 * The idea is to provide an API very similar to Drupal's theme_table()
 * function.
 *
 * Using the module's functions requires the phpexcel.inc file to be loaded:
 * @code
 * module_load_include('inc', 'phpexcel');
 * @endcode
 *
 * Exporting data is done via phpexcel_export().
 * @code
 * phpexcel_export(array('Header 1', 'Header 2'), array(
 *   array('A1', 'B1'),
 *   array('A2', 'B2'),
 * ), 'path/to/file.xls');
 * @endcode
 *
 * It is also possible to pass an array of options to the export function:
 * @code
 * phpexcel_export(array('Header 1', 'Header 2'), array(
 *   array('A1', 'B1'),
 *   array('A2', 'B2'),
 * ), 'path/to/file.xls', array('description' => "Some description"));
 * @endcode
 *
 * If the target file already exists, data will be appended to it, instead of
 * overwriting its content. It is also possible to use an existing file as a
 * template. This is done by specifying the "template" option:
 * @code
 * phpexcel_export(array('Header 1', 'Header 2'), array(
 *   array('A1', 'B1'),
 *   array('A2', 'B2'),
 * ), 'path/to/file.xls', array('template' => 'path/to/template.xls'));
 * @endcode
 *
 * It is possible to export data to multiple worksheets. In that case, the
 * headers array becomes a 2-dimensional array, and the data takes 3
 * dimensions. The 1st dimension represents the Worksheets. They can be
 * keyed by name, or simply numerically. The headers array determines the
 * worksheet names, unless the "ignore_headers", in which case worksheet names
 * are determined by the data array.
 * @code
 * phpexcel_export(
 *   array('Worksheet 1' => array(
 *     'Header 1',
 *     'Header 2',
 *   )),
 *   array(array(
 *     array('A1', 'B1'),
 *     array('A2', 'B2'),
 *   )),
 *   'path/to/file.xls'
 * );
 * @endcode
 *
 * Or, if ignoring headers:
 * @code
 * phpexcel_export(
 *   NULL,
 *   array('Worksheet 1' => array(
 *     array('A1', 'B1'),
 *     array('A2', 'B2'),
 *   )),
 *   'path/to/file.xls',
 *   array('ignore_headers' => TRUE)
 * );
 * @endcode
 *
 * phpexcel_export() accepts the following options, which must be given in
 * array format as the 4th parameter:
 * - ignore_headers: a boolean indicating whether the headers array should be
 *   used, or simply ignored. If ignored, worksheet names will be computed
 *   based on the data parameter.
 * - template: a path to an existing file, to be used as a template.
 * - format: The EXCEL format. Can be either 'xls', 'xlsx', 'csv', or 'ods'. By
 *   default, the extension of the file given as the target path will be used
 *   (e.g., 'path/to/file.csv' means a format of 'csv'). If the file has no
 *   extension, or an extension that is not supported, it will fallback to
 *   'xls'.
 * - creator: (metadata) The name of the creator of the file.
 * - title: (metadata) The title of the file.
 * - subject: (metadata) The subject of the file.
 * - description: (metadata) The description of the file.
 *
 * Any other options will simply be ignored, but can be useful for modules that
 * implement hook_phpexcel_export().
 *
 * phpexcel_export() will always return an integer. This integer can be one of
 * the following constants:
 * - PHPEXCEL_SUCCESS: Export was successful.
 * - PHPEXCEL_ERROR_NO_HEADERS: Error. Returned when no headers are passed, and
 *   the "ignore_headers" option is different than true.
 * - PHPEXCEL_ERROR_NO_DATA: Error. Returned when there is no data to export.
 * - PHPEXCEL_ERROR_PATH_NOT_WRITABLE: Error. Returned when the path is not
 *   writable.
 * - PHPEXCEL_ERROR_LIBRARY_NOT_FOUND: Error. Returned when the library could
 *   not be loaded. Usually this means the library is not in the correct
 *   location, or not extracted correctly. Remember that the changelog.txt file
 *   that comes with the source code must be present in the library directory.
 * - PHPEXCEL_ERROR_FILE_NOT_WRITTEN: Error. Even though the path is writable,
 *   something prevented PHPExcel from actually saving the file.
 * - PHPEXCEL_CACHING_METHOD_UNAVAILABLE: Error. This is a configuration error,
 *   and happens when the site administrator uses an unavailable caching method,
 *   like Memcached, when there's no Memcached server running.
 *
 * @section import Importing data
 *
 * Using the module's functions requires the phpexcel.inc file to be loaded:
 * @code
 * module_load_include('inc', 'phpexcel');
 * @endcode
 *
 * Importing data is done via phpexcel_import().
 * @code
 * $data = phpexcel_import('path/to/file.xls');
 * @endcode
 *
 * This will return the cell data in array format. The array structure is as
 * follows:
 * @code
 * array(
 *   0 => array(
 *     0 => array(
 *       'Header 1' => 'A1',
 *       'Header 2' => 'B1',
 *     ),
 *     1 => array(
 *       'Header 1' => 'A2',
 *       'Header 2' => 'B2',
 *     ),
 *   ),
 * );
 * @endcode
 *
 * The 1st dimension is the worksheet(s). The 2nd is the rows. Each row is keyed
 * by the table header by default.
 *
 * It is possible to export the headers as a row of data, and not key the
 * following rows by these header names by passing FALSE as the second
 * parameter:
 * @code
 * $data = phpexcel_import('path/to/file.xls', FALSE);
 * @endcode
 *
 * This will return the following format:
 * @code
 * array(
 *   0 => array(
 *     0 => array(
 *       'Header 1',
 *       'Header 2',
 *     ),
 *     1 => array(
 *       'A1',
 *       'B1',
 *     ),
 *     2 => array(
 *       'A2',
 *       'B2',
 *     ),
 *   ),
 * );
 * @endcode
 *
 * It is also possible to use the worksheet names as keys for the worksheet
 * data. This is done by passing TRUE as the third parameter.
 * @code
 * $data = phpexcel_import('path/to/file.xls', TRUE, TRUE);
 * @endcode
 *
 * This will return the following format:
 * @code
 * array(
 *   'Worksheet 1' => array(
 *     0 => array(
 *       'Header 1' => 'A1',
 *       'Header 2' => 'B1',
 *     ),
 *     1 => array(
 *       'Header 1' => 'A2',
 *       'Header 2' => 'B2',
 *     ),
 *   ),
 * );
 * @endcode
 *
 * It is possible to specify method calls to the PHPExcel reader before
 * processing the file data. This is done via the fourth parameter, which is
 * an array, keyed by method name, and whose value is the parameters. For
 * instance, if you only want to load specific worksheets to save memory:
 * @code
 * $data = phpexcel_import('path/to/file.xls', TRUE, TRUE, array(
 *   'setLoadSheetsOnly' => array('My sheet'))
 * );
 * @endcode
 *
 * The specified methods must exist, and are called on an instance of
 * PHPExcel_Reader_IReader.
 *
 * The returned data is either an array (meaning the import was successful) or
 * an integer. The integer can be one of the following:
 * - PHPEXCEL_ERROR_FILE_NOT_READABLE: Error. The file was not found or isn't
 *   readable.
 * - PHPEXCEL_ERROR_LIBRARY_NOT_FOUND: Error. Returned when the library could
 *   not be loaded. Usually this means the library is not in the correct
 *   location, or not extracted correctly. Remember that the changelog.txt file
 *   that comes with the source code must be present in the library directory.
 *
 * @}
 */

/**
 * @defgroup phpexcel_perf PHPExcel performance settings
 * @{
 * PHPExcel (the library) allows developers to have fine-grained control over
 * the way cell data is cached. Large Excel files can quickly take up a lot of
 * memory (about 1Kb per cell), and PHP processes could die running out of
 * available memory.
 *
 * PHPExcel is usable with APC, Memcached, SQLite or static file storage, to
 * optimize memory usage. PHPExcel can also gzip cell data, resulting in less
 * memory usage, but at the cost of speed.
 *
 * Because this should not be controlled by any modules, but depends on each
 * site install, there's no API to set what caching method to use. By default,
 * PHPEXcel will use in-memory caching for fastest performance. Site
 * administrators can change this by going to /admin/config/system/phpexcel.
 * This configuration form will allow them to choose an appropriate caching
 * method, and provide any related settings. The module will then start using
 * these settings when exporting and importing data, to optimize memory usage.
 *
 * The following methods are available:
 * - In memory, which is the fastest, but also consumes the most memory.
 * - In memory, serialized. Slightly slower, but decreases memory usage.
 * - In memory, gzipped. Slighty slower than serialized, but decreases memory
 *   usage even further.
 * - APC, requires APC to be installed. Fast, and doesn't increase memory usage.
 * - Memcache, requires Memcached to be installed and running. Fast, and doesn't
 *   increase memory usage.
 * - SQLite3. Ships with most PHP installs. Slow, but doesn't increase memory
 *   usage.
 * - Static files (stored in php://tmp). Slowest, but doesn't increase memory
 *   usage. In this case, it is still possible to set a maximum limit, up until
 *   which PHPExcel will still use in-memory caching. Defaults to 1Mb. After
 *   reaching that limit, data is stored in static files.
 * @}
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Implements hook_phpexcel_export().
 *
 * @see phpexcel_export()
 *
 * @param string $op
 *    The current operation. Can either be "headers", "new sheet", "data",
 *    "pre cell" or "post cell".
 * @param array|string &$data
 *    The data. Depends on the value of $op:
 *    - "headers": The $data parameter will contain the headers in array form.
 *      The headers have not been added to the document yet and can be altered
 *      at this point.
 *    - "new sheet": The $data parameter will contain the sheet ID. This is a
 *      new sheet and can be altered, if required, using the $phpexcel
 *      parameter.
 *    - "data": The $data parameter contains all the data to be exported as a
 *      3-dimensional array. The data has not been exported yet and can be
 *      altered at this point.
 *    - "pre cell": The $data parameter contains the call value to be rendered.
 *      The value has not been added yet and can still be altered.
 *    - "post cell": The $data parameter contains the call value that was
 *      rendered. This value cannot be altered anymore.
 * @param PHPExcel|PHPExcel_Worksheet $phpexcel
 *    The current object used. Can either be a PHPExcel object when working
 *    with the excel file in general or a PHPExcel_Worksheet object when
 *    iterating through the worksheets. Depends on the value of $op:
 *    - "headers" or "data": The $phpexcel parameter will contain the PHPExcel
 *      object.
 *    - "new sheet", "pre cell" or "post cell": The $phpexcel parameter will
 *      contain the PHPExcel_Worksheet object.
 * @param array $options
 *    The $options array passed to the phpexcel_export() function.
 * @param int $column
 *    The column number. Only available when $op is "pre cell" or "post cell".
 * @param int $row
 *    The row number. Only available when $op is "pre cell" or "post cell".
 *
 * @ingroup phpexcel_api
 */
function hook_phpexcel_export($op, &$data, $phpexcel, $options, $column = NULL, $row = NULL) {
  switch ($op) {
    case 'headers':

      break;

    case 'new sheet':

      break;

    case 'data':

      break;

    case 'pre cell':

      break;

    case 'post cell':

      break;
  }
}

/**
 * Implements hook_phpexcel_import().
 *
 * @see phpexcel_import()
 *
 * @param string $op
 *    The current operation. Either "full", "sheet", "row", "pre cell" or
 *    "post cell".
 * @param mixed &$data
 *    The data. Depends on the value of $op:
 *    - "full": The $data parameter will contain the fully loaded Excel file,
 *      returned by the PHPExcel_Reader object.
 *    - "sheet": The $data parameter will contain the current
 *      PHPExcel_Worksheet.
 *    - "row": The $data parameter will contain the current PHPExcel_Row.
 *    - "pre cell": The $data parameter will contain the current cell value. The
 *      value has not been added to the data array and can still be altered.
 *    - "post cell": The $data parameter will contain the current cell value.
 *      The value cannot be altered anymore.
 * @param PHPExcel_Reader|PHPExcel_Worksheet|PHPExcel_Cell $phpexcel
 *    The current object used. Can either be a PHPExcel_Reader object when
 *    loading the Excel file, a PHPExcel_Worksheet object when iterating
 *    through the worksheets or a PHPExcel_Cell object when reading data
 *    from a cell. Depends on the value of $op:
 *    - "full", "sheet" or "row": The $phpexcel parameter will contain the
 *      PHPExcel_Reader object.
 *    - "pre cell" or "post cell": The $phpexcel parameter will contain the
 *      PHPExcel_Cell object.
 * @param array $options
 *    The arguments passed to phpexcel_import(), keyed by their name.
 * @param int $column
 *    The column number. Only available when $op is "pre cell" or "post cell".
 * @param int $row
 *    The row number. Only available when $op is "pre cell" or "post cell".
 *
 * @ingroup phpexcel_api
 */
function hook_phpexcel_import($op, &$data, $phpexcel, $options, $column = NULL, $row = NULL) {
  switch ($op) {
    case 'full':

      break;

    case 'sheet':

      break;

    case 'row':

      break;

    case 'pre cell':

      break;

    case 'post cell':

      break;
  }
}

/**
 * @} End of "addtogroup hooks".
 */
