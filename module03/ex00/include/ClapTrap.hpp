// @author    Clément Vidon
// @created   230324 12:54:59  by  clem@spectre
// @modified  230324 13:24:42  by  clem@spectre
// @filename  ClapTrap.hpp

#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <iosfwd>
#include <string>

/**
 * ClapTrap
 *
 * - attack() causes the target to lost <attackDamage> healthPoints
 * - beRepaired() gives <amount> healthPoints back
 * - attack() and beRepaired() cost 1 energyPoints point each
 * - ClapTrap stops if it runs out of healthPoints or energyPoints
 */

class ClapTrap {
 public:
  ClapTrap( std::string const& name = "Xavier" );
  ClapTrap( ClapTrap const& src );
  ~ClapTrap( void );
  ClapTrap& operator=( ClapTrap const& rhs );
  void      print( std::ostream& o ) const;

  bool isAble( void ) const;
  void attack( std::string const& target );
  void takeDamage( unsigned int const& amount );
  void beRepaired( unsigned int const& amount );

  std::string  getName( void ) const;
  unsigned int getHealthPoints( void ) const;
  unsigned int getEnergyPoints( void ) const;
  unsigned int getAttackDamage( void ) const;

 private:
  std::string  _name;
  unsigned int _healthPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;
};

std::ostream& operator<<( std::ostream& o, ClapTrap const& i );

#endif  // CLAPTRAP_HPP_
