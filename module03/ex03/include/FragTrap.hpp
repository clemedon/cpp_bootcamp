// @author    Clément Vidon
// @created   230324 14:55:28  by  clem@spectre
// @modified  230324 14:58:14  by  clem@spectre
// @filename  FragTrap.hpp

#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_

#include <iosfwd>
#include <string>

#include "ClapTrap.hpp"

/**
 * FragTrap
 *
 * - attack() causes the target to lost <attackDamage> healthPoints
 * - beRepaired() gives <amount> healthPoints back
 * - attack() and beRepaired() cost 1 energyPoints point each
 * - FragTrap stops if it runs out of healthPoints or energyPoints
 */

class FragTrap : public virtual ClapTrap {
 public:
  explicit FragTrap( std::string const& name = "B" );
  FragTrap( FragTrap const& src );
  ~FragTrap( void );
  FragTrap& operator=( FragTrap const& rhs );
  void      print( std::ostream& o ) const;

  void attack( std::string const& target );
  void highFivesGuys( void );
};

std::ostream& operator<<( std::ostream& o, FragTrap const& i );

#endif  // FRAGTRAP_HPP_
