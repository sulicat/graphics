/* ***************************************************************************************** */
#include <iostream>
#include <string>


class Vector2f{
public:
  float x;
  float y;
  Vector2f(){}
  Vector2f( float _x,float _y ){
    x = _x; y = _y;
  }

  std::string toString(){
    return std::string( "( " + std::to_string(x) + ", " + std::to_string(y) + " )");
  }

};


class Vector3f{
public:
  float x;
  float y;
  float z;
  Vector3f(){}
  Vector3f( float _x,float _y,float _z ){
    x = _x; y = _y; z = _z;
  }

  Vector3f operator + ( Vector3f a){
    return Vector3f(x+a.x, y+a.y, z+a.z);
  }

  std::string toString(){
    return std::string( "( " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + " )");
  }

};



Vector3f cross( Vector3f a, Vector3f b){
  Vector3f out;
  out.x = (a.y * b.z) - (a.z * b.y);
  out.y = (a.z * b.x) - (a.x * b.z);
  out.z = (a.x * b.y) - (a.y * b.x);
  return out;
}


/* ***************************************************************************************** */

class Point{
public:
  std::vector< float > pos;

  Point(){}
  Point( float x, float y, float z ){
    pos.push_back( x );
    pos.push_back( y );
    pos.push_back( z );
  }

  float* arr(){
    float* out = &pos[0];
    return out;
  }

  float x(){ return pos[0]; }
  float y(){ return pos[1]; }
  float z(){ return pos[2]; }

};

/* ***************************************************************************************** */

class Plane{
public:
  Vector3f normal;
  Vector3f a;
  Vector3f b;
  Vector3f pos;

  Plane(){}
  Plane( Vector3f _a, Vector3f _b ){
    a = _a;
    b = _b;
    normal = cross(a,b);
    pos = Vector3f(0,0,0);
  }

  Plane( Vector3f _a, Vector3f _b, Vector3f _pos ){
    a = _a + _pos;
    b = _b + _pos;
    normal = cross(a,b);
    pos = _pos;
  }

  std::string toString(){
    std::string out;
    out += "Plane: \n";
    out += "\t A \t= " + a.toString() + "\n";
    out += "\t B \t= " + b.toString() + "\n";
    out += "\t N \t= " + normal.toString() + "\n";
    out += "\t Pos \t= " + pos.toString() + "\n";
    return out;
  }

};

/* ***************************************************************************************** */

class Rect{
public:
  // will always lie in a plane
  // then it will have a position
  // as well as a size
  Plane plane;
  Vector2f size;

  Rect(){}
  Rect( Vector3f _pos, Vector2f _s ){
    plane.pos = _pos;
    size = _s;
  }

  Rect( Vector3f _pos, Vector2f _s, Plane _p ){
    plane = _p;
    plane.pos = _pos;
    size = _s;
  }

  std::string toString(){
    std::string out;
    out += "Rect: \n";
    out += "\t size: \t" + size.toString() + "\n";
    out += plane.toString();
    return out;

  }

};

/* ***************************************************************************************** */

class Ray{
public:
  // we will define the ray in the form of
  // (s) + t(d)
  // (x0,y0,z0) + t(x1-x0, y1-y0, z1-z0)

  Vector3f s;
  Vector3f d;

  Ray( Vector3f p0, Vector3f p1 ){
    s = p0;
    d = Vector3f(
	      p1.x - p0.x,
	      p1.y - p0.y,
	      p1.z - p0.z
	      );
  }

  Vector3f findIntersection( Plane p ){
    Vector3f out;
    // s + td  
    return out;
  }



};
