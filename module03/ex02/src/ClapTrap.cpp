// @author    Clément Vidon
// @created   230324 14:33:16  by  clem@spectre
// @modified  230324 14:48:52  by  clem@spectre
// @filename  ClapTrap.cpp

#include <iostream>
#include <string>

#include "ClapTrap.hpp"

/*  STANDARD MEMBER FUNCTIONS
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

ClapTrap::ClapTrap( std::string const&  name,
                    unsigned int const& healthPoints,
                    unsigned int const& energyPoints,
                    unsigned int const& attackDamage )
  : _name( name ),
    _healthPoints( healthPoints ),
    _energyPoints( energyPoints ),
    _attackDamage( attackDamage ) {
  std::cout << *this;
  std::cout << "IS BORN !" << std::endl;
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
  std::cout << "IS BORN as a clone of " << src._name << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

ClapTrap::~ClapTrap( void ) {
  std::cout << *this;
  std::cout << "IS DEAD !" << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

ClapTrap& ClapTrap::operator=( ClapTrap const& rhs ) {
  std::cout << rhs;
  std::cout << "is assigned to " << *this << std::endl;
  if( this == &rhs ) {
    return *this;
  }
  _name = rhs._name;
  _healthPoints = rhs._healthPoints;
  _energyPoints = rhs._energyPoints;
  _attackDamage = rhs._attackDamage;
  return *this;
}

/**
 * @brief       Print Instance State
 */

void ClapTrap::print( std::ostream& o ) const {
  o << "[";
  o << " health = " << _healthPoints;
  o << " energy = " << _energyPoints;
  o << " attack = " << _attackDamage;
  o << "\t] ";
  o << "ClapTrap " << _name << " ";
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
  unsigned int hp = _healthPoints;
  unsigned int ep = _energyPoints;
  static bool end = 0;

  if (end) {
    return false;
  }
  if( hp <= 0 && ep <= 0 ) {
    std::cout << *this << "is DEAD !!!" << std::endl;
    end = true;
    return false;
  } else if( hp <= 0 && ep > 0 ) {
    std::cout << *this << "has NO MORE HEALTH points !" << std::endl;
    end = true;
    return false;
  } else if( hp > 0 && ep <= 0 ) {
    std::cout << *this << "has NO MORE ENERGY points !" << std::endl;
    end = true;
    return false;
  }
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
  if( isAble() ) {
    if ( _energyPoints < 1 ) {
      _energyPoints = 0;
    } else {
      _energyPoints -= 1;
    }
    std::cout << *this << "ATTACKED " << target << " with a mutex, causing "
              << _attackDamage << " points of damage !" << std::endl;
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
  if( isAble() ) {
    if ( _healthPoints < amount ) {
      _healthPoints = 0;
    } else {
      _healthPoints -= amount;
    }
    std::cout << *this << "TOOK " << amount << " points of damage !"
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
  if( isAble() ) {
    _energyPoints -= 1;
    _healthPoints += amount;
    std::cout << *this << "REPAIRED itself up to " << amount
              << " health points." << std::endl;
  }
  return;
}

/*  GETTERS SETTERS
------------------------------------------------- */

std::string ClapTrap::getName( void ) const {
  return _name;
}

unsigned int ClapTrap::getHealthPoints( void ) const {
  return _healthPoints;
}

unsigned int ClapTrap::getEnergyPoints( void ) const {
  return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage( void ) const {
  return _attackDamage;
}
