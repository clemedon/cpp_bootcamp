#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

#include <iosfwd>
#include <string>

class AMateria;

/**
 * Character Interface
 */

class ICharacter {
 public:
  virtual ~ICharacter() {}

  virtual void equip( AMateria* m ) = 0;
  virtual void unequip( int idx ) = 0;
  virtual void use( int idx, ICharacter& target ) = 0;

  virtual std::string const& getName() const = 0;
};

#endif  // ICHARACTER_HPP_
