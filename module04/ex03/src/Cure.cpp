#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include "Cure.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Cure::Cure( std::string const& type ) : AMateria( type ) {
  std::cout << __FILE__;
  std::cout << " CONSTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

Cure::Cure( Cure const& src ) : AMateria( src._type ) {
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

Cure::~Cure( void ) {
  std::cout << __FILE__;
  std::cout << " DESTROYED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Cure& Cure::operator=( Cure const& rhs ) {
  std::cout << rhs;
  std::cout << " ASSIGNED TO " << *this;
  std::cout << std::endl;
  if( this == &rhs ) {
    return *this;
  }
  return *this;
}

/**
 * @brief       Print State
 */

void Cure::print( std::ostream& o ) const {
  o << this->_type << "(" << this->_lockStatus << ")";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Cure const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

/**
 * @brief       Return a new instance of the same type
 */

AMateria* Cure::clone( void ) const {
  return new Cure( *this );  // TODO new ? copy constr ?
}

/**
 * @brief       Display Materia effect
 */

void Cure::use( ICharacter& target ) {
  if( this->_lockStatus ) {
    std::cout << "* heals ";
    std::cout << target.getName();
    std::cout << "'s wounds *";
    std::cout << std::endl;
  } else {
    std::cout << "This material must be equipped to be used.";
    std::cout << std::endl;
  }
  return;
}
