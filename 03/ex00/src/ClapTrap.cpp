#include <iostream>
#include <sstream>
#include <string>
#include "ClapTrap.hpp"

/**
 * @brief       Default Constructor
 */

ClapTrap::ClapTrap( std::string const& name )
  : _name( name ),
    _healthPoints( 10 ),
    _energyPoints( 10 ),
    _attackDamage( 0 ) {
  std::cout << __func__ << " Parametric constructor called" << std::endl;
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
  std::cout << __func__ << " Copy constructor called" << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

ClapTrap::~ClapTrap( void ) {
  std::cout << __func__ << " Destructor called" << std::endl;
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
    this->_healthPoints = rhs._healthPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
  }
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
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
  os << " health = " << this->_healthPoints;
  os << " energy = " << this->_energyPoints;
  os << " attack = " << this->_attackDamage;
  os << " ]\tClapTrap " << this->_name;
  return;
}

/**
 * @brief       Check ClapTrap state
 *
 * @return      True or false
 */

bool ClapTrap::isAble() const {
  int hp = this->_healthPoints;
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
 * Causes ClapTrap to recover hit points.
 * Costs 1 points of energy.
 *
 * @param[in]   amount the amount of hit points recovered
 */

void ClapTrap::beRepaired( unsigned int const& amount ) {
  if( this->isAble() ) {
    this->_energyPoints -= 1;
    this->_healthPoints += amount;
    std::cout << *this << " REPAIRED itself up to " << amount << " hit points."
              << std::endl;
  }
  return;
}

/**
 * @brief       Getters
 */

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
