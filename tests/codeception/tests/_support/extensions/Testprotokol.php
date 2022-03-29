<?php
namespace GT\Extension;

use Codeception\Event\StepEvent;
use Codeception\Event\TestEvent;
use Codeception\Event\FailEvent;
use Codeception\Events;
use Codeception\Exception\ExtensionException;
use Codeception\Lib\Interfaces\ScreenshotSaver;
use Codeception\Module\WebDriver;
use Codeception\Step\Comment as CommentStep;
use Codeception\Test\Descriptor;
use Codeception\Util\FileSystem;
use Codeception\Util\Template;
use Codeception\Util\Annotation;

/**
 * Saves a screenshot of each step in acceptance tests and shows them as a slideshow on one HTML page (here's an [example](http://codeception.com/images/recorder.gif))
 * Activated only for suites with WebDriver module enabled.
 *
 * The screenshots are saved to `tests/_output/record_*` directories, open `index.html` to see them as a slideshow.
 *
 * #### Installation
 *
 * Add this to the list of enabled extensions in `codeception.yml` or `acceptance.suite.yml`:
 *
 * ``` yaml
 * extensions:
 *     enabled:
 *         - Codeception\Extension\Recorder
 * ```
 *
 * #### Configuration
 *
 * * `delete_successful` (default: true) - delete screenshots for successfully passed tests  (i.e. log only failed and errored tests).
 * * `module` (default: WebDriver) - which module for screenshots to use. Set `AngularJS` if you want to use it with AngularJS module. Generally, the module should implement `Codeception\Lib\Interfaces\ScreenshotSaver` interface.
 *
 *
 * #### Examples:
 *
 * ``` yaml
 * extensions:
 *     enabled:
 *         Codeception\Extension\Recorder:
 *             module: AngularJS # enable for Angular
 *             delete_successful: false # keep screenshots of successful tests
 * ```
 *
 */
class Testprotokol extends \Codeception\Extension {
  protected $config = [
    'delete_successful' => TRUE, //tbi
    'module' => 'WebDriver',
    'default_expand_all' => TRUE //tbi
  ];

  protected $has_failed;
  protected $action_steps;
  protected $tests_failed = 0;
  protected $tests_all = 0;

  protected $template = <<<EOF
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>test protocol summary</title>

    <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" rel="stylesheet">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/featherlight/1.7.6/featherlight.min.css" rel="stylesheet">
    <link href="https://cdnjs.cloudflare.com/ajax/libs/featherlight/1.7.6/featherlight.gallery.min.css" rel="stylesheet">
<style>
    body {
        background-color: #ddd;
    }

    h3 {
        margin-top: 0;
    }

    .badge {
        background-color: #777;
    }

    .tabs-left {
        margin-top: 3rem;
    }

    .nav-tabs {
        float: left;
        border-bottom: 0;
    }
    .nav-tabs li {
        float: none;
        margin: 0;
    }
    .nav-tabs li a {
        margin-right: 0;
        border: 0;
        background-color: #333;
    }
    .nav-tabs li a:hover {
        background-color: #444;
    }
    .nav-tabs .glyphicon {
        color: #fff;
    }
    .nav-tabs .active .glyphicon {
        color: #333;
    }

    .nav-tabs > li.active > a, .nav-tabs > li.active > a:hover, .nav-tabs > li.active > a:focus {
        border: 0;
    }

    .tab-content {
        margin-left: 45px;
    }
    .tab-content .tab-pane {
        display: none;
        background-color: #fff;
        padding: 1.6rem;
        overflow-y: auto;
    }
    .tab-content .active {
        display: block;
    }

    .list-group {
        width: 100%;
    }
    .list-group .list-group-item {
      /*  height: 50px;*/
    }
    .list-group .list-group-item h4, .list-group .list-group-item span {
        line-height: 11px;
    }

    .panel-default.test-success>.panel-heading {
      background-color: #dff0d8;
    }

    .panel-default.test-failed>.panel-heading {
        background-color: #f2dede;
    }

    .emoji{
    width: 24px;
    display: inline-block;
    text-align: center;
    }

    .panel-default>.panel-heading {
      padding: 4px;
    }

    .panel-group.main-content {
        margin-top: 60px;
     }

.featherlight-image {
    width: auto !important;
    height: auto !important;
    max-width: 100%;

}

.featherlight  .caption {
background: #ddd;
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    padding: 5px;
    padding-bottom: 0;
}


</style>
</head>
<body>
<nav class="navbar navbar-default navbar-fixed-top">
    <div class="container-fluid">
        <!-- Brand and toggle get grouped for better mobile display -->
        <div class="navbar-header">
            <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1" aria-expanded="false">
                <span class="sr-only">Toggle navigation</span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
            <a class="navbar-brand" href="#">Test Summary ({{tests_failed}}/{{tests_total}})</a>
        </div>

