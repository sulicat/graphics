#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "tuple.h"

class Projectile{
 public:
  Tuple pos;
  Tuple vel;

  Projectile( Tuple _pos, Tuple _vel );
  std::string toString();

};

#endif
