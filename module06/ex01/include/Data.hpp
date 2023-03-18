#ifndef DATA_HPP_
#define DATA_HPP_

#include <iosfwd>
#include <string>

/**
 * Data
 */

class Data {
 public:
  Data( int a, float b, char c );
  virtual ~Data( void );
  virtual void print( std::ostream& o ) const;

 private:
  int   a_;
  float b_;
  char  c_;
};

std::ostream& operator<<( std::ostream& o, Data const& i );

#endif  // DATA_HPP_
