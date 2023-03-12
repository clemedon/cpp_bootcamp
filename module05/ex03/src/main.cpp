#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/**
 * Bureaucrat throws EGradeTooHigh and EGradeTooLow as "temporary", they are
 * created and thrown at once like: throw EGradeTooLow ( _grade );
 *
 * Bureaucrat::giveGrade is exactly the same as Bureaucrat::getGrade but unlike
 * the latter it does respect encapsulation principle.
 *
 * Attempting to sign a contract at too high a level will not interrupt the
 * program as catch() is in a member function in the middle of the program,
 * conversely if the grade of a Bureaucrat is not legal then the program will
 * end as the catch() is at the end of the program in the main.
 *
 * In my quest for my non-use of getters I was confronted with a problem when
 * implementing the copy constructor of AForm derived classes, indeed, how to
 * access AForm source attributes to build AForm copy if they are private? The
 * solution was to set AForm copy constructor to protected, therefor I can
 * directly call AForm's copy constructor from its derived classes and build a
 * copy without accessing its attributes.
 *
 * In addition to that it is recommended to set any abstract class' constructors
 * to protected to prevent any attempt of illegal instantiation on the user side
 *
 * I decided to (void)executor; in execute() because I dont need him since I
 * have a beExecuted() in AForm that already print "<bureaucrat> executed
 * <form>" message, to stay consistent with previously implemented beSigned()
 * behavior.
 */

int main( void ) {
  std::cout << std::endl;
  std::cout << "------------------------------" << std::endl;

  Intern someRandomIntern;
  AForm* rrf;

  try {
    rrf = someRandomIntern.makeForm( "robotomy request", "Bender" );
    std::cout << "new form>> " << *rrf << std::endl;

    std::cout << "------------------------------" << std::endl;
    std::cout << std::endl;
  } catch( EBureaucratGradeTooHigh const& e ) {
    /* delete rrf; */
    return 1;
  } catch( ... ) {
    /* delete rrf; */
    std::cout << "Error occurred during what() message formatting";
    std::cout << std::endl;
    return 1;
  }
  /* delete rrf; */
  return 0;
}
