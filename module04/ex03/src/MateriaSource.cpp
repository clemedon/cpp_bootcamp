#include <iostream>
#include <string>

#include "AMateria.hpp"

#include "MateriaSource.hpp"

extern const int g_sourceSize;

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

MateriaSource::MateriaSource( void ) {
  int i;

  for( i = 0; i < g_sourceSize; i++ ) {
    this->_source[i] = NULL;
  }
  std::cout << __FILE__;
  std::cout << " CONSTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

MateriaSource::MateriaSource( MateriaSource const& src ) {
  int i;

  for( i = 0; i < g_sourceSize; i++ ) {
    if( src._source[i] ) {
      this->_source[i] = src._source[i]->clone();
    } else {
      this->_source[i] = NULL;
    }
  }
  std::cout << __FILE__;
  std::cout << " COPY CONSTRUCTED ";
  std::cout << *this;
  std::cout << " FROM ";
  std::cout << src;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

MateriaSource::~MateriaSource( void ) {
  int i;

  std::cout << __FILE__;
  std::cout << " DESTROYED ";
  std::cout << *this;
  std::cout << std::endl;
  for( i = 0; i < g_sourceSize; i++ ) {
    if( this->_source[i] ) {
      delete this->_source[i];
    }
  }
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

MateriaSource& MateriaSource::operator=( MateriaSource const& rhs ) {
  int i;

  std::cout << rhs;
  std::cout << " ASSIGNED TO " << *this;
  std::cout << std::endl;
  if( this == &rhs ) {
    return *this;
  }
  for( i = 0; i < g_sourceSize; i++ ) {
    if( this->_source[i] ) {
      delete this->_source[i];
    }
    this->_source[i] = rhs._source[i]->clone();
  }
  return *this;
}

/**
 * @brief       Print State
 */

void MateriaSource::print( std::ostream& o ) const {
  o << "source";
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
  for( i = 0; i < g_sourceSize; i++ ) {
    if( this->_source[i] == NULL ) {
      this->_source[i] = m;
      std::cout << *this;
      std::cout << " has placed ";
      std::cout << *m;
      std::cout << " in space ";
      std::cout << i;
      std::cout << " of its source";
      std::cout << std::endl;
      return;
    }
  }
  return;
}

/**
 * @brief       Create a Materia of one of the learned type
 *
 * @param[in]   type a type of Materia
 * @return      a new Materia of the given type if the type if known or nothing
 */

AMateria* MateriaSource::createMateria( std::string const& type ) {
  int i;

  for( i = 0; i < g_sourceSize; i++ ) {
    if( this->_source[i]->compareType( type ) ) {
      return this->_source[i]->clone();
    }
  }
  return NULL;
}
