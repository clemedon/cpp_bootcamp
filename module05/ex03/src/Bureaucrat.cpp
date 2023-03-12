#include <iostream>
#include <string>

#include "AForm.hpp"

#include "Bureaucrat.hpp"

size_t const Bureaucrat::_topGrade = 1;
size_t const Bureaucrat::_botGrade = 150;

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Bureaucrat::Bureaucrat( std::string const& name, size_t const grade )
  : _name( name ),
    _grade( grade ) {
  checkGradeLimits( _grade );
#if defined( DEBUG )
  std::cout << __FILE__;
  std::cout << " CONSTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Constructor
 */

Bureaucrat::Bureaucrat( Bureaucrat const& src )
  : _name( src._name ),
    _grade( src._grade ) {
  checkGradeLimits( _grade );
#if defined( DEBUG )
  std::cout << __FILE__;
  std::cout << " COPY CONSTRUCTED ";
  std::cout << *this;
  std::cout << " FROM ";
  std::cout << src._name;
  std::cout << std::endl;
#endif
  return;
}

/**
 * @brief       Destructor
 */

Bureaucrat::~Bureaucrat( void ) {
#if defined( DEBUG )
  std::cout << __FILE__;
  std::cout << " DESTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Bureaucrat& Bureaucrat::operator=( Bureaucrat const& rhs ) {
#if defined( DEBUG )
  std::cout << rhs;
  std::cout << " ASSIGNED TO " << *this;
  std::cout << std::endl;
#endif
  if( this == &rhs ) {
    return *this;
  }
  _grade = rhs._grade;
  return *this;
}

/**
 * @brief       Print State
 */

void Bureaucrat::print( std::ostream& o ) const {
  o << _name;
  o << ", bureaucrat grade ";
  o << _grade;
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Bureaucrat const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

void Bureaucrat::checkGradeLimits( size_t const grade ) const {
  if( grade < Bureaucrat::_topGrade ) {
    throw EBureaucratGradeTooHigh( grade );
  } else if( grade > Bureaucrat::_botGrade ) {
    throw EBureaucratGradeTooLow( grade );
  }
  return;
}

void Bureaucrat::upGrade( void ) {
#if defined( DEBUG )
  std::cout << *this << " is up graded to " << _grade - 1;
  std::cout << std::endl;
#endif
  _grade -= 1;
  checkGradeLimits( _grade );
  return;
}

void Bureaucrat::downGrade( void ) {
#if defined( DEBUG )
  std::cout << *this << " is down graded to " << _grade + 1;
  std::cout << std::endl;
#endif
  _grade += 1;
  checkGradeLimits( _grade );
  return;
}

void Bureaucrat::signForm( AForm& f ) const {
  try {
    f.beSigned( *this );
    std::cout << *this << " signed " << f;
    std::cout << std::endl;
  } catch( EAFormGradeTooLow const& e ) {
    std::cout << *this << " couldn't sign " << f << ", grade too low.";
    std::cout << std::endl;
  } catch( ... ) {
    std::cout << "Error occurred during what() message formatting";
    std::cout << std::endl;
  }
  return;
}

void Bureaucrat::executeForm( AForm& f ) const {
  try {
    f.beExecuted( *this );
    std::cout << *this << " executed " << f;
    std::cout << std::endl;
  } catch( EAFormGradeTooLow const& e ) {
    std::cout << *this << " couldn't execute " << f << ", grade too low.";
    std::cout << std::endl;
  } catch( ... ) {
    std::cout << "Error occurred during what() message formatting";
    std::cout << std::endl;
  }
  return;
}

size_t Bureaucrat::giveGrade( void ) const {
  return _grade;
}

/*  GETTERS SETTERS
------------------------------------------------- */

std::string Bureaucrat::getName( void ) const {
  return _name;
}

size_t Bureaucrat::getGrade( void ) const {
  return _grade;
}

/*  EXCEPTIONS
------------------------------------------------- */

EBureaucratGradeTooHigh::GradeTooHighException( size_t const grade )
  : _message( "Error: Grade " + std::to_string( grade ) + " too high" ) {
  return;
}

EBureaucratGradeTooHigh::~GradeTooHighException( void ) throw() {
  return;
}

char const* EBureaucratGradeTooHigh::what( void ) const throw() {
  return _message.c_str();
}

EBureaucratGradeTooLow::GradeTooLowException( size_t const grade )
  : _message( "Error: Grade " + std::to_string( grade ) + " too low" ) {
  return;
}

EBureaucratGradeTooLow::~GradeTooLowException( void ) throw() {
  return;
}

char const* EBureaucratGradeTooLow::what( void ) const throw() {
  return _message.c_str();
}
