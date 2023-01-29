#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <string>

class Weapon {
 public:
  Weapon( std::string weapon );
  ~Weapon( void );

  std::string const& getType( void ) const;
  void               setType( std::string type );

 private:
  std::string _type;
};

#endif /* __WEAPON_HPP__ */
