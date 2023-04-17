// @author    Clément Vidon
// @created   230324 12:56:23  by  clem@spectre
// @modified  230329 15:58:10  by  clem@spectre
// @filename  main.cpp

#include <cstdlib>
#include <iostream>

#include "ClapTrap.hpp"

int main( void ) {
  unsigned int random;
  ClapTrap     ct0;
  ClapTrap     ct1( "Charly" );

  srand( static_cast<unsigned int>( time( NULL ) ) );
  std::cout << ">> Start <<" << std::endl;
  while( ct0.isAble() && ct1.isAble() ) {
    random = static_cast<unsigned int>( rand() % 100 + 1 );

    if( random <= 50 ) {
      ct0.attack( ct1.getName() );
      ct1.takeDamage( ct0.getAttackDamage() );
    } else {
      ct1.attack( ct0.getName() );
      ct0.takeDamage( ct1.getAttackDamage() );
    }

    random = static_cast<unsigned int>( rand() % 100 + 1 );
    if( random <= 50 ) {
      ct0.beRepaired( random % 10 );
    } else {
      ct1.beRepaired( random % 10 );
    }
  }

  std::cout << ">> Finish <<" << std::endl;
  return 0;
}
