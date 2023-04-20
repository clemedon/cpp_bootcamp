// @author    Clément Vidon
// @created   230324 11:48:20  by  clem@spectre
// @modified  230420 18:31:13  by  clem@spectre
// @filename  main.cpp

#include "Zombie.hpp"

int main() {
  Zombie* zombie;

  zombie = newZombie( "Delphine" );
  zombie->announce();
  delete zombie;
  randomChump( "Xavier" );
  return 0;
}
