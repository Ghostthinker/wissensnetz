<?php


class CoreSystemQueue extends SystemQueue implements DrupalReliableQueueInterface {

  public function __construct($name) {
    watchdog(CoreSystemQueue::class, 'Constructed queue: %name', ['%name' => $name]);
    parent::__construct($name);
  }

  /**
   * @param $name
   *
   * @return DrupalReliableQueueInterface|mixed
   */
  public static function create($name) {
    variable_set('queue_class_' . $name, CoreSystemQueue::class);

    $systemQueue = DrupalQueue::get($name);
    $systemQueue->createQueue();
    return $systemQueue;
  }

  /**
   * @param $data
   *
   * @return bool
   */
  public function createItem($data) {
    watchdog(CoreSystemQueue::class, 'Created item: %data', ['%data' => print_r($data, TRUE)]);
    return parent::createItem($data);
  }

  /**
   * @param $item
   */
  public function deleteItem($item) {
    watchdog(CoreSystemQueue::class, 'Delete item: %data', ['%data' => print_r($item, TRUE)]);
    parent::deleteItem($item);
  }

  /**
   * @param $item
   *
   * @return bool|DatabaseStatementInterface|null
   */
  public function releaseItem($item) {
    watchdog(CoreSystemQueue::class, 'Release item: %data', ['%data' => print_r($item, TRUE)]);
    return parent::releaseItem($item);
  }

  /**
   * @return mixed
   */
  public function numberOfItems() {
    $count = parent::numberOfItems();
    watchdog(CoreSystemQueue::class, 'Asked for numberOfItems: %num', ['%num' => $count]);
    return $count;
  }

  /**
   * e.q. $module = 'onsite_notification';
   *
   * @param        $module
   * @param string $hook
   */
  public static function executeByModule($module, $hook = 'cron_queue_info') {
    $queues = module_invoke($module, $hook);
    foreach ($queues as $name => $queue) {
      CoreSystemQueue::execute($name, $queue);
    }
  }

  public static function executeAll() {
    $hook = 'cron_queue_info';

    $queues = module_invoke_all($hook);
    foreach ($queues as $name => $queue) {
      CoreSystemQueue::execute($name, $queue);
    }
  }

  /**
   * @param $name
   * @param $info
   *
   * @return bool
   */
  public static function execute($name, $info) {

    if (empty($name) || empty($info)) {
      return FALSE;
    }
    watchdog(CoreSystemQueue::class, 'data: %data', ['%data' => print_r($info, TRUE)]);

    $callback = $info['worker callback'];
    $end = time() + (isset($info['time']) ? $info['time'] : 15);
    $queue = \CoreSystemQueue::create($name);
    while (time() < $end && ($item = $queue->claimItem())) {
      try {
        call_user_func($callback, $item->data);
        $queue->deleteItem($item);
      } catch (\Exception $ex) {
        // In case of exception log it and leave the item in the queue
        // to be processed again later.
        watchdog_exception(CoreSystemQueue::class, $ex);
      }
    }
    return TRUE;
  }

}
