/* src/main */
/* Created: 230705 17:30:15 by clem@spectre */
/* Updated: 230705 17:30:15 by clem@spectre */
/* Maintainer: Clément Vidon */

#include <iostream>
#include <string>

#include "RPN.hpp"

int main( int argc, char* argv[] ) {
  if( argc != 2 ) {
    std::cout << "Usage: RPN <expression>\n";
    return 1;
  }
  try {
    RPN rpn;
    std::cout << "Result: " << rpn.evaluateExpression( argv[1] ) << "\n";
  } catch( const std::runtime_error& e ) {
#ifdef DEV
    std::cout << e.what() << std::endl;
#else
    std::cout << "Error.\n";
#endif
    return 1;
  }
  return 0;
}
