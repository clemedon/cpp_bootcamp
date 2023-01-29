#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA( std::string const name, Weapon& weapon )
  : _name( name ),
    _weapon( weapon ) {
}

HumanA::~HumanA( void ) {
}

void HumanA::attack( void ) {
  std::cout << this->_name;
  std::cout << " attacks with their ";
  std::cout << this->_weapon.getType();
  std::cout << std::endl;
}
