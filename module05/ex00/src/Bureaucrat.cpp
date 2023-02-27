#include <iostream>
#include <sstream>
#include <string>
#include "Bureaucrat.hpp"

size_t Bureaucrat::_topLevel = 1;
size_t Bureaucrat::_botLevel = 150;

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Bureaucrat::Bureaucrat( std::string const& name, size_t grade )
  : _name( name ),
    _grade( grade ) {
  if( this->_grade < Bureaucrat::_topLevel ) {
    throw Bureaucrat::GradeTooHighException( this->_grade );
  } else if( this->_grade > Bureaucrat::_botLevel ) {
    throw Bureaucrat::GradeTooLowException( this->_grade );
  }
  std::cout << __FILE__;
  std::cout << " CONSTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

Bureaucrat::Bureaucrat( Bureaucrat const& src )
  : _name( src._name ),
    _grade( src._grade ) {
  if( src._grade > Bureaucrat::_topLevel ) {
    throw Bureaucrat::GradeTooHighException( src._grade );
  } else if( src._grade < Bureaucrat::_botLevel ) {
    throw Bureaucrat::GradeTooLowException( src._grade );
  }
  *this = src;
  std::cout << src;
  std::cout << " COPIED AS " << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

Bureaucrat::~Bureaucrat( void ) {
  std::cout << __FILE__;
  std::cout << " DESTROYED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Bureaucrat& Bureaucrat::operator=( Bureaucrat const& rhs ) {
  std::cout << rhs;
  std::cout << " ASSIGNED TO " << *this;
  std::cout << std::endl;
  if( this == &rhs ) {
    return *this;
  }
  // TODO
  // _name is const
  /* this->_name = rhs._name; */
  /* this->_grade = rhs._grade; */
  *this = rhs;
  return *this;
}

/**
 * @brief       Print State
 */

void Bureaucrat::print( std::ostream& o ) const {
  o << this->_name;
  o << ", bureaucrat grade ";
  o << this->_grade;
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

void Bureaucrat::upGrade( void ) {
  this->_grade -= 1;
  if( this->_grade < Bureaucrat::_topLevel ) {
    throw Bureaucrat::GradeTooHighException( this->_grade );
  } else if( this->_grade > Bureaucrat::_botLevel ) {
    throw Bureaucrat::GradeTooLowException( this->_grade );
  }
}

void Bureaucrat::downGrade( void ) {
  this->_grade += 1;
  if( this->_grade < Bureaucrat::_topLevel ) {
    throw Bureaucrat::GradeTooHighException( this->_grade ); // TODO instantiated
  } else if( this->_grade > Bureaucrat::_botLevel ) {
    throw Bureaucrat::GradeTooLowException( this->_grade );
  }
}

/*  EXCEPTIONS TODO
------------------------------------------------- */

// TODO where is it instantiated
Bureaucrat::GradeTooHighException::GradeTooHighException( size_t grade )
  : _grade( grade ) {
}

char const* Bureaucrat::GradeTooHighException::what( void ) const throw() {
  std::cerr << this->_grade << " ";
  return ( "Grade Too High" );
}

Bureaucrat::GradeTooLowException::GradeTooLowException( size_t grade )
  : _grade( grade ) {
}

char const* Bureaucrat::GradeTooLowException::what( void ) const throw() {
  std::cerr << this->_grade << " ";
  return ( "Grade Too Low" );
}


/*  GETTERS SETTERS
------------------------------------------------- */

std::string Bureaucrat::getName( void ) const {
  return this->_name;
}

std::size_t Bureaucrat::getGrade( void ) const {
  return this->_grade;
}
