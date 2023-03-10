#include <iostream>
#include "Bureaucrat.hpp"

/**
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