        <!-- Collect the nav links, forms, and other content for toggling -->
        <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">

            <form class="navbar-form navbar-left">
                <div class="form-group">
                    <input type="text" class="form-control search" placeholder="Search (tbi)">
                </div>
            </form>
            <div class="navbar-nav right">
                <button type="button" class="btn btn-default navbar-btn expand_all_toggle">Expand all</button>
            </div>
        </div><!-- /.navbar-collapse -->
    </div><!-- /.container-fluid -->
</nav>
<div class="panel-group container main-content" id="accordion" role="tablist" aria-multiselectable="true">
    {{tab_panes}}
</div>

<!-- jQuery -->
<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/2.1.4/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/holder/2.9.4/holder.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/vanilla-lazyload/7.2.0/lazyload.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/featherlight/1.7.6/featherlight.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/featherlight/1.7.6/featherlight.gallery.min.js"></script>
<script src="//cdnjs.cloudflare.com/ajax/libs/detect_swipe/2.1.1/jquery.detect_swipe.min.js"></script>

<script>

      $.featherlightGallery.prototype.afterContent = function() {
  var caption = this.\$currentTarget.html();
  this.\$instance.find('.caption').remove();
  $('<div class="caption">').html(caption).prependTo(this.\$instance.find('.featherlight-content'));
};

    $(function(){
    var myLazyLoad = new LazyLoad();

    $("input.search").on('input', function(e){
      var txt = $(this).val();
      $('.panel').css("display","none");
      $('.panel:contains("'+txt+'")').css("display","block");
      });

   // $(".lightbox").featherlight();


        var collapsed = true;
        $(".expand_all_toggle").click(function(){
            if (collapsed) {
                collapsed = false;
                $('.panel-collapse').collapse('show');
                $('.panel-title').attr('data-toggle', '');
                $(this).text('Collapse all');
            } else {
                collapsed = true;
                $('.panel-collapse').collapse('hide');
                $('.panel-title').attr('data-toggle', 'collapse');
                $(this).text('Expand all');
            }
        });
    });

</script>
</body>

</html>

EOF;

  protected $template2 = <<<EOF
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>test protocol summary</title>

    <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css" rel="stylesheet">
<style>
    body {
        background-color: #ddd;
    }

    h3 {
        margin-top: 0;
    }

    .badge {
        background-color: #777;
    }

    .tabs-left {
        margin-top: 3rem;
    }

    .nav-tabs {
        float: left;
        border-bottom: 0;
    }
    .nav-tabs li {
        float: none;
        margin: 0;
    }
    .nav-tabs li a {
        margin-right: 0;
        border: 0;
        background-color: #333;
        color: white;
    }
    .nav-tabs li a:hover {
        background-color: #444;
    }
    .nav-tabs .glyphicon {
        color: #fff;
    }
    .nav-tabs .active .glyphicon {
        color: #333;
    }

    .nav-tabs > li.active > a, .nav-tabs > li.active > a:hover, .nav-tabs > li.active > a:focus {
        border: 0;
    }

    .tab-content {
        margin-left: 45px;
    }
    .tab-content .tab-pane {
        display: none;
        background-color: #fff;
        padding: 1.6rem;
        overflow-y: auto;
    }
    .tab-content .active {
        display: block;
    }

    .list-group {
        width: 100%;
    }
    .list-group .list-group-item {
      /*  height: 50px;*/
    }
    .list-group .list-group-item h4, .list-group .list-group-item span {
        line-height: 11px;
    }

</style>
</head>
<body>
<!-- Navigation -->
<nav class="navbar navbar-default" role="navigation">
    <div class="navbar-header">
        <a class="navbar-brand" href="#">Test Protocol Summary</a>
    </div>
</nav>

<div class="container">
    <div class="row">
        <div class="col">
            <div class="tabs-left">
                <ul class="nav nav-tabs">
                    {{nav_links}}
                </ul>
                <div class="tab-content">
                    {{tab_panes}}
                </div><!-- /tab-content -->
            </div><!-- /tabbable -->
        </div><!-- /col -->
    </div><!-- /row -->
</div><!-- /container -->
<!-- jQuery -->
<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/2.1.4/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>

</body>

</html>


EOF;

  protected $navTemplate = <<<EOF
<li class="{{classes}}"><a href="#{{id}}" data-toggle="tab"><span>{{title}}</span></a></li>
EOF;

