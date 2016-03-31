#include "filters.h"
#include <stdio.h>

void apply_threshold(unsigned char *data, float threshold, int width, int height, int offset) {
  int clrR, clrG, clrB;
  float ratio;
  int i, j;

  for (i=0;i<width;i++) {  
       for (j=0;j<height;j++) {
          clrR = data[offset + i*3 + j*width*3 + 2];
          clrG = data[offset + i*3 + j*width*3 + 1]; 
          clrB = data[offset + i*3 + j*width*3 ]; 

          ratio = (float)((clrR + clrG + clrB) / (float)3.0f / (float)255.0f);
         
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
}

// credit Max Galkin http://stackoverflow.com/questions/1061093/how-is-a-sepia-tone-created
void apply_sepia(unsigned char *data, int width, int height, int offset) {
  int clrR, clrG, clrB, newR, newG, newB;
  int i, j;

  for (i=0;i<width;i++) {  
       for (j=0;j<height;j++) {
          clrR = data[offset + i*3 + j*width*3 + 2];
          clrG = data[offset + i*3 + j*width*3 + 1]; 
          clrB = data[offset + i*3 + j*width*3 ];

          if ((newR = (clrR * .393) + (clrG *.769) + (clrB * .189)) > 255) {
            data[offset + i*3 + j*width*3 + 2] = 255;
          } else {
            data[offset + i*3 + j*width*3 + 2] = newR;
          }

          if ((newG = (clrR * .349) + (clrG *.686) + (clrB * .168)) > 255) {
            data[offset + i*3 + j*width*3 + 2] = 255;
          } else {
            data[offset + i*3 + j*width*3 + 2] = newG;
          }

          if ((newB = (clrR * .272) + (clrG *.534) + (clrB * .131)) > 255) {
            data[offset + i*3 + j*width*3 + 2] = 255;
          } else {
            data[offset + i*3 + j*width*3 + 2] = newB;
          }
       }
    }
}

