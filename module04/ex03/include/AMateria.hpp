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
 */

class AMateria {
 public:
  AMateria( std::string const& type = "amateria" );
  AMateria( AMateria const& src );
  virtual ~AMateria( void );
  AMateria&    operator=( AMateria const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual AMateria* clone( void ) const = 0;
  virtual void      use( ICharacter& target );
  bool              compareType( std::string const& type );

  std::string const& getType( void ) const;

 protected:
  std::string _type;
};

std::ostream& operator<<( std::ostream& o, AMateria const& i );

#endif  // AMATERIA_HPP_
