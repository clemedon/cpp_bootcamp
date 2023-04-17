// @author    Clément Vidon
// @created   230324 11:55:42  by  clem@spectre
// @modified  230324 11:55:44  by  clem@spectre
// @filename  HumanB.hpp

#ifndef HUMANB_HPP_
#define HUMANB_HPP_

#include <string>

#include "Weapon.hpp"

class HumanB {
 public:
  explicit HumanB( std::string const name );
  ~HumanB( void );

  void setWeapon( Weapon& weapon );
  void attack( void ) const;

 private:
  std::string const _name;
  Weapon*           _weapon;
};

#endif /* HUMANB_HPP_ */
