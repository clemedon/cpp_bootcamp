// @author    Clément Vidon
// @created   230324 14:34:16  by  clem@spectre
// @modified  230324 14:47:06  by  clem@spectre
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

class FragTrap : public ClapTrap {
 public:
  FragTrap( std::string const&  name = "Derived",
            unsigned int const& healthPoints = 100,
            unsigned int const& energyPoints = 100,
            unsigned int const& attackDamage = 30 );
  FragTrap( FragTrap const& src );
  virtual ~FragTrap( void );
  FragTrap&    operator=( FragTrap const& rhs );
  virtual void print( std::ostream& o ) const;

  virtual void attack( std::string const& target );
  void         highFivesGuys( void );
};

std::ostream& operator<<( std::ostream& o, FragTrap const& i );

#endif  // FRAGTRAP_HPP_
