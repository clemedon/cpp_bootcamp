#ifndef AMATERIA_HPP_
#define AMATERIA_HPP_

#include <iosfwd>
#include <string>

class ICharacter;

/**
 * Abstract Materia
 *
 *
 * Data members
 *
 *  _type
 *    the materia type
 *
 *  _lockStatus
 *    indicate if the Materia is held by a character
 *
 *  _head
 *   the list of all existing free Materias (which are not equipped)
 *
 * - created    = add
 * - equipped   = delete
 * - unequipped = add
 *
 * - la liste est déclarée en static par la première instance de AMateria
 * - la liste n'est pas sur la heap ainsi le destructor appelé automatiquement
 *   supprime l'ensemble de la liste
 *
 *   Ainsi le Character s'occupe des ses Materias et AMateria s'occupe des
 *   orphelines.
 */

class AMateria {
 public:
  AMateria( std::string const& type = "Materia" );
  AMateria( AMateria const& src );
  virtual ~AMateria( void );
  AMateria&    operator=( AMateria const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual AMateria* clone( void ) const = 0;
  virtual void      use( ICharacter& target );

  bool compareType( std::string const& type ) const;
  bool checkLockStatus( void ) const;
  void lock( bool lockStatus );

 protected:
  std::string const& getType( void ) const;

  std::string _type;
  bool        _lockStatus;

  // TODO Node
  static Node* _head;
};

std::ostream& operator<<( std::ostream& o, AMateria const& i );

#endif  // AMATERIA_HPP_
