// @author    Clément Vidon
// @created   230324 13:34:03  by  clem@spectre
// @modified  230330 06:48:00  by  clem@spectre
// @filename  main.cpp

#include <stdlib.h>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
  unsigned int      random;
  ClapTrap ct0( "Xavier" );
  ScavTrap st0( "Charly" );

  srand( static_cast<unsigned int>(time( NULL )) );
  std::cout << ">> Start <<" << std::endl;
  while( ct0.isAble() && st0.isAble() ) {
    random = static_cast<unsigned int>(rand() % 100 + 1);
    if( random <= 50 ) {
      ct0.attack( st0.getName() );
      st0.takeDamage( ct0.getAttackDamage() );
    } else {
      st0.attack( ct0.getName() );
      ct0.takeDamage( st0.getAttackDamage() );
    }
    random = static_cast<unsigned int>(rand() % 100 + 1);
    if( random <= 50 ) {
      ct0.beRepaired( random % 10 );
    } else {
      st0.beRepaired( random % 10 );
    }
    random = static_cast<unsigned int>(rand() % 100 + 1);
    if( random <= 50 ) {
      st0.guardGate();
    }
  }
  std::cout << ">> Finish <<" << std::endl;
  return 0;
}
