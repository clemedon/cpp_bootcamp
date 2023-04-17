// @author    Clément Vidon
// @created   230324 14:55:34  by  clem@spectre
// @modified  230324 14:58:01  by  clem@spectre
// @filename  ScavTrap.hpp

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
  explicit ScavTrap( std::string const& name = "C" );
  ScavTrap( ScavTrap const& src );
  ~ScavTrap( void );
  ScavTrap& operator=( ScavTrap const& rhs );
  void      print( std::ostream& o ) const;

  void attack( std::string const& target );
  void guardGate( void );
};

std::ostream& operator<<( std::ostream& o, ScavTrap const& i );

#endif  // SCAVTRAP_HPP_
