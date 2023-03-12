#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

/**
 * ex00
 *
 * Bureaucrat throws EGradeTooHigh and EGradeTooLow as "temporary", they are
 * created and thrown at once like: throw EGradeTooLow ( _grade );
 *
 * ex01
 *
 * Bureaucrat::giveGrade is exactly the same as Bureaucrat::getGrade but unlike
 * the latter it does respect encapsulation principle.
 *
 * Attempting to sign a contract at too high a level will not interrupt the
 * program as catch() is in a member function in the middle of the program,
 * conversely if the grade of a Bureaucrat is not legal then the program will
 * end as the catch() is at the end of the program in the main.
 */

int main( void ) {
  try {
    Bureaucrat henry = Bureaucrat( "Henry", 5 );
    Form       f1 = Form( "Organ Donation", false, 10, 1 );
    Form       f2 = Form( "Time Donation", false, 1, 10 );
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
    std::cout << std::endl;
  }
  return 0;
}
