#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point );

int main( void ) {
  Point const a;
  Point const b( 10, 30 );
  Point const c( 20, 0 );
  Point const p1( 15.0, 14.999 );
  Point const p2( 10, 3 );
  Point const p3( 0, 15.9 );

  std::cout << "                          " << std::endl;
  std::cout << "           b(10,30)       " << std::endl;
  std::cout << "           / \\           " << std::endl;
  std::cout << "      p3  /   \\          " << std::endl;
  std::cout << "         /     p1         " << std::endl;
  std::cout << "        /       \\        " << std::endl;
  std::cout << "       /   p2    \\       " << std::endl;
  std::cout << "a(0,0) ----------- c(20,0)" << std::endl;
  std::cout << std::endl;
  std::cout << "Is p inside of abc?" << std::endl;
  std::cout << "p1: " << bsp( a, b, c, p1 ) << std::endl;
  std::cout << "p2: " << bsp( a, b, c, p2 ) << std::endl;
  std::cout << "p3: " << bsp( a, b, c, p3 ) << std::endl;
}
