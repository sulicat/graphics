#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include "../include/tuple.h"

class Environment{
 public:
  Tuple gravity;
  Tuple wind;

  Environment( Tuple _g, Tuple _w );
  std::string toString();
};

#endif
