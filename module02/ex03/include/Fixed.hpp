// @author    Clément Vidon
// @created   230324 12:46:10  by  clem@spectre
// @modified  230324 12:46:14  by  clem@spectre
// @filename  Fixed.hpp

#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iosfwd>
#include <string>

/**
 * Fixed-point number
 *
 *
 * Data members:
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

  bool operator>( Fixed const& rhs ) const;
  bool operator<( Fixed const& rhs ) const;
  bool operator>=( Fixed const& rhs ) const;
  bool operator<=( Fixed const& rhs ) const;
  bool operator==( Fixed const& rhs ) const;
  bool operator!=( Fixed const& rhs ) const;

  Fixed operator+( Fixed const& rhs ) const;
  Fixed operator-( Fixed const& rhs ) const;
  Fixed operator*( Fixed const& rhs ) const;
  Fixed operator/( Fixed const& rhs ) const;

  Fixed& operator++( void );
  Fixed  operator++( int );
  Fixed& operator--( void );
  Fixed  operator--( int );

  int   getRawBits( void ) const;
  void  setRawBits( int const rawBits );
  float toFloat( void ) const;
  float toInt( void ) const;

  static Fixed min( Fixed& a, Fixed& b );
  static Fixed min( Fixed const& a, Fixed const& b );
  static Fixed max( Fixed& a, Fixed& b );
  static Fixed max( Fixed const& a, Fixed const& b );

 private:
  int              _rawBits;
  static int const _fractionalBits;
};

std::ostream& operator<<( std::ostream& os, Fixed const& i );

#endif  // FIXED_HPP_
