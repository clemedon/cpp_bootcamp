// @author    Clément Vidon
// @created   230417 15:55:53  by  clem@spectre
// @modified  230417 15:56:00  by  clem@spectre
// @filename  main.cpp

#include <cstdlib>
#include <iostream>
#include <vector>

#include "Span.hpp"

void subjectTest( void ) {
  std::cout << "*** Subject Test ***" << std::endl;
  Span sp = Span( 5 );
  sp.addNumber( 6 );
  sp.addNumber( 3 );
  sp.addNumber( 17 );
  sp.addNumber( 9 );
  sp.addNumber( 11 );
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  return;
}

void myTest( void ) {
  Span             span( 1000000 );
  std::vector<int> nums;
  int              i;

  std::cout << "*** My Test ***" << std::endl;
  std::cout << "Add a range: " << std::endl;
  for( i = 0; i < 10; ++i ) {
    nums.push_back( i );
  }
  span.addRange( nums.begin(), nums.end() );
  std::cout << span << std::endl;

  std::cout << "Fill the remaining spaces with numbers: " << std::endl;
  for( i = 0; static_cast<unsigned int>( i ) < ( 100000 - nums.size() ); i++ ) {
    span.addNumber( rand() % 1000 );
  }
  std::cout << span << std::endl;
  std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
  std::cout << "Longest span: " << span.longestSpan() << std::endl;
  return;
}

int main( void ) {
  try {
    subjectTest();
    myTest();
  } catch( const std::exception& e ) {
    std::cerr << e.what() << '\n';
  }
  return 0;
}
