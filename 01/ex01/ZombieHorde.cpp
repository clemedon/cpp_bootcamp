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
