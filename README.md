# Views Slideshow: Galleria

This is a port to Backdrop of the Drupal contributed module 
'Views Slideshow: Galleria' version 7.x-3.2.

It integrates the jQuery library Galleria with Views Slideshow.

Galleria is a JavaScript image gallery framework built on top
of the jQuery library. The aim is to simplify the process of 
creating professional image galleries for the web and mobile devices.

It requires the Views Slideshow module to be installed, together with the
jQuery Galleria library from from http://galleria.io/download.


## Status
This port is 'work in progress'. 
It requires the latest release 1.x-3.2.1 of Views Slideshow.

## Installation

Install as usual, then add the required javascript libraries to their own 
directories within the site's libraries folder.

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
