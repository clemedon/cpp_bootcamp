// @author    Clément Vidon
// @created   230324 12:12:20  by  clem@spectre
// @modified  230324 12:12:20  by  clem@spectre
// @filename  main.cpp

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

  std::cout << "foo.max( Fixed( 5.01f ), Fixed( 5.49f ).toInt() );"
            << std::endl;
  std::cout << " max is " << foo.max( Fixed( 5.01f ), Fixed( 5.49f ).toInt() )
            << std::endl;
  std::cout << "foo.min( Fixed( 6 ), Fixed( 66 ).toInt() );"
            << std::endl;
  std::cout << " min is " << foo.min( 6, 66 ) << std::endl;
  std::cout << std::endl;

  Fixed i( 3.2f );
  Fixed j( 42.1f );

  std::cout << "foo.max( Fixed( 42f ), Fixed( -42 ) );" << std::endl;
  std::cout << " max is " << foo.max( i, j ) << std::endl;
  return 0;
}
