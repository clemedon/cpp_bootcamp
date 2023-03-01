#ifndef IMATERIASOURCE_HPP_
#define IMATERIASOURCE_HPP_

#include <iosfwd>
#include <string>

class AMateria;

/**
 * MateriaSource Interface
 */

class IMateriaSource {
 public:
  virtual ~IMateriaSource() {}

  virtual void      learnMateria( AMateria* m ) = 0;
  virtual AMateria* createMateria( std::string const& type ) = 0;
  virtual void              displayLearned( void ) const = 0;
};

#endif  // IMATERIASOURCE_HPP_
