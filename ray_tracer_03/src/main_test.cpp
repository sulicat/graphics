#include <iostream>
#include "../include/Tracer.h"
#include <gtest/gtest.h>
#include <math.h>

// Tuple tests
TEST( TupleTest, createW0){
  Tuple t0(4.3, -4.2, 3.1, 0.0);
  EXPECT_FLOAT_EQ( t0.x, 4.3 );
  EXPECT_FLOAT_EQ( t0.y, -4.2 );
  EXPECT_FLOAT_EQ( t0.z, 3.1 );
  EXPECT_FLOAT_EQ( t0.w, 0.0 );
  EXPECT_EQ( t0.isPoint(), false );
  EXPECT_EQ( t0.isVector(), true );

}

TEST( TupleTest, createW1){
  Tuple t0(4.3, -4.2, 3.1, 1.0);
  EXPECT_FLOAT_EQ( t0.x, 4.3 );
  EXPECT_FLOAT_EQ( t0.y, -4.2 );
  EXPECT_FLOAT_EQ( t0.z, 3.1 );
  EXPECT_FLOAT_EQ( t0.w, 1.0 );
  EXPECT_EQ( t0.isPoint(), true );
  EXPECT_EQ( t0.isVector(), false );
}

TEST( TupleTest, createPoint){
  Tuple p = Tracer::Point(4, -4, 3);
  EXPECT_FLOAT_EQ( p.x, 4 );
  EXPECT_FLOAT_EQ( p.y, -4 );
  EXPECT_FLOAT_EQ( p.z, 3 );
  EXPECT_FLOAT_EQ( p.w, 1.0 );
}

TEST( TupleTest, createVector){
  Tuple p = Tracer::Vector(4, -4, 3);
  EXPECT_FLOAT_EQ( p.x, 4 );
  EXPECT_FLOAT_EQ( p.y, -4 );
  EXPECT_FLOAT_EQ( p.z, 3 );
  EXPECT_FLOAT_EQ( p.w, 0.0 );
}

TEST( TupleTest, Sum){
  Tuple t0(3, 2, 1);
  Tuple t1(5, 6, 7);
  Tuple p = t0 - t1;
  EXPECT_FLOAT_EQ( p.x, -2 );
  EXPECT_FLOAT_EQ( p.y, -4 );
  EXPECT_FLOAT_EQ( p.z, -6);
  EXPECT_EQ( p.isPoint(), false );
  EXPECT_EQ( p.isVector(), true );
}


TEST( TupleTest, subtractZero){
  Tuple t0(1, -2, 3, -4);
  Tuple zero( 0, 0, 0, 0 );
  Tuple p = zero-t0;
  EXPECT_FLOAT_EQ( p.x, -1 );
  EXPECT_FLOAT_EQ( p.y,  2 );
  EXPECT_FLOAT_EQ( p.z, -3 );
  EXPECT_FLOAT_EQ( p.w,  4 );
  EXPECT_EQ( p.isPoint(), true );
  EXPECT_EQ( p.isVector(), false );
}


TEST( TupleTest, Negate){
  Tuple t0(1, -2, 3, -4);
  Tuple p = -t0;
  EXPECT_FLOAT_EQ( p.x, -1 );
  EXPECT_FLOAT_EQ( p.y,  2 );
  EXPECT_FLOAT_EQ( p.z, -3 );
  EXPECT_FLOAT_EQ( p.w,  4 );
  EXPECT_EQ( p.isPoint(), true );
  EXPECT_EQ( p.isVector(), false );
}


TEST( TupleTest, MultiplyScaler){
  Tuple t0(1, -2, 3, -4);
  t0 = t0 * 3.5;
  EXPECT_FLOAT_EQ( t0.x, 3.5  );
  EXPECT_FLOAT_EQ( t0.y, -7   );
  EXPECT_FLOAT_EQ( t0.z, 10.5 );
  EXPECT_FLOAT_EQ( t0.w, -14  );
  EXPECT_EQ( t0.isPoint(), true );
  EXPECT_EQ( t0.isVector(), false );

  t0 = Tuple(1, -2, 3, -4);
  t0 = t0 * 0.5;
  EXPECT_FLOAT_EQ( t0.x, 0.5  );
  EXPECT_FLOAT_EQ( t0.y, -1   );
  EXPECT_FLOAT_EQ( t0.z, 1.5  );
  EXPECT_FLOAT_EQ( t0.w, -2   );
  EXPECT_EQ( t0.isPoint(), true );
  EXPECT_EQ( t0.isVector(), false );
}


