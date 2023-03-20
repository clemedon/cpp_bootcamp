#include <iostream>
#include <vector>

#include "easyfind.hpp"

/**
 * std::distance( InputIt first, InputIt last ); is an iterator operation that
 * calculates the number of elements between two iterators
 */

int main() {
  std::vector<int>           v;
  std::vector<int>::iterator it;

  v.push_back( 1 );
  v.push_back( 2 );
  v.push_back( 3 );
  v.push_back( 4 );
  v.push_back( 5 );
  try {
    it = easyfind( v, 3 );
    std::cout << "Found value at index " << std::distance( v.begin(), it );
    std::cout << std::endl;

    it = easyfind( v, 42 );
    std::cout << "Found value at index " << std::distance( v.begin(), it );
    std::cout << std::endl;

  } catch( const std::runtime_error& e ) {
    std::cerr << e.what() << "\n";
  }
  return 0;
}
