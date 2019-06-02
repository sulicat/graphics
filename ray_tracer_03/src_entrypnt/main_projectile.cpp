#include <iostream>
#include "../include/Tracer.h"
#include <gtest/gtest.h>
#include <math.h>


int main( int argc, char** argv ){

  Projectile p( Tracer::Point(0,0,0), Tracer::Vector(1,0,0) );
  p.toString();

  Environment e( Tracer::Vector(0, -0.1, 0), Tracer::Vector(0, 0, 0.01) );
  e.toString();

  return 1;
}
