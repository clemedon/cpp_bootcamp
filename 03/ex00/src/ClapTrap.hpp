#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <iostream>
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
  ClapTrap( std::string const& name = "Unknown" );
  ClapTrap( ClapTrap const& src );
  ~ClapTrap( void );
  ClapTrap& operator=( ClapTrap const& rhs );
  void      print( std::ostream& os ) const;

  bool isAble() const;
  void attack( std::string const& target );
  void takeDamage( unsigned int const& amount );
  void beRepaired( unsigned int const& amount );

  std::string getName( void ) const;
  int         getHealthPoints( void ) const;
  int         getEnergyPoints( void ) const;
  int         getAttackDamage( void ) const;

 protected:  // TODO ex00
  std::string _name;
  int         _healthPoints;
  int         _energyPoints;
  int         _attackDamage;
};

std::ostream& operator<<( std::ostream& os, ClapTrap const& i );

#endif  // CLAPTRAP_HPP_
