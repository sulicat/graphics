#define GL_GLEXT_PROTOTYPES

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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

int index( int r, int c ){
  return (r*window_size_x + c)*3;
}

float yFromR( int r ){
  float temp = ((float)r)/window_size_y;
  return temp-0.5;
}

float xFromC( int c ){
  float temp = ((float)c)/window_size_x;
  return temp-0.5;
}


/* ******************************************************************************** */

int main( int argc, char** argv ){
  OUTPUT_DATA = new char[window_size_x*window_size_y*3];


  Plane plane = Plane( Vector3f( 1, 0, 0 ), Vector3f( 0, 1, 0 ), Vector3f( 0, 0, 1 ) );
  std::cout << plane.toString() << "\n";

  std::cout << "--------------------------------------------------------------------------------\n";

  Rect rect = Rect( Vector3f( 0.1, 0.1, 3 ), Vector2f( 0.5, 0.5 ), plane );
  std::cout << rect.toString() << "\n";




  std::cout << "--------------------------------------------------------------------------------\n";

  Ray ray = Ray( Vector3f( 0.0, 0.5, 0.0 ),
		 Vector3f( 0.0, 0.5, 0.5 ) );
  Vector3f point = ray.findIntersection( plane );
  std::cout << point.toString() << "\n";

  std::cout << "--------------------------------------------------------------------------------\n";


  /*
  // for ths raytracer we will make an orthographic projection
  // for every pixel
  for( int r = 0; r <  window_size_y; r += 1 ){
    for( int c = 0; c <  window_size_x; c += 1 ){
      // we will generate a ray for every pixel
      // the ray is going to run parallel to the normal of the viewport
      Ray ray( Point( xFromC(c), yFromR(r) ,0),
	       Point( xFromC(c), yFromR(r) ,1) );

    }
  }
  */

  //int stbi_write_bmp(char const *filename, int w, int h, int comp, const void *data);
  stbi_write_bmp("test.bmp", window_size_x, window_size_y, 3, OUTPUT_DATA);


  return 0;
}
