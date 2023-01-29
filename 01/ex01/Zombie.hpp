#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

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

#endif /* __ZOMBIE_H__ */
