<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */

$basePath = base_path() . drupal_get_path('module', 'salto_knowledgebase') . '/webcomponents/GTReactions/svg';

$previewImageClass = $preview_image ? 'image' : 'no-image';

?>

<?php if ($teaser): ?>
  <div
    class="<?php print $previewImageClass . ' ' . $classes; ?> clearfix hearbeat-activity-stream-new nid-<?php print $nid; ?>"
>

    <div class="icon-top-right">
      <?php print render($title_prefix); ?>
      <?php print render($title_suffix); ?>
    </div>

    <div
        class="activity-stream-left"
        style="background-image:linear-gradient(180deg, rgba(84, 86, 95, 0.00) 0.26%, rgba(84, 86, 95, 0.27) 23.54%, rgba(84, 86, 95, 0.61) 42.35%, rgba(84, 86, 95, 0.85) 58.87%, rgba(84, 86, 95, 0.95) 99.74%), url(<?php print $preview_image; ?>)"

    >
      <div style="position: relative; height: calc(100% - 105px);">
          <div class="activity-stream-chip">
            <a
              href="<?php print url('user/' . $node->uid) ?>"
              target="_blank"
              style="position: absolute; top:0; right:0; bottom:0; left:0;"
            >
            </a>
            <?php print $user_picture ?>
            <div class="content-info">
              <span><b><?php print $name; ?></b></span>
              <span class="chip-info-date"><?php print $submit_date; ?></span>
            </div>
          </div>
          <div class="activity-stream-main">
            <div class="activity-stream-heading">


              <h2<?php print $title_attributes; ?>><a
                  href="<?php print $node_url; ?>"><?php print $title; ?></a>
              </h2>
              <?php if (isset($publishing_label)): ?>
                <span class="publishing">
                    <?php print $publishing_label; ?>
                </span>
              <?php endif; ?>
            </div>
            <div class="activity-stream-content">
              <div class="group-content"<?php print $content_attributes; ?>>
                <?php
                hide($content['comments']);
                hide($content['links']);
                hide($content['links_right']);
                print render($content);
                ?>
              </div>
            </div>
        </div>
      </div>
      <!--<div class="statistics">
        <span><i class="icon-eye"></i><?php print $num_views; ?></span>
        <div>
          <img class="comment-button-icon"
               src="<?php echo $basePath . '/commentButton.svg' ?>">
          <a target="_blank"
             href="/node/<?php print $nid; ?>/#comments"><?php print $num_comments; ?></a>
        </div>
      </div>-->
      <div class="footer-container">
        <div class="statistics">
          <?php if ($reactions_enabled): ?>
            <div class="reaction-footer">
              <div class="reaction-summary"
                   data-entity-type="node"
                   data-entity-id="<?php print $nid ?>"
              ><?php print $reactionsSerialized ?></div>
            </div>
          <?php endif; ?>
          <span><i
              class="icon-eye"></i><?php print $num_views; ?></span>
          <div class="statistics-comment">
            <a target="_blank"
               href="/node/<?php print $nid; ?>/#comments">
              <div class="comment-button-icon-mask"
                   style="mask-image: url(<?php echo url($basePath . '/commentButton.svg', ['absolute' => TRUE]) ?>);">
              </div>
              <?php print $num_comments; ?>
            </a>
          </div>
        </div>
        <div class="action-buttons">
          <div class="left-side">
            <gt-reactions-button data-entity-type="node" data-entity-id="<?php print $nid ?>">
              <div class="footer-icon">
              <div class="icon-mask like-button"
                   style="mask-image: url(<?php print $basePath . '/likeButton.svg'; ?>);"></div>
              </div>
            </gt-reactions-button>

            <a target="_blank" href="<?php print url('/node/' . $node->nid, [
              'absolute' => TRUE,
              'fragment' => 'comment-anchor',
            ]) ?>">
              <div class="footer-icon">
                <div class="icon-mask comment-button"
                     style="mask-image: url(<?php print $basePath . '/commentButton.svg'; ?>);">
                </div>
              </div>
            </a>
          </div>
        </div>
      </div>
    </div>


    <div
      class="activity-stream-right <?php print $preview_image ? 'image' : 'no-image' ?>">
      <span class="stream-icon heartbeat-activity-type-post"></span>
      <?php if (!empty($preview_image)): ?>
        <img class="chip-img"
             src="<?php print $preview_image; ?>"
             width="100%">
      <?php endif; ?>
    </div>

  </div>

