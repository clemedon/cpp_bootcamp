// @author    Clément Vidon
// @created   230324 11:47:44  by  clem@spectre
// @modified  230324 11:47:46  by  clem@spectre
// @filename  Zombie.hpp

#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <string>

class Zombie {
 public:
  Zombie( void );
  ~Zombie( void );

  void setName( std::string );
  void announce( void ) const;

 private:
  std::string _name;
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif  // ZOMBIE_HPP_
