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
	/* waste enquiry form checkbox */
	 $('.checkbox-image input[type="checkbox"]').click(function(){
	  //alert('hello');
	  $(this).parent('.checkbox-image').toggleClass("check");  
		  if($(this).is(':checked')) {		
			   $(this).attr('Checked','Checked'); 
			   $(this).parent('.checkbox-image').next('.form-item').find('input[type="text"]').prop('disabled', false);
		  }else{
			   $(this).removeAttr('Checked'); 
			   $(this).closest('.checkbox-image').next('.form-item').find('input[type="text"]').prop('disabled', true);
		  }		 
	 });

	$('.radioBtn a').on('click', function(){
    	var sel = $(this).data('title');
    	var tog = $(this).data('toggle');
    	$('#'+tog).prop('value', sel);
    
    	$('a[data-toggle="'+tog+'"]').not('[data-title="'+sel+'"]').removeClass('active').addClass('notActive');
    	$('a[data-toggle="'+tog+'"][data-title="'+sel+'"]').removeClass('notActive').addClass('active');
	});
	$('#vehicle-data').on('click', '.radioBtn a' ,function(){
    	var sel = $(this).data('title');
    	var tog = $(this).data('toggle');
    	$('#'+tog).prop('value', sel);
    
    	$('a[data-toggle="'+tog+'"]').not('[data-title="'+sel+'"]').removeClass('active').addClass('notActive');
    	$('a[data-toggle="'+tog+'"][data-title="'+sel+'"]').removeClass('notActive').addClass('active');
	});
	
	$('.collection-detail select').change(function(){
		var value = $(this).val();
		var currentID = $(this).attr('data-id');
		if(value == 'Daily'){			
			$('#'+currentID).show();
		} else {
			$('#'+currentID).hide();
		}
	});
	/* stick menu */
	$(window).scroll(function() {
     	var y = $(window).scrollTop(); 
		var hh = $('header').outerHeight();
		var ww = $(window).width();
		if(ww > 991)
		{
			if(y > hh)
			{
				$('nav').removeClass("animated fadeIn navbar-fixed-top");
				$('nav').addClass("animated fadeIn navbar-fixed-top");
			}
			else{
				$('nav').removeClass("animated fadeIn navbar-fixed-top");
			}
		}
 	});
});