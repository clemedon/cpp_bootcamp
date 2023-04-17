// @author    Clément Vidon
// @created   230324 15:35:22  by  clem@spectre
// @modified  230324 15:35:22  by  clem@spectre
// @filename  AAnimal.hpp

#ifndef AANIMAL_HPP_
#define AANIMAL_HPP_

#include <iosfwd>
#include <string>

/**
 * Abstract Animal
 */

class AAnimal {
 public:
  explicit AAnimal( std::string const& type = "AAnimal" );
  AAnimal( AAnimal const& src );
  virtual ~AAnimal( void );
  AAnimal&     operator=( AAnimal const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual void makeSound( void ) const = 0;
  std::string  getType( void ) const;

 protected:
  std::string _type;
};

std::ostream& operator<<( std::ostream& o, AAnimal const& i );

#endif  // AANIMAL_HPP_
