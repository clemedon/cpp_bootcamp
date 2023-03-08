#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#include "Character.hpp"

extern const int g_inventorySize;

/*  STANDARD
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

Character::Character( std::string const& name )
  : _name( new std::string( name ) ) {
  int i;
  for( i = 0; i < g_inventorySize; i++ ) {
    _inventory[i] = NULL;
  }
#if defined( DEBUG )
  std::cout << __FILE__;
  std::cout << " CONSTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
#endif
  return;
}

/**
 * @brief       Copy Constructor
 */

Character::Character( ICharacter const& src )
#if defined( DEBUG )
  : _name( new std::string( src.getName() + "_copy" ) ) {
#else
  : _name( new std::string( src.getName() ) ) {
#endif
  int       i;
  AMateria* materia;

  for( i = 0; i < g_inventorySize; i++ ) {
    materia = src.getInventory( i );
    if( materia ) {
      _inventory[i] = materia->clone();
      _inventory[i]->delFreeMaterias();
    } else {
      _inventory[i] = NULL;
    }
  }
#if defined( DEBUG )
  std::cout << __FILE__;
  std::cout << " COPY CONSTRUCTED ";
  std::cout << *this;
  std::cout << " FROM ";
  std::cout << src.getName();
  std::cout << std::endl;
#endif
  return;
}

/**
 * @brief       Destructor
 */

Character::~Character( void ) {
  int i;

#if defined( DEBUG )
  std::cout << __FILE__;
  std::cout << " DESTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
#endif

  delete _name;
  for( i = 0; i < g_inventorySize; i++ ) {
    if( _inventory[i] ) {
      delete _inventory[i];
      _inventory[i] = NULL;
    }
  }
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

ICharacter& Character::operator=( ICharacter const& rhs ) {
  int i;

#if defined( DEBUG )
  std::cout << rhs;
  std::cout << " ASSIGNED TO " << *this;
  std::cout << std::endl;
#endif
  if( this == &rhs ) {
    return *this;
  }
  if( _name ) {
    delete _name;
  }
#if defined( DEBUG )
  _name = new std::string( rhs.getName() + "_assigned" );
#else
  _name = new std::string( rhs.getName() );
#endif
  for( i = 0; i < g_inventorySize; i++ ) {
    if( _inventory[i] ) {
      delete _inventory[i];
    }
    if( rhs.getInventory( i ) ) {
      _inventory[i] = rhs.getInventory( i )->clone();
      _inventory[i]->delFreeMaterias();
    } else {
      _inventory[i] = NULL;
    }
  }
  return *this;
}

/**
 * @brief       Print State
 */

void Character::print( std::ostream& o ) const {
  o << *_name;
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, ICharacter const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

/**
 * @brief       Get equipped with a new Materia
 */

void Character::equip( AMateria* m ) {
  int i;

  if( m == NULL ) {
    return;
  }
  if( m->checkLockStatus() ) {
    std::cout << "Materia " << *m << " is already in ";

    for( i = 0; i < g_inventorySize; i++ ) {
      if( _inventory[i] == m ) {
        std::cout << *this << " inventory…";
        break;
      } else if( i == 3 ) {
        std::cout << "someone else's inventory…";
        break;
      }
    }

    std::cout << std::endl;
    return;
  }
  for( i = 0; i < g_inventorySize; i++ ) {
    if( _inventory[i] == NULL ) {
      _inventory[i] = m;
      m->delFreeMaterias();
      std::cout << *this;
      std::cout << " has placed a Materia ";
      std::cout << *m;
      std::cout << " in his inventory!";
      std::cout << std::endl;
      return;
    }
  }
  std::cout << *this;
  std::cout << "'s inventory is full.";
  std::cout << std::endl;
  return;
}

/**
 * @brief       Get unequipped from a Materia
 */

void Character::unequip( int idx ) {
  if( idx > -1 && idx < g_inventorySize && _inventory[idx] ) {
    _inventory[idx]->addFreeMaterias();
    std::cout << *this;
    std::cout << " carefully lay its Materia ";
    std::cout << *_inventory[idx];
    std::cout << " on the ground and says: ";
    std::cout << "\"I am going to miss you…  but we must say good bye.\"";
    std::cout << std::endl;
    _inventory[idx] = NULL;
  } else if( idx > -1 && idx < g_inventorySize ) {
    std::cout << "Compartment ";
    std::cout << idx;
    std::cout << " of ";
    std::cout << *this;
    std::cout << "'s inventory has nothing but dust…";
    std::cout << std::endl;
  }
  return;
}

/**
 * @brief       Invoke an arbitrary Materia effect
 */

void Character::use( int idx, ICharacter& target ) {
  if( idx > -1 && idx < g_inventorySize && _inventory[idx] ) {
    std::cout << *this;
    std::cout << " uses a Materia ";
    std::cout << *_inventory[idx];
    std::cout << "… ";
    _inventory[idx]->use( target );
  } else {
    std::cout << "Compartment ";
    std::cout << idx;
    std::cout << " of ";
    std::cout << *this;
    std::cout << "'s inventory has nothing but dust…";
    std::cout << std::endl;
  }
  return;
}

/**
 * @brief       Display the content of the inventory
 */

void Character::displayInventory( void ) const {
  int i;

  std::cout << "* " << *this << " take a look at its inventory *" << std::endl;
  for( i = 0; i < g_inventorySize; i++ ) {
    if( _inventory[i] ) {
      std::cout << " Compartments " << i + 1 << ": ";
      std::cout << "Materia " << *_inventory[i];
      std::cout << std::endl;
    } else {
      std::cout << " Compartments " << i + 1 << ": ";
      std::cout << "empty";
      std::cout << std::endl;
    }
  }
  return;
}

/*  GETTERS
------------------------------------------------- */

std::string const& Character::getName( void ) const {
  return *_name;
}

AMateria* Character::getInventory( int idx ) const {
  return _inventory[idx];
}
