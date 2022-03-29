<?php

/**
 * @file
 * The standard url processor class.
 */

/**
 * Url processor plugin that retrieves facet data from the query string.
 *
 * This plugin retrieves facet data from $_GET, and stored all information in
 * the "f" query string variable by default.
 */
class SaltoSearchFacetapiUrlProcessor extends FacetapiUrlProcessorStandard {

  private $count = 0;
  private $session = null;
  /**
   * Implements FacetapiUrlProcessor::fetchParams().
   *
   * Use $_GET as the source for facet data.
   */
  public function fetchParams() {

    $session = salto_search_session('solr_search_param');
    if (strlen($session) > 1) {
      $query = $_GET;
      $query['search_api_views_fulltext'] = $session;

      salto_search_session('solr_search_param', 'n');

      $this->session = $query;
      return $query;
    }
    if ($this->session !== null) {
      return $this->session;
    }
    return $_GET;
  }

  protected function getCurrentCollation() {
    $search = search_api_current_search();
    $response = $search[1]['search_api_solr_response'];
    if (isset($response->spellcheck->collations->collation)) {
      return $response->spellcheck->collations->collation;
    }
    return null;
  }

  public function getQueryString(array $facet, array $values, $active) {
    //fetch param only once, not for any query
    if ($this->count < 1) {
      // now is search execute, so overwrite params
      $params = $this->fetchParams();
      $this->setParams($params, $this->getFilterKey());
    }
    $this->count++;
    return parent::getQueryString($facet, $values, $active);
  }


}
