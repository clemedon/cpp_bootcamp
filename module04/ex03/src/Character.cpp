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
  : _name( new std::string( name ) ) {  // TODO new, to keep the ptr?
  int i;

  for( i = 0; i < g_inventorySize; i++ ) {
    this->_inventory[i] = NULL;
  }
  std::cout << __FILE__;
  std::cout << " CONSTRUCTED ";
  std::cout << *this;
  std::cout << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

Character::Character( Character const& src )
  : _name( new std::string(
    src.getName() ) ) {  // TODO why not src._name TRY *src._name
  int i;

  for( i = 0; i < g_inventorySize; i++ ) {
    if( src._inventory[i] ) {
      this->_inventory[i] = src._inventory[i]->clone();
    } else {
      this->_inventory[i] = NULL;
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

Character::~Character( void ) {
  int i;

  std::cout << __FILE__;
  std::cout << " DESTROYED ";
  std::cout << *this;
  std::cout << std::endl;

  delete this->_name;
  for( i = 0; i < g_inventorySize; i++ ) {
    if( this->_inventory[i] ) {
      delete this->_inventory[i];
      this->_inventory[i] = NULL;
    }
    std::cout << std::endl;
  }
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

Character& Character::operator=( Character const& rhs ) {
  int i;

  std::cout << rhs;
  std::cout << " ASSIGNED TO " << *this;
  std::cout << std::endl;
  if( this == &rhs ) {
    return *this;
  }
  if( this->_name ) {
    delete this->_name;
  }
  this->_name = new std::string( *rhs._name );
  for( i = 0; i < g_inventorySize; i++ ) {
    if( this->_inventory[i] ) {
      delete this->_inventory[i];
    }
    if( rhs._inventory[i] ) {
      this->_inventory[i] = rhs._inventory[i]->clone();
    } else {
      this->_inventory[i] = NULL;
    }
  }
  return *this;
}

/**
 * @brief       Print State
 */

void Character::print( std::ostream& o ) const {
  o << ( *this->_name );
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, Character const& i ) {
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
    std::cout << "This Materia is already stored in an inventory.";
    std::cout << std::endl;
    return;
  }
  for( i = 0; i < g_inventorySize; i++ ) {
    if( this->_inventory[i] == NULL ) {
      this->_inventory[i] = m;
      m->lock( true );
      std::cout << *this;
      std::cout << " has placed ";
      std::cout << *m;
      std::cout << " in space ";
      std::cout << i;
      std::cout << " of its inventory";
      std::cout << std::endl;
      return;
    }
  }
  std::cout << *this;
  std::cout << "'s inventory is full";
  std::cout << std::endl;
  return;
}

/**
 * @brief       Get unequipped from a Materia
 */

void Character::unequip( int idx ) {
  if( idx > -1 && idx < g_inventorySize
      && this->_inventory[idx] ) {  // TODO test
    std::cout << *this;
    std::cout << " carefully lay its ";
    std::cout << *this->_inventory[idx];
    std::cout << " Materia on the ground and say: ";
    std::cout << "\"I am going to miss you…  but we must separate now.\"";
    std::cout << std::endl;
    // TODO leak ?
    // "la fonction unequip ne doit PAS delete la Materia"
    //
    // "Vous pouvez enregistrer l’adresse avant d’appeler unequip(), ou autre,
    // du moment que vous n’avez pas de fuites de mémoire."
    this->_inventory[idx]->lock( false );
    this->_inventory[idx] = NULL;
  } else {
    std::cout << *this;
    std::cout << " does not have a Materia in space ";
    std::cout << idx;
    std::cout << " of its inventory";
    std::cout << std::endl;
  }
  return;
}

/**
 * @brief       Invoke an arbitrary Materia effect
 */

void Character::use( int idx, ICharacter& target ) {
  if( idx > -1 && idx < g_inventorySize
      && this->_inventory[idx] ) {  // TODO test
    std::cout << target.getName();  // TODO interface encapsulation
    std::cout << " uses a ";
    std::cout << *this->_inventory[idx];
    std::cout << " Materia";
    std::cout << std::endl;
    this->_inventory[idx]->use( target );
  } else {
    std::cout << target.getName();  // TODO interface encapsulation
    std::cout << " does not have a Materia in space ";
    std::cout << idx;
    std::cout << " of its inventory";
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
    if( this->_inventory[i] ) {
      std::cout << " - space " << i + 1  << " contains " << *this->_inventory[i] << std::endl;
    } else {
      std::cout << " - space " << i + 1  << " is free" << std::endl;
    }
  }
  return;
}

/*  GETTERS
------------------------------------------------- */

std::string const& Character::getName( void ) const {
  return *this->_name;
}
