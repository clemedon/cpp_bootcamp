// @author    Clément Vidon
// @created   230417 15:41:23  by  clem@spectre
// @modified  230417 15:41:23  by  clem@spectre
// @filename  main.cpp

#include <iostream>
#include <string>

#include "whatever.hpp"

int main( void ) {
  std::cout << std::endl;
  std::cout << "Should output:" << std::endl;
  std::cout << std::endl;
  std::cout << "a = 3, b = 2" << std::endl;
  std::cout << "min( a, b ) = 2" << std::endl;
  std::cout << "max( a, b ) = 3" << std::endl;
  std::cout << "c = chaine2, d = chaine1" << std::endl;
  std::cout << "min( c, d ) = chaine1" << std::endl;
  std::cout << "max( c, d ) = chaine2" << std::endl;
  std::cout << std::endl;
  std::cout << "Output:" << std::endl;
  std::cout << std::endl;

  int a = 2;
  int b = 3;
  ::swap( a, b );
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
  std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap( c, d );
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
  std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
  return 0;
}
