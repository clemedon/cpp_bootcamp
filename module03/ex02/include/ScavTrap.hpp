// @author    Clément Vidon
// @created   230324 14:34:27  by  clem@spectre
// @modified  230324 14:47:08  by  clem@spectre
// @filename  ScavTrap.hpp

#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include <iosfwd>
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
  ScavTrap( std::string const& name = "Derived",
            unsigned int const&         healthPoints = 100,
            unsigned int const&         energyPoints = 50,
            unsigned int const&         attackDamage = 20 );
  ScavTrap( ScavTrap const& src );
  virtual ~ScavTrap( void );
  ScavTrap&    operator=( ScavTrap const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual void attack( std::string const& target );
  void         guardGate( void );
};

std::ostream& operator<<( std::ostream& o, ScavTrap const& i );

#endif  // SCAVTRAP_HPP_
