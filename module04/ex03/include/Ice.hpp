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
