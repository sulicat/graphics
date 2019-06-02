#include "../include/projectile.h"

Projectile::Projectile( Tuple _pos, Tuple _vel ){
  pos = _pos;
  vel = _vel;
}

std::string Projectile::toString(){
  std::cout << "Projectile:\n";
  std::cout << "  pos:\t" << pos << "\n";
  std::cout << "  vel:\t" << vel << "\n";
  return "";
}
