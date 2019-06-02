#ifndef _COLOR_H_
#define _COLOR_H_

#include "../include/tuple.h"

class Color {
 public:
  float r;
  float g;
  float b;
  float a;

  Color( float _r, float _g, float _b, float _a = 1 ){
    r = _r; g = _g; b = _b; a = _a;
  }

  Color( Tuple t ){
    r = t.x; g = t.y; b = t.z; a = t.w;
  }

  // ------------------------------------------------------------------------------------------
  // operators
  // +
  Color operator + ( const Color& c ){
    return Color( r + c.r, g + c.g, b + c.b, a + c.a );
  }

  // -
  Color operator - ( const Color& c ){
    return Color( r - c.r, g - c.g, b - c.b, a - c.a );
  }

  // *
  Color operator * ( const float& f ){
    return Color( r * f, g * f, b * f, a * f );
  }

  Color operator * ( const Color& c ){
    return Color( r * c.r, g * c.g, b * c.b, a * c.a );
  }

};

#endif
