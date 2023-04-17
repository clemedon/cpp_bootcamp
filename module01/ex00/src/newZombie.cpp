// @author    Clément Vidon
// @created   230324 11:48:26  by  clem@spectre
// @modified  230324 11:48:28  by  clem@spectre
// @filename  newZombie.cpp

#include <string>

#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
  Zombie* zm;

  zm = new Zombie();
  zm->setName( name );
  return zm;
}
