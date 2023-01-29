#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iostream>

/**
 * Fixed-point number
 */

class Fixed {
 public:
  Fixed( void );
  Fixed( Fixed const& src );
  ~Fixed( void );

  Fixed& operator=( Fixed const& src );

  int  getRawBits( void ) const;
  void setRawBits( int const raw );

 private:
  int              _number;
  static int const _point = 8;
};

#endif  // FIXED_HPP_
