<?php

namespace salto_core\service;

use Wissensnetz\Core\Node\DrupalNode;
use Wissensnetz\Core\Node\Exception\DrupalNodeNotExistsException;
use Wissensnetz\User\DrupalUser;

class LegalService {

  private const STANDARD_LEGAL_UPDATED_TIME_KEY = 'standard_legal_updated';

  public function updateLegal($legalData, $reaccept = TRUE) {

    $legal = legal_get_conditions($legalData['language']);

    if(!$reaccept){
      dbtng_query('UPDATE {legal_conditions} SET conditions= :conditions WHERE version = :version AND revision = :revision and language = :language',
        [
          ':conditions' => $legalData['termsOfUse'],
          ':version' => $legal['version'],
          ':revision' => $legal['revision'],
          ':language' => $legalData['language'],
        ]);

      return;
    }

    $new_vals['revision'] = $legal['revision'];
    $new_vals['version'] = ++$legal['version'];
    $new_vals['conditions'] = $legalData['termsOfUse'];
    $new_vals['date'] = time();
    $new_vals['language'] = $legalData['language'];
    $new_vals['extras'] = serialize($legal['extras']);
    $new_obj = (object) $new_vals;

    drupal_write_record('legal_conditions', $new_obj);

    return $new_obj;


  }

  public function updateLegalTime($updated) {
    variable_set(self::STANDARD_LEGAL_UPDATED_TIME_KEY, strtotime($updated));
  }

  public function getLegalUpdatedTime(){
    return variable_get(self::STANDARD_LEGAL_UPDATED_TIME_KEY, NULL);
  }

}
