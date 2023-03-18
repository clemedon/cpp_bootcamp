#include <iostream>
#include <string>

#include "Data.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Data::Data( int a, float b, char c ) : a_( a ), b_( b ), c_( c ) {
#if defined( DEBUG )
  std::cerr << __FILE__ << " CONSTRUCTED " << *this;
  std::cerr << std::endl;
#endif
}

/**
 * @brief       Destructor
 */

Data::~Data( void ) {
#if defined( DEBUG )
  std::cerr << __FILE__ << " DESTRUCTED " << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Print State
 */

void Data::print( std::ostream& o ) const {
  o << "a_ = " << a_ << std::endl;
  o << "b_ = " << b_ << std::endl;
  o << "c_ = " << c_ << std::endl;
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Data const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */
