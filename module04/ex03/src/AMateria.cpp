#include <iostream>
#include <string>

#include "ICharacter.hpp"

#include "AMateria.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

AMateria::AMateria( std::string const& type ) : _type( type ) {
  std::cout << __FILE__;
  std::cout << " CONSTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

AMateria::AMateria( AMateria const& src ) {
  this->_type = src._type;
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

AMateria::~AMateria( void ) {
  std::cout << __FILE__;
  std::cout << " DESTROYED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

AMateria& AMateria::operator=( AMateria const& rhs ) {
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

void AMateria::print( std::ostream& o ) const {
  o << this->_type;
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, AMateria const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

/**
 * @brief       * should not exist *
 */

void AMateria::use( ICharacter& target ) {
  (void)target;
  std::cout << "Why wasn't i born pure virtual?" << std::endl;
  return;
}

/**
 * @brief       Compare the Materia's type with another type
 *
 * @param[in]   type any type
 * @return      True if the type match, or false
 */

bool AMateria::compareType( std::string const& type ) {
  return this->_type == type;
}

/*  GETTERS
------------------------------------------------- */

std::string const& AMateria::getType( void ) const {
  return this->_type;
}
