#include <iostream>
#include <string>
#include "Rot.hpp"
int main() {
  Rot base( 11, 22 );
  Rot copy( base );
  Rot assi( 33, 66 );

  std::cout << std::endl;

  std::cerr << "Rot base( 11, 22 )" << std::endl;
  std::cerr << "Rot copy( base )      // copy is a copy of base" << std::endl;
  std::cerr << "Rot assi( 33, 66 )" << std::endl;

  std::cout << std::endl;

  std::cout << " base " << &base << base << std::endl;
  std::cout << " copy " << &copy << copy << std::endl;
  std::cout << " assi " << &assi << assi << std::endl;

  std::cout << std::endl;

  assi = base;
  std::cout << "assi = base;        // assi get assigned base" << std::endl;

  std::cout << std::endl;

  std::cout << " base " << &base << base << std::endl;
  std::cout << " copy " << &copy << copy << std::endl;
  std::cout << " assi " << &assi << assi << std::endl;

  std::cout << std::endl;

  return 0;
}
