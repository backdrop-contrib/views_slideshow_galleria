# Views Slideshow: Galleria

This is a port to Backdrop of the Drupal contributed module 
'Views Slideshow: Galleria' version 7.x-3.2.
It integrates the jQuery library Galleria with Views Slideshow.

Galleria is a JavaScript image gallery framework built on top
of the jQuery library. The aim is to simplify the process of 
creating professional image galleries for the web and mobile devices.

It depends on the Views Slideshow module being installed.

This latest release includes the Galleria jQuery library and does
not require the separate Libraries module, now obsolete.


## Installation

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules.

- If upgrading from a previous release, the Libraries module is no longer required
by this module, nor is the separate copy of the jQuery Galleria library.

## Usage notes

+ Create a new View with images, using 'Slideshow' for the 'Display Format' 
  and 'Galleria' for the 'Slideshow Type'.

+ When creating a view the image files must not be rendered in a single row.
  They can originate from the multiple file attachments of a single node or
  from multiple nodes.
  
+ There are many optional settings for Galleria that can be administered via
  the view slideshow settings page.

## License

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.
    
    
## Current Maintainers

### For Drupal:
+ Gabor Seljan (sgabe)

### Port to Backdrop:
+ Graham Oliver github.com/Graham-72

## Acknowledgements

The original author was Aaron Winborn.
