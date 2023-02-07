#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <iostream>
#include <string>

/**
 * Brain
 */

class Brain {
 public:
  Brain( void );
  Brain( Brain const& src );
  ~Brain( void );
  Brain& operator=( Brain const& rhs );
  void   print( std::ostream& o ) const;

  void printIdea( size_t index ) const;
  void saveIdea( size_t index, std::string const& idea );

 private:
  const size_t _size;
  std::string* _ideas;
};

std::ostream& operator<<( std::ostream& o, Brain const& i );

#endif  // BRAIN_HPP_
