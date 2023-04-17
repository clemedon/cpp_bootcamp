// @author    Clément Vidon
// @created   230324 11:55:40  by  clem@spectre
// @modified  230324 11:55:41  by  clem@spectre
// @filename  HumanA.hpp

#ifndef HUMANA_HPP_
#define HUMANA_HPP_

#include <string>

#include "Weapon.hpp"

class HumanA {
 public:
  HumanA( std::string const name, Weapon& weapon );
  ~HumanA( void );

  void attack( void ) const;

 private:
  std::string const _name;
  Weapon&           _weapon;
};

#endif /* HUMANA_HPP_ */
