jQuery(document).ready(function($){
	Drupal.behaviors.recapcha_ajax_behaviour = {
		attach: function(context, settings) {
		  $('.webform-client-form', context).once('webform_ajax', function () {
			if (typeof grecaptcha != "undefined") {
			  var captchas = document.getElementsByClassName('g-recaptcha');
			  for (var i=0;i<captchas.length;i++) {
				var site_key = captchas[i].getAttribute('data-sitekey');
				grecaptcha.render(captchas[i], { 'sitekey' : site_key});
			  }
			}
			});
		}
  	}
	$('.about-services').click(function(){
		var content = $(this).data('content');
		$('.blog-content').hide();
		$('.'+content).show();		
	});
	Drupal.behaviors.basicWorks = function(context) {
	  // Track submission events.
	  $('#webform-client-form-60', context).submit(function() {
		 ga( 'send', 'event', 'Online Enquiry Form', 'submit' );
	  });
	
	};
});