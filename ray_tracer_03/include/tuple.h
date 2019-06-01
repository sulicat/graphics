#ifndef _TUPLE_H_
#define _TUPLE_H_

#include <iostream>
#include <string>

#define ROW_MAJOR_ORDER


class Tuple{
 public:
  float x;
  float y;
  float z;
  float w;

  Tuple();
  Tuple( float _x, float _y, float _z, float w = 1.0 );

  // common funcs
  float length();
  float magnitude();
  Tuple normalize();
  float dot( Tuple v2 );
  bool isVector();
  bool isPoint();

  Tuple cross( const Tuple &v2 );
  void toString();
  // operators
  Tuple operator + ( const Tuple &a );
  Tuple operator - ( const Tuple &a );
  Tuple operator * ( const float &a );
  Tuple operator / ( const float &a );
  Tuple operator - ();
};

#endif
