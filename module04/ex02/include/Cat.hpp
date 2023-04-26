// @author    Clément Vidon
// @created   230324 15:35:51  by  clem@spectre
// @modified  230324 15:36:00  by  clem@spectre
// @filename  Cat.hpp

#ifndef CAT_HPP_
#define CAT_HPP_

#include <iosfwd>
#include <string>

#include "Brain.hpp"

#include "AAnimal.hpp"

/**
 * Cat
 */

class Cat : public AAnimal {
 public:
  explicit Cat( void );
  Cat( Cat const& src );
  virtual ~Cat( void );
  Cat&          operator=( Cat const& rhs );
  virtual void  print( std::ostream& o ) const;

  virtual void makeSound( void ) const;

 private:
  Brain* _brain;
};

std::ostream& operator<<( std::ostream& o, Cat const& i );

#endif  // CAT_HPP_
