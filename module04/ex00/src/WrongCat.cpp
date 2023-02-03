#include <iostream>
#include <sstream>
#include <string>
#include "WrongCat.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Cat::Cat( std::string const& type ) : Animal( type ) {
  std::cout << *this;
  std::cout << " CONSTRUCTED" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

WrongCat::WrongCat( WrongCat const& src ) : Animal( src._type ) {
  std::cout << *src;
  std::cout << " COPIED AS " << *this << std::endl;
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

WrongCat::~WrongCat( void ) {
  std::cout << *this;
  std::cout << " DESTROYED" << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

WrongCat& WrongCat::operator=( WrongCat const& rhs ) {
  std::cout << rhs;
  std::cout << " ASSIGNED TO " << *this << std::endl;
  if( this == &rhs ) {
    return *this;
  }
  this->_type = rhs._type;
  return *this;
}

/**
 * @brief       Print State
 */

void WrongCat::print( std::ostream& o ) const {
  o << this->_type;
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, WrongCat const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

void WrongCat::makeSound( void ) const {
  std::cout << "*" << this->_type << " sound*" << std::endl;
  return;
}
