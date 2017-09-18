(function ($) {
    Drupal.behaviors.gCapcha = {
        attach: function (context, settings) {
            if (typeof grecaptcha !== 'undefined') {
                this.addCaptcha();
            }
        },
        addCaptcha: function () {
            var settings = Drupal.settings;
            grecaptcha.render(
                settings.g_captcha.captcha_form_name, settings.g_captcha.options
            );
        }
    };
})(jQuery)

var google_recaptcha_onload = function () {
    Drupal.behaviors.gCapcha.addCaptcha();
};