// @author    Clément Vidon
// @created   230324 11:48:20  by  clem@spectre
// @modified  230324 11:48:23  by  clem@spectre
// @filename  main.cpp

#include "Zombie.hpp"

int main() {
  Zombie* zombie;

  zombie = newZombie( "Alice" );
  zombie->announce();
  delete zombie;
  randomChump( "Bob" );
  return 0;
}
