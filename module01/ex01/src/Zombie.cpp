// @author    Clément Vidon
// @created   230324 11:52:25  by  clem@spectre
// @modified  230324 11:52:27  by  clem@spectre
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

void Zombie::setName( std::string name ) {
  _name = name;
  return;
}

void Zombie::announce( void ) {
  std::cout << _name << " : BraiiiiiiinnnzzzZ...";
  std::cout << std::endl;
  return;
}
