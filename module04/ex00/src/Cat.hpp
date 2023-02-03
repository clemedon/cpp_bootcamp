#ifndef CAT_HPP_
#define CAT_HPP_

#include <iostream>
#include <string>
#include "Animal.hpp"

/**
 * Cat
 */

class Cat : public Animal {
 public:
  Cat( std::string const& type = "Cat" );
  Cat( Cat const& src );
  virtual ~Cat( void );
  Cat&         operator=( Cat const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual void makeSound( void ) const;
};

std::ostream& operator<<( std::ostream& o, Cat const& i );

#endif  // CAT_HPP_
