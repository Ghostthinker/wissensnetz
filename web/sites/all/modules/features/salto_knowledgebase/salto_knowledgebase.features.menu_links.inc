<?php
/**
 * @file
 * salto_knowledgebase.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function salto_knowledgebase_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-knowledgebase-left_erfahrungsberichte:knowledge/experience
  $menu_links['menu-knowledgebase-left_erfahrungsberichte:knowledge/experience'] = array(
    'menu_name' => 'menu-knowledgebase-left',
    'link_path' => 'knowledge/experience',
    'router_path' => 'knowledge',
    'link_title' => 'Erfahrungsberichte',
    'options' => array(
      'identifier' => 'menu-knowledgebase-left_erfahrungsberichte:knowledge/experience',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-knowledgebase-left_fragen:knowledge/questions
  $menu_links['menu-knowledgebase-left_fragen:knowledge/questions'] = array(
    'menu_name' => 'menu-knowledgebase-left',
    'link_path' => 'knowledge/questions',
    'router_path' => 'knowledge',
    'link_title' => 'Fragen',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-knowledgebase-left_fragen:knowledge/questions',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-knowledgebase-left_lehr-lern-materialien:knowledge/files
  $menu_links['menu-knowledgebase-left_lehr-lern-materialien:knowledge/files'] = array(
    'menu_name' => 'menu-knowledgebase-left',
    'link_path' => 'knowledge/files',
    'router_path' => 'knowledge/files',
    'link_title' => t('Materials'),
    'options' => array(
      'identifier' => 'menu-knowledgebase-left_lehr-lern-materialien:knowledge/files',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Erfahrungsberichte');
  t('Fragen');
  t('Materials');


  return $menu_links;
}
