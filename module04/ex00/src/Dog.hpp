#ifndef DOG_HPP_
#define DOG_HPP_

#include <iostream>
#include <string>
#include "Animal.hpp"

/**
 * Dog
 */

class Dog : public Animal {
 public:
  Dog( std::string const& type = "Dog" );
  Dog( Dog const& src );
  virtual ~Dog( void );
  Dog&         operator=( Dog const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual void makeSound( void ) const;
};

std::ostream& operator<<( std::ostream& o, Dog const& i );

#endif  // DOG_HPP_
