#include "../include/Tracer.h"


Tuple Tracer::Point( float x, float y, float z ){
  return Tuple( x, y, z, 1.0 );
}

Tuple Tracer::Vector( float x, float y, float z ){
  return Tuple( x, y, z, 0.0 );
}


