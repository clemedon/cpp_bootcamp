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
  Span             span( 10000 );
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
  for( i = 0; static_cast<unsigned int>( i ) < ( 10000 - nums.size() ); i++ ) {
    span.addNumber( rand() % 1000 );
  }
  std::cout << span << std::endl;
  std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
  std::cout << "Longest span: " << span.longestSpan() << std::endl;
  return;
}

int main( void ) {
  subjectTest();
  myTest();
  return 0;
}
