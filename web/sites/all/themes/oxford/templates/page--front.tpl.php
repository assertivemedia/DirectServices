<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */ 
?>
<?php 
$theme_path = drupal_get_path('theme',$GLOBALS['theme'])
?>
<header class="site-header">
    <div class="site-header__bar-one"></div>

    <div class="container">
        <div class="site-header__contact-bar"></div>

        <div>
            <div class="site-header__contact">
                <span>T :</span>  <a href="tel:01865684988">01865 684988</a>
            </div>
             <ul class="social-icons">
                <li><a href="https://www.facebook.com/OxfordDirectServices/"><i class="fa fa-facebook" aria-hidden="true"></i></a></li>
                <li><a href="https://twitter.com/OxfordCity"><i class="fa fa-twitter" aria-hidden="true"></i></a></li>
                <li><a href="https://www.linkedin.com/company/oxford-city-council"><i class="fa fa-linkedin" aria-hidden="true"></i></a></li>
                <li><a href="https://plus.google.com/u/0/+oxfordcitycouncil"><i class="fa fa-google-plus" aria-hidden="true"></i></a></li>
            </ul>
        </div>

        <div class="site-header__identity">                    
            <?php if ($logo): ?>
            <a class="" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
              <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" class="img-responsive" />
            </a>
          <?php endif; ?>                                       
        </div>
        <div class="site-header__qoute">
            <span><?php if (!empty($site_slogan)): print $site_slogan; endif;?></span>
        </div>                
        <div class="site-header__logo__container">                    
            <a class="" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
              <img src="<?php print base_path().path_to_theme(); ?>/images/city-council-logo.svg" alt="<?php print t('Home'); ?>" class="img-responsive site-header__small-logo" /> 
            </a>
        </div>
    </div>

    <div class="site-header__bar-two"></div>
</header>
<?php /*?><nav class="navbar navbar-default" role="navigation">
    <div class="container">
        <!-- Brand and toggle get grouped for better mobile display -->
        <div class="navbar-header">
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-ex1-collapse">
                <span class="sr-only">Toggle navigation</span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </button>
        </div>

        <!-- Collect the nav links, forms, and other content for toggling -->
        <div class="collapse navbar-collapse navbar-ex1-collapse">
          <?php if (!empty($primary_nav)): ?>
          <?php print render($primary_nav); ?>
          <?php endif; ?>          
        </div><!-- /.navbar-collapse -->
    </div>
</nav><?php */?>
<?php if (!empty($page['navigation'])): ?> 
<nav class="navbar navbar-default" role="navigation" itemscope="itemscope" itemtype="https://schema.org/SiteNavigationElement">
	<div class="container">
		<?php print render($page['navigation']); ?>    
    </div>
</nav>    
<?php endif; ?> 
<?php if (!empty($page['header'])): ?>
<section id="carousel-section">  
	 
	<?php print render($page['header']); ?>    
</section>     
<?php endif; ?>   
<div class="main-container <?php print $container_class; ?>">
  <!--<header role="banner" id="page-header">
      <?php //print render($page['header']); ?>
  </header> <!-- /#page-header -->
  <div class="row">
    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>    
    <section<?php print $content_column_class; ?>>
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>      
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
        <div class="">
            <div class="row">
                <div class="col-sm-12">
                    <div class="headings-services">
                        <?php if (!empty($title)): ?>
                        <h3><?php print $title; ?></h3> 
                        <?php endif; ?>
                        <?php print render($page['content']); ?>                    </div>                   
                </div>                
            </div>
        </div>                    
    </section>
    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
    <?php if (!empty($page['content_bottom'])): ?>      
    <div class="<?php //print $container_class; ?>">
        <div class="row"> 
            <?php print render($page['content_bottom']); ?> 
        </div>
    </div>  
    <?php endif; ?>
    <?php if (!empty($page['content_bottom1'])): ?>      
    <div class="<?php //print $container_class; ?>">
        <div class="row"> 
            <?php print render($page['content_bottom1']); ?> 
        </div>
    </div>  
    <?php endif; ?>
</div> 
<?php if (!empty($page['service_carousel'])): ?> 
<section id="grey-carousel">     
    <div class="<?php print $container_class; ?>">
        <div class="row"> 
            <?php print render($page['service_carousel']); ?> 
        </div>
    </div> 
