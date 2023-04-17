// @author    Clément Vidon
// @created   230324 11:56:04  by  clem@spectre
// @modified  230324 11:56:07  by  clem@spectre
// @filename  HumanA.cpp

#include <iostream>
#include <string>

#include "Weapon.hpp"

#include "HumanA.hpp"

HumanA::HumanA( std::string const name, Weapon& weapon )
  : _name( name ),
    _weapon( weapon ) {
  return;
}

HumanA::~HumanA( void ) {
  return;
}

void HumanA::attack( void ) const {
  std::cout << _name;
  std::cout << " attacks with their ";
  std::cout << _weapon.getType();
  std::cout << std::endl;
  return;
}
