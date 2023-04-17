// @author    Clément Vidon
// @created   230324 11:42:10  by  clem@spectre
// @modified  230324 11:42:13  by  clem@spectre
// @filename  main.cpp

#include <cstdlib>
#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "phonebook.h"

/**
 * @brief      PhoneBook is a small contact book
 *
 * Eval tests:
 * - eol protection: try c-d from the prompt
 *
 *   o eval script
 */

int main( void ) {
  PhoneBook   pb;
  std::string input;

  while( true ) {
    CLEAR;
    std::cout << std::endl;
    std::cout << "      ******************" << std::endl;
    std::cout << "      * WELCOME TO THE *" << std::endl;
    std::cout << "      * PhoneBook Menu *" << std::endl;
    std::cout << "      ******************" << std::endl;
    std::cout << std::endl;
    std::cout << "  'ADD' to add a new contact" << std::endl;
    std::cout << "  'SEARCH' to find a contact" << std::endl;
    std::cout << "  'EXIT' to reset and exit.." << std::endl;
    std::cout << std::endl;
    std::cout << "> ";
    if( !std::getline( std::cin, input ) ) {
      CLEAR;
      std::cerr << "Failure: " << __FILE__ << ": " << __LINE__ << std::endl;
      exit( 1 );
    }
    if( input.empty() || input.length() > 6 ) {
      continue;
    }
#ifdef DEV
    if( input == "ADD" || input == "a" ) {
      pb.add_contact();
    }
    if( input == "SEARCH" || input == "s" ) {
      pb.search_contact();
    }
    if( input == "EXIT" || input == "e" ) {
      return 0;
    }
#else
    if( input == "ADD" ) {
      pb.add_contact();
    }
    if( input == "SEARCH" ) {
      pb.search_contact();
    }
    if( input == "EXIT" ) {
      return 0;
    }
#endif
  }
  return 0;
}
