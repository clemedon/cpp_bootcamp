#include <stdlib.h>
#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
  int      random;
  FragTrap ft0( "Xavier" );
  ScavTrap st0( "Charly" );

  srand( time( NULL ) );
  std::cout << ">> Start <<" << std::endl;
  while( 1 ) {
    random = rand() % 100 + 1;

    if( ft0.isAble() && st0.isAble() ) {
      if( random <= 50 ) {
        ft0.attack( st0.getName() );
        st0.takeDamage( ft0.getAttackDamage() );
      } else {
        st0.attack( ft0.getName() );
        ft0.takeDamage( st0.getAttackDamage() );
      }
    } else {
      break;
    }

    if( ft0.isAble() && st0.isAble() ) {
      random = rand() % 100 + 1;
      if( random <= 50 ) {
        ft0.beRepaired( random % 10 );
      } else {
        st0.beRepaired( random % 10 );
      }
      random = rand() % 100 + 1;
    } else {
      break;
    }

    if( ft0.isAble() && st0.isAble() ) {
      if( random <= 50 ) {
        st0.guardGate();
      } else {
        ft0.highFivesGuys();
      }
    } else {
      break;
    }
  }
  std::cout << ">> Finish <<" << std::endl;
  return 0;
}
