#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iosfwd>
#include <string>

class AMateria;

#include "ICharacter.hpp"

/**
 * Character
 *
 *
 * Data members
 *
 *  _name
 *    the character's name
 *
 *  _inventory
 *    the character's inventory which can hold up to 4 Materias
 */

const int g_inventorySize = 4;

class Character : public ICharacter {
 public:
  Character( std::string const& name = "Unknown" );
  Character( ICharacter const& src );
  virtual ~Character( void );
  virtual ICharacter& operator=( ICharacter const& rhs );
  virtual void        print( std::ostream& o ) const;

  virtual void equip( AMateria* m );
  virtual void unequip( int idx );
  virtual void use( int idx, ICharacter& target );
  virtual void displayInventory( void ) const;

  virtual std::string const& getName( void ) const;
  virtual AMateria*          getInventory( int idx ) const;

 private:
  std::string* _name;
  AMateria*    _inventory[g_inventorySize];
};

std::ostream& operator<<( std::ostream& o, ICharacter const& i );

#endif  // CHARACTER_HPP_
