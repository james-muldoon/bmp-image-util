#ifndef FILTERS_H
#define FILTERS_H

#include <stdlib.h>

#define DEF_OUTPUT_FILE "out.bmp";
#define ENABLED 1
#define DISABLED 0

void apply_threshold(unsigned char *data, float threshold, int width, int height, int offset);

void apply_sepia(unsigned char *data, int width, int height, int offset);


#endif