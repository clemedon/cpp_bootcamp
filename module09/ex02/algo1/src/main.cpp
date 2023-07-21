/* src/main */
/* Created: 230718 20:00:55 by clem@spectre */
/* Updated: 230718 20:00:55 by clem@spectre */
/* Maintainer: Clément Vidon */

#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

#ifndef PRINTNUMBERS
#  define PRINTNUMBERS
template <typename T>
void printNumbers( T& numbers ) {
  for( typename T::iterator it = numbers.begin(); it != numbers.end(); it++ ) {
    std::cout << *it << " ";
  }
  std::cout << '\n';
}
#endif

int main( int argc, char** argv ) {
  try {
    if( argc < 2 ) {
      throw std::runtime_error( "Error" );
    }
    std::vector<std::string> inputNumbers;
    inputNumbers.assign( argv + 1, argv + argc );
    PmergeMe<std::vector<long> > vec( inputNumbers );
    PmergeMe<std::deque<long> >  deq( inputNumbers );
    std::cout << "Before:\t";
    printNumbers( inputNumbers );
    std::cout << "After:\t";
    printNumbers( vec.getNumbers() );
    /* std::cout << "      \t"; */
    /* printNumbers( deq.getNumbers() ); */
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::vector : " << std::scientific
              << std::setprecision( 6 ) << vec.getExecutionTime() << " μs\n";
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::deque  : " << std::scientific
              << std::setprecision( 6 ) << deq.getExecutionTime() << " μs\n";
  } catch( const std::exception& e ) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
