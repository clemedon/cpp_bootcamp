#include <iostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "PresidentialPardonForm.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

PresidentialPardonForm::PresidentialPardonForm( std::string const& target )
  : AForm( "Presidential Pardon", false, 25, 5 ),
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

PresidentialPardonForm::PresidentialPardonForm(
  PresidentialPardonForm const& src )
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

PresidentialPardonForm::~PresidentialPardonForm( void ) {
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

PresidentialPardonForm& PresidentialPardonForm::operator=(
  PresidentialPardonForm const& rhs ) {
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " COPY ASSIGNMENT OPERATOR DISABLED";
  std::cerr << std::endl;
#endif
  (void)rhs;
  return *this;
}

/* ---------------------------------------------- */

void PresidentialPardonForm::execute( Bureaucrat const& executor ) const {
  (void)executor;
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox";
  std::cout << std::endl;
  return;
}
