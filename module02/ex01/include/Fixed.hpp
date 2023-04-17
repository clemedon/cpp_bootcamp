// @author    Clément Vidon
// @created   230324 12:11:42  by  clem@spectre
// @modified  230324 12:11:42  by  clem@spectre
// @filename  Fixed.hpp

#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iosfwd>
#include <string>

/**
 * Fixed-point number
 *
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
