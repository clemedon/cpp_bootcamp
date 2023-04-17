// @author    Clément Vidon
// @created   230323 20:19:10  by  clem@spectre
// @modified  230324 12:28:43  by  clem@spectre
// @filename  Point.hpp

#ifndef POINT_HPP_
#define POINT_HPP_

#include <iosfwd>
#include <string>

#include "Fixed.hpp"

/**
 * Point
 *
 *
 * Data members:
 *
 * _x :
 *    the x-axis coordinate
 *
 * _y :
 *    the y-axis coordinate
 */

class Point {
 public:
  Point( void );
  Point( float const& x, float const& y );
  Point( Point const& src );
  virtual ~Point( void );
  Point&       operator=( Point const& rhs );
  virtual void print( std::ostream& o ) const;

  Fixed get_x( void ) const;
  Fixed get_y( void ) const;

 private:
  Fixed const _x;
  Fixed const _y;
};

std::ostream& operator<<( std::ostream& o, Point const& i );

#endif  // POINT_HPP_
