#include <iostream>
#include <sstream>
#include <string>
#include "Dog.hpp"

/*  STANDARD
    ------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Dog::Dog( std::string const& type ) : Animal( type ) {
  std::cout << *this;
  std::cout << " CONSTRUCTED ";
  std::cout << this->_type;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

Dog::Dog( Dog const& src ) : Animal( src._type ) {
  std::cout << src;
  std::cout << " COPIED AS " << *this;
  std::cout << std::endl;
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

Dog::~Dog( void ) {
  std::cout << *this;
  std::cout << " DESTROYED ";
  std::cout << this->_type;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Dog& Dog::operator=( Dog const& rhs ) {
  std::cout << rhs;
  std::cout << " ASSIGNED TO " << *this;
  std::cout << std::endl;
  if( this == &rhs ) {
    return *this;
  }
  this->_type = rhs._type;
  return *this;
}

/**
 * @brief       Print State
 */

void Dog::print( std::ostream& o ) const {
  o << this->_type;
  std::cout << " (via " << __FILE__ << ")";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Dog const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

void Dog::makeSound( void ) const {
  std::cout << "*" << this->_type << " sound*";
  std::cout << std::endl;
  return;
}
