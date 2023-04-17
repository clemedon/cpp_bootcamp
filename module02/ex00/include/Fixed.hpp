// @author    Clément Vidon
// @created   230324 12:03:26  by  clem@spectre
// @modified  230324 12:03:27  by  clem@spectre
// @filename  Fixed.hpp

#ifndef FIXED_HPP_
#define FIXED_HPP_

/**
 * Fixed-point number
 */

class Fixed {
 public:
  Fixed( void );
  Fixed( Fixed const& src );
  ~Fixed( void );
  Fixed& operator=( Fixed const& rhs );

  int  getRawBits( void ) const;
  void setRawBits( int const raw );

 private:
  int              _number;
  static int const _point;
};

#endif  // FIXED_HPP_