  protected $tabPaneTemplate = <<<EOF
<div class="panel panel-default {{classes}}">
    <div class="panel-heading" role="tab" id="heading{{id}}">
        <h4 class="panel-title pull-left">
            <a role="button" data-toggle="collapse" data-parent="#accordion" href="#collapse{{id}}" aria-expanded="true" aria-controls="collapseOne">
                {{title}}
            </a>
        </h4>
        <span class="pull-right">US: {{user_stories_summary}}</span>
        <span class="clearfix"></span>
    </div>
    <div id="collapse{{id}}" class="panel-collapse collapse" role="tabpanel" aria-labelledby="heading{{id}}">
        <div class="panel-body">

            {{scenario}}
            {{user_stories}}
            {{expects}}
            {{given}}
               <section
      data-featherlight-gallery
      data-featherlight-filter="a"
    >            {{steps}}
    </section>

            {{errors}}

        </div>
    </div>
</div>
EOF;
  protected $stepTemplate = <<<EOF
            <div class="row {{isError}}">
              <div class="col-xs-12 col-md-12"><span class="emoji">{{emoji}}</span> <a class="lightbox" href="{{img_src}}">{{step}}</a></div>
              <!--<div class="col-xs-6 col-md-2"><img src="holder.js/300x200"></div> -->
             <!-- <div class="col-xs-6 col-md-2"><a class="lightbox" href="#" data-featherlight-gallery="{{img_src}}"><img data-original="{{img_src}}" width="300" alt="screenshot of test step {{step}}"></a></div> -->
            </div>
EOF;

  public static $events = [
    Events::SUITE_BEFORE => 'beforeSuite',
    Events::SUITE_AFTER => 'afterSuite',
    Events::TEST_BEFORE => 'before',
    Events::TEST_AFTER => 'after',
    Events::TEST_ERROR => 'persist',
    Events::TEST_FAIL => 'persist',
    Events::TEST_SUCCESS => 'cleanup',
    Events::STEP_AFTER => 'afterStep',
  ];

  /**
   * @var WebDriver
   */
  protected $webDriverModule;
  protected $dir;
  protected $slides = [];
  protected $expects = [];
  protected $stepNum = 0;
  protected $seed;
  protected $recordedTests = [];
  protected $baseUrl;
  protected $all_steps;
  protected $givens;
  protected $inSetup;
  protected $fail_event;

  public function beforeSuite() {

    $this->writeln("Testprotokoll extractor started");
    $this->writeln("===============================");


    if (!$this->hasModule($this->config['module'])) {
      $this->writeln("Recorder is disabled, no available modules");
      return;
    }

    $this->seed = uniqid();
    $this->webDriverModule = $this->getModule($this->config['module']);
    if (!$this->webDriverModule instanceof ScreenshotSaver) {
      throw new ExtensionException(
        $this,
        'You should pass module which implements Codeception\Lib\Interfaces\ScreenshotSaver interface'
      );
    }
    $this->writeln(sprintf(
      "🚀 <bold>Recording and generating Support summary</bold> 🚀 step-by-step screenshots will be saved to <info>%s</info>",
      codecept_output_dir()
    ));
    $this->writeln("Directory Format: <debug>record_{$this->seed}_{testname}</debug> ----");

  }

  public function afterSuite() {
    $this->writeFile();
  }

