(function ($) {
	Drupal.behaviors.oxford_mots = {
    	attach: function (context, settings) {
			$('#address_lookup').click(function(){
				var postcode = $('.postcode-input').val();  
				//alert(postcode);
				var url = '/find_address';		
				var data = 'pcode='+ postcode;
				$.ajax({
				  type: 'POST',
				  url: url,			  				  
				  data: data,
				  success: function (data1) {	
					$('.address-input').html(data1); 
				  }
				});
			}); 		
			
		}
	} 
	Drupal.ajax.prototype.commands.redirectUser = function(ajax, response)
	{
	  // response.path is the path we gave in our Ajax callback
	  window.location.replace(response.path);
	};
}(jQuery));  
