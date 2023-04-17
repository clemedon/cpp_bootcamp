// @author    Clément Vidon
// @created   230324 14:04:49  by  clem@spectre
// @modified  230324 14:51:41  by  clem@spectre
// @filename  main.cpp

#include <cstdlib>
#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
  unsigned int random;
  FragTrap     ft0( "Xavier" );
  ScavTrap     st0( "Charly" );

  srand( static_cast<unsigned int>( time( NULL ) ) );
  std::cout << ">> Start <<" << std::endl;
  while( 1 ) {
    random = static_cast<unsigned int>( rand() % 100 + 1 );

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
      random = static_cast<unsigned int>( rand() % 100 + 1 );
      if( random <= 50 ) {
        ft0.beRepaired( random % 10 );
      } else {
        st0.beRepaired( random % 10 );
      }
      random = static_cast<unsigned int>( rand() % 100 + 1 );
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
