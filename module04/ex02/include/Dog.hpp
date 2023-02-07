#ifndef DOG_HPP_
#define DOG_HPP_

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

/**
 * Dog
 */

class Dog : public AAnimal {
 public:
  Dog( std::string const& type = "Dog" );
  Dog( Dog const& src );
  ~Dog( void );
  Dog& operator=( Dog const& rhs );
  void print( std::ostream& o ) const;

  void makeSound( void ) const;

 private:
  Brain* _brain;
};

std::ostream& operator<<( std::ostream& o, Dog const& i );

#endif  // DOG_HPP_
