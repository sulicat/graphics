#include "../include/environment.h"

Environment::Environment( Tuple _g, Tuple _w ){
  gravity = _g;
  wind = _w;
}

std::string Environment::toString(){
  std::cout << "Environment: \n  G:\t" << gravity << "\n  W:\t" << wind << "\n";
  return "";
}
