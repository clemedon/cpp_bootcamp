// @author    Clément Vidon
// @created   230324 11:48:44  by  clem@spectre
// @modified  230324 11:49:32  by  clem@spectre
// @filename  Zombie.cpp

#include <iostream>
#include <string>

#include "Zombie.hpp"

Zombie::Zombie( void ) {
  return;
}

Zombie::~Zombie( void ) {
  std::cout << _name << " has been destroyed";
  std::cout << std::endl;
  return;
}

void Zombie::announce( void ) const {
  std::cout << _name << ": BraiiiiiiinnnzzzZ...";
  std::cout << std::endl;
  return;
}

void Zombie::setName( std::string name ) {
  _name = name;
  return;
}
