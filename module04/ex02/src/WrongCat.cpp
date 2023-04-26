// @author    Clément Vidon
// @created   230324 15:41:43  by  clem@spectre
// @modified  230324 15:41:43  by  clem@spectre
// @filename  WrongCat.cpp

#include <iostream>
#include <string>

#include "WrongCat.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

WrongCat::WrongCat( void ) : WrongAnimal( "WrongCat" ) {
  std::cout << *this;
  std::cout << " CONSTRUCTED ";
  std::cout << _type;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

WrongCat::WrongCat( WrongCat const& src ) : WrongAnimal( src._type ) {
  std::cout << src;
  std::cout << " COPIED AS " << *this;
  std::cout << std::endl;
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

WrongCat::~WrongCat( void ) {
  std::cout << *this;
  std::cout << " DESTROYED ";
  std::cout << _type;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

WrongCat& WrongCat::operator=( WrongCat const& rhs ) {
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

void WrongCat::print( std::ostream& o ) const {
  o << _type;
  std::cout << " (via " << __FILE__ << ")";
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
  std::cout << "*" << _type << " sound*";
  std::cout << std::endl;
  return;
}
