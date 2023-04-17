// @author    Clément Vidon
// @created   230417 15:27:30  by  clem@spectre
// @modified  230417 15:27:45  by  clem@spectre
// @filename  main.cpp

#include <iomanip>
#include <iostream>
#include <string>

#include "convert.hpp"

/**
 * Detect if a string represents a valid char, int, float or double value,
 * convert this string into the matching type's value, finally cast this value
 * into each of those types and print them.
 */

int main( int argc, char* argv[] ) {
  double doubleVal = 0.0;
  std::cout << std::fixed << std::setprecision( 1 );

  (void)argv;
  (void)argc;

#ifdef DEV
  std::string str = "fillme";
#else
  if( argc != 2 ) {
    std::cerr << "Usage: " << argv[0] << " <literal>\n";
    return 1;
  }
  std::string str( argv[1] );
#endif

  if( detectChar( str ) ) {
    convertChar( str, doubleVal );
  } else if( detectInt( str ) ) {
    convertInt( str, doubleVal );
  } else if( detectFloat( str ) ) {
    convertFloat( str, doubleVal );
  } else if( detectDouble( str ) ) {
    convertDouble( str, doubleVal );
  } else {
    std::cout << "Input \"" << str;
    std::cout << "\" did not match any of the supported types:";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << " char, int, float, double";
    std::cout << std::endl;
    return 1;
  }
  printChar( doubleVal );
  printInt( doubleVal );
  printFloat( doubleVal );
  printDouble( doubleVal );
  return 0;
}
