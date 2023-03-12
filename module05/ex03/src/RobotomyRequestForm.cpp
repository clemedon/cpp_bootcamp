#include <iostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "RobotomyRequestForm.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

RobotomyRequestForm::RobotomyRequestForm( std::string const& target )
  : AForm( "Robotomy Request", false, 72, 45 ),
    _target( target ) {
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " CONSTRUCTED ";
  std::cerr << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Constructor
 */

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const& src )
  : AForm( src ),
    _target( src._target ) {
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " COPY CONSTRUCTED ";
  std::cerr << *this;
  std::cerr << " FROM ";
  std::cerr << src;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Destructor
 */

RobotomyRequestForm::~RobotomyRequestForm( void ) {
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " DESTRUCTED ";
  std::cerr << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

RobotomyRequestForm& RobotomyRequestForm::operator=(
  RobotomyRequestForm const& rhs ) {
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " COPY ASSIGNMENT OPERATOR DISABLED";
  std::cerr << std::endl;
#endif
  (void)rhs;
  return *this;
}

/* ---------------------------------------------- */

void RobotomyRequestForm::execute( Bureaucrat const& executor ) const {
  (void)executor;
  std::srand( std::time( NULL ) );
  std::cout << "* drilling noise *" << std::endl;
  if( rand() % 2 ) {
    std::cout << _target << " has been robotomized successfully!";
    std::cout << std::endl;
  } else {
    std::cout << _target << "'s robotomy has failed…";
    std::cout << std::endl;
  }
  return;
}
