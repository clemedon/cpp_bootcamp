#include <iostream>
#include <sstream>
#include <string>
#include "Cat.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Cat::Cat( std::string const& type ) : Animal( type ) {
  std::cout << *this;
  std::cout << " CONSTRUCTED ";
  std::cout << this->_type;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

Cat::Cat( Cat const& src ) : Animal( src._type ) {
  std::cout << src;
  std::cout << " COPIED AS " << *this;
  std::cout << std::endl;
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

Cat::~Cat( void ) {
  std::cout << *this;
  std::cout << " DESTROYED ";
  std::cout << this->_type;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Cat& Cat::operator=( Cat const& rhs ) {
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

void Cat::print( std::ostream& o ) const {
  o << this->_type;
  std::cout << " (via " << __FILE__ << ")";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Cat const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

void Cat::makeSound( void ) const {
  std::cout << "*" << this->_type << " sound*";
  std::cout << std::endl;
  return;
}
