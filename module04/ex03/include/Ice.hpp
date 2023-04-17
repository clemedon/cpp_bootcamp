// @author    Clément Vidon
// @created   230324 15:43:52  by  clem@spectre
// @modified  230324 15:45:28  by  clem@spectre
// @filename  Ice.hpp

#ifndef ICE_HPP_
#define ICE_HPP_

#include <iosfwd>
#include <string>

class ICharacter;

#include "AMateria.hpp"

/**
 * Ice Materia
 *
 *
 * Data members
 *
 *  _type
 *    the materia type
 */

class Ice : public AMateria {
 public:
  Ice( std::string const& type = "ice" );
  Ice( AMateria const& src );
  virtual ~Ice( void );
  Ice& operator=( Ice const& rhs );
  void print( std::ostream& o ) const;

  virtual AMateria* clone( void ) const;
  virtual void      use( ICharacter& target );
};

#endif  // ICE_HPP_
