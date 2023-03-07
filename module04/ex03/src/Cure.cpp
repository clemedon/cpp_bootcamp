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

Cure::Cure( AMateria const& src ) : AMateria( src.getType() ) {
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

Cure::~Cure( void ) {
#if defined( DEBUG )
  std::cerr << __FILE__;
  std::cerr << " DESTRUCTED ";
  std::cerr << *this;
  std::cerr << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Cure& Cure::operator=( Cure const& rhs ) {
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
 * @brief       Return a new materia of the same type
 */

AMateria* Cure::clone( void ) const {
  AMateria* m = new Cure( *this );
  std::cout << "salut" << std::endl;
  return m;
}

/**
 * @brief       Display Materia effect
 */

void Cure::use( ICharacter& target ) {
  if( _lockStatus ) {
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
