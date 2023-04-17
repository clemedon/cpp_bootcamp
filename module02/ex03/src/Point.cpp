// @author    Clément Vidon
// @created   230323 20:16:58  by  clem@spectre
// @modified  230324 12:13:49  by  clem@spectre
// @filename  Point.cpp

#include <iostream>

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
  return ( _x );
}

Fixed Point::get_y( void ) const {
  return ( _y );
}
