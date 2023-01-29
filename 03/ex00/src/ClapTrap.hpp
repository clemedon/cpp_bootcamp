#ifndef CLAPTRAP_HPP_
#define CLAPTRAP_HPP_

#include <iostream>
#include <string>

/**
 * ClapTrap
 *
 * - When ClapTrack attacks, it causes its target to lose <_attackDamage>
 *   _hitPoints.
 * - When ClapTrap beRepaired() itself, it gets <amount> hit points back.
 * - Attacking and repairing cost 1 _energyPoints point each.
 * - Of course, ClapTrap can’t do anything if it has no _hitPoints or
 *   _energyPoints left.
 */

class ClapTrap {
 public:
  ClapTrap( std::string const& name = "Unknown" );
  ClapTrap( ClapTrap const& src );
  ~ClapTrap( void );

  ClapTrap& operator=( ClapTrap const& rhs );

  void print( std::ostream& os ) const;

  bool isAble() const;

  void attack( std::string const& target );
  void takeDamage( unsigned int amount );
  void beRepaired( unsigned int amount );

  std::string getName( void ) const;
  int         getAttackDamage( void ) const;

 private:
  std::string _name;
  int         _hitPoints;
  int         _energyPoints;
  int         _attackDamage;
};

std::ostream& operator<<( std::ostream& os, ClapTrap const& i );

#endif  // CLAPTRAP_HPP_
