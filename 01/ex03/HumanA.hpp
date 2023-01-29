#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include <string>
#include "Weapon.hpp"

class HumanA {
 public:
  HumanA( std::string const name, Weapon& weapon );
  ~HumanA( void );

  void attack( void );

 private:
  std::string const _name;
  Weapon&           _weapon;
};

#endif /* __HUMANA_HPP__ */
