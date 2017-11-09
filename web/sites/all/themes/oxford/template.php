<?php
/**
 * @file
 * The primary PHP file for this theme.
 */
function oxford_html_head_alter(&$head_elements) {
  unset($head_elements['system_meta_generator']);
  foreach ($head_elements as $key => $element) {
    if (isset($element['#attributes']['rel']) && $element['#attributes']['rel'] == 'canonical') {
      unset($head_elements[$key]);
    }

    if (isset($element['#attributes']['rel']) && $element['#attributes']['rel'] == 'shortlink') {
      unset($head_elements[$key]);
    }
  }
}
function oxford_preprocess_html(&$vars) {
	drupal_add_css('https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css', array('type' => 'external'));
}
	
function oxford_preprocess_page(&$vars, $hook) {
  //print_r($vars);
  
  if (isset($vars['node']->type)) {
    $vars['theme_hook_suggestions'][] = 'page__' . $vars['node']->type;
  }   
}
function oxford_preprocess_block(&$vars) { 
	
	//echo "Module:".$vars['block']->module."<br/>";
	//echo "Delta:".$vars['block']->delta."<br/>";
	//echo "<hr>";	
	$vars['theme_hook_suggestions'][] = 'block__' . $vars['block']->region;
	$vars['theme_hook_suggestions'][] = 'block__' . $vars['block']->module;
	$vars['theme_hook_suggestions'][] = 'block__' . $vars['block']->module . '__' . $vars['block']->delta;
}
function oxford_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    // Prevent dropdown functions from being added to management menu so it
    // does not affect the navbar module.
    if (($element['#original_link']['menu_name'] == 'management') && (module_exists('navbar'))) {
      $sub_menu = drupal_render($element['#below']);
    }
    else{
    unset($element['#below']['#theme_wrappers']);
    $sub_menu = '<ul class="dropdown-menu">' . drupal_render($element['#below']) . '</ul>';
    $element['#localized_options']['attributes']['class'][] = 'dropdown-toggle disabled';
    $element['#localized_options']['attributes']['data-toggle'] = 'dropdown';
	$element['#localized_options']['attributes']['data-hover'] = 'dropdown';
	$element['#localized_options']['attributes']['data-delay'] = '100';
	$element['#localized_options']['attributes']['data-close-others'] = 'false';




    // Check if this element is nested within another
    if ((!empty($element['#original_link']['depth'])) && ($element['#original_link']['depth'] > 1)) {
      // Generate as dropdown submenu
      $element['#attributes']['class'][] = 'dropdown-submenu';
	  $element['#localized_options']['attributes']['tabindex'][] = '-1';

    }
    else {
      // Generate as standard dropdown
      $element['#attributes']['class'][] = 'dropdown';
      $element['#localized_options']['html'] = TRUE;
      $element['#title'] .= '<span class="caret"></span>';
    }
  }
  // Set dropdown trigger element to # to prevent inadvertant page loading with submenu click
   $element['#localized_options']['attributes']['data-target'] = '#';
  }
  // On primary navigation menu, class 'active' is not set on active menu item.
  // @see https://drupal.org/node/1896674
  if (($element['#href'] == $_GET['q'] || ($element['#href'] == '<front>' && drupal_is_front_page())) && (empty($element['#localized_options']['language']))) {
    $element['#attributes']['class'][] = 'active';
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
function oxford_form_alter(&$form, &$form_state, $form_id) {	
	if ($form_id == 'webform_client_form_60') {  	    
		//print_r($form);
		$form['#validate'][] = 'enquiry_custom_validation';  
	}	
}
function enquiry_custom_validation($form, &$form_state) {
	//echo "Hello";exit;
	//print_r($form);
	/*if($form_state['values']['submitted']['name'] != "")
	{
		if (!preg_match('/^[A-Za-z]+$/', $form_state['values']['submitted']['name'])) {
			// $form['submitted'][$key]['#attributes']['class'] = 'error';
			form_set_error('submitted][name', t('Please enter alphabets only for Name.'));
		}
	}*/
	if($form_state['values']['submitted']['telephone'] != "")
	{
		if (!preg_match('/^[0-9]+$/', $form_state['values']['submitted']['telephone'])) {
			// $form['submitted'][$key]['#attributes']['class'] = 'error';
			form_set_error('submitted][telephone', t('Please enter Number only.'));			
		}	
		if(strlen($form_state['values']['submitted']['telephone']) != '11')
		{
			form_set_error('submitted][telephone', t('Please enter 11 digit telephone No.'));
		} 
		
	}
}
function oxford_easy_breadcrumb($variables) {

  $breadcrumb = $variables['breadcrumb'];
  $segments_quantity = $variables['segments_quantity'];
  $separator = $variables['separator'];

  $html = '';

  if ($segments_quantity > 0) {

    $html .= '<div class="easy-breadcrumb" typeof="BreadcrumbList" vocab="https://schema.org/">';

    for ($i = 0, $s = $segments_quantity - 1; $i < $segments_quantity; ++$i) {
			$it = $breadcrumb[$i];
      $content = decode_entities($it['content']);
	  $text = '<span property="name">'.$content.'</span>';
			if (isset($it['url'])) {
				$html .='<span property="itemListElement" typeof="ListItem">';
				$html .= l($text, $it['url'], array('html' => TRUE, 'attributes' => array('class' => $it['class'], 'typeof' => 'webpage' ,'property' => 'item')));
				$html .='</span>';
			} else {
        $class = implode(' ', $it['class']);
		        $html .='<span property="itemListElement" typeof="ListItem">';
				$html .= '<span class="' . $class . '" typeof="webpage" property="item"><span property="name">'	. check_plain($content) . '</span></span>'; 
				$html .='</span>';
			}
			if ($i < $s) {
				$html .= '<span class="easy-breadcrumb_segment-separator"> ' . $separator . '</span>';
			}
    }
    
    $html .= '</div>';
  }

  return $html;
}

