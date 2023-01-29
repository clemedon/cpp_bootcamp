#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iostream>
#include <string>

/**
 * Fixed-point number
 *
 * The fixed-point representation of 1 is expressed as 1 << 8 ( or 256 ) because
 * it has 8 bits for the fractional part.  This means that when we divide a
 * number x with a fixed point number y with the value 1, we will arrive at the
 * same number x, but shifted right by 8.
 *
 * Data members
 *
 * _rawBits :
 *    the raw value of the fixed-point value
 *
 * _fractionalBits :
 *    the number of fractional bits
 */

class Fixed {
 public:
  Fixed( void );
  Fixed( int const& number );
  Fixed( float const& number );
  Fixed( Fixed const& src );
  ~Fixed( void );

  Fixed& operator=( Fixed const& rhs );

  int   getRawBits( void ) const;
  void  setRawBits( int const rawBits );
  float toFloat( void ) const;
  float toInt( void ) const;

 private:
  int              _rawBits;
  static int const _fractionalBits;
};

std::ostream& operator<<( std::ostream& os, Fixed const& i );

#endif  // FIXED_HPP_
