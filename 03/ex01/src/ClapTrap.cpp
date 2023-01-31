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
  std::cout << __func__ << " ";
  std::cout << " Parametric constructor called" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

ClapTrap::ClapTrap( ClapTrap const& src ) {
  *this = src;
  std::cout << __func__ << " ";
  std::cout << " Copy constructor called" << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

ClapTrap::~ClapTrap( void ) {
  std::cout << __func__ << " ";
  std::cout << " Destructor called" << std::endl;
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
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

/**
 * @brief       Print Instance State
 */

void ClapTrap::print( std::ostream& o ) const {
  o << "[";
  o << " health = " << this->_healthPoints;
  o << " energy = " << this->_energyPoints;
  o << " attack = " << this->_attackDamage;
  o << " ]\tClapTrap " << this->_name;
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
