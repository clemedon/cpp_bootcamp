// @author    Clément Vidon
// @created   230417 15:56:01  by  clem@spectre
// @modified  230417 15:57:48  by  clem@spectre
// @filename  Span.cpp

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Span.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Span::Span( void ) : _N( 0 ) {
#if defined( DEV )
  std::cerr << __FILE__ << " CONSTRUCTED " << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Parametric Constructor
 */

Span::Span( unsigned int n ) : _N( n ) {
#if defined( DEV )
  std::cerr << __FILE__ << " CONSTRUCTED " << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Constructor
 */

Span::Span( Span const& src ) {
  *this = src;
#if defined( DEV )
  std::cerr << __FILE__ << " COPY CONSTRUCTED " << *this << " FROM " << src;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Destructor
 */

Span::~Span( void ) {
#if defined( DEV )
  std::cerr << __FILE__ << " DESTRUCTED " << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Span& Span::operator=( Span const& rhs ) {
#if defined( DEV )
  std::cerr << rhs << " ASSIGNED TO " << *this;
  std::cerr << std::endl;
#endif
  if( this == &rhs ) {
    return *this;
  }
  _N = rhs._N;
  _v = std::vector<int>( rhs._v );
  return *this;
}

/**
 * @brief       Print State
 */

void Span::print( std::ostream& o ) const {
  std::vector<int>::const_iterator it;

  for( it = _v.begin(); it != _v.end(); ++it ) {
    if( it - _v.begin() < 5 ) {
      o << *it << "; ";
    } else if( it - _v.begin() == 10 ) {
      o << "[ ... ]  ";
    } else if( _v.end() - it < 5 ) {
      o << *it << "; ";
    }
  }
  std::cout << std::endl;
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Span const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

/**
 * @brief       Add a number to vector
 */

void Span::addNumber( int num ) {
  if( _v.size() >= _N ) {
    throw std::overflow_error( "error: maximum number of elements reached" );
  }
  _v.push_back( num );
  return;
}

/**
 * @brief       Fill vector with the given range of numbers
 */

void Span::addRange( std::vector<int>::iterator begin,
                     std::vector<int>::iterator end ) {
  while( begin != end ) {
    addNumber( *begin );
    begin++;
  }
  return;
}

/**
 * @brief       Return the shortest span between two elements
 */

int Span::shortestSpan( void ) {
  std::vector<int>::iterator it;
  int                        shortest;
  int                        span;

  if( _v.size() < 2 ) {
    throw std::runtime_error( "error: span is less than two elements" );
  }
  std::sort( _v.begin(), _v.end() );
  shortest = _v[1] - _v[0];
  for( it = _v.begin(); it != _v.end() - 1; ++it ) {
    span = *( it + 1 ) - *it;
    if( span < shortest ) {
      shortest = span;
    }
  }
  return shortest;
}

/**
 * @brief       Return the longest span between two elements
 */

int Span::longestSpan( void ) const {
  int min;
  int max;

  if( _v.size() < 2 ) {
    throw std::runtime_error( "error: span is less than two elements" );
  }
  min = *std::min_element( _v.begin(), _v.end() );
  max = *std::max_element( _v.begin(), _v.end() );
  return max - min;
}
