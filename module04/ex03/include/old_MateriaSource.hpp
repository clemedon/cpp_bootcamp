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
 *
 *  _createdCount
 *    the total number of created (thus existing) materias
 *
 *  _created
 *    the address of each created (thus existing) materias
 */

struct Node {
  AMateria* data;
  Node*     next;
};

const int g_learningCapacity = 4;

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource( void );
  MateriaSource( MateriaSource const& src );
  virtual ~MateriaSource( void );
  MateriaSource& operator=( MateriaSource const& rhs );
  virtual void   print( std::ostream& o ) const;

  void      learnMateria( AMateria* );
  AMateria* createMateria( std::string const& type );

  void displayLearned( void ) const;

  void displayCreated( void ) const;
  /* void addToCreated( void ) const; // ? */
  /* void destroyCreated( void ) const; */

 private:
  AMateria* _learned[g_learningCapacity];
  int       _createdCount;
  Node*     _created;
};

std::ostream& operator<<( std::ostream& o, MateriaSource const& i );

#endif  // MATERIASOURCE_HPP_
