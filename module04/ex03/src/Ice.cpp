#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include "Ice.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Ice::Ice( std::string const& type ) : AMateria( type ) {
  std::cout << __FILE__;
  std::cout << " CONSTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

// TODO why not AMateria ( src ) to call the copy constr de AMateria directement
// plutot que d'appeler son constructor
Ice::Ice( Ice const& src ) : AMateria( src._type ) {
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

Ice::~Ice( void ) {
  std::cout << __FILE__;
  std::cout << " DESTROYED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Ice& Ice::operator=( Ice const& rhs ) {
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

void Ice::print( std::ostream& o ) const {
  o << this->_type << "(" << this->_lockStatus << ")";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Ice const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

/**
 * @brief       Return a new instance of the same type
 */

AMateria* Ice::clone( void ) const {
  return new Ice( *this );  // TODO new ? copy constr ?
}

/**
 * @brief       Display Materia effect
 */

void Ice::use( ICharacter& target ) {
  if( this->_lockStatus ) {
    std::cout << "* shoots an ice bolt at ";
    std::cout << target.getName();
    std::cout << " *";
    std::cout << std::endl;
  } else {
    std::cout << "This Materia must be equipped to be used.";
    std::cout << std::endl;
  }
  return;
}
