(function ($) {
    Drupal.behaviors.og_invite_selector = {
        attach: function (context, settings) {
            Drupal.InvitePool.init(context);
        }
    }

    Drupal.InvitePool = {
        init: function (context) {

            var gid = $('#og_invite_page').data('og_gid');
            Drupal.InvitePool.gid = gid;
            Drupal.InvitePool.is_api = $("#og_invite_page").hasClass( "api");

            if (!Drupal.InvitePool.init_complete) {
                this._self = this;
                this.users = this.users || [];
                this.init_complete = true;

                this.newcounter = 0;

                var ajax_invitepool = this;

                var delay = (function (InvitePool) {
                    var timer = 0;
                    return function (callback, ms) {
                        clearTimeout(timer);
                        timer = setTimeout(callback, ms);
                    };
                })();

                //searcher

                $('.salto_og_users_selector .searcher .search-query:not(.edubreak-users-selector-processed)').addClass('edubreak-users-selector-processed').bind('keyup', {
                    InvitePool: this
                }, function (event) {
                    var self = this;
                    var val = $(this).val();

                    delay(function () {
                        var url = "";
                        if(Drupal.InvitePool.is_api) {
                          url = Drupal.settings.basePath + "salto_og/js/" + Drupal.InvitePool.gid + "/search_api/-1";
                        }else {
                          url = Drupal.settings.basePath + "salto_og/js/" + Drupal.InvitePool.gid + "/search/-1";
                        }


                        //uids to explude from next search
                        var exclude_search_uids = [];

                        for (var key in ajax_invitepool.users) {
                            exclude_search_uids.push(key);
                        }

                        ajax_invitepool.set_loading(true);

                        //abort previous searches
                        if (typeof(Drupal.InvitePool.search_request) !== "undefined") {
                            Drupal.InvitePool.search_request.abort();
                        }

                        Drupal.InvitePool.search_request = $.ajax({
                            type: "POST",
                            url: url,
                            data: {
                                search: val,
                                exclude: exclude_search_uids
                            },
                            success: function (response) {

                                if(response.length == 0) {
                                  response = "<div></div>"
                                }

                                $('#edubreak_og_ui_searchlist').html(response);
                                Drupal.attachBehaviors(response);

                                ajax_invitepool.set_loading(false);
                            }
                        });
                    }, 300);


                });

                //searchlist load all results button click
                $('#salto_og_users_selector_load_all:not(.edubreak-users-selector-processed)').addClass('edubreak-users-selector-processed').click(function (event) {

                    var self = this;

                    ajax_invitepool.set_loading(true);

                    var url = Drupal.settings.basePath + "salto_og/js/" + Drupal.InvitePool.gid + "/search/0";

                    $.ajax({
                        type: "GET",
                        url: url,
                        success: function (response) {
                            $('.items.searchlist').html(response);

                            Drupal.attachBehaviors(response);
                            ajax_invitepool.set_loading(false);
                        }
                    });

                    return false;
                });

                $(document).keypress(function(event){
                    if( (event.keyCode == 13) && (event.target.className.indexOf('search-query') > -1)) {
                        event.preventDefault();
                        return false;
                    }
                });

                $('.salto_og_user_invite .newuser-form .btn-add:not(.edubreak-users-selector-processed)').addClass('edubreak-users-selector-processed').click(function (event) {

                    var email = $('.salto_og_user_invite .newuser-form #inputEmail').val();
                    var name_first = $('.salto_og_user_invite .newuser-form #inputFirstname').val();
                    var name_last = $('.salto_og_user_invite .newuser-form #inputLastname').val();

                    if ($(".salto_og_user_invite .newuser-form #organisation-select").length) {
                        var organisation = $(".salto_og_user_invite .newuser-form #organisation-select").val();
                        Drupal.InvitePool.checkAndNewUser(email, name_first, name_last, organisation, true);
                    } else {
                        Drupal.InvitePool.checkAndNewUser(email, name_first, name_last, null, false);
                    }

                });

                //import user event
                $('.salto_og_user_invite .importuser-form .btn-add:not(.edubreak-users-selector-processed)').addClass('edubreak-users-selector-processed').click(function (event) {


                });

                $('.importuser-form .import-user-area:not(.edubreak-users-selector-processed)').addClass('edubreak-users-selector-processed').bind('keyup', function (e) {
                    Drupal.InvitePool.parseExcel();
                });
                this.initModal();

            }
            this.init_search_results();

        },
        set_loading: function (loading) {
            if (loading) {
                $('#salto_og_users_selector_load_all').attr("disabled", true);
                $('.salto_og_users_selector .searcher .search-query').addClass('loading');
            } else {
                $('#salto_og_users_selector_load_all').attr("disabled", false);
                $('.salto_og_users_selector .searcher .search-query').removeClass('loading');
            }
        },
        init_search_results: function () {
            //existing users add button click
            $('.salto_og_users_selector .item .btn-add:not(.edubreak-users-selector-processed)').addClass('edubreak-users-selector-processed').click(function (event) {
                var p = $(this).closest('.item');
                var name = p.find('.item-label');
                var uid = p.attr('id').substring(10);
                Drupal.InvitePool.addUserExisting(uid);
                p.hide();
            });

        },
        checkAndNewUser: function (email, name_first, name_last, organisation, should_have_organisation) {

            //disable add button
            $('.salto_og_user_invite .newuser-form .btn-add').attr("disabled", true);

            var data = {};
            data.name_first = name_first;
            data.name_last = name_last;
            data.email = email;

            data.guid = "new-" + Drupal.InvitePool.guid();

            if (email.length === 0) {
                alert(Drupal.t("Email not valid"));
                $('.salto_og_user_invite .newuser-form .btn-add').attr("disabled", false);
                return;
            }

            if (should_have_organisation) {
                if (organisation.length === 0) {
                    alert(Drupal.t("User must be member of a organisation."));
                    $('.salto_og_user_invite .newuser-form .btn-add').attr("disabled", false);
                    return;
                } else {
                    data.organisation = organisation;
                }
            }

            //first check if the email adress is already in our list
            for (var key in this.users) {
                if (this.users[key].hasOwnProperty("email") && this.users[key].email == email) {
                    alert(Drupal.t("Email already added in list"));
                    $('.salto_og_user_invite .newuser-form .btn-add').attr("disabled", false);
                    return;
                }
            }

            var udata = {};
            udata.data = [data];

            var argGid = Drupal.InvitePool.gid;
            if (typeof argGid === 'undefined' || argGid.length === 0) {
                argGid = data.organisation;
            }

            //validate on server side and get template
            $.ajax({
                type: "POST",
                url: Drupal.settings.basePath + "salto_og/js/" + argGid + "/validate",
                data: udata,
                dataType: "json",
                success: function (msg) {
                    var id = msg.id;
                    if (msg.is_new === true) {
                        data.id = id;
                        Drupal.InvitePool.users[id] = data;
                        Drupal.InvitePool.appendUserList(id, msg.out[id]);
                    }
                    else {
                        if (Drupal.InvitePool.users[id] == undefined) {
                            Drupal.InvitePool.users[id] = {
                                id: id
                            };
                            Drupal.InvitePool.appendUserList(id, msg.out[id]);
                            //check if the user is currently in intemlist and hide it
                            $("#user-item-" + id).hide();
                        }
                    }

                    //bin update user list event on value change event
                    $(".item-rid").not(".salto_og_user_invite_processed").change(function () {
                        Drupal.InvitePool.updateList();
                    }).addClass( "salto_og_user_invite_processed" );

                    $('.salto_og_user_invite .newuser-form .btn-add').attr("disabled", false);
                    $('.salto_og_user_invite .newuser-form #inputEmail').val("");
                    $('.salto_og_user_invite .newuser-form #inputFirstname').val("");
                    $('.salto_og_user_invite .newuser-form #inputLastname').val("");
                    if ($('#organisation_select_chosen').get(0) == null) {
                        $(".salto_og_user_invite .newuser-form #organisation-select").val("");
                    }
                },
                error: function (msg) {
                    if (msg.responseText) {
                        var errors = $.parseJSON(msg.responseText);
                        alert(errors.message);
                        $('.salto_og_user_invite .newuser-form .btn-add').attr("disabled", false);
                    }
                }
            });
        },
        checkAndNewUserMultiple: function (newusers) {

            var _users = {};
            //first check if the email adress is already in our list
            for (var key in newusers) {
                var id = "new-" + Drupal.InvitePool.guid();
                newusers[key].guid = id;
                _users[id] = newusers[key];
            }

            var udata = {};
            udata.data = _users;

            //validate on server side and get template
            $.ajax({
                type: "POST",
                url: Drupal.basePathPurl() + "/coursedetails/members/invite/js/validate",
                data: udata,
                dataType: "json",
                success: function (msg) {

                    for (var key in _users) {
                        if (msg.out[key]) {
                            _users[key].id = key;
                            Drupal.InvitePool.users[key] = _users[key];
                            Drupal.InvitePool.appendUserList(key, msg.out[key]);
                        }
                    }

                    //bind update user_list on value change event
                    $(".item-rid").not(".salto_og_user_invite_processed").change(function () {
                        Drupal.InvitePool.updateList();
                    }).addClass( "salto_og_user_invite_processed" );

                },
                error: function (msg) {
                    if (msg.responseText) {
                        var errors = $.parseJSON(msg.responseText);
                        alert(errors.message);
                        $('.salto_og_user_invite .newuser-form .btn-add').attr("disabled", false);
                    }
                }
            });
        },
        addUserExisting: function (id) {
            var data = {};

            data.uid = id;

            $.ajax({
                type: "POST",
                url: Drupal.settings.basePath + "salto_og/js/" + Drupal.InvitePool.gid + "/render",
                data: data,
                dataType: "json",
                success: function (msg) {
                    if (Drupal.InvitePool.users[id] == undefined) {
                        Drupal.InvitePool.users[id] = {
                            id: id
                        };
                        Drupal.InvitePool.appendUserList(id, msg.out);

                        //bind update user_list on value change event
                        $(".item-rid").not(".salto_og_user_invite_processed").change(function () {
                            Drupal.InvitePool.updateList();
                        }).addClass( "salto_og_user_invite_processed" );
                    }
                }
            });

        },
        appendUserList: function (id, data) {
            $('.og_users_invite_list .items').append(data);

            Drupal.InvitePool.updateList();

            $('#invitelist-item-' + id + " .btn-remove:not(.users-selector-processed)").click(function (event) {
                Drupal.InvitePool.removeUser(id);
            }).addClass('users-selector-processed');

            $("#invitelist-item-" + id + " [name='item-admin'], #invitelist-item-" + id + " [name='item-rid']:not(.edubreak-users-selector-processed)").addClass('edubreak-users-selector-processed').change(function (event) {
                Drupal.InvitePool.updateList();
            });


        },
        updateList: function () {
            var data = {};

            for (var key in this.users) {

                //extract form values
                var p = $('#invitelist-item-' + key);
                var rid_checked = p.find(".item-rid:checkbox:checked").map(function() {
                    return this.value;
                }).get();

                var admin = p.find("[name='item-admin']").is(':checked');
                data[key] = this.users[key];
                data[key].roles = rid_checked;
                data[key].admin = admin;
            }

            //toggle some ui elements
            if ($.isEmptyObject(this.users)) {
                $('.salto_og_user_invite .invitelist-empty').show();
                $('#salto-og-invite-form #edit-submit').hide();
                $('#salto-og-invite-api-form #edit-submit').hide();
            } else {
                $('.salto_og_user_invite .invitelist-empty').hide();
                $('#salto-og-invite-form #edit-submit').show();
                $('#salto-og-invite-api-form #edit-submit').show();
            }
            $('#salto-og-invite-form input[name="accounts"]').val(JSON.stringify(data));
            $('#salto-og-invite-api-form input[name="accounts"]').val(JSON.stringify(data));
        },
        removeUser: function (id) {

            //remove from list
            $('#invitelist-item-' + id).remove();

            //try to list value in selector again
            $('#user-item-' + id).show();

            delete this.users[id];

            this.updateList();
        },
        // Generate four random hex digits.
        S4: function () {
            return (((1 + Math.random()) * 0x10000) | 0).toString(16).substring(1);
        },
        guid: function () {
            return (this.S4() + this.S4() + "-" + this.S4() + "-" + this.S4() + "-" + this.S4() + "-" + this.S4() + this.S4() + this.S4());
        },
        parseExcel: function () {

            var data = $('.importuser-form .import-user-area').val();
            this.importusers = [];

            var rows = data.split("\n");
            var string = "";

            for (var y in rows) {
                var cells = rows[y].split("\t");
                string += '<tr>';
                for (var x in cells) {
                    string += ('<td>' + cells[x] + '</td>');
                }
                string += '</tr>';

                var user = {};
                user.email = cells[0];
                user.name_first = cells[1];
                user.name_last = cells[2];
                this.importusers.push(user);
            }
            $('.importuser-form .preview_grid tbody').html(string);

        },
        initModal: function () {
            $('#userImportModal:not(.edubreak-users-selector-processed)').addClass('edubreak-users-selector-processed').on('hidden', function () {
            });
            var self = this;

            //import button clicked
            $('#userImportModal .btn-import:not(.edubreak-users-selector-processed)').addClass('edubreak-users-selector-processed').on('click', function (e) {
                e.preventDefault();

                self.checkAndNewUserMultiple(self.importusers);
                $('#userImportModal').modal("hide");

            });
        }
    };

})(jQuery);
