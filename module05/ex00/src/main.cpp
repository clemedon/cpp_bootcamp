#include <iostream>
#include "Bureaucrat.hpp"

/**
 * Bureaucrat throws EGradeTooHigh and EGradeTooLow as "temporary", they are
 * created and thrown at once like: throw EGradeTooLow ( _grade );
 */

int main( void ) {
  try {
    Bureaucrat clem = Bureaucrat( "Clem", 142 );

    // TODO if clem is on the heap
    while( 1 ) {
      /* std::cout << clem; */
      /* std::cout << " downgraded to "; */
      clem.downGrade();
      /* std::cout << clem; */
      /* std::cout << std::endl; */
    }
  } catch( EGradeTooHigh const& e ) {
    std::cerr << e.what() << std::endl;
  } catch( EGradeTooLow const& e ) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
