#include <iostream>
#include <sstream>
#include <string>
#include "ClapTrap.hpp"

/*  STANDARD MEMBER FUNCTIONS
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

ClapTrap::ClapTrap( std::string const& name )
  : _name( name ),
    _healthPoints( 10 ),
    _energyPoints( 10 ),
    _attackDamage( 0 ) {
  std::cout << *this;
  std::cout << " IS BORN !" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

ClapTrap::ClapTrap( ClapTrap const& src )
  : _name( src._name ),
    _healthPoints( src._healthPoints ),
    _energyPoints( src._energyPoints ),
    _attackDamage( src._attackDamage ) {
  std::cout << *this;
  std::cout << " IS BORN as a clone of " << src << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

ClapTrap::~ClapTrap( void ) {
  std::cout << *this;
  std::cout << " IS DEAD !" << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

ClapTrap& ClapTrap::operator=( ClapTrap const& rhs ) {
  if( this == &rhs ) {
    return *this;
  }
  this->_name = rhs._name;
  this->_healthPoints = rhs._healthPoints;
  this->_energyPoints = rhs._energyPoints;
  this->_attackDamage = rhs._attackDamage;
  std::cout << "ClapTrap ";
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

/**
 * @brief       Print Instance State
 */

void ClapTrap::print( std::ostream& o ) const {
  o << "ClapTrap " << this->_name;
  o << "\t[";
  o << " health = " << this->_healthPoints;
  o << " energy = " << this->_energyPoints;
  o << " attack = " << this->_attackDamage;
  o << " ]\t";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, ClapTrap const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

/**
 * @brief       Check ClapTrap state
 *
 * @return      True or false
 */

bool ClapTrap::isAble() const {
  int hp = this->_healthPoints;
  int ep = this->_energyPoints;

  if( hp <= 0 && ep <= 0 ) {
    std::cout << *this << " is DEAD !!!" << std::endl;
    return false;
  } else if( hp <= 0 && ep > 0 ) {
    std::cout << *this << " has NO MORE HEALTH points !" << std::endl;
    return false;
  } else if( hp > 0 && ep <= 0 ) {
    std::cout << *this << " has NO MORE ENERGY points !" << std::endl;
    return false;
  }
  std::cout << *this << " is in good shape  !" << std::endl;
  return true;
}

/**
 * @brief       ClapTrap attacks
 *
 * Causes its target to lose health points.
 * Costs 1 points of energy.
 *
 * @param[in]   target the target to attack
 */

void ClapTrap::attack( std::string const& target ) {
  if( this->isAble() ) {
    this->_energyPoints -= 1;
    std::cout << *this << " ATTACKED " << target << ", causing "
              << this->_attackDamage << " points of damage !" << std::endl;
  }
  return;
}

/**
 * @brief       ClapTrap take damage
 *
 * Causes ClapTrap to lost health points.
 *
 * @param[in]   amount the amount of health points taken
 */

void ClapTrap::takeDamage( unsigned int const& amount ) {
  if( this->isAble() ) {
    this->_healthPoints -= amount;
    std::cout << *this << " TOOK " << amount << " points of damage !"
              << std::endl;
  }
  return;
}

/**
 * @brief       ClapTrap repairs
 *
 * Causes ClapTrap to recover health points.
 * Costs 1 points of energy.
 *
 * @param[in]   amount the amount of health points recovered
 */

void ClapTrap::beRepaired( unsigned int const& amount ) {
  if( this->isAble() ) {
    this->_energyPoints -= 1;
    this->_healthPoints += amount;
    std::cout << *this << " REPAIRED itself up to " << amount
              << " health points." << std::endl;
  }
  return;
}

/*  GETTERS SETTERS
------------------------------------------------- */

std::string ClapTrap::getName( void ) const {
  return _name;
}

int ClapTrap::getHealthPoints( void ) const {
  return _healthPoints;
}

int ClapTrap::getEnergyPoints( void ) const {
  return _energyPoints;
}

int ClapTrap::getAttackDamage( void ) const {
  return _attackDamage;
}
