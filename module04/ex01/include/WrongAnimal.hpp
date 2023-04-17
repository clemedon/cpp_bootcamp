// @author    Clément Vidon
// @created   230324 15:28:07  by  clem@spectre
// @modified  230324 15:28:07  by  clem@spectre
// @filename  WrongAnimal.hpp

#ifndef WRONGANIMAL_HPP_
#define WRONGANIMAL_HPP_

#include <iosfwd>
#include <string>

/**
 * WrongAnimal
 */

class WrongAnimal {
 public:
  explicit WrongAnimal( std::string const& type = "WrongAnimal" );
  WrongAnimal( WrongAnimal const& src );
  virtual ~WrongAnimal( void );
  WrongAnimal& operator=( WrongAnimal const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual void makeSound( void ) const;
  std::string  getType( void ) const;

 protected:
  std::string _type;
};

std::ostream& operator<<( std::ostream& o, WrongAnimal const& i );

#endif  // WRONGANIMAL_HPP_
