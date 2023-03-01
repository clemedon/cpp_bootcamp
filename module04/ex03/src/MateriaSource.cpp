#include <iostream>
#include <string>

#include "AMateria.hpp"

#include "MateriaSource.hpp"

extern const int g_knowledgeSize;

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

MateriaSource::MateriaSource( void ) {
  int i;

  for( i = 0; i < g_knowledgeSize; i++ ) {
    _learned[i] = NULL;
  }
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " CONSTRUCTED ";
  std::cerr << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Constructor
 */

MateriaSource::MateriaSource( MateriaSource const& src ) {
  int i;

  for( i = 0; i < g_knowledgeSize; i++ ) {
    if( src._learned[i] ) {
      _learned[i] = src._learned[i]->clone();
    } else {
      _learned[i] = NULL;
    }
  }
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " COPY CONSTRUCTED ";
  std::cerr << *this;
  std::cerr << " FROM ";
  std::cerr << src;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Destructor
 */

MateriaSource::~MateriaSource( void ) {
  int i;

#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " DESTROYED ";
  std::cerr << *this;
  std::cerr << std::endl;
#endif

  for( i = 0; i < g_knowledgeSize; i++ ) {
    if( _learned[i] ) {
      delete _learned[i];
    }
  }
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

MateriaSource& MateriaSource::operator=( MateriaSource const& rhs ) {
  int i;

#if defined( DEBUG )
  std::cerr << rhs;
  std::cerr << " ASSIGNED TO " << *this;
  std::cerr << std::endl;
#endif
  if( this == &rhs ) {
    return *this;
  }
  for( i = 0; i < g_knowledgeSize; i++ ) {
    if( _learned[i] ) {
      delete _learned[i];
    }
    _learned[i] = rhs._learned[i]->clone();
  }
  return *this;
}

/**
 * @brief       Print State
 */

void MateriaSource::print( std::ostream& o ) const {
  o << "MateriaSource";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, MateriaSource const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

/**
 * @brief       Learn a new type of Materia
 *
 * @param[in]   m a new type of Materia
 */

void MateriaSource::learnMateria( AMateria* m ) {
  int i;

  if( m == NULL ) {
    return;
  }
  for( i = 0; i < g_knowledgeSize; i++ ) {
    if( _learned[i] == NULL ) {
      _learned[i] = m;
      std::cout << *this;
      std::cout << " has learned how to create a Materia ";
      std::cout << *m << ".";
      std::cout << std::endl;
      return;
    }
  }
  std::cout << *this;
  std::cout << " is tired to learn, be happy with what you have.";
  std::cout << std::endl;
  return;
}

/**
 * @brief       Create a Materia of one of the learned type
 *
 * @param[in]   type a type of Materia
 * @return      a new Materia of the given type if the type if known or nothing
 */

AMateria* MateriaSource::createMateria( std::string const& type ) {
  int       i;
  AMateria* newMateria;

  for( i = 0; i < g_knowledgeSize; i++ ) {
    if( _learned[i] && _learned[i]->compareType( type ) ) {
      newMateria = _learned[i]->clone();
      std::cout << *this << " has successfully created a Materia ";
      std::cout << *newMateria << "!";
      std::cout << std::endl;
      return newMateria;
    }
  }
  std::cout << *this << " doesn't know how to create a Materia ";
  std::cout << type << "…";
  std::cout << std::endl;
  return NULL;
}

/**
 * @brief       Display the learned materia
 */

void MateriaSource::displayLearned( void ) const {
  int i;

  std::cout << *this << "'s knowledge:" << std::endl;
  for( i = 0; i < g_knowledgeSize; i++ ) {
    if( _learned[i] ) {
      std::cout << " - space " << i + 1 << " contains " << *_learned[i]
                << std::endl;
    } else {
      std::cout << " - space " << i + 1 << " is empty" << std::endl;
    }
  }
  return;
}
