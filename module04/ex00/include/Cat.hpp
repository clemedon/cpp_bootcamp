// @author    Clément Vidon
// @created   230324 15:19:39  by  clem@spectre
// @modified  230324 15:19:39  by  clem@spectre
// @filename  Cat.hpp

#ifndef CAT_HPP_
#define CAT_HPP_

#include <iosfwd>
#include <string>

#include "Animal.hpp"

/**
 * Cat
 */

class Cat : public Animal {
 public:
  explicit Cat( void );
  Cat( Cat const& src );
  virtual ~Cat( void );
  Cat&         operator=( Cat const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual void makeSound( void ) const;
};

std::ostream& operator<<( std::ostream& o, Cat const& i );

#endif  // CAT_HPP_
