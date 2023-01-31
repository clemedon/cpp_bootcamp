#ifndef ROT_HPP_
#define ROT_HPP_

#include <iostream>

/**
 * Rule of Three
 */

class Rot {
 public:
  Rot( void );
  Rot( int const val, int const ptr );
  Rot( Rot const& src );
  ~Rot( void );
  Rot& operator=( Rot const& src );

  void print( std::ostream& o ) const;

 private:
  int  _val;
  int* _ptr;
};

std::ostream& operator<<( std::ostream& o, Rot const& i );

#endif  // ROT_HPP_
