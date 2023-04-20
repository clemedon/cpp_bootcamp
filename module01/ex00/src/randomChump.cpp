// @author    Clément Vidon
// @created   230324 11:48:29  by  clem@spectre
// @modified  230420 18:27:37  by  clem@spectre
// @filename  randomChump.cpp

#include <string>

#include "Zombie.hpp"

void randomChump( std::string name ) {
  Zombie zm( name );

  zm.announce();
  return;
}
