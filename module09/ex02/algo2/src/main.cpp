/* src/main */
/* Created: 230718 20:00:55 by clem@spectre */
/* Updated: 230718 20:00:55 by clem@spectre */
/* Maintainer: Clément Vidon */

#include <sys/time.h>
#include <cstdlib>
#include <ctime>
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

double calculateExecutionTime( struct timeval start, struct timeval finish ) {
  double startTime, finishTime;

  startTime = static_cast<double>( start.tv_sec )
              + static_cast<double>( start.tv_usec ) * 1e-6;
  finishTime = static_cast<double>( finish.tv_sec )
               + static_cast<double>( finish.tv_usec ) * 1e-6;
  return ( finishTime - startTime ) * 1e6;
}

int main( int argc, char** argv ) {
  try {
    if( argc < 2 ) {
      throw std::runtime_error( "Error" );
    }

    std::vector<std::string> numbers;
    long                     num;
    char*                    endptr;
    std::vector<long>        vec;
    std::deque<long>         deq;

    numbers.assign( argv + 1, argv + argc );
    std::vector<std::string>::const_iterator it;
    for( it = numbers.begin(); it != numbers.end(); ++it ) {
      num = std::strtol( ( *it ).c_str(), &endptr, 10 );
      if( *endptr != '\0' || num < 0 ) {
        throw std::runtime_error( "Error" );
      } else {
        vec.push_back( num );
        deq.push_back( num );
      }
    }

    struct timeval start, finish;
    double         vecExecutionTime;
    double         deqExecutionTime;

    gettimeofday( &start, NULL );
    mergeInsertSort( vec );
    gettimeofday( &finish, NULL );
    vecExecutionTime = calculateExecutionTime( start, finish );

    gettimeofday( &start, NULL );
    mergeInsertSort( deq );
    gettimeofday( &finish, NULL );
    deqExecutionTime = calculateExecutionTime( start, finish );

    std::cout << "Before:\t";
    printNumbers( numbers );
    std::cout << "After:\t";
    printNumbers( vec );
    std::cout << "      \t";
    printNumbers( deq );
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::vector : " << std::scientific
              << std::setprecision( 6 ) << vecExecutionTime << " μs\n";
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::deque  : " << std::scientific
              << std::setprecision( 6 ) << deqExecutionTime << " μs\n";
  } catch( const std::exception& e ) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
