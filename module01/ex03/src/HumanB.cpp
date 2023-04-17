// @author    Clément Vidon
// @created   230324 11:56:08  by  clem@spectre
// @modified  230324 11:56:08  by  clem@spectre
// @filename  HumanB.cpp

#include <iostream>
#include <string>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB( std::string const name ) : _name( name ), _weapon( NULL ) {
  return;
}

HumanB::~HumanB( void ) {
  return;
}

void HumanB::setWeapon( Weapon& weapon ) {
  _weapon = &weapon;
  return;
}

void HumanB::attack( void ) const {
  std::cout << _name;
  std::cout << " attacks with their ";
  if( _weapon ) {
    std::cout << _weapon->getType();
  } else {
    std::cout << "hands lol";
  }
  std::cout << std::endl;
  return;
}
