<?php

namespace salto_core\service;

use Wissensnetz\Core\Node\DrupalNode;
use Wissensnetz\Core\Node\Exception\DrupalNodeNotExistsException;
use Wissensnetz\User\DrupalUser;

class SettingsService {

  const SETTING_CUSTOMIZATION_SETTING = 'customization_settings';
  const SETTING_SOCIAL_VIDEO_HELP = 'social_video_help';
  const SETTING_THEMENFELDER_AS_CARD = 'themenfelder_as_card';
  const SETTING_SALTO_ORGANISATION_DEFAULT_NID = 'organisation_default_nid';
  const SETTING_ORGANISATION_SELECT = 'organisation_select';
  const SUB_SETTING_ASSIGN_GROUPS_RETROSPECTIVELY = 'assign_groups_retrospectively';
  const SUB_SETTING_POST_TEASER_IMAGE_ENABLED = 'post_teaser_image_enabled';
  const SUB_SETTING_KNOWLEDGEBASE_FALLBACK_TID = 'knowledgebase_fallback_tid';
  const SUB_SETTING_MATERIAL_THEMENFELDER_AS_CARD = 'themenfelder_as_card';
  const SUB_SETTING_RELEVANT_GROUP_FILTER = 'relevant_group_filter';
  const SUB_SETTING_MANAGE_USER_ORGANISATIONS = 'manage_user_organisations';
  const SUB_SETTING_MANAGE_FORMAT_MATERIAL_TITLE = 'format_material_title';
  const SUB_SETTING_ORGANISATION_SELECT_ENABLED = 'organisation_select_enabled';
  const SUB_SETTING_ORGANISATION_SELECT_FALLBACK_ORGANISATION_DISABLED = 'organisation_select_fallback_organisation_disabled';
  const SUB_SETTING_ORGANISATION_SELECT_INFO_TEXT_MAIL_TARGET = 'organisation_select_info_text_mail_target';

  const SETTING_ONLINE_TREFFEN_COMMUNITY_AREA = 'online_meeting_community_area_enabled';

  const SUB_SETTING_MAIL_ENABLE_PREVIEW_IMAGES = 'mail_enable_preview_images';


  public static function getSetting($setting, $subsetting = NULL){
    $settings = variable_get($setting, []);

    if($subsetting){
      return $settings[$subsetting];
    }

    return $settings;
  }

  public static function assignGroupsRetrospectivelyEnabled(){
    return self::getSetting(self::SETTING_CUSTOMIZATION_SETTING, self::SUB_SETTING_ASSIGN_GROUPS_RETROSPECTIVELY);
  }

  public static function postTeaserImageEnabled(){
    return self::getSetting(self::SETTING_CUSTOMIZATION_SETTING, self::SUB_SETTING_POST_TEASER_IMAGE_ENABLED);
  }

  public static function getKnowledgeBaseFallbackTid(){
    return self::getSetting(self::SETTING_CUSTOMIZATION_SETTING, self::SUB_SETTING_KNOWLEDGEBASE_FALLBACK_TID);
  }

  public static function relevantGroupFilterEnabled(){
    return self::getSetting(self::SETTING_CUSTOMIZATION_SETTING, self::SUB_SETTING_RELEVANT_GROUP_FILTER);
  }

  public static function mailPreviewImagesEnabled() {
    return self::getSetting(self::SETTING_CUSTOMIZATION_SETTING, self::SUB_SETTING_MAIL_ENABLE_PREVIEW_IMAGES);

  }

  public static function manageUserOrganisationsEnabled(){
    return self::getSetting(self::SETTING_CUSTOMIZATION_SETTING, self::SUB_SETTING_MANAGE_USER_ORGANISATIONS);
  }

  public static function hideMaterialTitleEnabled(){
    return self::getSetting(self::SETTING_CUSTOMIZATION_SETTING, self::SUB_SETTING_MANAGE_FORMAT_MATERIAL_TITLE);
  }

  public static function onlineTreffenCommunityAreaEnabled(){
    return self::getSetting(self::SETTING_ONLINE_TREFFEN_COMMUNITY_AREA);
  }

  public static function materialThemenfelderCardsEnabled(){
    return self::getSetting(self::SETTING_CUSTOMIZATION_SETTING, self::SUB_SETTING_MATERIAL_THEMENFELDER_AS_CARD);
  }


  public static function getFallbackOrganisationNid(){
    $fallbackNid = self::getSetting(self::SETTING_SALTO_ORGANISATION_DEFAULT_NID);
    if(empty($fallbackNid)){
      return SALTO_ORGANISATION_DEFAULT_NID;
    }

    return $fallbackNid;
  }

  public static function getSelectOrganisationOptions(){
    $defaultSettings = [
      self::SUB_SETTING_ORGANISATION_SELECT_ENABLED => FALSE,
      self::SUB_SETTING_ORGANISATION_SELECT_FALLBACK_ORGANISATION_DISABLED => FALSE,
      self::SUB_SETTING_ORGANISATION_SELECT_INFO_TEXT_MAIL_TARGET => ''
    ];

    $setting = self::getSetting(self::SETTING_ORGANISATION_SELECT);
    return array_merge($defaultSettings, $setting);
  }

  public static function getSocialVideoHelp(){
    $defaultSettings = [
      'enabled' => FALSE,
      'panel_heading' => '',
      'gif_url' => '/sites/all/static_files/svp-community-einbindung-startseite-480p-240502.gif',
      'target_url' => ''
    ];

    $setting = self::getSetting(self::SETTING_SOCIAL_VIDEO_HELP);
    return array_merge($defaultSettings, $setting);
  }

  public static function getThemenfelderAsCard() {
    $defaultSettings = [
      'enabled' => FALSE,
      'default_logo' => '/sites/all/static_files/material_card_fallback.png',
      'default_icon' => '/sites/all/static_files/material_card_fallback_icon.svg',
      'taxonomy_id' => '6'
    ];

    $setting = self::getSetting(self::SETTING_THEMENFELDER_AS_CARD);
    return array_merge($defaultSettings, $setting);
  }

}
