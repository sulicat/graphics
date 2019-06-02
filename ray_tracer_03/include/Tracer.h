#ifndef _TRACER_H_
#define _TRACER_H_

#include "tuple.h"
#include "projectile.h"
#include "environment.h"
#include "color.h"


class Tracer{
 public:
  static Tuple Point( float x, float y, float z );
  static Tuple Vector( float x, float y, float z );
  static Tuple Color( float r, float g, float v );
};

#endif
