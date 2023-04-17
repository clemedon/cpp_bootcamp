// @author    Clément Vidon
// @created   230324 15:27:38  by  clem@spectre
// @modified  230324 15:27:38  by  clem@spectre
// @filename  Cat.hpp

#ifndef CAT_HPP_
#define CAT_HPP_

#include <iosfwd>
#include <string>

#include "Brain.hpp"

#include "Animal.hpp"

/**
 * Cat
 */

class Cat : public Animal {
 public:
  explicit Cat( std::string const& type = "Cat" );
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
