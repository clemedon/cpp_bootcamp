#include <stdlib.h>
#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
  int      random;
  ClapTrap ct0;
  ClapTrap ct1( "Charly" );

  srand( time( NULL ) );
  std::cout << ">> Start <<" << std::endl;
  while( ct0.isAble() && ct1.isAble() ) {
    random = rand() % 100 + 1;

    if( random <= 50 ) {
      ct0.attack( ct1.getName() );
      ct1.takeDamage( ct0.getAttackDamage() );
    } else {
      ct1.attack( ct0.getName() );
      ct0.takeDamage( ct1.getAttackDamage() );
    }

    random = rand() % 100 + 1;
    if( random <= 50 ) {
      ct0.beRepaired( random % 10 );
    } else {
      ct1.beRepaired( random % 10 );
    }
  }

  std::cout << ">> Finish <<" << std::endl;
  return 0;
}
