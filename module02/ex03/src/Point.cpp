#include <iostream>
#include <sstream>
#include <string>
#include "Point.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Point::Point( void ) : _x( 0 ), _y( 0 ) {
  return;
}

/**
 * @brief       Parametric Constructor
 */

Point::Point( float const& x, float const& y )
  : _x( Fixed( x ) ),
    _y( Fixed( y ) ) {
  return;
}

/**
 * @brief       Copy Constructor
 */

Point::Point( Point const& src ) : _x( src._x ), _y( src._y ) {
  *this = src;
  return;
}

/**
 * @brief       Destructor
 */

Point::~Point( void ) {
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Point& Point::operator=( Point const& rhs ) {
  if( this == &rhs ) {
    return *this;
  }
  return *this;
}

/**
 * @brief       Print State
 */

void Point::print( std::ostream& o ) const {
  o << "Point";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Point const& i ) {
  i.print( o );
  return o;
}

/*  GETTERS
------------------------------------------------- */

Fixed Point::get_x( void ) const {
  return ( this->_x );
}

Fixed Point::get_y( void ) const {
  return ( this->_y );
}
