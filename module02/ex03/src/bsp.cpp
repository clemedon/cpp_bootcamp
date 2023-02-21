#include <iostream>
#include "Point.hpp"

/**
 * @brief       Calculate area of triangle
 *
 * @param[in]   a a point
 * @param[in]   b a point
 * @param[in]   c a point
 * @return      the area of the triangle
 */

float area( Point const& a, Point const& b, Point const& c ) {
  float x1;
  float y1;
  float x2;
  float y2;
  float x3;
  float y3;
  float area;

  x1 = a.get_x().toFloat();
  y1 = a.get_y().toFloat();
  x2 = b.get_x().toFloat();
  y2 = b.get_y().toFloat();
  x3 = c.get_x().toFloat();
  y3 = c.get_y().toFloat();
  area = ( x1 * ( y2 - y3 ) + x2 * ( y3 - y1 ) + x3 * ( y1 - y2 ) ) / 2.0;
  if( area < 0 )
    area *= -1;
  return ( area );
}

/**
 * @brief       Check whether a point lies inside a triangle area
 *
 * https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
 *
 * @param[in]   a a point of the triangle
 * @param[in]   b a point of the triangle
 * @param[in]   c a point of the triangle
 * @param[in]   p a point
 * @return      true or flase if p point is inside abc triangle
 */

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
  float abc;
  float pbc;
  float pac;
  float pab;

  abc = area( a, b, c );
  pbc = area( point, b, c );
  pac = area( a, point, c );
  pab = area( a, b, point );
  if( pbc == 0 || pac == 0 || pab == 0 )
    return ( false );
  if( abc != pbc + pac + pab )
    return ( false );
  return ( true );
}
