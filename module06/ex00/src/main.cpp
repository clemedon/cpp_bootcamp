#include <iomanip>
#include <iostream>
#include <string>

#include "convert.hpp"

/**
 * @brief       Detect if a string represents a valid char, int, float or double
 *              value, convert this string into the matching type's value,
 *              finally cast this value into each of those types and print them.
 */

int main( int argc, char* argv[] ) {
  double doubleVal = 0.0;
  std::cout << std::fixed << std::setprecision( 1 );

#ifdef DEBUG
  std::string str = "salut"; // TODO
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
  }
  printChar( doubleVal );
  printInt( doubleVal );
  printFloat( doubleVal );
  printDouble( doubleVal );
  return 0;
}
