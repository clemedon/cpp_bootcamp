// @author    Clément Vidon
// @created   230324 11:51:54  by  clem@spectre
// @modified  230324 11:51:56  by  clem@spectre
// @filename  Zombie.hpp

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <string>

class Zombie {
 public:
  Zombie( void );
  ~Zombie( void );

  void setName( std::string );
  void announce( void );

 private:
  std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif /* ZOMBIE_H_ */
