#ifndef CANON_HPP_
#define CANON_HPP_

#include <iostream>
#include <string>

/**
 * TODO
 */

class Canon {
 public:
  Canon( void );
  Canon( Canon const& src );
  ~Canon( void );
  Canon& operator=( Canon const& rhs );

  void print( std::ostream& o ) const;

 private:
};

std::ostream& operator<<( std::ostream& os, Canon const& i );

#endif  // CANON_HPP_
