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
 *  _learned
 *    up to 4 learned Materia's recipe
 */

const int g_knowledgeSize = 4;

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource( void );
  MateriaSource( MateriaSource const& src );
  virtual ~MateriaSource( void );
  MateriaSource& operator=( MateriaSource const& rhs );
  virtual void   print( std::ostream& o ) const;

  virtual void      learnMateria( AMateria* );
  virtual AMateria* createMateria( std::string const& type );
  virtual void      displayLearned( void ) const;

 private:
  AMateria* _learned[g_knowledgeSize];
};

std::ostream& operator<<( std::ostream& o, MateriaSource const& i );

#endif  // MATERIASOURCE_HPP_
