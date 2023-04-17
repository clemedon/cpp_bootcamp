// @author    Clément Vidon
// @created   230324 12:03:30  by  clem@spectre
// @modified  230324 12:03:32  by  clem@spectre
// @filename  main.cpp

#include <iostream>

#include "Fixed.hpp"

int main( void ) {
  Fixed a;
  Fixed b( a );
  Fixed c;

  c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  return 0;
}
