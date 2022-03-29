<?php if (!empty($toolbar)): ?>
  <div class="toolbar">
    <div class="left">
      <?php if (!empty($toolbar['left'])): ?>
        <?php print $toolbar['left']; ?>
      <?php elseif ($toolbar['back']): ?>
        <a href="<?php print $toolbar['back']; ?>" class="float"
           id="goBackHistory"
          <?php if (isset($toolbar['back_onclick'])): ?>
            onclick="<?php print$toolbar['back_onclick'] ?>"
          <?php endif; ?>
        ><i class="fa fa-angle-left"></i></a>
      <?php if ($toolbar['js']): ?>
        <script
          src="/sites/all/themes/salto2014/assets/md/src/toolbar.js"></script>
      <?php endif; ?>
      <?php endif; ?>
      <h4 class="title"><?php print $toolbar['title']; ?></h4>
    </div>
    <div class="right">
      <div class="action-link-wrapper">
        <?php if (!empty($toolbar['filter'])): ?>
          <?php print $toolbar['filter']; ?>
        <?php endif; ?>
        <?php if (is_array($toolbar['action_links'])): ?>
          <?php foreach ($toolbar['action_links'] as $link): ?>
            <a href="<?php print $link['target']; ?>"
               class="icon-button ease-out <?php print $link['class']; ?>"
               title="<?php print $link['title']; ?>">
              <i class="fa fa-<?php print $link['icon']; ?>"></i>
            </a>
          <?php endforeach ?>
        <?php endif; ?>
      </div>
      <?php if (!empty($toolbar['context_links'])): ?>
        <div class="context">
          <button class="context-icon"><i class="fa fa-ellipsis-v"></i></button>
          <div class="context-menu">
            <?php foreach ($toolbar['context_links'] as $link): ?>
              <?php
              $icon = '<i class="fa fa-' . $link['#options']['attributes']['class'] . '"></i>';
              $inner = $icon . '<span>' . $link['#text'] . '</span>';
              $body = render($link);
              $body = str_replace('>' . $link['#text'] . '<', '>' . $inner . '<', $body);
              print $body;
              ?>
            <?php endforeach ?>
          </div>
        </div>

      <?php elseif (is_array($toolbar['context_menu']) && sizeof($toolbar['context_menu']) > 0) : ?>
        <?php if (sizeof($toolbar['context_menu']) > 1): ?>
          <div class="context">
            <button class="context-icon"><i class="fa fa-ellipsis-v"></i>
            </button>
            <div class="context-menu">
              <?php foreach ($toolbar['context_menu'] as $link): ?>
                <?php
                $text = $link['text'];
                $icon = $link['icon'] ? '<i class="fa fa-' . $link['icon'] . '"></i>' : '';
                $output = '<a href="' . $link['target'] . '">' . $icon . '<span>' . $text . '</span></a>';
                print $output;
                ?>
              <?php endforeach ?>
            </div>
          </div>
        <?php elseif (sizeof($toolbar['context_menu']) == 1): ?>
          <div class="context">
            <?php
            $link = $toolbar['context_menu'][0];
            $icon = $link['icon'] ? '<i class="fa fa-' . $link['icon'] . '"></i>' : '';
            $output = '<a href="' . $link['target'] . '">' . $icon . '</a>';
            print $output;
            ?>
          </div>
        <?php endif; ?>
      <?php endif; ?>
    </div>
  </div>
<?php endif; ?>
