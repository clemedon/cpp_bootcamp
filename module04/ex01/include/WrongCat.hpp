#ifndef WRONGCAT_HPP_
#define WRONGCAT_HPP_

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

/**
 * WrongCat
 */

class WrongCat : public WrongAnimal {
 public:
  WrongCat( std::string const& type = "WrongCat" );
  WrongCat( WrongCat const& src );
  ~WrongCat( void );
  WrongCat& operator=( WrongCat const& rhs );
  void      print( std::ostream& o ) const;

  void makeSound( void ) const;
};

std::ostream& operator<<( std::ostream& o, WrongCat const& i );

#endif  // WRONGCAT_HPP_
