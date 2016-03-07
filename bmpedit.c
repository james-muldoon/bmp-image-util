#include <stdio.h>
#include <stdlib.h>

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


/* Code for taking arguments from terminal appropriated from these sources:
http://stackoverflow.com/questions/498320/pass-arguments-into-c-program-from-command-line
http://stackoverflow.com/questions/17645447/how-to-pass-command-line-arguments-to-a-c-program?rq=1
*/
int main(int argc, char *argv[]) {
  int sz;
  unsigned char *data;

  // read the file into memory, then close it
  FILE *input_image = fopen("cup.bmp", "r");

  if (input_image == NULL) {
    printf("Error: problem opening file\n");
    return 0;
  }
  // get size of file
  /* Credit: Rob Walker, 2008. http://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c */
  fseek(input_image, 0L, SEEK_END);
  sz = ftell(input_image);
  fseek(input_image, 0L, SEEK_SET);

  // reserve memory for file data
  data = (unsigned char *) malloc(sz); 

  

  if (fread(data, sz, 1, input_image) != 1) {
    printf("Error: problem reading file\n");
    return 0;
  }

  fclose(input_image);
  
  int width = data[18] | data[19] << 8 | data[20] << 16 | data[21] << 24;
  printf("width: %d\n", width);

  int height = data[22] | data[23] << 8 | data[24] << 16 | data[25] << 24;
  printf("height: %d\n", height);


  int offset = data[10] | data[11] << 8 | data[12] << 16 | data[13] << 24;

  for (i=0;i<XDIM;i++) {  // set every pixel in the image based on bytes from the bmp file.
       for (j=0;j<YDIM;j++) {
           setcolorRGB(i, YDIM - j, data[pos + i*3 + j*XDIM*3 + 2], 
                                    data[pos + i*3 + j*XDIM*3 + 1], 
                                    data[pos + i*3 + j*XDIM*3 ]);   // note this striding will not work if the width is not a multiple of 4.
       }
    }



  return 0;

}
