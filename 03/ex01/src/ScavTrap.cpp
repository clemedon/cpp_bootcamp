#include <iostream>
#include <sstream>
#include <string>
#include "ScavTrap.hpp"

/*  STANDARD MEMBER FUNCTIONS
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

ScavTrap::ScavTrap( std::string const& name )
  : _name( name ), // TODO issue
    _healthPoints( 100 ),
    _energyPoints( 50 ),
    _attackDamage( 20 ) {
  std::cout << __func__ << " ";
  std::cout << " Parametric constructor called" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

ScavTrap::ScavTrap( ScavTrap const& src ) {
  *this = src;
  std::cout << __func__ << " ";
  std::cout << " Copy constructor called" << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

ScavTrap::~ScavTrap( void ) {
  std::cout << __func__ << " ";
  std::cout << " Destructor called" << std::endl;
  return;
}

/**
 * @brief       Copy Assignment Operator
 */

ScavTrap& ScavTrap::operator=( ScavTrap const& rhs ) {
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

void ScavTrap::print( std::ostream& o ) const {
  o << "[";
  o << " health = " << this->_healthPoints;
  o << " energy = " << this->_energyPoints;
  o << " attack = " << this->_attackDamage;
  o << " ]\tScavTrap " << this->_name;
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, ScavTrap const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

// /**
//  * @brief       Check ScavTrap state
//  *
//  * @return      True or false
//  */
//
// bool ScavTrap::isAble() const {
//   int hp = this->_healthPoints;
//   int ep = this->_energyPoints;
//
//   if( hp <= 0 && ep <= 0 ) {
//     std::cout << this->_name << " is DEAD !!!" << std::endl;
//     return false;
//   } else if( hp <= 0 && ep > 0 ) {
//     std::cout << this->_name << " has NO MORE HIT points !" << std::endl;
//     return false;
//   } else if( hp > 0 && ep <= 0 ) {
//     std::cout << this->_name << " has NO MORE ENERGY points !" << std::endl;
//     return false;
//   }
//   return true;
// }
//
// /**
//  * @brief       ScavTrap attacks
//  *
//  * Causes its target to lose hit points.
//  * Costs 1 points of energy.
//  *
//  * @param[in]   target the target to attack
//  */
//
// void ScavTrap::attack( std::string const& target ) {
//   if( this->isAble() ) {
//     this->_energyPoints -= 1;
//     std::cout << *this << " ATTACKED " << target << ", causing "
//               << this->_attackDamage << " points of damage !" << std::endl;
//   }
//   return;
// }
//
// /**
//  * @brief       ScavTrap take damage
//  *
//  * Causes ScavTrap to lost hit points.
//  *
//  * @param[in]   amount the amount of hit points taken
//  */
//
// void ScavTrap::takeDamage( unsigned int const& amount ) {
//   if( this->isAble() ) {
//     this->_healthPoints -= amount;
//     std::cout << *this << " TOOK " << amount << " points of damage !"
//               << std::endl;
//   }
//   return;
// }
//
// /**
//  * @brief       ScavTrap repairs
//  *
//  * Causes ScavTrap to recover hit points.
//  * Costs 1 points of energy.
//  *
//  * @param[in]   amount the amount of hit points recovered
//  */
//
// void ScavTrap::beRepaired( unsigned int const& amount ) {
//   if( this->isAble() ) {
//     this->_energyPoints -= 1;
//     this->_healthPoints += amount;
//     std::cout << *this << " REPAIRED itself up to " << amount << " hit points."
//               << std::endl;
//   }
//   return;
// }

/**
 * @brief       ScavTrap attacks
 *
 * Causes its target to lose hit points.
 * Costs 1 points of energy.
 *
 * @param[in]   target the target to attack
 */

void ScavTrap::attack( std::string const& target ) {
  if( this->isAble() ) {
    this->_energyPoints -= 1;
    std::cout << *this << "ScavTrap ATTACKED " << target << ", causing "
              << this->_attackDamage << " points of damage !" << std::endl;
  }
  return;
}

/**
 * @brief       ScavTrap guard gate
 *
 * Causes its target to lose hit points.
 * Costs 1 points of energy.
 *
 * @param[in]   target the target to attack
 */

void ScavTrap::guardGate( void ) {
  if( this->isAble() ) {
    std::cout << *this << " is no in gate keeper mode" << std::endl;
  }
  return;
}

/*  GETTERS SETTERS
------------------------------------------------- */

// std::string ScaScavp::getName( void ) const {
//   return _name;
// }
//
// int ScavTrap::getHealthPoints( void ) const {
//   return _healthPoints;
// }
//
// int ScavTrap::getEnergyPoints( void ) const {
//   return _energyPoints;
// }
//
// int ScavTrap::getAttackDamage( void ) const {
//   return _attackDamage;
// }
