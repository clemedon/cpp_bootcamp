// @author    Clément Vidon
// @created   230324 15:43:11  by  clem@spectre
// @modified  230419 15:48:25  by  clem@spectre
// @filename  AMateria.hpp

#ifndef AMATERIA_HPP_
#define AMATERIA_HPP_

#include <iosfwd>
#include <string>

#include "LinkedList.hpp"

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
 *    indicate if the Materia is held by a character, it is not subject to the
 *    copy constructor or the assignment operator
 *
 *  _freeMaterias
 *   the list of all existing free Materias (those which are not equipped)
 */

class AMateria {
 protected:
  AMateria( std::string const& type = "AMateria" );
  AMateria( AMateria const& src );

 public:
  virtual ~AMateria( void );
  AMateria& operator=( AMateria const& rhs );
  void      print( std::ostream& o ) const;

  virtual AMateria* clone( void ) const = 0;
  virtual void      use( ICharacter& target );

  bool compareType( std::string const& type ) const;
  bool checkLockStatus( void ) const;
  void lock( bool lockStatus );

  std::string const& getType( void ) const;

 protected:
  std::string                  _type;
  bool                         _lockStatus;
};

std::ostream& operator<<( std::ostream& o, AMateria const& i );

#endif  // AMATERIA_HPP_
