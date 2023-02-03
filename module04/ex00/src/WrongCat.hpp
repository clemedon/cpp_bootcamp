#ifndef WRONGCAT_HPP_
#define WRONGCAT_HPP_

#include <iostream>
#include <string>
#include "Animal.hpp"

/**
 * WrongCat
 */

class WrongCat : public WrongAnimal {
 public:
  WrongCat( std::string const& type = "WrongCat" );
  WrongCat( WrongCat const& src );
  virtual ~WrongCat( void );
  WrongCat&    operator=( WrongCat const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual void makeSound( void ) const;
};

std::ostream& operator<<( std::ostream& o, WrongCat const& i );

#endif  // WRONGCAT_HPP_
