<?php


namespace Wissensnetz\Menu;

use Wissensnetz\Group\GroupDrupalNode;
use Wissensnetz\Notification\NotificationService;
use Wissensnetz\User\DrupalUser;

class MenuService {


  /**
   * @var DrupalUser
   */
  private $drupalUser;

  #private $drupalDomain;
  #private $ogContext;

  public function __construct() {
    $this->notificationService = new NotificationService();
  }

  public function getLocalUserMenu(DrupalUser $drupalUser = NULL, $ogContext = NULL, $domainContext = NULL) {

    $this->drupalUser = $drupalUser ?? DrupalUser::current();

    $menu = [
      'group' => 'community',
      'label' => 'Community',
    ];

    $menu['dropdown_entries'] = $this->collectMenuEntries();
    $menu['bar_entries'] = $this->collectIconEntries();

    return [$menu];
  }

  private function collectMenuEntries() {

    $account = $this->drupalUser->getUser();

    $menuEntries[] = [
      'icon' => 'pi-circle',
      'label' => t('My Community profile'),
      'href' => url('user/profile/edit'),
    ];

    $menuEntries[] = [
      'icon' => 'pi-circle',
      'label' => t('My Organisation(s)'),
      'href' => url('user/organisations'),
    ];

    $menuEntries[] = [
      'icon' => 'pi-circle',
      'label' => t('My Invites'),
      'href' => url('user/invites'),
    ];

    $hasMembershipRequestAccess = user_has_role(ROLE_GLOBAL_ADMIN_RID, $account) || user_has_role(ROLE_GLOBAL_GARDENER_RID, $account);
    if ($hasMembershipRequestAccess) {
      $menuEntries[] = [
        'icon' => 'pi-circle',
        'label' => t('Membership requests'),
        'href' => url('user/membership-requests'),
      ];
    }

    return $menuEntries;
  }

  private function collectIconEntries() {
    drupal_add_js(drupal_get_path('module', 'salto_help') . '/js/salto_help.js', ['weight' => 55]);
    $iconEntries[] = [
      'icon' => 'pi-question-circle',
      'href' => '/context_support/nojs/contact/user_bar',
      'click_event' =>  "",
      'label' => t('Support')
    ];

    $iconEntries[] = [
      'icon' => 'pi-bell',
      'href' => url('notifications/all'),
      'indicator' => $this->formatIndicator($this->notificationService->getNewNotificationsCount($this->drupalUser->getUid())),
      'label' => t('Notifications')
    ];

    $iconEntries[] = [
      'icon' => 'pi-envelope',
      'href' => url('messages'),
      'indicator' => privatemsg_unread_count($this->drupalUser->getUser()) > 0 ? privatemsg_unread_count($this->drupalUser->getUser()) : "",
      'label' => t('Messages')
    ];

    return $iconEntries;
  }

  public function getContextSwitcherLabel() {

    $groupNode = GroupDrupalNode::current();

    return $groupNode ? $groupNode->getTitle() : NULL;
  }

  public function getContextSwitcherUrl() {

    $groupNode = GroupDrupalNode::current();

    return $groupNode ? $groupNode->getUrlAbsolute() : NULL;
  }

  private function formatIndicator($count = NULL) {

    if(empty($count)) {
      return NULL;
    }
    if($count > 99) {
      return "99+";
    }

    return $count;
  }

}
