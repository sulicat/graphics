#ifndef _TRACER_H_
#define _TRACER_H_

#include "tuple.h"

class Tracer{
 public:
  static Tuple Point( float x, float y, float z );
  static Tuple Vector( float x, float y, float z );
};

#endif
