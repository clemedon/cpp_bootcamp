#include <stdlib.h>
#include <iostream>
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/** XXX Another heavier but more flexible approach would be to create the
 * parents at first (from the initialization list) then to recover the values of
 * their attributes from which our diamond must inherit and assign them to it
 * within the body of its constructor
 */

int main( void ) {
  int         random;
  DiamondTrap ft0( "Xavier" );
  DiamondTrap st1( "Charly" );
  DiamondTrap st0( st1 );

  /* srand( time( NULL ) ); */
  srand( 166328311 );
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
