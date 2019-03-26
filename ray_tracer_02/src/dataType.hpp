/* ***************************************************************************************** */
#include <iostream>
#include <string>

#define ROW_MAJOR_ORDER


template <typename T>
class Vec{

public:
  T x;
  T y;
  T z;

  Vec(){
    x = 0; y = 0; z = 0;
  }

  Vec( T _x, T _y, T _z ){
    x = _x; y = _y; z = _z;
  }

  // common funcs
  T length(){
    return sqrt(x*x + y*y + z*z);
  }

  void normalize(){
    T len = this->length();
    if( len > 0 ){
      T len_inverse = 1/len; // avoiding multiple divisions
      x = x * len_inverse;
      y = y * len_inverse;
      z = z * len_inverse;
    }
  }

  T dot( Vec<T> v2 ){
    return x*v2.x + y*v2.y + z*v2.z;
  }

  Vec<T> cross( const Vec<T> &v2 ){
    return Vec<T>( y*v2.z - z*v2.y,
		   z*v2.x - x*v2.z,
		   x*v2.y - y*v2.x );
  }

  void toString(){
    std::cout << "Vector\n";
    std::cout << "\t ( " << x << ", " << y << ", " << z << " )\n";
    std::cout << "\t len: " << this->length() << "\n";
  }

  // operators
  Vec<T> operator + ( const Vec<T> &a ){
    return Vec<T>( x+a.x, y+a.y, z+a.z );
  }

  Vec<T> operator - ( const Vec<T> &a ){
    return Vec<T>( x-a.x, y-a.y, z-a.z );
  }

  Vec<T> operator * ( const T &a ){
    return Vec<T>( x*a, y*a, z*a );
  }

};



// ----------------------------------------------------------------------------------------------------


template <typename T>
class Mat44{

public:
  T m[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}; // identity matrix

  Mat44(){
  }

  void toString(){
    std::cout << "Matrix: \n";
    for( int r = 0; r < 4; r++ ){
      std::cout << "\t";
      for( int c = 0; c < 4; c++ ){
	std::cout << m[r][c] << "\t";
      }
      std::cout << "\n";
    }
  }


  Mat44 (T a, T b, T c, T d, T e, T f, T g, T h,
	 T i, T j, T k, T l, T x, T n, T o, T p)
  {
    m[0][0] = a;
    m[0][1] = b;
    m[0][2] = c;
    m[0][3] = d;
    m[1][0] = e;
    m[1][1] = f;
    m[1][2] = g;
    m[1][3] = h;
    m[2][0] = i;
    m[2][1] = j;
    m[2][2] = k;
    m[2][3] = l;
    m[3][0] = x;
    m[3][1] = n;
    m[3][2] = o;
    m[3][3] = p;
  }

  T* operator [] ( int i ){ return m[i]; }

  Mat44 operator * ( Mat44<T> &B ){
    Mat44<T> output;

    for( int r = 0; r < 4; r++ ){
      for( int c = 0; c < 4; c++ ){
	output.m[r][c] = m[r][0] * B[0][c] +
	  m[r][1] * B[1][c] +
	  m[r][2] * B[2][c] +
	  m[r][3] * B[3][c];
      }
    }
    return output;
  }


