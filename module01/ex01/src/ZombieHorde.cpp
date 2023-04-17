// @author    Clément Vidon
// @created   230324 11:52:30  by  clem@spectre
// @modified  230324 11:52:33  by  clem@spectre
// @filename  ZombieHorde.cpp

#include "Zombie.hpp"

#include <string>

Zombie* zombieHorde( int N, std::string name ) {
  Zombie* zombie;
  int     i;

  zombie = new Zombie[N];
  for( i = 0; i < N; i++ ) {
    zombie[i].setName( name );
  }
  return zombie;
}
