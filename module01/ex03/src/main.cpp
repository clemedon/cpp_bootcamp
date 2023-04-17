// @author    Clément Vidon
// @created   230324 11:56:08  by  clem@spectre
// @modified  230324 11:56:09  by  clem@spectre
// @filename  main.cpp

#include <iostream>
#include <string>

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main( void ) {
  {
    Weapon club = Weapon( "crude spiked club" );
    HumanA bob( "Bob", club );
    bob.attack();
    club.setType( "some other type of club" );
    bob.attack();
  }
  {
    Weapon club = Weapon( "crude spiked club" );
    HumanB jim( "Jim" );
    jim.setWeapon( club );
    jim.attack();
    club.setType( "some other type of club" );
    jim.attack();
  }
  return 0;
}
