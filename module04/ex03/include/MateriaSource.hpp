// @author    Clément Vidon
// @created   230324 15:44:34  by  clem@spectre
// @modified  230324 15:47:02  by  clem@spectre
// @filename  MateriaSource.hpp

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
 *  _knowledge
 *    up to 4 Materia's recipe
 */

const int g_knowledgeSize = 4;

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource( void );
  MateriaSource( IMateriaSource const& src );
  virtual ~MateriaSource( void );
  virtual IMateriaSource& operator=( IMateriaSource const& rhs );
  virtual void            print( std::ostream& o ) const;

  virtual void      learnMateria( AMateria* );
  virtual AMateria* createMateria( std::string const& type );
  virtual void      displayKnowledge( void ) const;

  virtual AMateria* getKnowledge( int idx ) const;

 private:
  AMateria* _knowledge[g_knowledgeSize];
};

std::ostream& operator<<( std::ostream& o, IMateriaSource const& i );

#endif  // MATERIASOURCE_HPP_
