// @author    Clément Vidon
// @created   230417 10:34:58  by  clem@spectre
// @modified  230417 11:04:12  by  clem@spectre
// @filename  main.cpp

#include <iostream>

#include "Bureaucrat.hpp"

/**
 * ex00
 *
 * Bureaucrat throws EGradeTooHigh and EGradeTooLow as "temporary", they are
 * created and thrown at once like: throw EGradeTooLow ( _grade );
 */

int main( void ) {
  try {
    Bureaucrat clem = Bureaucrat( "Clem", 142 );
    while( 1 ) {
      clem.downGrade();
    }
  } catch( EGradeTooHigh const& e ) {
    std::cerr << e.what() << std::endl;
  } catch( EGradeTooLow const& e ) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
