#include <iostream>
#include <sstream>
#include <string>
#include "DiamondTrap.hpp"

/*  STANDARD MEMBER FUNCTIONS
------------------------------------------------- */

/**
 * @brief       Default Constructor
 *
 * XXX DiamondTrap inherits of FragTrap and ScavTrap attributes, which is of
 * little interest since both come from the same source: ClapTrap.
 */

DiamondTrap::DiamondTrap( std::string const& name )
  : ClapTrap( name + "_clap_name" ),
    FragTrap(),
    ScavTrap() {
  this->_name = name;
  this->_healthPoints = FragTrap::_healthPoints;
  this->_energyPoints = ScavTrap::_energyPoints;
  this->_attackDamage = FragTrap::_attackDamage;
  std::cout << *this;
  std::cout << "IS BORN !" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */
DiamondTrap::DiamondTrap( DiamondTrap const& src )
  : ClapTrap( src._name + "_clap_name" ),
    FragTrap(),
    ScavTrap() {
  this->_name = src._name;
  this->_healthPoints = src._healthPoints;
  this->_energyPoints = src._energyPoints;
  this->_attackDamage = src._attackDamage;
  std::cout << *this;
  std::cout << "IS BORN as a clone of " << src << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

DiamondTrap::~DiamondTrap( void ) {
  std::cout << *this;
  std::cout << "IS DEAD !" << std::endl;
  return;
}

DiamondTrap& DiamondTrap::operator=( DiamondTrap const& rhs ) {
  std::cout << rhs;
  std::cout << "is assigned to " << *this << std::endl;
  if( this == &rhs ) {
    return *this;
  }
  this->_name = rhs._name;
  this->_healthPoints = rhs._healthPoints;
  this->_energyPoints = rhs._energyPoints;
  this->_attackDamage = rhs._attackDamage;
  return *this;
}

/**
 * @brief       Print Instance State
 */

void DiamondTrap::print( std::ostream& o ) const {
  o << "[";
  o << " health = " << this->_healthPoints;
  o << " energy = " << this->_energyPoints;
  o << " attack = " << this->_attackDamage;
  o << "\t] ";
  o << "DiamondTrap " << this->_name << " ";
  return;
}

/**
 * @brief       Output Operator Handling
 */

std::ostream& operator<<( std::ostream& o, DiamondTrap const& i ) {
  i.print( o );
  return o;
}

/* ---------------------------------------------- */

/**
 * @brief       DiamondTrap attacks
 *
 * Causes its target to lose health points.
 * Costs 1 points of energy.
 *
 * @param[in]   target the target to attack
 */

void DiamondTrap::attack( std::string const& target ) {
  ScavTrap::attack( target );
  return;
}

/**
 * @brief       DiamondTrap who am I
 *
 * Print identity
 */

void DiamondTrap::whoAmI( void ) {
  std::cout << "\"My name is DiamondTrap " << this->_name
            << ", I am the son of ";
  std::cout << "ClapTrap " << this->ClapTrap::_name << "\"";
  std::cout << std::endl;
}
