#ifndef AANIMAL_HPP_
#define AANIMAL_HPP_

#include <iostream>
#include <string>

/**
 * Abstract Animal
 */

class AAnimal {
 public:
  AAnimal( std::string const& type = "AAnimal" );
  AAnimal( AAnimal const& src );
  virtual ~AAnimal( void );
  AAnimal&      operator=( AAnimal const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual void makeSound( void ) const = 0; // pure virtual function
  std::string  getType( void ) const;

 protected:
  std::string _type;
};

std::ostream& operator<<( std::ostream& o, AAnimal const& i );

#endif  // AANIMAL_HPP_
