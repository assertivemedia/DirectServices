Structured Data Markup (sdm) module
==========

Provides an entity for adding Structured Data Markup (SDM) JSON/LD
script objects to your site. You can create fieldable sdm object types
to add whatever custom JSON/LD objects you like, and use context module
to determine what sdm objects are rendered (in the page <head>) and when.

A feature module is provided as both an example and an implementation
of the popular google social profiles via JSON/LD.


Installation
==========

1)  Download and install in the usual way.
2)  Make sure that your admin user(s) have the Administer Structured
    Data Markup (administer_sdm_data) permission.
3)  Navigate to /admin/structure/sdm/types to add a sdm object type(s).
4)  Manage the sdm type as you would any other entity by adding a
    description, adding fields etc. NOTE that the display management
    screen is not used so you can ignore that.
5)  Navigate to /admin/structure/sdm and add an sdm object(s) of your
    new type(s).
6)  Navigate to /admin/structure/context and add a context (or
    modify an existing one). Add an sdm reaction and select one or
    more sdm objects that you have created. The JSON/LD object will
    be included in the <head> of the pages on which the context is active.

Google Social Profiles SDM
==========

1)  Install the google_social_profile_sdm module as usual.
2)  Navigate to /admin/structure/sdm and add one or more sdm objects
    of type Google Social Profile (google_social_profile).
    See https://developers.google.com/structured-data/customize/social-profiles
    for more information on this JSON/LD implementation.

AUTHOR/MAINTAINER
======================
-Ted Benice, PHD -- http://bythewaylabs.com [ted@bythewaylabs<DOT>com]