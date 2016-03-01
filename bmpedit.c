#include <stdio.h>

/* Usage: bmpedit [OPTIONS...] [input.bmp]

DESCRIPTION:
  This program does simple edits of BMP image files. When the program runs it first prints 
  out the width and the height of the input image within the BMP file.  Once this is done if
  there is a filter (or sequence of filters) then they are applied to the image.  The resulting image is also
  stored using BMP format into an output file.  Without any filters only the width and height of the image is output.

OPTIONS:
  -o FILE      Sets the output file for modified images (default output file is "out.bmp").
  -t 0.0-1.0   Apply a threshold filter to the image with a threshold the threshold value given.
  -h           Displays this usage message. */

FILE *input_image;
  
// HEADER PARSER FUNCTION DEFINITION WILL GO HERE
void HeaderParser(FILE input_image);


/* Code for taking arguments from terminal appropriated from these sources:
http://stackoverflow.com/questions/498320/pass-arguments-into-c-program-from-command-line
http://stackoverflow.com/questions/17645447/how-to-pass-command-line-arguments-to-a-c-program?rq=1
*/
int main(int argc, char *argv[]) {
	input_image = fopen(argv[1], "r");

  HeaderParser(input_image);


	printf("File name %s\n", argv[1]);
	return 0;

	// continue reading: http://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1048384537&id=1043284392

}
