#include <iostream>
#include <sstream>
#include <string>
#include "Canon.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Canon::Canon( void ) {
  return;
}

/**
 * @brief       Copy Constructor
 */

Canon::Canon( Canon const& src ) {
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

Canon::~Canon( void ) {
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Canon& Canon::operator=( Canon const& rhs ) {
  if( this == &rhs ) {
    return *this;
  }
  return *this;
}

/**
 * @brief       Print State
 */

void Canon::print( std::ostream& o ) const {
  o << "class: Canon";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Canon const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */
