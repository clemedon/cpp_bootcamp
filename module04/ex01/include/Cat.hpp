#ifndef CAT_HPP_
#define CAT_HPP_

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

/**
 * Cat
 */

class Cat : public Animal {
 public:
  Cat( std::string const& type = "Cat" );
  Cat( Cat const& src );
  ~Cat( void );
  Cat& operator=( Cat const& rhs );
  void print( std::ostream& o ) const;

  void makeSound( void ) const;

 private:
  Brain* _brain;
};

std::ostream& operator<<( std::ostream& o, Cat const& i );

#endif  // CAT_HPP_