TEST( TupleTest, DivideScaler){
  Tuple t0(1, -2, 3, -4);
  t0 = t0 / 2;
  EXPECT_FLOAT_EQ( t0.x, 0.5  );
  EXPECT_FLOAT_EQ( t0.y, -1   );
  EXPECT_FLOAT_EQ( t0.z, 1.5  );
  EXPECT_FLOAT_EQ( t0.w, -2   );
  EXPECT_EQ( t0.isPoint(), true );
  EXPECT_EQ( t0.isVector(), false );
}


TEST( TupleTest, Magnitude){
  Tuple t0 = Tracer::Vector(1, 0, 0);
  EXPECT_FLOAT_EQ( t0.magnitude(), 1  );
  EXPECT_EQ( t0.isPoint(), false );
  EXPECT_EQ( t0.isVector(), true );

  t0 = Tracer::Vector(0, 1, 0);
  EXPECT_FLOAT_EQ( t0.magnitude(), 1  );
  EXPECT_EQ( t0.isPoint(), false );
  EXPECT_EQ( t0.isVector(), true );

  t0 = Tracer::Vector(0, 0, 1);
  EXPECT_FLOAT_EQ( t0.magnitude(), 1  );
  EXPECT_EQ( t0.isPoint(), false );
  EXPECT_EQ( t0.isVector(), true );

  t0 = Tracer::Vector(1, 2, 3);
  EXPECT_FLOAT_EQ( t0.magnitude(), sqrt(14)  );
  EXPECT_EQ( t0.isPoint(), false );
  EXPECT_EQ( t0.isVector(), true );

  t0 = Tracer::Vector(-1, -2, -3);
  EXPECT_FLOAT_EQ( t0.magnitude(), sqrt(14)  );
  EXPECT_EQ( t0.isPoint(), false );
  EXPECT_EQ( t0.isVector(), true );
}



TEST( TupleTest, Normalize){
  Tuple t0 = Tracer::Vector(4, 0, 0);
  t0 = t0.normalize();
  EXPECT_FLOAT_EQ( t0.x, 1  );
  EXPECT_FLOAT_EQ( t0.y, 0   );
  EXPECT_FLOAT_EQ( t0.z, 0  );
  EXPECT_FLOAT_EQ( t0.w, 0   );
  EXPECT_EQ( t0.isVector(), true );

  t0 = Tracer::Vector(1, 2, 3);
  t0 = t0.normalize();
  EXPECT_FLOAT_EQ( t0.x, 0.26726124  );
  EXPECT_FLOAT_EQ( t0.y, 0.53452247  );
  EXPECT_FLOAT_EQ( t0.z, 0.80178368  );
  EXPECT_FLOAT_EQ( t0.w, 0  );
  EXPECT_FLOAT_EQ( t0.magnitude(), 1  );
  EXPECT_EQ( t0.isVector(), true );

}


TEST( TupleTest, Dot){
  Tuple t0 = Tracer::Vector(1, 2, 3);
  Tuple t1 = Tracer::Vector(2, 3, 4);

  EXPECT_FLOAT_EQ( t0.dot(t1), 20 );
}


TEST( TupleTest, Coss){
  Tuple t0 = Tracer::Vector(1, 2, 3);
  Tuple t1 = Tracer::Vector(2, 3, 4);
  Tuple cross = t0.cross(t1);

  EXPECT_FLOAT_EQ( cross.x, -1 );
  EXPECT_FLOAT_EQ( cross.y, 2 );
  EXPECT_FLOAT_EQ( cross.z, -1 );
  EXPECT_EQ( cross.isVector(), true );

  cross = t1.cross(t0);

  EXPECT_FLOAT_EQ( cross.x, 1 );
  EXPECT_FLOAT_EQ( cross.y, -2 );
  EXPECT_FLOAT_EQ( cross.z, 1 );
  EXPECT_EQ( cross.isVector(), true );

}



int main( int argc, char**argv ){
  std::cout << "MAIN TEST ENTRY POINT\n";
  testing::InitGoogleTest( &argc, argv );
  return RUN_ALL_TESTS();
}
