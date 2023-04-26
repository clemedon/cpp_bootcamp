// @author    Clément Vidon
// @created   230324 15:40:11  by  clem@spectre
// @modified  230324 15:40:11  by  clem@spectre
// @filename  Dog.cpp

#include <iostream>
#include <string>

#include "Dog.hpp"

/*  STANDARD
    ------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Dog::Dog( void ) : AAnimal( "Dog" ), _brain( new Brain() ) {
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
  delete _brain;
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
  delete _brain;
  _brain = new Brain( *rhs._brain );
  _type = rhs._type;
  return *this;
}

/**
 * @brief       Print State
 */

void Dog::print( std::ostream& o ) const {
  o << _type;
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
