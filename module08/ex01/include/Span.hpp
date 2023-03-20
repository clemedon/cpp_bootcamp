#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <cstddef>
#include <iosfwd>
#include <string>
#include <vector>

/**
 * Span
 */

class Span {
 public:
  Span( void );
  explicit Span( unsigned int n = 0 );
  Span( Span const& src );
  virtual ~Span( void );
  Span&        operator=( Span const& rhs );
  virtual void print( std::ostream& o ) const;

  void addNumber( int num );
  void addRange( std::vector<int>::iterator beg,
                 std::vector<int>::iterator end );
  int  shortestSpan( void );
  int  longestSpan( void ) const;

 private:
  unsigned int     _N;
  std::vector<int> _v;
};

std::ostream& operator<<( std::ostream& o, Span const& i );

#endif  // SPAN_HPP_
