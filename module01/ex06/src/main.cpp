// @author    Clément Vidon
// @created   230324 12:02:31  by  clem@spectre
// @modified  230324 12:02:33  by  clem@spectre
// @filename  main.cpp

#include <iostream>
#include <string>

#include "Harl.hpp"

int main( int argc, char** argv ) {
  Harl harl;

  if( argc == 2 ) {
    harl.complain( argv[1] );
  } else {
    return 1;
  }
  return 0;
}
