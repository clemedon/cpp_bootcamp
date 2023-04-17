// @author    Clément Vidon
// @created   230324 15:20:50  by  clem@spectre
// @modified  230324 15:21:16  by  clem@spectre
// @filename  Animal.cpp

#include <iostream>
#include <string>

#include "Animal.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Animal::Animal( std::string const& type ) : _type( type ) {
  std::cout << *this;
  std::cout << " CONSTRUCTED ";
  std::cout << _type;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

Animal::Animal( Animal const& src ) : _type( src._type ) {
  std::cout << src;
  std::cout << " COPIED AS " << *this;
  std::cout << std::endl;
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

Animal::~Animal( void ) {
  std::cout << *this;
  std::cout << " DESTROYED ";
  std::cout << _type;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Animal& Animal::operator=( Animal const& rhs ) {
  std::cout << rhs;
  std::cout << " ASSIGNED TO " << *this;
  std::cout << std::endl;
  if( this == &rhs ) {
    return *this;
  }
  _type = rhs._type;
  return *this;
}

/**
 * @brief       Print State
 */

void Animal::print( std::ostream& o ) const {
  o << _type;
  std::cout << " (via " << __FILE__ << ")";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Animal const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

void Animal::makeSound( void ) const {
  std::cout << "*" << _type << " sound‥ silence*";
  std::cout << std::endl;
  return;
}

/*  GETTERS SETTERS
------------------------------------------------- */

std::string Animal::getType( void ) const {
  return _type;
}
