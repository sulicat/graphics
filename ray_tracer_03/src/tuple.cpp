#include "../include/tuple.h"
#include <iostream>
#include <string>
#include <math.h>

Tuple::Tuple(){
  x = 0; y = 0; z = 0; w = 1;
}

Tuple::Tuple( float _x, float _y, float _z, float _w ){
  x = _x; y = _y; z = _z; w = _w;
}

float Tuple::length(){
  return sqrt(x*x + y*y + z*z + w*w);
}

float Tuple::magnitude(){
  return sqrt(x*x + y*y + z*z + w*w);
}

Tuple Tuple::normalize(){
  float len = this->magnitude();
  if( len > 0 ){
    float len_inverse = 1/len; // avoiding multiple divisions
    x = x * len_inverse;
    y = y * len_inverse;
    z = z * len_inverse;
    w = w * len_inverse;
  }
  return *this;
}

float Tuple::dot( Tuple v2 ){
  return x*v2.x + y*v2.y + z*v2.z + w*v2.w;
}

Tuple Tuple::cross( const Tuple &v2 ){
  return Tuple( y*v2.z - z*v2.y,
		z*v2.x - x*v2.z,
		x*v2.y - y*v2.x,
		0);
}

bool Tuple::isVector() const {
  if( w == 0.0 )
    return true;
  return false;
}

bool Tuple::isPoint() const {
  if( w != 0.0 )
    return true;
  return false;
}

void Tuple::toString(){
  std::cout << "Tuple\n";
  std::cout << "\t ( " << x << ", " << y << ", " << z << " )\n";
  std::cout << "\t len: " << this->length() << "\n";
}


// operators
std::ostream& operator << ( std::ostream& os, const Tuple &t ){
  if ( t.isVector() ){ os << "v: "; }else{ os << "p: "; }
  os << "(" << t.x << ", " << t.y << ", " <<  t.z << ", " << t.w << ")";
  return os;
}

Tuple Tuple::operator + ( const Tuple &a ){
  return Tuple( x+a.x, y+a.y, z+a.z, w+a.w );
}

Tuple Tuple::operator - ( const Tuple &a ){
  return Tuple( x-a.x, y-a.y, z-a.z, w-a.w );
}

Tuple Tuple::operator * ( const float &a ){
  return Tuple( x*a, y*a, z*a, w*a );
}

Tuple Tuple::operator / ( const float &a ){
  return Tuple( x/a, y/a, z/a, w/a );
}

Tuple Tuple::operator - (){
  return Tuple( -1*x, -1*y, -1*z, -1*w );
}


