#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

/**
 * Bureaucrat throws EGradeTooHigh and EGradeTooLow as "temporary", they are
 * created and thrown at once like: throw EGradeTooLow ( _grade );
 */

int main( void ) {
  try {
    Bureaucrat henry = Bureaucrat( "Henry", 5 );
    Form       f1 = Form( "Organ Donation", false, 10, 1 );
    Form       f2 = Form( "Time Donation", false, 1, 10 );

    // TODO why this one stops the program unstack wind etc. unlike prev ones
    /* Form f3 = Form( "Time Donation", false, 0, 0 ); */

    henry.signForm( f1 );
    henry.signForm( f1 );
    henry.signForm( f2 );

  } catch( EBureaucratGradeTooHigh const& e ) {
    std::cerr << e.what() << std::endl;
  } catch( EBureaucratGradeTooLow const& e ) {
    std::cerr << e.what() << std::endl;
  } catch( EFormGradeTooHigh const& e ) {
    std::cerr << e.what() << std::endl;
  } catch( EFormGradeTooLow const& e ) {
    std::cerr << e.what() << std::endl;
  } catch( ... ) {
    std::cerr << "Error occurred during what() message formatting";
  }

  return 0;
}
