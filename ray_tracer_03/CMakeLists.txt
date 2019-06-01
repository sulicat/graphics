cmake_minimum_required ( VERSION 2.8.11 )
project ( katRayTrace )

SET(CMAKE_CXX_FLAGS "-std=c++0x")

file( GLOB_RECURSE src src/* )
file( GLOB_RECURSE include include/* )
file( GLOB_RECURSE srcTests src/* )
file( GLOB_RECURSE tests tests/* )

list(FILTER src EXCLUDE REGEX ".*test.cpp$")
list(FILTER srcTests EXCLUDE REGEX ".*main.cpp$")

#target_include_directories( test PRIVATE include/ )
include_directories(include)


find_package( GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories( test  )

# unit tests
add_executable( test
  ${srcTests}
  ${include}
  ${tests}
  )

#projectile test

# ray tracer
add_executable( katTracer
  ${src}
  ${include}
  ${tests}
  )

target_link_libraries(test ${GTEST_LIBRARIES} pthread)
