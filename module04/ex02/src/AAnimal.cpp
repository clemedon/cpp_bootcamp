#include <iostream>
#include <sstream>
#include <string>
#include "AAnimal.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

AAnimal::AAnimal( std::string const& type ) : _type( type ) {
  std::cout << __FILE__;
  std::cout << " CONSTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

AAnimal::AAnimal( AAnimal const& src ) : _type( src._type ) {
  std::cout << src;
  std::cout << " COPIED AS " << *this;
  std::cout << std::endl;
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

AAnimal::~AAnimal( void ) {
  std::cout << __FILE__;
  std::cout << " DESTROYED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

AAnimal& AAnimal::operator=( AAnimal const& rhs ) {
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

void AAnimal::print( std::ostream& o ) const {
  o << this->_type;
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, AAnimal const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

/*  GETTERS SETTERS
------------------------------------------------- */

std::string AAnimal::getType( void ) const {
  return this->_type;
}
