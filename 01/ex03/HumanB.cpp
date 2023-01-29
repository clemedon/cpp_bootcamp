#include <iostream>
#include <string>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB( std::string const name ) : _name( name ) {
  this->_weapon = NULL;
}

HumanB::~HumanB( void ) {
}

void HumanB::setWeapon( Weapon& weapon ) {
  this->_weapon = &weapon;
}

void HumanB::attack( void ) {
  std::cout << this->_name;
  std::cout << " attacks with their ";
  if( this->_weapon ) {
    std::cout << this->_weapon->getType();
  } else {
    std::cout << "hands lol";
  }
  std::cout << std::endl;
}
