// @author    Clément Vidon
// @created   230324 15:45:48  by  clem@spectre
// @modified  230419 15:45:17  by  clem@spectre
// @filename  Ice.cpp

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
#if defined( DEV )
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

Ice::Ice( AMateria const& src ) : AMateria( src.getType() ) {
#if defined( DEV )
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
#if defined( DEV )
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
#if defined( DEV )
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
  AMateria* m = new Ice( *this );
  return m;
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
