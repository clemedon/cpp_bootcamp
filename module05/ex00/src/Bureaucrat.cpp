// @author    Clément Vidon
// @created   230417 10:28:33  by  clem@spectre
// @modified  230417 11:22:07  by  clem@spectre
// @filename  Bureaucrat.cpp

#include <iostream>
#include <string>

#include "utils.hpp"

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
#if defined( DEV )
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
#if defined( DEV )
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
#if defined( DEV )
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
#if defined( DEV )
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
    throw EGradeTooHigh( grade );
  } else if( grade > Bureaucrat::_botGrade ) {
    throw EGradeTooLow( grade );
  }
  return;
}

void Bureaucrat::upGrade( void ) {
#if defined( DEV )
  std::cout << *this << " is up graded to " << _grade - 1;
  std::cout << std::endl;
#endif
  _grade -= 1;
  checkGradeLimits( _grade );
  return;
}

void Bureaucrat::downGrade( void ) {
#if defined( DEV )
  std::cout << *this << " is down graded to " << _grade + 1;
  std::cout << std::endl;
#endif
  _grade += 1;
  checkGradeLimits( _grade );
  return;
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

EGradeTooHigh::GradeTooHighException( size_t const grade )
  : _message( "Error: Grade " + intToString( static_cast<int>( grade ) )
              + " too high" ) {
  return;
}

EGradeTooHigh::~GradeTooHighException( void ) throw() {
  return;
}

char const* EGradeTooHigh::what( void ) const throw() {
  return _message.c_str();
}

EGradeTooLow::GradeTooLowException( size_t const grade )
  : _message( "Error: Grade " + intToString( static_cast<int>( grade ) )
              + " too low" ) {
  return;
}

EGradeTooLow::~GradeTooLowException( void ) throw() {
  return;
}

char const* EGradeTooLow::what( void ) const throw() {
  return _message.c_str();
}
