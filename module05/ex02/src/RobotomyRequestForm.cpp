// @author    Clément Vidon
// @created   230417 11:46:17  by  clem@spectre
// @modified  230417 14:44:07  by  clem@spectre
// @filename  RobotomyRequestForm.cpp

#include <cstdlib>
#include <ctime>
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
#if defined( DEV )
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
#if defined( DEV )
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
#if defined( DEV )
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
#if defined( DEV )
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
  srand( static_cast<unsigned int>( std::time( NULL ) ) );
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
