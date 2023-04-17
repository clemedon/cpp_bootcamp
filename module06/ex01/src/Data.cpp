// @author    Clément Vidon
// @created   230417 15:29:57  by  clem@spectre
// @modified  230417 15:46:16  by  clem@spectre
// @filename  Data.cpp

#include <iostream>
#include <string>

#include "Data.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Data::Data( int a, float b, char c ) : a_( a ), b_( b ), c_( c ) {
#if defined( DEV )
  std::cerr << __FILE__ << " CONSTRUCTED ";
  std::cerr << std::endl;
  std::cerr << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Destructor
 */

Data::~Data( void ) {
#if defined( DEV )
  std::cerr << __FILE__ << " DESTRUCTED ";
  std::cerr << std::endl;
  std::cerr << *this;
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
