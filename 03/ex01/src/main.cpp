#include <stdlib.h>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
  int      random;
  ClapTrap ct0( "Xavier" );
  ScavTrap st0( "Kevin" );

  srand( time( NULL ) );

  std::cout << ">> Start <<" << std::endl;
  while( ct0.isAble() && st0.isAble() ) {
    random = rand() % 100 + 1;
    if( random <= 50 ) {
      ct0.attack( st0.getName() );
      st0.takeDamage( ct0.getAttackDamage() );
    } else {
      st0.attack( ct0.getName() );
      ct0.takeDamage( st0.getAttackDamage() );
    }
    if( random <= 50 ) {
      ct0.beRepaired( random % 10 );
    } else {
      st0.beRepaired( random % 10 );
    }
  }

  std::cout << ">> Finish <<" << std::endl;
  return 0;
}
