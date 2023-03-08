#include <iostream>
#include <string>

#include "ICharacter.hpp"
#include "LinkedList.hpp"

#include "AMateria.hpp"

LinkedList<AMateria*> AMateria::_freeMaterias;

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

AMateria::AMateria( std::string const& type )
  : _type( type ),
    _lockStatus( false ) {
  _freeMaterias.addBack( this );
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

AMateria::AMateria( AMateria const& src )
  : _type( src._type ),
    _lockStatus( false ) {
  _freeMaterias.addBack( this );
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

AMateria::~AMateria( void ) {
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

AMateria& AMateria::operator=( AMateria const& rhs ) {
#if defined( DEBUG )
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
#if defined( DEBUG )
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

/**
 * @brief       Add the Materia to the list of free Materias
 */

void AMateria::addFreeMaterias( void ) {
  lock( false );
  _freeMaterias.addBack( this );
  return;
}

/**
 * @brief       Remove the Materia from the list of free Materias
 */

void AMateria::delFreeMaterias( void ) {
  lock( true );
  _freeMaterias.delFirst( this );
  return;
}

/**
 * @brief       Display the list of free Materias
 */

void AMateria::displayFreeMaterias( void ) const {
  std::cout << "The following Materias are lying around:" << std::endl;
  std::cout << " " << _freeMaterias;
  return;
}

/*  GETTERS
------------------------------------------------- */

std::string const& AMateria::getType( void ) const {
  return _type;
}