  // this is a multiplication that adds a homogenous point w=1 to the vector, then normalizes the vector making sure w always =1
  // this is used for translation purposes
  Vec<T> multVec( Vec<T> &src  ){
    Vec<T> dst;
    #ifdef ROW_MAJOR_ORDER
    dst.x = src.x*m[0][0] + src.y*m[1][0] + src.z*m[2][0] + m[3][0];
    dst.y = src.x*m[0][1] + src.y*m[1][1] + src.z*m[2][1] + m[3][1];
    dst.z = src.x*m[0][2] + src.y*m[1][2] + src.z*m[2][2] + m[3][2];
    T w   = src.x*m[0][3] + src.y*m[1][3] + src.z*m[2][3] + m[3][3];
    #else
    dst.x = src.x*m[0][0] + src.y*m[0][1] + src.z*m[0][2] + m[0][3];
    dst.y = src.x*m[1][0] + src.y*m[1][1] + src.z*m[1][2] + m[1][3];
    dst.z = src.x*m[2][0] + src.y*m[2][1] + src.z*m[2][2] + m[2][3];
    T w   = src.x*m[3][0] + src.y*m[3][1] + src.z*m[3][2] + m[3][3];
    #endif

    if( w != 1 && w != 0 ){
      dst.x = dst.x / w;
      dst.y = dst.y / w;
      dst.z = dst.z / w;
    }
    return dst;
  }



  // this is a multiplaction without the translation
  // ie: there is no homogenous coordinate in this transormation, therefore we cannot perform a translation
  // used to multiply vectors (not points)
  Vec<T> multDir( Vec<T> &src ){
    Vec<T> dst;
    #ifdef ROW_MAJOR_ORDER
    dst.x = src.x*m[0][0] + src.y*m[1][0] + src.z*m[2][0];
    dst.y = src.x*m[0][1] + src.y*m[1][1] + src.z*m[2][1];
    dst.z = src.x*m[0][2] + src.y*m[1][2] + src.z*m[2][2];
    #else
    dst.x = src.x*m[0][0] + src.y*m[0][1] + src.z*m[0][2];
    dst.y = src.x*m[1][0] + src.y*m[1][1] + src.z*m[1][2];
    dst.z = src.x*m[2][0] + src.y*m[2][1] + src.z*m[2][2];
    #endif
    return dst;
  }


  Mat44<T> transpose(){
    Mat44<T> out;
    for( int r = 0; r < 4; r++ )
      for( int c = 0; c < 4; c++ )
	out[c][r] = m[r][c];

    return out;
  }


  /* Matrix inverse.... not my code, copied from scratchpixel */
  Mat44 inverse(){
    int i, j, k;
    Mat44 s;
    Mat44 t (*this);

    // Forward elimination
    for (i = 0; i < 3 ; i++) {
      int pivot = i;

      T pivotsize = t[i][i];

      if (pivotsize < 0)
	pivotsize = -pivotsize;

      for (j = i + 1; j < 4; j++) {
	T tmp = t[j][i];

	if (tmp < 0)
	  tmp = -tmp;

	if (tmp > pivotsize) {
	  pivot = j;
	  pivotsize = tmp;
	}
      }

      if (pivotsize == 0) {
	// Cannot invert singular matrix
	return Mat44();
      }

      if (pivot != i) {
	for (j = 0; j < 4; j++) {
	  T tmp;

	  tmp = t[i][j];
	  t[i][j] = t[pivot][j];
	  t[pivot][j] = tmp;

	  tmp = s[i][j];
	  s[i][j] = s[pivot][j];
	  s[pivot][j] = tmp;
	}
      }

      for (j = i + 1; j < 4; j++) {
	T f = t[j][i] / t[i][i];

	for (k = 0; k < 4; k++) {
	  t[j][k] -= f * t[i][k];
	  s[j][k] -= f * s[i][k];
	}
      }
    }

    // Backward substitution
    for (i = 3; i >= 0; --i) {
      T f;

      if ((f = t[i][i]) == 0) {
	// Cannot invert singular matrix
	return Mat44();
      }

      for (j = 0; j < 4; j++) {
	t[i][j] /= f;
	s[i][j] /= f;
      }

      for (j = 0; j < i; j++) {
	f = t[j][i];

	for (k = 0; k < 4; k++) {
	  t[j][k] -= f * t[i][k];
	  s[j][k] -= f * s[i][k];
	}
      }
    }

    return s;
  }

  // \brief set current matrix to its inverse
  const Mat44<T>& invert(){
    *this = inverse();
    return *this;
  }

};
