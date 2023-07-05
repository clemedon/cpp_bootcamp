/* src/main */
/* Created: 230501 10:50:50 by clem@spectre */
/* Updated: 230705 15:50:08 by clem@spectre */
/* Maintainer: Clément Vidon */

#include <cstdlib>
#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

int main( int argc, char** argv ) {
  if( argc != 2 )  // Invalid argument
  {
    std::cout << "Error: wrong argument." << std::endl;
    std::cout << "Usage: ./btc input.csv" << std::endl;
    exit( 1 );
  }
  BitcoinExchange( "data.csv" ).processInput( argv[1] );
  return 0;
}
