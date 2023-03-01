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

// TODO why not AMateria ( src ) to call the copy constr de AMateria directement
// plutot que d'appeler son constructor
Ice::Ice( Ice const& src ) : AMateria( src._type ) {
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

Ice::~Ice( void ) {
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " DESTROYED ";
  std::cerr << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Ice& Ice::operator=( Ice const& rhs ) {
#if defined( DEBUG )
  std::cerr << rhs;
  std::cerr << " ASSIGNED TO " << *this;
  std::cerr << std::endl;
#endif
  if( this == &rhs ) {
    return *this;
  }
  return *this;
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
  if( _lockStatus ) {
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
