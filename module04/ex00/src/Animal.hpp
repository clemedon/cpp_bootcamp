#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <iostream>
#include <string>

/**
 * Animal
 */

class Animal {
 public:
  Animal( std::string const& type = "Animal" );
  Animal( Animal const& src );
  virtual ~Animal( void );
  Animal&      operator=( Animal const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual void makeSound( void ) const;
  std::string  getType( void ) const;

 protected:
  std::string _type;
};

std::ostream& operator<<( std::ostream& o, Animal const& i );

#endif  // ANIMAL_HPP_
