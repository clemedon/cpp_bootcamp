// @author    Clément Vidon
// @created   230324 11:48:29  by  clem@spectre
// @modified  230324 11:48:35  by  clem@spectre
// @filename  randomChump.cpp

#include <string>

#include "Zombie.hpp"

void randomChump( std::string name ) {
  Zombie zm;

  zm.setName( name );
  zm.announce();
  return;
}
