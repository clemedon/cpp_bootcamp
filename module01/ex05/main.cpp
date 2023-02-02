#include <iostream>
#include <string>
#include "Karen.hpp"

int main( void ) {
  Karen             karen;
  std::string       input;
  std::string const clearscreen = "\033[2J\033[1;1H";

  while( 1 ) {
    std::cout << clearscreen;
    std::cout << "Hello, I am Karen" << std::endl;
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
    karen.complain( input );
    std::cout << "" << std::endl;
    std::cin.ignore();
  }
  return 0;
}
