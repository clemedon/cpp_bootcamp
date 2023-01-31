#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

/**
 * ScavTrap
 *
 * - attack() causes the target to lost <attackDamage> healthPoints
 * - beRepaired() gives <amount> healthPoints back
 * - attack() and beRepaired() cost 1 energyPoints point each
 * - ScavTrap stops if it runs out of healthPoints or energyPoints
 */

class ScavTrap : public ClapTrap {
 public:
  ScavTrap( std::string const& name = "Unknown" );
  ScavTrap( ScavTrap const& src );
  virtual ~ScavTrap( void );
  /* ScavTrap& operator=( ScavTrap const& rhs ); */
  /* void      print( std::ostream& o ) const; */

  /* bool isAble() const; */
  void attack( std::string const& target );
  void guardGate( void );
  /* void takeDamage( unsigned int const& amount ); */
  /* void beRepaired( unsigned int const& amount ); */

  /* std::string getName( void ) const; */
  /* int         getHealthPoints( void ) const; */
  /* int         getEnergyPoints( void ) const; */
  /* int         getAttackDamage( void ) const; */

 protected:
  /* std::string _name; */
  /* int         _healthPoints; */
  /* int         _energyPoints; */
  /* int         _attackDamage; */
};

std::ostream& operator<<( std::ostream& o, ScavTrap const& i );

#endif  // SCAVTRAP_HPP_
