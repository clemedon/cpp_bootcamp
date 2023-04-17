// @author    Clément Vidon
// @created   230324 11:59:33  by  clem@spectre
// @modified  230324 11:59:35  by  clem@spectre
// @filename  main.cpp

#include <iostream>
#include <string>

#include "Harl.hpp"

int main( void ) {
  Harl              harl;
  std::string       input;
  std::string const clearscreen = "\033[2J\033[1;1H";

  while( 1 ) {
    std::cout << clearscreen;
    std::cout << "Hello, I am Harl" << std::endl;
    std::cout << std::endl;
    std::cout << "Complains: DEBUG, INFO, WARNING, ERROR" << std::endl;
    std::cout << "Test my complain (or exit with Ctrl-d): " << std::endl;
    std::cout << std::endl;
    std::cout << "> ";
    if( !std::getline( std::cin, input ) ) {
      std::cout << clearscreen;
      std::cerr << "Ciao" << std::endl;
      return ( 0 );
    }
    if( input.empty() || input.length() > 50 ) {
      continue;
    }
    std::cout << "" << std::endl;
    harl.complain( input );
    std::cout << "" << std::endl;
    std::cin.ignore();
  }
  return 0;
}
