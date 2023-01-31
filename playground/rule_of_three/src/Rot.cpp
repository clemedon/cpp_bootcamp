#include <iostream>
#include <sstream>
#include "Rot.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Rot::Rot( void ) : _val( 0 ), _ptr( new int() ) {
  std::cout << "Default Constructor called" << std::endl;
  return;
}

/**
 * @brief       Parametric Constructor
 */

Rot::Rot( int const val, int ptr ) : _val( val ), _ptr( new int( ptr ) ) {
  std::cout << "Parametric Constructor called" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

Rot::Rot( Rot const& src ) : _val( src._val ), _ptr( new int( *src._ptr ) ) {
  std::cout << "Copy Constructor called" << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

Rot::~Rot( void ) {
  std::cout << "Destructor called" << std::endl;
  delete this->_ptr;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Rot& Rot::operator=( Rot const& src ) {
  if( this == &src ) {
    return *this;
  }
  this->_val = src._val;
  *this->_ptr = *src._ptr;

  // deep copy (for objects)

  /* delete this->_ptr; */
  /* this->_ptr = new int (*src._ptr); */

  return *this;
}

/**
 * @brief       Print Instance State
 */

void Rot::print( std::ostream& o ) const {
  o << "  _val: " << this->_val;
  o << "  _ptr: " << *this->_ptr;
  o << "  " << this->_ptr;
  return;
}

/* ---------------------------------------------- */

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Rot const& i ) {
  i.print( o );
  return o;
}
