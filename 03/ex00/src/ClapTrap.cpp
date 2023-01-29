#include <iostream>
#include <sstream>
#include <string>
#include "ClapTrap.hpp"

/**
 * @brief       Default Constructor
 */

ClapTrap::ClapTrap( std::string const& name )
  : _name( name ),
    _hitPoints( 10 ),
    _energyPoints( 10 ),
    _attackDamage( 0 ) {
  std::cout << "Parametric constructor called" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 *
 * Create a copy of the given object
 * They both use different memory location
 *
 * @param[in]   src the object to copy
 */

ClapTrap::ClapTrap( ClapTrap const& src ) {
  *this = src;
  std::cout << "Copy constructor called" << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

ClapTrap::~ClapTrap( void ) {
  std::cout << "Destructor called" << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 *
 * Assigns value of one existing object to another existing object
 * They both share the same memory location
 *
 * @param[in]   rhs the object to copy
 * @return      a reference on rhs
 */

ClapTrap& ClapTrap::operator=( ClapTrap const& rhs ) {
  if( this != &rhs ) {
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
  }
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

/**
 * @brief       Getters
 */

std::string ClapTrap::getName( void ) const {
  return _name;
}

int ClapTrap::getAttackDamage( void ) const {
  return _attackDamage;
}

/**
 * @brief       Verify is the ClapTrap is able to confront
 *
 * @return      True or false
 */

bool ClapTrap::isAble() const {
  int hp = this->_hitPoints;
  int ep = this->_energyPoints;

  if( hp <= 0 && ep <= 0 ) {
    std::cout << this->_name << " is DEAD !!!" << std::endl;
    return false;
  } else if( hp <= 0 && ep > 0 ) {
    std::cout << this->_name << " has NO MORE HIT points !" << std::endl;
    return false;
  } else if( hp > 0 && ep <= 0 ) {
    std::cout << this->_name << " has NO MORE ENERGY points !" << std::endl;
    return false;
  }
  return true;
}

/**
 * @brief       Print
 *
 * Print this object
 *
 * @param[out]  os where to print
 */

void ClapTrap::print( std::ostream& os ) const {
  os << "[";
  os << " hitpts = " << this->_hitPoints;
  os << " energy = " << this->_energyPoints;
  os << " attack = " << this->_attackDamage;
  os << " ]\t" << this->_name << "\t";
  return;
}

/**
 * @brief       ClapTrap attacks
 *
 * Causes its target to lose hit points.
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
 * Causes ClapTrap to lost hit points.
 *
 * @param[in]   amount the amount of hit points taken
 */

void ClapTrap::takeDamage( unsigned int amount ) {
  if( this->isAble() ) {
    this->_hitPoints -= amount;
    std::cout << *this << " TOOK " << amount << " points of damage !"
              << std::endl;
  }
  return;
}

/**
 * @brief       ClapTrap repairs
 *
 * Causes ClapTrap to recover hit points.
 * Costs 1 points of energy.
 *
 * @param[in]   amount the amount of hit points recovered
 */

void ClapTrap::beRepaired( unsigned int amount ) {
  if( this->isAble() ) {
    this->_energyPoints -= 1;
    this->_hitPoints += amount;
    std::cout << *this << " REPAIRED itself up to " << amount << " hit points."
              << std::endl;
  }
  return;
}

/**
 * @brief       Output Operator Overloading
 *
 * How the Output Operator should handle ClapTrap
 *
 * Use print member function in order to access the data members without to
 * break the encapsulation with getters
 *
 * @param[out]  os where to stream
 * @param[in]   i what to stream
 * @return      the stream
 */

std::ostream& operator<<( std::ostream& os, ClapTrap const& i ) {
  i.print( os );
  return os;
}
