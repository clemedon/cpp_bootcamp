// @author    Clément Vidon
// @created   230324 15:47:25  by  clem@spectre
// @modified  230419 15:48:00  by  clem@spectre
// @filename  AMateria.cpp

#include <iostream>
#include <string>

#include "ICharacter.hpp"
#include "LinkedList.hpp"

#include "AMateria.hpp"

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

AMateria::AMateria( std::string const& type )
  : _type( type ),
    _lockStatus( false ) {
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

AMateria::AMateria( AMateria const& src )
  : _type( src._type ),
    _lockStatus( false ) {
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

AMateria::~AMateria( void ) {
#if defined( DEV )
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

AMateria& AMateria::operator=( AMateria const& rhs ) {
#if defined( DEV )
  std::cerr << rhs;
  std::cerr << " ASSIGNED TO " << *this;
  std::cerr << std::endl;
#endif
  if( this == &rhs ) {
    return *this;
  }
  _type = rhs._type;
  return *this;
}

/**
 * @brief       Print State
 */

void AMateria::print( std::ostream& o ) const {
  o << _type;
#if defined( DEV )
  std::cerr << "{";
  if( _lockStatus ) {
    std::cerr << "busy";
  } else {
    std::cerr << "free";
  }
  std::cerr << "}";
#endif
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

bool AMateria::compareType( std::string const& type ) const {
  return _type == type;
}

/**
 * @brief       Check if the Materia is already equipped
 *
 * @return      True if it is equipped, or false
 */

bool AMateria::checkLockStatus( void ) const {
  return _lockStatus;
}

/**
 * @brief       Lock/Unlock the Materia
 *
 *  false is unlocked is unequipped
 *  true is locked is equipped
 *
 * @param[in]   lockStatus the lock status
 */

void AMateria::lock( bool lockStatus ) {
  _lockStatus = lockStatus;
  return;
}

/*  GETTERS
------------------------------------------------- */

std::string const& AMateria::getType( void ) const {
  return _type;
}
