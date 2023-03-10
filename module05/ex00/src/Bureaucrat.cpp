#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

size_t const Bureaucrat::_topLevel = 1;
size_t const Bureaucrat::_botLevel = 150;

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Bureaucrat::Bureaucrat( std::string const& name, size_t const& grade )
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
  checkGradeLimits( src._grade );
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

void Bureaucrat::checkGradeLimits( size_t const& grade ) const {
  if( grade < Bureaucrat::_topLevel ) {
    throw EGradeTooHigh( grade );
  } else if( grade > Bureaucrat::_botLevel ) {
    throw EGradeTooLow( grade );
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

/*  EXCEPTIONS
------------------------------------------------- */

EGradeTooHigh::GradeTooHighException( size_t grade )
  : _message( "Error: Grade " + std::to_string( grade )
              + " grade abnormaly high" ) {
  return;
}

EGradeTooHigh::~GradeTooHighException( void ) throw() {
  return;
}

char const* EGradeTooHigh::what( void ) const throw() {
  return _message.c_str();
}

EGradeTooLow::GradeTooLowException( size_t grade )
  : _message( "Error: Grade " + std::to_string( grade )
              + " is abnormaly low" ) {
  return;
}

EGradeTooLow::~GradeTooLowException( void ) throw() {
  return;
}

char const* EGradeTooLow::what( void ) const throw() {
  return _message.c_str();
}

/*  GETTERS SETTERS
------------------------------------------------- */

std::string Bureaucrat::getName( void ) const {
  return _name;
}

std::size_t Bureaucrat::getGrade( void ) const {
  return _grade;
}
