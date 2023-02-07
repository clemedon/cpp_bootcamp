#include <iostream>
#include <sstream>
#include <string>
#include "Dog.hpp"

/*  STANDARD
    ------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Dog::Dog( std::string const& type ) : AAnimal( type ), _brain( new Brain() ) {
  std::cout << __FILE__;
  std::cout << " CONSTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

Dog::Dog( Dog const& src )
  : AAnimal( src._type ),
    _brain( new Brain( *src._brain ) ) {
  std::cout << src;
  std::cout << " COPIED AS " << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

Dog::~Dog( void ) {
  delete this->_brain;
  std::cout << __FILE__;
  std::cout << " DESTROYED ";
  std::cout << *this;
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
  delete this->_brain;
  this->_brain = new Brain( *rhs._brain );
  this->_type = rhs._type;
  return *this;
}

/**
 * @brief       Print State
 */

void Dog::print( std::ostream& o ) const {
  o << this->_type;
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
  std::cout << "*" << *this << " sound*";
  std::cout << std::endl;
  return;
}
