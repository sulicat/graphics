#define GL_GLEXT_PROTOTYPES

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define MAX_ITER 10e8

#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"

#include "dataType.hpp"

/* ******************************************************************************** */

int window_size_x = 1280;
int window_size_y = 720;
char *OUTPUT_DATA;

/* ******************************************************************************** */

int main( int argc, char** argv ){
  OUTPUT_DATA = new char[window_size_x*window_size_y*3];


  Vec<float> testV1( 0, 100, 0 );
  Vec<float> testV2( 100, 0, 0 );

  testV1.toString();
  testV1.normalize();
  testV1.toString();

  std::cout << "------------------------------------------------------------------------------------------\n";

  testV2.toString();

  std::cout << "------------------------------------------------------------------------------------------\n";

  std::cout << "Dot: " << testV1.dot(testV2) << "\n";
  testV2.normalize();
  std::cout << "Dot: " << testV1.dot(testV2) << "\n";

  std::cout << "Cross \n";
  testV1.cross(testV2).toString();
  testV2.cross(testV1).toString();

  (testV1+testV2).toString();
  (testV1-testV2).toString();
  (testV2-testV1).toString();
  (testV1*50).toString();


  // ----------------------------------------------------------------------------------------------------

  Mat44<float> m1 = Mat44<float>();
  m1[0][0] = 3;
  m1[0][1] = 3;
  m1[0][2] = 3;
  m1.toString();
  std::cout << m1[0][0] << "\n";


  Mat44<float> m2 = Mat44<float>();
  m2[0][0] = 2;
  m2[0][1] = 2;
  m2[2][3] = 4;
  m2[1][3] = 4;

  m2.toString();
  std::cout << m1[0][0] << "\n";

  (m1*m2).toString();


  (m1*m2).transpose().toString();

  (m1*m2).transpose().inverse().toString();


  // matric mult speed check
  clock_t start = clock();
  Vec<float> v(1, 2, 3);
  Mat44<float> M;
  float *tmp = &M.m[0][0];

  for (int i = 0; i < 16; i++) *(tmp + i) = drand48();

  for (int i = 0; i < MAX_ITER; ++i) {
    Vec<float> vt = M.multVec(v);
  }

  fprintf(stderr, "Clock time %f\n", (clock() - start) / float(CLOCKS_PER_SEC));









  int red = 0, green = 0, blue = 0;
  for( int i = 0; i < window_size_x*window_size_y*3 - 3; i+= 3 ){

    red = 255;
    green = 0;
    blue = 255;

    OUTPUT_DATA [i]     = red;
    OUTPUT_DATA [i + 1] = green;
    OUTPUT_DATA [i + 2] = blue;
  }

  stbi_write_bmp("test.bmp", window_size_x, window_size_y, 3, OUTPUT_DATA);

  return 0;
}
