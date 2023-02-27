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
  Ice( Ice const& src );
  virtual ~Ice( void );
  Ice&         operator=( Ice const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual AMateria* clone( void ) const;
  virtual void      use( ICharacter& target );
};

std::ostream& operator<<( std::ostream& o, Ice const& i );

#endif  // ICE_HPP_
