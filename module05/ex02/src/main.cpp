#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
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
  Bureaucrat henry = Bureaucrat( "Olaf", 6 );
  AForm*     f1 = new PresidentialPardonForm( "Vadim" );
  AForm*     f2 = new ShrubberyCreationForm( "Kitchen" );
  AForm*     f3 = new RobotomyRequestForm( "Vadim" );
  std::cout << std::endl;
  try {
    henry.signForm( *f1 );
    henry.executeForm( *f1 );
    henry.upGrade();
    henry.executeForm( *f1 );
    std::cout << std::endl;

    henry.signForm( *f2 );
    henry.executeForm( *f2 );
    std::cout << std::endl;

    henry.signForm( *f3 );
    henry.executeForm( *f3 );
    std::cout << std::endl;

    henry.upGrade();
    henry.upGrade();
    henry.upGrade();
    henry.upGrade();
    henry.upGrade();
    std::cout << std::endl;

  } catch( EBureaucratGradeTooHigh const& e ) {
    std::cout << e.what() << std::endl;
    delete f1;
    delete f2;
    delete f3;
    return 1;
  } catch( EBureaucratGradeTooLow const& e ) {
    std::cout << e.what() << std::endl;
    delete f1;
    delete f2;
    delete f3;
    return 1;
  } catch( EAFormGradeTooHigh const& e ) {
    std::cout << e.what() << std::endl;
    delete f1;
    delete f2;
    delete f3;
    return 1;
  } catch( EAFormGradeTooLow const& e ) {
    std::cout << e.what() << std::endl;
    delete f1;
    delete f2;
    delete f3;
    return 1;
  } catch( ... ) {
    std::cout << "Error occurred during what() message formatting";
    std::cout << std::endl;
    delete f1;
    delete f2;
    delete f3;
    return 1;
  }
  delete f1;
  delete f2;
  delete f3;
  return 0;
}
