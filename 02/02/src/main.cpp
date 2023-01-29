#include <iostream>
#include "Fixed.hpp"

int main( void ) {
  Fixed       a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl;
  std::cout << "==================" << std::endl;

  Fixed foo( .5f );
  std::cout << std::endl;
  std::cout << "foo;" << std::endl;
  std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
  std::cout << " float representation  is " << foo << std::endl;
  std::cout << std::endl;

  foo++;
  std::cout << "foo++;" << std::endl;
  std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
  std::cout << " float representation  is " << foo << std::endl;
  std::cout << std::endl;

  foo.setRawBits( foo.getRawBits() - 1 );
  std::cout << "foo.setRawBits( foo.getRawBits() - 1 );" << std::endl;
  std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
  std::cout << " float representation  is " << foo << std::endl;
  std::cout << std::endl;

  foo = foo * 2;
  std::cout << "foo = foo * 2;" << std::endl;
  std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
  std::cout << " float representation  is " << foo << std::endl;
  std::cout << std::endl;

  foo = foo / 2;
  std::cout << "foo = foo / 2;" << std::endl;
  std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
  std::cout << " float representation  is " << foo << std::endl;
  std::cout << std::endl;

  foo = foo / 4.2f;
  std::cout << "foo = foo / 4.2;" << std::endl;
  std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
  std::cout << " float representation  is " << foo << std::endl;
  std::cout << std::endl;

  std::cout << "PRECISION LOST" << std::endl;
  std::cout << std::endl;

  foo = foo * 4.2f;
  std::cout << "foo = foo / 4.2;" << std::endl;
  std::cout << " fixed point number    is " << foo.getRawBits() << std::endl;
  std::cout << " float representation  is " << foo << std::endl;
  std::cout << std::endl;
}