</section> 
<?php endif; ?>
<?php if (!empty($page['accordion_section'])): ?>      
<div class="<?php print $container_class; ?>">
    <div class="row"> 
        <?php print render($page['accordion_section']); ?> 
    </div>
</div>  
<?php endif; ?>
<?php if (!empty($page['contact_section'])): ?>      
<div class="<?php print $container_class; ?>">
    <div class="row"> 
        <?php print render($page['contact_section']); ?> 
    </div>
</div>  
<?php endif; ?>
<?php if (!empty($page['news_tweet_section'])): ?>      
<div class="<?php print $container_class; ?>">
    <div class="row posts">
        <?php print render($page['news_tweet_section']); ?> 
    </div>
</div>  
<?php endif; ?>
<?php if (!empty($page['testimonial_section'])): ?>      
<div class="<?php print $container_class; ?>">
    <div class="row">
        <?php print render($page['testimonial_section']); ?>
    </div>
</div>  
<?php endif; ?>
<?php if (!empty($page['client_logo_section'])): ?>       
<div class="<?php print $container_class; ?>">
    <div class="row">
        <?php print render($page['client_logo_section']); ?>
    </div>
</div>  
<?php endif; ?>
<?php if (!empty($page['footer'])): ?>
  <footer class="footer">
  	<div class="<?php print $container_class; ?>">
        <div class="row">
    		<?php print render($page['footer']); ?>
		</div>
    </div>            
  </footer>
  <a class="sticky_contact_btn" href="/contact-us">Contact Us</a>  
<?php endif; ?>

<?php /*?><?php if (!empty($page['footer'])): ?>  
<footer>
    <div class="container">
        <div class="row">
            <div class="col-xs-12 col-sm-8 col-md-4 col-lg-4">
                <img src="img/footer-logo.png" alt="" class="img-responsive">
                <div class="adress">
                     <span><i class="fa fa-map-marker" aria-hidden="true"></i></span>
                     <span>Oxford City Council<br>
St Aldate's Chambers <br>
109 St Aldate's <br>
Oxford <br>
OX1 1DS</span>
            <div class="phone">
              <ul>
                <li><i class="fa fa-phone" aria-hidden="true"></i> 01865 249811 </li>
                <li><i class="fa fa-envelope" aria-hidden="true"></i> DigitalDevelopmentTeam@oxford.gov.uk</li>
              </ul>
            </div>
                </div>
            </div>

            <div class="col-xs-12 col-sm-4 col-md-2 col-lg-2">
              <div class="footer-1">
                <h3>Main Menu</h3>
                <ul>
                   <li><a href="#">Home</a></li>
                   <li><a href="#">About</a></li>
                   <li><a href="#">Testimonials</a></li>
                   <li><a href="#">Why Choose Us ?</a></li>
                   <li><a href="#">Our Service Standards</a></li>
                   <li><a href="#">Contact Us</a></li>
                </ul>
            </div>
            </div>
            <div class="col-xs-12 col-sm-6 col-md-3 col-lg-">
                <div class="footer-1">
                <h3>Services</h3>
                <ul>
                   <li><a href="#">Commercial Recycling & Waste</a></li>
                   <li><a href="#">Landscaping & Grounds Maintenance</a></li>
                   <li><a href="#">Environmental Cleansing</a></li>
                   <li><a href="#">Vehicle Testing, Repairs & Maintenance</a></li>
                   <li><a href="#">Post Control</a></li>
                   <li><a href="#">General Civil Engineering</a></li>
                    <li><a href="#">Building Repairs & Maintenance</a></li>
                     <li><a href="#">Services for Private Residents</a></li>
                </ul>
            </div>
            </div>

            <div class="col-xs-12 col-sm-6 col-md-3 col-lg-3">
                <div class="footer-2">
                  <img src="img/10.png">
                  <ul class="social-icons">
                <li><a href="#"><i class="fa fa-facebook" aria-hidden="true"></i></a></li>
                <li><a href="#"><i class="fa fa-twitter" aria-hidden="true"></i></a></li>
                <li><a href="#"><i class="fa fa-linkedin" aria-hidden="true"></i></a></li>
                <li><a href="#"><i class="fa fa-google-plus" aria-hidden="true"></i></a></li>
            </ul>
                </div>
            </div>
        </div>
    </div>
</footer>
<?php endif; ?><?php */?>