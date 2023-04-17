// @author    Clément Vidon
// @created   230417 14:48:35  by  clem@spectre
// @modified  230417 16:47:54  by  clem@spectre
// @filename  Intern.cpp

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include "Intern.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Intern::Intern( void ) {
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

Intern::Intern( Intern const& src ) {
  *this = src;
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

Intern::~Intern( void ) {
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

Intern& Intern::operator=( Intern const& rhs ) {
#if defined( DEV )
  std::cerr << __FILE__;
  std::cerr << " COPY ASSIGNMENT OPERATOR DISABLED";
  std::cerr << std::endl;
#endif
  (void)rhs;
  return *this;
}

/**
 * @brief       Print State
 */

void Intern::print( std::ostream& o ) const {
  o << "Intern";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Intern const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

AForm* Intern::makeForm( std::string const& formName,
                         std::string const& formTarget ) {
  size_t i;
  AForm* newForm = NULL;

  struct Forms {
    std::string const name;
    AForm*            form;
  };
  const Forms forms[] = {
    { "shrubbery creation", new ShrubberyCreationForm( formTarget ) },
    { "robotomy request", new RobotomyRequestForm( formTarget ) },
    { "presidential pardon", new PresidentialPardonForm( formTarget ) },
  };
  for( i = 0; i < sizeof( forms ) / sizeof( *forms ); ++i ) {
    if( formName == forms[i].name ) {
      newForm = forms[i].form;
    } else {
      delete forms[i].form;
    }
  }
  if( !newForm )
    throw EInternFormNotFound( formName );
  else
    std::cout << *this << " creates " << *newForm << std::endl;
  return newForm;
}

/*  EXCEPTIONS
------------------------------------------------- */

EInternFormNotFound::FormNotFoundException( std::string const& formName )
  : _message( "Error: could not find any form called \"" + formName + "\"" ) {
  return;
}

EInternFormNotFound::~FormNotFoundException( void ) throw() {
  return;
}

char const* EInternFormNotFound::what( void ) const throw() {
  return _message.c_str();
}
