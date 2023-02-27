#include <iostream>
#include <string>

#include "AMateria.hpp"

#include "MateriaSource.hpp"

extern const int g_learningCapacity;

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

MateriaSource::MateriaSource( void ) : _createdCount( 0 ), _created( NULL ) {
  int i;

  for( i = 0; i < g_learningCapacity; i++ ) {
    this->_learned[i] = NULL;
  }

  // TODO
  this->_created = NULL;

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

  for( i = 0; i < g_learningCapacity; i++ ) {
    if( src._learned[i] ) {
      this->_learned[i] = src._learned[i]->clone();
    } else {
      this->_learned[i] = NULL;
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

  for( i = 0; i < g_learningCapacity; i++ ) {
    if( this->_learned[i] ) {
      delete this->_learned[i];
    }
  }

  Node* ptr;

  ptr = this->_created;
  while( ptr != NULL ) {
    if( ptr->data->checkLockStatus() == false ) { //TODO
      delete ptr->data;
    }
    ptr = ptr->next;
  }

  while( this->_created != NULL ) {
    ptr = this->_created;
    this->_created = this->_created->next;
    delete ptr;
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
  for( i = 0; i < g_learningCapacity; i++ ) {
    if( this->_learned[i] ) {
      delete this->_learned[i];
    }
    this->_learned[i] = rhs._learned[i]->clone();
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
  for( i = 0; i < g_learningCapacity; i++ ) {
    if( this->_learned[i] == NULL ) {
      this->_learned[i] = m;
      std::cout << *this;
      std::cout << " has placed ";
      std::cout << *m;
      std::cout << " in space ";
      std::cout << i;
      std::cout << " of its learning memory";
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
  int   i;
  Node* newCreated;

  newCreated = new Node();
  for( i = 0; i < g_learningCapacity; i++ ) {
    if( this->_learned[i]->compareType( type ) ) {
      newCreated->data = this->_learned[i]->clone();
      this->_createdCount++;
      newCreated->next = this->_created;
      this->_created = newCreated;
      return newCreated->data;
    }
  }
  return NULL;
}

/**
 * @brief       Display the learned materia
 */

void MateriaSource::displayLearned( void ) const {
  int i;

  std::cout << *this << "'s learning memory:" << std::endl;
  for( i = 0; i < g_learningCapacity; i++ ) {
    if( this->_learned[i] ) {
      std::cout << " - space " << i + 1 << " contains " << *this->_learned[i]
                << std::endl;
    } else {
      std::cout << " - space " << i + 1 << " is free" << std::endl;
    }
  }
  return;
}

/**
 * @brief       Display the created (thus existing) materia
 */

void MateriaSource::displayCreated( void ) const {
  Node* ptr;

  ptr = this->_created;
  std::cout << *this << "'s created:" << std::endl;
  while( ptr != NULL ) {
    std::cout << *ptr->data;
    std::cout << std::endl;
    ptr = ptr->next;
  }
  std::cout << "For a total of " << this->_createdCount << " Materias.";
  std::cout << std::endl;
  return;
}
