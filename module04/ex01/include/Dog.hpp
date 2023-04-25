// @author    Clément Vidon
// @created   230324 15:27:55  by  clem@spectre
// @modified  230324 15:27:55  by  clem@spectre
// @filename  Dog.hpp

#ifndef DOG_HPP_
#define DOG_HPP_

#include <iosfwd>
#include <string>

#include "Brain.hpp"

#include "Animal.hpp"

/**
 * Dog
 */

class Dog : public Animal {
 public:
  explicit Dog( std::string const& type = "Dog" );
  Dog( Dog const& src );
  virtual ~Dog( void );
  Dog&      operator=( Dog const& rhs );
  virtual   void print( std::ostream& o ) const;

  virtual void makeSound( void ) const;

 private:
  Brain* _brain;
};

std::ostream& operator<<( std::ostream& o, Dog const& i );

#endif  // DOG_HPP_
