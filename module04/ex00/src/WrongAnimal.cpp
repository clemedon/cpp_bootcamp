#include <iostream>
#include <sstream>
#include <string>
#include "WrongAnimal.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

WrongAnimal::WrongAnimal( std::string const& type ) : _type( type ) {
  std::cout << *this;
  std::cout << " CONSTRUCTED" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

WrongAnimal::WrongAnimal( Animal const& src ) : _type( src._type ) {
  std::cout << *src;
  std::cout << " COPIED AS " << *this << std::endl;
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

WrongAnimal::~WrongAnimal( void ) {
  std::cout << *this;
  std::cout << " DESTROYED" << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

WrongAnimal& WrongAnimal::operator=( WrongAnimal const& rhs ) {
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

void WrongAnimal::print( std::ostream& o ) const {
  o << this->_type;
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, WrongAnimal const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

void WrongAnimal::makeSound( void ) const {
  std::cout << "*" << this->_type << " sound‥ sounds weird*" << std::endl;
  return;
}

/*  GETTERS SETTERS
------------------------------------------------- */

std::string WrongAnimal::getType( void ) const {
  return this->_type;
}
