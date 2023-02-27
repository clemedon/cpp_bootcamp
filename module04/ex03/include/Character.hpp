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
  Character( Character const& src );
  ~Character( void );
  Character& operator=( Character const& rhs );
  void       print( std::ostream& o ) const;

  void equip( AMateria* m );
  void unequip( int idx );
  void use( int idx, ICharacter& target );

  std::string const& getName() const;

 public: //TODO
  std::string* _name;
  AMateria*    _inventory[g_inventorySize];
};

std::ostream& operator<<( std::ostream& o, Character const& i );

#endif  // CHARACTER_HPP_
