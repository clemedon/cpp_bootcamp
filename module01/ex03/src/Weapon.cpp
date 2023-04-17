// @author    Clément Vidon
// @created   230324 11:56:09  by  clem@spectre
// @modified  230324 11:56:14  by  clem@spectre
// @filename  Weapon.cpp

#include <string>

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type( type ) {
  return;
}

Weapon::~Weapon( void ) {
  return;
}

std::string const& Weapon::getType( void ) const {
  return _type;
}

void Weapon::setType( std::string type ) {
  _type = type;
  return;
}
