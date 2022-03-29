If your site become inaccessible for some reason, add the following line of
code to settings.php to disable the module functionality.

$conf['force_password_change_module_enabled'] = FALSE;

Save the file, fix your problems, then remove the line of code above.

If you don't remove this line of code, the module does nothing and is essentially useless.
