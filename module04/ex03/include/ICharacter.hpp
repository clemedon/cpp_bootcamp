// @author    Clément Vidon
// @created   230422 17:14:43  by  cvidon@e1r9p17.clusters.42paris.fr
// @modified  230422 17:14:43  by  cvidon@e1r9p17.clusters.42paris.fr
// @filename  ICharacter.hpp

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

#include <string>

class AMateria;

/**
 * Character Interface
 */

class ICharacter {
 public:
  virtual ~ICharacter() {}
  virtual ICharacter& operator=( ICharacter const& rhs ) = 0;
  virtual void        print( std::ostream& o ) const = 0;

  virtual void equip( AMateria* m ) = 0;
  virtual void unequip( int idx ) = 0;
  virtual void use( int idx, ICharacter& target ) = 0;

  virtual void                displayInventory( void ) const = 0;
  virtual std::string const&  getName( void ) const = 0;
  virtual AMateria*           getInventory( int idx ) const = 0;
};

#endif  // ICHARACTER_HPP_