  private function writeFile() {

    $_id = 0;
    $tabPanes = "";
    $navLinks = "";

    /*
    $txt = "<pre>" .print_r($this->recordedTests, TRUE). "</pre>";

    file_put_contents(codecept_output_dir() . 'protocol.html', $txt);
    return;
    */

    foreach ($this->recordedTests as $testname => $details) {

      $out = '';
      $id = "t-" . $_id;

      $errors ="";

      $classes = "";
      if ($_id == 0) {
        $classes = "active";
      }

      $scenario = "<h4>Scenario</h4>";
      $scenario .= "<div class=\"\">{$details['feature']}</></div>";

      $expects = "<h4>AK checks & Expectations:</h4>";
      $expects .= "<ul class=\"list-group\">";


      $aks = array();

      foreach ($details['expects'] as $step) {
        $expect = $step->getAction();

        preg_match("/^I check ([0-9]{1,3}\.[0-9]{2}).* -> (AK [\d]+(|\.[\d]+)):(.*)/", $step->getAction(), $output_array);

        $emoji = json_decode('"\u2139"');
        //$emoji = json_decode('"\u2705"');

        if (!empty($output_array)) {
          if (empty($aks[$output_array[1]][$output_array[2]])) {
            $emoji = json_decode('"\u2705"');
            $aks[$output_array[1]][$output_array[2]] = '<li class ="list-group-item"><span class="emoji">' . $emoji . "</span> " . $expect . '</li>';
            //  $expects .= '<li class ="list-group-item"><span class="emoji">' . $emoji . "</span> " . $expect . '</li>';
          }else{
            continue;
          }
        }else{
          $expects .= '<li class ="list-group-item"><span class="emoji">' . $emoji . "</span> " . $expect . '</li>';
        }
      }
      $expects .= "</ul>";

      $user_stories_summary = [];
      $user_stories = "<h4>User stories:</h4>";
      if (empty($details['user_stories'])) {
        $user_stories .= "<div>none</div>";
        $user_stories_summary[] = "none";
      }
      else {
        $user_stories .= "<ul class=\"list-group\">";
        foreach ($details['user_stories'] as $us) {

          preg_match("/([0-9]{1,3}\.[0-9]{1,3}).*(https:\/\/.*)/", $us, $output_array);

          $us_number = $output_array[1];
          $us_link = "<a target = \"_blank\" href=\"" . $output_array[2] . "\">Trello</a>";

          $user_stories_summary[$us_number] = "<a target = \"_blank\" href=\"" . $output_array[2] . "\">" . $us_number . "</a>";

          $user_stories .= '<li class ="list-group-item">' . $us_number . ' - ' . $us_link . '</li>';

          if(!empty($aks[$us_number])) {
            ksort($aks[$us_number]);
            foreach ($aks[$us_number] as $ak => $sum) {
              $user_stories .= $sum;
            }
            $user_stories_summary[$us_number] .=  "( " . implode(", ", array_keys($aks[$us_number])) ." )";
          }
        }
        $user_stories .= "</ul>";
      }


      $given = "<h4>Given:</h4>";
      $given .= "<ul class=\"list-group\">";

      if (empty($details['givens'])) {
        $given .= '<li class ="list-group-item">none</li>';
      }
      else {


        foreach ($details['givens'] as $givens) {
          $emoji = json_decode('"\uD83C\uDF81"');
          $given .= '<li class ="list-group-item"><span class="emoji">' . $emoji . "</span> I  " . $givens . '</li>';
        }
      }
      $given .= "</ul>";


      $all_steps = "<h4>Steps:</h4>";
      $all_steps .= "<ul class=\"list-group\">";
      foreach ($details['all_steps'] as $item) {

        $as = $item['step'];
        if ($item['type'] == 'action') {
          $file_name_screenshot = $item['screenshot'];

          //  preg_match("/([0-9]{2}\.[0-9]{2}).*(https:\/\/.*)/", $us, $output_array);
          $arr = preg_split('/(?=[A-Z])/', $as->getAction());
          $arr = array_map('strtolower', $arr);
          $action = implode(" ", $arr);


          $params = $as->getArgumentsAsString();

          $params_json = json_decode($params);

          if (!empty($params_json)) {
            //   $params = "<pre>".print_r($params_json, TRUE). "</pre>";
          }

          $step_method = "I " . $action . " " . $params . " ---- " . $as->getHtml('#3498db');
          $step_method = $as->getHtml('#3498db');
          $img_src = $file_name_screenshot;

          $emoji = json_decode('"\uD83D\uDE80"');


          $steps_item = (new Template($this->stepTemplate))
            ->place('step', $step_method)
            ->place('img_src', $img_src)
            ->place('emoji', $emoji)
            ->place('isError', $as->hasFailed() ? 'error' : '')
            ->produce();

          $all_steps .= '<li class ="list-group-item">' . $steps_item . '</li>';

        }
        elseif ($item['type'] == 'comment') {

          $step_method = $as->getAction() . " " . $as->getArgumentsAsString();

          preg_match("/^I check ([0-9]{2}\.[0-9]{2}).* -> (AK [\d]+(|\.[\d]+)):(.*)/", $as->getAction(), $output_array);

          $emoji = json_decode('"\u2139"');
          //$emoji = json_decode('"\uD83D\uDE80"');

          if (!empty($output_array)) {
            $aks[$output_array[1]][$output_array[2]] = $output_array[4];
            $emoji = json_decode('"\u2705"');
          }

          $all_steps .= '<li class ="list-group-item"><span class="emoji">' . $emoji . "</span> " . $step_method . '</li>';

        }

      }
      $all_steps .= "</ul>";

      if ($details['has_failed']) {
        $errors = "<h4>Error</h4>";

        $errors .= '<div class="bg-danger">' . "<pre class=\"bg-danger\">" . $this->fail_event->getFail()
            ->getMessage() . "</pre>" . '</div>';
      }


      if ($details['has_failed']) {
        $classes .= " test-failed";
        $emoji = json_decode('"\uD83D\uDE21"');
      }
      else {
        $classes .= " test-success bg-success";
        $emoji = json_decode('"\uD83D\uDE01"');
      }


      $tabPanes .= (new Template($this->tabPaneTemplate))
        ->place('id', $id)
        ->place('scenario', $scenario)
        ->place('user_stories', $user_stories)
        ->place('expects', $expects)
        ->place('given', $given)
        ->place('steps', $all_steps)
        ->place('errors', $errors)
        ->place('classes', $classes)
        ->place('title', $emoji . " " . str_replace("_", " ", $testname))
        ->place('user_stories_summary', implode(", ", $user_stories_summary))
        ->produce();

      $_id++;
    }


    $indexHTML = (new Template($this->template))
      ->place('tab_panes', $tabPanes)
      ->place('tests_total', $this->tests_all)
      ->place('tests_failed', $this->tests_failed)
      ->produce();


    file_put_contents(codecept_output_dir() . 'protocol.html', $indexHTML);
    $this->writeln("TB saved in <info>file://" . codecept_output_dir() . 'protocol.html</info>');
  }

