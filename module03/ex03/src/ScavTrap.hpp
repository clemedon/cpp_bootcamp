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

class ScavTrap : public virtual ClapTrap {
 public:
  ScavTrap( std::string const& name = "C" );
  ScavTrap( ScavTrap const& src );
  ~ScavTrap( void );
  ScavTrap& operator=( ScavTrap const& rhs );
  void      print( std::ostream& o ) const;

  void attack( std::string const& target );
  void guardGate( void );
};

std::ostream& operator<<( std::ostream& o, ScavTrap const& i );

#endif  // SCAVTRAP_HPP_
