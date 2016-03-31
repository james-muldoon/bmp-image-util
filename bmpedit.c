#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filters.h"


int parse_args(int argc, char *argv[], float *threshold, int *TF, int *SEPIA, char *output_file, char *input_file) {

  return 1;
}


int main(int argc, char *argv[]) {
  int sz;
  float threshold;
  unsigned char *data;
  char *output_file = NULL;
  char *input_file = NULL;
  int TF, SEPIA;

    // Set variables to defaults
  output_file = DEF_OUTPUT_FILE;
  TF = DISABLED;
  SEPIA = DISABLED;


  // Read through the command line arguments and set variables accordingly
  while (argc > 1) {
    if (argv[1][0] == '-') {
      switch (argv[1][1]) {
          case 'o':
            output_file = argv[2];
            --argc;
            ++argv; 
            break;
          case 't':
            threshold = (float) atof(argv[2]);
            TF = ENABLED;
            --argc;
            ++argv;
            break;
          case 's':
            SEPIA = ENABLED;
            break;
          case 'h':
            printf("Usage: bmpedit [OPTIONS...] [input.bmp] \n \n DESCRIPTION: This program does simple edits of BMP image files. \n When the program runs it first prints out the width and the height of the input image within the BMP file. \n  Once this is done if there is a filter (or sequence of filters) then they are applied to the image.  \n The resulting image is also stored using BMP format into an output file.  \n Without any filters only the width and height of the image is output. \n \n  OPTIONS: \n -o FILE      Sets the output file for modified images (default output file is \"out.bmp\"). \n -t 0.0-1.0   Apply a threshold filter to the image with a threshold the threshold value given. \n -s           Applies a sepia filter to the image. \n -h           Displays this usage message.\n");
            return 0;
      } 
    } else {
      // if there is no option selected, program will assume that it is being given 
      // the name of the input file
      // check that the user has not given multiple input file names
      if (input_file == NULL) {
        input_file = argv[1];
      } else {
        printf("Error: more than one input file given\n");
        return 0;
      }

    }
    --argc;
    ++argv;
  }

  // read the file into memory
  FILE *input_image = fopen(input_file, "r");

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
  printf("Image width: %d\n", width);
  int height = data[22] | data[23] << 8 | data[24] << 16 | data[25] << 24;
  printf("Image height: %d\n", height);

  int offset = data[10] | data[11] << 8 | data[12] << 16 | data[13] << 24;

  if (TF == ENABLED) {
    apply_threshold(data, threshold, width, height, offset);
  }
  if (SEPIA == ENABLED) {
    apply_sepia(data, width, height, offset);
  }

  // check the user is not trying to (or unintentionally) overwrite the original file
  if (strcmp(input_file, output_file) == 0) {
    printf("File output name cannot be the same as the input\n");
    return 0;
  }

  // write data to the output file
  // only do this if some modification has been made to the image.
  if ((TF == ENABLED) || (SEPIA == ENABLED)) {
  FILE *fp = fopen(output_file, "w+");
  fwrite(data, 1, sz, fp);
  fclose(fp);
  }

  return 0;
}

