// @author    Clément Vidon
// @created   230324 15:20:12  by  clem@spectre
// @modified  230324 15:20:34  by  clem@spectre
// @filename  WrongCat.hpp

#ifndef WRONGCAT_HPP_
#define WRONGCAT_HPP_

#include <iosfwd>
#include <string>

#include "WrongAnimal.hpp"

/**
 * WrongCat
 */

class WrongCat : public WrongAnimal {
 public:
  explicit WrongCat( std::string const& type = "WrongCat" );
  WrongCat( WrongCat const& src );
  virtual ~WrongCat( void );
  WrongCat&    operator=( WrongCat const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual void makeSound( void ) const;
};

std::ostream& operator<<( std::ostream& o, WrongCat const& i );

#endif  // WRONGCAT_HPP_
