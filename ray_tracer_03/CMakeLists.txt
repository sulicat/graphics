cmake_minimum_required ( VERSION 2.8.11 )
project ( katRayTrace )

SET(CMAKE_CXX_FLAGS "-std=c++0x")

file( GLOB_RECURSE src src/* )
file( GLOB_RECURSE include include/* )

include_directories(include)

find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})

#--------------------------------------------------------------------------------
# unit tests
add_executable( unitTest
  ${src}
  ${include}
  src_entrypnt/main_test.cpp
  )

target_link_libraries(unitTest ${GTEST_LIBRARIES} pthread)

#--------------------------------------------------------------------------------
#projectile test
add_executable( projectile
  ${src}
  ${include}
  src_entrypnt/main_projectile.cpp
  )


#--------------------------------------------------------------------------------
# ray tracer
add_executable( RayTracer
  ${src}
  ${include}
  src_entrypnt/main_ray_tracer.cpp
  )
