// @author    Clément Vidon
// @created   230417 14:48:31  by  clem@spectre
// @modified  230417 14:50:06  by  clem@spectre
// @filename  AForm.cpp

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "utils.hpp"

#include "AForm.hpp"

size_t const AForm::_topGrade = 1;
size_t const AForm::_botGrade = 150;

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

AForm::AForm( std::string const& name,
              bool const         s,
              size_t const       signGrade,
              size_t const       execGrade )
  : _name( name ),
    _signed( s ),
    _signGrade( signGrade ),
    _execGrade( execGrade ) {
  checkGradeLimits( _signGrade );
  checkGradeLimits( _execGrade );
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

AForm::AForm( AForm const& src )
  : _name( src._name ),
    _signed( src._signed ),
    _signGrade( src._signGrade ),
    _execGrade( src._execGrade ) {
  checkGradeLimits( _signGrade );
  checkGradeLimits( _execGrade );
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

AForm::~AForm( void ) {
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

AForm& AForm::operator=( AForm const& rhs ) {
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

void AForm::print( std::ostream& o ) const {
  o << "[ Form: ";
  o << _name;
  o << " SIG_";
  o << _signGrade;
  o << " EXE_";
  o << _execGrade;
  if( _signed ) {
    o << " SIGNED ]";
  } else {
    o << " UNSIGNED ]";
  }
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, AForm const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

void AForm::checkGradeLimits( size_t const grade ) const {
  if( grade < AForm::_topGrade ) {
    throw EAFormGradeTooHigh( grade );
  } else if( grade > AForm::_botGrade ) {
    throw EAFormGradeTooLow( grade );
  }
  return;
}

void AForm::beSigned( Bureaucrat const& b ) {
  size_t const bGrade = b.giveGrade();

  if( _signed ) {
    std::cout << *this << " form already signed." << std::endl;
  } else {
    if( _signGrade < bGrade ) {
      throw EAFormGradeTooLow( bGrade );
    } else {
      _signed = true;
    }
  }
  return;
}

void AForm::beExecuted( Bureaucrat const& b ) {
  size_t const bGrade = b.giveGrade();

  if( _signed == false ) {
    std::cout << *this << " form has to be signed first." << std::endl;
  } else {
    if( _execGrade < bGrade ) {
      throw EAFormGradeTooLow( bGrade );
    } else {
      execute( b );
    }
  }
  return;
}

bool AForm::isSigned( void ) const {
  return _signed == true;
}

/*  GETTERS SETTERS
------------------------------------------------- */

std::string AForm::getName( void ) const {
  return _name;
}

bool AForm::getSigned( void ) const {
  return _signed;
}

size_t AForm::getSignGrade( void ) const {
  return _signGrade;
}

size_t AForm::getExecGrade( void ) const {
  return _execGrade;
}

/*  EXCEPTIONS
------------------------------------------------- */

EAFormGradeTooHigh::GradeTooHighException( size_t const grade )
  : _message( "Error: Grade " + intToString( static_cast<int>( grade ) )
              + " too high" ) {
  return;
}

EAFormGradeTooHigh::~GradeTooHighException( void ) throw() {
  return;
}

char const* EAFormGradeTooHigh::what( void ) const throw() {
  return _message.c_str();
}

EAFormGradeTooLow::GradeTooLowException( size_t const grade )
  : _message( "Error: Grade " + intToString( static_cast<int>( grade ) )
              + " too low" ) {
  return;
}

EAFormGradeTooLow::~GradeTooLowException( void ) throw() {
  return;
}

char const* EAFormGradeTooLow::what( void ) const throw() {
  return _message.c_str();
}
