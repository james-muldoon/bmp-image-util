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
  int sz, clrR, clrG, clrB;
  float ratio, threshold; 
  unsigned char *data;
  int i, j;

  threshold = 0.5;

  // read the file into memory
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

  
  // read the file into memory
  if (fread(data, sz, 1, input_image) != 1) {
    printf("Error: problem reading file\n");
    return 0;
  }

  fclose(input_image);
  
  // get information from the bmp header
  int width = data[18] | data[19] << 8 | data[20] << 16 | data[21] << 24;
  printf("width: %d\n", width);
  int height = data[22] | data[23] << 8 | data[24] << 16 | data[25] << 24;
  printf("height: %d\n", height);


  int offset = data[10] | data[11] << 8 | data[12] << 16 | data[13] << 24;

  for (i=0;i<width;i++) {  
       for (j=0;j<height;j++) {
            clrR = data[offset + i*3 + j*width*3 + 2]; 
            clrG = data[offset + i*3 + j*width*3 + 1]; 
            clrB = data[offset + i*3 + j*width*3 ]; 

            ratio = ((clrR + clrG + clrB) / 3 / 255.0f); 
            
            if (ratio < threshold) {
              data[offset + i*3 + j*width*3 + 2] = 0;
              data[offset + i*3 + j*width*3 + 1] = 0;
              data[offset + i*3 + j*width*3    ] = 0;
            } else {
              data[offset + i*3 + j*width*3 + 2] = 255;
              data[offset + i*3 + j*width*3 + 1] = 255;
              data[offset + i*3 + j*width*3    ] = 255;
            }
       }
    }

    FILE *fp = fopen("test.bmp", "w+");
    fwrite(data, 1, sz, fp);
    fclose(fp);


  return 0;

}
