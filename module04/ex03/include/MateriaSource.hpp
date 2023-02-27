#ifndef MATERIASOURCE_HPP_
#define MATERIASOURCE_HPP_

#include <iosfwd>
#include <string>

class AMateria;

#include "IMateriaSource.hpp"

/**
 * MateriaSource
 *
 *
 * Learns new Materia types in order to recreate them at will
 *
 * Data members
 *
 *  _source
 *    a source which can save up to 4 types of Materias
 */

const int g_sourceSize = 4;

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource( void );
  MateriaSource( MateriaSource const& src );
  virtual ~MateriaSource( void );
  MateriaSource& operator=( MateriaSource const& rhs );
  virtual void   print( std::ostream& o ) const;

  void      learnMateria( AMateria* );
  AMateria* createMateria( std::string const& type );

 private:
  AMateria* _source[g_sourceSize];
};

std::ostream& operator<<( std::ostream& o, MateriaSource const& i );

#endif  // MATERIASOURCE_HPP_
