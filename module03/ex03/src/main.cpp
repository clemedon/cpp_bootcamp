// @author    Clément Vidon
// @created   230324 15:04:56  by  clem@spectre
// @modified  230324 15:04:56  by  clem@spectre
// @filename  main.cpp

#include <cstdlib>
#include <iostream>

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/**
 * My approach to initialization differs from the previous exercises.
 * Rather than cascading the parameters of the derived class that I instantiate
 * to the base class so that it is directly initialized with the derived class
 * wanted values, I create the base class with its default values then I
 * overwrite them with those of the derived class that invoked it.
 */

int main( void ) {
  std::cout << std::endl;
  std::cout << ">>> CREATION OF XAV <<<" << std::endl;
  DiamondTrap a( "Xav" );

  std::cout << std::endl;
  std::cout << ">>> CREATION OF XAV COPY <<<" << std::endl;
  DiamondTrap b( a );

  std::cout << std::endl;
  std::cout << ">>> XAV <<<" << std::endl;
  std::cout << a << std::endl;
  a.whoAmI();

  std::cout << std::endl;
  std::cout << ">>> XAV COPY <<<" << std::endl;
  std::cout << b << std::endl;
  b.whoAmI();

  std::cout << std::endl;
  std::cout << ">>> XAV ATTACK XAV COPY <<<" << std::endl;
  a.attack( b.getName() );
  b.takeDamage( a.getAttackDamage() );

  std::cout << std::endl;
  std::cout << ">>> XAV <<<" << std::endl;
  std::cout << a << std::endl;
  a.whoAmI();

  std::cout << std::endl;
  std::cout << ">>> XAV COPY <<<" << std::endl;
  std::cout << b << std::endl;
  b.whoAmI();

  std::cout << std::endl;
  std::cout << ">>> DESTRUCTION OF XAV COPY AND XAV <<<" << std::endl;
  return 0;
}
