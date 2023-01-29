#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include <string>
#include "Weapon.hpp"

class HumanB {
 public:
  HumanB( std::string const name );
  ~HumanB( void );

  void setWeapon( Weapon& weapon );
  void attack( void );

 private:
  std::string const _name;
  Weapon*           _weapon;
};

#endif /* __HUMANB_HPP__ */