  public function after(TestEvent $e) {
    $this->writeFile();
  }

  public function before(TestEvent $e) {


    $test = Descriptor::getTestFullName($e->getTest());
    $this->writeln("checking: $test");
    $this->expects = [];
    $this->all_steps = [];
    $this->givens = [];
    $this->inSetup = TRUE;
    $this->action_steps = [];
    $this->has_failed = FALSE;


    if (!$this->webDriverModule) {
      return;
    }
    $this->dir = NULL;
    $this->stepNum = 0;
    $this->slides = [];
    $testName = preg_replace('~\W~', '_', Descriptor::getTestAsString($e->getTest()));
    // $this->dir = codecept_output_dir() . "record_{$this->seed}_$testName";
    $this->dir = codecept_output_dir() . "screenshots_" . $this->tests_all;
    $this->baseUrl = "screenshots_" . $this->tests_all . "/";
    @mkdir($this->dir);
    $this->tests_all++;

  }

  public function cleanup(TestEvent $e) {

    $this->persist($e);
  }

  public function persist(TestEvent $e) {

    $has_failed = FALSE;
    if ($e instanceof FailEvent) {
      $this->fail_event = $e;
      $has_failed = true;
    }

    $test = $e->getTest();
    $testName = $test->getTestClass();
    $method = $test->getTestMethod();
    $example = $test->getMetadata()->getCurrent('example');


    $testname = $method;

    if(!empty($example)) {
      $testname .= " example: " .json_encode($example);
    }


    $userStories = Annotation::forMethod($testName, $method)
      ->fetchAll("UserStory");

    $this->recordedTests[$testname] = array(
      "feature" => "I want to " . $e->getTest()->getFeature(),
      "expects" => $this->expects,
      "action_steps" => $this->action_steps,
      "all_steps" => $this->all_steps,
      "givens" => $this->givens,
      "user_stories" => $userStories,
      "has_failed" => $has_failed,
    );
  }

  public function afterStep(StepEvent $e) {

    $step = $e->getStep();


    if ($step->hasFailed()) {
      $this->has_failed = TRUE;
      $this->tests_failed++;
    }

    //do not take screenshots of comments
    if ($step instanceof CommentStep) {
      $this->expects[] = $e->getStep();//->getAction();
      $this->all_steps[] = [
        'step' => $step,
        'type' => 'comment'
      ];

      return;
    }

    //check givens


    if ($this->inSetup == TRUE) {
      $method = $step->getAction();
      if ($method == 'completedSetup') {
        $this->inSetup = FALSE;
      }
      else {
        $this->givens[] = $step;
      }
      return;
    }


    //$this->givens[] = $e->getStep();


    if (!$this->webDriverModule or !$this->dir) {
      $this->writeln("return-...................");
      return;
    }

    $filename = str_pad($this->stepNum, 3, "0", STR_PAD_LEFT) . '.png';
    $this->webDriverModule->_saveScreenshot($this->dir . DIRECTORY_SEPARATOR . $filename);
    $this->stepNum++;
    $this->action_steps[$this->baseUrl . $filename] = $step;
    $this->all_steps[] = [
      'step' => $step,
      'type' => 'action',
      'screenshot' => $this->baseUrl . $filename
    ];

  }
}