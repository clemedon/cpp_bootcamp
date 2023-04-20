// @author    Clément Vidon
// @created   230324 11:48:26  by  clem@spectre
// @modified  230420 18:27:04  by  clem@spectre
// @filename  newZombie.cpp

#include <string>

#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
  Zombie* zm;

  zm = new Zombie( name );
  return zm;
}
