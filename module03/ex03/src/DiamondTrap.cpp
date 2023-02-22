#include <iostream>
#include <sstream>
#include <string>
#include "DiamondTrap.hpp"

/*  STANDARD MEMBER FUNCTIONS
------------------------------------------------- */

/**
 * @brief       Default Constructor
 */

DiamondTrap::DiamondTrap( std::string const& name,
                          int const&         healthPoints,
                          int const&         energyPoints,
                          int const&         attackDamage )
  : ClapTrap( name + "_clap_name", healthPoints, energyPoints, attackDamage ) {
  this->whoAmI();
  std::cout << "IS BORN !" << std::endl;
  return;
}

/**
 * @brief       Copy Constructor
 */

DiamondTrap::DiamondTrap( DiamondTrap const& src )
  : ClapTrap( src.ClapTrap::_name,
              src.ClapTrap::_healthPoints,
              src.ClapTrap::_energyPoints,
              src.ClapTrap::_attackDamage ),
    ScavTrap(),
    FragTrap() {
  this->whoAmI();
  std::cout << "IS BORN as a clone of " << src << std::endl;
  return;
}

/**
 * @brief       Destructor
 */

DiamondTrap::~DiamondTrap( void ) {
  this->whoAmI();
  std::cout << "IS DEAD !" << std::endl;
  return;
}

DiamondTrap& DiamondTrap::operator=( DiamondTrap const& rhs ) {
  std::cout << rhs;
  std::cout << "is assigned to " << *this << std::endl;
  this->whoAmI();
  std::cout << std::endl;
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
  o << "(ClapTrap " << this->ClapTrap::_name << ") ";
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
  std::cout << *this;
}
