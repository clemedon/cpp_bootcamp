// @author    Clément Vidon
// @created   230417 14:57:06  by  clem@spectre
// @modified  230417 14:57:06  by  clem@spectre
// @filename  main.cpp

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
 *
 * ex02
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
  Bureaucrat olaf = Bureaucrat( "Olaf", 5 );
  AForm*     rrf = NULL;
  Intern     someRandomIntern;
  std::cout << std::endl;

  try {
    rrf = someRandomIntern.makeForm( "jump from the window", "Bender" );
    olaf.signForm( *rrf );
    olaf.executeForm( *rrf );
  } catch( EInternFormNotFound const& e ) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    rrf = someRandomIntern.makeForm( "robotomy request", "Bender" );
    olaf.signForm( *rrf );
    olaf.executeForm( *rrf );
  } catch( EInternFormNotFound const& e ) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