<?php else: ?>

  <article id="node-<?php print $node->nid; ?>"
           class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <?php if (stripos($node->type, 'comment') === FALSE): ?>
      <div class="card">
        <div class="card-content">
          <div class="header">
            <?php print $user_picture; ?>
            <div>
              <div class="post-header">
                <b><?php print $name; ?></b>
              </div>
              <?php if ($submit_date): ?>
              <div class="submit-date">
                <?php print $submit_date; ?>
              </div>
            </div>
          </div>
          <br>
          <div class="header">
            <?php endif; ?>

            <?php if (!$page): ?>
              <h2<?php print $title_attributes; ?>><a
                  href="<?php print $node_url; ?>"><?php print $title; ?></a>
              </h2>
            <?php else: ?>
              <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
            <?php endif; ?>
            <?php if (isset($publishing_label)): ?>
              <span class="publishing">
                <?php print $publishing_label; ?>
            </span>
            <?php endif; ?>
            <?php print render($title_prefix); ?>
            <?php print render($title_suffix); ?>
          </div>

          <div class="group-content"<?php print $content_attributes; ?>>
            <?php
            hide($content['comments']);
            hide($content['links']);
            hide($content['links_right']);
            print render($content);
            ?>
          </div>

          <?php if ($reactions_enabled): ?>
            <?php
            $content['links']['comment2'] = array_replace([], $content['links']['comment']);
            unset($content['links']['comment2']['#links']['comment-comments']);
            unset($content['links']['comment']['#links']['comment-add']);

            $comment_link = drupal_render($content['links']['comment2']);
            ?>

            <div class="reaction-footer">
              <div class="footer-meta">
                <div class="reaction-summary" data-entity-type="node"
                     data-entity-id="<?php print $node->nid ?>"><?php print $reactionsSerialized ?></div>
                <div
                  class="footer-links"><?php print render($content['links']['statistics']); ?> <?php print render($content['links']['attachments']); ?>
                  <?php if (!empty($content['links']['comment']['#links']['comment-comments'])): ?>
                    <img
                      class="comment-button-icon"
                      src="<?php echo $basePath . '/commentButton.svg' ?>">
                  <?php endif; ?>
                  <?php print render($content['links']['comment']); ?></div>
              </div>
              <?php if ($user->uid > 0): ?>
                <div class="reaction-actions">
                  <gt-reactions-button data-entity-type="node"
                                       data-entity-id="<?php print $node->nid ?>">
                    <img
                      class="like-button"
                      src="<?php echo $basePath . '/likeButton.svg' ?>"><span
                      class="like-text"><?php print t("Like"); ?></span>
                  </gt-reactions-button>
                  <div class="comment-button"><span
                      class="comment-text"><?php print l('<img class="comment-button" src="' . $basePath . '/commentButton.svg">' . t("Comment"), "/node/" . $node->nid, [
                        'fragment' => 'edit-comment-body',
                        'html' => TRUE,
                      ]) ?>
              </span>
                  </div>
                </div>
              <?php endif; ?>
            </div>
          <?php else: ?>

            <div class="group-footer">
              <div class="foo-left">

                <?php print render($content['links']); ?>

                <?php if ($submit_date): ?>
                  <div class="submit-date">
                    <?php print $submit_date; ?>
                  </div>
                <?php endif; ?>
              </div>
              <div class="foo-right">
                <?php print render($content['links_right']); ?>
              </div>
            </div>
          <?php endif; ?>
        </div>
      </div>
    <?php endif; ?>
    <?php if (!empty($content['comments']['comment_form'])): ?>
      <div class="accordion-container">
        <button class="accordion-button">Kommentare</button>
        <div class="accordion-panel">
          <?php print render($content['comments']); ?>
        </div>
      </div>
      <!--script src="/sites/all/themes/salto2014/assets/md/src/accordion.js"></script-->
    <?php endif; ?>
  </article>
<?php endif; ?>
