#include "Zombie.hpp"

#include <iostream>

int main() {
  Zombie* horde;
  int     i;

  i = 3;
  horde = zombieHorde( i, "Atila" );
  while( i-- ) {
    horde[i].announce();
  }
  delete[] horde;
  return 0;
}
