#ifndef CURE_HPP_
#define CURE_HPP_

#include <iosfwd>
#include <string>

class ICharacter;

#include "AMateria.hpp"

/**
 * Cure Materia
 *
 *
 * Data members
 *
 *  _type
 *    the materia type
 */

class Cure : public AMateria {
 public:
  Cure( std::string const& type = "cure" );
  Cure( Cure const& src );
  virtual ~Cure( void );
  Cure& operator=( Cure const& rhs );
  void  print( std::ostream& o ) const;

  virtual AMateria* clone( void ) const;
  virtual void      use( ICharacter& target );
};

#endif  // CURE_HPP_
