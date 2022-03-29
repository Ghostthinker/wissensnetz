<div id="og_invite_page" class="salto_og_user_invite <?php echo $api ? "api" : "" ?>"
     data-og_gid="<?php print $gid ?>">

  <div class="salto_og_users_selector">
    <?php if (!empty($show_add_form)): ?>
      <div class="col-md-6 invite-panel" id="invite-by-name-panel">
        <div class="accordion-container">
          <button type="button" class="accordion-button">
            <?php print t('Invite new user'); ?>
          </button>
          <div class="accordion-panel">
            <div class="row">
              <div class="form-horizontal newuser-form">
                <div class="control-group">
                  <label class="control-label hidden-xs"
                         for="inputEmail"> <?php print t('Email') ?></label>

                  <div class="controls">
                    <input type="email" id="inputEmail"
                           placeholder="<?php print t('Email') ?>" <?php print $add_form_disabled; ?>>
                  </div>
                </div>
                <div class="control-group">
                  <label class="control-label hidden-xs"
                         for="inputFirstname" <?php print $add_form_disabled; ?>> <?php print t('First Name') ?></label>

                  <div class="controls">
                    <input type="text" id="inputFirstname"
                           maxlength="<?php echo $max_len_fist; ?>"
                           placeholder="<?php print t('First Name') ?>" <?php print $add_form_disabled; ?>>
                  </div>
                </div>
                <div class="control-group">
                  <label class="control-label hidden-xs"
                         for="inputLastname"> <?php print t('Last Name') ?></label>

                  <div class="controls">
                    <input type="text" id="inputLastname"
                           maxlength="<?php echo $max_len_last; ?>"
                           placeholder="<?php print t('Last Name') ?>" <?php print $add_form_disabled; ?>>
                  </div>
                </div>
                <?php if (!empty($organisation_field)) : ?>
                  <div class="control-group">
                    <label class="control-label"
                           for="organisation-select"> <?php print t('Organisation name') ?></label>
                    <div class="controls">
                      <?php print $organisation_field ?>
                    </div>
                  </div>
                <?php endif ?>

                <br/>

                <div class="span2 offset4">
                  <button class="btn btn-add icon-only primary"
                          id="invite-by-name-button"
                          type="button" <?php print $add_form_disabled; ?> ><i class="fa fa-plus-circle"></i></button>
                </div>
              </div>
            </div>

            <?php if (!empty($show_import)): ?>
              <div>
                <a href="#userImportModal" role="button" class="btn"
                   data-toggle="modal"><?php print t('Import users'); ?></a>
              </div>
            <?php endif ?>
          </div>
        </div>

      </div>
    <?php endif ?>

    <?php if (!empty($showExistUsers) && $showExistUsers): ?>
      <div class="col-md-6 invite-panel" id="invite-search-panel">
        <div class="accordion-container">
          <button type="button" class="accordion-button">
            <?php print t('Existing users'); ?>
          </button>
          <div class="accordion-panel">
            <div class="searcher">
              <form class="navbar-search" style="width:90%">
                <input type="text" class="search-query"
                       placeholder="<?php print t("Search"); ?>">
              </form>
            </div>
            <ul class="items searchlist" id="edubreak_og_ui_searchlist">
              <?php foreach ($users as $uid => $userdata) : ?>

                <?php echo theme('og_users_selector_item_row', array('uid' => $uid)); ?>

              <?php endforeach; ?>
            </ul>
            <div class="row">
              <a href="#" class="hide btn pull-right"
                 id="salto_og_users_selector_load_all"><?php echo t('Load all users') ?></a>
            </div>
          </div>
        </div>
      </div>
    <?php endif ?>
  </div>

  <div class="salto_og_user_invites">
    <div class="invite-panel" id="all-invites-panel">
      <div class="accordion-container attachment">
        <button type="button" class="accordion-button">
          <?php echo $api ? t('All API requirements') : t('Invites and permissions'); ?>
        </button>
        <div class="accordion-panel">
          <div class="og_users_invite_list row">
            <div class="col-md-12 invitelist-header hidden-xs hidden-sm">
              <div class="invite-list">
                <div class="col-md-2">
                </div>
                <div class="col-md-3 invite-list-heading">
                  <?php print t('Name') ?>
                </div>
                <div class="col-md-3 permissions invite-list-heading">
                  <?php if ($group->type != "group" && $api != 1) : ?>
                    <?php print t('Organisation permissions') ?>
                  <?php endif ?>
                </div>
                <div class="col-md-3 invite-list-heading">
                  <?php if (!empty($organisation_field)) : ?>
                    <?php print t('Organisation name') ?>
                  <?php endif ?>
                </div>
              </div>
            </div>
            <ul class="items <?php echo $api ? "api" : "" ?>">
              <li class="col-md-12 invitelist-empty ui-state-disabled">
                <?php print t('Add users to the invite list.') ?>
              </li>
            </ul>
          </div>
        </div>

        <!-- Import Modal -->
        <div id="userImportModal" class="modal hide fade" tabindex="-1" role="dialog"
             aria-labelledby="userImportModalLabel" aria-hidden="true">
          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal"
                    aria-hidden="true">×
            </button>
            <h3
              id="userImportModalLabel"><?php print t('Paste users from excel'); ?></h3>
          </div>
          <div class="modal-body">
            <div class="form-horizontal importuser-form">
        <textarea class="import-user-area"
                  placeholder="<?php print t("Paste from spreadsheet..") ?>"></textarea>
              <table class="preview_grid">
                <thead>
                <tr>
                  <th><?php print("Mail"); ?></th>
                  <th><?php print("Firstname"); ?></th>
                  <th><?php print("Lastname"); ?></th>
                </tr>
                </thead>
                <tbody>
                </tbody>
              </table>
            </div>
          </div>
          <div class="modal-footer">
            <button class="btn" data-dismiss="modal"
                    aria-hidden="true"><?php print("Cancel"); ?></button>
            <button
              class="btn btn-primary btn-import"><?php print("Add users"); ?></button>
          </div>
        </div>

      </div>
    </div>
  </div>
  <?php if (!empty($content['floating_button'])): ?>
    <div class="floating-button-wrapper">
      <?php print render($content['floating_button']); ?>
    </div>
  <?php endif; ?>
