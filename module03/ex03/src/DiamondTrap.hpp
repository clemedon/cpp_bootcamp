#ifndef DIAMONDTRAP_HPP_
#define DIAMONDTRAP_HPP_

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/**
 * DiamondTrap
 *
 * - attack() causes the target to lost <attackDamage> healthPoints
 * - beRepaired() gives <amount> healthPoints back
 * - attack() and beRepaired() cost 1 energyPoints point each
 * - DiamondTrap stops if it runs out of healthPoints or energyPoints
 */

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  DiamondTrap( std::string const& name = "Diamond",
               int const&         healthPoints = 100,
               int const&         energyPoints = 50,
               int const&         attackDamage = 30 );
  DiamondTrap( DiamondTrap const& src );
  ~DiamondTrap( void );
  DiamondTrap& operator=( DiamondTrap const& rhs );
  void         print( std::ostream& o ) const;

  void attack( std::string const& target );
  void whoAmI( void );

 private:
  std::string _name;
};

std::ostream& operator<<( std::ostream& o, DiamondTrap const& i );

#endif  // DIAMONDTRAP_HPP_
