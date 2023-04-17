// @author    Clément Vidon
// @created   230324 11:52:23  by  clem@spectre
// @modified  230324 11:52:24  by  clem@spectre
// @filename  main.cpp

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
